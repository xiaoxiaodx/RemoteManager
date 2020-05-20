/*
//  CS2 Network LIMITED All right reserved.
//
//  SPS_API.h: header file DPS API
//  Author: Charlie Chang (sengfu@gmail.com)
//
*/



#if !defined(__INCLUDED_SPS_API____H)
#define __INCLUDED_SPS_API____H


#include "NDT_Type.h"

#ifdef ARCH_WINDOWS
#ifdef SPS_API_EXPORTS
#define __SPS_API __declspec(dllexport)
#else
#define __SPS_API __declspec(dllimport)
#endif //// #ifdef SPS_API_EXPORTS
#else
#define __SPS_API
#endif //// #ifdef ARCH_WINDOWS

#ifdef __cplusplus
extern "C" {
#endif //// #ifdef __cplusplus

__SPS_API void CS2_SPS_Initialize();
__SPS_API void CS2_SPS_DeInitialize();
__SPS_API CHAR* CS2_SPS_GetAPIVersion(UINT32 *Version);
__SPS_API INT32 CS2_SPS_Upload(const CHAR *SPSInfo, const CHAR *AuthWord, const CHAR *DID, const CHAR *LNS, const UINT32 CH, const CHAR *PINFO, const CHAR *AINFO, const CHAR *SnapshotBuf, const UINT32 SSBufSize, CHAR *PostResultBuf, const UINT32 PRBufSize);
//  SPSInfo: The Server information of SPS. This information is provided by QS of WiPN.
//  AuthWord: The authentication word. This must match SPSˇs setting otherwise SPS Server will not accept connection. AuthWord can be at most 16 characters. If exceeds 16 characters, only the fist 16 characters are compared.
//  DID, LNS, CH, ,PINFO, AINFO: Information needed for Post action.
//  SnapshotBuf: The buffer of snapshot picture, Or the full file path name of snapshot picture. Or NULL.
//          If SnapshotBuf is NULL, you must use a thread to call SPS_FeedSnapshotData() to provide Snapshot data.
//  SSBufSize: The size of snapshot.
//          If the SnapshotBuf is a full file path name of snapshot (for example: /the/full/path/filename), SSBufSize must be 0xFFFFFFFF,.
//          If SnapshotBuf is NULL, SSBufSize tells the size of snapshot (if size is unknown, please enter 0xFFFFFFF).
//          Otherwise, SSBufSize tell the size of SnapshotBuf in memory.
//  PostResultBuf: If PostResultBuf != NULL && PRBufSize != 0,  CS2s3_Upload() will wait till post action finished and post result is stored in PostResultBuf. If PostResultBuf == NULL, CS2s3_Upload() will not waiting for post result.
//  PRBufSize: size of PostResultBuf. If PRBufSize is not big enough, the post result will be truncated.
__SPS_API INT32 CS2_SPS_FeedSnapshotData(const UCHAR *Buf, const UINT32 Size);
// to externally provide snapshot data for CS2_SPS_Upload() with parameter SnapshotBuf == NULL.
// if Size == 0, means fininsh.

__SPS_API INT32 CS2_SPS_Download(const CHAR *DLInfo, const CHAR *AuthWord, const CHAR *FileName, CHAR* SnapshotBuf, UINT32 *SBufSize, const CHAR FunCode);
//  DLInfo The IP:Port information to download snapshot. DLInfo is inside push content.
//  FileName: the FileName of snapshot. SPS IP, Port and FileName is provided in payload of Push notify content.
//  SnapshotBuf: The memory buffer or the file path name for download snapshot from SPS Server.
//          If SnapshotBuf is memory buffer, you must declare SnapshotBuf with memory size > snapshot size, which is provided in payload of Push notify content.
//  BufSize: When calling, it specify the sizeof SnapshotBuf.
//          if *BufSize == 0xFFFFFFFF when calling, it indecated that SnapshotBuf is a file path name.
//          if *BufSize != 0xFFFFFFFF when calling, it indecated that SnapshotBuf is a memory buffer.
//          When returned, it is the actual size of SnapshotBuf downloaded.
//  FunCode: 0: Download only, 1: Download and Delete file, 2: Delete file only (donˇt download)

__SPS_API void CS2_SPS_Break();
//to break executing of CS2_SPS_Upload and CS2_SPS_Download.

//////////////////// SPS API Return Code NOTE ///////////////////////////
/// Return value = 0: successfully.
/// Return value > 0: network or socket error, please refer to definition of linux errno
/// Return value < 0: API Error, as following

#define ERROR_SPS_NoError               0   //// API is successfully executed
#define ERROR_SPS_InvalidParameter      -1  //// Invalid Parameter
#define ERROR_SPS_InvalidFunCode        -2  //// Invalid FunCode
#define ERROR_SPS_TimeOut               -3  //// TimeOut (over 5 sec) waiting for Server's response
#define ERROR_SPS_AuthWordError         -4  //// AuthWord mismatch
#define ERROR_SPS_FileNotExist          -5  //// FileName doesn't exist
#define ERROR_SPS_BufferNotEnough       -6  //// Snapshot buffer size is too samll
#define ERROR_SPS_UserBreak             -7  //// User break, ie CS2_SPS_Break() is called
#define ERROR_SPS_NotEnoughMemory       -8  //// The system memory is not enough for malloc
#define ERROR_SPS_InvalidDID            -9  //// Something wrong with 'DID'
#define ERROR_SPS_ServerCloseSession    -10 //// Server has closed tcp session, please look up Server Log for what happened.
#define ERRPR_SPS_LocalSocketTimeout    -11 //// Local socket read timeout (5 sec)
#define ERRPR_SPS_UploadIsNotRunning    -12 //// SPS_Upload (with Parameter SnapshotBuf = NULL) is not calling
#define ERROR_SPS_ExceedMaxPINFOSize    -13 //// The PINFO must be less than 4095 Bytes
#define ERROR_SPS_ExceedMaxAINFOSize    -14 //// The AINFO must be less than 4095 Bytes
#define ERROR_SPS_ExceedMaxSnapshotSize -15 //// The Snapshot must be less than 32 MBytes
#define ERRPR_SPS_UploadTemporaryDisabled -16 //// The SPS_Upload function is temporarily disabled, due to too many Upload in last 10 minutes
#define ERROR_SPS_ServerError           -98 //// Server Error, Please check log of all CS2 SPS Servers, or contact CS2 FAE.
#define ERROR_SPS_UnknownError          -99 //// Unknown Error, please contact CS2 FAE.
#ifdef __cplusplus
}
#endif //// #ifdef __cplusplus

#endif //// #if !defined(__INCLUDED_SPS_API____H)


