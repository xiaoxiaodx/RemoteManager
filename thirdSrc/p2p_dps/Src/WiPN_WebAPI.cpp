#include "WiPN_WebAPI.h"

//// -------------------------------- WiPN Web API Begin --------------------------------
int WiPN_WebAPI_QueryAll(char *QSDID[],
						unsigned short QSNumber,
						const char *WiPN_Key,
						const char *Host,
						unsigned short Port,
						const char *pURL,
						const char *pDeviceDID,
						char *QSResult,
						unsigned short *QSRBufSize)
{
	const char APIName[] = "WiPN_WebAPI_QueryAll:";
    // Parameter Detect
    if (!QSDID)
    {
        st_info("%s - QSDID Buf is NULL!!\n", APIName);
        return WiPN_ERROR_InvalidParameter;
    }
    if (0 == QSNumber)
    {
        st_info("%s - Invalid QSNumber Parameter!!\n", APIName);
        return WiPN_ERROR_InvalidParameter;
    }
    int i = 0;
    for (; i < QSNumber; i++)
    {
        if (NULL == QSDID[i]) break;
    }
    if (i != QSNumber)
    {
        st_info("%s - QSDIDbuf[%d] have no DID!!\n", APIName, i);
        return WiPN_ERROR_InvalidParameter;
    }
    if (!WiPN_Key || 16 != strlen(WiPN_Key))
    {
        st_info("%s - Invalid WiPN_Key parameter!!\n", APIName);
        return WiPN_ERROR_InvalidParameter;
    }
    if (!Host || 0 == strlen(Host))
    {
        st_info("%s - Invalid Host address parameter!!\n", APIName);
        return WiPN_ERROR_InvalidParameter;
    }
    if (!pURL || 0 == strlen(pURL))
    {
        st_info("%s - Invalid URL parameter!!\n", APIName);
        return WiPN_ERROR_InvalidParameter;
    }
    if (!pDeviceDID || 12 > strlen(pDeviceDID))
    {
        st_info("%s - Invalid DeviceDID Parameter!!\n", APIName);
        return WiPN_ERROR_InvalidParameter;
    }
    if (!QSResult || !QSRBufSize || 0 == *QSRBufSize)
    {
        st_info("%s - Invalid QSResult Buf or QSRBufSize!!\n", APIName);
        return WiPN_ERROR_InvalidParameter;
    }

    // Save: 1.Cmd (Encryption before)
	//	2.Server DID (Have been encrypted)
	//	3.Body: The server in response to the HTTP Body data (Not decrypt)
	//	4.NDTRET: The server returns the NDT error
	unsigned short SizeOfCSBN = 1024;
    char CSBN_Buffer[1024];
	memset(CSBN_Buffer, 0, SizeOfCSBN);

	// Save: 1.Cmd (encrypted)
	//	2.HTTP Read Data: The server response data(Including the HTTP Body)
	//	3.Body: The HTTP Body of data after decryption
	unsigned short SizeOfBuffer = 1280;
	char *Buffer = (char *)malloc(SizeOfBuffer);
	if (!Buffer)
	{
		st_debug("%s - malloc Buffer failed!!\n", APIName);
		return WiPN_ERROR_MallocFailed;
	}

	int ret = -1;

//    st_Time_Info TimeBegin;
//    st_Time_Info TimeEnd;
	srand((unsigned int)time(NULL));
	unsigned short index = abs(rand() % QSNumber);

    for (int i = 0; i < QSNumber; i++)
    {
        index = (index + 1) % QSNumber;

        // Formatted QueryCmd to CSBN_Buffer
        sprintf(CSBN_Buffer, "DID=%s&", pDeviceDID);
        st_debug("QueryCmd(%u byte):%s\n", (unsigned int)strlen(CSBN_Buffer), CSBN_Buffer);

        // Encryption QueryCmd to Buffer
        if (0 > iPN_StringEnc(WiPN_Key, CSBN_Buffer, Buffer, SizeOfBuffer))
        {
            st_debug("%s iPN_StringEnc: QueryCmd Enc failed!\n", APIName);
            if (Buffer) {free((void *)Buffer); Buffer=NULL;}
            return WiPN_ERROR_StringEncFailed;
        }

        // Encryption QueryServer DID to CSBN_Buffer
        if (0 > iPN_StringEnc(WiPN_Key, QSDID[index], CSBN_Buffer, SizeOfCSBN))
        {
            st_debug("%s iPN_StringEnc: QSDID Enc failed!\n", APIName);
            if (Buffer) free((void *)Buffer);
            return WiPN_ERROR_StringEncFailed;
        }

        char Body[1280] = {};
        SNPRINTF(Body, sizeof(Body), "A=%s&B=%s", CSBN_Buffer, Buffer);

        st_debug("%s send cmd to WebServer, QSDID[%d]=%s. CmdSize=%u byte, sending...\n", APIName, index, QSDID[index], (unsigned int)strlen(Buffer));

        // http POST request, ret>=0: datasize, ret<0: something error
        ret = HTTP_POST(Host, Port, pURL, Body, Buffer, SizeOfBuffer, 5000);//TimeOut_ms=5000 ms.
        if (0 > ret)
        {
            st_debug("%s send cmd failed!! ret=%d [%s]\n\n", APIName, ret, getWiPNErrorCodeInfo(ret));
            continue;
        }
        else
        {
            st_debug("\n%s From WebServer(%d byte):\n%s\n\n", APIName, ret, Buffer);
            char Body[1024] = {};
            if (0 > GetHTTPBody(Buffer, "\r\n\r\n", Body, sizeof(Body)))
            {
                st_debug("%s Get HTTP Body Data failed!\n", APIName);
                ret = WiPN_ERROR_GetHttpBodyFailed;
                break;
            }
            // st_debug("Body(%u byte):%s\n", (unsigned)strlen(Body), Body);
            // To decrypt the Http body data into the Buffer
            if (0 > iPN_StringDnc(WiPN_Key, Body, QSResult, *QSRBufSize))
            {
                st_debug("%s iPN_StringDnc: WiPN_Key=%s, Decryption failed!\n", APIName, WiPN_Key);
                SNPRINTF(QSResult, *QSRBufSize, "%s", Body);
                ret = WiPN_ERROR_StringDecFailed;
            }
            else st_debug("%s After decrypt Data(%u byte): %s\n", APIName, (unsigned)strlen(QSResult), QSResult);
            break;
        }
    } // for

	if (Buffer) {free((void *)Buffer); Buffer=NULL;}
	*QSRBufSize = (unsigned int)strlen(QSResult);
    return ret;
} // WiPN_WebAPI_QueryAll

//// WiPN_WebAPI_Send
int WiPN_WebAPI_Send(const char *pServerDIDString,	// Post/Subs Server String, such as: "01,PPCS-123456-ABCDEF"
					const char *WiPN_Key,
					const char *Host,
					unsigned short Port,
					const char *pURL,
					const char *pCmd,
					char *pResult,                  // Save Server return info
                    unsigned short *RBufSize,       // Result Buf Size.
                    char *pUTCT)                    // 此参数在此已弃用
{
    const char APIName[] = "WiPN_WebAPI_Send:";
    if (!pServerDIDString || 0 == strlen(pServerDIDString))
    {
        st_info("%s - Invalid ServerDIDString parameter!!\n", APIName);
        return WiPN_ERROR_InvalidParameter;
    }
    if (!WiPN_Key || 16 != strlen(WiPN_Key))
    {
        st_info("%s - Invalid WiPN_Key parameter!!\n", APIName);
        return WiPN_ERROR_InvalidParameter;
    }
    if (!Host || 0 == strlen(Host))
    {
        st_info("%s - Invalid Host address parameter!!\n", APIName);
        return WiPN_ERROR_InvalidParameter;
    }
    if (!pURL || 0 == strlen(pURL))
    {
        st_info("%s - Invalid URL parameter!!\n", APIName);
        return WiPN_ERROR_InvalidParameter;
    }
    if (!pCmd || 0 == strlen(pCmd))
    {
        st_info("%s - Invalid Cmd parameter!!\n", APIName);
        return WiPN_ERROR_InvalidParameter;
    }
    if (!pResult || !RBufSize || 0 == *RBufSize)
    {
        st_info("%s - Invalid Result or RBufSize parameter!!\n", APIName);
        return WiPN_ERROR_InvalidParameter;
    }
    // if (!pUTCT || 0 == strlen(pUTCT))
    // {
    //     st_info("%s - Invalid UTCTString parameter!!\n", APIName);
    //     return WiPN_ERROR_InvalidParameter;
    // }

    int ret = 0;
	//// Get Server DID
    unsigned short NumberOfServer = 0;
    unsigned char SizeOfDID = 0;
    char *pServerDID = NULL;
    if ( 0 > (ret = Split_DID(pServerDIDString, &NumberOfServer, &SizeOfDID, &pServerDID)) )
    {
        return ret;
    }

	// Calculate the space required for PostCmd
	unsigned int Length_PostCmd = unsigned(strlen("UTCT=0x&")+strlen(pCmd)+12);

	// NDT can only send a maximum of 1280 bytes of data, according to the encryption algorithm, encryption data can not be more than 630 bytes
	unsigned int MaxSizeOfCmd = 630;
	if (MaxSizeOfCmd < Length_PostCmd)
	{
		st_info("%s - Length Of PostCmd is Exceed %d bytes!!\n", APIName, MaxSizeOfCmd);
		if (pServerDID) {free((void *)pServerDID); pServerDID=NULL;}
		return WiPN_ERROR_ExceedMaxSize;
	}

	// Save: Has not been encrypted CMD /HTTP Body data/NDTRET
	unsigned int SizeOfCSBN = (Length_PostCmd/4+1)*4;
	char *CSBN_Buffer = (char *)malloc(SizeOfCSBN);
	if (!CSBN_Buffer)
	{
		st_info("%s - malloc PostCmd Buf failed!!\n", APIName);
		if (pServerDID) {free((void *)pServerDID); pServerDID=NULL;}
		return WiPN_ERROR_MallocFailed;
	}

	// Save: The encrypted cmd /The server response data/Decrypt the server response data
	unsigned short SizeOfBuffer = 1280;
	char *Buffer = (char *)malloc(SizeOfBuffer);
	if (!Buffer)
	{
		st_info("%s - malloc Buffer failed!!\n", APIName);
		if (pServerDID) {free((void *)pServerDID); pServerDID=NULL;}
		if (CSBN_Buffer) {free((void *)CSBN_Buffer); CSBN_Buffer=NULL;}
		return WiPN_ERROR_MallocFailed;
	}

	int i = 0;
	srand((unsigned int)time(NULL));
	short index = 0;
	unsigned short j = abs(rand() % NumberOfServer);
    for (i = 0; i < NumberOfServer; i++)
    {
        j = (j + 1) % NumberOfServer;
        index = SizeOfDID * j;

        // Calculate UTCT time
        // unsigned long UTCT_Now = time(NULL) - gTime_ServerRet + strtol(pUTCT, NULL, 16);
        unsigned long UTCT_Now = time_UTCT(NULL);

        // Format PostCmd, Save in CSBN_Buffer
        memset(CSBN_Buffer, '\0', SizeOfCSBN);
        SNPRINTF(CSBN_Buffer, SizeOfCSBN, "UTCT=0x%X&%s", (unsigned int)UTCT_Now, pCmd);
        st_debug("%s Cmd=%s\nSize=%u byte (Not Encrypted Size)\n\n", APIName, CSBN_Buffer, (unsigned int)strlen(CSBN_Buffer));

        // encryption PostCmd, Save in Buffer
        if (0 > iPN_StringEnc(WiPN_Key, CSBN_Buffer, Buffer, SizeOfBuffer))
        {
            st_info("%s iPN_StringEnc: CMD Enc failed!\n", APIName);
            if (pServerDID) {free((void *)pServerDID); pServerDID=NULL;}
            if (CSBN_Buffer) {free((void *)CSBN_Buffer); CSBN_Buffer=NULL;}
            if (Buffer) {free((void *)Buffer); Buffer=NULL;}
            return WiPN_ERROR_StringEncFailed;
        }

        // Encryption PostServer DID to CSBN_Buffer
        if (0 > iPN_StringEnc(WiPN_Key, &pServerDID[index], CSBN_Buffer, SizeOfCSBN))
        {
            st_debug("%s iPN_StringEnc: ServerDID Enc failed!\n", APIName);
            if (pServerDID) {free((void *)pServerDID); pServerDID=NULL;}
            if (CSBN_Buffer) {free((void *)CSBN_Buffer); CSBN_Buffer=NULL;}
            if (Buffer) {free((void *)Buffer); Buffer=NULL;}
            return WiPN_ERROR_StringEncFailed;
        }
        // Body: A=ENC(QS/SNDID)&B=ENC(CMD)
        char Body[1280] = {};
        SNPRINTF(Body, sizeof(Body), "A=%s&B=%s", CSBN_Buffer, Buffer);

        st_debug("%s send cmd to WebServer, SNDID[%d]=%s. CmdSize=%u byte, sending...\n", APIName, index, &pServerDID[index], (unsigned int)strlen(Buffer));

        // http POST request, ret>=0: datasize, ret<0: something error
        ret = HTTP_POST(Host, Port, pURL, Body, Buffer, SizeOfBuffer, 5000);//TimeOut_ms=5000 ms.

        if (0 > ret)
        {
            st_debug("%s send cmd failed!! ret=%d [%s]\n\n", APIName, ret, getWiPNErrorCodeInfo(ret));
            continue;
        }
        else
        {
            st_debug("\n%s From WebServer(%d byte):\n%s\n\n", APIName, ret, Buffer);
            char Body[1024] = {};
            if (0 > GetHTTPBody(Buffer, "\r\n\r\n", Body, sizeof(Body)))
            {
                st_debug("%s Get HTTP Body Data failed!\n", APIName);
                ret = WiPN_ERROR_GetHttpBodyFailed;
                break;
            }
            // st_debug("Body(%u byte):%s\n", (unsigned)strlen(Body), Body);
            // To decrypt the Http body data into the Buffer
            if (0 > iPN_StringDnc(WiPN_Key, Body, pResult, *RBufSize))
            {
                st_debug("%s iPN_StringDnc: WiPN_Key=%s, Decryption failed!\n", APIName, WiPN_Key);
                SNPRINTF(pResult, *RBufSize, "%s", Body);
                ret = WiPN_ERROR_StringDecFailed;
            }
            else st_debug("%s After decrypt Data(%u byte): %s\n", APIName, (unsigned)strlen(pResult), pResult);
            break;
        }
    } // for
	if (pServerDID) {free((void *)pServerDID); pServerDID=NULL;}
	if (CSBN_Buffer) {free((void *)CSBN_Buffer); CSBN_Buffer=NULL;}
	if (Buffer) {free((void *)Buffer); Buffer=NULL;}
    return ret;
} // WiPN_WebAPI_Send
