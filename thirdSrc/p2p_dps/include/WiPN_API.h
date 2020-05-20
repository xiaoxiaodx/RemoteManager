#ifndef _WIPN_API_H_
#define _WIPN_API_H_

#include <stdio.h>
#include <time.h>
#include <stdlib.h>     // malloc/free atoi atol atoll srand
#include <errno.h>

#include "NDT_API.h"
#include "WiPN_Common.h"

#if defined WINDOWS
#include <windows.h>
#elif defined LINUX
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#endif // #if defined WINDOWS

#ifdef __cplusplus
extern "C" {
#endif

extern char g_NDT_InitString[SIZE_InitString];   // InitString
extern char g_NDT_AES128Key[SIZE_AES128Key];     // NDT AESKey
// extern time_t gTime_ServerRet;
extern char gWiPN_Key[17];

// get UTCT from NDT
UINT32 time_NDT(UINT32 *t);

//// ---------------------------------- 2018.07.24 --------------------------------- ////
//// -------------------------------- WiPN Root API -------------------------------- ////
//// 20180723: Query All response data from QueryServer and save in QSResult buffer.
INT32 WiPN_QueryAll(const CHAR *pDeviceDID,         // device DID.
                    CHAR *QSDID[],                  // QueryServer DID.
                    UINT16 NumberOfServer,          // QueryServer DID Number
                    CHAR *QSResult,                 // Query Result String, from Query server response.
                    UINT16 *QSRBufSize,              // QSResult Buf Size.
                    const CHAR *NDTByServerString,  // if this NDTByServerString Parameter is NULL,then use NDT SendTo,Otherwise use SendToByserver.
                    const CHAR *NDTByAES128Key);    // if NDTByServerString not NULL,then this NDTByAES128Key Parameter also not NULL.
// Send CMD to Server
INT32 WiPN_API_Send(const CHAR *pServerDIDString,   // PostString or SubsString,from QSResult.such as:"01,PPCS-123456-ABCDEF"
                    const CHAR *pCmd,               // Cmd, Please see the command description document in detail.
                    CHAR *pResult,                  // Save Server return info.
                    UINT16 *RBufSize,                // Result Buf Size.
                    CHAR *pUTCT,                    // UTCT From QS/SN Server response.
                    const CHAR *NDTByServerString,  // if this NDTByServerString Parameter is NULL,then use NDT SendTo,Otherwise use SendToByserver.
                    const CHAR *NDTByAES128Key);    // if NDTByServerString not NULL,then this NDTByAES128Key Parameter also not NULL.

// WiPN_Select this API does not necessarily need to be called，When you call this API, you must save the new string returned .
INT32 WiPN_Select(  CHAR *pServerDIDString,         // PostString or SubsString, The server DID string that needs to be sorted. when return,is new string.
                    const CHAR *NDTByServerString,  // if this NDTByServerString Parameter is NULL,then use NDT SendTo,Otherwise use SendToByserver.
                    const CHAR *NDTByAES128Key);    // if NDTByServerString not NULL,then this NDTByAES128Key Parameter also not NULL.
//// ------------------------------ WiPN API End ------------------------------
#ifdef __cplusplus
}
#endif
#endif 	// _WIPN_API_H_
