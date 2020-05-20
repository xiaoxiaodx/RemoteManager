#include "warndps.h"
//#include "windows.h"
#include <debuglog.h>
//#include <winsock2.h>   // windows gethostbyname
//#include <ws2tcpip.h>   // getaddrinfo
//#include <conio.h>      // windows getch()

#define QUERY_SERVER_NUMBER     2      // QueryServer DID Number.
WarnDps::WarnDps(QObject *parent) : QObject(parent)
{

    // DebugLog::getInstance()->writeLog("NDT 0");

    //    QString initstr = "EBGDEJBJKDJMGAJMEJGNFPEAHNMMHCJIGFEMBPHHBBNCLLOCCBEIHMOLCOKDJBPOALMOKCGBONJGBFHEJBIEMMAJJIPHAP";
    //    //memcpy(g_NDT_InitString,initstr.data(),initstr.length());

    //    QString keystr = "GaoZhi1234567890";
    //    //memcpy(g_NDT_AES128Key,keystr.data(),keystr.length());

    //    //memcpy(g_DPS_AES128Key,keystr.data(),keystr.length());

    //    QString ip = "120.76.143.156";
    //    //memcpy(g_DPS_IP,ip.data(),ip.length());

    //    QString apname = "iEagleCam";
    //    //memcpy(gAPP_Name,apname.data(),apname.length());
    //    //gQSDID[0] = "INEW-000003-BYRYY";

    //    int ret = 0;

    //    DebugLog::getInstance()->writeLog("NDT 1");

    //    ret = NDT_PPCS_Initialize("EBGDEJBJKDJMGAJMEJGNFPEAHNMMHCJIGFEMBPHHBBNCLLOCCBEIHMOLCOKDJBPOALMOKCGBONJGBFHEJBIEMMAJJIPHAP", 0, NULL, "GaoZhi1234567890");

    //    if (NDT_ERROR_NoError != ret && NDT_ERROR_AlreadyInitialized != ret) {
    //        DebugLog::getInstance()->writeLog("NDT 初始化失败");

    //    }else{
    //        DebugLog::getInstance()->writeLog("NDT 初始化成功");
    //    }

    parameterInit();
}

void WarnDps::parameterInit()
{
    const char *pDID = "INEW-000003-BYRYY";//gDID = "INEW-002468-NYCLM"

    const char *pInitString = "EBGDEJBJKDJMGAJMEJGNFPEAHNMMHCJIGFEMBPHHBBNCLLOCCBEIHMOLCOKDJBPOALMOKCGBONJGBFHEJBIEMMAJJIPHAP";
    const char *pNDT_AES128Key = "GaoZhi1234567890";
    const char *pWiPNKey = "GaoZhi1234567890";

    int QSDID_Index = 8;
    const char *pAPP_Name = "iEagleCam";
    const char *pDPS_IP = "120.76.143.156";
    const char *pDPS_Key = "GaoZhi1234567890";

    const char *gisdid = "INEW-000003-BYRYY";

    unsigned int Len_InitString = strlen(pInitString);
    unsigned int Len_NDT_AES128Key = strlen(pNDT_AES128Key);
    unsigned int Len_DID = strlen(pDID);
    unsigned int Len_WiPNkey = strlen(pWiPNKey);

    memset(g_DID, 0, sizeof(g_DID));
    memset(g_iPNLicense, 0, sizeof(g_iPNLicense));
    memset(g_APP_Name, 0, sizeof(g_APP_Name));
    memset(g_NDT_InitString, 0, sizeof(g_NDT_InitString));
    memset(g_NDT_AES128Key, 0, sizeof(g_NDT_AES128Key));
    memset(g_DPS_IP, 0, sizeof(g_DPS_IP));
    memset(g_DPS_Key, 0, sizeof(g_DPS_Key));
    memset(gWiPN_Key, 0, sizeof(gWiPN_Key));
    memset(g_SPS_IPString, 0, sizeof(g_SPS_IPString));



    memcpy(g_DID, pDID, Len_DID);
    memcpy(g_NDT_InitString, pInitString, Len_InitString);
    memcpy(g_NDT_AES128Key, pNDT_AES128Key, Len_NDT_AES128Key);
    memcpy(g_DPS_Key,pDPS_Key, strlen(pDPS_Key));
    memcpy(g_DPS_IP,pDPS_IP, strlen(pDPS_IP));
    memcpy(g_APP_Name,pAPP_Name, strlen(pAPP_Name));

    memcpy(gWiPN_Key, pWiPNKey, Len_WiPNkey);


    /*
    unsigned int Len_QSDID = strlen(argv[QSDID_Index]);
    unsigned short SizeOfDID = (Len_QSDID/4+2)*4;
    if (!gQSDIDBuf)
    {
        gQSDIDBuf = (char *)malloc(QS_NUM * SizeOfDID);
        if (!gQSDIDBuf)
        {
            printf("malloc QueryDID Buffer failed!!\n");
            return 0;
        }
    }
    memset(gQSDIDBuf, '\0', SizeOfDID * QS_NUM);
    if (!gQSDID)
    {
        gQSDID = (char **)malloc(sizeof(char *)*((QS_NUM/4+1)*4));
        if (!gQSDID)
        {
            printf("malloc gQSDID Buffer failed!!\n");
            if (gQSDIDBuf) {free(gQSDIDBuf); gQSDIDBuf=NULL;}
            return 0;
        }
    }
    memset(gQSDID, 0, sizeof(char *)*((QS_NUM/4+1)*4));
    for (int i = 0; i < QS_NUM; i++)
    {
        memcpy(&gQSDIDBuf[SizeOfDID*i], argv[QSDID_Index+i], Len_QSDID);
        gQSDID[i] = &gQSDIDBuf[SizeOfDID*i];
    }*/

}


void WarnDps::GetAPIVersion()
{
    UINT32 APIVersion;
    DebugLog::getInstance()->writeLog("GetAPIVersion:");
    DebugLog::getInstance()->writeLog(NDT_PPCS_GetAPIVersion(&APIVersion));
    DebugLog::getInstance()->writeLog("--------------------------------------------\n");
    // get DPS Version
    UINT32 DPS_APIVersion;
    DebugLog::getInstance()->writeLog(DPS_GetAPIVersion(&DPS_APIVersion));
    DebugLog::getInstance()->writeLog("--------------------------------------------\n");
    // get SPS Version
    UINT32 SPS_APIVersion;
    DebugLog::getInstance()->writeLog(CS2_SPS_GetAPIVersion(&SPS_APIVersion));
    DebugLog::getInstance()->writeLog("--------------------------------------------\n");
}

void WarnDps::initDps()
{

    //***1***
    GetAPIVersion();

    WSADATA wsaData;
    WORD socketVersion = MAKEWORD(2, 2);
    if (0 != WSAStartup(socketVersion, &wsaData))
    {
        DebugLog::getInstance()->writeLog("Init socket dll error! errno");
        //   printf("Init socket dll error! errno=%d (%s)\n", errno, strerror(errno));
    }

    // ***2***
    int ret;
//    DebugLog::getInstance()->writeLog("NDT_PPCS_Initialize  :");
//    DebugLog::getInstance()->writeLog(g_NDT_InitString);
//    DebugLog::getInstance()->writeLog(g_NDT_AES128Key);
//    ret = NDT_PPCS_Initialize(g_NDT_InitString, Port, NULL, g_NDT_AES128Key);
//    if (NDT_ERROR_NoError == ret && NDT_ERROR_AlreadyInitialized != ret) {
//        DebugLog::getInstance()->writeLog("NDT 初始化成功");
//    }else{
//        DebugLog::getInstance()->writeLog("NDT 初始化失败" + QString::number(ret));
//    }

//    // ***3***. get UTCT from NDT Server. 需在 NDT 初始化后获取 UTCT 时间
//    for (int i = 0; i < 150; i++)
//    {
//        if (0 == time_NDT(NULL)) _WiPN_mSecSleep(20);
//        else break;
//    }
//    st_debug("UTCT=0x%08X\n", time_NDT(NULL));

    // ***4***. Network Detect.
    st_NDT_NetInfo NetInfo;
    for (int times=0;times<3;times++) {
        ret = NDT_PPCS_NetworkDetect(&NetInfo, 3000); //// wait for 3 sec
        DebugLog::getInstance()->writeLog("---------- NDT_PPCS_NetworkDetect ---------- \n");
        DebugLog::getInstance()->writeLog("My Wan IP:"+QString(NetInfo.WanIP));
        DebugLog::getInstance()->writeLog("My Lan IP:"+QString(NetInfo.LanIP)+" port:"+QString(NetInfo.LanPort));
        DebugLog::getInstance()->writeLog("Server Hello Ack: "+QString(1 == NetInfo.bServerHelloAck ? "Yes":"No"));
        DebugLog::getInstance()->writeLog("--------------------------------------------\n");

        if(1 == NetInfo.bServerHelloAck )
            break;
    }


    // ***5***. DPS Initialize
    DebugLog::getInstance()->writeLog("DPS_Initialize:"+QString(g_DPS_IP)+","+QString::number(g_DPS_Port)+","+QString(g_DPS_Key));
    ret = DPS_Initialize(g_DPS_IP, g_DPS_Port, g_DPS_Key, 0);
    if (ERROR_DPS_Successful != ret && ERROR_DPS_AlreadyInitialized != ret)
    {
        DebugLog::getInstance()->writeLog(getDPSErrorCodeInfo(ret));
        return ;
    }
    else
    {
        g_DPS_InitFlag = 1;
        DebugLog::getInstance()->writeLog("DPS_Initialize OK! ret="+QString::number(ret));
    }


    char QSResult[1024] = {};
    unsigned short QSRBufSize = sizeof(QSResult);
    ret = WiPN_WebAPI_QueryAll(gQSDID, QS_NUM, gWiPN_Key, WEB_HOST, WEB_PORT, URL, g_DID, QSResult, &QSRBufSize);

    if (0 > ret)
    {
        st_debug("WiPN WebAPI Query failed: ret=%d [%s]\n", ret, getWiPNErrorCodeInfo(ret));
        // HTTP failed, so, do NDT SendTo.
        unsigned short QSRBufSize = sizeof(QSResult);
        ret = WiPN_QueryAll(g_DID, gQSDID, QS_NUM, QSResult, &QSRBufSize, NULL, NULL);

        if (0 > ret)
        {
            st_info("WiPN Query: failed(%d) [%s]\n", ret, getWiPNErrorCodeInfo(ret));
            return;
        }
    }
    // 更新保存 UTCT
    char RET_UTCT[SIZE_UTCTString] = {};
    if (0 == GetStringItem(QSResult, "UTCT", '&', RET_UTCT, sizeof(RET_UTCT)))
    {
        Update_UTCT(RET_UTCT);
    }
    if (-2 == GetStringItem(QSResult, "Post", '&', g_SNDIDString, sizeof(g_SNDIDString)))
    {
        //st_info("WiPN Query: %d ms => %s\n", ST_TIME_USED, QSResult);
        return;
    }
    // st_info("WiPN Query: %d ms => %s\n", ST_TIME_USED, g_SNDIDString);
    if (0 == GetStringItem(QSResult, "SPS", '&', g_SPS_IPString, sizeof(g_SPS_IPString)))
    {
        st_info("                   => %s\n", g_SPS_IPString);
    }


    // ***7***. Get DPS Token， 获取 dps token。
    ret = DPS_TokenAcquire(g_Token, sizeof(g_Token));

    char SubsCmd[sizeof(g_DID)+sizeof(g_EventCH)+sizeof(g_AG_Name)+sizeof(g_APP_Name)+sizeof(g_Token)+64] = {};
    // 8. Subscribe, 订阅。
    SNPRINTF(SubsCmd, sizeof(SubsCmd), "DID=%s&CH=%lu&AG=%s&APP=%s&INFO=%s&ACT=%s&", g_DID, g_EventCH, g_AG_Name, g_APP_Name, g_Token, "Subscribe"); // ACT="Subscribe"

    char Result[600] = {0};
    unsigned short RBufSize = sizeof(Result);
    // 优先采用 HTTP 方式订阅。
    ret = WiPN_WebAPI_Send(g_SNDIDString, gWiPN_Key, WEB_HOST, WEB_PORT, URL, SubsCmd, Result, &RBufSize, NULL);
    if (0 > ret)
    {
        st_info("WiPN Web Subscribe failed: ret=%d [%s]\n", ret, getWiPNErrorCodeInfo(ret));
        // http 方式失败，改用 NDT 方式订阅。
        RBufSize = sizeof(Result);
        ret = WiPN_API_Send(g_SNDIDString, SubsCmd, Result, &RBufSize, NULL,NULL,NULL);

        if (0 > ret)
        {
            st_info("WiPN Subscribe failed: ret=%d [%s]\n", ret, getWiPNErrorCodeInfo(ret));
            return;
        }
    }

    // 更新 UTCT.
    int SubsFlag = 0;
    if (strstr(Result, "RET=OK")) // Subscribe Success. 订阅成功。
    {
        //st_info("WiPN Subscribe Success: %d ms, DID:%s,CH:%d => %s\n", ST_TIME_USED, g_DID, g_EventCH, Result);
        SubsFlag = 1;
    }
    else // Subscribe failed.  订阅失败。
    {
        // st_info("WiPN Subscribe failed: %d ms, DID:%s,CH:%d => %s\n", ST_TIME_USED, g_DID, g_EventCH, Result);
        SubsFlag = 0;
        return;
    }

}

void WarnDps::recDps(){
    /*

    st_info_T("WiPN_Post: [Post Time]        [RecvNotify Time]\n");
    while (gRunning)//  && Repeat < Total_Times
    {
        if (!IntervalTime) // IntervalTime=0 -> Push for press the Enter key
        {
            char ch = my_getch();
            st_debug("my_getch=%d\n\r", ch);
            if (Ctrl_C == ch || 'q' == ch || 'Q' == ch) break;
        }
        else if (Repeat >= Total_Times) break;
        if (!gRunning) break;
        st_print("\n-----------------------> Repeat=%d\n", ++Repeat);

        if (0 == CreateThread_Post()) g_PostFlag = 0; // 0 ->posting...
        else goto EXIT;

        if (gRunning && !g_Thread_RecvNotify_Running)
        {
            if (0 > CreateThread_RecvNotify()) goto EXIT;
        }
        if (gRunning && !g_Thread_DPSInit_Running)
        {
            if (0 > CreateThread_DPSInit()) goto EXIT;
        }

        my_GetCurrentTime(&TimeBegin);
        // wait post return, when g_PostFlag == 0.
        int sleepCounter = 0;
        while (gRunning && 0 == g_PostFlag) { _WiPN_mSecSleep(50); }
        my_GetCurrentTime(&TimeEnd);
        st_debug("sleep %d ms for wait post!\n", ST_TIME_USED);
        int sleepTime = IntervalTime*1000 - ST_TIME_USED;
        if (0 < sleepTime && -2 != g_PostFlag) mySleep_ms(sleepTime);

        // show WiPN Post info
        st_info("[%04d-%02d-%02d %02d:%02d:%02d.%03d]\t%3u: ", gTimeBegin.Year,
                gTimeBegin.Mon,
                gTimeBegin.Day,
                gTimeBegin.Hour,
                gTimeBegin.Min,
                gTimeBegin.Sec,
                gTimeBegin.mSec, Repeat);
        if (1 == g_PostFlag)
        {
            st_info("%u ms\t", g_TimeUsed_Post);
            t_Max_Used_Post = (t_Max_Used_Post < g_TimeUsed_Post)?g_TimeUsed_Post:t_Max_Used_Post;
            t_Min_Used_Post = (t_Min_Used_Post > g_TimeUsed_Post)?g_TimeUsed_Post:t_Min_Used_Post;
            Total_Time_Post += g_TimeUsed_Post;
            SuccessCounter_Post++;
        }
        else if (-1 == g_PostFlag)
        {
            st_info("failed(%s)", g_PostRET);
        }
        else if (-2 == g_PostFlag)
        {
            st_info("%s", g_PostRET);
            if (   0 == strcmp(g_PostRET, "Invalid LNS")
                   || 0 == strcmp(g_PostRET, "Invalid DID"))
            {
                st_info("\n");
                goto EXIT;
            }
        }
        else st_info("failed(%d)", g_PostFlag);// something is wrong, may be cmd parameter wrong.
        g_TimeUsed_Post = 0;
        g_PostFlag = -99;

        // show DPS RecvNotify info
        if (1 == g_RecvFlag)
        {
            st_info("\t %u ms\n", g_Time_Used_Recv);
            t_Max_Used_Recv = (t_Max_Used_Recv < g_Time_Used_Recv)?g_Time_Used_Recv:t_Max_Used_Recv;
            t_Min_Used_Recv = (t_Min_Used_Recv > g_Time_Used_Recv)?g_Time_Used_Recv:t_Min_Used_Recv;
            Total_Time_Recv += g_Time_Used_Recv;
            SuccessCounter_Recv++;
        }
        else if (0 == g_DPSRET) st_info("\tfailed(%d)\n", ERROR_DPS_TimeOut);
        else st_info("\tfailed(%d)\n", g_DPSRET);

        g_Time_Used_Recv = 0;
        g_RecvFlag = -1;

        for (int i = 0; gRunning && !g_DPS_InitFlag && i < 200; i++)
        {
            _WiPN_mSecSleep(10);
        }
    } // while
    gRunning = 0;

    GetTime_ms(&TimeEnd, TimeBuf, sizeof(TimeBuf));
    st_info("%s: \n", TimeBuf);
    st_info("Push times: %d\n", Repeat);
    if (SuccessCounter_Post)
    {
        Total_Time_Post = Total_Time_Post/SuccessCounter_Post;      // msec

        st_info("Post Success: %d (%f%%, max=%d.%03d sec, averge=%d.%03d sec, min=%d.%03d sec)\n",
                SuccessCounter_Post,
                100.0*((float)SuccessCounter_Post)/((float)Repeat),
                t_Max_Used_Post/1000, t_Max_Used_Post%1000,         // max
                Total_Time_Post/1000, Total_Time_Post%1000 ,        // averge
                t_Min_Used_Post/1000, t_Min_Used_Post%1000);        // min
    }
    else st_info("Post Success: %d (%f%%)\n", SuccessCounter_Post, (float)0);
    if (SuccessCounter_Recv)
    {
        Total_Time_Recv = Total_Time_Recv/SuccessCounter_Recv;      // msec
        st_info("Notification received: %d (%f%%, max=%d.%03d sec, averge=%d.%03d sec, min=%d.%03d sec)\n",
                SuccessCounter_Recv,
                100.0*((float)SuccessCounter_Recv)/((float)Repeat),
                t_Max_Used_Recv/1000, t_Max_Used_Recv%1000,         // max
                Total_Time_Recv/1000, Total_Time_Recv%1000 ,        // averge
                t_Min_Used_Recv/1000, t_Min_Used_Recv%1000);        // min
    }
    else st_info("Notification received: %d (%f%%)\n", SuccessCounter_Recv, (float)0);
    break;*/

}

void WarnDps::subCmd(QString did){

    int gEventCH = 0;
    QString Command = "DID=" + did + "&CH=" + gEventCH + "&AG=DPS" + "&APP=" + gAPP_Name + "&INFO=" + g_Token + "&ACT=Subscribe&";


    int ret ;

    char SubsCmd[sizeof(g_DID)+sizeof(g_EventCH)+sizeof(g_AG_Name)+sizeof(g_APP_Name)+sizeof(g_Token)+64] = {};
    memset(SubsCmd, 0, sizeof(SubsCmd));


    snprintf(SubsCmd,sizeof (SubsCmd), "DID=%s&CH=%lu&AG=%s&APP=%s&INFO=%s&ACT=%s&", g_DID, g_EventCH, "DPS", g_APP_Name, g_Token, "Subscribe");

    char Result[600] = {0};
    unsigned short RBufSize = sizeof(Result);
    // ret = WiPN_API_Send(g_SubsString, SubsCmd, Result, &RBufSize, g_UTCTString, NULL,NULL);
    ret = WiPN_API_Send(g_SubsString, SubsCmd, Result, &RBufSize, NULL, NULL,NULL);



    char RETBuf[32] = {};
    GetStringItem(Result, "RET", '&', RETBuf, sizeof(RETBuf));
    if (strstr(Result, "RET=OK")) // Subscribe Success. 订阅成功。
    {
        DebugLog::getInstance()->writeLog("WiPN Subscribe succ ");
        //SubsFlag = 1;
    }
    else // Subscribe failed.  订阅失败。
    {
        DebugLog::getInstance()->writeLog("WiPN Subscribe failed:");
    }
}


const char*WarnDps::getDPSErrorCodeInfo(int err)
{
    switch (err)
    {
    // DPS Error
    case 0: return "ERROR_DPS_Successful";
    case -1: return "ERROR_DPS_NotInitialized";
    case -2: return "ERROR_DPS_AlreadyInitialized";
    case -3: return "ERROR_DPS_TimeOut";
    case -4: return "ERROR_DPS_FailedToResolveHostName";
    case -5: return "ERROR_DPS_FailedToCreateSocket";
    case -6: return "ERROR_DPS_FailedToBindPort";
    case -7: return "ERROR_DPS_FailedToConnectServer";
    case -8: return "ERROR_DPS_FailedToRecvData";
    case -9: return "ERROR_DPS_NotEnoughBufferSize";
    case -10: return "ERROR_DPS_InvalidAES128Key";
    case -11: return "ERROR_DPS_InvalidToken";
    case -12: return "ERROR_DPS_OnRecvNotify";
    case -13: return "ERROR_DPS_OnAcquireToken";
    case -14: return "ERROR_DPS_NotOnRecvNotify";
    default: return "Unknown, Not the DPS Error code!";
    }
}
