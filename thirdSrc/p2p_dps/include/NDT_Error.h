/*
//  CS2 Network LIMITED All right reserved.
//
//  NDT_Error.h: header file of error code for DNT
//  Author: Charlie Chang (sengfu@gmail.com)
//
*/


#if !defined(__INCLUDED_NDT_ErrorCode____H)
#define __INCLUDED_NDT_ErrorCode____H


#define NDT_ERROR_NoError					0  	// API function is successfully returned and no error occurs
#define NDT_ERROR_AlreadyInitialized		-1	// Initialize function is already successfully called
#define NDT_ERROR_NotInitialized			-2	// The NDT lib is not initialize yet.
#define NDT_ERROR_TimeOut					-3	// Time out

#define NDT_ERROR_ScketCreateFailed			-4	// Socket create error
#define NDT_ERROR_ScketBindFailed			-5	// Socket bind error
#define NDT_ERROR_HostResolveFailed			-6  // Calling gethostbyname is failed
#define NDT_ERROR_ThreadCreateFailed		-7	// Thread create error
#define NDT_ERROR_MemoryAllocFailed			-8	// Failed to allocate memory
#define NDT_ERROR_NotEnoughBufferSize		-9 // The size of data buffer is not enough

#define NDT_ERROR_InvalidInitString			-10	// Not a legal InitString or InitString length > 250
#define NDT_ERROR_InvalidAES128Key			-11	// the AES128Key require exectly 16 Byte
#define NDT_ERROR_InvalidDataOrSize			-12 // The specified Data buffer or Data size is invalid
#define NDT_ERROR_InvalidDID				-13	// The DID is invalid, Maybe invalid Prefix or CheckCode, or exceed max SN, or DID is not specified in Initialize()
#define NDT_ERROR_InvalidNDTLicense			-14 // The DID string don't include valid NDT License, it should looks like "AAAA-123456-ABCDE:FGHIJK"

#define NDT_ERROR_InvalidHandle				-15 // The specified Handle is invalid
#define NDT_ERROR_ExceedMaxDeviceHandle		-16	// Exceed Max number of Device handle
#define NDT_ERROR_ExceedMaxClientHandle		-17	// Exceed Max number of Client handle

#define NDT_ERROR_NetworkDetectRunning		-18	// Network Detect function is on going
#define NDT_ERROR_SendToRunning				-19	// The SendTo() or SendToByServer() for the same DID is running
#define NDT_ERROR_RecvRunning				-20 // Recv function is running
#define NDT_ERROR_RecvFromRunning			-21	// RecvFrom()for the same DeviceHandle is running
#define NDT_ERROR_SendBackRunning			-22	// SendBack()for the same ClientHandle is running

#define NDT_ERROR_DeviceNotOnRecv			-23 // The Target device is not calling Recv()
#define NDT_ERROR_ClientNotOnRecvFrom		-24 // The Client is not calling RecvFrom()
#define NDT_ERROR_NoAckFromCS				-25 // None of 3 CS acks, it's very likely due to local network problem
#define NDT_ERROR_NoAckFromPushServer		-26 // No Push Server acks, it's very likely due to local network problem
#define NDT_ERROR_NoAckFromDevice			-27 // Device doesn't ack, it's very likely due to device is not online now (but device did online in last minite)
#define NDT_ERROR_NoAckFromClient			-28 // Client doesn't ack, it's very likely due to Client is not online now
#define NDT_ERROR_NoPushServerKnowDevice	-29 // Device doesn't send alive to any PS, it's very likely due to device is not online now
#define NDT_ERROR_NoPushServerKnowClient	-30	// Cleint doesn't send message PS, it's very likely due to Client is not online now

#define NDT_ERROR_UserBreak					-31	// Recv_Break(), SendTo_Break(), SendBack_Break(), RecvFrom_Break()  or CloseHandle() is called
#define NDT_ERROR_SendToNotRunning			-32	// The SendTo() or SendToByServer() for the same DID is not running
#define NDT_ERROR_RecvNotRunning			-33 // Recv function is not running
#define NDT_ERROR_RecvFromNotRunning		-34	// RecvFrom()for the same DeviceHandle is not running
#define NDT_ERROR_SendBackNotRunning		-35	// SendBack()for the same ClientHandle is not running
#define NDT_ERROR_RemoteHandleClosed		-36	// Remote Device or Client already call CloseHandle()


#define NDT_ERROR_FAESupportNeeded			-99 // When this Error occurs, please contact CS2' FAE for technical answer


#endif  //__INCLUDED_NDT_ErrorCode____H

