#ifndef _WIPN_WEBAPI_H_
#define _WIPN_WEBAPI_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>

#if defined WINDOWS
#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <windows.h>
//#include <ws2tcpip.h>
#elif defined LINUX
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#endif

#include "WiPN_Common.h"

#ifdef __cplusplus
extern "C" {
#endif

#define WEB_HOST       "120.24.6.102"
#define WEB_PORT       80
#define URL          "/iot/WiPN/WiPN.php"   // http://120.24.6.102/iot/WiPN/WiPN.php

// ---------------------------- WiPN Web API ---------------------------
int WiPN_WebAPI_QueryAll(char *QSDID[],				// QueryServer DID
						unsigned short QSNumber,	// Number of QueryServer DID
						const char *WiPN_Key,		// WiPN String Enc/Dec Key
						const char *Host,			// Web Server Host
						unsigned short Port,		// Web Server Port
						const char *pURL,			// Web url
						const char *pDeviceDID,		// Device DID
						char *QSResult,				// save result from QueryServer response.
						unsigned short *QSRBufSize);// QSResult buf size,when return,is real size of QSResult data.

int WiPN_WebAPI_Send(const char *pServerDIDString,	// Post/Subs Server String, such as: "01,PPCS-123456-ABCDEF"
					const char *WiPN_Key,			// WiPN String Enc/Dec Key
					const char *Host,				// Web Server Host
					unsigned short Port,			// Web Server Port
					const char *pURL,				// Web url
					const char *pCmd,				// CMD BufSize
					char *pResult,                  // Save Server return info
                    unsigned short *RBufSize,       // Result Buf Size.when return,is real size of Result data.
                    char *pUTCT);                   // 此参数在此已弃用

#ifdef __cplusplus
}
#endif
#endif 	// _WIPN_WEBAPI_H_