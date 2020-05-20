/*
//  CS2 Network LIMITED All right reserved.
//
//  NDT_API.c: The DNT API include file
//  Author: Charlie Chang (sengfu@gmail.com)
//
*/



#if !defined(__INCLUDED_NDT_API____H)
#define __INCLUDED_NDT_API____H


#include "NDT_Type.h"


 #ifdef __cplusplus
extern "C" {
 #endif //// #ifdef __cplusplus

typedef struct{	
	CHAR WanIP[16];  		// The Wan IP, ¡°0.0.0.0¡± means Wan IP is not successfully detected.
	CHAR WanIPv6[40];		// The Wan IPv6 IP, available only when IPv6 IP is activated and working. 
	CHAR LanIP[16]; 		// The Local IP , ¡°0.0.0.0¡± means Lan IP is not successfully detected.
	CHAR LanIPv6[40];		// The Local IPv6 IP , available only when IPv6 IP is activated and working.
	UINT16 LanPort;			// Local UDP Port, 0 means not successfully detected.
	UINT16 WanPort;			// Wan UDP Port , 0 means not successfully detected.
	CHAR bServerHelloAck;	// 0: No server response, 1: server responsed.
	CHAR bReserved[3];		// Reserved ...Should always be "0"
} st_NDT_NetInfo;

CHAR* NDT_PPCS_GetAPIVersion(UINT32 *Version);
INT32 NDT_PPCS_Initialize(const CHAR *InitString, const UINT16 PortNo, const CHAR *DIDString, const CHAR *AES128Key);
INT32 NDT_PPCS_DeInitialize();
INT32 NDT_PPCS_NetworkDetect(st_NDT_NetInfo *NetInfo, UINT32 TimeOut_ms);
INT32 NDT_PPCS_Recv(CHAR *Data, UINT16 *Size, const UINT32 TimeOut_ms, const INT32 Option);
INT32 NDT_PPCS_SendBack(const INT32 ClientHandle, const CHAR *Data, const UINT16 Size, const UINT32 TimeOut_ms);
INT32 NDT_PPCS_SendTo(const CHAR *DID, const CHAR *Data, const UINT16 Size, const INT32 Mode);
INT32 NDT_PPCS_SendToByServer(const CHAR *DID, const CHAR *Data, const UINT16 Size, const INT32 Mode, const CHAR *InitString,const CHAR *AES128Key);
INT32 NDT_PPCS_RecvFrom(const INT32 DeviceHandle, CHAR *Data, UINT16 *Size, const UINT32 TimeOut_ms);
INT32 NDT_PPCS_CloseHandle(const INT32 Handle);
INT32 NDT_PPCS_SendTo_Break(const CHAR *DID);
INT32 NDT_PPCS_Recv_Break();
INT32 NDT_PPCS_SendBack_Break(const INT32 ClientHandle);
INT32 NDT_PPCS_RecvFrom_Break(const INT32 DeviceHandle);
INT32 NDT_PPCS_StatusCheck(INT32 *AckTime, INT32 *NumberDH, INT32 *NumberCH);
#ifdef __cplusplus
}
#endif //// #ifdef __cplusplus

#endif //// #if !defined(__INCLUDED_NDT_API____H)