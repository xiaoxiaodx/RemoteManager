#include "WiPN_Common.h"

//// ---------------- Very important ----------------- ////
//// 以下两个变量 gUTCTString 与 gLocalT0 在正确获取UTCT值后，请务必将相应的值保存至本地，为下次获取新的 UTCT 提供计算参数。
//// gUTCTString 与 gLocalT0 必须同步更新。
char gUTCTString[SIZE_UTCTString] = {};  // 保存从服务器获取的 UTCT 时间。
time_t gLocalT0 = 0;                     // 保存从获取服务器获取 UTCT 成功时返回的本地时间。
char gUTCTServerIP[20] = {};    // 用于保存域名解析的结果，即 UTCT Server IP.
//// ------------------------------------------------- ////

void _WiPN_mSecSleep(unsigned int ms)
{
#if defined(WIN32DLL) || defined(WINDOWS)
    Sleep(ms);
#elif defined LINUX
    usleep(ms * 1000);
#endif
}

// return:0->OK,-1->error.
int WinSockInit()
{
#if defined(WIN32DLL) || defined(WINDOWS)
    WSADATA wsaData;
    WORD socketVersion = MAKEWORD(2, 2);
    if (0 != WSAStartup(socketVersion, &wsaData))
    {
        st_debug("WSAStartup Init failed: errno=%d (%s)\n", errno, strerror(errno));
        return -1;
    }
#endif
    return 0;
}

void WinSockDeInit()
{
#if defined(WINDOWS) || defined(WIN32DLL)
    WSACleanup();
#endif
}

const char *getNDTErrorCodeInfo(int err)
{
    switch (err)
    {   // NDT Error
        case 0: return "NDT_ERROR_NoError";
        case -1: return "NDT_ERROR_AlreadyInitialized";
        case -2: return "NDT_ERROR_NotInitialized";
        case -3: return "NDT_ERROR_TimeOut";
        case -4: return "NDT_ERROR_ScketCreateFailed";
        case -5: return "NDT_ERROR_ScketBindFailed";
        case -6: return "NDT_ERROR_HostResolveFailed";
        case -7: return "NDT_ERROR_ThreadCreateFailed";
        case -8: return "NDT_ERROR_MemoryAllocFailed";
        case -9: return "NDT_ERROR_NotEnoughBufferSize";
        case -10: return "NDT_ERROR_InvalidInitString";
        case -11: return "NDT_ERROR_InvalidAES128Key";
        case -12: return "NDT_ERROR_InvalidDataOrSize";
        case -13: return "NDT_ERROR_InvalidDID";
        case -14: return "NDT_ERROR_InvalidNDTLicense";
        case -15: return "NDT_ERROR_InvalidHandle";
        case -16: return "NDT_ERROR_ExceedMaxDeviceHandle";
        case -17: return "NDT_ERROR_ExceedMaxClientHandle";
        case -18: return "NDT_ERROR_NetworkDetectRunning";
        case -19: return "NDT_ERROR_SendToRunning";
        case -20: return "NDT_ERROR_RecvRunning";
        case -21: return "NDT_ERROR_RecvFromRunning";
        case -22: return "NDT_ERROR_SendBackRunning";
        case -23: return "NDT_ERROR_DeviceNotOnRecv";
        case -24: return "NDT_ERROR_ClientNotOnRecvFrom";
        case -25: return "NDT_ERROR_NoAckFromCS";
        case -26: return "NDT_ERROR_NoAckFromPushServer";
        case -27: return "NDT_ERROR_NoAckFromDevice";
        case -28: return "NDT_ERROR_NoAckFromClient";
        case -29: return "NDT_ERROR_NoPushServerKnowDevice";
        case -30: return "NDT_ERROR_NoPushServerKnowClient";
        case -31: return "NDT_ERROR_UserBreak";
        case -32: return "NDT_ERROR_SendToNotRunning";
        case -33: return "NDT_ERROR_RecvNotRunning";
        case -34: return "NDT_ERROR_RecvFromNotRunning";
        case -35: return "NDT_ERROR_SendBackNotRunning";
        case -36: return "NDT_ERROR_RemoteHandleClosed";
        case -99: return "NDT_ERROR_FAESupportNeeded";
        default: return "Unknown, something is wrong!";
    }
} // getNDTErrorCodeInfo

const char *getSPSErrorCodeInfo(int err)
{
    if (0 < err) return strerror(err);
    switch (err)
    {
        // SPS Error
        case 0: return "ERROR_SPS_NoError";
        case -1: return "ERROR_SPS_InvalidParameter";
        case -2: return "ERROR_SPS_InvalidFunCode";
        case -3: return "ERROR_SPS_TimeOut";
        case -4: return "ERROR_SPS_AuthWordError";
        case -5: return "ERROR_SPS_FileNotExist";
        case -6: return "ERROR_SPS_BufferNotEnough";
        case -7: return "ERROR_SPS_UserBreak";
        case -8: return "ERROR_SPS_NotEnoughMemory";
        case -9: return "ERROR_SPS_InvalidDID";
        case -10: return "ERROR_SPS_ServerCloseSession";
        case -11: return "ERROR_SPS_LocalSocketTimeout";
        case -12: return "ERROR_SPS_UploadIsNotRunning";
        case -13: return "ERROR_SPS_ExceedMaxPINFOSize";
        case -14: return "ERROR_SPS_ExceedMaxAINFOSize";
        case -15: return "ERROR_SPS_ExceedMaxSnapshotSize";
        case -16: return "ERRPR_SPS_UploadTemporaryDisabled";
        case -98: return "ERROR_SPS_ServerError";
        case -99: return "ERROR_SPS_UnknownError";
        default: return "Unknown, something is wrong!";
    }
}

const char *getWiPNErrorCodeInfo(int err)
{
    if (-99 <= err) return getNDTErrorCodeInfo(err);
    switch (err)
    {
        // WiPN && Web TCP/UDP Error code info
        case WiPN_ERROR_InvalidParameter: return "WiPN_ERROR_InvalidParameter";
        case WiPN_ERROR_MallocFailed: return "WiPN_ERROR_MallocFailed";
        case WiPN_ERROR_ExceedMaxSize: return "WiPN_ERROR_ExceedMaxSize";
        case WiPN_ERROR_TimeOut: return "WiPN_ERROR_TimeOut";
        case WiPN_ERROR_StringParseFailed: return "WiPN_ERROR_StringParseFailed";
        case WiPN_ERROR_StringEncFailed: return "WiPN_ERROR_StringEncFailed";
        case WiPN_ERROR_StringDecFailed: return "WiPN_ERROR_StringDecFailed";
        case WiPN_ERROR_SocketInitFailed: return "WiPN_ERROR_SocketInitFailed";
        case WiPN_ERROR_HostResolveFailed: return "WiPN_ERROR_HostResolveFailed";
        case WiPN_ERROR_SetNonBlockFailed: return "WiPN_ERROR_SetNonBlockFailed";
        case WiPN_ERROR_SocketCreateFailed: return "WiPN_ERROR_SocketCreateFailed";
        case WiPN_ERROR_SocketConnectFailed: return "WiPN_ERROR_SocketConnectFailed";
        case WiPN_ERROR_InvalidSocketID: return "WiPN_ERROR_InvalidSocketID";
        case WiPN_ERROR_SetSockOptFailed: return "WiPN_ERROR_SetSockOptFailed";
        case WiPN_ERROR_SocketWriteFailed: return "WiPN_ERROR_SocketWriteFailed";
        case WiPN_ERROR_SocketReadFailed: return "WiPN_ERROR_SocketReadFailed";
        case WiPN_ERROR_RemoteSocketClosed: return "WiPN_ERROR_RemoteSocketClosed";
        case WiPN_ERROR_SelectError: return "WiPN_ERROR_SelectError";
        case WiPN_ERROR_GetHttpBodyFailed: return "WiPN_ERROR_GetHttpBodyFailed";
        default: return "Unknown, something is wrong!";
    }
}

/*
//// GetStrItem: string format must be: "IPxxxxxxPyyyy", such as:"IP127.0.0.1Port32121", So we need to use this API to get IP(xxxxxx) or port(yyyy), and we can use this API to get other similar strings.
Example:
    char *DLInfo = "IP127.0.0.1Port32121";
    char IP[24] = {};
    GetStrItem(DLInfo, "IP", 'P', IP, sizeof(IP));
//// return code: ret=0 OK, ret=-1: Invalid Parameter, ret=-2: No such Item
*/
int GetStrItem( const char *SrcStr,
                const char *ItemName,
                const char Seperator,
                char *RetString,
                const int MaxSize)
{
    if (!SrcStr || !ItemName || !RetString || 0 == MaxSize)
    {
        return -1;
    }
    const char *pFand = SrcStr;
    while (1)
    {
        pFand = strstr(pFand, ItemName);
        if (!pFand) return -2;
        break;
    }
    pFand += strlen(ItemName);
    memset(RetString, 0, MaxSize);

    int i = 0;
    while (1)
    {
        if (Seperator == *(pFand + i) || '\0' == *(pFand + i) || i >= (MaxSize - 1))
        {
            break;
        }
        else
        {
            *(RetString + i) = *(pFand + i);
        }
        i++;
    }
    *(RetString + i) = '\0';
    return 0;
}

//// ret=0 OK, ret=-1: Invalid Parameter, ret=-2: No such Item
int GetStringItem(  const char *SrcStr,
                    const char *ItemName,
                    const char Seperator,
                    char *RetString,
                    const int MaxSize)
{
    if (!SrcStr || !ItemName || !RetString || 0 == MaxSize)
    {
        return -1;
    }
    const char *pFand = SrcStr;
    while (1)
    {
        pFand = strstr(pFand, ItemName);
        if (!pFand) return -2;
        pFand += strlen(ItemName);
        if ('=' != *pFand) continue;
        else break;
    }
    memset(RetString, 0, MaxSize);
    pFand += 1;
    int i = 0;
    while (1)
    {
        if (Seperator == *(pFand + i) || '\0' == *(pFand + i) || i >= (MaxSize - 1))
        {
            break;
        }
        else
        {
            *(RetString + i) = *(pFand + i);
        }
        i++;
    }
    *(RetString + i) = '\0';
    return 0;
}

//// parse_number: to get DID Number and DID Lenght, pServerString such as: "Post=02,ABCD-000000-ABCDE,ABCD-000000-ABCDE&", call parse_number to get DID Number=02.
//// return: 0->OK, <0 failed.
int parse_number(const char *pServerString, unsigned short *pOutput_DIDNumber, unsigned char *pOutput_DIDLen)
{
    if (!pServerString || !pOutput_DIDNumber || !pOutput_DIDLen)
    {
        return -1;
    }
    char buf[8];
    memset(buf, 0, sizeof(buf));
    const char *pS = pServerString;
    const char *p1 = strstr(pServerString, ","); // -> First ','
    if (!p1) return -1;
    if (p1 - pS > sizeof(buf) - 1) return -1;

    int i = 0;
    while (1)
    {
        if (pS + i >= p1) // PS -> First ','
        {
            break;
        }
        buf[i] = *(pS + i);
        i++;
    }
    buf[i] = '\0';
    *pOutput_DIDNumber = atoi(buf);

    // Get PostServerDID length
    p1 += 1;    // -> point the First DID
    const char *p2 = strstr(p1, ",");
    if (!p2)    // -> Only one DID -> "01,ABCD-123456-ABCDEF"
    {
        *pOutput_DIDLen = strlen(p1);
    }
    else
    {
        *pOutput_DIDLen = (unsigned char)(p2 - p1);
    }
    return 0;
}

//// return: 0->OK, <0 failed.
int GetOneDID(const char *pServerString, int index, char *output_OneDID, unsigned int outputBufSize)
{
    if (!pServerString || 0 > index || !output_OneDID || 11 > outputBufSize)
    {
        return -1;
    }
    const char *p1 = strstr(pServerString, ",");
    if (!p1) return -1;

    p1 += 1;        // -> point the First DID
    const char *p2 = strstr(p1, ",");
    if (!p2) // -> Only one DID -> "01,ABCD-123456-ABCDEF"
    {
        unsigned char LengthOfDID = strlen(p1);
        if (0 == LengthOfDID) return -1;
        //st_debug("in parse_DID: LengthOfDID= %d\n", LengthOfDID);
        memset(output_OneDID, '\0', outputBufSize);
        memcpy(output_OneDID, p1, LengthOfDID);
        return 0;
    }
    unsigned char SizeOfDID = (unsigned char)(p2 - p1);
    p1 = pServerString;
    int i = 0;
    for (; i < index + 1; i++)
    {
        p1 = strstr(p1, ",");
        if (!p1) break;
        p1 += 1;
    }
    if (!p1) return -1;
    memset(output_OneDID, '\0', outputBufSize);
    memcpy(output_OneDID, p1, SizeOfDID);
    return 0;
} // GetOneDID

//// return: success->DID,failed->NULL.
//// after call parse_DID,if success, you must call free() to release memory buffer.
const char *parse_DID(const char *pServerString, int index)
{
    if (!pServerString || 0 > index)
    {
        return NULL;
    }
    const char *p1 = strstr(pServerString, ",");
    if (!p1)
    {
        return NULL;
    }
    p1 += 1;        // -> point the First DID

    const char *p2 = strstr(p1, ",");
    if (!p2) // -> Only one DID -> "01,ABCD-123456-ABCDEF"
    {
        unsigned char LengthOfDID = strlen(p1);
        if (0 == LengthOfDID)
        {
            return NULL;
        }
        //st_debug("in parse_DID: LengthOfDID= %d\n", LengthOfDID);
        char *pDID = (char *)malloc((LengthOfDID/4+1)*4);
        if (!pDID)
        {
            st_debug("parse_DID - malloc failed!!\n");
            return NULL;
        }
        memset(pDID, '\0', (LengthOfDID/4+1)*4);
        memcpy(pDID, p1, LengthOfDID);
        return pDID;
    }
    unsigned char SizeOfDID = (unsigned char)(p2 - p1);
    p1 = pServerString;
    int i = 0;
    for (; i < index + 1; i++)
    {
        p1 = strstr(p1, ",");
        if (!p1)
        {
            break;
        }
        p1 += 1;
    }
    if (!p1)
    {
        return NULL;
    }
    char *pDID = (char *)malloc((SizeOfDID/4+1)*4);
    if (!pDID)
    {
        st_debug("in parse_DID: malloc failed!!\n");
        return NULL;
    }
    memset(pDID, '\0', (SizeOfDID/4+1)*4);
    memcpy(pDID, p1, SizeOfDID);
    return pDID;
}

//// return:0->OK, <0 failed.
int Split_DID(const char *pServerDIDString, unsigned short *pOutput_DIDNumber, unsigned char *pOutput_DIDLen, char **pResultBuf)
{
    if (!pServerDIDString || !pOutput_DIDNumber || !pOutput_DIDLen || !pResultBuf)
    {
        st_info("Split_DID: Invalid Parameter!!\n");
        return WiPN_ERROR_InvalidParameter;
    }
    //// ServerDIDString: "NN,DID,DID,DID,...,DID"
    //// sample: "03,PPCS-123456-ETLRN,PPCS-123456-HYEXE,PPCS-123456-RFVMV"
    //// Get Number from ServerDIDString
    if (0 > parse_number(pServerDIDString, pOutput_DIDNumber, pOutput_DIDLen) || 0 == *pOutput_DIDNumber)
    {
        st_info("Split_DID: parse_number failed!!\n");
        return -1;
    }
    *pOutput_DIDLen = (*pOutput_DIDLen/4+1)*4; // Keep enough distance between DID
    unsigned short sizeOfmalloc = (*pOutput_DIDLen) * (*pOutput_DIDNumber);
    // Allocate memory space according to the number of SubscribeServerDID
    *pResultBuf = (char *)malloc(sizeOfmalloc);
    if (!(*pResultBuf))
    {
        st_info("Split_DID: malloc ServerDID Buf failed!!\n");
        return -1;
    }
    memset(*pResultBuf, '\0', sizeOfmalloc);

#if 1
    //// Get DID From ServerDIDString
    for (int i = 0; i < *pOutput_DIDNumber; i++)
    {
        char OneDID[SIZE_DID] = {};
        if (0 > GetOneDID(pServerDIDString, i, OneDID, sizeof(OneDID)))
        {
            return -1;
        }
        memcpy(&(*pResultBuf)[(*pOutput_DIDLen)*i], OneDID, strlen(OneDID));
        //st_debug("Split_DID: pResultBuf[%d]= %s\n", i, &(*pResultBuf)[(*pOutput_DIDLen)*i]);
    }
#else
    //// Get DID From ServerDIDString
    const char *pDID = NULL;
    int i = 0;
    for ( ; i < *pOutput_DIDNumber; i++)
    {
        pDID = parse_DID(pServerDIDString, i);
        if (!pDID)
        {
            free((void *)(*pResultBuf));
            return -1;
        }
        memcpy(&(*pResultBuf)[(*pOutput_DIDLen)*i], pDID, strlen(pDID));
        //st_debug("Split_DID: pResultBuf[%d]= %s\n", i, &(*pResultBuf)[(*pOutput_DIDLen)*i]);
        free((void*)pDID);
        pDID = NULL;
    }
#endif
    return 0;
}

// Get Body Data From Http_Read
int GetHTTPBody(const char *SrcStr, const char *Seperator, char *RetStr, unsigned int MaxSizeOfRetStr)
{
    if (!SrcStr || !Seperator || !RetStr || 0 == MaxSizeOfRetStr || 0 == strlen(SrcStr))
    {
        return -1;
    }
    const char *pData = strstr(SrcStr, Seperator);
    if (!pData) return -1;
    pData += strlen(Seperator);
    if (!pData || 0 == strlen(pData)) return -1;

    int i = 0;
    memset(RetStr, 0, MaxSizeOfRetStr);
    while (1)
    {
        if (0 == *(pData + i) || i >= (int)(MaxSizeOfRetStr - 1))
        {
            break;
        }
        *(RetStr + i) = *(pData + i);
        i++;
    }
    *(RetStr + i) = '\0';
    return 0;
}

// ret:0->OK, <0,failed.
int GetHostIP(const char *Host, char *output_IP, unsigned int size)
{
    if (!Host || 0 == strlen(Host) || !output_IP || 16 > size) return WiPN_ERROR_InvalidParameter;
    memset(output_IP, 0, size);

    st_Time_Info TimeBegin, TimeEnd;
    char TimeBuf[] = "[YYYY-MM-DD hh:mm:ss.xxx]";

    st_debug("Begin gethostbyname(%s)...\n", Host);
    GetTime_ms(&TimeBegin, TimeBuf, sizeof(TimeBuf));
    struct hostent *pHost = gethostbyname(Host);
    GetTime_ms(&TimeEnd, TimeBuf, sizeof(TimeBuf));
    if (!pHost)
    {
        st_debug("gethostbyname failed: %d ms, errno=%d (%s)\n", ST_TIME_USED, errno, strerror(errno));
        return WiPN_ERROR_HostResolveFailed;
    }
    else
    {
        //const char *pAddr = inet_ntop(pHost->h_addrtype, pHost->h_addr, dest, sizeof(dest));
        const char *pAddr = inet_ntoa(*(struct in_addr*)pHost->h_addr);
        // memcpy(output_IP, pAddr, strlen(pAddr));
        SNPRINTF(output_IP, size, "%s", pAddr);
    }
    st_debug("After gethostbyname:%d ms, result:%s\n", ST_TIME_USED, output_IP);
    return 0;
}

// ret:0->OK, <0,failed.
int setSktNonBlock(int socket)
{
#if defined(WINDOWS) || defined(WIN32DLL)
    unsigned long on_windows=1;
    if (ioctlsocket(socket, FIONBIO, &on_windows) < 0)
    {
        st_debug("ioctlsocket failed: errno=%d (%s)\n", errno, strerror(errno));
        return WiPN_ERROR_SetNonBlockFailed;
    }
#else
    int flags = fcntl(socket, F_GETFL);
    if (0 > flags)
    {
        st_debug("fcntl(socket, GETFL) failed: errno=%d (%s)\n", errno, strerror(errno));
        return WiPN_ERROR_SetNonBlockFailed;
    }
    if (0 > fcntl(socket, F_SETFL, flags | O_NONBLOCK))
    {
        st_debug("fcntl(socket, F_SETFL, flags|O_NONBLOCK) failed: errno=%d (%s)\n", errno, strerror(errno));
        return WiPN_ERROR_SetNonBlockFailed;
    }
#endif
    return 0;
}

// ret: <0: Invalid Parameter or socket read error or timeout.
//      >=0: data size.
int UDP_Recv_Till_TimeOut(int Skt, char *RecvBuf, int SizeToRead, unsigned int TimeOut_ms)
{
    if (0 > Skt || !RecvBuf || 0 == SizeToRead)
    {
        st_debug("UDP_Recv_Till_TimeOut: Invalid Parameter!!\n");
        return WiPN_ERROR_InvalidParameter;
    }
    setSktNonBlock(Skt);

    st_Time_Info TimeBegin, TimeEnd, TimeStart;
    char TimeBuf[] = "[YYYY-MM-DD hh:mm:ss.xxx]";
    size_t size = 0;
    int Times = TimeOut_ms/10;
    struct sockaddr_in fromAddr;
    memset(&fromAddr, 0, sizeof(fromAddr));
    unsigned int sin_size = sizeof(struct sockaddr_in);

    GetTime_ms(&TimeBegin, TimeBuf, sizeof(TimeBuf));
    while (1)
    {
        GetTime_ms(&TimeStart, TimeBuf, sizeof(TimeBuf));
        size = recvfrom(Skt, RecvBuf, SizeToRead, 0, (struct sockaddr *)&fromAddr, (socklen_t*)&sin_size);
        GetTime_ms(&TimeEnd, TimeBuf, sizeof(TimeBuf));

        if (SizeToRead == size)
        {
            st_debug("UDP recvfrom: Skt=%d, TimeUsed:%d ms, data(%u Byte): %s\n", Skt, ST_TIME_USED, size, RecvBuf);
            break;
        }
        // if (EAGAIN != errno && 0 != errno)
        // {
        //     st_debug("UDP recvfrom: ret=%d, Skt=%d, TimeUsed:%d ms, errno=%d (%s)\n", size, Skt, ST_TIME_USED, errno, strerror(errno));
        //     break;
        // }
        if (ST_TIME_USED >= TimeOut_ms || !Times) // 耗时已超过或达到所设定的超时时间。
        {
            if (0 < size) break;
            else return WiPN_ERROR_TimeOut;
        }
        else if (Times > 0)
        {
            _WiPN_mSecSleep(10);
            Times--;
            continue;
        }
    } // while
    return size;
} // UDP_recv_With_TimeOut

// ret: <0: Invalid Parameter or socket read error or timeout.
//      >=0: data size.
int TCP_Read_Till_TimeOut(int Skt, char *ReadBuf, int SizeToRead, unsigned int TimeOut_ms)
{
    if (0 > Skt || !ReadBuf || 0 == SizeToRead)
    {
        st_debug("TCP_Read_Till_TimeOut: Invalid Parameter!!\n");
        return WiPN_ERROR_InvalidParameter;
    }
    setSktNonBlock(Skt);

    st_Time_Info TimeBegin, TimeEnd;
    char TimeBuf[] = "[YYYY-MM-DD hh:mm:ss.xxx]";
    size_t len = 0;
    int Times = TimeOut_ms/10;
    int SizeCount = 0;
    GetTime_ms(&TimeBegin, TimeBuf, sizeof(TimeBuf));
    while (1)
    {
        char oneByte;
#if defined(WINDOWS) || defined(WIN32DLL)
        len = recv(Skt, &oneByte, 1, 0);
#else
        len = read(Skt, &oneByte, 1);
#endif
        GetTime_ms(&TimeEnd, TimeBuf, sizeof(TimeBuf));
        if (1 == len)
        {
            ReadBuf[SizeCount] = oneByte;
            if (++SizeCount == SizeToRead) break; // done
        }
        else if (0 == len) // remote skt close.
        {
            st_debug("TCP Read: ret=%d, Skt=%d, SizeCount=%d, TimeUsed:%d ms\n", len, Skt, SizeCount, ST_TIME_USED);
            break;
        }
        else // error
        {
            // if (EAGAIN != errno && 0 != errno)
            // {
            //     st_debug("TCP read: ret=%d, Skt=%d, SizeCount=%d, TimeUsed:%d ms, errno=%d (%s)\n", len, Skt, SizeCount, ST_TIME_USED, errno, strerror(errno));
            //     if (0 < SizeCount) break;
            //     else return WiPN_ERROR_SocketReadFailed;
            // }
            if (ST_TIME_USED >= TimeOut_ms || !Times) // 耗时已超过或达到所设定的超时时间。
            {
                if (0 < SizeCount) break;
                else return WiPN_ERROR_TimeOut;
            }
            else if (Times > 0)
            {
                _WiPN_mSecSleep(10);
                Times--;
                continue;
            }

        }
    } // while
    return SizeCount;
} // TCP_Read_Till_TimeOut

// ret: 0->OK, <0 ->timeout or failed.
int TCP_Connect_Till_TimeOut(int Skt, struct sockaddr_in serveraddr, int TimeOut_ms)
{
    if (0 > Skt)
    {
        st_debug("TCP_Connect_Till_TimeOut: Invalid Skt Parameter!!\n");
        return WiPN_ERROR_InvalidParameter;
    }
    st_Time_Info TimeBegin, TimeEnd, TimeStart;
    char TimeBuf[] = "[YYYY-MM-DD hh:mm:ss.xxx]";

    int ret = 0;
    int Times = TimeOut_ms/10;
    st_debug("connect to %s:%d ...\n", inet_ntoa(serveraddr.sin_addr), ntohs(serveraddr.sin_port));
    GetTime_ms(&TimeBegin, TimeBuf, sizeof(TimeBuf));

    while (1)
    {
        GetTime_ms(&TimeStart, TimeBuf, sizeof(TimeBuf));
        ret = connect(Skt, (struct sockaddr *)&serveraddr, sizeof(struct sockaddr));
        GetTime_ms(&TimeEnd, TimeBuf, sizeof(TimeBuf));

        // if (0 > ret)
        // {
        //     st_debug("ERROR, connect to %s:%d failed: ret=%d, TimeUsed:%d ms, errno=%d (%s)\n", inet_ntoa(serveraddr.sin_addr), ntohs(serveraddr.sin_port), ret, ST_TIME_USED, errno, strerror(errno));
        // }
        if (0 == ret) // 连接成功。
        {
            st_debug("connect to %s:%d Success! ret=%d, TimeUsed:%d ms\n", inet_ntoa(serveraddr.sin_addr), ntohs(serveraddr.sin_port), ret, ST_TIME_USED);
            break;
        }
        if (EISCONN == errno)
        {
            st_debug("errno=%d (%s)\n", errno, strerror(errno));
            return 0;
        }
        if (ST_TIME_USED >= TimeOut_ms || !Times) // 连接耗时已超过或达到所设定的超时时间。
        {
            return WiPN_ERROR_TimeOut;
        }
        if (EINPROGRESS == errno || EALREADY == errno)
        {
            _WiPN_mSecSleep(10);
            Times--;
            continue;
        }
    }
    return ret;
}

//// 更新 UTCT
//// ret:0->OK, <0 failed.
int Update_UTCT(const char *UTCT)
{
    if (!UTCT || 0 == strlen(UTCT))
    {
        st_info("in Update_UTCT: Invalid UTCT parameter!!\n");
        return WiPN_ERROR_InvalidParameter;
    }
    //// 更新 UTCT
    memset(gUTCTString, 0, sizeof(gUTCTString));
    SNPRINTF(gUTCTString, sizeof(gUTCTString), "%s", UTCT);
    gLocalT0 = time(NULL);
    return 0;
}

//// time_UTCT 内部的实现:
//// 1.先判断与上一次向服务器询问的时间间隔是否超过24小时，超过24小时未向服务器询问过UTCT，则询问一次。
//// 2.若与上一次询问的时间间隔在24小时之内，则返回[本地记录的时间戳与上一次询问的UTCT之和]，保证在 24 小时内不得重复向服务器询问。
//// 3.time_UTCT 会进行域名解析，网络很差情况下将会阻塞非常耗时，建议保存域名解析的结果IP，下一次调用直接使用IP。
//// return: UTCT.
unsigned int time_UTCT(unsigned int *t) //
{
    int time_Interval = time(NULL) - gLocalT0; // sec
    unsigned long UTCT_Now = time_Interval + strtol(gUTCTString, NULL, 16);
    if (t) *t = UTCT_Now;
    if (86400 > time_Interval) // 判断与上一次询问服务器的时间间隔是否超过24小时。
    {
        return UTCT_Now; // 未超过24小时，则直接返回（本地时间戳与上一次获取的 UTCT 之和）。
    }

    st_Time_Info TimeBegin, TimeEnd, TimeInfo;
    char TimeBuf[] = "[YYYY-MM-DD hh:mm:ss.xxx]";

    if (0 > WinSockInit())
    {
        return UTCT_Now;
    }
    //// 将域名解析的IP保存至全局，下次直接拿来用，无需再次域名解析。
    if (0 == strlen(gUTCTServerIP) && 0 > GetHostIP(UTCT_SERVER_HOST, gUTCTServerIP, sizeof(gUTCTServerIP)))
    {
        WinSockDeInit();
        return UTCT_Now;
    }

    struct sockaddr_in serveraddr;
    memset((void *)&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr(gUTCTServerIP);
    serveraddr.sin_port = htons(UTCT_SERVER_PORT);
    // unsigned int sin_len = sizeof(struct sockaddr_in);
    char CMD[] = {REQUEST_STRING};
    char ReadBuf[17] = {};
    memset(ReadBuf, 0, sizeof(ReadBuf));
    int size = 0;
    int ret = 0;
    //// ------------------------ UDP ------------------------ ////
    int UDPSkt = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (0 > UDPSkt)
    {
        st_debug("ERROR, create UDP socket failed: errno=%d (%s)\n", errno, strerror(errno));
        WinSockDeInit();
        return UTCT_Now;
    }
    setSktNonBlock(UDPSkt);

    for (int i = 0; i < 2; i++)
    {
        GetTime_ms(&TimeBegin, TimeBuf, sizeof(TimeBuf));
        ret = sendto(UDPSkt, CMD, sizeof(CMD), 0, (struct sockaddr *)&serveraddr, sizeof(struct sockaddr_in));
        GetTime_ms(&TimeEnd, TimeBuf, sizeof(TimeBuf));
        if (0 > ret)
        {
            st_debug("UDP sendto CMD(%u Byte) to UTCTServer(%s:%d) failed: TimeUsed:%d ms, errno=%d (%s)\n",sizeof(CMD),inet_ntoa(serveraddr.sin_addr),ntohs(serveraddr.sin_port), ST_TIME_USED, errno, strerror(errno));
            break;
        }
        st_debug("UDP sendto CMD(%u Byte) to UTCTServer(%s:%d) done!! TimeUsed:%d ms\n",sizeof(CMD),inet_ntoa(serveraddr.sin_addr), ntohs(serveraddr.sin_port), ST_TIME_USED);
        st_debug("UDP Recv_Till_TimeOut(Skt:%d, ..., readsize:%d, timeout:%d ms) ...\n", UDPSkt, 16, 1000);
        size = UDP_Recv_Till_TimeOut(UDPSkt, ReadBuf, 16, 1000);
        // 关键!! 保存返回的本地时间
        GetTime_ms(&TimeInfo, TimeBuf, sizeof(TimeBuf));
        if (0 >= size)
        {
            continue;
        }
        else
        {
            ReadBuf[size] = '\0';
            if (16 != size) st_debug("UDP recv Invalid data(%u Byte):%s\n", size, ReadBuf);
            break;
        }
        break;
    }
    my_SocketClose(UDPSkt);

    if (0 >= size) // UDP 获取失败改用 TCP 获取。
    {
        //// ------------------------ TCP ------------------------ ////
        int TCPSkt = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (0 > TCPSkt)
        {
            st_debug("ERROR, create TCP socket failed: ret=%d, errno=%d (%s)", TCPSkt, errno, strerror(errno));
            WinSockDeInit();
            return UTCT_Now;
        }
        int TimeOut_ms = 3000;
        // 设置非阻塞
        /* set non-blocking mode on socket */
        int res = setSktNonBlock(TCPSkt);
        if (0 == res) st_debug("setSktNonBlock Success!!\n");
        else TimeOut_ms = 0;
        if (0 != TCP_Connect_Till_TimeOut(TCPSkt, serveraddr, TimeOut_ms))
        {
            my_SocketClose(TCPSkt);
            WinSockDeInit();
            return UTCT_Now;
        }
        st_debug("TCP send Request CMD(%u byte) to UTCTServer(%s:%d) ...\n", sizeof(CMD), inet_ntoa(serveraddr.sin_addr), ntohs(serveraddr.sin_port));
        //// ---------------------- TCP Send ---------------------- ////
#if defined(WINDOWS) || defined(WIN32DLL)
        size = send(TCPSkt, CMD, sizeof(CMD), 0);
#else
        size = write(TCPSkt, CMD, sizeof(CMD));
#endif
        if (0 >= size)
        {
            st_debug("ERROR, TCP send failed: ret=%d, errno=%d (%s)\n", size, errno, strerror(errno));
            my_SocketClose(TCPSkt);
            WinSockDeInit();
            return UTCT_Now;
        }
        else
        {
            st_debug("TCP send data(%u Byte):%s, [Success]\n", size, CMD);
        }
        //// ---------------------- TCP Read ---------------------- ////
        st_debug("TCP Read_Till_TimeOut(Skt:%d, ..., readsize:%d, timeout:%d ms) ...\n", TCPSkt, 16, 1000);
        size = TCP_Read_Till_TimeOut(TCPSkt, ReadBuf, 16, 1000);
        // 关键!! 保存返回的本地时间
        GetTime_ms(&TimeInfo, TimeBuf, sizeof(TimeBuf));
        if (16 != size)
        {
            if (0 < size)
            {
                ReadBuf[size] = '\0';
                st_debug("TCP recv Invalid data(%u Byte):%s\n", size, ReadBuf);
            }
            my_SocketClose(TCPSkt);
            WinSockDeInit();
            return UTCT_Now;
        }
        my_SocketClose(TCPSkt);
    } // if (0 >= size)
    WinSockDeInit();

    if (0 == GetStringItem(ReadBuf, "UTCT", '\0', gUTCTString, sizeof(gUTCTString)))
    {
        gLocalT0 = TimeInfo.TimeTick_Sec;
    }
    else
    {
        st_debug("No Item 'UTCT' from server response!!\n");
        return UTCT_Now;
    }
    // 正确向服务器取得 UTCT.
    unsigned long New_UTCT = time(NULL) - gLocalT0 + strtol(gUTCTString, NULL, 16);
    if (t) *t = New_UTCT;
    return New_UTCT;
} // time_UTCT

//// ret>=0: SocketID, ret<0: something error
int _HTTP_POST(const char *pHost,
            unsigned short Port,
            const char *pUrl,
            const char *pBody,
            unsigned int TimeOut_ms)
{
    if (!pHost || !pUrl || !pBody || 0 == strlen(pHost) || 0 == strlen(pUrl) || 0 == strlen(pBody))
    {
        return WiPN_ERROR_InvalidParameter;
    }
    // Calculate the HTTP body length
    unsigned int Len_HttpBody = (unsigned)strlen(pBody);
    st_debug("Len_HttpBody:%d byte\n", Len_HttpBody);

    // Calculate the HTTP POST request length
    unsigned int Length_Http_PostBuf = unsigned(strlen("POST  HTTP/1.0\r\n")+strlen(pUrl)
                            +strlen("Host: \r\n")+strlen(pHost)
                            +strlen("Content-type: application/x-www-form-urlencoded\r\n")
                            +strlen("Content-Length: \r\n\r\n")+sizeof(int)
                            +Len_HttpBody
                            +strlen("\r\n"));

    // Malloc HTTP POST requests memory buffer
    unsigned int Size_HttpPostBuf = (Length_Http_PostBuf/4+1)*4;
    char *pHttp_PostBuf = (char*)malloc(Size_HttpPostBuf);
    if (!pHttp_PostBuf)
    {
        st_debug("_HTTP_POST - Malloc pHttp_PostBuf failed!!\n");
        return WiPN_ERROR_MallocFailed;
    }
    memset(pHttp_PostBuf, 0, Size_HttpPostBuf);

    // Formatted HTTP POST request information to pHttp_PostBuf
    SNPRINTF(pHttp_PostBuf, Size_HttpPostBuf,
            "POST %s HTTP/1.0\r\n"  // POST or GET, both tested and works. Both HTTP 1.0 HTTP 1.1 works, but sometimes
            "Host: %s\r\n"     // but sometimes HTTP 1.0 works better in localhost type
            "Content-type: application/x-www-form-urlencoded\r\n"
            "Content-length: %d\r\n\r\n"
            "%s\r\n",
            pUrl, pHost, Len_HttpBody, pBody);
    st_debug("Http_CMD(%u byte):\n%s\n", (unsigned int)strlen(pHttp_PostBuf), pHttp_PostBuf);

    if (0 != WinSockInit())
    {
        if (pHttp_PostBuf) {free((void*)pHttp_PostBuf); pHttp_PostBuf=NULL;}
        return WiPN_ERROR_SocketInitFailed;
    }
    char ServerIP[24];
    if (0 > GetHostIP(pHost, ServerIP, sizeof(ServerIP)))
    {
        if (pHttp_PostBuf) {free((void*)pHttp_PostBuf); pHttp_PostBuf=NULL;}
        WinSockDeInit();
        return WiPN_ERROR_HostResolveFailed;
    }

    int SocketID;
    size_t len = 0;
    struct sockaddr_in remote_addr;
    memset(&remote_addr, 0, sizeof(remote_addr));
    remote_addr.sin_family = AF_INET;
    remote_addr.sin_addr.s_addr = inet_addr(ServerIP);  // Host
    remote_addr.sin_port = htons(Port);         // 80

    // Create TCP Socket
    SocketID = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (0 > SocketID)
    {
        st_debug("create TCP socket failed: ret=%d, errno=%d (%s)", SocketID, errno, strerror(errno));
        WinSockDeInit();
        if (pHttp_PostBuf) {free((void*)pHttp_PostBuf); pHttp_PostBuf=NULL;}
        return WiPN_ERROR_SocketCreateFailed;
    }
    setSktNonBlock(SocketID);
    // Connect to Web Server
    if (0 != TCP_Connect_Till_TimeOut(SocketID, remote_addr, TimeOut_ms))
    {
        my_SocketClose(SocketID);
        WinSockDeInit();
        if (pHttp_PostBuf) {free((void*)pHttp_PostBuf); pHttp_PostBuf=NULL;}
        return WiPN_ERROR_SocketConnectFailed;
    }
    // Send cmd to Web server
    st_debug("send cmd to WebServer, cmdSize=%u byte. sending ...\n", (unsigned int)strlen(pHttp_PostBuf));
#if defined(WINDOWS) || defined(WIN32DLL)
    if ( 0 > (len = send(SocketID, pHttp_PostBuf, strlen(pHttp_PostBuf), 0)) )
#else
    if ( 0 > (len = write(SocketID, pHttp_PostBuf, strlen(pHttp_PostBuf))) )
#endif
    {
        st_debug("send failed(%d)! SocketID=%d, errno=%d (%s)\n", len, SocketID, errno, strerror(errno));
        my_SocketClose(SocketID);
        WinSockDeInit();
        if (pHttp_PostBuf) {free((void*)pHttp_PostBuf); pHttp_PostBuf=NULL;}
        return WiPN_ERROR_SocketWriteFailed;
    }
    //st_debug("send data(%d byte): \n%s\n", len, pHttp_PostBuf);
    if (pHttp_PostBuf) {free((void*)pHttp_PostBuf); pHttp_PostBuf=NULL;}
    return SocketID;
}

// http POST request, ret>=0: datasize, ret<0: something error
int HTTP_POST(const char *pHost,
            unsigned short Port,
            const char *pUrl,
            const char *pBody,
            char *Result,
            unsigned int RBufSize,
            unsigned int TimeOut_ms)
{
    if (!pHost || !pUrl || !pBody || !Result
        || 0 == strlen(pHost) || 0 == strlen(pUrl) || 0 == strlen(pBody) || 0 == RBufSize)
    {
        return WiPN_ERROR_InvalidParameter;
    }
    //// ------------------------- TCP Send ------------------------- ////
    int SocketID = _HTTP_POST(pHost, Port, pUrl, pBody, TimeOut_ms/2);
    if (0 > SocketID) return SocketID;
    //// ------------------------- TCP Read ------------------------- ////
    memset(Result, 0, RBufSize);
    st_debug("TCP Read_Till_TimeOut(Skt:%d, ..., readsize:%d, timeout:%d ms) ...\n", SocketID, RBufSize, TimeOut_ms);
    int size = TCP_Read_Till_TimeOut(SocketID, Result, RBufSize, TimeOut_ms);
    my_SocketClose(SocketID);
    WinSockDeInit();
    return size;
}
