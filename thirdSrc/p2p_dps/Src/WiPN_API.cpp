/*
2018.08.01 WiPN API V1.0.0
Author: Zheng.B.C
use for Post/Subscribe/UnSubscribe/ChkSubscribe/ ...
---------------------------------------------
2018.08.04 WiPN API V1.0.1
Author: Zheng.B.C
update: WiPN API 增加 WiPN_Key 以兼容旧推送平台加解密的处理。
---------------------------------------------
2018.08.13 WiPN API V1.0.2
Author: Zheng.B.C
update: 1. WiPN_SDK 1.0.2 (NDT 0.6.6.0) 以上版本采用新的方式获取 UTCT: time_NDT 可以获得服务器的 UTCT 时间，必须在 NDT 初始化完成后调用才有效。
        2.采用新方式获取 UTCT 就无需从 QS/SN 获取回应的 UTCT，也就无需去更新保存 UTCT。
        3.WiPN_API_Send 内部计算 UTCT 方式改用新方法由 time_NDT 获得。
---------------------------------------------
2018.08.22 WiPN API V1.0.2
Author: Zheng.B.C
update: 修复 getWiPNErrorCodeInfo 判断是否为 NDT 错误的条件。
---------------------------------------------
2018.08.24 WiPN API V1.0.2
Author: Zheng.B.C
update: 修改判断 WiPN_Key 长度的条件为 16 byte, 长度匹配则加解密处理。
---------------------------------------------
2018.11.01 WiPN API V1.0.3
Author: BC.ZHENG
update: 修改 time_NDT 方法，当获取不到 UTCT 时间则打印 NDT 库版本号，以便排查。
---------------------------------------------
2018.11.19 WiPN API V1.0.4
Author: BC.ZHENG
update: 1.修改 WiPN_QueryAll 与 WiPN_API_Send 对 NDT_PPCS_SendTo 返回 NDT_ERROR_NoAckFromDevice(-27) 时不对同一个 SN DID 进行重试一次的处理，而直接换下一个 SN DID.
        2.WiPN_API.cpp 新添加几个简便易用的内部函数：TimeFormat_ms, GetTime_ms, getUTCT,其实只是对处理行为包了一层。
        3.在 WiPN API 内部处理 NDT Init 与 Deinit，在调 NDT_PPCS_SendTo 之前先做 Deinit 与 Init, 接着通过调用 time_NDT 获取 UTCT，在 WiPN API 结束返回前调 Deinit, 所以建议用户直接带 initstringAPP(initstringAPP 无需做域名解析，速度快)。
---------------------------------------------
2018.11.29 WiPN API V1.0.5
Author: BC.ZHENG
update:
        1.修改优化 WiPN_SDK 1.0.6 版中 WiPN_API.cpp (WiPN API 1.0.4) API 内部的 NDT DeInit/Init 的步骤：去掉 API 结束前的 NDT DeInit 操作，在 API 开始前先调 NDT_StatusCheck 再根据返回结果决定是否做 NDT Init。
        2.WiPN_API.cpp 内 mSecSleep 函数名加模块 _WiPN_ 前缀，以区分外部可能定义了相同函数名。
---------------------------------------------
2019.04.09 WiPN API V1.0.6
Author: BC.ZHENG
update:
        1.将一些共用的函数整合到 WiPN_Common.cpp。
---------------------------------------------
*/

#include "WiPN_API.h"

#if 1
//// 以下三个参数需要从外部获取，若已知此参数，则可直接定义之。
char g_NDT_InitString[SIZE_InitString] = {0};   // NDT InitString
char g_NDT_AES128Key[SIZE_AES128Key] = {0};     // NDT AESKey
char gWiPN_Key[17] = {};  // 有设置 WiPN_Key 则指令数据将会加密处理，没设置则不加密处理。此处的 gWiPN_Key 由测试程序命令行传入。
#else
//// 若已知 NDT_InitString && NDT_AES128Key && WiPN_Key 此参数，则直接定义之, 其中 WiPN_Key 可不设，直接给空字符串。
const char *g_NDT_InitString = NDT_INITSTRING;
const char *g_NDT_AES128Key = NDT_AES128KEY;
const gWiPN_Key[] = "";//WiPN_KEY; // 16 byte 的 WiPN 加解密 Key.
#endif

//// Mode:	0->Sending via Both LAN and Internet
//// 		1->Sending via Internet only
////		2->Sending via LAN only.
static int g_SendToMode = 1;

my_Thread_mutex_t thread_mutex_SendTo;

typedef struct {
    char *DID;
    int Time;
    int Handle;
} st_DID;

void st_swap(st_DID arr[], unsigned int x, unsigned int y)
{
    char *pTemp = arr[x].DID;
    arr[x].DID = arr[y].DID;
    arr[y].DID = pTemp;

    arr[x].Time = arr[x].Time ^ arr[y].Time;
    arr[y].Time = arr[x].Time ^ arr[y].Time;
    arr[x].Time = arr[x].Time ^ arr[y].Time;
}

void st_selectSort(st_DID arr[], unsigned int length)
{
    int Min = 0;
    for (int i = 0; i < length - 1; i++)
    {
        Min = i;
        for (int j = i + 1; j < length; j++)
        {
            if (arr[Min].Time > arr[j].Time)
            {
                Min = j;
            }
        }
        if (Min != i)
        {
            st_swap(arr, i, Min);
        }
    }
}

int NDT_StatusCheck(const char *APIName, INT32 *AckTime, INT32 *NumberDH, INT32 *NumberCH)
{
    st_Time_Info TimeBegin, TimeEnd;
    char TimeBuf[] = "[YYYY-MM-DD hh:mm:ss.xxx]";
    GetTime_ms(&TimeBegin, TimeBuf, sizeof(TimeBuf));
    int ret = NDT_PPCS_StatusCheck(AckTime, NumberDH, NumberCH);
    GetTime_ms(&TimeEnd, TimeBuf, sizeof(TimeBuf));
    st_debug("%s %s: NDT_PPCS_StatusCheck: %d ms, AckTime=%d, NumberDH=%d, NumberCH=%d, ret=%d [%s]\n", TimeBuf, APIName, ST_TIME_USED, *AckTime, *NumberDH, *NumberCH, ret, getNDTErrorCodeInfo(ret));
    return ret;
}

int NDT_Init(const char *APIName)
{
    int ret = -1;
    st_Time_Info TimeBegin, TimeEnd;
    char TimeBuf[] = "[YYYY-MM-DD hh:mm:ss.xxx]";
    for (int i = 0, times = 1; i < times; i++)
    {
        unsigned short Port = 0;//The working UDP Port Number, 0 -> decided by system.
        GetTime_ms(&TimeBegin, TimeBuf, sizeof(TimeBuf));
        st_debug("%s %s: NDT_PPCS_Initialize(%s, %d, NULL, %s)...\n", TimeBuf, APIName, g_NDT_InitString, Port, g_NDT_AES128Key);
        ret = NDT_PPCS_Initialize(g_NDT_InitString, Port, NULL, g_NDT_AES128Key);
        GetTime_ms(&TimeEnd, TimeBuf, sizeof(TimeBuf));

        if (NDT_ERROR_NoError != ret && NDT_ERROR_AlreadyInitialized != ret)
        {
            st_debug("%s %s: NDT_PPCS_Initialize failed: TimeUsed: %d ms, ret=%d [%s]\n", TimeBuf, APIName, ST_TIME_USED, ret, getWiPNErrorCodeInfo(ret));
            if (times-1 == i)
            {
                return ret;
            }
        }
        else
        {
            st_debug("%s %s: NDT_PPCS_Initialize OK! ret=%d, TimeUsed: %d ms.\n", TimeBuf, APIName, ret, ST_TIME_USED);
            break;
        }
    } // for
    return ret;
}

int NDT_DeInit(const char *APIName)
{
    int ret = -1;
    st_Time_Info TimeBegin, TimeEnd;
    char TimeBuf[] = "[YYYY-MM-DD hh:mm:ss.xxx]";
    GetTime_ms(&TimeBegin, TimeBuf, sizeof(TimeBuf));
    st_debug("%s %s: NDT_PPCS_DeInitialize ...\n", TimeBuf, APIName);
    ret = NDT_PPCS_DeInitialize();
    GetTime_ms(&TimeEnd, TimeBuf, sizeof(TimeBuf));
    st_debug("%s %s: NDT_PPCS_DeInitialize done! TimeUsed: %d ms.\n", TimeBuf, APIName, ST_TIME_USED);
    return ret;
}

//// importent:  time_NDT must be call after NDT_PPCS_Initialize, time_NDT will call NDT_PPCS_GetAPIVersion to get UTCT.
//// success: will return UTCT.
//// failed: will return 0.
unsigned int time_NDT(unsigned int *t)
{
    char UTCT_Buf[16] = {};
    unsigned int vtime = 0;
    unsigned int APIVersion;

    int AckTime = 0;
    int NumberDH = 0;
    int NumberCH = 0;
    if (NDT_ERROR_NotInitialized == NDT_StatusCheck("time_NDT", &AckTime, &NumberDH, &NumberCH))
    {
        if (0 > NDT_Init("time_NDT"))
        {
            return vtime;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        // printf("%s\n", NDT_PPCS_GetAPIVersion(&APIVersion));
        char *p = strstr(NDT_PPCS_GetAPIVersion(&APIVersion), "UTCT");
        if (p)
        {
            memcpy(UTCT_Buf, p + 7, 8); // UTCT=0x00000000
            // printf("UTCT_Buf=%s\n", UTCT_Buf);
            vtime = strtol(UTCT_Buf, NULL, 16);
            // printf("UTCT=0x%X\n", vtime);
            if (t) *t = vtime;
            if (0x5C000000 < vtime) break;
            else _WiPN_mSecSleep(50);
        }
        else
        {
            st_info("====> NDT API Version: %d.%d.%d.%d  (%u) <====\n",
                    (APIVersion & 0xFF000000) >> 24,
                    (APIVersion & 0x00FF0000) >> 16,
                    (APIVersion & 0x0000FF00) >> 8,
                    (APIVersion & 0x000000FF) >> 0,
                    APIVersion);
            break;
        }
    }
    return vtime;
}

// getUTCT will call time_NDT to get UTCT from NDT_PPCS_GetAPIVersion.
// 0:success, -1:failed.
int getUTCT()
{
    for (int i = 0, times = 500; i < times; i++)
    {
        UINT32 UTCT = time_NDT(NULL);
        if (0 == UTCT)
        {
            if (times-1 == i)
            {
                st_debug("Can not get UTCT!!\n");
                return -1;
            }
            _WiPN_mSecSleep(20);
        }
        else if (0x5B000000 < UTCT)
        {
            st_debug("UTCT=0x%08X\n", UTCT);
            break;
        }
    } // for
    return 0;
}

//// ----------------------------- 2018.07.24 ----------------------------- ////
//// --------------------------- WiPN Root API ---------------------------- ////
//// ---------------------------------------------------------------------- ////
//// 20180723: Query All response data from QueryServer and save in QSResult buffer.
INT32 WiPN_QueryAll(const char *pDeviceDID, // device DID.
                    char *QSDID[],          // QueryServer DID.
                    UINT16 NumberOfServer,  // QueryServer DID Number
                    char *QSResult,         // Query Result String.
                    UINT16 *QSRBufSize,      // QSResult Buf Size.
                    const char *NDTByServerString,// if this NDTByServerString Parameter is NULL,then use NDT SendTo,Otherwise use SendToByserver.
                    const char *NDTByAES128Key)// if NDTByServerString not NULL,then this NDTByAES128Key Parameter also not NULL.
{
    const char APIName[] = "WiPN_QueryAll";
    st_Time_Info TimeBegin, TimeEnd;
    char TimeBuf[] = "[YYYY-MM-DD hh:mm:ss.xxx]";
    GetTime_ms(&TimeBegin, TimeBuf, sizeof(TimeBuf));
    // Parameter Detect
    if (!pDeviceDID || 12 > strlen(pDeviceDID))
    {
        st_info("%s %s - Invalid DeviceDID Parameter!!\n", TimeBuf, APIName);
        return WiPN_ERROR_InvalidParameter;
    }
    if (!QSDID)
    {
        st_info("%s %s - QSDID Buf is NULL!!\n", TimeBuf, APIName);
        return WiPN_ERROR_InvalidParameter;
    }
    if (0 == NumberOfServer)
    {
        st_info("%s %s - Invalid NumberOfServer Parameter!!\n", TimeBuf, APIName);
        return WiPN_ERROR_InvalidParameter;
    }
    int i = 0;
    for (; i < NumberOfServer; i++)
    {
        if (NULL == QSDID[i]) break;
    }
    if (i != NumberOfServer)
    {
        st_info("%s %s - QSDIDbuf[%d] have no DID!!\n", TimeBuf, APIName, i);
        return WiPN_ERROR_InvalidParameter;
    }
    if (!QSResult || !QSRBufSize || 0 == *QSRBufSize)
    {
        st_info("%s %s - Invalid QSResult Buf or QSRBufSize!!\n", TimeBuf, APIName);
        return WiPN_ERROR_InvalidParameter;
    }
    if (NDTByServerString && 48 > strlen(NDTByServerString))
    {
        st_info("%s %s - Invalid NDTByServerString Parameter!!\n", TimeBuf, APIName);
        return WiPN_ERROR_InvalidParameter;
    }
    if (NDTByServerString && !NDTByAES128Key)
    {
        st_info("%s %s - NDTByAES128Key=NULL -> Invalid NDTByAES128Key Parameter!!\n", TimeBuf, APIName);
        return WiPN_ERROR_InvalidParameter;
    }
    if (NDTByAES128Key && 16 > strlen(NDTByAES128Key))
    {
        st_info("%s %s - Invalid NDTByAES128Key Parameter!!\n", TimeBuf, APIName);
        return WiPN_ERROR_InvalidParameter;
    }
    int ret = -1;
    INT32 AckTime = 0;
    INT32 NumberDH = 0;
    INT32 NumberCH = 0;
    ret = NDT_StatusCheck(APIName, &AckTime, &NumberDH, &NumberCH);
    if (NDT_ERROR_NotInitialized == ret)
    {
        GetTime_ms(&TimeBegin, TimeBuf, sizeof(TimeBuf));
        if ( 0 > (ret = NDT_Init(APIName)) )
        {
            GetTime_ms(&TimeEnd, TimeBuf, sizeof(TimeBuf));
            st_info("%s %s - NDT_PPCS_Initialize failed: %d ms, ret=%d.\n", TimeBuf, APIName, ST_TIME_USED, ret);
            return ret;
        }
    }
    else if (-1 == AckTime || 60 < AckTime)
    {
        NDT_DeInit(APIName);
        GetTime_ms(&TimeBegin, TimeBuf, sizeof(TimeBuf));
        if ( 0 > (ret = NDT_Init(APIName)) )
        {
            GetTime_ms(&TimeEnd, TimeBuf, sizeof(TimeBuf));
            st_info("%s %s - NDT_PPCS_Initialize failed: %d ms, ret=%d.\n", TimeBuf, APIName, ST_TIME_USED, ret);
            return ret;
        }
    }

    char CMD[32] = {0};
    SNPRINTF(CMD, sizeof(CMD), "DID=%s&", pDeviceDID);

    char *Buffer = CMD;
    unsigned short BufSize = 1280;
    unsigned short WiPNKey_Len = strlen(gWiPN_Key);
    if (16 == WiPNKey_Len) // 有String加密 Key
    {
        GetTime_ms(&TimeBegin, TimeBuf, sizeof(TimeBuf));
        st_debug("%s %s: WiPN_Key=%s\n", TimeBuf, APIName, gWiPN_Key);
        if (!(Buffer = (char *)malloc(BufSize)))
        {
            GetTime_ms(&TimeEnd, TimeBuf, sizeof(TimeBuf));
            st_info("%s %s: malloc Buffer failed!!\n", TimeBuf, APIName);
            return WiPN_ERROR_MallocFailed;
        }
    }

    char *pSendflag = (char*)malloc(NumberOfServer+1);
    memset(pSendflag, 0, NumberOfServer+1);
    pSendflag[NumberOfServer] = 1;

    int QSHandle = -1;
    short retryRecvFromCount = 0;
    short retrySendToCount = 0;

    srand((UINT32)time(NULL));
    short index = abs(rand() % NumberOfServer);

    while (1)
    {
        if (0 > QSHandle)
        {
            for (i = 0; i < NumberOfServer; i++)
            {
                index = (index + 1) % NumberOfServer;
                if (1 == pSendflag[index])
                {
                    continue; // 此 Server DID 已经重试过，不再往下。
                }
                GetTime_ms(&TimeBegin, TimeBuf, sizeof(TimeBuf));
                st_debug("%s %s: QueryCmd(%u Byte):%s\n", TimeBuf, APIName, strlen(CMD), CMD);
                if (16 == WiPNKey_Len)
                {
                    memset(Buffer, 0, BufSize);
                    // Encryption query CMD -> Buffer
                    if (0 > iPN_StringEnc(gWiPN_Key, CMD, Buffer, BufSize))
                    {
                        GetTime_ms(&TimeEnd, TimeBuf, sizeof(TimeBuf));
                        st_info("%s %s: iPN_StringEnc: Cmd Enc failed!\n", TimeBuf, APIName);
                        if (Buffer) {free((void *)Buffer); Buffer=NULL;}
                        if (pSendflag) {free((void *)pSendflag); pSendflag=NULL;}
                        return WiPN_ERROR_StringEncFailed;
                    }
                }
                unsigned short CMDSize = strlen(Buffer);

                // Only one SendTo can run at the same time,otherwise,it will return -19. (NDT_ERROR_SendToRunning -19)
                my_Mutex_Lock(thread_mutex_SendTo); // One time only one SendTo can Run.
                //my_GetCurrentTime(&TimeBegin);
                // Send query cmd to QueryServer
                if (!NDTByServerString) // NDTByServerString is NULL, so use NDT_PPCS_SendTos.
                {
                    st_debug("%s %s: send cmd to QS[%d]=%s. CMDSize=%u Byte. NDT_PPCS_SendTo(SendToMode:%d) ...\n", TimeBuf, APIName, index, QSDID[index], CMDSize, g_SendToMode);
                    ret = NDT_PPCS_SendTo(QSDID[index], Buffer, CMDSize, g_SendToMode);
                }
                else // NDTByServerString is Not NULL, so use NDT_PPCS_SendToByServer.
                {
                    st_debug("%s %s: send cmd to QS[%d]=%s. CMDSize=%u Byte. NDT_PPCS_SendToByServer(..., SendToMode:%d,NDTByServerString:%s, NDTByAES128Key:%s) ...\n", TimeBuf, APIName, index, QSDID[index], CMDSize, g_SendToMode, NDTByServerString, NDTByAES128Key);
                    ret = NDT_PPCS_SendToByServer(  QSDID[index],
                                                    Buffer,
                                                    CMDSize,
                                                    g_SendToMode,
                                                    NDTByServerString,  // Other NDT platforms Initstring
                                                    NDTByAES128Key);    // Other NDT platforms AES128Key
                }
                GetTime_ms(&TimeEnd, TimeBuf, sizeof(TimeBuf));
                my_Mutex_UnLock(thread_mutex_SendTo);
                //st_debug("NDT SendTo done! TimeUsed: %d ms\n", ST_TIME_USED);

                if (0 > ret)
                {
                    st_debug("%s %s: send cmd to QS[%d]=%s failed!! ret=%d [%s]\n\n", TimeBuf, APIName, index, QSDID[index], ret, getWiPNErrorCodeInfo(ret));
                    if (-1 == pSendflag[index]) // -1: only return NoAckFromDevice error, pSendflag[i] will set -1.
                    {
                        pSendflag[index] = 1;
                        continue;   // try next DID.
                    }
                    // 连续出现 NDT_ERROR_DeviceNotOnRecv(-23) 则对同一个 DID 重试 SendTo 5次。
                    if (NDT_ERROR_DeviceNotOnRecv == ret)
                    {
                        if (5 > retrySendToCount++)
                        {
                            i--;   // This DID will try again.
                            index--;
                        }
                        else
                        {
                            pSendflag[index] = 1;  // 1-> This DID won't try again.
                            retrySendToCount = 0;
                        }
                    }
                    // else if (NDT_ERROR_NoAckFromDevice == ret) // This NoAckFromDevice(-27) error is only retrying once.
                    // {
                    //     retrySendToCount = 0;
                    //     pSendflag[index] = -1;
                    //     i--;
                    //     index--;
                    // }
                    continue;
                }
                else
                {
                    st_debug("%s %s: send cmd to QS[%d]=%s success! ret=%d\n", TimeBuf, APIName, index, QSDID[index], ret);
                    QSHandle = ret;
                    pSendflag[index] = 1;
                    break;
                }
            } // for
            if (0 > QSHandle)
            {
                break; // 所有 DID 都 sendto 失败，直接退出。
            }
        }
        else
        {
            unsigned int Timeout_ms = 3*1000;
            UINT16 SizeOfBuf;
            if (16 == WiPNKey_Len)
            {
                SizeOfBuf = BufSize;
            }
            else
            {
                Buffer = QSResult;
                SizeOfBuf = *QSRBufSize;
            }
            memset(Buffer, 0, SizeOfBuf);

            GetTime_ms(&TimeBegin, TimeBuf, sizeof(TimeBuf));
            st_debug("%s %s: NDT_PPCS_RecvFrom(QSHandle:%d, ..., Timeout:%u ms) ...\n", TimeBuf, APIName, QSHandle, Timeout_ms);
            ret = NDT_PPCS_RecvFrom(QSHandle, Buffer, &SizeOfBuf, Timeout_ms);
            GetTime_ms(&TimeEnd, TimeBuf, sizeof(TimeBuf));

            if (0 > ret)
            {
                st_debug("%s %s: NDT_PPCS_RecvFrom: QS[%d]=%s. ret=%d. [%s]\n",TimeBuf, APIName,index,QSDID[index], ret, getWiPNErrorCodeInfo(ret));
                // -26 -27 -3
                if (NDT_ERROR_NoAckFromPushServer == ret || NDT_ERROR_NoAckFromDevice == ret || NDT_ERROR_TimeOut == ret)
                {
                    if (1 < retryRecvFromCount++) break;
                }
                else if (NDT_ERROR_RemoteHandleClosed == ret) // -36
                {
                    st_debug_T("%s: NDT_PPCS_CloseHandle(%d) !!\n", APIName, QSHandle,NDT_PPCS_CloseHandle(QSHandle));
                    QSHandle = -1;
                }
                continue;
            }
            else
            {
                if (16 == WiPNKey_Len && 0 > iPN_StringDnc(gWiPN_Key, Buffer, QSResult, *QSRBufSize))
                {
                    GetTime_ms(&TimeEnd, TimeBuf, sizeof(TimeBuf));
                    st_info("%s %s: iPN_StringDnc failed!\n", TimeBuf, APIName);
                    ret = WiPN_ERROR_StringDecFailed;
                    break ;
                }
                st_debug("%s %s: From Server(QSHandle:%d, QS[%d]=%s): \nData(%u Byte):%s\n", TimeBuf, APIName, QSHandle, index, QSDID[index], strlen(QSResult), QSResult);
            } // ret > 0
            break;
        } // Handle > 0
    } // while
    if (0 <= QSHandle)
    {
        st_debug_T("%s: NDT_PPCS_CloseHandle(%d) done! ret=%d\n", APIName, QSHandle, NDT_PPCS_CloseHandle(QSHandle));
    }
    if (16 == WiPNKey_Len)
    {
        if (Buffer) {free((void *)Buffer); Buffer=NULL;}
    }
    if (pSendflag) {free((void *)pSendflag); pSendflag=NULL;}
    *QSRBufSize = strlen(QSResult);

    st_debug("\n");

    return ret;
} // WiPN_QueryAll

INT32 WiPN_API_Send(const char *pServerDIDString,   // Post/Subs Server String, such as: "01,PPCS-123456-ABCDEF"
                    const char *pCmd,
                    char *pResult,                  // Save Server return info
                    UINT16 *RBufSize,               // Result Buf Size.
                    char *pUTCT,                    // 此参数在此已弃用
                    const char *NDTByServerString,  // if this NDTByServerString Parameter is NULL,then use NDT SendTo,Otherwise use SendToByserver.
                    const char *NDTByAES128Key)     // if NDTByServerString not NULL,then this NDTByAES128Key Parameter also not NULL.
{
    const char APIName[] = "WiPN_API_Send";
    st_Time_Info TimeBegin, TimeEnd;
    char TimeBuf[] = "[YYYY-MM-DD hh:mm:ss.xxx]";
    GetTime_ms(&TimeBegin, TimeBuf, sizeof(TimeBuf));
    if (!pServerDIDString || 0 == strlen(pServerDIDString))
    {
        st_info("%s %s - Invalid ServerDIDString parameter!!\n", TimeBuf, APIName);
        return WiPN_ERROR_InvalidParameter;
    }
    if (!pCmd || 0 == strlen(pCmd))
    {
        st_info("%s %s - Invalid Cmd parameter!!\n", TimeBuf, APIName);
        return WiPN_ERROR_InvalidParameter;
    }
    if (!pResult || !RBufSize || 0 == *RBufSize)
    {
        st_info("%s %s - Invalid Result or RBufSize parameter!!\n", TimeBuf, APIName);
        return WiPN_ERROR_InvalidParameter;
    }
    // if (!pUTCT || 0 == strlen(pUTCT))
    // {
    //     st_info("%s - Invalid UTCTString parameter!!\n", APIName);
    //     return WiPN_ERROR_InvalidParameter;
    // }
    if (NDTByServerString && 48 > strlen(NDTByServerString))
    {
        st_info("%s %s - Invalid NDT_ByServerString Parameter!!\n", TimeBuf, APIName);
        return WiPN_ERROR_InvalidParameter;
    }
    if (NDTByServerString && !NDTByAES128Key)
    {
        st_info("%s %s - NDTByAES128Key=NULL -> Invalid NDTByAES128Key Parameter!!\n", TimeBuf, APIName);
        return WiPN_ERROR_InvalidParameter;
    }
    if (NDTByAES128Key && 16 > strlen(NDTByAES128Key))
    {
        st_info("%s %s - Invalid NDTByAES128Key Parameter!!\n", TimeBuf, APIName);
        return WiPN_ERROR_InvalidParameter;
    }
    int ret = -1;
    INT32 AckTime = 0;
    INT32 NumberDH = 0;
    INT32 NumberCH = 0;
    ret = NDT_StatusCheck(APIName, &AckTime, &NumberDH, &NumberCH);
    if (NDT_ERROR_NotInitialized == ret)
    {
        GetTime_ms(&TimeBegin, TimeBuf, sizeof(TimeBuf));
        if ( 0 > (ret = NDT_Init(APIName)) )
        {
            GetTime_ms(&TimeEnd, TimeBuf, sizeof(TimeBuf));
            st_info("%s %s - NDT_PPCS_Initialize failed: %d ms, ret=%d.\n", TimeBuf, APIName, ST_TIME_USED, ret);
            return ret;
        }
    }
    else if (-1 == AckTime || 60 < AckTime)
    {
        NDT_DeInit(APIName);
        GetTime_ms(&TimeBegin, TimeBuf, sizeof(TimeBuf));
        if ( 0 > (ret = NDT_Init(APIName)) )
        {
            GetTime_ms(&TimeEnd, TimeBuf, sizeof(TimeBuf));
            st_info("%s %s - NDT_PPCS_Initialize failed: %d ms, ret=%d.\n", TimeBuf, APIName, ST_TIME_USED, ret);
            return ret;
        }
    }
    // _WiPN_mSecSleep(20);
    // get UTCT from NDT Server. 需在 NDT 初始化后获取 UTCT 时间
    if (0 > getUTCT())
    {
        GetTime_ms(&TimeEnd, TimeBuf, sizeof(TimeBuf));
        st_info("%s %s - getUTCT failed!!\n", TimeBuf, APIName);
        return -1;
    }

    //// Get Server DID
    unsigned short NumberOfServer = 0;
    unsigned char SizeOfDID = 0;
    char *pServerDID = NULL;
    if (0 > Split_DID(pServerDIDString, &NumberOfServer, &SizeOfDID, &pServerDID))
    {
        return WiPN_ERROR_StringParseFailed;
    }

    GetTime_ms(&TimeBegin, TimeBuf, sizeof(TimeBuf));
    // Calculate the size of SubscribeCmd
    UINT32 Length_Cmd = (UINT32)(strlen(pCmd)+strlen("UTCT=0x&"))+12;
    UINT32 MaxSizeOfCmd = 1280;     // NDT can only send a maximum of 1280 bytes of data
    if (MaxSizeOfCmd < Length_Cmd)  // 指令长度太长!! 不能超过 1280
    {
        st_debug("%s %s: Length Of Cmd is Exceed %d bytes!!\n", TimeBuf, APIName, MaxSizeOfCmd);
        if (pServerDID) {free((void *)pServerDID); pServerDID=NULL;}
        return WiPN_ERROR_ExceedMaxSize;
    }

    GetTime_ms(&TimeBegin, TimeBuf, sizeof(TimeBuf));
    unsigned short CMDBufSize = (Length_Cmd/4+1)*4;
    char *CMD = (char *)malloc(CMDBufSize);
    if (!CMD)
    {
        st_info("%s %s: malloc Cmd Buf failed!!\n", TimeBuf, APIName);
        if (pServerDID) {free((void *)pServerDID); pServerDID=NULL;}
        return WiPN_ERROR_MallocFailed;
    }

    char *Buffer = CMD;
    unsigned short BufSize = 1280;
    unsigned short WiPNKey_Len = strlen(gWiPN_Key);
    if (16 == WiPNKey_Len) // 有设 String 加密 Key
    {
        GetTime_ms(&TimeBegin, TimeBuf, sizeof(TimeBuf));
        st_debug("%s %s: WiPN_Key=%s\n", TimeBuf, APIName, gWiPN_Key);
        if (!(Buffer = (char *)malloc(BufSize+1)))
        {
            GetTime_ms(&TimeEnd, TimeBuf, sizeof(TimeBuf));
            st_info("%s %s: malloc Buffer failed!!\n", TimeBuf, APIName);
            if (pServerDID) {free((void *)pServerDID); pServerDID=NULL;}
            if (CMD) {free((void*)CMD); CMD=NULL;}
            return WiPN_ERROR_MallocFailed;
        }
    }

    char *pSendflag = (char*)malloc(NumberOfServer+1);
    memset(pSendflag, 0, NumberOfServer+1);
    pSendflag[NumberOfServer] = 1;

    int i = 0;
    int SNHandle = -1;
    // short retryRecvFromCount = 0;
    short retrySendToCount = 0;

    // srand((UINT32)time(NULL));
    // unsigned short j = abs(rand() % NumberOfServer);
    short index = 0;
    while (1)
    {
        if (0 > SNHandle)
        {
            for (i = 0; i < NumberOfServer; i++)
            {
                // i = (i + 1) % NumberOfServer;
                if (1 == pSendflag[i])
                {
                    continue; // This Server DID has been retested and no need to try again.
                }
                index = SizeOfDID * i;

                // Format CMD
                UINT32 New_UTCT = time_NDT(NULL);//time_UTCT(NULL);
                memset(CMD, 0, CMDBufSize);
                SNPRINTF(CMD, CMDBufSize, "%sUTCT=0x%X&", pCmd, New_UTCT);

                GetTime_ms(&TimeBegin, TimeBuf, sizeof(TimeBuf));
                st_debug("%s %s: Cmd(%u Byte):%s\n", TimeBuf, APIName, (unsigned)strlen(CMD), CMD);

                if (16 == WiPNKey_Len)
                {
                    memset(Buffer, 0, BufSize);
                    // Encryption query CMD -> Buffer
                    if (0 > iPN_StringEnc(gWiPN_Key, CMD, Buffer, BufSize))
                    {
                        st_info_T("%s: iPN_StringEnc: Cmd Enc failed!\n", APIName);
                        if (pServerDID) {free((void *)pServerDID); pServerDID=NULL;}
                        if (CMD) {free((void *)CMD); CMD=NULL;}
                        if (Buffer) {free((void *)Buffer); Buffer=NULL;}
                        if (pSendflag) {free((void *)pSendflag); pSendflag=NULL;}
                        return WiPN_ERROR_StringEncFailed;
                    }
                }
                unsigned short CMDSize = strlen(Buffer);

                // Only one SendTo can run at the same time,otherwise,it will return -19. (NDT_ERROR_SendToRunning -19)
                my_Mutex_Lock(thread_mutex_SendTo); // One time only one SendTo can Run.
                //my_GetCurrentTime(&TimeBegin);
                // Send cmd.
                if (!NDTByServerString) // NDTByServerString is NULL, so use NDT_PPCS_SendTos.
                {
                    st_debug("%s %s: send cmd to SN[%d]=%s. CMDSize=%u Byte. NDT_PPCS_SendTo(SendToMode:%d) ...\n", TimeBuf, APIName, i, &pServerDID[index], CMDSize, g_SendToMode);
                    ret = NDT_PPCS_SendTo(&pServerDID[index], Buffer, CMDSize, g_SendToMode);
                }
                else // NDTByServerString is Not NULL, so use NDT_PPCS_SendToByServer.
                {
                    st_debug("%s %s: send cmd to SN[%d]=%s. CMDSize=%u Byte. NDT_PPCS_SendToByServer(..., SendToMode:%d,NDTByServerString:%s, NDTByAES128Key:%s) ...\n", TimeBuf, APIName, i, &pServerDID[index], CMDSize,g_SendToMode, NDTByServerString, NDTByAES128Key);
                    ret = NDT_PPCS_SendToByServer(  &pServerDID[index],
                                                    Buffer,
                                                    CMDSize,
                                                    g_SendToMode,
                                                    NDTByServerString,  // Other NDT platforms Initstring
                                                    NDTByAES128Key);    // Other NDT platforms AES128Key
                }
                GetTime_ms(&TimeEnd, TimeBuf, sizeof(TimeBuf));
                my_Mutex_UnLock(thread_mutex_SendTo);
                //st_debug("NDT SendTo done! TimeUsed: %d ms\n", ST_TIME_USED);

                if (0 > ret)
                {
                    st_debug("%s %s: send cmd to SN[%d]=%s failed! ret=%d [%s]\n", TimeBuf, APIName, i, &pServerDID[index], ret, getWiPNErrorCodeInfo(ret));
                    if (-1 == pSendflag[i]) // -1: only return NoAckFromDevice error, pSendflag[i] will set -1.
                    {
                        pSendflag[i] = 1;
                        continue;   // try next DID.
                    }
                    // If NDT_ERROR_DeviceNotOnRecv(-23) occurs continuously, retry SendTo 5 times for the same DID.
                    if (NDT_ERROR_DeviceNotOnRecv == ret)
                    {
                        if (5 > retrySendToCount++)
                        {
                            i--;   // This DID will try again.
                        }
                        else
                        {
                            pSendflag[i] = 1;  // 1-> This DID won't try again.
                            retrySendToCount = 0;
                        }
                    }
                    continue; // In addition to the above mistakes, try the next QS DID.
                }
                else
                {
                    st_debug("%s %s: send cmd to SN[%d]=%s success! ret=%d\n", TimeBuf, APIName, i, &pServerDID[index], ret);
                    SNHandle = ret;
                    pSendflag[i] = 1;
                    break;
                }
            }
            if (0 > SNHandle)
            {
                break;
            }
        }
        else
        {
            unsigned int Timeout_ms = 6*1000;
            UINT16 SizeOfBuf;
            if (16 == WiPNKey_Len)
            {
                SizeOfBuf = BufSize;
            }
            else
            {
                Buffer = pResult;
                SizeOfBuf = *RBufSize;
            }
            memset(Buffer, 0, SizeOfBuf);

            GetTime_ms(&TimeBegin, TimeBuf, sizeof(TimeBuf));
            st_debug("%s %s: NDT_PPCS_RecvFrom(%d, ..., Timeout:%u ms) ...\n", TimeBuf, APIName, SNHandle, Timeout_ms);
            ret = NDT_PPCS_RecvFrom(SNHandle, Buffer, &SizeOfBuf, Timeout_ms);
            GetTime_ms(&TimeEnd, TimeBuf, sizeof(TimeBuf));
            if (0 > ret)
            {
                st_debug("%s %s: NDT_PPCS_RecvFrom: %d ms, SN[%d]=%s. ret=%d. [%s]\n", TimeBuf, APIName, ST_TIME_USED, i, &pServerDID[index], ret, getWiPNErrorCodeInfo(ret));
            }
            else
            {
                if (16 == WiPNKey_Len && 0 > iPN_StringDnc(gWiPN_Key, Buffer, pResult, *RBufSize))
                {
                    st_info("%s %s: iPN_StringDnc failed!\n", TimeBuf,APIName);
                    ret = WiPN_ERROR_StringDecFailed;
                    break;
                }
                *RBufSize = strlen(pResult);
                st_debug("%s %s: From Server(Handle:%d, SN[%d]=%s, Size:%u Byte): %s\n", TimeBuf,APIName, SNHandle, i, &pServerDID[index], *RBufSize, pResult);
            } // ret > 0
            break;
        } // Handle > 0
    } // while (1)

    if (0 <= SNHandle)
    {
        st_debug_T("%s: NDT_PPCS_CloseHandle(%d) done! ret=%d\n", APIName, SNHandle, NDT_PPCS_CloseHandle(SNHandle));
        SNHandle = -1;
    }

    if (pServerDID) {free((void *)pServerDID); pServerDID=NULL;}
    if (CMD) {free((void *)CMD); CMD=NULL;}
    if (pSendflag) {free((void *)pSendflag); pSendflag=NULL;}
    if (16 == WiPNKey_Len)
    {
        if (Buffer) {free((void *)Buffer); Buffer=NULL;}
    }

    *RBufSize = strlen(pResult);
    st_debug("\n");
    return ret;
} // WiPN_API_Send

int WiPN_Select(char *pServerDIDString,
                const char *NDTByServerString,  // if this NDTByServerString Parameter is NULL,then use NDT SendTo,Otherwise use SendToByserver.
                const char *NDTByAES128Key)    // if NDTByServerString not NULL,then this NDTByAES128Key Parameter also not NULL.
{
    const char APIName[] = "WiPN_Select";
    st_Time_Info TimeBegin, TimeEnd;
    char TimeBuf[] = "[YYYY-MM-DD hh:mm:ss.xxx]";

    unsigned short StringSize = strlen(pServerDIDString);
    if (!pServerDIDString || 0 == StringSize)
    {
        st_info_T("%s - Invalid NDTByServerString Parameter!!\n", APIName);
        return WiPN_ERROR_InvalidParameter;
    }
    if (NDTByServerString && 48 > strlen(NDTByServerString))
    {
        st_info_T("%s - Invalid NDTByServerString Parameter!!\n", APIName);
        return WiPN_ERROR_InvalidParameter;
    }
    if (NDTByAES128Key && 16 > strlen(NDTByAES128Key))
    {
        st_info_T("%s - Invalid NDTByAES128Key Parameter!!\n", APIName);
        return WiPN_ERROR_InvalidParameter;
    }
    if (NDTByServerString && !NDTByAES128Key)
    {
        st_info_T("%s - NDTByAES128Key=NULL -> Invalid NDTByAES128Key Parameter!!\n", APIName);
        return WiPN_ERROR_InvalidParameter;
    }

    int ret = -1;
    int AckTime = 0;
    int NumberDH = 0;
    int NumberCH = 0;
    ret = NDT_StatusCheck(APIName, &AckTime, &NumberDH, &NumberCH);
    if (NDT_ERROR_NotInitialized == ret)
    {
        GetTime_ms(&TimeBegin, TimeBuf, sizeof(TimeBuf));
        if ( 0 > (ret = NDT_Init(APIName)) )
        {
            GetTime_ms(&TimeEnd, TimeBuf, sizeof(TimeBuf));
            st_info("%s %s - NDT_PPCS_Initialize failed: %d ms, ret=%d.\n", TimeBuf, APIName, ST_TIME_USED, ret);
            return ret;
        }
    }
    else if (-1 == AckTime || 60 < AckTime)
    {
        NDT_DeInit(APIName);
        GetTime_ms(&TimeBegin, TimeBuf, sizeof(TimeBuf));
        if ( 0 > (ret = NDT_Init(APIName)) )
        {
            GetTime_ms(&TimeEnd, TimeBuf, sizeof(TimeBuf));
            st_info("%s %s - NDT_PPCS_Initialize failed: %d ms, ret=%d.\n", TimeBuf, APIName, ST_TIME_USED, ret);
            return ret;
        }
    }
    //// Get Server DID
    unsigned short NumberOfServer = 0;
    unsigned char SizeOfDID = 0;
    char *pServerDID = NULL;
    if (0 > Split_DID(pServerDIDString, &NumberOfServer, &SizeOfDID, &pServerDID))
    {
        return WiPN_ERROR_StringParseFailed;
    }

    st_DID *pDIDInfo = (st_DID *)malloc(sizeof(st_DID)*NumberOfServer);
    if (!pDIDInfo)
    {
        GetTime_ms(&TimeEnd, TimeBuf, sizeof(TimeBuf));
        st_info("%s %s: malloc DID Buf failed!!\n", TimeBuf, APIName);
        return WiPN_ERROR_MallocFailed;
    }
    memset(pDIDInfo, 0, sizeof(st_DID)*NumberOfServer);

    //// Copy DID From ServerDIDString
    for (int i = 0; i < NumberOfServer; i++)
    {
        pDIDInfo[i].DID = &pServerDID[SizeOfDID*i];
        // st_debug("ServerDID[%d]=%s\n", i, pServerDID+(SizeOfDID*i));
        // st_debug("DIDInfo[%d]=%s\n", i, pDIDInfo[i].DID);
    }

    short index = 0;
    int counter = 0;
    for (int i = 0; i < NumberOfServer; i++)
    {
        index = SizeOfDID*i;
        my_Mutex_Lock(thread_mutex_SendTo);
        GetTime_ms(&TimeBegin, TimeBuf, sizeof(TimeBuf));
        if (!NDTByServerString) // NDTByServerString is NULL, so use NDT_PPCS_SendTos.
        {
            ret = NDT_PPCS_SendTo(&pServerDID[index], "UTCT=0&", strlen("UTCT=0&"), g_SendToMode);
        }
        else // NDTByServerString is Not NULL, so use NDT_PPCS_SendToByServer.
        {
            ret = NDT_PPCS_SendToByServer(  &pServerDID[index],
                                            "UTCT=0&",
                                            strlen("UTCT=0&"),
                                            g_SendToMode,
                                            NDTByServerString,  // Other NDT platforms Initstring
                                            NDTByAES128Key);    // Other NDT platforms AES128Key
        }
        GetTime_ms(&TimeEnd, TimeBuf, sizeof(TimeBuf));
        my_Mutex_UnLock(thread_mutex_SendTo);
        pDIDInfo[i].Time = ST_TIME_USED;
        pDIDInfo[i].Handle = ret;
        st_debug("%s %s: %d-SendTo(%s) done! ret=%d, TimeUsed: %lu ms\n", TimeBuf, APIName, i, pDIDInfo[i].DID, ret, pDIDInfo[i].Time);
        if (0 <= ret)
        {
            counter++;
            GetTime_ms(&TimeBegin, TimeBuf, sizeof(TimeBuf));
            NDT_PPCS_CloseHandle(ret);
            GetTime_ms(&TimeEnd, TimeBuf, sizeof(TimeBuf));
            // st_debug("%s %s: %d-NDT_PPCS_CloseHandle(%d) done! %d ms.\n", TimeBuf, APIName, i, ret, ST_TIME_USED);
        }
    }
    if (0 < counter)
    {
        st_selectSort(pDIDInfo, NumberOfServer); // Sort the Server DID by TimeUsed
        // for (int i = 0; i < NumberOfServer; i++)
        // {
        //     st_debug( "DID[%d]=%s, TimeUsed: %lu ms\n", i, pDIDInfo[i].DID, pDIDInfo[i].Time);
        // }
        //// ServerDIDString: "NN,DID,DID,DID,...,DID"
        //// sample: "03,PPCS-123456-ETLRN,PPCS-123456-HYEXE,PPCS-123456-RFVMV"
        memset(pServerDIDString, 0, StringSize+1);
        SNPRINTF(pServerDIDString, StringSize+1, "%02d", NumberOfServer);
        for (int i = 0; i < NumberOfServer; i++)
        {
            char DID[SIZE_DID];
            memset(DID, 0, SIZE_DID);
            SNPRINTF(DID, SIZE_DID, ",%s", pDIDInfo[i].DID);
            strcat(pServerDIDString, DID);
        }
    }
    if (pServerDID) {free((void *)pServerDID); pServerDID=NULL;}
    if (pDIDInfo) {free((void *)pDIDInfo); pDIDInfo=NULL;}

    if (0 < counter) return 0;
    else return ret;
} // WiPN_Select
