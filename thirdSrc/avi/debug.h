#ifndef __DEBUG_APP_H__
#define __DEBUG_APP_H__

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

#include "hi_type.h"


#define MAX_LENGTH_OF_FUNC	32//13	//���������ȣ������޸�
#define MAX_LENGTH_OF_LEVEL	16	//level��Ϣ��ӡ���ȣ�һ�㲻���޸�
//#define MAX_LENGTH_OF_DATA	24	//���ڳ��ȣ�һ�㲻���޸�
//#define MAX_LENGTH_OF_FUNC_INFO	(MAX_LENGTH_OF_FUNC+MAX_LENGTH_OF_LEVEL+16)
#define MAX_CHAR_NUM_IN_LINE	1024

/* printf colour */
#define NONE_C       "\033[m"
#define RED          "\033[0;32;31m"
#define LIGHT_RED    "\033[1;31m"
#define GREEN        "\033[0;32;32m"
#define LIGHT_GREEN  "\033[1;32m"
#define BLUE         "\033[0;32;34m"
#define LIGHT_BLUE   "\033[1;34m"
#define DARY_GRAY    "\033[1;30m"
#define CYAN         "\033[0;36m"
#define LIGHT_CYAN   "\033[1;36m"
#define PURPLE       "\033[0;35m"
#define LIGHT_PURPLE "\033[1;35m"
#define BROWN        "\033[0;33m"
#define YELLOW       "\033[1;33m"
#define LIGHT_GRAY   "\033[0;37m"
#define WHITE        "\033[1;37m"

/*todo,����������������صĵ��Զ��弶������ */
/*support DBG types*/
#define ERR			        2	//��ӡ��д��log�ļ�����ɫ���壬���ڴ�ӡ�쳣��Ϣ
#define PRI			        1	//��ӡ��д��log�ļ�����ɫ���壬���ڴ�ӡĳЩ��Ҫ��Ϣ
#define DBG			        5	//ֻ��ӡ��д��log�ļ�
#define WRN			        3	//��ӡ��д��log�ļ�����ɫ���壬���ڴ�ӡһЩ����������Ϣ
#define MAIN_DBG	        3	//����ģ��ĵ�����Ϣ
#define AV_DBG		        3	
#define NET_DBG		        3

/*������Ϣ �ȼ�*/
#define DBG_FATAL           (0)   /* system is unusable, used for printing fatal error with red color */
#define DBG_CRIT            (1)   /* critical conditions��used for printing some important information with blue color */
#define DBG_ERR             (2)   /* error conditions, used for printing normal error, but the system can still run with light red color */
#define DBG_WARN            (3)   /* warning conditions, used for printing warning informatins with yellow color */
#define DBG_INFO            (4)   /* informational, used for printing informations with green color */
#define DBG_DEBUG           (5)   /* debug-level messages, used for printing debug messages with white color */

#define MAX_DEBUG_LEVEL    (6)   /* max debug level count */


/*ģ����Կ���:  0,�رյ�����Ϣ;
               ��0,��ָ���ȼ�����(С��ָ���ȼ�)�ĵ�����Ϣ*/

#if(defined DEBUG_ON )
#define DEBUG_MAIN              3       /*������*/
#define DEBUG_DEVS              3       /*�豸����*/
#define DEBUG_DEVM              3       /*�豸����*/
#define DEBUG_MCTP              0       /*ý����ƴ���*/
#define DEBUG_MBUF              0       /*mbuf*/
#define DEBUG_TRANS             0       /*˽��Э��-����ģ��*/
#define DEBUG_OPRTM             0       /*˽��Э��-ҵ�����*/
#define DEBUG_INIT              0       /*��ʼ��ģ��*/
#define DEBUG_OUT               0       /*���ģ��*/
#define DEBUG_MD                0       /*MDģ��*/
#define DEBUG_OD                3	     /*ODģ��*/
#define DEBUG_OSD               3       /*OSDģ��*/
#define DEBUG_SNAP              3       /*ץ��ģ��*/
#define DEBUG_REC               0       /*¼��ģ��*/
#define DEBUG_AUTH              0       /*Ȩ��ģ��*/
#define DEBUG_PTZ               0       /*��̨����ģ��*/
#define DEBUG_ENC               3       /*����Ƶģ��*/
#define DEBUG_AI                3      /*AIģ��*/
#define DEBUG_VI                3       /*VIģ��*/
#define DEBUG_AO                3       /*AIģ��*/
#define DEBUG_VO                3       /*VOģ��*/
#define DEBUG_VENC              3       /*��Ƶ����ģ��*/
#define DEBUG_VDEC              3       /*��Ƶ����ģ��*/
#define DEBUG_AENC              3       /*��Ƶ����ģ��*/
#define DEBUG_ADEC              3       /*��Ƶ����ģ��*/
#define DEBUG_VPSS              3       /*��Ƶ����ģ��*/
#define DEBUG_MEDIA             3       /*ý�崦��ģ��*/
#define DEBUG_COVER             0       /*��Ƶ�ڵ�ģ��*/
#define DEBUG_CMD               0       /*������ģ��*/
#define DEBUG_TCMD              0       /*telnet������UIģ��*/
#define DEBUG_SYS               3       /*ϵͳ��Ϣģ��*/
#define DEBUG_USBDEV            0       /**/
#define DEBUG_MTRANS            3       /*�㲥ҵ��ģ��*/
#define DEBUG_VOD               3       /*�㲥ҵ��ģ��*/
#define DEBUG_HTTP_LIVE         3       /*�㲥ҵ��ģ��*/
#define DEBUG_RTSP_LIVE         3      /*�㲥ҵ��ģ��*/
#define DEBUG_TALK              0       /*�Խ�ҵ��ģ��*/
#define DEBUG_MAIL              0       /*�ʼ�����ģ��*/
#define DEBUG_NTP               0       /*ntpģ��*/
#define DEBUG_CGI               3       /*CGIģ��*/
#define DEBUG_EVENT             0       /*�¼�����*/
#define DEBUG_ALARM             0       /*�澯����*/
#define DEBUG_CONFACC           0       /*���ô�ȡ*/
#define DEBUG_NOTIFY            0       /*NOTIFY*/
#define DEBUG_TIMER             3       /*��ʱ����*/
#define DEBUG_LOG               3       /*��־*/
#define DEBUG_ISP               0       /*ISP*/
#define DEBUG_HAL               3       /*HAL*/
#define DEBUG_AUDIO             3       /*AUDIO*/
#define DEBUG_SCHE              3      /*�ճ̹���*/
#define DEBUG_HTTP              3      /*HTTPD*/
#define DEBUG_UPGRADE           3       /*UPGRADE*/
#define DEBUG_VODTRANS_LIVE_LIVE 3
#define DEBUG_RTSP_O_HTTP_LIVE   3
#define DEBUG_VSCP               0
#define DEBUG_SLOG               4

#else
#define DEBUG_MAIN              0       /*������*/
#define DEBUG_DEVS              0       /*�豸����*/
#define DEBUG_DEVM              0       /*�豸����*/
#define DEBUG_MCTP              0       /*ý����ƴ���*/
#define DEBUG_MBUF              0       /*mbuf*/
#define DEBUG_TRANS             0       /*˽��Э��-����ģ��*/
#define DEBUG_OPRTM             0       /*˽��Э��-ҵ�����*/
#define DEBUG_INIT              0       /*��ʼ��ģ��*/
#define DEBUG_OUT               0       /*���ģ��*/
#define DEBUG_MD                0       /*MDģ��*/
#define DEBUG_OD                0	     /*ODģ��*/
#define DEBUG_OSD               0       /*OSDģ��*/
#define DEBUG_SNAP              0       /*ץ��ģ��*/
#define DEBUG_REC               0       /*¼��ģ��*/
#define DEBUG_AUTH              0       /*Ȩ��ģ��*/
#define DEBUG_PTZ               0       /*��̨����ģ��*/
#define DEBUG_ENC               0       /*����Ƶģ��*/
#define DEBUG_AI                0      /*AIģ��*/
#define DEBUG_VI                0       /*VIģ��*/
#define DEBUG_AO                0       /*AIģ��*/
#define DEBUG_VO                0       /*VOģ��*/
#define DEBUG_VENC              0       /*��Ƶ����ģ��*/
#define DEBUG_VDEC              0       /*��Ƶ����ģ��*/
#define DEBUG_AENC              0       /*��Ƶ����ģ��*/
#define DEBUG_ADEC              0       /*��Ƶ����ģ��*/
#define DEBUG_VPSS              0       /*��Ƶ����ģ��*/
#define DEBUG_MEDIA             0       /*ý�崦��ģ��*/
#define DEBUG_COVER             0       /*��Ƶ�ڵ�ģ��*/
#define DEBUG_CMD               0       /*������ģ��*/
#define DEBUG_TCMD              0       /*telnet������UIģ��*/
#define DEBUG_SYS               0       /*ϵͳ��Ϣģ��*/
#define DEBUG_USBDEV            0       /**/
#define DEBUG_MTRANS            0       /*�㲥ҵ��ģ��*/
#define DEBUG_VOD               0       /*�㲥ҵ��ģ��*/
#define DEBUG_HTTP_LIVE         0       /*�㲥ҵ��ģ��*/
#define DEBUG_RTSP_LIVE         0      /*�㲥ҵ��ģ��*/
#define DEBUG_TALK              0       /*�Խ�ҵ��ģ��*/
#define DEBUG_MAIL              0       /*�ʼ�����ģ��*/
#define DEBUG_NTP               0       /*ntpģ��*/
#define DEBUG_CGI               0       /*CGIģ��*/
#define DEBUG_EVENT             0       /*�¼�����*/
#define DEBUG_ALARM             0       /*�澯����*/
#define DEBUG_CONFACC           0       /*���ô�ȡ*/
#define DEBUG_NOTIFY            0       /*NOTIFY*/
#define DEBUG_TIMER             0       /*��ʱ����*/
#define DEBUG_LOG               0       /*��־*/
#define DEBUG_ISP               0       /*ISP*/
#define DEBUG_HAL               0       /*HAL*/
#define DEBUG_AUDIO             0       /*AUDIO*/
#define DEBUG_SCHE              0      /*�ճ̹���*/
#define DEBUG_HTTP              0      /*HTTPD*/
#define DEBUG_UPGRADE           0       /*UPGRADE*/
#define DEBUG_VODTRANS_LIVE_LIVE 0
#define DEBUG_RTSP_O_HTTP_LIVE   0
#define DEBUG_VSCP               0
#define DEBUG_SLOG               2
#endif  /* DEBUG_ON */

HI_S32 DEBUG_FLPrintf(const HI_CHAR* pszModeName, HI_U32 u32Level,
                                const HI_CHAR* pszFileName, HI_S32 s32Line, HI_CHAR* pszFmt, ...);

/*��־,Ϊ��linuxϵͳ����־�궨��������������log������ر����PRINT��׺������ */
#if (DEBUG_LOG == 0) 
    #define LOG_DEBUG_PRINT(u32Level, args ...)
#else
    #define LOG_DEBUG_PRINT(u32Level, args ...)   \
        do  \
        {   \
            if (DEBUG_LOG >= u32Level)  \
            {   \
                DEBUG_FLPrintf("LOG", u32Level, __FILE__, __LINE__, args);   \
            }   \
        }   \
        while(0)
#endif

/*ץ�Ĺ���*/
#if (DEBUG_SNAP == 0)
    #define SNAP_DEBUG(u32Level, args ...)
#else
    #define SNAP_DEBUG(u32Level, args ...)   \
        do  \
        {   \
            if (DEBUG_SNAP >= u32Level)  \
            {   \
                DEBUG_FLPrintf("SNAP", u32Level, __FILE__, __LINE__, args);   \
            }   \
        }   \
        while(0)
#endif

/*��ʱ����*/
#if (DEBUG_TIMER == 0)
    #define TIMER_DEBUG(u32Level, args ...)
#else
    #define TIMER_DEBUG(u32Level, args ...)   \
        do  \
        {   \
            if (DEBUG_TIMER >= u32Level)  \
            {   \
                DEBUG_FLPrintf("TIMER", u32Level, __FILE__, __LINE__, args);   \
            }   \
        }   \
        while(0)
#endif

/*������*/
#if (DEBUG_MAIN == 0) 
    #define MAIN_DEBUG(u32Level, args ...)
#else
    #define MAIN_DEBUG(u32Level, args ...)   \
        do  \
        {   \
            if (DEBUG_MAIN >= u32Level)  \
            {   \
                DEBUG_FLPrintf("MAIN", u32Level, __FILE__, __LINE__, args);   \
            }   \
        }   \
        while(0)
#endif

/*notify*/
#if (DEBUG_NOTIFY == 0) 
    #define NOTIFY_DEBUG(u32Level, args ...)
#else
    #define NOTIFY_DEBUG(u32Level, args ...)   \
        do  \
        {   \
            if (DEBUG_NOTIFY >= u32Level)  \
            {   \
                DEBUG_FLPrintf("NOTIFY", u32Level, __FILE__, __LINE__, args);   \
            }   \
        }   \
        while(0)
#endif

/*�豸����*/
#if (DEBUG_DEVS == 0) 
    #define DEVS_DEBUG(u32Level, args ...)
#else
    #define DEVS_DEBUG(u32Level, args ...)   \
    do  \
    {   \
        if (DEBUG_DEVS >= u32Level)  \
        {   \
            DEBUG_FLPrintf("DEV_SEARCH", u32Level, __FILE__, __LINE__, args);    \
        }   \
    }   \
    while(0)
#endif

/*���ô�ȡ*/
#if (DEBUG_CONFACC == 0) 
    #define CONFACC_DEBUG(u32Level, args ...)
#else
    #define CONFACC_DEBUG(u32Level, args ...)   \
    do  \
    {   \
        if (DEBUG_CONFACC >= u32Level)  \
        {   \
            DEBUG_FLPrintf("CONFACC", u32Level, __FILE__, __LINE__, args);    \
        }   \
    }   \
    while(0)
#endif

/*�豸����*/
#if (DEBUG_DEVM == 0) 
    #define DEVM_DEBUG(u32Level, args ...)
#else
    #define DEVM_DEBUG(u32Level, args ...)   \
    do  \
    {   \
        if (DEBUG_DEVM >= u32Level)  \
        {   \
            DEBUG_FLPrintf("DEVMNG", u32Level, __FILE__, __LINE__,args);    \
        }   \
    }   \
    while(0)
#endif

/**/
#if (DEBUG_USBDEV == 0) 
    #define USBDEV_DEBUG(u32Level, args ...)
#else
    #define USBDEV_DEBUG(u32Level, args ...)   \
    do  \
    {   \
        if (DEBUG_USBDEV >= u32Level)  \
        {   \
            DEBUG_FLPrintf("USBDEV", u32Level, __FILE__, __LINE__,args);    \
        }   \
    }   \
    while(0)
#endif

/*ý����ƴ���*/
#if (DEBUG_MCTP == 0) 
    #define MCTP_DEBUG(u32Level, args ...)
#else
    #define MCTP_DEBUG(u32Level, args ...)   \
    do  \
    {   \
        if (DEBUG_MCTP >= u32Level)  \
        {   \
            DEBUG_FLPrintf("MCTP", u32Level, __FILE__, __LINE__, args);    \
        }   \
    }   \
    while(0)
#endif

/*Mbuf*/
#if (DEBUG_MBUF == 0) 
    #define MBUF_DEBUG(u32Level, args ...)
#else
    #define MBUF_DEBUG(u32Level, args ...)  \
    do  \
    {   \
        if (DEBUG_MBUF >= u32Level)  \
        {   \
            DEBUG_FLPrintf("MBUF", u32Level, __FILE__, __LINE__, args);    \
        }   \
    }   \
    while(0)
#endif

/*MTRANS*/
#if (DEBUG_MTRANS == 0) 
    #define MTRANS_DEBUG(u32Level, args ...)
#else
    #define MTRANS_DEBUG(u32Level, args ...)   \
    do  \
    {   \
        if (DEBUG_MTRANS >= u32Level)    \
        {   \
            DEBUG_FLPrintf("MTRANS", u32Level, __FILE__, __LINE__, args);   \
        }   \
    }   \
    while(0)
#endif

/*VOD*/
#if (DEBUG_VOD == 0) 
    #define VOD_DEBUG(u32Level, args ...)
#else
    #define VOD_DEBUG(u32Level, args ...)   \
    do  \
    {   \
        if (DEBUG_VOD >= u32Level)    \
        {   \
            DEBUG_FLPrintf("VOD", u32Level, __FILE__, __LINE__, args);   \
        }   \
    }   \
    while(0)
#endif

/*http for live*/
#if (DEBUG_HTTP_LIVE == 0) 
    #define HTTP_LIVE_DEBUG(u32Level, args ...)
#else
    #define HTTP_LIVE_DEBUG(u32Level, args ...)   \
    do  \
    {   \
        if (DEBUG_HTTP_LIVE >= u32Level)    \
        {   \
            DEBUG_FLPrintf("HTTP_LIVE", u32Level, __FILE__, __LINE__, args);   \
        }   \
    }   \
    while(0)
#endif

/*VODTRANS for live*/
#if (DEBUG_VODTRANS_LIVE_LIVE == 0) 
    #define VODTRANS_LIVE_DEBUG(u32Level, args ...)
#else
    #define VODTRANS_LIVE_DEBUG(u32Level, args ...)   \
    do  \
    {   \
        if (DEBUG_VODTRANS_LIVE_LIVE >= u32Level)    \
        {   \
            DEBUG_FLPrintf("VODTRANS", u32Level, __FILE__, __LINE__, args);   \
        }   \
    }   \
    while(0)
#endif


/*rtsp over http for live*/
#if (DEBUG_RTSP_O_HTTP_LIVE == 0) 
    #define RTSP_O_HTTP_LIVE_DEBUG(u32Level, args ...)
#else
#define RTSP_O_HTTP_LIVE_DEBUG(u32Level, args ...)   \
    do  \
    {   \
        if (DEBUG_RTSP_O_HTTP_LIVE >= u32Level)    \
        {   \
            printf(args);   \
        }   \
    }   \
    while(0)
#endif

/*rtsp for live*/
#if (DEBUG_RTSP_LIVE == 0) 
    #define RTSP_DEBUG(u32Level, args ...)
#else
    #define RTSP_DEBUG(u32Level, args ...)   \
    do  \
    {   \
        if (DEBUG_RTSP_LIVE >= u32Level)    \
        {   \
            DEBUG_FLPrintf("RTSP", u32Level, __FILE__, __LINE__, args);   \
        }   \
    }   \
    while(0)
#endif

/*TALK*/
#if (DEBUG_TALK == 0) 
    #define TALK_DEBUG(u32Level, args ...)
#else
    #define TALK_DEBUG(u32Level, args ...)   \
    do  \
    {   \
        if (DEBUG_TALK >= u32Level)    \
        {   \
            DEBUG_FLPrintf("TALK", u32Level, __FILE__, __LINE__, args);   \
        }   \
    }   \
    while(0)
#endif

/*MDģ��*/
#if (DEBUG_MD == 0) 
    #define MD_DEBUG(u32Level, args ...)
#else
    #define MD_DEBUG(u32Level, args ...)  \
    do  \
    {   \
        if (DEBUG_MD >= u32Level)  \
        {   \
            DEBUG_FLPrintf("MD", u32Level, __FILE__, __LINE__, args);    \
        }   \
    }   \
    while(0)
#endif

/*ODģ��*/
#if (DEBUG_OD == 0) 
    #define OD_DEBUG(u32Level, args ...)
#else
    #define OD_DEBUG(u32Level, args ...)  \
     do  \
     {   \
         if (DEBUG_OD >= u32Level)  \
         {   \
             DEBUG_FLPrintf("OD", u32Level, __FILE__, __LINE__, args);    \
         }   \
     }   \
     while(0)
#endif

/*OSDģ��*/
#if (DEBUG_OSD == 0) 
    #define OSD_DEBUG(u32Level, args ...)
#else
    #define OSD_DEBUG(u32Level, args ...) \
    do  \
    {   \
        if (DEBUG_OSD >= u32Level)  \
        {   \
            DEBUG_FLPrintf("OSD", u32Level, __FILE__, __LINE__, args);    \
        }   \
    }   \
    while(0)
#endif

/*¼��ģ��*/
#if (DEBUG_REC == 0) 
    #define REC_DEBUG(u32Level, args ...)
#else
    #define REC_DEBUG(u32Level, args ...) \
    do  \
    {   \
        if (DEBUG_REC >= u32Level)  \
        {   \
            DEBUG_FLPrintf("REC", u32Level, __FILE__, __LINE__, args);    \
        }   \
    }   \
    while(0)
#endif

/*Ȩ�޹���ģ��*/
#if (DEBUG_AUTH == 0) 
    #define AUTH_DEBUG(u32Level, args ...)
#else
    #define AUTH_DEBUG(u32Level, args ...) \
    do  \
    {   \
        if (DEBUG_AUTH >= u32Level)  \
        {   \
            DEBUG_FLPrintf("AUTH", u32Level, __FILE__, __LINE__, args);    \
        }   \
    }   \
    while(0)
#endif

/*��̨����ģ��*/
#if (DEBUG_PTZ == 0) 
    #define PTZ_DEBUG(u32Level, args ...)
#else
    #define PTZ_DEBUG(u32Level, args ...)    \
    do  \
    {   \
        if (DEBUG_PTZ >= u32Level)  \
        {   \
            DEBUG_FLPrintf("PTZ", u32Level, __FILE__, __LINE__, args);    \
        }   \
    }   \
    while(0)
#endif

/*AIģ��*/
#if (DEBUG_AI == 0) 
    #define AI_DEBUG(u32Level, args ...)
#else
    #define AI_DEBUG(u32Level, args ...)    \
        do  \
        {   \
            if (DEBUG_AI >= u32Level)  \
            {   \
                DEBUG_FLPrintf("AI", u32Level, __FILE__, __LINE__, args);    \
            }   \
        }   \
        while(0)
#endif

/*AOģ��*/
#if (DEBUG_AO == 0) 
    #define AO_DEBUG(u32Level, args ...)
#else
    #define AO_DEBUG(u32Level, args ...)    \
        do  \
        {   \
            if (DEBUG_AO >= u32Level)  \
            {   \
                DEBUG_FLPrintf("AO", u32Level, __FILE__, __LINE__, args);    \
            }   \
        }   \
        while(0)
#endif

/*AENCģ��*/
#if (DEBUG_AENC == 0) 
    #define AENC_DEBUG(u32Level, args ...)
#else
    #define AENC_DEBUG(u32Level, args ...)    \
        do  \
        {   \
            if (DEBUG_AENC >= u32Level)  \
            {   \
                DEBUG_FLPrintf("AENC", u32Level, __FILE__, __LINE__, args);    \
            }   \
        }   \
        while(0)
#endif

/*ADECģ��*/
#if (DEBUG_ADEC == 0) 
    #define ADEC_DEBUG(u32Level, args ...)
#else
    #define ADEC_DEBUG(u32Level, args ...)    \
        do  \
        {   \
            if (DEBUG_ADEC >= u32Level)  \
            {   \
                DEBUG_FLPrintf("ADEC", u32Level, __FILE__, __LINE__, args);    \
            }   \
        }   \
        while(0)
#endif

/*VIģ��*/
#if (DEBUG_VI == 0) 
    #define VI_DEBUG(u32Level, args ...)
#else
    #define VI_DEBUG(u32Level, args ...)    \
        do  \
        {   \
            if (DEBUG_VI >= u32Level)  \
            {   \
                DEBUG_FLPrintf("VI", u32Level, __FILE__, __LINE__, args);    \
            }   \
        }   \
        while(0)
#endif

/*VOģ��*/
#if (DEBUG_VO == 0) 
    #define VO_DEBUG(u32Level, args ...)
#else
    #define VO_DEBUG(u32Level, args ...)    \
        do  \
        {   \
            if (DEBUG_VO >= u32Level)  \
            {   \
                DEBUG_FLPrintf("VO", u32Level, __FILE__, __LINE__, args);    \
            }   \
        }   \
        while(0)
#endif

/*VPSSģ��*/
#if (DEBUG_VPSS == 0) 
    #define VPSS_DEBUG(u32Level, args ...)
#else
    #define VPSS_DEBUG(u32Level, args ...)    \
        do  \
        {   \
            if (DEBUG_VPSS >= u32Level)  \
            {   \
                DEBUG_FLPrintf("VPSS", u32Level, __FILE__, __LINE__, args);    \
            }   \
        }   \
        while(0)
#endif

/*VENCģ��*/
#if (DEBUG_VENC == 0) 
    #define VENC_DEBUG(u32Level, args ...)
#else
    #define VENC_DEBUG(u32Level, args ...)    \
        do  \
        {   \
            if (DEBUG_VENC >= u32Level)  \
            {   \
                DEBUG_FLPrintf("VENC", u32Level, __FILE__, __LINE__, args);    \
            }   \
        }   \
        while(0)
#endif

/*VDECģ��*/
#if (DEBUG_VDEC == 0) 
    #define VDEC_DEBUG(u32Level, args ...)
#else
    #define VDEC_DEBUG(u32Level, args ...)    \
        do  \
        {   \
            if (DEBUG_VDEC >= u32Level)  \
            {   \
                DEBUG_FLPrintf("VDEC", u32Level, __FILE__, __LINE__, args);    \
            }   \
        }   \
        while(0)
#endif


/*MEDIAģ��*/
#if (DEBUG_MEDIA == 0) 
    #define MEDIA_DEBUG(u32Level, args ...)
#else
    #define MEDIA_DEBUG(u32Level, args ...)    \
        do  \
        {   \
            if (DEBUG_MEDIA >= u32Level)  \
            {   \
                DEBUG_FLPrintf("MEDIA", u32Level, __FILE__, __LINE__, args);    \
            }   \
        }   \
        while(0)
#endif

/*��Ƶ�ڵ�ģ��*/
#if (DEBUG_COVER == 0) 
    #define COVER_DEBUG(u32Level, args ...)
#else
    #define COVER_DEBUG(u32Level, args ...)    \
        do  \
        {   \
            if (DEBUG_COVER >= u32Level)  \
            {   \
                DEBUG_FLPrintf("COVER", u32Level, __FILE__, __LINE__, args);    \
            }   \
        }   \
        while(0)
#endif

/*������ģ��*/
#if (DEBUG_CMD == 0) 
    #define CMD_DEBUG(u32Level, args ...)
#else
    #define CMD_DEBUG(u32Level, args ...)    \
    do  \
    {   \
        if (DEBUG_CMD >= u32Level)  \
        {   \
            DEBUG_FLPrintf("CMD", u32Level, __FILE__, __LINE__, args);    \
        }   \
    }   \
    while(0)
#endif

/*telnet������UIģ��*/
#if (DEBUG_TCMD == 0) 
    #define TCMD_DEBUG(u32Level, args ...)
#else
    #define TCMD_DEBUG(u32Level, args ...)   \
    do  \
    {   \
        if (DEBUG_TCMD >= u32Level)  \
        {   \
            DEBUG_FLPrintf("TCMD", u32Level, __FILE__, __LINE__, args);    \
        }   \
    }   \
    while(0)
#endif

/*ϵͳ��Ϣģ��*/
#if (DEBUG_SYS == 0) 
    #define SYS_DEBUG(u32Level, args ...)
#else
    #define SYS_DEBUG(u32Level, args ...)    \
    do  \
    {   \
        if (DEBUG_SYS >= u32Level)  \
        {   \
            DEBUG_FLPrintf("SYS", u32Level, __FILE__, __LINE__,args);    \
        }   \
    }   \
    while(0)
#endif

/*�¼�����*/
#if (DEBUG_EVENT == 0) 
    #define EVENT_DEBUG(u32Level, args ...)
#else
    #define EVENT_DEBUG(u32Level, args ...)     \
    do  \
    {   \
        if (DEBUG_EVENT >= u32Level)  \
        {   \
            DEBUG_FLPrintf("EVENT", u32Level, __FILE__, __LINE__, args);    \
        }   \
    }   \
    while(0)
#endif

/*�澯����*/
#if (DEBUG_ALARM == 0) 
    #define ALARM_DEBUG(u32Level, args ...)
#else
    #define ALARM_DEBUG(u32Level, args ...)     \
    do  \
    {   \
        if (DEBUG_ALARM >= u32Level)  \
        {   \
            DEBUG_FLPrintf("ALARM", u32Level, __FILE__, __LINE__, args);    \
        }   \
    }   \
    while(0)
#endif


/*�ʼ�����*/
#if (DEBUG_MAIL == 0) 
    #define MAIL_DEBUG(u32Level, args ...)
#else
    #define MAIL_DEBUG(u32Level, args ...)     \
    do  \
    {   \
        if (DEBUG_MAIL >= u32Level)  \
        {   \
            DEBUG_FLPrintf("MAIL", u32Level, __FILE__, __LINE__, args);    \
        }   \
    }   \
    while(0)
#endif

/*NTP*/
#if (DEBUG_NTP == 0) 
    #define NTP_DEBUG(u32Level, args ...)
#else
    #define NTP_DEBUG(u32Level, args ...)     \
    do  \
    {   \
        if (DEBUG_NTP >= u32Level)  \
        {   \
            DEBUG_FLPrintf("DEBUG", u32Level, __FILE__, __LINE__, args);    \
        }   \
    }   \
    while(0)
#endif

/*CGI*/
#if ((DEBUG_CGI == 0) )
    #define CGI_DEBUG(u32Level, args ...)
#else
    #define CGI_DEBUG(u32Level, args ...)   \
    do  \
    {   \
        if (DEBUG_CGI >= u32Level)  \
        {   \
            DEBUG_FLPrintf("CGI", u32Level, __FILE__, __LINE__, args);    \
        }   \
    }   \
    while(0)
#endif

/*ISPģ��*/
#if (DEBUG_ISP == 0) 
    #define ISP_DEBUG(u32Level, args ...)
#else
    #define ISP_DEBUG(u32Level, args ...)    \
        do  \
        {   \
            if (DEBUG_ISP >= u32Level)  \
            {   \
                DEBUG_FLPrintf("ISP", u32Level, __FILE__, __LINE__, args);    \
            }   \
        }   \
        while(0)
#endif

/*HALģ��*/
#if (DEBUG_HAL == 0) 
    #define HAL_DEBUG(u32Level, args ...)
#else
    #define HAL_DEBUG(u32Level, args ...)    \
            do  \
            {   \
                if (DEBUG_HAL >= u32Level)  \
                {   \
                    DEBUG_FLPrintf("HAL", u32Level, __FILE__, __LINE__, args);    \
                }   \
            }   \
            while(0)
#endif

/*AUDIOģ��*/
#if (DEBUG_AUDIO == 0) 
    #define AUDIO_DEBUG(u32Level, args ...)
#else
    #define AUDIO_DEBUG(u32Level, args ...)    \
            do  \
            {   \
                if (DEBUG_AUDIO >= u32Level)  \
                {   \
                    DEBUG_FLPrintf("AUDIO", u32Level, __FILE__, __LINE__, args);    \
                }   \
            }   \
            while(0)
#endif

/*SCHEDULEģ��*/
#if (DEBUG_SCHE == 0) 
    #define SCHE_DEBUG(u32Level, args ...)
#else
    #define SCHE_DEBUG(u32Level, args ...)    \
            do  \
            {   \
                if (DEBUG_SCHE >= u32Level)  \
                {   \
                    DEBUG_FLPrintf("SCHE", u32Level, __FILE__, __LINE__, args);    \
                }   \
            }   \
            while(0)
#endif

/*HTTPDģ��*/
#if (DEBUG_HTTP == 0) 
    #define HTTP_DEBUG(u32Level, args ...)
#else
    #define HTTP_DEBUG(u32Level, args ...)    \
            do  \
            {   \
                if (DEBUG_HTTP >= u32Level)  \
                {   \
                    DEBUG_FLPrintf("HTTPD", u32Level, __FILE__, __LINE__, args);    \
                }   \
            }   \
            while(0)
#endif

/*upgradeģ��*/
#if (DEBUG_UPGRADE== 0) 
    #define UPGRADE_DEBUG(u32Level, args ...)
#else
    #define UPGRADE_DEBUG(u32Level, args ...)    \
            do  \
            {   \
                if (DEBUG_UPGRADE >= u32Level)  \
                {   \
                    DEBUG_FLPrintf("UPGRADE", u32Level, __FILE__, __LINE__, args);    \
                }   \
            }   \
            while(0)
#endif

/*�豸����ģ��*/
#if (DEBUG_VSCP == 0) 
    #define VSCP_DEBUG(u32Level, args ...)
#else
    #define VSCP_DEBUG(u32Level, args ...)    \
            do  \
            {   \
                if (DEBUG_HTTP >= u32Level)  \
                {   \
                    DEBUG_FLPrintf("HTTPD", u32Level, __FILE__, __LINE__, args);    \
                }   \
            }   \
            while(0)
#endif



/*SLOG �ӿ�*/
#if (DEBUG_SLOG == 0) 
#define SLOG(level, fmt...)	
#else
#define SLOG(level, fmt...)	\
            do  \
            {   \
                if (DEBUG_SLOG >= level)  \
                {   \
                    DEBUG_FLPrintf(NULL, level, __FUNCTION__, __LINE__, fmt);\
                }   \
            }   \
            while(0)
#endif

//#define PLOG(level, fmt...)	\
//	do {	\
//		DEBUG_FLPrintf(NULL, level, __FUNCTION__, __LINE__, fmt);\
//	}while(0)

#ifndef CHECK_ARG
#define CHECK_ARG(args) do{ \
	    if(args == NULL){printf("%serr: invalid parames.\n%s", LIGHT_RED, NONE_C);\
		return HI_FAILURE;} \
}while(0)
#endif


#endif //end of __DEBUG_APP_H__
