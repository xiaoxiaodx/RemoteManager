/*
//  CS2 Network LIMITED All right reserved.
//
//  DPS_API.h: header file DPS API
//  Author: Charlie Chang (sengfu@gmail.com)
//
*/


#if !defined(__INCLUDED_DPS_API____H)
#define __INCLUDED_DPS_API____H


#include "NDT_Type.h"

 #ifdef ARCH_WINDOWS
  #ifdef DPS_API_EXPORTS
#define __DPS_API __declspec(dllexport)
  #else
#define __DPS_API __declspec(dllimport)
  #endif //// #ifdef DPS_API_EXPORTS
 #else
#define __DPS_API
 #endif //// #ifdef ARCH_WINDOWS

 #ifdef __cplusplus
extern "C" {
 #endif //// #ifdef __cplusplus

__DPS_API CHAR* DPS_GetAPIVersion(UINT32 *Version);
__DPS_API INT32 DPS_Initialize(const CHAR *ServerIP, const UINT16 ServerPort, const CHAR *AES128Key, const UINT16 PortNo);
__DPS_API INT32 DPS_DeInitialize();
__DPS_API INT32 DPS_TokenAcquire(CHAR* TokenBuf, const UINT16 Size);
__DPS_API INT32 DPS_RecvNotify(const CHAR *Token, CHAR *NotifyContent, UINT16 *Size, UINT32 TimeOut_ms);
__DPS_API INT32 DPS_GetLastAliveTime(UINT32 *Time_Sec);

#define ERROR_DPS_Successful				  0 	//API is successfully executed
#define ERROR_DPS_NotInitialized			 -1 	//DPS_Inistialize is not called yet
#define ERROR_DPS_AlreadyInitialized		 -2 	//DPS_Inistialize is called already
#define ERROR_DPS_TimeOut					 -3 	//Time out
#define ERROR_DPS_FailedToResolveHostName	 -4 	//Can't resolve Server Name
#define ERROR_DPS_FailedToCreateSocket		 -5 	//Socket create failed
#define ERROR_DPS_FailedToBindPort			 -6 	//Socket bind failed
#define ERROR_DPS_FailedToConnectServer		 -7 	//Connection to DPS Server failed
#define ERROR_DPS_FailedToRecvData			 -8 	//Failed to Receive data from Server
#define ERROR_DPS_NotEnoughBufferSize		 -9 	//Buffer size is not enough
#define ERROR_DPS_InvalidAES128Key			-10 	//AES128Key string must exactly 16 Byte
#define ERROR_DPS_InvalidToken 				-11 	//The Token string is not valid
#define ERROR_DPS_OnRecvNotify 				-12 	//You can't call this function while DPS_RecvNotify() is running
#define ERROR_DPS_OnAcquireToken 			-13 	//You can't call this function while DPS_TokenAcquire() is running
#define ERROR_DPS_NotOnRecvNotify			-14		//You can't call this function while DPS_RecvNotify() is not running
#ifdef __cplusplus
}
#endif //// #ifdef __cplusplus

#endif //// #if !defined(__INCLUDED_DPS_API____H)


