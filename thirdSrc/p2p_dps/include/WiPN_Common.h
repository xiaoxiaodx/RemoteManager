//// 2019.01.08

#ifndef _WIPN_COMMON_H_
#define _WIPN_COMMON_H_

#include <stdio.h>
#include <time.h>
#include <stdlib.h>     // malloc/free atoi atol atoll srand
#include <string.h>
#include <errno.h>

#if defined(WIN32DLL) || defined(WINDOWS)
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#elif defined LINUX
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <netdb.h>       // linux gethostbyname
#include <arpa/inet.h>   // inet_ntoa
#include <fcntl.h> // fcntl
#endif // #if defined WINDOWS

#include "NDT_Error.h"
#include "Debug_Log.h"
#include "stTime.h"
#include "StringEncDec.h"

#ifdef __cplusplus
extern "C" {
#endif

//// for WiPN Web API
#define WiPN_ERROR_InvalidParameter         -1000 // Invalid Parameter
#define WiPN_ERROR_MallocFailed             -1001 // Allocates memory Failed
#define WiPN_ERROR_ExceedMaxSize            -1002 // More than most Byte size, Possible title, content or cmd length exceeds the limit
#define WiPN_ERROR_TimeOut                  -1003 // TimeOut
#define WiPN_ERROR_StringParseFailed        -1004 // DID or other item parse failed
#define WiPN_ERROR_StringEncFailed          -1005 // String Encryption failed
#define WiPN_ERROR_StringDecFailed          -1006 // String Decryption failed
#define WiPN_ERROR_SocketInitFailed         -1007 // Win socket init failed.
#define WiPN_ERROR_HostResolveFailed        -1008 // Host Resolve failed
#define WiPN_ERROR_SetNonBlockFailed        -1009 // set socket non-blocking failed.
#define WiPN_ERROR_SocketCreateFailed       -1010 // Create socket Failed
#define WiPN_ERROR_SocketConnectFailed      -1011 // TCP Connect Failed
#define WiPN_ERROR_InvalidSocketID          -1012 // Invalid socket
#define WiPN_ERROR_SetSockOptFailed         -1013 // SetSockOpt error
#define WiPN_ERROR_SocketWriteFailed        -1014 // TCP/UDP Write/Send/sendto Failed
#define WiPN_ERROR_SocketReadFailed         -1015 // TCP/UDP Read/Recv/recvfrom Failed
#define WiPN_ERROR_RemoteSocketClosed       -1016 // remote close Socket
#define WiPN_ERROR_SelectError              -1017 // select return -1
#define WiPN_ERROR_GetHttpBodyFailed        -1018 // Get HTTP Body data failed


#if defined(WIN32DLL) || defined(WINDOWS)
typedef     DWORD                   my_threadid;
typedef     HANDLE                  my_Thread_mutex_t;
#define     my_Mutex_Lock(mutex)    WaitForSingleObject(mutex, INFINITE)
#define     my_Mutex_UnLock(mutex)  ReleaseMutex(mutex)
#define     my_Mutex_Close(mutex)   CloseHandle(mutex)
#define     my_SocketClose(skt)     closesocket(skt)
#define     my_Thread_exit(a)       return(a)
#define     SNPRINTF                _snprintf
#define     LocalTime_R(a, b)       localtime_s(b, a)
#define     GmTime_R(a, b)          gmtime_s(b, a)
#elif defined(LINUX)
typedef     pthread_t               my_threadid;
typedef     pthread_mutex_t         my_Thread_mutex_t;
#define     my_Mutex_Lock(mutex)    pthread_mutex_lock(&mutex)
#define     my_Mutex_UnLock(mutex)  pthread_mutex_unlock(&mutex)
#define     my_Mutex_Close(mutex)   pthread_mutex_destroy(&mutex)
#define     my_SocketClose(skt)     close(skt)
#define     my_Thread_exit(a)       pthread_exit(a)
#define     SNPRINTF                snprintf
#define     LocalTime_R(a, b)       localtime_r(a, b)
#define     GmTime_R(a, b)          gmtime_r(a, b)
#endif

//// for Device && Client
#define SIZE_DID                	24
#define SIZE_InitString         	200
#define SIZE_AES128Key              20
//// for Device
#define SIZE_LNS                    12
//// for WiPN API Device&&Client
#define SIZE_UTCTString         	16
#define SIZE_RETString              32
#define SIZE_DeviceName             64
#define SIZE_SNDIDString            600
//// for WiPN API Device Post
#define SIZE_Title                  32
#define SIZE_Content            	256
#define SIZE_Payload            	180	//Payload size: huawei: max size(96), apns and fcm max size(128)
#define SIZE_SoundName          	64
//// for WiPN API Client Subscribe
#define SIZE_APPName                24
#define SIZE_Token                  128
#define SIZE_ListString             630
#define SIZE_SPSInfo                300

// #define OLN_ON_EVENT_CH     0x7FFFFF01  //2147483393
// #define OLN_OFF_EVENT_CH    0x7FFFFF02  //2147483394

//// WiPN NDT InitString && NDT AES128Key.
#define NDT_INITSTRING  "EBGAEIBIKHJJGFJKEOGCFAEPHPMAHONDGJFPBKCPAJJMLFKBDBAGCJPBGOLKIKLKAJMJKFDOOFMOBECEJIMM"
#define NDT_AES128KEY   "0123456789ABCDEF"
// WiPN
#define QS_NUM       2  // QueryServer DID Number.
#define QSDID_1     "PPCS-014143-SBKHR"
#define QSDID_2     "PPCS-014144-RVDKK"
#define WiPN_KEY     "WiPN@CS2-Network"

#define UTCT_SERVER_HOST            "www.cs2-aipn.com"
#define UTCT_SERVER_PORT            16868
#define REQUEST_STRING              "$UTCTServer@cs2-aipn:Hello_Please_Tell_me_UTCT$"

//// 以下两个变量 gUTCTString 与 gLocalT0 在正确获取UTCT值后，请务必将相应的值保存至本地，为下次获取新的 UTCT 提供计算参数。
//// gUTCTString 与 gLocalT0 必须同步更新。
extern char gUTCTString[SIZE_UTCTString];
extern time_t gLocalT0;

//// Time delay unit: ms
void _WiPN_mSecSleep(unsigned int ms);
//// get NDT Error Code Info
const char *getNDTErrorCodeInfo(int err);
//// get SPS Error Code Info
const char *getSPSErrorCodeInfo(int err);
//// get NDT/WiPN Error Code Info
const char *getWiPNErrorCodeInfo(int err);

//// Windows socket init and deinit. ret:0->OK,-1->error.
int WinSockInit();
void WinSockDeInit();

/*
//// GetStrItem: string format must be: "IPxxxxxxPyyyy", such as:"IP127.0.0.1Port32121", So we need to use this API to get IP(xxxxxx) or port(yyyy), and we can use this API to get other similar strings.
Example:
    char *DLInfo = "IP127.0.0.1Port32121";
    char IP[24] = {};
    GetStrItem(DLInfo, "IP", 'P', IP, sizeof(IP));
//// return code: ret=0 OK, ret=-1: Invalid Parameter, ret=-2: No such Item
*/
int GetStrItem(const char *SrcStr, const char *ItemName, const char Seperator, char *RetString, const int MaxSize);
//// GetStringItem: string have '=' and ',', such as: "Post=02,ABCD-000000-ABCDE,ABCD-000000-ABCDE&"
//// return code: ret=0 OK, ret=-1: Invalid Parameter, ret=-2: No such Item
int GetStringItem(const char *SrcStr, const char *ItemName, const char Seperator, char *RetString, const int MaxSize);
//// parse_number: to get DID Number and DID Lenght, pServerString such as: "Post=02,ABCD-000000-ABCDE,ABCD-000000-ABCDE&", call parse_number to get DID Number=02.
//// return: 0->OK, <0 failed.
int parse_number(const char *pServerString, unsigned short *pOutput_DIDNumber, unsigned char *pOutput_DIDLen);
//// GetOneDID: output one DID for the specified index form "NN,DID,DID,DID,...,DID"
//// return: 0->OK, <0 failed.
int GetOneDID(const char *pServerString, int index, char *output_OneDID, unsigned int outputBufSize);
// //// return: success->DID,failed->NULL.
// //// after call parse_DID,if success, you must call free() to release memory buffer.
// const char *parse_DID(const char *pServerString, int index);

//// Split_DID: to get DID and Number and DID Lenght. ServerDIDString: "NN,DID,DID,DID,...,DID"
//// sample: "03,PPCS-123456-ETLRN,PPCS-123456-HYEXE,PPCS-123456-RFVMV"
//// return:0->OK, <0 failed.
int Split_DID(const char *pServerDIDString, unsigned short *pOutput_DIDNumber, unsigned char *pOutput_DIDLen, char **pResultBuf);
//// Get Body From Http data
int GetHTTPBody(const char *SrcStr, const char *Seperator, char *RetStr, unsigned int MaxSizeOfRetStr);

//// 保存或更新 UTCT 与当下的本地时间。
//// ret:0->OK, <0 failed.
int Update_UTCT(const char *UTCT);
//// time_UTCT 内部的实现:
//// 1.先判断与上一次向服务器(包括从 QS/SN 询问取得的结果)询问的时间间隔是否超过24小时，超过则执行 UDP/TCP 协议向 UTCTServer 获取，否则直接返回[本地的时间戳与上一次询问的UTCT之和]，以保证在 24 小时内不得重复向 UTCTServer 查询。
//// 2.在正确获取 UTCT 值后，请务必将 UTCT 值保存下来，并把当下的本地时间(gLocalT0)记录下来，之后在调用 time_UTCT 时，可以根据本地时间差( time(NULL) - gLocalT0 )加上 UTCT 来求得现在的 UTCT_Now。
//// 3.time_UTCT 内会进行域名解析，网络不好情况下将会阻塞，非常耗时，建议保存域名解析的结果IP，下一次调用直接使用IP。
unsigned int time_UTCT(unsigned int *t);

//// http POST request, ret>=0: datasize, ret<0: something error
int HTTP_POST(const char *pHost,
            unsigned short Port,
            const char *pUrl,
            const char *pBody, //// if http, Body is Enc(CMD), if https, Body is CMD.
            char *Result,
            unsigned int RBufSize,
            unsigned int TimeOut_ms);

#ifdef __cplusplus
}
#endif
#endif
