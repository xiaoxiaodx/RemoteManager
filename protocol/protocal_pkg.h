
#ifndef _PROTOCAL_PKG_H_
#define _PROTOCAL_PKG_H_

#include <time.h>

#define MEIAN_HEAD 0xBEEE
#define MEIAN_HEAD1 0xBEEF

/******************************************************************************
//APP命令格式

|---------|-----------|-------------|-------------|-----------| 
|系统参数 | CMD_CHAR  |CMDMOD_ID    |  CMD_ID     | CMD_DIRECT|  
|---------|-------------------------|-------------|-----------| 
|<-4bits->|<--1bit--->|<---5bits--->|<--5bits---> |<--1bit--->|
CMD_CHAR: 0 --ASCII, 1 -- HEX;
CMD_DIRECT: 0 --REQ, 1 ---RESP;

******************************************************************************/

typedef enum tagCMDMOD_ID_E
{
    /*板端*/
    CMDMOD_ID_LOGIN     =0x01,
    CMDMOD_ID_VIDEO     =0x02,
    CMDMOD_ID_AUDIO     =0x03,
    CMDMOD_ID_VOD       =0x04,
    CMDMOD_ID_TALK      =0x04,
    CMDMOD_ID_MEDIA     =0x06,
    CMDMOD_ID_HW        =0x07,
    CMDMOD_ID_ISP       =0x08,
    CMDMOD_ID_VDA       =0x09,
    CMDMOD_ID_NET       =0x0A,
    CMDMOD_ID_PARA      =0x0B,
    CMDMOD_ID_PTZ       =0x0C,
    CMDMOD_ID_REC       =0x0D,
    CMDMOD_ID_MESS      =0x0E,
    CMDMOD_ID_NETWORK	=0x0F,
    CMDMOD_ID_REG		=0x10,
    CMDMOD_ID_TEST      =0x11,
	CMDMOD_ID_FACTORY	=0x12,
    
    CMDMOD_ID_BUTTY      = 0x1F,  /**/
} APPCMD_ID_E;
#define DEF_APPCMD_ASCII_REQ(CMDMOD, CMD_ID) \
    ((unsigned short)( ((CMDMOD) << 6 ) | ((CMD_ID)<<1 )|0))

#define DEF_APPCMD_HEX_REQ(CMDMOD, CMD_ID) \
    ((unsigned short)( (1<<11)|((CMDMOD) << 6 ) | ((CMD_ID)<<1 )|0))
    
#define APPCMD_RESP(APPCMD_ID) ((unsigned short)((APPCMD_ID)))    

#define APPERR(CMDMOD,ERR_ID) \
    ((unsigned short)( ((CMDMOD) << 8 )|(ERR_ID) ))



#define CMD_VIDEO_REQ		    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_VIDEO,1)   //0x0082
#define CMD_VIDEO_TRNS		    DEF_APPCMD_HEX_REQ(CMDMOD_ID_VIDEO,2)   //0x0884
#define CMD_VIDEO_STOP	    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_VIDEO,3)   //0x0086
#define CMD_GET_VIDEO_INFO	    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_VIDEO,4)   //0x0088

#define CMD_PUSHVIDEO_REQ	    DEF_APPCMD_HEX_REQ(CMDMOD_ID_VIDEO,5)     //0X088A

#define CMD_AUDIO_REQ		    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_AUDIO,1)   //0x00c2
#define CMD_AUDIO_TRNS		    DEF_APPCMD_HEX_REQ(CMDMOD_ID_AUDIO,2)   //0x08c4
#define CMD_AUDIO_STOP	    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_AUDIO,3)       //0x00c6
#define CMD_GET_AUDIO_OUTVOL DEF_APPCMD_ASCII_REQ(CMDMOD_ID_AUDIO,4) //0X00C8
#define	CMD_SET_AUDIO_OUTVOL DEF_APPCMD_ASCII_REQ(CMDMOD_ID_AUDIO,5) //0X00CA

#define CMD_TALK_REQ	    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_TALK,1)        //0x0102
#define CMD_TALK_DATA_TRANS	    DEF_APPCMD_HEX_REQ(CMDMOD_ID_TALK,2)    //0x0904
#define CMD_TALK_STOP		    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_TALK,3)        //0x0106

#define CMD_HELLO		    DEF_APPCMD_HEX_REQ(CMDMOD_ID_LOGIN,3)       //0x0846
#define CMD_DEBUG_GET_LOG		    DEF_APPCMD_HEX_REQ(CMDMOD_ID_LOGIN,4)   //0x0848
#define CMD_USR_KEY		    DEF_APPCMD_HEX_REQ(CMDMOD_ID_LOGIN,5)   //0x084A

#define CMD_GET_CURRENTPIC DEF_APPCMD_ASCII_REQ(CMDMOD_ID_MEDIA,1)        //0x0182

#define CMD_SEND_CURRENTPIC DEF_APPCMD_HEX_REQ(CMDMOD_ID_MEDIA,1)        //0x0982

/*** User/System/Misc Module ***/
#define CMD_USR_LINK		    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_LOGIN,1) //0x0042
#define CMD_DEV_CLOSED		    0xfefe // used in cms

#define CMD_LOGIN		    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_LOGIN,2) //0x0044

#define CMD_NEW_PROTROL              0x9ff9//DEF_APPCMD_ASCII_REQ(CMDMOD_ID_LOGIN,2) //0x0044//新协议都使用这个命令字
//系统信息
#define CMD_GET_SYSINFO		    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_PARA,1)  //0x02c2
#define CMD_SET_SYSINFO		    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_PARA,2)  //0x02c4

//修改用户密码
#define CMD_GET_USRINFO		    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_PARA,3)  //0x02c6
#define CMD_SET_USRINFO		    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_PARA,4)  //0x02c8


//用户链接数目
#define CMD_GET_USR_INFO		    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_PARA,5)  //0x02ca
//#define CMD_SET_USR_INFO		    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_PARA,6)      //0x02cc

//时间设置
#define CMD_GET_DEV_TIME		    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_PARA,7)  //0x02ce
#define CMD_SET_DEV_TIME		    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_PARA,8)  //0x02d0

//SD卡信息
#define CMD_GET_SD_INFO		    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_PARA,9)  //0x02d2
#define CMD_SET_SD_FORMAT		    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_PARA,10) //0x02d4

//设备能力集合 
#define CMD_GET_DEV_CAPACITY		    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_PARA,11) //0x02d6

//EMail设置
#define CMD_GET_EMAIL		    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_PARA,12)  //0x02d8
#define CMD_SET_EMAIL		    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_PARA,13) //0x02da
#define CMD_SET_EMAIL_TEST		    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_PARA,14) //0x02dc

//RTMP 设置
#define CMD_REC_GET_RTMPCFG	    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_PARA,15)      //0x02de
#define CMD_REC_SET_RTMPCFG	    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_PARA,16)      //0x02e0

// NTP 设置
#define CMD_GET_NTP 		    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_PARA,17) //0x02e2
#define CMD_SET_NTP 		    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_PARA,18) //0x02e4

// OSD 设置
#define CMD_GET_OSD 		    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_PARA,19) //0x02e6
#define CMD_SET_OSD 		    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_PARA,20) //0x02e8

// AlARMSERV 设置
#define CMD_GET_AlARMSERV_PARA   DEF_APPCMD_ASCII_REQ(CMDMOD_ID_PARA,21) //0x02ea
#define CMD_SET_AlARMSERV_PARA   DEF_APPCMD_ASCII_REQ(CMDMOD_ID_PARA,22) //0x02ec

//网络命令
#define CMD_GET_NET		    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_NET,1)   //0x0282
#define CMD_SET_NET		    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_NET,2)   //0x0284
#define CMD_GET_WIFI		    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_NET,3)   //0x0286
#define CMD_SET_WIFI		    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_NET,4)   //0x0288
#define CMD_SCAN_WIFI   DEF_APPCMD_ASCII_REQ(CMDMOD_ID_NET,5)

//移动侦测开关和灵敏度
#define CMD_GET_MD		    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_VDA,1)       //0x0242
#define CMD_SET_MD		    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_VDA,2)       //0x0244
#define CMD_SET_MD_SCENE		    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_VDA,3)   //0x0246
#define CMD_GET_MD_SCENE		    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_VDA,4)   //0x0248

//消息推送
#define CMD_GET_MF		    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_MESS,1)      //0x0302
#define CMD_SET_MF		    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_MESS,2)      //0x0304
#define CMD_MF_MESS		DEF_APPCMD_ASCII_REQ(CMDMOD_ID_MESS,3)      //0x0306
#define  CMD_EVENT_REPORT   DEF_APPCMD_ASCII_REQ(CMDMOD_ID_MESS,4)    //0x0308
#define  CMD_PUSHVIDEO_GET   DEF_APPCMD_ASCII_REQ(CMDMOD_ID_MESS,5)    //0X038A

//视频有关参数
#define CMD_GET_VIDEOFLIP 		DEF_APPCMD_ASCII_REQ(CMDMOD_ID_ISP,1)   //0x0202
#define CMD_SET_VIDEOFLIP		DEF_APPCMD_ASCII_REQ(CMDMOD_ID_ISP,2)       //0x0204

#define CMD_GET_VIDEOMODE 		DEF_APPCMD_ASCII_REQ(CMDMOD_ID_ISP,3)   //0x0206
#define CMD_SET_VIDEOMODE		DEF_APPCMD_ASCII_REQ(CMDMOD_ID_ISP,4)       //0x0208


//录像计划
#define CMD_GET_REC_PLAN		DEF_APPCMD_ASCII_REQ(CMDMOD_ID_REC,1)       //0x0342
#define CMD_SET_REC_PLAN		DEF_APPCMD_ASCII_REQ(CMDMOD_ID_REC,2)       //0x0344
//录像质量获取、设置
#define CMD_GET_REC_QUALITY		DEF_APPCMD_ASCII_REQ(CMDMOD_ID_REC,14)		//0x35c
#define	CMD_SET_REC_QUALITY		DEF_APPCMD_ASCII_REQ(CMDMOD_ID_REC,15)		//0x35e

#define CMD_GET_REC_PARA		DEF_APPCMD_ASCII_REQ(CMDMOD_ID_REC,3)       //0x0346
#define CMD_SET_REC_PARA		DEF_APPCMD_ASCII_REQ(CMDMOD_ID_REC,4)       //0x0348


#define CMD_REC_REQ		    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_REC,5)       //0x034a
#define CMD_REC_VIDEO_TRNS		    DEF_APPCMD_HEX_REQ(CMDMOD_ID_REC,6) //0x0b4c
#define CMD_REC_STOP	    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_REC,7)           //0x034e
#define CMD_REC_PAUSE	    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_REC,8)           //0x0350
#define CMD_REC_CONTINUE	    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_REC,9)       //0x0352
#define CMD_REC_QUICKLY		DEF_APPCMD_ASCII_REQ(CMDMOD_ID_REC,16)

#define CMD_REC_GET_MDREC	    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_REC,10)      //0x0354
#define CMD_REC_SET_MDREC	    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_REC,11)      //0x0356


#define CMD_GET_REC_HISTORY		DEF_APPCMD_ASCII_REQ(CMDMOD_ID_REC,12)  //0x0358
#define CMD_REC_AUDIO_TRNS		    DEF_APPCMD_HEX_REQ(CMDMOD_ID_REC,13)   //0x0b5a


#define CMD_PTZ_STOP	    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_PTZ,1)       //0x0302
#define CMD_PTZ_MOVE	    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_PTZ,2)       //0x0304
#define CMD_PTZ_GETPARA	    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_PTZ,3)       //0x0306
#define CMD_PTZ_SETPARA	    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_PTZ,4)       //0x0308
//寄存器读写
#define CMD_GET_REGPARA		DEF_APPCMD_ASCII_REQ(CMDMOD_ID_REG, 1)		//0x402
#define CMD_SET_REGPARA		DEF_APPCMD_ASCII_REQ(CMDMOD_ID_REG, 2)		//0x404

//reboot cmd in app
#define CMD_REBOOT	    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_PTZ,5)       //0x030A

#define CMD_GET_PARA_DID    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_FACTORY,1) //0x0c82
#define CMD_SET_PARA_DID    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_FACTORY,2) //0x0c84


//test
#define CMD_AUDIO_TEST  DEF_APPCMD_ASCII_REQ(CMDMOD_ID_TEST,3)
#define CMD_UPGRADE 	DEF_APPCMD_ASCII_REQ(CMDMOD_ID_TEST,1)
#define CMD_UPGRADE_TRANS       DEF_APPCMD_ASCII_REQ(CMDMOD_ID_TEST,2)
#define CMD_SD_TEST	    DEF_APPCMD_ASCII_REQ(CMDMOD_ID_TEST,4)


#define APPERR_SUCCESS      0
#define APPERR_LOGIN_PWDERR      APPERR(CMDMOD_ID_LOGIN,1) //登录密码错误   //0x0101
#define APPERR_LOGIN_USRMAX     APPERR(CMDMOD_ID_LOGIN,2)//登录用户过多     //0x0102
#define APPERR_LOGIN_VODMAX     APPERR(CMDMOD_ID_LOGIN,3)//点播用户过多     //0x0103

#define APPERR_NO_PERMISSION    APPERR(CMDMOD_ID_LOGIN,4)//无权限           //0x0104
#define APPERR_ERRCMDID          APPERR(CMDMOD_ID_LOGIN,5)//无对应命令ID     //0x0105
#define APPERR_ERRCMDSTR            APPERR(CMDMOD_ID_LOGIN,6)//命令不匹配   //0x0106
#define APPERR_INTERNAL          APPERR(CMDMOD_ID_LOGIN,7)//内部错误        //0x0107
#define APPERR_NO_USRKEY          APPERR(CMDMOD_ID_LOGIN,8)//无对USRKEY     //0x0108
#define APPERR_REPLAY_MAX          APPERR(CMDMOD_ID_LOGIN,9)//回放用户过多     //0x0109

#define APPERR_TALKUSED         APPERR(CMDMOD_ID_TALK,0)//对讲使用中        //0x0400

#define APPERR_OLDPWD          APPERR(CMDMOD_ID_PARA,3)//旧密码错误         //0x0b03

#define APPERR_NORECFILE          APPERR(CMDMOD_ID_REC,1)//录像文件不存在   //0x0d01
#define APPERR_RECFILEEND         APPERR(CMDMOD_ID_REC,2)//播放结束 //0x0d02
#define APPERR_RECFILEERR         APPERR(CMDMOD_ID_REC,3)//录像文件获取异常 //0x0d03  //sd卡异常
#define APPERR_PUSHVIDEOFILE		   APPERR(CMDMOD_ID_REC,4)  //0Xd04 推送文件不存在
#define APPERR_PUSHVIDEOFILEERR		   APPERR(CMDMOD_ID_REC,5) 

#define APPERR_NETWORK_BLOCK           APPERR(CMDMOD_ID_NETWORK,1) //0x0f01
#define APPERR_NETWORK_IMPROVE         APPERR(CMDMOD_ID_NETWORK,2) //0x0f02


#define DEVICE_BC_PORT	    5678
#define CLIENT_BC_PORT	    8765

#define NET_INTFACE_WIRED   1
#define NET_INTFACE_WILAN   2
#define NET_MODE_DHCP	    1
#define NET_MODE_STATIC	    2

#define DEV_ONLINE	    0x1
#define DEV_OFFLINE	    0x2
#define CMD_BROADCAST_INFO	    0x0901
#define CMD_SET_BROADCAST_INFO	    0x0902

struct gsm_param_get_type
{
    int priority;
};

struct gsm_param_type
{
    unsigned char GsmEnable;                 /// Gsm ????  y
    unsigned char GprsEnable;                /// gprs ???? y
    unsigned char GprsApn[48];               /// gprs apn  y
    unsigned char GprsUser[48];              /// gprs user y
    unsigned char GprsPwd[48];    
};

struct gsm_param_get_res_type
{
    int flag; //0 success
    struct gsm_param_type gsm_param;
};

struct gsm_param_set_type
{
    int priority; //0 success
    struct gsm_param_type gsm_param;
};

struct gsm_param_set_res_type
{
    int flag; // 0 success    
};


struct phone_get_type
{
    int priority;
};

struct phone_param_type
{
    unsigned char UserPhone[4][18];
     unsigned char UserDialCnt; //dial num 
};

struct phone_get_res_type
{
    int flag; //0 success
    struct phone_param_type phone_param;
};

struct phone_set_type
{
    int priority; //0 success
    struct phone_param_type phone_param;
};

struct phone_set_res_type
{
    int flag; // 0 success    
};


struct ptz_control_type
{
    int priority;
    int cmd;
};

struct event_pos_info 
{
    unsigned int index;
    unsigned char id[4];
    char name[32];
};
struct event_report_res_type 
{/* XML protocol to client,binary to push server */
    char did[32];
    struct event_pos_info zone; 
    struct event_pos_info area;
    int video_rec; //0x1 have video record 0x0 no video record
    unsigned char cid_code[4];
    char snap_fname[64];
};


struct event_md_set_type
{
    int priority;
    int on;
    int level; 
};

struct event_md_set_res_type
{
    int flag; // 0 - success 1 - unauthorized 
};

struct event_md_get_type
{
    int priority;
};

struct event_md_get_res_type
{
    int flag; //0 success, 1 priority err
    int on;
    int level;
};

struct event_mail_set_type
{
    int priority;
    int on;
    char to[5][64];
    int smtp_use_on; // use below parameters,or use DEFAULT SMTP Server
    char smtp_server[32];
    int smtp_port;
    int security_protocol;//0:none,1:TLS, 2:STARTTLS
    char from_name[64];
    char from_passwd[64];
};

struct event_mail_set_res_type
{
    int flag; // 0 success 1 priority err 2 other error
};

struct event_mail_get_type
{
    int priority;
};

struct event_mail_get_res_type
{
    int flag; // 0 success 1 priority err
    int on;
    char to[5][64];
    int smtp_use_on; // use below parameters,or use DEFAULT SMTP Server
    char smtp_server[32];
    int smtp_port;
    int security_protocol;//0:none,1:TLS, 2:STARTTLS
    char from_name[64];
    char from_passwd[64];
};

struct event_mail_test_type
{
    int priority;
};

struct event_mail_test_res_type
{
    int flag; // 0 success 1 priority err
};

struct event_notify_type
{
    char did[32]; // device id
    int seq; // 0~255
    int type; // event type
    char desc[64]; // other specific information
};


struct login_type
{
    char did[32];
    char pwd[16];
    char usr[32];
    int flag;		// 0 p2p 1 relay server
};

struct login_res_type
{
	int flag; 		//0: access 1: usr full 2:pwd err
	int priority;	//usr priority
	int dev_type; //0x1: ipc h264 0x2: ipc h265
/* defined in mcu_alarm/mcu_protocal/McuCommunicationCmd.h,keep same: 
#define AREA_UNUSED   0
#define AREA_DISARM   1
#define AREA_STAY     2
#define AREA_ARM      3
*/
	int defense_status; 
	char ver[32];	//software version
	char resv[32];
};

struct net_mode_set_type
{
    int priority;
    int mode; //1 dhcp 2 static ip
};

struct net_mode_set_res_type
{
    int flag; // 0 - success 1 - unauthorized 
    int mode;
};

struct net_mode_get_type
{
    int priority;
};

struct net_mode_get_res_type
{
    int flag; //0 success, 1 priority err
    int mode; //1 dhcp 2 static ip
};

struct net_param_set_type
{
    int priority;
    char ip[32];
    char gw[32];
    char netmask[32];
    char dns[32];
};

struct net_param_set_res_type
{
    int flag; // 0 success 1 priority err 2 other error
    char ip[32];
    char gw[32];
    char netmask[32];
    char dns[32];
};

struct net_param_get_type
{
    int priority;
    char ip[32];
    char gw[32];
    char netmask[32];
    char dns[32];
};

struct net_param_get_res_type
{
    int flag; // 0 success 1 priority err
    char ip[32];
    char gw[32];
    char netmask[32];
    char dns[32];
};

struct wlan_scan_type
{
    int priority;
};

struct wifi_sap_type
{
    char ssid[32];
    int signal;
};

#define MAX_SAP_NUM 30

struct wlan_scan_res_type
{
    int flag; // 0 success 1 priority err 2 other err
    int cnt;
    struct wifi_sap_type wifi_ap_list[MAX_SAP_NUM];
};

struct wlan_connect_type
{
    int priority;
    char ssid[32];
    char pwd[16];
};

struct wlan_connect_res_type
{
    int flag;
    char ssid[32];
    char pwd[16];
    int connect_status;
};

struct  broadcast_info
{
    char deviceid[32];
    char version[32];
    int  netinterface; // 0 -- error,1 -- wired; 2 - wifi
    int  netmode; // 1 - dhcp; 2 - static ip
    char ipaddr[32];
    char gateway[32];
    char netmask[32];
    char dns[32];
    char status[32]; // more define need
    char event[32]; // more define need 
};

struct broadcast_set_info
{
    char deviceid[32];
    int  netmode; // 1 - dhcp; 2 - static ip
    char ipaddr[32];
    char gateway[32];
    char netmask[32];
    char dns[32];
};

struct video_req_stop_type
{
    int priority;
};

struct req_video_stop_res_type
{
    int flag;//0 success, 1: err
};

struct color_set_type
{
    int priority;		
    int brightness;	
    int hue;
    int contrast;	
};

struct color_get_type
{
    int flag;
    int brightness;
    int hue;
    int contrast;
};

struct image_set_type
{
    int priority;
    int v;	
    int h;
};

struct image_get_type
{
    int flag;
    int v;	
    int h;
};

struct nv_set_type
{
    int priority;
    int mode;	
};

struct nv_get_type
{
    int flag;
    int mode;
};

struct osd_set_type
{
    int priority;
    char buf[32]; 
};

struct osd_get_type
{
    int flag;
    char buf[32]; 	
};

struct nv_switch_set_type
{
    int priority;
    int mode;			//1: open;2: close.
};

struct nv_switch_get_type
{
    int flag;
    int mode;
};



//old protocal video head
#define FRAME_TYPE_I                 0x0
#define FRAME_TYPE_P                  0x1
#define FRAME_TYPE_NEW_I              (0x80) //add by fan 切码流时,第一个I帧
typedef struct tagvideoframeheader
{
    int frame_type;
    int pts[2]; //pts 精度为微秒
    int pack_num;
    int frame_len;
    int fts; /* hhmmss */
}video_frame_header;

struct video_req_type
{
    int priority;
    int req_type;
};

struct video_res_type
{
    int flag; //0 success 1:priority err
};

struct audio_listen_req_type
{
    int priority;
};

struct audio_listen_res_type
{
    int flag; //0 success 1:priority err
};
struct audio_listen_stop_req_type
{
    int priority;
};

struct audio_listen_stop_res_type
{
    int flag;//0 success, 1: err
};
struct audio_talk_req_type
{
    int priority;
};

struct audio_talk_res_type
{
    int flag; //0 success 1:priority err
};
struct audio_talk_stop_req_type
{
    int priority;
};

struct audio_talk_stop_res_type
{
    int flag;//0 success, 1: err
};


struct mcu_alarm_report_type
{
	unsigned char Zone;
	unsigned char Area;
	unsigned char  Event;
	unsigned char CID_Code[4];
};

struct clear_wls_type 
{
    int priority;
};

struct clear_wls_res_type
{
    int flag; //0 sucess 1 err
};

enum wls_type
{
    WLS_TYPE_REMOTE = 1,
    WLS_TYPE_SENSOR,
    WLS_TYPE_SWITCH,
    WLS_TYPE_BUTT,
};
struct get_wls_info_type
{
    int priority;
    int wls_type; // 1 - remote control,2 - sensor, 3 - electric switch
};

struct wls_item_info
{
    unsigned char valid; /* 1 - valid, 0 - unused */
    unsigned char id[3];
    unsigned char enable;/* 1 - enable, 0 - disabled */
    unsigned char attr; /* ZoneType for sensor,on-off-Status for eswitch */
    char	  name[32];
};
/** The DataStructure Size should < 1500B */
struct get_wls_info_res_type
{
    int flag;
    int type;// 1 - remote control,2 - sensor, 3 - electric switch
    struct wls_item_info item[32];
};

struct 	sensor_add_type
{
    int priority;
    char ID[16];
    char name[32];
    int alarm_mode; // ALARM_EVENT defined in McuCommunicationCmd.h
    int enable;//0 disable 1 enable
};

struct sensor_add_res_type
{
    int flag;
    char ID[16];
    char name[32];
};

struct 	remote_control_add_type
{
    int priority;
    char ID[16];
    char name[32];
};

struct remote_control_res_type
{
    int flag;
    char ID[16];
    char name[32];
};

struct 	remote_control_del_type
{
    int priority;
    char ID[16];
    char name[32];
};

struct remote_control_del_res_type
{
    int flag;
    char ID[16];
    char name[32];
};

struct 	switch_add_type
{
    int priority;
    char ID[16];
    char name[32];
};


struct switch_res_type
{
    int flag;
    char ID[16];
    char name[32];
};

struct 	switch_del_type
{
    int priority;
    char ID[16];
    char name[32];
};

struct switch_del_res_type
{
    int flag;
    char ID[16];
    char name[32];
};


struct 	sensor_del_type
{
    int priority;
    char ID[16];
    char name[32];
};

struct sensor_del_res_type
{
    int flag;
    char ID[16];
    char name[32];
};

struct alarm_zone_set_type
{
    int priority;
    char ID[16];
    char name[32];
    int alarm_mode; // ALARM_EVENT defined in McuCommunicationCmd.h
    int enable;//0 disable 1 enable
};

struct alarm_zone_set_res_type
{
    int flag; 
};

struct sensor_auto_add_type
{
    int priority;
};

struct sensor_auto_add_res_type
{
    int flag;
    int ID[16];
};

struct 	get_switch_status_type
{
    int priority;
    char ID[16];
};

struct 	get_switch_status_res_type
{
    int flag;
    char ID[16];
    char name[32];
    int status;
};


struct 	set_switch_status_type
{
    int priority;
    char ID[16];
    char name[32];
    int status;
};
struct set_enable_alarm_type 
{
    int priority;
};
struct res_enable_alarm_type 
{
    int flag; // 0 - success 1 - unauthorized 
};
struct set_home_alarm_type 
{
    int priority;
};
struct res_home_alarm_type 
{
    int flag; // 0 - success 1 - unauthorized 
};
struct set_disable_alarm_type 
{
    int priority;
};
struct res_disable_alarm_type 
{
    int flag; // 0 - success 1 - unauthorized 
};

//send / recv cbz item
struct item_pkg_type
{
    int usr_index;
    int len;
    char data[1500]; /* wifi scan result */
};

struct meian_pkg_head_type
{
    unsigned short head;
    unsigned short len;
    unsigned short cmd;
    unsigned short reslv;
};

struct record_set_param_type
{
    int priority;
    int on;//1:on 2 off
    int audio_on; // 1 on, 2 off
    int timelen; // seconds
};

struct record_set_param_res
{
    int flag;
};

struct record_get_param_type
{
    int priority;
};

struct record_get_param_res
{
    int flag;
    int on;//1:on 2 off
    int audio_on; // 1 on, 2 off
    int timelen; // seconds
};

struct sd_list_query_type
{
    int priority;
    char path[64]; // 目录名,查看根目录填空
};

struct item_info
{
    int type; // 类型:1 目录, 2 文件
    char fname[64];
    unsigned int fsize;
};
struct sd_list_query_res
{
    int cnt; // if cnt = 16, indicates has next slice,if < 16 indicates list end.
    struct item_info item[16]; /* send cbz unit size: 1500bytes */
};

struct sd_playback_req_type
{
    int priority;
    char fname[128]; // 文件名,相对于sd卡根目录的路径文件名
};

struct sd_playback_res_type
{
    int flag;
};

struct sd_stop_playback_type
{
    int priority;
};
struct sd_stop_playback_res
{
    int flag;
};
struct sd_pause_playback_type
{
    int priority;
};
struct sd_pause_playback_res
{
    int flag;
};
struct sd_end_playback_msg
{
    int flag;
};
struct record_status_query_type
{
    int priority;
};
struct record_status_query_res
{
    int flag;//0 success; 1 权限不够 2 其他
    int record_status; // 1 录像中 0 未录像
    int sd_status; // 1 不存在 2 只读 3 正常
    int sd_total_space; // 总容量，MB
    int sd_free_space;// 剩余容量, MB
};

enum log_type
{
    LOG_TYPE_MAIN = 0,
    LOG_TYPE_UPDATE,
    LOG_TYPE_REBOOT,
    LOG_TYPE_MAX,
};
struct log_get_req_type
{
    int priority;
    int type; // 0 - 主程序，1 - 升级程序, 2 - 重启日志
};
struct log_get_res_type
{
    int flag;
    int type;
    unsigned int size;
    unsigned int cur_packnum; // 0-total_packnum - 1
    unsigned int total_packnum;
};

struct restore_factory_req 
{
    int priority;
};
struct restore_factory_res 
{
    int flag;
};

struct replay_dateline_req
{
    int priority;
};
#define REPLAY_SECTION_MAX 150
struct replay_date
{
    unsigned short year;
    unsigned char month;
    unsigned char day;
};
struct replay_time
{
    unsigned short hour;
    unsigned char min;
    unsigned char sec;
};
struct replay_dateline
{
    int num;
    struct replay_date section[REPLAY_SECTION_MAX];
};
struct replay_dateline_res
{
    int flag;
    struct replay_dateline dateline;
};
struct replay_daytline_req
{
    int priority;
    struct replay_date date;
};
struct replay_timeline
{
    int num;
    struct replay_date date;
    struct
    {
	struct replay_time tstart;
	struct replay_time tend;
    }section[REPLAY_SECTION_MAX];
};
struct replay_daytline_res
{
    int flag;
    struct replay_timeline timeline;
};
struct replay_start_req
{
    int priority;
    struct replay_date date;
    struct replay_time tstart;
    unsigned int tlen; /* 0 for manual stop replay */
};
struct replay_start_res
{
    int flag;
};
struct replay_forward_req
{
    int priority;
    int rate; /* 0 - 10, 3 - normal, the smaller the faster */
};
struct replay_forward_res
{
    int flag;
};
struct replay_backward_req
{
    int priority;
    int rate; /* 0 - 10, 3 - normal, the smaller the faster */
};
struct replay_backward_res
{
    int flag;
};
struct client_did_list_type
{
        char did[16][32];
};
#define ITEM_PKG_VALID_SIZE(item) ((item).len+8)
#define MA_PKG_HEAD_SIZE sizeof(struct meian_pkg_head_type)


int process_req_pkg(int usr_index, unsigned short cmd, void *req_data, int data_size);

#endif

