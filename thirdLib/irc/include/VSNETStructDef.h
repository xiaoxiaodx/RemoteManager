// VSNETStructDef.h
#ifndef __VSNET_STRUCTDEF_H__
#define __VSNET_STRUCTDEF_H__

enum
{
    VSNETALARMMSG_SERSTART = 1,                // Server Start
    VSNETALARMMSG_MOTION,                      // Moving Detection Alarm
    VSNETALARMMSG_VIDEOLOST,                   // Video Lost Alarm
    VSNETALARMMSG_SENSOR,                      // Sensor Alarm
    VSNETALARMMSG_DISKFULL,                    // Disk Full Alarm
    VSNETALARMMSG_HIDEALARM,                   // Video Hide Alarm
    VSNETALARMMSG_SERSTOP,                     // Server Stop
    VSNETALARMMSG_DISKERROR,                   // Disk Error Alarm(smart)
    VSNETALARMMSG_ACCESSVIOLATION,             // violative access
    VSNETALARMMSG_ANALYSESINGLELINEALARM = 11, // Intellective Analyses and single-line Alarm
    VSNETALARMMSG_ANALYSEDOUBLELINEALARM,      // Intellective Analyses and double-line Alarm
    VSNETALARMMSG_ANALYSEREGIONENTRYALARM,     // Alarm for entering Intellective Analyses Region
    VSNETALARMMSG_ANALYSEREGIONEXITALARM,      // Alarm for Leaving Intellective Analyses Region
    VSNETALARMMSG_ANALYSEHOVERALARM,           // Alarm for hovering Intellective Analyses Region
    VSNETALARMMSG_NETANOMALYALARM,             // Network Anomaly Alarm
    VSNETALARMMSG_NVR_PUSENSOR,                // NVR pu Sensor Alarm
	VSNETALARMMSG_DISKLOST,                    // Disk Lost Alarm
	VSNETALARMMSG_ALARM_IN_SHUT = 34,          // Sensor Alarm stop
    VSNETALARMMSG_SGLINEALARM = 100,           // Alarm for Intellective Analyses caution line(>=100 and <=109��Now There are 10 rules for caution line
    VSNETALARMMSG_NODISK = 110,                // No Disk
    VSNETALARMMSG_NET_BROKEN,                  // network line broken
    VSNETALARMMSG_DISKUNHEALTH,                // Disk is unhealth, please change disk timely.
    VSNETALARMMSG_PLATECHECK,                  // Alarm for plate check
    VSNETALARMMSG_FR_NETOFF,                   // Alarm for front device network off
	VSNETALARMMSG_FR_IPUPDATE,                 // Alarm for front device ip address update
    VSNETALARMMSG_IPUPDATE,                    // Alarm for device ip address update
    VSNETALARMMSG_GLOBAL_TEMP,                 // Alarm for global temperature limit
    VSNETALARMMSG_REGION_TEMP,                 // Alarm for region temperature limit
    VSNETALARMMSG_ALARM_IN,                    // Alarm in
    
	//����汾������120��ʼ�������ۼ�
    VSNETALARMMSG_IPCONFLICT = 120,            // IP conflict
	
	//DX����������200��ʼ�����ۼ�
    VSNETALARMMSG_USBSTATE = 200,              // DX USB status 0:plugin 1:plugout
    VSNETALARMMSG_AUDIOCH = 201,               // DX auidoch
    VSNETALARMMSG_DXSWITCHCH = 202,            // DX Swtch Channel
    VSNETALARMMSG_DVDSTATE = 203,              // DX DVD status 0:plugin 1:plugout
    VSNETALARMMSG_DISPDVDINFO = 204,           // DX Notify to display DVD information: 0-no display; 1-get and display 
    
	//����������300�Ժ�ʼ���Դ��ۼӣ���Χ��int 65535��
	VSNETALARMMSG_HM_INFRARED = 301,           // ������䱨��
    VSNETALARMMSG_HM_DEMOLITION = 302,         // ���𱨾�

    //VSNETALARMMSG_SD_SPACE_FULL = 400,         ///<SD���ռ���

    //���ⱨ��������400�Ժ�ʼ���Դ��ۼӣ���Χ��int 65535��
    VSNETALARMMSG_IR_HIGH_TEMPERATURE_ALARM = 401,              // ������±���
    VSNETALARMMSG_IR_LOW_TEMPERATURE_ALARM = 402,               // ������±���
    VSNETALARMMSG_FIRE,                        // Alarm for fire temperature limit
    VSNETALARMMSG_TEMPDIFF,                    // Alarm for temperature compare
    VSNETALARMMSG_SMART_ANALYSIS,              // Alarm for smart analysis
};

enum ENUM_VSNET_VIDEO_RESOLUTION
{
    VSNET_VIDEO_RESOLUTION_QCIF = 0,
    VSNET_VIDEO_RESOLUTION_CIF,
    VSNET_VIDEO_RESOLUTION_2CIF,
    VSNET_VIDEO_RESOLUTION_4CIF,
    VSNET_VIDEO_RESOLUTION_DCIF,
    VSNET_VIDEO_RESOLUTION_QVGA,               // 320*240
    VSNET_VIDEO_RESOLUTION_VGA_60HZ,           // 640*480
    VSNET_VIDEO_RESOLUTION_SVGA_60HZ,          // 800*600
    VSNET_VIDEO_RESOLUTION_XGA_60HZ,           // 1024*768
    VSNET_VIDEO_RESOLUTION_SXGA_60HZ,          // 1280*1024
    VSNET_VIDEO_RESOLUTION_UXGA_60HZ,          // 1600*1200
    VSNET_VIDEO_RESOLUTION_720P,               // 1280*720, no use
    VSNET_VIDEO_RESOLUTION_HDTV,               // 1920*1080, no use
    VSNET_VIDEO_RESOLUTION_SVGA_75HZ,          // 800*600
    VSNET_VIDEO_RESOLUTION_XGA_75HZ,           // 1024*768
    VSNET_VIDEO_RESOLUTION_720P_50HZ,          // 1280*720, 50HZ
    VSNET_VIDEO_RESOLUTION_720P_60HZ,          // 1280*720, 60HZ
    VSNET_VIDEO_RESOLUTION_1080P_50HZ,         // 1920*1080, 50HZ
    VSNET_VIDEO_RESOLUTION_1080P_60HZ,         // 1920*1080, 60HZ
    VSNET_VIDEO_RESOLUTION_LTF,                // 240*192
    VSNET_VIDEO_RESOLUTION_WQVGA1,             // 480*352
    VSNET_VIDEO_RESOLUTION_WQVGA2,             // 480*272
    VSNET_VIDEO_RESOLUTION_UVGA_50HZ,          // 1280*960,50HZ
    VSNET_VIDEO_RESOLUTION_UVGA_60HZ,          // 1280*960,60Hz
    VSNET_VIDEO_RESOLUTION_1080P_30HZ,         // 1920*1080, 30HZ
    VSNET_VIDEO_RESOLUTION_1080I_50HZ,         // 1920*1080, 50HZ
    VSNET_VIDEO_RESOLUTION_1080I_60HZ,         // 1920*1080, 60HZ
    VSNET_VIDEO_RESOLUTION_SXGA_75HZ,          // 1280*1024, 75HZ
    VSNET_VIDEO_RESOLUTION_WXGA_60HZ,          // 1280*800, 60HZ
    VSNET_VIDEO_RESOLUTION_WXGA_75HZ,          // 1280*800, 75HZ
    VSNET_VIDEO_RESOLUTION_SXGAP_60HZ,         // 1400*1050, 60HZ SXGA+
    VSNET_VIDEO_RESOLUTION_SXGAP_75HZ,         // 1400*1050, 75HZ SXGA+
    VSNET_VIDEO_RESOLUTION_WXGAP_60HZ,         // 1440*900,  60HZ WXGA+
    VSNET_VIDEO_RESOLUTION_WSXGAP_60HZ,        // 1680*1050, 60HZ WSXGA+
    VSNET_VIDEO_RESOLUTION_WSUVGAP_60HZ,       // 1920*1080, 60HZ WSUVGA+
    VSNET_VIDEO_RESOLUTION_1366X768_60HZ,      // 1366*768, 60HZ
    VSNET_VIDEO_RESOLUTION_WXGA_59HZ,          // 1280*800, 60HZ,�Ǳ�
    VSNET_VIDEO_RESOLUTION_1280X720_59HZ,      // 1280*720, 60HZ �Ǳ�
    VSNET_VIDEO_RESOLUTION_1360X768_60HZ,      // 1360*768, 60HZ
};

// record type
enum
{
    HDISK_RECTYPE_HAND              = (1 << 0),
    HDISK_RECTYPE_TIMER             = (1 << 1),
    HDISK_RECTYPE_MOTION            = (1 << 2),
    HDISK_RECTYPE_ALARM             = (1 << 3),
    HDISK_RECTYPE_VILOST            = (1 << 4),
    HDISK_RECTYPE_VIHIDE            = (1 << 5),
    HDISK_RECTYPE_OTHER             = (1 << 6),
    HDISK_RECTYPE_BACKUP            = (1 << 7),
    HDISK_RECTYPE_NETANOMALY        = (1 << 8),
    HDISK_RECTYPE_PLATE             = (1 << 9),  // ����ʶ�𴥷���ץ��ͼƬ
    HDISK_RECTYPE_TEMP              = (1 << 10), //ȫ�ֲ��º�������±���
    HDISK_RECTYPE_SMART_ANALYSIS    = (1 << 11), //���ܷ�������
    HDISK_RECTYPE_MASK              = 0xff       //¼�����룬��ʾ��������
};

//FTP����״̬
typedef enum
{
    VS_FTP_LINK_OFF = 0,       //���ӹر�
    VS_FTP_LINK_SUCCESS,       //���ӳɹ�
    VS_FTP_LINK_FAIL,          //����ʧ��
} VS_FTP_LINK_STATE;        



/*ptz conctrl code*/
enum{
    PTZ_LEFT         =  0,
    PTZ_RIGHT        =  1,
    PTZ_UP           =  2,
    PTZ_DOWN         =  3,
    PTZ_IRISADD      =  4,
    PTZ_IRISDEC      =  5,
    PTZ_FOCUSADD     =  6,
    PTZ_FOCUSDEC     =  7,
    PTZ_ZOOMADD      =  8,
    PTZ_ZOOMDEC      =  9,
    PTZ_GOTOPOINT    =  10,
    PTZ_SETPOINT     =  11,
    PTZ_AUTO         =  12,
    PTZ_STOP         =  13,
    PTZ_LEFTSTOP     =  14,
    PTZ_RIGHTSTOP    =  15,
    PTZ_UPSTOP       =  16,
    PTZ_DOWNSTOP     =  17,
    PTZ_IRISADDSTOP  =  18,
    PTZ_IRISDECSTOP  =  19,
    PTZ_FOCUSADDSTOP =  20,
    PTZ_FOCUSDECSTOP =  21,
    PTZ_ZOOMADDSTOP  =  22,
    PTZ_ZOOMDECSTOP  =  23,
    PTZ_LIGHT        =  24,
    PTZ_LIGHTSTOP    =  25,
    PTZ_RAIN         =  26,
    PTZ_RAINSTOP     =  27,
    PTZ_TRACK        =  28,
    PTZ_TRACKSTOP    =  29,
    PTZ_DEVOPEN      =  30,
    PTZ_DECCLOSE     =  31,
    PTZ_AUTOSTOP     =  32,
    PTZ_CLEARPOINT   =  33,
    PTZ_LEFTUP       =  200,
    PTZ_LEFTUPSTOP   =  201,
    PTZ_RIGHTUP      =  202,
    PTZ_RIGHTUPSTOP  =  203,
    PTZ_LEFTDOWN     =  204,
    PTZ_LEFTDOWNSTOP =  205,
    PTZ_RIGHTDOWN    =  206,
    PTZ_RIGHTDOWNSTOP=  207,
	PTZ_LOOP_START     =  208,     // ��ʼԤ�õ���Ѳ   �����豸֧��  value ��Ѳ��� priority ��ѯʱ�䣨0��5-1800��
	PTZ_LOOP_STOP      =  209,     // ֹͣԤ�õ���Ѳ   �����豸֧��  value ��Ѳ���
};

//��������  ��ȡ��ʽ��״ֵ̬
enum
{
	HDISK_UNFORMATTED = 0,
	HDISK_FORMATTING,
	HDISK_FORMATFINISH,
};

//Device type
#define DEVICE_DVS      0X01
#define DEVICE_DVR      0X02
#define DEVICE_IPC      0X03
#define DEVICE_NVR      0X04

// Transmit Customer's Rights
#define VSNET_USER_RIGHT_ADMIN      1   // Administrator Right
#define VSNET_USER_RIGHT_HIOPER     2   // High-grade Operator
#define VSNET_USER_RIGHT_OPERIAL    3   // Operator

#define VSNET_DVR_MAXCH             64  // Max number for channel
#define VSNET_DVR_MAXALARMOUT       16  // Max number for alarm output
#define VSNET_DVR_MAXTRACKNUM       16  // Max number for track
#define VSNET_DVR_MAXVONUM          8   // Max number for vo
#define VSNET_DVR_MAXSTM            4   // Max number for stream

#define VSNET_OSDTITLE_NUM          6   //Max number for OSDTITLE
#define VSNET_CAPTURE_OSDSTR_LENTH  60  //Max number for character

#define VSNET_NETCFG_IPV6LEN        48  //ipv6 config

/**********************************VSNET_DVR_GUI_PORT******************************************/
#define VSNET_DVR_GUI_PORT          10000   // DVR GUI�ڲ�ͨ�Ŷ˿�10000~10999��DVR GUIר��
// 10001:�����˿�
// 10002:��������
/************************************VSNET_DVR_GUI_PORT****************************************/

#ifndef TEMP_AREA_NUM
#define TEMP_AREA_NUM 1
#endif

/* ͨ���������� */
typedef struct
{
    unsigned int m_bandwidthRecv[VSNET_DVR_MAXCH][VSNET_DVR_MAXSTM];       //ͨ���������մ�����λBps
    unsigned int m_bandwidthRecvAv[VSNET_DVR_MAXCH][VSNET_DVR_MAXSTM];     //ͨ������ƽ�����մ�����λBps
}VSNET_STREAMINFO_S;

typedef struct
{
    char                m_username[20];     // Username
    char                m_password[20];     // Password
} ONEUSER;

typedef struct
{
    ONEUSER             m_admin;            // Administrator
    ONEUSER             hl_operator[10];    // High-grade Operator
    ONEUSER             m_operator[10];     // Operator
} WHOLE_USER;

typedef struct
{
    ONEUSER             m_adminsuper;
    ONEUSER             m_admin;            // Administrator
    ONEUSER             hl_operator[10];    // High-grade Operator
    ONEUSER             m_operator[10];     // Operator
} WHOLE_USERSUPER;

typedef struct
{
    int                 bUseDDNS;           // DDNS Enable
    char                DDNSSerIp[40];      // DDNS Server IP
    unsigned short      DDNSSerPort;        // DDNS Server Port
    unsigned short      LocalMapPort;       // Local Port
} WHOLE_DDNS;

typedef struct
{
    char                pStrWebRomVer[50];       // Web Page Version
    char                pStrWebRomBuildTime[50]; // Web Page Compile Time
} VERSIONWEBROM;

typedef struct
{
    char                pStrBSPVer[50];       // BSP Version
    char                pStrAPPVer[50];       // Application Version
    char                pStrBSPBuildTime[50]; // BSP Compile Time
    char                pStrAPPBuildTime[50]; // Application Compile Time
} VERSIONINFO;

// Flash�汾��Ϣ
typedef struct
{
    char                pStrFLASHVer[64];       // FLASH Version
    char                pStrFLASHBuildTime[64]; // FLASH Compile Time
} VSNET_FLASHVERSION;

typedef struct
{
    char                m_servername[24];   // Server Name
    char                m_serverip[16];     // IP Address
    char                m_servermask[16];   // Subnet Mask
    char                m_gatewayAddr[16];  // GateWay
    char                m_dnsaddr[16];      // DNS Address
    char                m_multiAddr[16];    // Multicasting Address
    unsigned short      m_serport;          // Data Port
    unsigned short      m_mulport;          // Multicasting Port
    unsigned short      m_webport;          // Web Page Port
    unsigned char       m_isPAL;            // Video Mood(1-PAL,0-NTSC)
    unsigned char       m_launage;          // Language
    unsigned char       m_phyAddr[6];       // Physical Address
    unsigned short      m_reserved;         // reserved
    unsigned char       m_serial[8];        // Serial Number
    WHOLE_DDNS          m_ddns;             // DDNS Parameter
    VERSIONINFO         m_version;          // Version
} WHOLEPARAM;

typedef struct
{
    char                m_servername[60];   // Server Name
    char                m_serverip[16];     // IP Address
    char                m_servermask[16];   // Subnet Mask
    char                m_gatewayAddr[16];  // GateWay
    char                m_dnsaddr[16];      // DNS Address
    char                m_multiAddr[16];    // Multicasting Address
    unsigned short      m_serport;          // Data Port
    unsigned short      m_mulport;          // Multicasting Port
    unsigned short      m_webport;          // Web Page Port
    unsigned char       m_isPAL;            // Video Mood(PAL,NTSC)
    unsigned char       m_launage;          // Language
    unsigned char       m_phyAddr[6];       // Physical Address
    unsigned short      m_reserved;         // Reserved
    unsigned char       m_serial[8];        // Serial Number
    WHOLE_DDNS          m_ddns;             // DDNS Parameter
    VERSIONINFO         m_version;          // Version
} WHOLEPARAMEX;

typedef struct
{
    unsigned char       m_starthour;        // Start Hour
    unsigned char       m_startmin;         // Start Minute
    unsigned char       m_stophour;         // Stop Hour
    unsigned char       m_stopmin;          // Stop Hour
    unsigned char       m_maskweek;         // Week
    unsigned char       bReceive[3];        // Reserved
} TIMECHECK;

typedef struct
{
    TIMECHECK           pList[7];           // Time Table
} TIMELIST;

typedef struct
{
    unsigned char       m_beanb;             // Moving Detection Enable
    unsigned char       m_alarmsenstive;     // sensitivity of Moving Detection
    unsigned char       m_brecord;           // relate to recording
    unsigned char       bReceive;            // Reserved
    unsigned char       m_outputmap[8];      // relate to output
    unsigned char       m_detect[18][22];    // Detection Range
    TIMELIST            m_timelist;          // Detection Time Table
} CHANNMOTION;

typedef struct
{
    unsigned char       m_beanb;             // Moving Detection Enable
    unsigned char       m_alarmsenstive;     // sensitivity of Moving Detection
    unsigned char       m_brecord;           // relate to recording
    unsigned char       m_capjpeg;           // relate to jpeg capture image
    unsigned char       m_singlehost;        // Center for uploading
    unsigned char       m_reseved1;          // Reserved
    unsigned char       m_reseved2;          // Reserved
    unsigned char       m_reseved3;          // Reserved
    unsigned char       m_outputmap[8];      // relate to output
    unsigned char       m_detect[18][22];    // Detection Range
    TIMELIST            m_timelist;          // Detection Time Table
} CHANNMOTIONEX, CHANNVAEX;

typedef struct
{
    int                 nFormat;            // Format of Display
    unsigned short      x, y;               // Coordinate of Display
} TIMEOSD;

typedef struct
{
    int                 bShow;              // Show(1),Hide(0)
    unsigned short      x, y;               // Coordinate of Display
} BITSINFOOSD;

typedef struct
{
    char                lpString[32];       // characters to be showed
    unsigned short      x, y;               // Coordinate
} TITALOSD;


typedef struct
{
    TIMEOSD             m_time;             // Time
    TITALOSD            m_tital[4];         // Title
    BITSINFOOSD         m_bits;             // Bit Rate
#if defined(PLATFORM_TXSL)
    char                m_channelName[32];
#endif
} CHANNOSD;


typedef struct
{
    TIMEOSD             m_time;                         // Time
    TITALOSD            m_tital[VSNET_OSDTITLE_NUM];    // Title
    BITSINFOOSD         m_bits;                         // Bit Rate
} CHANNOSD_EXT;

typedef struct
{
    char                lpString[44];       // characters to be showed
    unsigned short      x, y;               // Coordinate
} TITALOSD_HT;

typedef struct
{
    TIMEOSD             m_time;             // Time
    TITALOSD_HT            m_tital[4];         // Title
    BITSINFOOSD         m_bits;             // Bit Rate
} CHANNOSD_HT;

typedef struct
{
    int             m_enable;                   // label of channel OSD superposition for Intellective analyses alarm   0-Disable 1-Enable
    unsigned short  m_x, m_y;                   // Coordinate
    char            m_tripwire_osdText[32];     // literal contents  of OSD superposition for alarm of caution line
    char            m_regionEnter_osdText[32];  // literal contents  of OSD superposition for alarm of entering region
    char            m_regionLeave_osdText[32];  // literal contents  of OSD superposition for alarm of leaving region
    char            m_regionWander_osdText[32]; // literal contents  of OSD superposition for alarm of hovering region
} VSNETCHVAALARMOSD;

#ifndef MAX_OSDSTRLEN
#define MAX_OSDSTRLEN 200
#endif 

typedef struct
{
    unsigned short    m_nStrLen;                     // �豸֧�ֵ�����ַ����� ֻ�ܻ�ȡ
    unsigned short    m_bShow;                       // show(1),hide(0)    
    char              m_szString[MAX_OSDSTRLEN];     // characters to be showed
    unsigned short    m_nX, m_nY;                    // coordinate
} VSNET_TITALOSD;

//osd������չ ���豸��ȡ֧�ֵ�����ַ���
typedef struct
{
    TIMEOSD           m_time;            // time
    VSNET_TITALOSD    m_tital[4];        // title
    BITSINFOOSD       m_bits;            // bit rate
} VSNET_CHANNOSD;

typedef struct
{
    unsigned char          m_alpha;
    unsigned char          m_red;           //��ɫ  
    unsigned char          m_green;         //��ɫ
    unsigned char          m_blue;          //��ɫ
    unsigned short         m_rgb;
    unsigned char          reserve[2];      //����Ϊ
} VSNET_RGB_COLOR;

typedef struct
{
    VSNET_RGB_COLOR     m_fgcolor;          //������ɫ
    VSNET_RGB_COLOR     m_bgcolor;          //δʹ��
} VSNET_OSDCOLOR;       

typedef struct
{
    int                m_enable;            // label of Intellective analyses alarm  OSD superposition   0-Disable 1-Enable
    VSNETCHVAALARMOSD  m_chAlarmOsd[8];     // setting of OSD superposition for channel Intellective analyses alarm
} VSNETVAALARMOSD;

typedef struct
{
    int                 m_bmask;            // Image Mask Enable
    unsigned short      m_x;                // x
    unsigned short      m_y;                // y
    unsigned short      m_width;            // width
    unsigned short      m_height;           // height
} CHANNVIDEOMASK;

typedef struct
{
    unsigned char       m_bri;              // Image Brightness
    unsigned char       m_con;              // Image Contrast
    unsigned char       m_sat;              // Image Saturation
    unsigned char       m_hue;              // Image Hue
} CHANNVIPARAM;

typedef struct
{
    char                m_channelName[16];  // Channel Name
    int                 m_streamType;       // Stream Type:Video Stream��AV Stream
    int                 m_encodeType;       // Image Type:CIF,2CIF,4CIF
    int                 m_Iinterval;        // key frame interval(10-200)
    int                 m_videoFrameRate;   // Frame rate
    int                 m_bitratetype;      // bit rate type��CBR & VBR
    int                 m_maxqueue;         // VBR Quantified Coefficient(2-31)
    int                 m_minqueue;         // CBR Quantified Coefficient(2-31)
    int                 m_maxbitrates;      // CBR Max bit rate(64K-8000K)
    int                 m_audiosample;      // AF sampling frequency
    int                 m_audiobitrate;     // AF bit rate
    int                 m_delay;            // Alarm Delay
    int                 m_benrecord;        // Regular Recording Enable
    TIMELIST            m_record;           // Regular Recording Time Table
} CHANNELPARAM;

typedef struct
{
    char                m_channelName[60];  // Channel Name
    int                 m_streamType;       // Stream Type:Video Stream��AV Stream
    int                 m_encodeType;       // Image TypeCIF,2CIF,4CIF
    int                 m_Iinterval;        // key frame interval(10-200)
    int                 m_videoFrameRate;   // Frame rate
    int                 m_bitratetype;      // bit rate type��CBR & VBR
    int                 m_maxqueue;         // VBR Quantified Coefficient(2-31)
    int                 m_minqueue;         // CBR Quantified Coefficient(2-31)
    int                 m_maxbitrates;      // CBR Max bit rate(64K-8000K)
    int                 m_audiosample;      // AF sampling frequency
    int                 m_audiobitrate;     // AF bit rate
    int                 m_delay;            // Alarm Delay
    int                 m_benrecord;        // Regular Recording Enable
    TIMELIST            m_record;           // Regular Recording Time Table
} CHANNELPARAMEXNAME;

typedef struct
{
    char                m_channelName[16];  // Channel Name
    int                 m_streamType;       // Stream Type:Video Stream��AV Stream
    int                 m_encodeType;       // Image TypeCIF,2CIF,4CIF
    int                 m_Iinterval;        // key frame interval(10-200)
    int                 m_videoFrameRate;   // Frame rate
    int                 m_bitratetype;      // bit rate type��CBR & VBR
    int                 m_maxqueue;         // CBR Quantified Coefficient(2-31)
    int                 m_minqueue;         // VBR Quantified Coefficient(2-31)
    int                 m_maxbitrates;      // CBR Max bit rate(64K-8000K)
    int                 m_audiosample;      // AF sampling frequency
    int                 m_audiobitrate;     // AF bit rate
    int                 m_delay;            // Alarm Delay
    int                 m_nPrerecordTime;   // Prerecording Time(0=off,1-10=ON)
    int                 m_videofilebackup;  // Video File Backup(0=OFF,1=ONLY Alarm File,2=All Files)
    int                 m_jpegfilebackup;   // Jpeg File Backup(0=OFF,1=ONLY Alarm File,2=All Files)
    int                 m_benrecord;        // Regular Recording Enable
    TIMELIST            m_record;           // Regular Recording Time Table
} CHANNELPARAMEX;
//m_channelName��    ͨ�����ƣ�
//m_streamType��     ����ʽ��0����������1����Ƶ����
//m_encodeType��     ����ֱ��ʣ�0:QCIF,1:CIF,2:2CIF,3:D1,5:QVGA(320*240),6:VGA(640*480),7:SVGA@60HZ(800*600),8:XGA@60HZ(1024*768),9:SXGA@60HZ(1280*1024),10:UXGA@60HZ(1600*1200),11:720P(1280*720),12:HDTV(1920*1080),13:SVGA@75HZ(800*600),14:XGA@75HZ(1024*768),15:720P@50HZ(1280*720),16:720P@60HZ(1280*720)
//m_Iinterval��      I֡�����ȡֵ��Χ��10-200��
//m_videoFrameRate�� ��Ƶ֡�ʣ�PALȡֵ��Χ��1-25��NTSCȡֵ��Χ��1-30��
//m_bitratetype��    �������ͣ�0�������ʣ�1�������ʣ�
//m_maxqueue��       �������ϵ����ȡֵ��Χ��8-31��ȡֵԽ��ͼ������Խ����ֵ�ڶ�����ʱ��Ч��������ͼ��������������ֵ����31������������������Զ���֡�������31�����������ᶪ֡��
//m_minqueue:       �������ʱ������ϵ�������ֵ�ڶ�����ʱ�ķ�ΧΪ2-31��������ʱ4-31(4CIFʱ��5-31)�����ֵԽС����Խ�ã�
//m_maxbitrates��    ������ʱ��������ʣ�ȡֵ��Χ��32-4000������Ӧ32K-4M��
//m_audiosample��    ��Ƶ����Ƶ�ʣ�ȡֵΪ8000,16000,32000��
//m_audiobitrate��   ��Ƶѹ�����ʣ�ȡֵΪ8��16��24��32��48��64��������Ƶ��Ϊ32Kʱ���ʱ��벻С��32��
//m_delay��          �����ӳ�ʱ�䣬ȡֵ��Χ��5-600�룻
//m_benrecord��      ��ʱ¼���־��TRUE��������ʱ¼��FALSE��ȡ����ʱ¼��
//m_record��         ��ʱ¼��ƻ���

/*********************************************************************
                        ������ƵԤ��������
 ����ģʽ       ����>=D1��h264����              5  0  2  128  2
 ���ն�ģʽ     ����>=D1���ն��µ�h264����      5 -4  3  255  4
 ��ǿģʽ       ����<D1��h264���룬���ɸ���     7  5  2  128  2
 �ֶ�ģʽ       ����>=D1��h264����
 *********************************************************************/
typedef struct
{
    int      m_nVppmode;     /* VPPģʽ 0-�ر� 1-���� 2-���ն� 3-��ǿ 4-�ֶ� */
    int      m_nIeSth;       /* IE Strength [0,10] */
    int      m_nSpSth;       /* SP Strength [-4,5] */
    int      m_nDnSfCosSth;  /* coarse DN sf Strength [0,3] */
    int      m_nDnSfIncSth;  /* Inching of DN sf Strength [0,255] */
    int      m_nDnTfSth;     /* DN tf Strength [0,4] */
} VSNET_ENC_VPP;

typedef struct
{
    int                 m_baudrate;         // baud rate
    int                 decoderModel;       // Protocol Type(Not Use)
    unsigned char       m_databit;          // Data bit
    unsigned char       m_stopbit;          // Stop bit
    unsigned char       m_checkbit;         // Check bit
    unsigned char       m_flowcontrol;      // Flow Control
    unsigned char       decoderAddress;     // Decoder Address
    unsigned char       bReceive[3];        // Reserved
} SERIAL485_PARAM;

typedef struct
{
    int                 baudrate;           // baud rate
    char                databit;            // data bit
    char                stopbit;            // stop bit
    char                checkbit;           // check bit
    char                flowcontrol;        // flow control
} VSSERIAL_INFO;

typedef struct
{
    int                 m_year;             // Year
    unsigned char       m_month;            // Month
    unsigned char       m_dayofmonth;       // Day
    unsigned char       m_dayofweek;        // Week
    unsigned char       m_hour;             // Hour
    unsigned char       m_minute;           // Minute
    unsigned char       m_second;           // Second
    unsigned char       bReceive[2];        // Reserved
} TIME_PARAM;

typedef struct
{
    int                 m_bias;             // Timezone in minutes
} TIMEZONE_PARAM;

typedef struct
{
    unsigned char       m_record[16];       // relate to recording
    unsigned char       m_out[8];           // relate to output
    unsigned char       m_enpreno[16];      // relate to preset point
    unsigned char       m_preno[16];        // number of preset point to be called
    TIMELIST            m_timelist;         // detection time table
} ALARMRECORD;

typedef struct
{
    int                 m_alarmmode;        // Alarm Mode 0��OFF,1��ON
    int                 m_singlehost;       // label of center for uploading alarm signal
    unsigned char       m_record[16];       // relate to recording
    unsigned char       m_out[8];           // relate to output
    unsigned char       m_enpreno[16];      // relate to preset point
    unsigned char       m_preno[16];        // number of preset point to be called
    unsigned char       m_capjpeg[16];      // relate to capturing
    TIMELIST            m_timelist;         // detection time table
} ALARMRECORDEX;

typedef struct
{
    int                 m_benab;            // Alarm Enable
    ALARMRECORD         m_alarmrec[8];      // parameter of relating to alarm
} ALARMPARAM;

typedef struct
{
    int                 m_benab;            // Alarm Enable
    ALARMRECORDEX       m_alarmrec[8];      // parameter of relating to alarm
} ALARMPARAMEX;

typedef struct
{
    int                 m_benab;            // ʹ��
    ALARMRECORDEX       m_alarmrec[9];      // 1 + 8(��ӱ������ϵ�8����������)
} ALARMPARAMEX_SEA;

typedef struct
{
    int                 m_chanuser[16];     // Channel
    unsigned char       m_chanIP[16][20][4];// Linked IP Address
} CONNECTIP;

typedef struct
{
    int                 m_chanuser[64];     // Channel
    unsigned char       m_chanIP[64][20][48];// Linked IP Address
} CONNECTIPEX;

typedef struct
{
    unsigned int        m_videotag;         // Video tag
    short               m_width, m_height;  // Video Size
    int                 m_bhaveaudio;       // have audio or not
    int                 m_samplesize;       // audio sampling frequency
    unsigned short      m_audiotag;         // audio tag
    unsigned short      m_audiobitrate;     // audio bit rate
} VSTREAMINFO;

typedef struct
{
    unsigned int        m_url;              // URL address
    char                m_sername[24];      // Server Address
    int                 m_ch;               // channel
    int                 trantype;           // transport type
#ifndef USE_HANDLE_32
    /*int*/void*        handle;             // handle
#else
    int                 handle;             // handle
#endif
    
} VSUSERINFO;

typedef struct
{
    int                 m_benable;          // hide detection enable
    int                 m_decval;           // sensitivity of detection(1(lowest)---3(highest))
    unsigned char       m_out[8];           // output of relating alarm
    TIMELIST            pTimeList;          // detection time
} CHANNELHIDEALARM;

typedef struct
{
    int                 m_benable;          // hide detection enable
    int                 m_bsinglehost;      // label of center for alarm signal
    int                 m_decval;           // sensitivity of detection(1(lowest)---3(highest))
    unsigned char       m_out[8];           // output of relating alarm
    TIMELIST            pTimeList;          // detection time
} CHANNELHIDEALARMEX;

typedef struct
{
    int                 m_benbale;          // Regular Restart Enable
    int                 m_invalidtime;      // interval time(HOUR AS UNIT��10h-240h:10 hours to 10 days)
    int                 m_rsthour;          // Restart Hour
    int                 m_rstminute;        // Restart Minute
} VSTIMERRESET;

typedef struct
{
    char                m_hostserverurl[40]; // IP of Recording Server
    char                m_alarservermurl[40];// IP of Alarm Server
    unsigned short      m_hostserverport;    // Port of Recording Server
    unsigned short      m_alarserverport;    // Port of Alarm Server
} VSREMOTEHOST;

typedef struct
{
    int                 m_streamType;       // Stream Type:Video Stream��AV Stream
    int                 m_encodeType;       // Image TypeCIF,2CIF,4CIF
    int                 m_Iinterval;        // Key Frame interval(10-200)
    int                 m_videoFrameRate;   // frame rate
    int                 m_bitratetype;      // bit rate type��CBR & VBR
    int                 m_maxqueue;         // VBR Quantified Coefficient(2-31)
    int                 m_minqueue;         // CBR Quantified Coefficient(2-31)
    int                 m_maxbitrates;      // CBR max bit rate(64K-8000K)
} VSSUBCHANPARAM;

typedef struct
{
    int                 m_hds;             // Total of Hard Disk
    int                 m_hdtype[8];       // Disk Type
    int                 m_hdstate[8];      // Disk State 0xff-����0xfe-��Ӳ��
    int                 m_totalsize[8];    // Disk Size
    int                 m_freesize[8];     // free size
} VSDISKSTATE;

typedef struct
{
    unsigned int        m_channel;         // Channel NO.
    unsigned short      m_detectall;       // all alarm
    unsigned char       m_detect[18][22];  // alarm block
} VSNETVIDEOMOVE_BLOCK;

typedef struct
{
    int                 m_busepppoe;        // USE PPPOE
    char                m_pppoename[64];    // PPPOE username
    char                m_pppoepswd[64];    // PPPOE password
} VSNETPPPOEPARAM;

typedef struct
{
    int      m_packet_type;                 // packet type of recording(0:packing with file size; 1:packing with time)
    int      m_packet_size;                 // packet size of recording��MB as UNIT
    int      m_packet_time;                 // packet time of recording��Minute as UNIT
    int      m_hdisk_reserved_size;         // Reserved Space of DISK��MB as UNIT
    int      m_hdisk_full_alarm;            // whether alarm when free space less than reserved space of hard disk
    int      m_hdisk_full_action;           // the action when free space less than reserved space of hard disk(1:circular covering; 0:stop recording)
} VSNETRECORDPARAM;

typedef struct
{
    int                 m_bsinglehost;      // label of center for uploading
    unsigned char       m_out[8];           // alarm output
    TIMELIST            m_timelist;         // detection time
} VSNETVIDEOLOSTPARAM;

typedef struct
{
    unsigned char       m_caprate;          // frame rate of capturing (1-5)
    unsigned char       m_encquant;         // quality of capturing(JPEG,1-100)
    unsigned char       m_encformat;        // format of capturing(CIF,2CIF,4CIF)
    unsigned char       m_reserved;         // reserved
    int                 m_capnums;          // frame number to be captured(-1:keep capturing)
} VSNETJPEGCAPPARAM;

/* �洢ģʽ����,tyto�ڲ�ʹ�� */
typedef struct
{
    int                 m_storagemode;      // LC_STORAGEMODE_E
    int                 m_stilloption;      // LC_STILLOPT_E
    int                 m_visibleoption;    // LC_VISIBLEOPT_E
    int                 m_iroption;         // LC_IROPT_E
    int                 m_spectrum;         // LC_SPECTRUM_E
    int                 m_viscomprate;      // LC_COMPRATE_E
    int                 m_ircomprate;       // LC_COMPRATE_E
    int                 m_visoption;        // LC_VISOPT_E
    int                 m_video_subtitle;   // 1ʹ��
} VSNETSTORAGEMODE; 

/* ��Ƶ���ģʽ���� */
typedef struct
{
    int                 m_hdmioutput_mode;  // LC_HDMIMODE_E
    int                 m_vis_zoom;         // 100,200,400
} VSNETVOUTMODE; 

typedef struct
{
    int                 m_stillperiod;      // 0~60s
    int                 m_stillishz;        // 0,1
    int                 m_videosnapshot;    // 0,1
    int                 m_imagenumbers;     // Number of images to capture total - -1 for unlimited capture
} VSNETSTILLPARAM; 

typedef struct
{
    unsigned int        m_id;               //0, 1
    unsigned int        m_color;            //COLOR_XX 
    unsigned int        m_on_msec;          //led on msec
    unsigned int        m_cycle_msec;       //led on and off cycle msec
} VSNETLEDCTRL; //the same as led_ctrl

typedef struct
{
    unsigned char       m_sd1_mount;        //0, 1
    unsigned char       m_sd2_mount;        //0, 1
    unsigned short      m_sd_alarm_state;   //0, 1
    unsigned int        m_sd1_space;        //unit: Mb
    unsigned int        m_sd2_space;        //unit: Mb
    unsigned int        m_sd1_total_space;  //unit: Mb
    unsigned int        m_sd2_total_space;  //unit: Mb
    unsigned char       m_sd1_state;        //
    unsigned char       m_sd2_state;        //
    unsigned short      m_reserve;          //0, 1
} VSNETMSDSTATUS;                          //sd��״̬��tyto�ڲ�ʹ��

typedef struct
{
    float               m_essivity;
    float               m_bkgtmp;//Ambient temperature
    float               m_atmktmp;//Atmosphere temperature
    float               m_wintmp;//win_temperature 
    float               m_wintrans;//win_transmission
    float               m_atmtrans;//atmosphere transmission
    float               m_humidity;//Relative humidity
    float               m_lenstrans;//Lens transmission
    float               m_lensfnum;//Lens F number
}VSNETRADPARAM;/*����������*/

typedef struct
{
    unsigned short      m_frequency;
    short               m_orientation;
    unsigned int        m_color;
    float               m_zoom;
}VSNETVIDEOPARAM;/*��Ƶ��ز���*/

typedef struct
{
    char                m_sn[20];
    char                m_pn[20];
    char                m_ver[20];
    char                m_devsn[20];
    char                m_devpn[20];
}VSNETCAMERAINFO;/*camera��Ϣ*/

typedef struct 
{
    float               m_startupTemp;   ///<�����¶ȣ���λ��
    float               m_fpaTemp;       ///<FPA�¶ȣ���λ��
    float               m_housingTemp;   ///<����¶ȣ���λ��
}VSNETDEVICEPARAM;/*tau�豸��Ϣ*/

/*************************M10 parameter start********************************/
typedef struct
{
    int                 m_osd_enable;       //ȫ��OSD����ʹ�ܿ��� 0:�ر� 1:����
    float               m_envtemp;          //�����¶ȣ���λ��
    float               m_detectdist;       //�����룬��λm
    float               m_radrate;          //������,��Χ[0,1]
    float               m_humidity;         //ʪ��,��Χ[0,100],��λ%
}VSNETTEMPPARAM;/*������ز���������OSD���ӣ��ɽӿڣ��������ϵ�m10����*/

typedef struct
{
    float               m_envtemp;          //�����¶ȣ���λ��
    float               m_detectdist;       //�����룬��λm
    float               m_radrate;          //������,��Χ[0,1]
    float               m_humidity;         //ʪ��,��Χ[0,100],��λ%
}VSNETTEMPPARAM_EX;/*������ز���*/

typedef struct
{
    float               m_emissivity;       ///<����������
    float               m_winTrans;         ///<���ڴ�����
    float               m_winTemp;          ///<�����¶ȣ���λ��
    float               m_winRefl;          ///<���ڷ�����
    float               m_reflTemp;         ///<���ڷ����¶ȣ���λ��
    float               m_atmTrans;         ///<����������
    float               m_atmTemp;          ///<�����¶ȣ���λ��
    float               m_bkgTemp;          ///<�����¶ȣ���λ��
}VSNETTEMPCALIBPARAM;/*������ز����������¶�У׼*/

typedef struct
{
    int                 m_enable;           //�ֶ�ʹ�ܿ���
    float               m_hightemp;         //�����ֵ
    float               m_lowtemp;          //�����ֵ
}VSNETAGCPARAM;/*AGC����*/

typedef struct
{
    float               m_maxtemp;          //�����ֵ
    float               m_mintemp;          //�����ֵ
    float               m_avgtemp;          //ƽ����ֵ
}VSNETTEMPVALUE;

typedef struct
{
    float               m_ir_avgtemp;       //����ƽ���¶�
    float               m_ir_hightemp;      //��������¶�
    float               m_ir_lowtemp;       //��������¶�
    float               m_ir_high;          //�¶�������¶�
    float               m_ir_low;           //�¶�������¶�
}VSNETTEMPDATA;/*��������*/

typedef struct
{   
    int                 min_x;              //����¶�x����
    int                 min_y;              //����¶�y����
    int                 max_x;              //����¶�x����
    int                 max_y;              //����¶�y����
}VSNETCOORDINFO;

typedef struct
{
    int                 m_enable;           //�ںϹ���ʹ�ܿ��� 0:�ر� 1:����
    int                 m_strength;         //�ں�ǿ��(��/��/��) 0:�� 1:�� 2:��
}VSNETIMAGEFUSEPARAM;

typedef struct
{
    int                 m_horiz_offset;     //ˮƽƫ��ֵ
    int                 m_vert_offset;      //��ֱƫ��ֵ
}VSNETIMAGEFUSEOFFSET;

typedef struct
{
    int                 m_osd_enable;       //ȫ��OSD����ʹ�ܿ��� 0:�ر� 1:����
}VSNETOSDPARAM;

typedef struct
{
    int                 m_ir_temp_enable;    //����ȫ�ֲ��µ���ʹ�� 0:�ر� 1:����
    int                 m_ir_param_enable;   //����ȫ�ֲ��²�������ʹ�� 0:�ر� 1:����
    int                 m_ir_strip_enable;   //����α��ɫ������ʹ�� 0:�ر� 1:����
    int                 m_ir_cursor_enable;  //����ߵ��¹�����ʹ�� 0:�ر� 1:����
}VSNETIROSDPARAM;

typedef struct
{
    int                 m_type;    //0:���ɼ��� 1:pip
}VSNETVIS_ENCSRC;   //ch0����Դѡ��

#define REGIONTEMPNUM 8

typedef struct
{
    int                 m_region_enable; // �������ʹ��
    int                 m_osd_enable;    // �������osd����ʹ��
    int                 m_cursor_enable; // ������¸ߵ��¹�����ʹ��
    int                 m_param_enable;  // �������ʹ�ñ��ز���
    unsigned short      m_x;             // x
    unsigned short      m_y;             // y
    unsigned short      m_width;         // width
    unsigned short      m_height;        // height
    float               m_detectdist;    //Ŀ����룬��λm
    float               m_radrate;       //������,��Χ[0,1]
}VSNETREGIONTEMPAREA;

typedef struct
{
    VSNETREGIONTEMPAREA m_region[REGIONTEMPNUM];   //������²���
}VSNETREGIONTEMPPARAM;

typedef struct
{
    char m_firmwaretag[32];   //�豸���
}VSNETFIRMWARETAG;

typedef struct
{
    VSNETTEMPVALUE      m_region_temp[REGIONTEMPNUM];   //�����¶���Ϣ
}VSNETREGIONTTEMPVALUE;

typedef struct
{
    short               m_valid;    // 1:��Ч 0:��Ч
    short               m_val;      // T * 100��
    unsigned short      m_x;        //X����     
    unsigned short      m_y;        //Y����   
}VSNETREGION;

typedef struct
{
    int                 m_enable;   //�������ʹ�� 
    VSNETREGION         m_max;      //�����ֵ
    VSNETREGION         m_min;      //�����ֵ
    VSNETREGION         m_avg;      //ƽ����ֵ
}VSNETREGIONTEMP;
typedef struct
{
    VSNETREGIONTEMP     m_region_temp[REGIONTEMPNUM]; //�����ֵ
}VSNETREGIONTEMPLIST;

typedef struct
{
    int                 m_gaintype;       //�����л����� 0:�Զ��л� 1:�ֶ��л�
    int                 m_gainmode;       //����ģʽ 1:������ 2:������(�Զ��л�ʱ������Ч)
}VSNETGAINMODE;

/* ��Ƶ���ģʽ���� */
typedef struct
{
    int                 m_videoout_mode;  // HDMIMODE_E 0:�ɼ��� 1:PIP 2:�����
}VSNETVIDEOOUTMODE; 

typedef struct
{
    VSNETCOORDINFO      m_global_coord;                  //ȫ�ָߵ��µ�����
    VSNETCOORDINFO      m_region_coord[REGIONTEMPNUM];   //����ߵ��µ�����
}VSNETTEMPCOORDINFO;

/* �豸�˿����� */
typedef struct
{
    short               m_localport;      //���ض˿ں�
    short               m_webport;        //Web�������˿�
    short               m_multiport;      //�ಥ�˿�
    short               m_recv2;          //��������������
}VSNETCHPORT; 

typedef struct
{
    char  m_product_type[32]; //sensor�豸���к�
}PRODUCTINFO; 
typedef struct
{
    char  m_sensor_serial[32]; //sensor�豸���к�
}VSNETSERIALNO; 

typedef struct
{
    float m_temp_value;
    int   m_temp_x;
    int   m_temp_y;
}VSNETCOORDVALUE; //������Ϣ

typedef struct
{
    VSNETCOORDVALUE m_maxtempinfo; 
    VSNETCOORDVALUE m_mintempinfo;
    float           m_avgtempinfo;
}VSNETTEMPVALUE_EX;

typedef struct
{
    int m_mode;             //0: ����ģʽ�� 1: У׼ģʽ
}VSNETSWITCHMODE;         //У׼ģʽ�л�

typedef struct
{
    int m_segment;          //NUC����������Χ[0~4]
}VSNETTEMPSEGMENT;        //���¶α��

typedef struct
{
    unsigned char m_NUCTableIdx;  //NUC����������Χ[0~4]
    char          m_DevState;     //�豸״̬��-1-�豸״̬δ֪��0-�ȶ���1-���ȶ�
    unsigned char m_u8Reserve[2]; //����
    int           m_FPA;          //��ǰFPA X 100,��λC
    int           m_FPASpeed;     //��ǰFPA�仯���� X 1000����λC/min��> 0���£�< 0����
    int           m_s32Reserve[5];//����
}VSNETSENSORSTATE;              //Sensor״̬

///**************ʱ�������***************************/
//typedef enum
//{
//    ETI_DAY_MONDAY = 0,    //����һ
//    ETI_DAY_TUESDAY = 1,    //���ڶ�
//    ETI_DAY_WEDNESDAY = 2,    //������
//    ETI_DAY_THURSDAY = 3,    //������
//    ETI_DAT_FRIDAY = 4,    //������
//    ETI_DAY_SATURDAY = 5,    //������
//    ETI_DAY_SUNDAY = 6,    //������
//    ETI_DAY_MON_FRI = 7,    //����һ-������
//    ETI_DAY_SAT_SUN = 8,    //������-������
//    ETI_DAY_DAILY = 9,    //ÿ��
//    ETI_DAY_OFF = 10,   //�ر�
//}ETI_TIME_DAYTYPE;
typedef struct
{
    short           m_OBJTemp;        //Ŀ���¶ȣ���Χ[0~450]C
    unsigned char   m_ErrRange;       //��Χ����m_ErrRange C���ߡ�m_ErrRange %C
    unsigned char   m_GainMode;       //0-��ǰ���棬1-�����棬2-������
    unsigned short  m_MinFlux;        //�������Χ��m_OBJTemp��Ӧ����С����ֵ
    unsigned short  m_MaxFlux;        //�������Χ��m_OBJTemp��Ӧ���������ֵ
}VSNETOBJFLUXRANGE;                 //Ŀ�����ط�Χ


/* ���±������� */
typedef struct
{
    int                	m_enable;           // function enable
	int					m_typethreshold;	// 0: >m_htempthreshold, 1: <m_ltempthreshold, 2: [m_ltempthreshold, m_htempthreshold], 3: not belong to[m_ltempthreshold, m_htempthreshold]
    float               m_htempthreshold;   // highTempAlarm Threshold
    float               m_ltempthreshold;   // lowTempAlarm Threshold
    int                 m_singlehost;       // label of center for uploading alarm signal
    unsigned char       m_record[16];       // relate to recording
    unsigned char       m_out[8];           // relate to output	1:ON, 0��OFF
    unsigned char       m_enpreno[16];      // relate to preset point
    unsigned char       m_preno[16];        // number of preset point to be called
    unsigned char       m_capjpeg[16];      // relate to capturing
    TIMELIST            m_timelist;         // detection time table define ETI_TIME_DAYTYPE
} VSNETTEMPALARMPARAM;

/* �Ż��������� */
typedef struct
{
    int                	m_enable;           // function enable
    float               m_tempthreshold;    // threshold of threshold
} VSNETFIREPOINTPARAM;

/* �Ż���ȡ�¶�ֵ */
typedef struct
{
    int m_isfire;   //0: no , 1: yes
    VSNETCOORDVALUE m_maxtempinfo; 
} VSNETFIREPOINTDATA;

typedef struct
{
    int m_indexes;             //��λ��ʾ bit0-�����棬bit1-������1�Σ�bit2-������2�Σ�bit3-������3�Σ�bit4-������4�Σ���bitnΪ1��ʾ֧�ָöΣ���֮Ϊ0��֧��
}VSNETTAUNUCTABLEINDEX;      //TAU��ǰ��֧�ֵ�nuc table��������

typedef struct
{
    int m_enable;              //���TAU��ǰ��֧�ֵ�nuc tableʹ�ܣ�1-������⣬0-�رռ��
}VSNETTAUNUCTABLEFUNCTION;  //TAU��ǰ��֧�ֵ�nuc table��⹦��

/*************************M10 parameter end********************************/

/*************************LEO parameter start********************************/
typedef struct
{
    int m_denoise;             // ���������[0,100]
}VSNETDENOISEPARAM; 

typedef struct
{
    int m_roll;             // ��ת������0������ 1������
}VSNETROLLPARAM;

typedef struct
{
    int m_mode;           // �������ģʽ��0 ԭʼraw��1 ����raw��2 ˫���������raw+ͼ��
}VSNETDIGITALOUTMODE; 	//��һ���֧��ԭʼraw������raw���ҳ������߿�ʹ��

typedef struct
{
    int m_mode;             // 0��manual��1��auto��2��external
}VSNETFFCMODE;

typedef struct
{
    int m_frame;             // ֡��
}VSNETFFCFRAMEPARAM;

typedef struct
{
    int m_temp;             // �¶� 
}VSNETFFCTEMPPARAM;

typedef struct
{
    int m_temp;             // �¶�
}VSNETVTEMPTEMP;

typedef struct
{
    int m_region;             //����ţ�0 - 5��
}VSNETVTEMPREGION;

typedef struct
{
    int m_enable;             //ʹ��
}VSNETKENABLE;

typedef struct
{
    int m_enable;             //ʹ��
}VSNETBENABLE;

typedef struct
{
    int m_enable;             //ʹ��
}VSNETBLINDENABLE;

typedef struct
{
    int m_enable;             //ʹ��
}VSNETFILTEENABLE;

typedef struct
{
    int m_value;             //�˲�ϵ��
}VSNETFILTEPARAM;

typedef struct
{
    unsigned char cmd[256];
    int  len;             //͸��
}VSNETTRAN;

typedef struct
{
    unsigned char m_register[22];             //�Ĵ�������(171bit)��Ч
}VSNETSMARTDATA;

typedef struct
{
    float m_shuttertemp;    //shutter�¶�
    float m_lenstemp;       //��ͷ�¶�
    float m_iboardtemp;     //i���¶�
    float m_sboardtemp;     //s���¶�
}VSNETSENSORTEMP;

typedef struct
{
    char m_type;    //���ͣ�0:Kֵ; 1:äԪ��2:DDAC
    char m_group;   //��ţ�0 - 5
    char m_res[2];  //����    
}VSNETWRITEFLASH;

/*************************LEO parameter end********************************/

typedef struct
{
    char                m_serverIP[40];     // Server IP
    unsigned int        m_port;             // Server Port
    unsigned int        m_intervaltime;     // interval time
    char                m_senddata[512];    // data to be sent
} VSNETHOSTNOTIFY;

typedef struct
{
    char                m_alarmname[32];    // name of alarm sensor
    int                 m_senseorinterval;  // interval time for sensor alarming
} VSNETSENSORALARM;

typedef struct
{
    int  m_videolossinterval;   // interval time for video losing
    int  m_videomoveinterval;   // interval time for video moving
    int  m_videohideinterval;   // interval time for video hiding
    int  m_reserved;            // reserved
} VSNETALARMINTERVAL;           // interval time for alarming

typedef struct
{
    int     m_alarmtype;        // sensor type
} ALARMTYPE;

typedef struct
{
    int m_audioinline;          // 1:linear input  0:Mic input
    int m_audioinDBline;        // proportion of linear input(-34 - +12DB) range of linear input(0-100)
    int m_audioinDBMic;         // proportion of Mic input(0,20DB)  range of Mic input(0-1)
    int m_audiooutDB;           // proportion of input(-73 - +6DB)  range of  input(0-100)
} VSNETAUDIOPARAM;              // structure of audio parameter

// structure of audio silent
typedef struct
{
    int m_audiosilent;          // silent:0�� not:others
} VSNETAUDIOSILENT;

typedef struct
{
    int             m_usecdma;  // use cdma
} VSNETCDMAPARAM;

typedef struct
{
    int             m_usewifi;          // use wifi
    char            m_wifiipaddr[16];   // wireless IP address
    char            m_wifinetmask[16];  // wireless MASK address
    char            m_wifigateway[16];  // wireless gateway
    char            m_wifidns[16];      // wireless DNS
    char            m_wifissid[40];     // wireless ssid
    int             m_wifiencmode;      // encription mode 0,no encription 1,wep-60  2,wep-128
    char            m_wifipwd[64];      // cryptographic key wep-60(5 ASCII or 10 HEX) wep-128(13 ASCII or 26 HEX)
} VSNETWIFIPARAM;

typedef struct
{
    int             m_usewifi;          // use wifi 0,OFF 1,Static 2,ppoe 3,DHCP
    int             m_usedefaultgw;     // wireless gateway as default enable (zero,disable nonzero,enable)
    char            m_pppoename[64];    // wireless PPPOE username
    char            m_pppoepswd[64];    // wireless PPPOE password
    char            m_wifiipaddr[16];   // wireless IP address
    char            m_wifinetmask[16];  // wireless MASK address
    char            m_wifigateway[16];  // wireless gateway
    char            m_wifidns[16];      // wireless DNS
    char            m_wifissid[40];     // wireless ssid
    int             m_wifiencmode;      // encription mode 0,no encription 1,wep-60  2,wep-128 3,wep-152 8,wpa-psk/wpa2-psk
    char            m_wifipwd[64];      // cryptographic key wep-60(5 ASCII or 10 HEX) wep-128(13 ASCII or 26 HEX)
} VSNETWIFIPARAMEX;

typedef struct
{
    char            m_wifissid[40];     // wireless ssid
    int             m_wifiencmode;      // encription mode      0-no encription 1-WEP 2-WPA-PSK/WPA2-PSK
} VSNETWIFISSIDINFO;

#define MAX_SSIDNUM 40
typedef struct
{
    int                 m_ssidnum;      // number of wireless router which have been searched
    VSNETWIFISSIDINFO   m_ssidinfo[MAX_SSIDNUM]; // route information
} VSNETWIFISSIDLIST;

typedef struct
{
    char            m_deviceID[32];      // Device ID
    int             m_maxconnect;        // max connection number,computing with 5 per channel
    int             m_linktype;          // link type,1:LAN,2:ADSL,3:others
    char            m_ftpuser[20];       // ftp username
    char            m_ftppass[20];       // ftp password
    char            m_devicemodel[32];   // device model
    int             m_sipport;           // sip port
} VSNETLINKCONFIG;                       // link configuration

typedef struct
{
    int             m_dnsprovider;       // ddns provider
    int             m_ddnsnotifytime;    // ddns update time
    char            m_dnsusername[20];   // ddns username
    char            m_dnspassword[20];   // ddns password
    char            m_dnsdomainname[50]; // dns domain name
} VSNETDNSEXPARAM;

typedef struct
{
    int             m_comport;           // serial port NO.
    int             m_protocol;          // protocol of serial port
    int             m_addr;              // device address
    int             m_alarmchecktime;    // time of alarm check
    int             m_alarmintervaltime; // interval time of alarm
} VSNETEXALARMPARAM;

typedef struct
{
    int             m_benablecheck;      // temperature alarm enable
    TIMELIST        m_timeList;          // detection time
    char            m_boutput[8];        // alarm output,each bit maps alarm output
    char            m_record[16];        // recording label
    char            m_capture[16];       // capturing label
    int             m_delay;             // alarm delay time
    int             m_singlehost;        // center  for uploading
    float           m_tempmax;           // max temperature
    float           m_tempmin;           // min temperature
    float           m_hummax;            // max humidity
    float           m_hummin;            // min humidity
} VSNETHUMITUREPRAM;

typedef struct
{
    int             m_xoffset;           // horizontal offset 0~32
} VSNETVIDEOOFFSET;

typedef struct
{
    unsigned short      m_x;             // x
    unsigned short      m_y;             // y
    unsigned short      m_width;         // width
    unsigned short      m_height;        // height
} VSNETVIDEOMASKAREA;

typedef struct
{
    int                 m_bmask;         // image mask enable
    VSNETVIDEOMASKAREA  m_maskarea[4];   // image mask area
} VSNETVIDEOMASK;

typedef struct
{
    unsigned short      m_x;             // x
    unsigned short      m_y;             // y
    unsigned short      m_width;         // width
    unsigned short      m_height;        // height
    int                 m_qp;            // quality,range(2-31),low is better
} VSNET_VIDEOINTEREST_AREA;

typedef struct
{
    int                      m_enable;   // video interest enable
    VSNET_VIDEOINTEREST_AREA m_area[4];  // video interest area
} VSNET_VIDEOINTEREST;

typedef struct
{
    char                mans_url[128];       // address of manager server
    char                mans_username[32];   // username of manager server
    char                mans_psd[32];        // password of manager server
    char                mans_conrequrl[128]; // inverse link PU address
    char                mans_conreqname[32]; // inverse linkPU username
    char                mans_conreqpsd[32];  // inverse link PU password
} VSNETSNMPCONFIG;

typedef struct
{
    int                 m_nyear;            // received time
    unsigned char       m_nmonth;
    unsigned char       m_nday;
    unsigned char       m_nhour;
    unsigned char       m_nminute;
    unsigned char       m_nsecond;
    unsigned char       m_received[3];      // reserved
    char                m_peplenum[100];    // supercargo number
    char                m_boxnum[100];      // box number
    unsigned short      m_recvnum;          // received box number
    unsigned short      m_sendnum;          // sent box number
} NETRVS_BANKINFO;

typedef struct
{
    int             m_CapJpgEnable;         // regular capturing enable
    int             m_ftp_timecapjpg;       // regular capturing FTP uploading
    int             m_CapJpgInterval;       // interval time for regular capturing
    TIMELIST        m_timeList;             // capture time
} VSNETTIMERCAP;

typedef struct
{
    int             m_busedhcp;             // use DHCP
} VSNETUSEDHCP;

typedef struct
{
    char            m_pppoename[64];        // wifi PPPOE username
    char            m_pppoepswd[64];        // wifi PPPOE password
} VSNETWIFIPPPOEPARAM;


typedef struct
{
    int m_busedefaultaddr;  // use default address or not
    int m_busealarmsms;     // message alarm enable
    int m_interval;         // min interval for sending
} VSNETALARMSMSPARAM;       // parameter structure of message for setting alarm

typedef struct
{
    int  m_zone;         // exactly timezone
    int  m_nReserve[3];  // reserved
} VSNET_EXACTTIMEZONE;

typedef struct
{
	char             m_ip[16];           //ip address
	unsigned short   m_webport;          //web port
	unsigned short   m_webportout;       //web outport
	unsigned short   m_webportstatus;    //webport status
	unsigned short   m_rtspport;         //rtsp port
	unsigned short   m_rtspportout;      //rtsp outport
	unsigned short   m_rtspportstatus;   //rtspport status
	unsigned short   m_msgport;          //msg port
	unsigned short   m_msgportout;       //msg outport
	unsigned short   m_msgportstatus;    //msgport status
	unsigned short   m_videoport;        //video port
	unsigned short   m_videoportout;     //video outport
	unsigned short   m_videoportstatus;  //videoport status
	unsigned short   m_fileoptport;      //file port
	unsigned short   m_fileoptportout;   //file outport
	unsigned short   m_fileoptportstatus;//fileport status
	unsigned short   m_reserve;          //reserved
}VSNET_UPNPINFO;

typedef struct
{
	int m_timetype;      //Time recordtype 0:������;1:������;2:��������
	int m_ftptype;       //FTP recordtype 0:������;1:������;2:��������
	int m_alltype;       //support type 0:��������1:����������������2:���������������͵�������
}VSNET_RECORDSTREAMTYPE;

typedef struct
{
	int m_wifimode;      //0:802.11b;1:802.11g;2:802.11b&802.11g
}VSNET_WIFIMODE;

typedef struct
{
	int   m_motion;        //�ƶ�����־ 0:�ر�1:����
	int   m_videohide;     //��Ƶ�ڵ���־ 0:�ر�1:����
	int   m_neterror;      //�����쳣��־ 0:�ر�1:����
	int   m_sensdec[16];   //̽ͷ��־     0:�ر�1:���� 
}VSNET_ALARMSHORTMSGPARAM;

typedef struct
{
	int             m_enable;          //�����쳣��������0:�ر�1:����
	unsigned char   m_capchannels[16]; //����ץͼͨ��
	unsigned char   m_revchannels[16]; //����¼��ͨ��
	unsigned char   m_alarmouts[4];    //�����������
}VSNET_NETERRORPARAM;

typedef struct
{
	short     m_disktype;        //�洢�豸���� 0:�豸Ӳ�� 2:NAS����Ӳ��
    short     m_NASenable;       //Զ��¼�ƿ��� 0:�ر�1:����
	char      m_NASaddr[128];    //Զ�̵�ַ 
    char      m_NASpath[128];    //Զ��·��
	char      m_NASuser[56];     //�û���
	char      m_NASpassword[56]; //����
}VSNET_DISKSELECTPARAM;  

typedef struct
{
	int	m_Hour;			//Сʱ
	int	m_Min;			//��
	int	m_Sec;			//��
	int m_Type;			//0��תҹ,1Ϊҹת��
}VSNET_DAYNIGHTTIME;


typedef struct
{
	VSNET_DAYNIGHTTIME   m_daynight[2];
	int                  m_daynight_mode;  //0:�ֶ�;1:�����趨��ʱ��ο��ƺ���; 2:�Զ���ת��(�����ⴥ��IR_CUT���ڴ���)
	int                  m_handblackwhite; //�ֶ���ת��   0:��ɫ; 1:��ɫ(ҹ��)
    int                  m_autoblackwhite; //�Զ���ת��   0:�ⴥ��IR_CUT;1�ڴ���
    int                  m_lux;//�������޸��ڴ�����ʽ�Ĳ�ת��
}VSNET_DAYNIGHTSWITCH;
    
//������������
typedef struct
{
	int m_nType;             // 0 �ߵ�ƽ/ҹ���͵�ƽ/�� 1 �͵�ƽ/ҹ���ߵ�ƽ/��
} VSNET_PHOTO_SENSITIVE_TYPE;// ֻ����ѡ������豸 ��ҹģʽΪ�Զ���ʱ�� ����Ч
   
typedef struct
{
	int  m_videoin; //��Ƶ���뷽ʽ0:ɫ������ 1:VGA���� 2:HDMI����
}VSNET_VIDEOINTYPE;

typedef struct
{
	int  m_nAICheck; //AIУ����ֵ
} VSNET_AI_CHECK;

typedef struct
{
	int m_wifienable;//�Ƿ�֧��wifi 0:��֧�� 1:֧��
	int m_3genable;  //�Ƿ�֧��3g 0:��֧�� 1:֧��
}VSNET_WIFIENABLE;

typedef struct
{
    int                 m_noisemode;        //����ģʽ     0:�Զ�; 1:�ֶ�
    int                 m_noiseenable;      //���뿪��     0:OFF;  1:ON
    int                 m_noiselevel;       //����ȼ�     0:����Ӧ 1:�� 2:�� 3:��   ץ�Ļ�ʹ��ʱ������ǿ��  ����ģʽ����Ϊ�ֶ�ʱ�����ã�ȡֵ��Χ��0~255
}VSNET_NOISEPARAM;

typedef struct
{
    VSNET_NOISEPARAM    m_noise;            //�������
    int                 m_wdrmode;          //sensor����ģʽ 0:����(linear)ģʽ, 1:��̬(wdr)ģʽ(ĿǰAR0331֧��wdrģʽ)
}VSNET_NOISEMODEPARAM;

typedef struct
{
	int m_serParamDevType;                  //�豸����    0: �Ǻ����豸  1: �����豸
}VSNET_SENEORPARAMDEVTYPE; 
           
/***************** long-distance retrieval,download,play ****************/
#define  MAX_FILE_DATA            10

typedef struct
{
    int                 m_year;             // year
    unsigned char       m_month;            // month
    unsigned char       m_day;              // day
    unsigned char       m_hour;             // hour
    unsigned char       m_minute;           // minute
    unsigned char       m_second;           // second
    unsigned char       Received[3];        // reserved
} VSNETPLAY_NETTIME, VSNETDIARY_NETTIME;

typedef struct
{
    int                 m_channel;          // channel NO.
    char                sFileName[100];     // file name
    VSNETPLAY_NETTIME   struStartTime;      // start time of file
    VSNETPLAY_NETTIME   struStopTime;       // end time of file
    unsigned int        dwFileSize;         // file size
} VSNETPLAY_FIND_DATA;

typedef struct
{
    int                 m_filenum;                 // file number
    VSNETPLAY_FIND_DATA m_filedata[MAX_FILE_DATA]; // file attribute
} VSNETPLAY_FILE_DATA;

typedef struct
{
    char                desc[200];
} VSNETALARMHOST_DESC;

typedef struct
{
    int                 m_logtime;                 /*ʱ��  Ϊ���������ʱ����*/
    char                m_logadmname[20];          /*����Ա����:  �����¼�����ʱû�в���Ա��ʱ��ȫ����0*/
    int                 m_logch;                   /*ͨ���� �� ̽ͷ�Ż�0*/
    int                 m_logmajtype;              /*�¼�������*/
    int                 m_logmintype;              /*�¼�������*/
    VSNETPLAY_NETTIME   m_logctltime;              /*�Ժ���־��������ṹ,����ʱ��*/
}VSNET_LOGINFO;

#define LOG_MAX_NUM 2500

typedef struct
{
    unsigned              m_lognum;                        /*��ǰ��־��*/
    unsigned              m_logcurlocat;                   /*��ǰλ��*/
    VSNET_LOGINFO         m_loginfo[LOG_MAX_NUM];          /*��־��Ϣ*/ 
}VSNET_LOGCASE;

typedef struct
{
    char             m_logctl;           //Ĭ��Ϊ0,1ʱΪɾ����־������2ʱΪ������־����
    char             m_logogich;         // 0Ϊ������־������Ϊ����
    char             m_logtypesearch;    //���������� 0,1,2,3 Ĭ��Ϊ0
    char             Received;		     //����
    int              m_logstarttime;     //����ʱ����ʼʱ��
    int  			 m_logstoptime;      //����ʱ�Ľ���ʱ��
    char*            m_logbuff;          //�����־(VSNET_LOGCASE *)
}VSNET_LOGCTL;

/*************************FTP uploading parameter********************************/
typedef struct
{
    int                 m_enable_ftp;      // label of FTP upload(reserved)
    char                m_remote_IP[32];   // IP address
    unsigned short      m_remote_port;     // port
    char                m_linkstatus;      // FTP link state
    char                m_resume_enable;   //offline resume enable
    char                m_ftp_user[40];    // Ftp username
    char                m_ftp_pwd[40];     // Ftp password
} VSNETFTPINFO;

/*************************UPNP parameter********************************/
typedef struct
{
    int                 m_enable_upnp;     // upnp enable
} VSNETUPNPCFG;

typedef struct
{
    int                 m_upnp_status;     // upnp status
} VSNETUPNPSTATUS;

/*************************MAIL parameter********************************/
#define SEND_MAIL_MAX_ADDR_NUM              0x3
#define SEND_MAIL_MAX_ATTACH_NUM            0x3
#define SEND_MAIL_MAX_SUBJECT_LEN           0x40
#define SEND_MAIL_MAX_CONTENT_LEN           0x100
#define SEND_MAIL_STRING_LEN                0x40
#define SEND_MAIL_NAME_LEN                  0x20
#define SEND_MAIL_ADDR_LEN                  0x40


typedef struct
{
    char        m_mail_name[SEND_MAIL_NAME_LEN];    // sender name
    char        m_mail_addr[SEND_MAIL_ADDR_LEN];    // sender address
} VSNETMAILADDR;

typedef struct
{
    int                 m_enable_sendmail;                     // sending alarm mail enable
    char                m_server_addr[SEND_MAIL_ADDR_LEN];     // mail server address
    int                 m_server_port;                         // mail server port��25 as default
    char                m_auth_name[SEND_MAIL_STRING_LEN];     // mail verification name
    char                m_auth_pwd[SEND_MAIL_STRING_LEN];      // mail verification password

    int                 m_priority;                            // priority of mail
    char                m_subject[SEND_MAIL_MAX_SUBJECT_LEN];  // title of mail
    char                m_content[SEND_MAIL_MAX_CONTENT_LEN];  // content of mail
    VSNETMAILADDR       m_from_addr;                           // sender address
    VSNETMAILADDR       m_send_addr[SEND_MAIL_MAX_ADDR_NUM];   // receiver address
} VSNETMAILCFG;

/*************************CCD parameter ********************************/
typedef struct
{
    int              m_shuttermode;      // shutter mode 0:AES; 1:MES
    int              m_shtspeed;         // shutter speed 0~255
    int              m_aelevel;          // AE level 0~255

    int              m_awb;              // balance mode 0~255
    int              m_wbr;              // balance by hand R 0~255
    int              m_wbg;              // balance by hand G 0~255
    int              m_wbb;              // balance by hand B 0~255

    int              m_vflip;            // vertical overset 0:OFF; 1:ON
    int              m_hmirror;          // horizontal overset 0:OFF; 1:ON

    int              m_exposuremode;     // exposure mode 0:AE; 1:ME
    int              m_blc;              // back light compensation 0:OFF; 1:ON
    int              m_agc;              // automatic gain 0~255
    int              m_iris;             // iris 0~255
    int              m_toblackwhite;     // color to black-and-white 0:automatic; 1:infrared(night)
    int              m_zoom;             // zoom 0:OFF; 1:ON

    int              m_lightmode;        // switch between day and night 0~255
    int              m_flc;              // 0:OFF; 1:ON
    int              m_switch;           // switch between positive and negative 0:Posi 1:Nega
    int              m_sense;            // 0:OFF; 1:ON
    int              m_sensemax;         // 0:x2; 1:x4; ...; 7:x256
    int              m_prio;             // 0:AGC; 1:Sense up
} VSNETCCDPARAM;
/*************************SENSOR parameter ********************************/
// ɫ�Ȳ���
typedef struct
{
    int     m_nRed;      // ��ɫ��ȡֵ��Χ0 ~ 1023
    int     m_nGreen;    // ��ɫ��ȡֵ��Χ0 ~ 1023
    int     m_nBlue;     // ��ɫ��ȡֵ��Χ0 ~ 1023
} VSNET_VIRBGPARAM;

// ��ת�ڲ���
typedef struct
{
    int     m_nMode;     // 0:��ɫ��1:�ڰף�2:�Զ�  
    int     m_nDay;      // ������ֵ��ȡֵ��Χ0~255���Զ�ʱ��Ч
    int     m_nNight;    // ҹ����ֵ��ȡֵ��Χ0~255���Զ�ʱ��Ч
} VSNET_COLORMODE;

// SENSOR����
typedef struct
{
    int                 m_nRGBEnable;            // RGBʹ�ܣ�0���ر�;1������
    VSNET_VIRBGPARAM    m_nRGB;                  // RGB����ֵ
    
    int                 m_nShutEnable;           // ����ʹ�ܣ�0���ر�;1������
    int                 m_nShutData;             // �����ٶȣ���λ��ʾ��1 < 0 1/25 1 < 1 1/30 1 < 2 1/50... 1 < 12 1/100K...
    unsigned char       m_nShutMode;             // ����ģʽ��0��AES; 1��MES
    unsigned char       m_nShutSpeed;            // �̶������ٶ� 0~255
    
    unsigned char       m_nAwbEnable;            // ��ƽ��ʹ�ܣ�0���ر�;1������
    unsigned char       m_nAwb;                  // ��ƽ��ģʽ��0���Զ�;1���ֶ�; ץ�Ļ�:0���Զ���1�����죻2�����죻3����ѹ�Ƶƣ�
    unsigned char       m_nWbr;                  // �ֶ���ƽ��R��ȡֵ��Χ0 ~ 255
    unsigned char       m_nWbg;                  // �ֶ���ƽ��G��ȡֵ��Χ0~255�� ץ�Ļ���ʹ�øò���
    unsigned char       m_nWbb;                  // �ֶ���ƽ��B��ȡֵ��Χ0~255
    
    unsigned char       m_nVflipEnable;          // ��ֱ��תʹ�ܣ�0���ر�;1������
    unsigned char       m_nVflip;                // ��ֱ��ת��0��OFF; 1��ON
    unsigned char       m_nHmirrEnable;          // ˮƽ��תʹ�ܣ�0���ر�;1������
    unsigned char       m_nHmirr;                // ˮƽ��ת��0��OFF; 1��ON
    
    unsigned char       m_nExposEnable;          // �ع�ģʽ 0���ر�;1������
    unsigned char       m_nExposMode;            // �ع�ģʽ 0��AE; 1��ME
    
    unsigned char       m_nBlcEnable;            // ���ⲹ��ʹ�� 0���ر�;1������
    unsigned char       m_nBlc;                  // ���ⲹ�� 0��OFF; 1��ON
    
    unsigned char       m_nAgcEnable;            // �Զ�����ʹ�ܣ�0���ر�;1������
    int                 m_nAgcData;              // ��λ��1 < 0 �� 1 < 1 �� 1 < 2 �� 1 < 3 ��  
    unsigned char       m_nAgc;                  // �Զ����棬0 ~ 3�ֱ��Ǹ�\��\��\�أ�Ĭ��Ϊ�ߣ������޸���Ϊ�Զ���ת�ڱ��뿪����
    
    unsigned char       m_nIrisEnable;           // ��Ȧʹ�ܣ�0���ر�;1������
    unsigned char       m_nIris;                 // ��Ȧ��ȡֵ��Χ0~255
    
    unsigned char       m_nColorEnable;          // ��ת��ʹ�ܣ�0���ر�;1������
    int                 m_nColorData;            // ��λ��1 < 0 ��ɫ 1 < 1 �ڰ� 1 < 2 �Զ�
    VSNET_COLORMODE     m_nColorMode;            // ��ת�ڲ���
    
    unsigned char       m_nZoomEnable;           // �佹ʹ�ܣ�0���ر�;1������
    unsigned char       m_nZoom;                 // �佹 0��OFF; 1��ON
    
    unsigned char       m_nLightEnable;          // ��ҹ�л�ʹ�ܣ�0���ر�;1������
    unsigned char       m_nLightMode;            // ��ҹ�л� 0~255
    
    unsigned char       m_nFlcEnable;            // ����˸��Ӧ�ó�����ʹ�ܣ�0���ر�;1������
    unsigned char       m_nFlc;                  // ����˸��Ӧ�ó�������0������50HZ��Դ; 1������60HZ��Դ; 2������ 3.�Զ� 4.�ر�
    
    unsigned char       m_nSwitchEnable;         // ����Ƭ�л�ʹ�ܣ�0���ر�;1������
    unsigned char       m_nSwitch;               // ����Ƭ�л���0��Posi 1��Nega
    
    unsigned char       m_nSenseEnable;          // ��Ȳ˵�ʹ�ܣ�0���ر�;1������
    unsigned char       m_nSensedate;            // ��Ȱ�λȡֵ��0����; 1����  2:�ϸ� 3:��
    unsigned char       m_nSenMaxEnable;         // ���ʹ�ܣ�0���ر�;1������
    unsigned char       m_nSenMax;               // ��ȣ�ȡֵ��Χ0 ~ 30��0��x2; 1��x4; ...; 7��x256...
    int                 m_nSenMode;              // ���ģʽ��0���Զ�;1���ֶ���  ץ�Ļ�ʹ��
	
	unsigned char       m_nGammaEnable;          // gamma ʹ�ܣ�0���ر�;1������
    unsigned char       m_nGamma;                // gammaֵ��ȡֵ��Χ0~3
    
    unsigned char       m_nAelEnable;            // AE����ʹ�ܣ�0���ر�;1������
    unsigned char       m_nAel;                  // AE����ȡֵ��Χ0 ~ 255
    
    unsigned char       m_nSensiEnable;          // ������ʹ�ܣ�0���ر�;1������
    unsigned char       m_nSensi;                // �����ȣ�ȡֵ��Χ0~255
    
    unsigned char       m_nBadPtEnable;          // ���㲹��ʹ�ܣ�0���ر�;1������
    unsigned char       m_nBadPt;                // ���㲹����0��OFF; 1��ON
    
    unsigned char       m_nPrioEnable;           // 0���ر�;1������
    unsigned char       m_nPrio;                 // 0��AGC; 1��Sense up
    
	unsigned char       m_nVYHEnable;          // 85-VYH�豸��Ƶ��������ʹ�� 0���ر�;1������
    unsigned char       m_nVYHType;            // ��Ƶ�������ڷ�ʽ 0:�Զ����� 1:�ֶ�����
    unsigned char       m_nVYHlight;           // ����  ��Χ��0~255
    unsigned char       m_nVYHaberrB;          // ɫ�����B ��Χ��0~255
    unsigned char       m_nVYHaberrR;          // ɫ�����R ��Χ��0~255
    
	unsigned char       m_nMirrorEnable;         // ����ʹ�ܣ�0���ر�;1������
	unsigned char       m_nMirror;               // ����0��OFF; 1��ON
	
	unsigned char       m_nLDCEnable;            // LDCʹ�ܣ�0���ر�;1������
	unsigned char       m_nLDC;                  // LDC��0��OFF; 1��ON
	
	unsigned char       m_ndrcEnable;            // ��̬ʹ�ܣ�0���ر�;1������
	unsigned char       m_ndrc;                  // ��̬��0:OFF;1:ON

    unsigned char       m_irisstopenable;        // AIУ��ʹ�ܣ�0���ر�;1������
    unsigned char       m_irisstopvalue;         // AIУ��ֵֹͣ,У��ǰ���û����� 

    unsigned char       m_noiseenable;           // ����ʹ�ܣ�0���ر�;1������
    VSNET_NOISEPARAM    m_noise;                 // �������
    unsigned char       m_wdrmode;               // sensor����ģʽ 0:����(linear)ģʽ, 1:��̬(wdr)ģʽ(ĿǰAR0331֧��wdrģʽ)
	
	unsigned char       m_frameAccEnable;        // ֡����ʹ��
    unsigned char       m_frameAcc;              // ֡����frame accumulation 0 �ر�,2 ��֡����,10 ʮ֡����,25 ��ʮ��֡����

    unsigned char       m_rotation;              // ͼ����ת�Ƕȣ�0����ת;1~4-����;5-˳ʱ��90��;6˳ʱ��270��

    unsigned char       m_cShutParamEnable;       // ���ӿ���ģʽ�²�������ʹ�� 0���ر�;1������
    unsigned char       m_cShutTargetBri;         // ����ͼ������ֵ����Χ0~100, ���ڵ��ӿ���
    unsigned short      m_nShutCurrentBri;        // ��ǰͼ������ֵ�����ڵ��ӿ��ţ�ֻ��
    unsigned short      m_nShutSpeedMin;          // �����ٶȷ�Χ��Сֵ����Χ32us~40000us�����ڵ��ӿ���
    unsigned short      m_nShutSpeedMax;          // �����ٶȷ�Χ���ֵ����Χ32us~40000us�����ڵ��ӿ���    
    unsigned char       m_cShutAgcMin;            // ģ�����淶Χ��Сֵ����Χ0~100, ���ڵ��ӿ���
    unsigned char       m_cShutAgcMax;            // ģ�����淶Χ���ֵ����Χ0~100, ���ڵ��ӿ���
    unsigned char       m_cShutImageBriMin;       // ͼ��������ֵ��Χ��Сֵ����Χ0~100, ���ڵ��ӿ���
    unsigned char       m_cShutImageBriMax;       // ͼ��������ֵ��Χ���ֵ����Χ0~100, ���ڵ��ӿ���

    unsigned char       m_cBlackLevelEnable;      // �ڵ�ƽ��������ʹ�� 0���ر�;1������
    unsigned char       m_cBlackLevel;           // �ڵ�ƽ����Χ0~100,���õ�ISP
    short               m_nFpgaBlackLevelOffset; //�ڵ�ƽƫ��ֵ ��Χ[-512, 512],���õ�FPGA
    unsigned char       m_cFpgaBlackLevel;       // �ڵ�ƽ���̶�Ϊ100�����õ�FPGA

    unsigned char       m_cAgcOffsetEnable;      // ����ƫ��ֵʹ�� 0���ر�;1������
    short               m_nAgcOffset;            // ����ƫ��ֵ����Χ[-512, 512]

    unsigned char       m_Mes_Agcenable;             // �̶�����ģʽ���������ʹ�� 0���ر�;1������
    unsigned char       m_Mes_AgcMax;                // �̶�����ģʽ����������[0, 199]

    unsigned char       m_Knf_enable;             // 3D����---������ʹ�� 0���ر�;1������
    unsigned char       m_Knf;                    // 3D����---������
    unsigned char       m_Tnf_enable;             // 3D����---ʱ����ʹ�� 0���ر�;1������
    unsigned char       m_Tnf;                    // 3D����---ʱ���� (����ֻ��0�ͷ�0���ֿ�������ر�  �Ժ���ܻ��н���ȼ�)

    short               m_reserved;                 //������������չ
    int                 m_reserve[36];               // ������������չ
}VSNET_SENSORPARAM;

//VPN����
typedef struct
{
    int        m_bVpnenable;                //�Ƿ�����VPN
    char       m_szVpnSerIpAddr[32];        //VPN������IP��ַ
    char       m_szVpnUsername[32];         //VPN��¼�û���
    char       m_szVpnUserpasswd[32];       //VPN��¼����
    char       m_szVpnLinkIpAddr[32];       //VPN���ӳɹ�������������IP��ַ��ֻ��
    int		   m_nVpnLinkStatus;            //VPN����״̬��ֻ�� 0;  //δ����	1; //������	2 ; //��������VPN������	3; //VPN���ų�ʱ���������²���	4; //VPN�����ѶϿ����������²���5; //VPN�������޸ģ��������²���
    char       m_nReserveD[28];             //��������������
} VSNET_VPN_INFO;

//wifi����
typedef struct
{
	int  m_nWifiState;   // wifi״̬��0:δ����, 1:������
	int  m_nWifiSignal;  // wifi�ź�ǿ�� 
} VSNET_WIFI_INFO;

/************************APP platform configuration parameter*******************************/
typedef struct
{
    unsigned char       m_register_type;       // register type
    unsigned char       m_enable_register;     // register enable
    short               m_reserved;            // reserved for alignment
    unsigned int        m_register_interval;   // interval time for register��Second as UNIT��0 means only register once when device start
    unsigned char       m_sessionid[128];      // platform session ID
    unsigned char       m_store_sessionid[128];// store session ID
} VSNETPLATFORM_REGISTER_STRATEGY;

typedef struct
{
    unsigned char           m_heartbeat_type;    // heart beat type  0 udp  1 tcp
    unsigned char           m_enable_heartbeat;  // heart beat enable
    short                   m_reserved;          // reserved for alignment
    unsigned int            m_heartbeat_interval;// interval time for heart beat ,Second as UNIT
} VSNETPLATFORM_HEARTBEAT_STRATEGY;

/*************************IP-PORT pair structure********************************/
typedef struct
{
    unsigned char           m_ipaddr[32];   // ip
    unsigned int            m_port;         // port
} VSNETPLATFORM_IPPORT;

typedef struct
{
    VSNETPLATFORM_IPPORT       m_mannage_server;   // configuration of manager server
    VSNETPLATFORM_IPPORT       m_register_server;  // configuration of register server
    VSNETPLATFORM_IPPORT       m_heartbeat_server; // configuration of heart beat server
    VSNETPLATFORM_IPPORT       m_alarm_server;     // configuration of alarm server
    VSNETPLATFORM_IPPORT       m_store_server;     // configuration of store server
} VSNETPLATFORM_SERVERINFO;

#define VSNET_MAX_PLATFORM_IPPAIR   4
/*************************platform link configuration********************************/
typedef struct
{
    unsigned  int                m_platformtype;               // platform type
    char                         m_deviceID[32];               // device ID
    unsigned short               m_maxconnet;                  // max connection number��computing with 5 per channel
    unsigned short               m_linktype;                   // link type,1:LAN,2:ADSL,3:others
    unsigned short               m_msgport;                    // message port
    unsigned short               m_videoport;                  // video port
    unsigned short               m_audioport;                  // audio port
    unsigned short               m_talkport;                   // talk port
    unsigned short               m_updateport;                 // update port
    short                              m_reserved;             // reserved for alignment
    VSNETPLATFORM_SERVERINFO           m_platform_serverinfo;  // information of platform server
    VSNETPLATFORM_REGISTER_STRATEGY    m_platform_reg;         // information of platform register
    VSNETPLATFORM_HEARTBEAT_STRATEGY   m_platform_heatbeat;    // information of platform heart beat
} VSNETPLATFORM_INFO;
/*********************************************************/

typedef struct
{
    unsigned char                m_enable_vo;      // enable image circle or not 0:off 1:on 101:��֧��
    unsigned char                m_enable_vo_vga;  // enable VGA 0:off 1:on 101:��֧��
    unsigned char                m_vo_vga_res;     // 7:800*600 8:1024*768 101:��֧��
    unsigned char                m_reserved[1];    // reserved for alignment
} VSNETVOCFG;

typedef struct
{
    unsigned char                m_upload_record;  // upload record
    unsigned char                m_upload_capjpeg; // upload captured image
    unsigned char                m_reserved[2];    // reserved for alignment
} VSNETFTPUPLOAD;

typedef struct
{
    char    m_ccCode[32];                          // manufacturer code
    char    m_devID[32];                           // device ID
    char    m_devType[32];                         // device type
    char    m_reserved[256];                       // reserved for extension
} VSNETDEVINFO_HH;

typedef struct
{
    int     m_run_seconds;                         // run time,second as UNIT
} VSNETRUNTIME_HH;

typedef struct
{
    VSNETFTPUPLOAD               m_ftp_upload[16]; // channel FTP upload parameter
} VSNETALARMFTPUPLOAD;

typedef struct
{
    unsigned char     m_alarm_rec[16];             // alarm relate to recording
    unsigned char     m_alarm_capjpeg[16];         // alarm relate to  JPEG capture
    unsigned char     m_ftp_alarmrec[16];          // uploading recording of alarm relating to FTP
    unsigned char     m_ftp_alarmcapjpeg[16];      // uploading capturing image of alarm relating to FTP
} VSNETALARMCONTACTEX;

typedef struct
{
    unsigned char     m_bEnable;                   // preset point plan enable
    unsigned char     m_reserved[1];               // reserved for alignment
    unsigned char     m_start_month;               // start month
    unsigned char     m_start_day;                 // start day
    unsigned char     m_start_hour;                // start hour
    unsigned char     m_start_min;                 // start minute
    unsigned char     m_stop_month;                // end month
    unsigned char     m_stop_day;                  // end day
    unsigned char     m_stop_hour;                 // end hour
    unsigned char     m_stop_min;                  // end minute
    unsigned char     m_point_intime;              // preset point number to be called in time
    unsigned char     m_point_outtime;             // preset point number to be called out of time
} VSNETAUTOPOINT_ITEM;

typedef struct
{
    unsigned char           m_bEnable;             // preset point plan enable
    unsigned char           m_interval;            // interval time reset automatically��minute as UNIT
    unsigned char           m_reserved[2];         // reserved for alignment
    VSNETAUTOPOINT_ITEM     m_scheme[4];           // 4 scheme of call preset point
} VSNETAUTOGOTOPOINT;

typedef struct
{
    unsigned char           m_enable;                  // temperature and humidity sensor enable
    unsigned char           m_addrtem;                 // address of temperature and humidity server
    unsigned char           m_osd_temperature;         // OSD temperature enable
    unsigned char           m_osd_humidity;            // OSD humidity enable
    int                     m_alarmtime;               // interval time for alarm
    TIMELIST                m_timelist;                // time for defense
    unsigned char           m_temperature_alarmout[16];// output of temperature alarm relating,previous 4 outputs are alarm outputs ,then 11 GPIO
    unsigned char           m_humidity_alarmout[16];   // output of humidity alarm relating,previous 4 outputs are alarm outputs ,then 11 GPIO
    float                   m_max_temperature;         // max temperature
    float                   m_min_temperature;         // min temperature
    float                   m_max_humidity;            // max humidity
    float                   m_min_humidity;            // min humidity
} VSNETTEMHUMYWCNCEN;

typedef struct
{
    unsigned char    m_enable;               // voltage sensor enable
    unsigned char    m_addrtem;              // voltage sensor address
    unsigned char    m_osd_voltage;          // OSD voltage enable
    unsigned char    m_reserved;             // reserved for alignment
    int              m_alarmtime;            // interval time for alarm
    TIMELIST         m_timelist;             // time for defence
    unsigned char    m_voltage_alarmout[16]; // output of humidity alarm relating,previous 4 outputs are alarm outputs ,then 11 GPIO
    float            m_rating;               // voltage rating ,V as UNIT
    float            m_alarm_voltage;        // alarm voltage��V as UNIT
} VSNETVYWCNCEN;

typedef struct
{
    unsigned char    m_bEnable[3];              // enable relate to dangerous temperature and humidity
    unsigned char    m_reserved;                // reserved
    unsigned char    m_bEnable_maxdan_tem[4];   // max dangerous temperature enable
    float            m_maxdan_temperature[3];   // max dangerous temperature
    unsigned char    m_bEnable_mindan_tem[4];   // min dangerous temperature enable
    float            m_mindan_temperature[3];   // min dangerous temperature
    unsigned char    m_bEnable_maxdan_hum[4];   // max dangerous humidity enable
    float            m_maxdan_humidity[3];      // max dangerous humidity
    unsigned char    m_bEnable_mindan_hum[4];   // min dangerous humidity enable
    float            m_mindan_humidity[3];      // min dangerous humidity
    unsigned int     m_checktimersecond;        // interval time for checking
} VSNETDANTEMHUMYWCNCEN;

typedef struct
{
    int                     m_alarmmode;        // alarm mode0��OFF,1��ON
    int                     m_singlehost;       // label of center for uploading alarm signal
    unsigned char           m_record[16];       // relating to recording
    unsigned char           m_out[15];          // relating to output
    unsigned char           m_osd_enable;       // OSD Enable
    unsigned char           m_enpreno[16];      // relating to preset point
    unsigned char           m_preno[16];        // perset point number to be called
    unsigned char           m_capjpeg[16];      // relating to capture
    TIMELIST                m_timelist;         // check time table
} ALARMRECORDEXYWCNCEN;

typedef struct
{
    int                     m_benab;            // alarm enable
    ALARMRECORDEXYWCNCEN    m_alarmrec[8];      // parameter of relating alarm
} ALARMPARAMEXYWCNCEN;

typedef struct
{
    float                   m_rate_voltage;     // rating voltage
    float                   m_cur_voltage;      // current voltage
} VSNETVALARMYWCNCEN;

typedef struct
{
    short                   m_temhumdata;       // temperature and humidity
    short                   m_alarmtype;        // alarm type 0:no alarm,1:higher than upper limit,2:lower than upper limit
} VSNETTEMHUMALARMYWCNCEN;

// caution line
typedef struct
{
    int     m_sgline_flg;        // single line alarm enable
    char    m_sgline_name[64];   // alarm rule name for single line
    int     m_sgline_drc;        // single line direction 0:Left1:Right 2:bidirectional
    int     m_sgline_beg_x;      // alarm coordinate of single line , top left
    int     m_sgline_beg_y;      // alarm coordinate of single line , top left
    int     m_sgline_end_x;      // alarm coordinate of single line , down right
    int     m_sgline_end_y;      // alarm coordinate of single line , down right
} VSNETVASINGLELINERULE;

typedef struct
{
    int                    m_multiline_flg;      // broken line alarm
    char                   m_multiline_name[64]; // rule name of broken line alarm
    int                    m_lineCount;          // single line count of broken line
    VSNETVASINGLELINERULE  m_multiline[10];      // rule of broken line
} VSNETVAMULTILINERULE;

typedef struct
{
    int     m_dbline_flg;        // double line alarm enable
    char    m_dbline_name[64];   // rule name of double line alarm
    int     m_dbline_drc;        // double line direction 0:left 1:right
    int     m_dbline0_beg_x;     // alarm coordinate of line one , top left
    int     m_dbline0_beg_y;     // alarm coordinate of line one , top left
    int     m_dbline0_end_x;     // alarm coordinate of line one , down right
    int     m_dbline0_end_y;     // alarm coordinate of line one , down right
    int     m_dbline1_beg_x;     // alarm coordinate of line two , top left
    int     m_dbline1_beg_y;     // alarm coordinate of line two , top left
    int     m_dbline1_end_x;     // alarm coordinate of line two , down right
    int     m_dbline1_end_y;     // alarm coordinate of line two , down right
} VSNETVADOUBLELINERULE;

// region alarm(enter,leave,hover) public segment
typedef struct
{
    int                m_region_valid;                  // valid label of region alarm
    int                m_region_flg;                    // region alarm enable
    char               m_region_name[64];               // rule name of region alarm
    unsigned int       m_packed_msk[352 * 288 / 8 / 4]; // region mask---stored as bit (0-->>0) (1-->>255)
} VSNETVAREGIONERULE;

typedef struct
{
    int                m_frm_bkgd;        // frame number when background initialization finished
    int                m_frm_pixels;      // average value of background and covariance period for updating---per m_frm_pixels frame updating once
    int                m_frm_object;      // time for static object becomes background ---update moving point for a long time  to background
} VSNETVABACKGROUND;

typedef struct
{
    int                m_obj_min_area;    // min area of moving object
    int                m_obj_max_area;    // max area of moving object
} VSNETVAOBJECTAREA;

typedef struct
{
    int                m_alm_window_enable;     // object rectangle enable
    int                m_alm_dotline_enable;    // point of object track enable
    int                m_stabilization_enable;  // image stabilization enable
    int                m_region_shield_enable;  // region shield enable
    unsigned int       m_region_shield_msk[352 * 288 / 8 / 4]; // mask code of region shield after packing---store with bit (0-->>0) (1-->>255)
} VSNETVAALARMSETTING;

typedef struct
{
    int                m_enable;    // 0:disable; 1:enable local preview
    int                m_scale;     // 0:1 picture; 1:4 pictures; 2:9 pictures; 3:16 pictures
    unsigned char      m_vichn[16]; // select input channels for 16 output channels
    // nvr: index is vochn  value is decch
} VSNETVIEWPARAM;

typedef struct
{
    VSNETVIEWPARAM     m_viewparam[VSNET_DVR_MAXVONUM];
} VSNETVIEWCFG;

typedef struct
{
    int                m_time;             // round look time
    int                m_scale;            // 0:1 picture; 1:4 pictures; 2:9 pictures; 3:16 pictures
    unsigned char      m_vichn[16];        // select input channels for 16 output channels
} VSNETLOOPPARAM;

typedef struct
{
    int                m_enable;           // 0:disable; 1:enable round look
    int                m_loopnum;          // group number of round look
    VSNETLOOPPARAM     m_loopparam[20];    // parameter of round look
} VSNETLOOPVIEW;

typedef struct
{
    VSNETLOOPVIEW      m_loopview[VSNET_DVR_MAXVONUM];
} VSNETLOOPCFG;

typedef struct
{
    int                m_enabled;          // disk support smartctl or not,1:enable��0:disable
    int                m_health;           // disk check,1:passed, 0:failed.
    int                m_temperature;      // disk temperature
    int                m_poweronhours;     // disk power-on time
    int                m_uncorrectalbe;    // percentage of error sector scanned off line
} VSNETSMARTPARAM;

typedef struct
{
    int                m_disknum;          // total of disk
    VSNETSMARTPARAM    m_smartinfo[8];     // smart information of 8 disks
} VSNETSMARTINFO;

typedef struct
{
    int                m_enable;           // nfs 1��enable�� 0��disable
    char               m_deviceip[40];     // device IP address
    char               m_devicedir[40];    // device path
} VSNETMNTNFS;

typedef struct
{
    int                m_enable;                        // enable
    int                m_singlehost;                    // label of center for uploading alarm signal
    int                m_singlebuzzer;                  // buzzer trigger
    int                m_magnify[VSNET_DVR_MAXVONUM];   // relating amplification
    int                m_reseved1;                      // reserved
    unsigned char      m_record[VSNET_DVR_MAXCH];       // relate to recording
    unsigned char      m_capjpeg[VSNET_DVR_MAXCH];      // relate to capture
    unsigned char      m_ftprecord[VSNET_DVR_MAXCH];    // ftp upload recording
    unsigned char      m_ftpcapjpeg[VSNET_DVR_MAXCH];   // ftp upload alarm capturing
    unsigned char      m_out[VSNET_DVR_MAXALARMOUT];    // relate to output
    unsigned char      m_enable_ptz[VSNET_DVR_MAXCH];   // enable relate to cloud platform
    unsigned char      m_enable_type[VSNET_DVR_MAXCH];  // ability type��1:call preset point��2:call track, 3:ONLY preset point,4:ONLY track
    unsigned char      m_preno[VSNET_DVR_MAXCH];        // call preset point
    unsigned char      m_pretrackno[VSNET_DVR_MAXCH];   // relating track number
    TIMELIST           m_timelist;                      // check time table
} VSNETDVRALARMPARAM;

typedef struct
{
    VSNETDVRALARMPARAM  m_alarmparam;
    unsigned char       m_alarmsenstive;    // sensitivity of moving detection
    unsigned char       m_reseved1;         // reserved
    unsigned char       m_reseved2;
    unsigned char       m_reseved3;
    unsigned char       m_detect[18][22];   // range to be detected
} VSNETDVRMOTIONALARM;                      // parameter of moving detection

typedef struct
{
    VSNETDVRALARMPARAM  m_alarmparam;
    int                 m_alarmmode;        // alarm mode0��OFF,1��ON
    int                 m_senseorinterval;  // interval time of sensor alarm
    char                m_alarmname[32];    // sensor name
} VSNETDVRSENSORALARM;                      // parameter of sensor alarm

typedef struct
{
    VSNETDVRALARMPARAM  m_alarmparam;
    int                 m_decval;           // detection sensitivity(1(lowest)---5(highest))
} VSNETDVRHIDEALARM;                        // hide alarm

typedef struct
{
    VSNETDVRALARMPARAM  m_alarmparam;
} VSNETDVRVILOSTALARM;                      // video lost

typedef struct
{
    VSNETDVRALARMPARAM  m_diskfull;         // disk full
    VSNETDVRALARMPARAM  m_diskerror;        // disk error
    VSNETDVRALARMPARAM  m_accessviolation;  // violative access
    VSNETDVRALARMPARAM  m_nodisk;           // no disk
    VSNETDVRALARMPARAM  m_reseved1;         // reserved
    VSNETDVRALARMPARAM  m_reseved2;         // reserved
    VSNETDVRALARMPARAM  m_reseved3;         // reserved
    VSNETDVRALARMPARAM  m_reseved4;         // reserved
} VSNETDVROTHERALARM;                       // other parameter

typedef struct
{
    VSNETDVRALARMPARAM  m_alarmparam;
    int                 m_capinterval;      // interval time of capture, 0:snap one picture
    int                 m_alarmtime;        // delay time of alarm
    float               m_alarmtemp;        // return difference temperature of alarm
    int                 m_alarmmode;        // alarm mode, 0:higher than 1:lower than 2:outof 3:between
    float               m_hightemp;         // the highest temperature of alarm
    float               m_lowtemp;          // the lowest temperature of alarm
}VSNETREGIONTEMPALARM;

typedef struct
{
    char                m_deviceID[16];     // device ID
    char                m_active;           // status, 1 : active
    char                m_reserved[3];
} VSNETREMOTECTRL;

typedef struct
{
    unsigned int      m_right;                // each bit represents a kind of right,from low to high,it is
    // local playback,long-distance playback,long-distance preview,talk,local cloud platform control,
    // long-distance cloud platform control��recording by hand��recording file backup��log management��
    // system parameter setting,upgrading system,close device,management of user account number
    unsigned int      m_right1;               // reserved
    unsigned int      m_netview;              // 0~31 channel of long-distance preview
    unsigned int      m_netview1;             // 32~63 channel of long-distance preview
    unsigned int      m_netplay;              // 0~31 channel of long-distance preview
    unsigned int      m_netplay1;             // 32~63 channel of local playback
    unsigned int      m_localplay;            // 0~31 channel of local playback
    unsigned int      m_localplay1;           // 32~63 channel of local playback
} VSNETDVRUSERRIGHT;

typedef struct
{
    VSNETDVRUSERRIGHT m_right;
    char              m_groupname[20];
} VSNETDVRUSERGROUP;

typedef struct
{
    char              m_username[20];
    char              m_password[20];
    int               m_groupnum;            // right group of user
    VSNETDVRUSERRIGHT m_right;
} VSNETDVRUSER;

typedef struct
{
    int               m_usernum;             // user number
    int               m_groupnum;            // number of valid groups
    VSNETDVRUSERGROUP m_group[8];            // 8 groups��initialize 4 groups ,reserve 4 groups
    VSNETDVRUSER      m_user[32];            // 32 users��initialize 4 users
} VSNETDVRSYSUSER;

// extent user info(add the stauts of user)
typedef struct
{
    char              m_status[32];          // the status of user(0:disbale, 1:enable)
    VSNETDVRSYSUSER   m_dvrsysuser;
} VSNETDVRSYSUSEREX;

typedef struct
{
    int               bShow;             // show(1),hide(0)
    char              lpString[32];      // characters to be showed
    unsigned short    x, y;              // coordinate
} TITALOSD_DVR;

typedef struct
{
    TIMEOSD           m_time;            // time
    TITALOSD_DVR      m_tital[4];        // title
    BITSINFOOSD       m_bits;            // bit rate
} CHANNOSD_DVR;

typedef struct
{
    int               m_doublebits;      // 1:double bit stream��0:single bit stream
} VSNETDVRDOUBLEBITS;

typedef struct
{
    char              m_name[9][32];     // name of switching button
} VSNETSWITCHSCREENNAME;

typedef struct
{
    char              m_servername[60];   // server name
    char              m_serverip[16];     // IP address
    char              m_servermask[16];   // network mask
    char              m_gatewayAddr[16];  // gateway
    unsigned short    m_serport;          // data port
    char              m_hostserverurl[40];// address of long-distance server
    unsigned short    m_hostserverport;   // port of long-distance server
    char              m_pppoename[64];    // PPPOE username
    char              m_pppoepswd[64];    // PPPOE password
} VSNETBASENETPARAM;

typedef struct
{
    int             m_ftp_timerec;     // regular FTP uploading capture
    TIMELIST        m_timeList;        // capture time
} VSNETFTPTIMEREC;

typedef struct
{
    int             m_xoffset;         // horizontal offset 0~32
    int             m_yoffset;         // vertical offset 0~32
} VSNETVIDEOOFFSETEX;

typedef struct
{
    int             m_state;             // 3G state
    char            m_ip[32];            // CenterIP
    char            m_subnetmask[32];    // subnet mask for WCDMA dialing
    char            m_gateway[32];       // gateway for WCDMA dialing
    char            m_wcdma_dns_pri[32]; // primary DNS for WCDMA dialing
    char            m_wcdma_dns_alt[32]; // Secondary DNS for WCDMA dialing
} VSNET3GSTATE;

typedef struct
{
    int             m_3gmode;            // connection parameter      -------->0-OFF 1-CDMA 2-evdo(3g cdma2000) 4-wcdma 8-tdcdma
    unsigned char   m_cdmaname[64];      // reserve cdma username(dv-do username)
    unsigned char   m_cdmapwd[64];       // reserve cdma password(dv-do password)
    char            m_cdmadial[16];      // reserve cdma dialing number(dv-do dialing number)
} VSNET3GPARAM;

typedef struct
{
    int              m_3gmode;           // connection parameter      -------->0-OFF 1-CDMA 2-evdo(3g cdma2000) 4-wcdma 8-tdcdma
    unsigned char    m_cdmaname[64];     // reserve cdma username(dv-do username)
    unsigned char    m_cdmapwd[64];      // reserve cdma password(dv-do password)
    char             m_cdmadial[16];     // reserve cdma dialing number(dv-do dialing number)
    unsigned char    m_apnname[64];      // point name
    int              m_keepalive;        // keep connection alive
    int              m_lcpechointerval;
    int              m_lcpechofailure;
    int              m_maxreceiveunit;
    int              m_maxtransferunit;
    int              m_networkconnectionmode;    // online,dial for need,dial by hand
    int              m_networkregistertype;      // AUTO,2G,3G
    int              m_radiobankset;             // band setting,represented by bit
    int              m_bandsaving;               // reserved band
    int              m_getdnsfromoperator;
    char             m_dns_pri[32];              // Primary DNS
    char             m_dns_alt[32];              // Secondary DNS
    int              m_authtype;
    unsigned char    m_expertoptions[128];       // extension parameter
} VSNET3GPARAMEX;

typedef struct
{
    int              m_pinprotection;            // pin protection
    unsigned char    m_pincode[64];              // pin code
} VSNETPININFO;

typedef struct
{
    int              m_simstatus;                // sim status
    unsigned char    m_simnumber[64];            // sim number
    char             m_operator[20];             // provider
    int              m_cur_cdma_network;         // current network
    int              m_sig_percent;              // signal strength
    char             m_imei[20];                 // IMEI
} VSNETSIMINFO;

typedef struct
{
    int              m_smsdays;                  // message days
    int              m_sms_sendip;               // message sends IP address or not
    unsigned char    m_smscellphone[64];         // number for receiving message
    unsigned char    m_smscenternumber[64];      // number of message center
    unsigned char    m_smscontent[128];          // content of message
} VSNETSMSINFO;

typedef struct
{
    int              m_logsize;                  // log size
    unsigned char *  m_logstring;                // log content
    unsigned char    m_logfilename[64];          // log name
} VSNETWCDMALOG;

typedef struct
{
    int              m_check3gstatus;            // check 3g status
    unsigned char    m_pingipaddr[64];           // ping IP Address
    int              m_pingipinterval;           // interval  of ping ip
    int              m_pingbytes;                // data size for ping
    int              m_pingfailcnt;              // redial number when ping failure
} VSNETCHECK3GSTATUS;

typedef struct
{
    int              m_nPhoneDisconnauto;         // ���ŵ绰��������������ʱ�Զ����ߣ�1����ѡ���޴�ֵ��δ��ѡ
    int              m_nPhoneDisconntimer;        // ���š��绰��������������ʱ�ȴ�ʱ�� 
    int              m_nChkPhone;                 // �������������º���Ķ��Ż����磺1����ѡ���޴�ֵ��δ��ѡ
    int              m_nManualDisconnauto;        // �ֶ���������������ʱ�Զ����ߣ�1����ѡ���޴�ֵ��δ��ѡ         
    int              m_nManualDisconntimer;       // �ֶ����������ӵȴ�ʱ�� 
    int              m_nCuroption;                // 0�����ò���; 1���������ߣ�2�������Ͽ�
    char             m_strPhonenumber[10][20];    // �ɽ��ܵ绰���� 
    int              m_nAlarmDisconnenAble;       // ����ģʽ������һ��ʱ��Ͽ�����ʹ��
    int              m_nAlarmDisconnTmSet;        // ����ģʽ�����öϿ�����ʱ��
    TIMELIST         m_timeList;                  // ��ʱʱ���
} VSNET_CHECK3GCONNPARAM;

typedef struct
{
    int                    m_nPhoneorSmsDisconnect; // ���ŵ绰����
    VSNET_CHECK3GCONNPARAM m_connParam;
} VSNET_CHECK3GCONNNET;

typedef struct
{
    int  m_nResult;          // 3G���Ų��Է��ؽ��
    char m_szTestMsg[256];   // 3G���Ų��Է��ؽ���ַ���
} VSNET_3GSMSTESTRES;

typedef struct
{ 
    int             m_nLogSize;  // ������־�ļ���С����ByteΪ��λ
} VSNET_3GDIALUPLOG;

typedef struct
{
    char             m_nSisNetState[120];  // ��������״̬
    VSNETSIMINFO     m_sistate;
} VSNET_3GSIMINFONET;

typedef struct
{
    int     m_linkenable;       // link enable
    int     m_listenport;       // monitor port
} VSNETRTSPPARAM;

// RTSP��չ����
typedef struct
{
    int     m_linkenable;       // RTSPʹ�ܣ�0-�رգ�1-����
    int     m_listenport;       // RTSP�����˿�
    int     m_udpstartport;     // RTSP��UDP��ʼ�˿�
} VSNETRTSPPARAMEX;

// VLC����
typedef struct
{
    int     m_linkenable;       // VLCʹ�ܣ�0-�رգ�1-����
    char    m_dstaddr[16];      // VLCĿ��IP��ַ��ֻ֧��IP��ַ
    int     m_dstport;          // VLCĿ��˿�
    int     m_streamselect;     // VLC�����ͣ�0-PS����1-TS��
} VSNETVLCPARAM;

// VLC��չ����
typedef struct
{
    int     m_linkenable;       // VLCʹ�ܣ�0-�رգ�1-����
    char    m_dstaddr[64];      // VLCĿ���ַ��֧��IP��ַ������
    int     m_dstport;          // VLCĿ��˿�
    int     m_streamselect;     // VLC�����ͣ�0-PS����1-TS��
} VSNETVLCPARAMEX;

// NTP����
typedef struct
{
    int     m_linkenable;       // NTPʹ�ܣ�0-�رգ�1-����
    char    m_serveraddr[16];   // NTP��������ַ��ֻ֧��IP��ַ
    int     m_serverport;       // NTP����˿�
    int     m_timezone;         // ʱ����ȡֵ��Χ-12 ~ 12
} VSNETNTPPARAM;

// NTP��չ����
typedef struct
{
    int     m_linkenable;       // NTPʹ�ܣ�0-�رգ�1-����
    char    m_serveraddr[64];   // NTP��������ַ��֧��IP��ַ������
    int     m_serverport;       // NTP����˿�
    int     m_timezone;         // ʱ����ȡֵ��Χ-12 ~ 12
} VSNETNTPPARAMEX;

typedef struct
{
    VSNETRTSPPARAM m_rtsp;      // RTSP parameter
    VSNETVLCPARAM  m_vlc;       // VLC  parameter
    VSNETNTPPARAM  m_ntp;       // NTP  parameter
} VSNETPROTOCOLPARAM;

typedef struct
{
    VSNETRTSPPARAMEX m_rtsp;      // RTSP parameter
    VSNETVLCPARAMEX  m_vlc;       // VLC  parameter
    VSNETNTPPARAMEX  m_ntp;       // NTP  parameter
} VSNETPROTOCOLPARAMEX;

typedef struct
{
    int             m_encodetype;  // encoding type, 0:H.264, 1:MJPEG 2:MPEG4 3:H265
} VSNETENCODETYPE;

//���뼶�� ����Ϊh264�²���Ч Ŀǰ��56�豸֧��
typedef struct
{
    int             m_encodeprofile;  // encoding profile, 0:baseline, 1:MP, 2:HP
} VSNETENCODEPROFILE;

typedef struct
{
    int             m_remotestreamtype;  // 0 ��������1 ��������2 ��������
} VSNETREMOTESTREAMTYPE;

typedef struct 
{
    unsigned int    m_encryption;        // ���ܷ�ʽ0:������1:SSL 2:STARTTLS
}VSNETENCRYPTIONTYPE;

typedef struct
{
    short       m_audiotag;     // audio tag
    short       m_auchs;        // audio channel number
    short       m_aurates;      // audio bit rate
    short       m_reserved;     // reserved
    int         m_ausample;     // audio sampling frequency
} VSNETTALKBOTHWAY;

typedef struct
{
    int         m_locktime;
} VSNETPTZCTRLTIME;

#define MAX_MEM_NUM 10
#define MAX_PRO_NUM 10
typedef struct
{
    int                      m_prono;            // preset point
    int                      m_time;             // time
    char                     m_proname[32];      // name of preset point
} APP_CRUISE_PRO;
typedef struct
{
    int                     m_enable;            // enable
    TIMECHECK               m_cruise_time;       // time
    char                    m_cruise_name[32];   // cruise name
    int                     m_line_enable;       // enable superposition of cruise route
    int                     m_dot_enable;        // enable superposition of cruise point
    int                     m_superpose_title;   // superposition to title, value as:0��1��2��3 represent superposition to 1,2,3,4 title
    APP_CRUISE_PRO          m_cruise_pro[MAX_PRO_NUM];
} APP_CRUISE_MEMBER;

typedef struct
{
    int                 m_enable;
    APP_CRUISE_MEMBER   m_cruise_member[MAX_MEM_NUM];
} VSNETPROLOOPPARAM;

typedef struct
{
    char  reccordName[60];     // record name
} VSNETSERVERRECPARAM;         // record command parameter of long-distance server

typedef struct
{
    int m_audio_bestir;
} NETFILE_REMOTEAUDIOBESTIR;

typedef struct
{
    int videoin;
} VSNETVIDEOENCMAPINFO;

typedef struct
{
    char    m_value[8];        // show evidence
} VSNETATTESTEXHIBIT;

typedef struct
{
    char m_actors[7];          // character array��from 0 to 5 represents 6  roles's channels��0 justice...��6 is end symbol
} VSNETACTORSINFO;

typedef struct
{
    int                 m_enable;               // enable
    unsigned int        m_brecord[2];           // relate to recording
    unsigned int        m_capjpeg[2];           // relate to jpeg capture
    unsigned int        m_ftp_alarmrec[2];      // uploading recording of alarm relating to FTP
    unsigned int        m_ftp_alarmcapjpeg[2];  // uploading alarm capture to FTP
    unsigned int        m_outputmap[4];         // relate to output
    TIMELIST            m_timelist;             // detection time table
} VSNETSMALARMLINK;                             // alarm relating of intellective analysis

typedef struct
{
    int                 m_enable;                         // ʹ��OSD�߿���
    int                 m_size;                           // �߿��С
    VSNET_RGB_COLOR     m_color;                          // �߿���ɫ
    int                 m_reserver;                       // ����
} VSNET_CHANNOSD_BORDER;//OSD�߿���Ϣ


typedef struct
{
    unsigned char                   m_video; //��Ƶ QOS ���ȼ�  ȡֵ��Χ[0, 63] , TOSʹ�õ��Ǹ�6λ���ײ�ʹ��ʱע����λ 
    unsigned char                   m_audio; //��Ƶ QOS ���ȼ�  ȡֵ��Χ[0, 63] , TOSʹ�õ��Ǹ�6λ���ײ�ʹ��ʱע����λ 
    unsigned char                   m_reserver[2];//����λ
} VSNET_QOS_TOS;//����Ƶ qos���ȼ����� ��ȡ

typedef struct 
{
    int                             m_num;              //֧�ֵ�ͨ����
    unsigned short                  m_encode[256];      //ǰ��m_num������֧�ֵķֱ���
}VSNET_RESOLUTION_LIST;

typedef struct 
{
    int                             m_stream_num;   //�豸֧�ֵ���������
    VSNET_RESOLUTION_LIST           m_encode[4];    //ÿ������֧�ֵķֱ���
    int                             m_reserver[4];
}VSNET_DEV_RESOLUTION;

#define VSNET_NETCFG_IPV6LEN 48
typedef struct
{
    char   m_localip[VSNET_NETCFG_IPV6LEN];               //�ֲ�IP�������޸� //ʹ��ʱ��ʱֻ��ò����������ı���
    int  m_local_fplen;                              //�ֲ�IP��ʽǰ׺����
    char   m_ipaddr1[VSNET_NETCFG_IPV6LEN];               //��������ַ�����ڶ�̬��ȡIP����DHCP
    int  m_ip1_fplen;                                //IP��ʽǰ׺����
    char   m_ipaddr2[VSNET_NETCFG_IPV6LEN];               //��������ַ��Ԥ��
    int  m_ip2_fplen;                                //IP��ʽǰ׺���ȣ�Ԥ��
    char   m_gateway[VSNET_NETCFG_IPV6LEN];               //����
    char   m_dns1[VSNET_NETCFG_IPV6LEN];                  //DNS1
    char   m_dns2[VSNET_NETCFG_IPV6LEN];                  //DNS2
    char   m_multiipaddr[VSNET_NETCFG_IPV6LEN];           //�ಥ��ַ
}VSNET_NETCFG_IPV6;

#define VSNET_SNMP_USER_BUFFER_LEN 64 //�û�������
#define VSNET_SNMP_USER_PASSWORD_LEN 64 //���볤��

typedef struct
{
    char  m_name[VSNET_SNMP_USER_BUFFER_LEN];//�û���
    char  m_hmac_type;//��Ȩ��ʽ
    char  m_hmac_passwd[VSNET_SNMP_USER_PASSWORD_LEN];//��������
    char  m_code_type;//���ܷ�ʽ
    char  m_code_passwd[VSNET_SNMP_USER_PASSWORD_LEN];//��������
    char  m_security_level;//0:����֤�޼��ܣ� 1:��֤������ 2:��֤����
    char  m_reserve;//��������
}VSNET_SNMP_USER_V3_T;

typedef struct
{  
    char  m_read_community[VSNET_SNMP_USER_BUFFER_LEN];            /*����ͬ��*/  
    char  m_rw_community[VSNET_SNMP_USER_BUFFER_LEN];      /*д��ͬ��*/
    
    /*����ֻ����v3�汾*/
    VSNET_SNMP_USER_V3_T m_read_user; //ֻ���û�
    VSNET_SNMP_USER_V3_T m_rw_user;//��д�û�
    
    int   m_reserve[16];//����
    
}VSNET_SNMP_USER_T;

typedef struct
{  
    int                 m_selectVersion;     //ѡ��ʹ��snmp�汾 ��λ��ʶ
    VSNET_SNMP_USER_T   m_user;              //�������õ��û���Ϣ
    char                m_trapaddr[16];      //�����ַ
    unsigned short      m_pollPort;          //��ѯ�˿�
    unsigned short      m_TrapPort;          //����˿�

    char                m_reserve[64];
    
}VSNET_SNMP_CFG_T;

typedef struct
{  
    VSNET_SNMP_CFG_T    m_snmp;              //������Ϣ
    int                 m_default_flag;      //snmp�ָ�Ĭ�ϱ�־
    char                m_reserve[4];
}VSNET_SNMP_T;

// ���ܷ�����չ������������(���֧��16����Ƶͨ��)
typedef struct 
{
	int					m_enable;               // enable
	unsigned int		m_brecord[16];          // relate to recording
	unsigned int		m_capjpeg[16];          // relate to jpeg capture
	unsigned int		m_ftp_alarmrec[16];     // uploading recording of alarm relating to FTP  
    unsigned int		m_ftp_alarmcapjpeg[16]; // uploading alarm capture to FTP
	unsigned int		m_outputmap[16];        // relate to output
	TIMELIST			m_timelist;             // detection time table
} VSNETSMALARMLINK_EX;

// ���ܷ���OSD���Ӳ���
typedef struct
{
    int                 m_enable;               // enable
    unsigned short      m_x, m_y;               // coordinate
    char                m_text[32];             // content to be showed of OSD superposition
} VSNETSMOSD;

// ���ܷ�����������\�뿪����
typedef struct
{
    int                 m_enable;                   // enable rule
    int                 m_enableosd;                // OSD enable
    int                 m_enabledefregion;          // enable default region
    char                m_rulename[64];             // rule name
    unsigned int        m_packed_msk[352 * 288 / 8 / 4]; // region mask---stored with bit (0-->>0) (1-->>255)
    VSNETSMALARMLINK    m_alarmlink;                // alarm relating
    VSNETSMOSD          m_osd[2];                   // OSD superposition of intellective analysis alarm
} VSNETSMREGIONINOUT;

// ���ܷ�����չ��������\�뿪����(���֧��16����Ƶͨ��)
typedef struct
{
	int					m_enable;					// enable rule
	int					m_enableosd;				// OSD enable
	int					m_enabledefregion;			// enable default region
	char				m_rulename[64];				// rule name
	unsigned int        m_packed_msk[352 * 288 / 8 /4];	// region mask---stored with bit (0-->>0) (1-->>255)
	VSNETSMALARMLINK_EX	m_alarmlink;				// alarm relating
	VSNETSMOSD			m_osd[2];					// OSD superposition of intellective analysis alarm
} VSNETSMREGIONINOUT_EX;

// ���ܷ����ǻ�����
typedef struct
{
    int                 m_enable;                   // enable rule
    int                 m_enableosd;                // OSD enable
    int                 m_enabledefregion;          // enable default region
    int                 m_hovertime;                // standard time of hovering
    char                m_rulename[64];             // rule name
    unsigned int        m_packed_msk[352 * 288 / 8 / 4]; // region mask---stored with bit (0-->>0) (1-->>255)
    VSNETSMALARMLINK    m_alarmlink;                // alarm relating
    VSNETSMOSD          m_osd[2];                   // OSD superposition of intellective analysis alarm
} VSNETSMREGIONHOVER;

// ������չ�����ǻ�����(���֧��16����Ƶͨ��)
typedef struct
{
	int					m_enable;                   // enable rule 
	int					m_enableosd;                // OSD enable
	int					m_enabledefregion;          // enable default region
	int					m_hovertime;                // standard time of hovering
	char				m_rulename[64];             // rule name
	unsigned int        m_packed_msk[352 * 288 /8 / 4];	// region mask---stored with bit (0-->>0) (1-->>255)
	VSNETSMALARMLINK_EX	m_alarmlink;                //alarm relating
	VSNETSMOSD			m_osd[2];                   //OSD superposition of intellective analysis alarm
} VSNETSMREGIONHOVER_EX;

// ���ܷ��������߹���			
typedef struct
{
    int                 m_enable;            // rule enable
    int                 m_sgline_drc;        // single line direction    0:left 1:right 2:bidirectional
    int                 m_sgline_beg_x;      // coordinate of single line alarm,top left
    int                 m_sgline_beg_y;      // coordinate of single line alarm,top left
    int                 m_sgline_end_x;      // coordinate of single line alarm,down right
    int                 m_sgline_end_y;      // coordinate of single line alarm,down right
    char                m_rulename[64];      // rule name
    unsigned char       m_enableosd;         // OSD enable
    VSNETSMALARMLINK    m_alarmlink;         // alarm relating
    VSNETSMOSD          m_osd[2];            // OSD superposition of intellective analysis alarm
} VSNETSMALARMLINE;

// ���ܷ�����չ�����߹���(���֧��16����Ƶͨ��)
typedef struct
{
	int					m_enable;            // rule enable
	int					m_sgline_drc;        // single line direction	0:left 1:right 2:bidirectional
	int					m_sgline_beg_x;      // coordinate of single line alarm,top left
	int					m_sgline_beg_y;      // coordinate of single line alarm,top left
	int					m_sgline_end_x;      // coordinate of single line alarm,down right
	int					m_sgline_end_y;      // coordinate of single line alarm,down right
	char				m_rulename[64];      // rule name
	int					m_enableosd;         // OSD enable
	VSNETSMALARMLINK_EX	m_alarmlink;         // alarm relating
	VSNETSMOSD		    m_osd[2];            // OSD superposition of intellective analysis alarm
} VSNETSMALARMLINE_EX;

#if defined(TARGET_FJTS64LINE)
#define SMART_MAXLINES 64   // max line count is 64
#else
#define SMART_MAXLINES 10   // max line count is 10
#endif

// ���ܷ��������߹���
typedef struct
{
    int                 m_count;            // line count
    VSNETSMALARMLINE    m_lines[SMART_MAXLINES];        
} VSNETSMALARMLINES;

// ���ܷ�����չ�����߹���(���֧��16����Ƶͨ��)               
typedef struct
{
	int					m_count;			// line count
	VSNETSMALARMLINE_EX	m_lines[SMART_MAXLINES];
} VSNETSMALARMLINES_EX;



/**************************** ���ܷ��������Ƿ���ʾ�ڿͷ��� *********************************************/
#define MAXSMPTNUM 64
typedef struct
{
#if defined(TARGET_FJTS64LINE)
    unsigned int m_nShowLineL;               //�Ƿ���ʾ���߹��� ��λ��ʾ Ŀǰ���64���߿��Ա�ʾ
    unsigned int m_nShowLineH;
#else
    int m_nShowLine;                //�Ƿ���ʾ���߹��� ��λ��ʾ Ŀǰ���10���߿��Ա�ʾ
#endif
    unsigned char m_bShowInRule;   //�Ƿ���ʾ�����������
    unsigned char m_bShowOutRule;  //�Ƿ���ʾ�����뿪����
    unsigned char m_bShowHoverRule;//�Ƿ���ʾ�����������    
    unsigned char m_cReserved1;    //����
    unsigned char m_cReserved2[4]; //����
} VSNET_SMCLIENTSHOW;

typedef struct
{
    float m_nX;
    float m_nY;
} VSNET_POINT;

typedef struct
{    
    VSNET_POINT m_pt[MAXSMPTNUM];//�������㱣��
    int m_nPtNum;             
} VSNET_SMRECTRULE;
/**************************  ���ܷ��������Ƿ���ʾ�ڿͷ��� ---      �� *************************************/

typedef struct
{
    unsigned int        m_alarmtime;        // alarm time
    int                 m_alarmtype;        // alarm type
    char                m_alarmdesc[56];    // alarm description
} VSNETALARMJPEGCAP;

typedef struct
{
    char m_num[8];              // pit number
    int m_bmotionjpg;           // uploading moving capture to FTP
    int m_waittime;             // wait time(second) for protecting from building bridge
    int m_front_sd;             // front value
} VSNETJNKYPARAM;

typedef struct
{
    char            m_postaddr[32]; // post address
    unsigned short  m_postport;     // post port
    unsigned short  m_reserved;     // reserved for alignment
} VSNETJNKYSERINFO;

typedef struct
{
    int                 m_cruise_day;               // cruise date
    TIMELIST            m_cruise_time;              // cruise time
    int                 m_line_enable;              // enable superposition of cruise route
    char                m_osdstring[32];            // display character of OSD superposition
    int                 m_superpose_title;          // superposition to title, value as:0��1��2��3 represent superposition to 1,2,3,4 title
    int                 m_staytime;                 // stay time of cruise point��3-255 seconds
    int                 m_cruise_pre[MAX_PRO_NUM];  // preset point number
} VSNETPROLOOPPARAMEX;                              // server cruise parameter,no relationship with previous version VSNETPROLOOPPARAM

#define   HNDX_STROSD_NUM   8
#define   HNDX_STROSD_LEN   40

typedef struct
{
    int      m_format;  // not show��2003-09-12 15:23:33��2003-09-12 FRI 15:23:33��09-12-2003 15:23:33��09-12-2003 FRI 15:23:33��12-09-2003 15:23:33
    int      m_x;       // x position��8-704 (multiple of 4)
    int      m_y;       // y position��10-576
} VSNETHNDXTIMEOSD;     // time OSD

typedef struct
{
    int      m_isshow;  // show bit rate or not
    int      m_x;       // x position��8-704 (multiple of 4)
    int      m_y;       // y position��10-576
} VSNETHNDXBITRATEOSD;  // bit rate OSD

typedef struct
{
    int      m_x;                       // x position��8-704 (multiple of 4)
    int      m_y;                       // y position��10-576
    int      m_color;                   // color 0:red 1:green 2:blue 3:white
    char     m_str[HNDX_STROSD_LEN];    // String
} VSNETHNDXOSDSTRING;                   // String OSD

// OSD parameter
typedef struct
{
    VSNETHNDXBITRATEOSD m_bitrateosd;
    VSNETHNDXTIMEOSD    m_timeosd;
    VSNETHNDXOSDSTRING  m_stringosd[HNDX_STROSD_NUM];
} VSNETHNDXOSDATTR;

// AAC parameter
typedef struct
{
    int       m_enableaac;   // AAC enable
    int       m_enSmpRate;   // AAC sampling frequency
    int       m_BitWidth;    // AAC bit width
    int       m_BandWidth;   // AAC band width
} VSNETAUDIOAAC;

typedef struct
{
    int       m_color_set;   // 0: automatic, 1: by hand
} VSNETHQCOLOR;              // set mode

typedef struct
{
    int     m_smart_sense;   // intellective analysis of sensitivity
} VSNETSMARTSENSE;

typedef struct
{
    int     m_smart_tracktype;    // intellective analysis of object type��0 all��1 human 2 vehicle
} VSNETSMARTTRACKTYPE;

typedef struct
{
    char    m_serurl[16];         // server IP address
    int     m_serport;            // server port
    char    m_stationID[10];      // station number
    char    m_reserve[2];         // reserved for alignment
    char    m_clienturl[16];      // additional client ip
    int     m_clientport;         // client port
    char    m_direction[4];       // station direction
} VSNETCDRHPARAM;

typedef struct
{
    int   m_enable;               // ON or OFF
    int   m_interval;             // check interval
    float m_flowlow;              // flow lower limit
    float m_flowhigh;             // flow upper limit
    float m_phlow;                // ph lower limit
    float m_phhigh;               // ph upper limit
    float m_Densitylow[12];       // lower limit of 12 kinds of pollution
    float m_Densityhigh[12];      // upper limit of 12 kinds of pollution
    char  m_Alarmflow[4];         // alarm ,flow relating to
    char  m_Alarmph[4];           // alarm ,PH relating to
    char  m_AlarmDensity[12][4];  // alarm ,pollution relating to
} VSNETYWCODPARAM;

typedef struct
{
    char   DeviceState[8];        // 8 devices
    float  m_flow;                // flow speed
    float  m_ph;                  // PH
    float  m_Density[12];         // lower limit of 12 kinds of pollution
} VSNETYWCODDATA;

typedef struct
{
    char m_cmd[52];               // command of sampling machine for water quality
} VSNETYWSZCYQCODE;

typedef struct
{
    char m_code[12];              // command of electromagnetism flowmeter
} VSNETYWFLOWMETERCODE;

typedef struct
{
    int     m_region_flg;         // region flag of analysis for black degree,judge region or not
    int     m_region_left;        // region coordinate of analysis for black degree,top left
    int     m_region_top;         // region coordinate of analysis for black degree,top left
    int     m_region_right;       // region coordinate of analysis for black degree,down right
    int     m_region_bottom;      // region coordinate of analysis for black degree,down right
} VSNET_BLACK_REGION;

typedef struct
{
    VSNET_BLACK_REGION  m_region[10];   // region of analysis for black degree
} VSNET_BLACK_REGIONTARGET;

typedef struct
{
    VSNET_BLACK_REGION  m_region;       // reference region for  analysis for black degree
} VSNET_BLACK_REGIONREFER;

typedef struct
{
    float m_min_val;                    // lowest value of black degree
    float m_max_val;                    // highest value of black degree
} VSNET_BLACK_ALARMRANGE;

typedef struct
{
    VSNET_BLACK_REGION  m_region;       // region of analysis for black degree
    float               m_value;        // value of black degree
} VSNET_BLACK_VALUE;

typedef struct
{
    VSNET_BLACK_VALUE   m_report[10];   // report value of analysis for black degree
} VSNET_BLACK_REPORT;

typedef struct
{
    int     m_state;         // state: open,close
    int     m_limittime;     // system limit times(hour)
    int     m_runedtime;     // device runned times(hour��only get valid)
} VSNETYWDEVRUNTIME;

typedef struct
{
    unsigned char   m_islock;          // is lock the disk
    unsigned char   m_reserved[3];     // reservation
} VSNETBUFFLOCK;

typedef struct
{
    unsigned short  m_serport;
    unsigned short  m_webport;
    unsigned short  m_rtspport;
    unsigned short  m_p2pport;
} VSNETCDHCPORT;

typedef struct
{
    unsigned int    m_sigpercent;       // signal power
    unsigned int    m_rx_byte;          // accepted flow
    unsigned int    m_tx_byte;          // sent flow
} VSNETSIGAND3GFLOW;

typedef struct
{
    float           m_gpsvx;
    float           m_gpsvy;
    int             m_gpsvsout;
    float           m_gpsvspeed;
    float           m_gpsvheight;
    char            m_gpsvtime[32];
} VSNETHZFLGPSINFO;

// Sensor������
typedef struct
{
	unsigned short  badpixelcount;      // �豸����ʵ�ʼ��Ļ�����������ʱ������
	unsigned short  badpixelcountmin;   // �û����ü�����С������
	unsigned short  badpixelcountmax;   // �û����ü�����󻵵���
    unsigned short  reserved;           // ����
} VSNET_BADPIXEL_RET;

// GZJieWei Parameter = VSNETGZJWUIDHEADER + Data
typedef struct
{
    int   m_Mask1;       // MSGHEAD_MASK1: 0X280028
    int   m_Vision;      // message version: current = 1
    int   m_MgsType;     // message type: m_MgsType = 8079
    int   m_ErrorCode;   // message status code
    int   m_DataSize;    // message data size: max size = 32 bytes
    short m_Ex1;         // extension 1
    short m_Ex2;         // extension 2
    int   m_Mask2;       // MSGHEAD_MASK2: 0X280028
} VSNETGZJWUIDHEADER;

// GZJieWei Parameter
typedef struct
{
    VSNETGZJWUIDHEADER m_MsgHead;
    char               m_MsgData[32];
} VSNETGZJWUIDPARAM;

// beijing huatuo
typedef struct
{
    int     m_bEnable;  // enable watcher, 1 enable, 0 disable
    int     m_iTime;    // check time > 0
    int     m_iPreset;  // preset number
} VSNETBJHTPTZWATCHER;

#define VSNET_MAXRESOLUTIONNUM    100    // ֧�ֵ������Ƶ�ֱ��ʸ���

// DVR��VO�ӿڶ���
typedef enum
{
    ENUM_VSNET_VO_VGA = 0,     // VO��VGA�ӿ�
    ENUM_VSNET_VO_HDMI = 1     // VO��HDMI�ӿ�
} ENUM_VSNET_DVRVO;

// DVR�ĵ���VO���ò���
typedef struct
{
    unsigned char  m_bSupport;                                  // �Ƿ�֧�ָ�VO�ӿڣ�ֻ�ܻ�ȡ����0-��֧�֣�1-֧��
    unsigned char  m_supportResolution[VSNET_MAXRESOLUTIONNUM]; // ֧�ֵķֱ��ʣ�ֻ�ܻ�ȡ��,��������ENUM_VSNET_VIDEO_RESOLUTION�����˳��,һ���ֽڴ���һ���ֱ����Ƿ�֧�֣�1-֧�֣�0-��֧��
    unsigned char  m_bEnable;                                   // �Ƿ����øýӿڣ�ֻ��֧�ָýӿ�ʱ���������ã�0-��֧�֣�1-δ���ã�2-����
    unsigned char  m_indentation;                               // VO������ϵ����ֻ��֧�ָýӿ�ʱ���������÷�Χ0~255��(��δʹ��)
    unsigned char  m_resolution;                                // ��ǰ�ķֱ��ʣ�ֻ��֧�ָýӿ�ʱ���������ã�ȡֵ��������ENUM_VSNET_VIDEO_RESOLUTION����
} VSNET_DVRVOSETTS;

// DVR��VO���ò���
typedef struct
{
    VSNET_DVRVOSETTS m_vointerface[VSNET_DVR_MAXVONUM];         // DVR��VO�������ã�Ŀǰ���֧��VSNET_DVR_MAXVONUM��VO�ӿڣ��ӿڰ�������ENUM_VSNETVO�Ķ��壬0-VGA��1-HDMI
} VSNET_DVRVOPARAM;

/***********************�´洢�ṹ��*********************************/
//Ӳ������
typedef enum {
    VS_DISK_TYPE_RW,            /**< ��д�� */
    VS_DISK_TYPE_RO,            /**< ֻ���� */
    VS_DISK_TYPE_RD,            /**< ������ */
    VS_DISK_TYPE_ALL,           /**< �������� */
    VS_DISK_TYPE_BUTT,          /**< ��Чֵ */
}VS_DISK_TYPE_E;

typedef struct
{
    int          m_diskno[16];      /**< Ӳ�̺Ŷ�Ӧ���� ��ͨ����ȡֵ [1-HD_MAXDISKNUM],��������ȡֵ-1*/
    int          m_chno[64];          /**< ͨ���Ŷ�Ӧ���� ��ͨ����ȡֵ [1-HD_MAXDISKNUM],��������ȡֵ-1*/
}VS_GROUP_CFG_T;

typedef struct
{
    int             m_type;         /**< Ӳ�����ͣ�ע:��ʹ��VS_DISK_TYPE_E�����ֵ*/
    int             m_lock;         /**< Ӳ���Ƿ�����  LC_TRUE���� LC_FALSEδ����  */
}VS_DISK_ATTR_T;

//Ӳ������
typedef struct
{
    VS_DISK_ATTR_T      m_disk[16];
}VS_DISK_CFG_T;

//�洢����������Ϣ
typedef struct
{
    VS_GROUP_CFG_T      m_groupcfg;        /**< ��������  */
    VS_DISK_CFG_T       m_dattrcfg;        /**< Ӳ������  */
}VS_STORAGE_CFG_T;

#define VS_SMART_ATTRIBUTES   30    
#define VS_SMART_ATTRNAMELEN  32    
#define VS_SMART_ATTRRAWVAL   32    

typedef struct
{
    unsigned char       m_id;
    unsigned char       m_curr;
    unsigned short      m_flags;
    unsigned char       m_worst;
    unsigned char       m_thresh;
    char                m_reserv[2];
    unsigned char       m_name[VS_SMART_ATTRNAMELEN];
    unsigned char       m_rawval[VS_SMART_ATTRRAWVAL];
}VS_SMART_ELEM_T;

//Ӳ��SMART��Ϣ
typedef struct
{
    int                     m_enabled;                      /**< 0��֧��SMART��1֧��SMART */
    unsigned int            m_version;
    VS_SMART_ELEM_T         m_smart[VS_SMART_ATTRIBUTES];
}VS_SMART_INFO_T;


// for DVR(LC78XX) ---add by buwp,2010-6-11
/**********************************  DVR GUI ADD *****************************************/
typedef struct
{
    unsigned char  m_no;                     // the number of preseting position
    char           m_name[31];               // the name   of preseting position
} VSNET_PTZ_PRESET_NO_T;

typedef struct
{
    int                    m_num;            // Now, how many preseting position we have
    VSNET_PTZ_PRESET_NO_T  m_presetno[255];
} VSNET_PTZ_PRESET_T;                        // Save PTZ preseting position

typedef struct
{
    int                 m_usernum;     // how many user we have,now
    int                 m_groupnum;    // how many valid user group we have ,now
    VSNETDVRUSERGROUP   m_group[8];    // 8 groups, initialize 4 groups  4 are reserved
    VSNETDVRUSER        m_user[32];    // 32 users, initialize 4 users
} VSNET_SYSUSER_T;

typedef struct
{
    char m_status[32];                 // the status of user(0:disbale, 1:enable)
    VSNET_SYSUSER_T m_user;
} VSNETDVRSYSUSER_EX;                  // extent user info(add the stauts of user)

typedef struct
{
    int             m_hdisk_attrib;         // disk attribute 0:default(read/write); 1:redundance ; 2:readonly
    char            m_hdisk_serialno[32];   // disk serial id
    int             m_resev[40];            // reserved
} VSNETDISKPARAM;

typedef struct
{
    int             m_disk_count;           // disk count
    VSNETDISKPARAM  m_diskparam[16];        // disk param
    int             m_disk_reduflag[64];    // disk redundance single, by channels
} VSNETRECORDDISKPARAM;

typedef struct
{
    int     m_type;                         // contorl type
    int     m_value;                        // speed or address; CVT: H
    int     m_paramfirst;                   // 3D:speed for H; CVT: V
    int     m_paramsecond;                  // 3D:speed for V; CVT: speed for H
    int     m_paramthird;                   // 3D:zoom parameter; CVT: speed for V
} VSNETDVRPTZ;

typedef struct
{
    int     m_zoom;                         // amplification factor
    int     m_X;                            // centre coordinate X
    int     m_Y;                            // centre coordinate Y
} VSNET_PTZCTRL_ZOOM;

typedef struct
{
    int              m_audio_type;             // audio type
    int              m_audio_bitrate;          // bit rate: 16K,24K,32K,40K for G726
    int              m_audio_samplerate;       // sample rate
    int              m_audio_bitwidth;         // bitwidth
} VSNETAUDIO;

typedef struct
{
    unsigned char timer;       // 0��HIDE 1��MM:SS:mm(00:00:00)2��HH:MM:SS(00:00:00)
    unsigned int  positionx;   // XPOS
    unsigned int  positiony;   // YPOS
} CHANNELTIMEROSD;

// SHTY
typedef struct
{
    int             m_audio_timerec;   // enable flag
    int             m_packtime;        // package time
    TIMELIST        m_timeList;        // capture time
} VSNETVIDEOTIMEREC;

// SHTY
typedef struct
{
    unsigned int  m_recodch[8][16];
} VSNETSHTYALARMAUDIO;

// SHTY
typedef struct
{
    unsigned int  m_capTime[8];
} VSNETSHTYALARMCAPTIME;

typedef struct
{
    int m_denoise;         // tvp5158 denoise level
    int m_reseved;         // reserved
} VSNET_TVP5158_DENOISE;

/**********************************  DVR GUI END *****************************************/


/**********************************  NVR ͨ���豸������� *****************************************/	

//NVR ֧�ֵķֱ�������
typedef enum
{
	VSNET_NVR_FORMAT_16F,
	VSNET_NVR_FORMAT_8F,
	VSNET_NVR_FORMAT_8H,
} VSNET_NVR_FORMAT_ENUM;

typedef struct
{
	VSNET_NVR_FORMAT_ENUM nNvrType;      //NVR ֧�ֵķֱ������� 
} VSNET_NVR_FORMAT_TYPE;

typedef struct
{
    char            m_szSerName[32];     //server name
    char            m_szSerIp[20];       //server ip address
    unsigned short  m_nSerport;          //server port
    unsigned short  m_nChannel;          //the channel of server to be connected
    unsigned short  m_nTransType;        //the media transport type tcp/udp/multi
    unsigned short  m_nChlinkState;      //channel link state
    unsigned short  m_nImgHeight;        //image height
    unsigned short  m_nImgWidth;         //image width
    char            m_szUserName[20];    //server user name
    char            m_szPasswd[20];      //server password
    int             m_reserved1;         //reserved1
    int             m_reserved2;         //reserved2
} VSNET_NVR_DEVINFO;

typedef struct
{
    char            m_szSerName[32];     //server name
    char            m_szSerIp[100];       //server ip address
    unsigned short  m_nSerport;          //server port
    unsigned short  m_nChannel;          //the channel of server to be connected
    unsigned short  m_nTransType;        //the media transport type tcp/udp/multi
    unsigned short  m_nChlinkState;      //channel link state
    unsigned short  m_nImgHeight;        //image height
    unsigned short  m_nImgWidth;         //image width
    char            m_szUserName[20];    //server user name
    char            m_szPasswd[20];      //server password
    int             m_reserved1;         //reserved1
    int             m_reserved2;         //reserved2
} VSNET_NVR_DEVINFO_EX;

typedef enum 
{
    NVR_FORMAT_NONE  = 0,
    NVR_FORMAT_D1    = 1,
	NVR_FORMAT_720P  = 3,
	NVR_FORMAT_1080P = 7,
	NVR_FORMAT_300W  = 8,
	NVR_FORMAT_500W  = 9,
} VSNET_NVR_FORMAT_VALUE;

//NVR ���豸����Ϣ
typedef struct
{
    int                     m_bEnable;        //channel been used ?
    VSNET_NVR_FORMAT_VALUE  m_nMaxSize;       //max video format
    VSNET_NVR_DEVINFO       m_vsDevInfo;      //channel info
} VSNET_NVR_CHINFO;

//NVR ���豸����Ϣ
typedef struct
{
    int                     m_bEnable;        //channel been used ?
    VSNET_NVR_FORMAT_VALUE  m_nMaxSize;       //max video format
    VSNET_NVR_DEVINFO_EX       m_vsDevInfo;      //channel info
} VSNET_NVR_CHINFO_EX;

typedef struct
{
    VSNET_NVR_CHINFO   		m_channel[VSNET_DVR_MAXCH];      //channel info,��ס�鿴,��VSNET_DVR_MAXCH�ı�ʱ�ǵ��޸�
} VSNET_NVR_CHANINFO;

typedef struct
{
    VSNET_NVR_CHINFO_EX   		m_channel[VSNET_DVR_MAXCH];      //channel info,��ס�鿴,��VSNET_DVR_MAXCH�ı�ʱ�ǵ��޸�
} VSNET_NVR_CHANINFO_EX;


typedef struct
{
    int                     m_maxrecv;      //���������
    int                     m_maxsend;      //����ʹ���
    int                     m_currecv;      //��ǰ�������
    int                     m_cursend;      //��ǰ���ʹ���
    int                     m_reserved1;
    int                     m_reserved2;
    int                     m_reserved3;
    int                     m_reserved4;
} VSNET_NVR_BANDWIDTH;

#define NVR_MAX_LOGICHS 64

//ͨ�����Ͳ����ṹ��
typedef struct 
{
    int m_modify[NVR_MAX_LOGICHS];	//����ͨ��, 1->����, 0->��ֹ
    int m_chtype[NVR_MAX_LOGICHS];    //ͨ�����ͣ�ģ��->1������->2��δʹ��->0
}VSNET_NVR_CHCTRL_CHTYPE_S;

#define NVR_MAX_SUPPORTRANGE 16

//ͨ��֧�ֱַ��ʽṹ��
typedef struct
{
	int m_support[NVR_MAX_SUPPORTRANGE];        //�����±��ʾ��Ӧ�ֱ��ʡ�������ֵ��ʾ�ֱ����Ƿ�֧��(0:��֧�֣�1:֧��)
	//�����±�:0:D1  1:720P 2:1080P
}VSNET_NVR_CHANNELFORMAT;

/**********************************  NVR ͨ���豸������� ��***************************************/

/* ˫��������ģʽ���� */
typedef struct
{
    int m_workmode;     /* ����ģʽѡ��0->���ؾ���, 1->�����ݴ�, 2->�������� */
    int m_defaultgw;    /* Ĭ������ѡ��0->LAN1, 1->LAN2 */
}VSNET_NETCARD_WORKMODE_S;

/********************************** 88258 STRUCT *****************************************/

#define MAX_CLIP_NUM 10
#define MAX_FAN_NUM  3                // fan number

// CARD TYPE
typedef enum
{
    CLIP_TYPE_MASTER    = 0,          // master card
    CLIP_TYPE_DEC       = 1,          // decoder card
    CLIP_TYPE_ENC_D1    = 2,          // D1
    CLIP_TYPE_ENC_720P  = 3,          // 720P
    CLIP_TYPE_ENC_1080P = 4,          // 1080
    CLIP_TYPE_ALARM     = 5,          // ALARM
    CLIP_TYPE_DEVICE    = 6,          // DEVICE
} APP_CLIP_TYPE;

typedef enum
{
    CLIP_SLOT_SUB0      = 0,          // CLIP1
    CLIP_SLOT_SUB1      = 1,          // CLIP2
    CLIP_SLOT_SUB2      = 2,          // CLIP3
    CLIP_SLOT_SUB3      = 3,          // CLIP4
    CLIP_SLOT_SUB4      = 4,          // MASTER
    CLIP_SLOT_SUB5      = 5,          // CLIP5
    CLIP_SLOT_SUB6      = 6,          // CLIP6
    CLIP_SLOT_SUB7      = 7,          // CLIP7
    CLIP_SLOT_MASTER    = 8,          // CLIP8
    CLIP_SLOT_MACHINE   = 9,          // ALARM
    CLIP_SLOT_ALARM     = 10,         // reserved
} APP_CLIP_NO;

typedef struct
{
    int        m_temperature;            // Temperature
    int        m_humidity;               // humidity
} VSNETHUMITUPARAM, *PVSNETHUMITUPARAM;  // Temperature and humidity


typedef struct
{
    unsigned int     m_speed;            // fan speed�� r/s
    unsigned char     m_state;           // state
    unsigned char     m_reseved[3];      // reserved
} VSNETFANSTATE, *PVSNETFANSTATE;        // fan state


typedef struct
{
    unsigned char     m_isexist;         // Be Exist
    unsigned char     m_type;            // card type
    unsigned char     m_state;           // state
    unsigned char     m_reseved[5];      // reserved
} VSNETCLIPSTATE, *PVSNETCLIPSTATE;      // clip card state


typedef struct
{
    VSNETCLIPSTATE    m_stotstate;       // slot state:master��clip��slot��alarm
    VSNETHUMITUPARAM  m_humitu;          // Temperature and humidity of card
} VSNETBANCARDINFO, *PVSNETBANCARDINFO;


typedef struct
{
    unsigned char     m_powerstate;                 // power state
    unsigned char     m_reseved[7];                 // reserved
    VSNETFANSTATE     m_fanstate[MAX_FAN_NUM];      // fan state
    VSNETBANCARDINFO  m_bancardinfo[MAX_CLIP_NUM];  // card information
} VSNETDECVICEPARAM, *PVSNETDECVICEPARAM;
/************************************ 88258 END ******************************************/

typedef struct
{
    int    m_clipstate;      // clip card state
    int    m_clipnum;        // clip card num
} VSNETUPDATESLOT;

// NAS state Information
#define NAS_STATE_UNENABLE      1
#define NAS_STATE_UNCONNECT     2
#define NAS_STATE_CONNECT       4
#define NAS_STATE_INUSE         8

typedef enum
{
    MNT_CIFS,
    MNT_NFS,
} MNTFILETYPE;

typedef struct
{
    char m_NASenable;               // Enable NAS
    char m_reseved[3];              // reseved
    char m_NASip[32];               // NAS IP
    char m_NASpath[80];             // NAS path
    char m_NASuser[40];             // NAS username
    char m_NASpassword[40];         // NAS password
    MNTFILETYPE  mnt_type;
} VSNETNASINFO;

typedef struct
{
    int  m_state;                   // Disk State 1��not use 2��Unlink  4.linked 8.on using
    int  m_totalsize;               // Disk Size
    int  m_freesize;                // free size
} VSNETNASSTATE;

typedef struct
{
    VSNETNASINFO  m_NASinfo[8];
    VSNETNASSTATE m_NASstate[8];
} VSNETNASPARAM;

typedef struct
{
    char              m_url[32];    // IP address
    int               m_port;       // data port
} VSNETINFONET;

typedef struct
{
    VSNETINFONET      m_netinfo[4];    // net information
    char              m_sername[40];   // server name
    char              m_username[20];  // user name
    char              m_password[20];  // password
    int               m_cardnum;       // card number
    unsigned char     m_isexist;       // card be exist
    unsigned char     m_type;          // card type
    unsigned char     m_state;         // card state
    unsigned char     m_reseved;       // reseved
} VSNETCARDINFO;

typedef struct
{
    VSNETCARDINFO m_cardinfo[8];
} VSNETCARDPARAM;

// ̽ͷ��ǰ״̬
typedef struct
{
    int m_nStatus[16]; //0 �� 1�պ� -1��Ч
} VSNET_ALARM_IN_STATUS;

// �������״̬
typedef struct
{
	BYTE m_nStatus[8]; //����1 ����2
} VSNET_ALARM_OUT_STATUS;

// ��������״̬
typedef struct
{
	BYTE m_nStatus[8]; //����1 ����2
} VSNET_ALARM_IN_SET;  



/*******************************�ռ���������******************************/
//���б�����������־�Ľṹ����m_nMark��ȡֵ

/************************��********************��*****************/
/*������*/
#define LOG_ALARM_MAJOR 0x1
/*������*/
#define LOG_ALARM_MINOR_MOTIONDEC_START         0x101   /* �ƶ���⿪ʼ*/
#define LOG_ALARM_MINOR_MOTIONDEC_STOP          0x111   /* �ƶ�������*/
#define LOG_ALARM_MINOR_VIDEOLOST_START         0x102   /* ��Ƶ��ʧ��ʼ*/
#define LOG_ALARM_MINOR_VIDEOLOST_STOP          0x112   /* ��Ƶ��ʧ����*/
#define LOG_ALARM_MINOR_SENSOR_START            0x103   /* ̽ͷ������ʼ*/
#define LOG_ALARM_MINOR_SENSOR_STOP             0x113   /* ̽ͷ��������*/
#define LOG_ALARM_MINOR_HIDEALARM_START         0x104   /* �ڵ�������ʼ*/
#define LOG_ALARM_MINOR_HIDEALARM_STOP          0x114   /* �ڵ���������*/
#define LOG_ALARM_MINOR_PUSENSOR_START          0x105   /* ǰ��̽ͷ������ʼ*/
#define LOG_ALARM_MINOR_PUSENSOR_STOP           0x115   /* ǰ��̽ͷ��������*/

/************************��********************��*****************/
/*������*/
#define LOG_EXCEPTION_MAJOR 0x2
/*������*/
#define LOG_EXCEPTION_MINOR_ILLEGALACCESS               0x201   /* �Ƿ�����*/
#define LOG_EXCEPTION_MINOR_HD_FULL                     0x202   /* Ӳ����*/
#define LOG_EXCEPTION_MINOR_HD_ERROR                    0x203   /* Ӳ�̴���*/
#define LOG_EXCEPTION_MINOR_NET_BROKEN                  0x204   /* ���߶�*/
#define LOG_EXCEPTION_MINOR_NET_TIMEOUT                 0x205   /* ���粻ͨ*/
#define LOG_EXCEPTION_MINOR_VIDEOMOODERROR              0x206   /* ��Ƶ��ʽ����*/
#define LOG_EXCEPTION_MINOR_IPADDRCONFLICT              0x207   /* IP��ַ��ͻ*/
#define LOG_EXCEPTION_MINOR_NODISK                      0x208   /* ��Ӳ��*/

#define LOG_EXCEPTION_MINOR_HD_TOOMANYBADSECTOR         0x209   /* ������̫�� */
#define LOG_EXCEPTION_MINOR_HD_DISKUNHEALTH             0x210   /* ����״̬������ */
#define LOG_EXCEPTION_MINOR_HD_DISKREMOVE               0x211   /* Ӳ�̱���������ȥ */

#define LOG_EXCEPTION_MINOR_VIDEOEXCEPTION              0x212   /* ��Ƶ�쳣 */
#define LOG_EXCEPTION_MINOR_CPUEXCEPTION      	        0x213   /* CPU �쳣 */
#define LOG_EXCEPTION_MINOR_NETEXCEPTION                0x214   /* ���� �쳣 */
#define LOG_EXCEPTION_MINOR_NOUSEABLEDISK               0x215   /* �޿���Ӳ��*/

#define LOG_EXCEPTION_MINOR_MACHINE_FAN_STOP            0x216   /* ����ֹͣת��*/
#define LOG_EXCEPTION_MINOR_MACHINE_FAN_SINGULARITY     0x217   /*�����쳣*/
#define LOG_EXCEPTION_MINOR_MACHINE_BANCARD_SINGULARITY 0x218  /*�忨�쳣*/

#define LOG_EXCEPTION_MINOR_GET_VIDEOLOST_FAILED        0x219   /*��ȡ��Ƶ��ʧ״̬ʧ��*/

#define LOG_EXCEPTION_MINOR_REBOOT                      0x220   /* �豸�쳣���� */
#define LOG_EXCEPTION_MINOR_DEVICE_RESOUT               0x221   /* �ֱ��ʳ��� */
#define LOG_EXCEPTION_MINOR_DEVICE_USERERROR            0x222   /* �û���������� */
#define LOG_EXCEPTION_MINOR_DEVICE_NORMAL               0x223   /* �������ӳɹ� */
#define LOG_EXCEPTION_MINOR_DEVICE_USEROVER             0x224   /* ������ͨ����Ա */
#define LOG_EXCEPTION_MINOR_DEVICE_SHUT                 0x225   /* ���ӶϿ� */
/************************��********************��*****************/
/*������*/
#define LOG_OPERAT_MAJOR 0x3
/*������*/
#define LOG_OPERAT_MINOR_START_DVR                      0x301   /* ����*/
#define LOG_OPERAT_MINOR_STOP_DVR                       0x302   /* �ػ�*/

#define LOG_OPERAT_MINOR_LOCAL_LOGIN                    0x303   /* ���ص�½*/
#define LOG_OPERAT_MINOR_LOCAL_CFG_PARM                 0x304   /* �������ò���*/
#define LOG_OPERAT_MINOR_REMOTE_GET_PARM                0x305   /* Զ�̻�ò���*/
#define LOG_OPERAT_MINOR_LOCAL_START_REC                0x306   /* ���ؿ�ʼ¼��*/
#define LOG_OPERAT_MINOR_LOCAL_STOP_REC                 0x307   /* ����ֹͣ¼��*/
#define LOG_OPERAT_MINOR_LOCAL_PLAYBYFILE               0x308   /* ���ذ��ļ��ط�*/
#define LOG_OPERAT_MINOR_LOCAL_PLAYBYTIME               0x309   /* ���ذ�ʱ��ط�*/
#define LOG_OPERAT_MINOR_LOCAL_PTZCTRL                  0x30A   /* ������̨����*/
#define LOG_OPERAT_MINOR_LOCAL_PREVIEW                  0x30B   /* ����Ԥ��*/
#define LOG_OPERAT_MINOR_LOCAL_UPGRADE                  0x30C   /* ��������*/
#define LOG_OPERAT_MINOR_LOCAL_COPYFILE                 0x30D   /* ���ر����ļ�*/
#define LOG_OPERAT_MINOR_REMOTE_ARM                     0x30E   /* ����*/
#define LOG_OPERAT_MINOR_REMOTE_REBOOT                  0x30F   /* Զ������*/
#define LOG_OPERAT_MINOR_START_VT                       0x310   /* ��ʼ�����Խ�*/
#define LOG_OPERAT_MINOR_STOP_VT                        0x311   /* ֹͣ�����Խ�*/

#define LOG_OPERAT_MINOR_MACHINE_BANCARD_ADD            0x312   /*�Ӱ忨����*/
#define LOG_OPERAT_MINOR_MACHINE_BANCARD_DEL            0x313   /*�Ӱ忨�γ�*/

#define LOG_OPERAT_MINOR_FORMATDISK				        0x314   /* ��ʽ��Ӳ��*/
#define LOG_OPERAT_MINOR_FORMATDISK_FAILED              0x315   /* ��ʽ��Ӳ��ʧ��*/
#define LOG_OPERAT_MINOR_DISK_LOCK				        0x316   /* ����Ӳ��*/
#define LOG_OPERAT_MINOR_DISK_UNLOCK                    0x317   /* ����Ӳ��*/

#define LOG_OPERAT_MINOR_START_LOOP                     0x318   /* ��ʼ��Ѳ*/
#define LOG_OPERAT_MINOR_STOP_LOOP                      0x319   /* ֹͣ��Ѳ*/
#define LOG_OPERAT_MINOR_START_AUDIO                    0x320   /* ��ʼ��Ƶ*/
#define LOG_OPERAT_MINOR_STOP_AUDIO                     0x321   /* ֹͣ��Ƶ*/
#define LOG_OPERAT_MINOR_START_NETWORK_TALK             0x322   /* ����Խ�����*/
#define LOG_OPERAT_MINOR_STOP_NETWORK_TALK              0x323   /* ����Խ�ֹͣ*/
#define LOG_OPERAT_MINOR_LOCAL_PLAY_STOP                0x324   /* ���ػطŽ���*/
#define LOG_OPERAT_MINOR_LOCAL_START_TIMEREC            0x325   /* ��ʼ���ض�ʱ¼��*/
#define LOG_OPERAT_MINOR_LOCAL_STOP_TIMEREC             0x326   /* ֹͣ���ض�ʱ¼��*/
#define LOG_OPERAT_MINOR_LOCAL_START_HANDREC            0x327   /* ��ʼ�����ֶ�¼��*/
#define LOG_OPERAT_MINOR_LOCAL_STOP_HANDREC             0x328   /* ֹͣ�����ֶ�¼��*/
#define LOG_OPERAT_MINOR_DEVICE_ADD                     0x32A   /* ����豸*/
#define LOG_OPERAT_MINOR_DEVICE_DEL                     0x32B   /* ɾ���豸*/
#define LOG_OPERAT_MINOR_DEVICE_MODIFY                  0x32C   /* �����豸*/
#define LOG_OPERAT_MINOR_LOG_CLS                        0x32D   /* �����־*/
#define LOG_OPERAT_MINOR_USER_ADD                       0x32E   /* ����û�*/
#define LOG_OPERAT_MINOR_USER_DEL                       0x32F   /* ɾ���û�*/
#define LOG_OPERAT_MINOR_USER_MODIFY                    0x330   /* �����û�*/
#define LOG_OPERAT_MINOR_TIME_MODIFY                    0x331   /* �޸�ϵͳʱ��*/
#define LOG_OPERAT_MINOR_ZONE_MODIFY                    0x332   /* �޸�ϵͳʱ��*/
#define LOG_OPERAT_MINOR_HARDDEFAULT                    0x335   /* Ӳ���ָ�Ĭ�� */
#define LOG_OPERAT_MINOR_LOADDEFAULT                    0x336   /* ���ز��������ָ�Ĭ�� */
#define LOG_OPERAT_MINOR_SAVEPARAM                      0x337   /* ������� */
#define LOG_OPERAT_MINOR_DEFAULTPARAM                   0x338   /* �ָ�Ĭ�ϲ��� */

#define LOG_OPERAT_MINOR_REMOTE_LOGIN                   0x340   /* Զ�̵�¼ */

enum SEARCH_DIARY_MARK
{
    SEARCH_DIARY_MARK_TYPE     = 1 << 0, //��־������ ��Ч
    SEARCH_DIARY_MARK_TYPE_SUB = 1 << 1, //��־������ ��Ч
    SEARCH_DIARY_MARK_CHANNEL  = 1 << 2, //ͨ������Ч
    SEARCH_DIARY_MARK_CARDNUM  = 1 << 3, //�忨����Ч
    SEARCH_DIARY_MARK_TIME     = 1 << 4, //ʱ����Ч 
};

//���б�����������־�Ľṹ��
typedef struct
{
    int m_nMark;                      //�涨��Щֵ��Ч ��SEARCH_DIARY_MARK
    int m_nType;                      //��־������
    int m_nTypeSub;                   //��־������ 
    int m_nChannel;                   //ͨ���� ���ڼ��б�����0-255
    VSNETDIARY_NETTIME vsnStratTime;  //��ʼʱ��
    VSNETDIARY_NETTIME vsnStopTime;   //����ʱ��
    char m_szReseved[64];             //����
} VSNET_SEARCH_DIARY;

//���б�����������־����
#define MAXDIARYNUM 256
typedef struct
{
    int m_nMark;                         // �涨��Щֵ��Ч ��SEARCH_DIARY_MARK
    int m_nChannel;                      // ͨ���� ���ڼ��б�����0-255 ������忨��
    int m_nType;                         // ��־������
    int m_nTypeSub;                      // ��־������     
    VSNETDIARY_NETTIME vsnTime;          // ����ʱ��
    char m_szReseved[12];                // ����
} VSNET_DIARY_INFO_CONTENT;

typedef struct
{
    int m_nDiaryNum;                     //VSNET_DIARY_INFO_CONTENT��Ч����
    VSNET_DIARY_INFO_CONTENT m_vdicInfo[MAXDIARYNUM];
} VSNET_DIARY_INFO;
/*******************************�ռ��������� ��**************************/


/************************************ 88258 END ******************************************/

/*
* ����ʶ��ṹ���壬��������DVS
* �޸�ʱ�䣺2011-03-23
* �޸��ˣ�zhangdw
*/

// �豸��Ϊ��������
typedef enum
{
    VCA_ABILITY_BKPLATEANALYSIS = (1 << 0),       // ����ʶ��(ʶ�����ڹ��������)
    VCA_ABILITY_PLATEANALYSIS = (1 << 1),         // ����ʶ��(ʶ������ǰ���豸��)
	VCA_ABILITY_INTELLIGENTANALYSIS = (1 << 2),   // ����������Ϊ����(�����߿�Խ���������֡������뿪���ǻ�)
} ENUM_VCA_ABILITYS;

typedef struct
{
    int ability_type;  // ��Ϊ������������
} VSNET_VCA_ABILITY;

/*
* ���ܳ���ʶ��ṹ���壬��������DVS
* �޸�ʱ�䣺2011-03-22
* �޸��ˣ�zhangdw
*/
/************************************ ���ܳ��� ��ʼ ***************************************/
#ifndef MAX_VCA_PLATERECT_NUM
#define MAX_VCA_PLATERECT_NUM  4     // ���Ʒ�����೵����
#endif

#ifndef MAX_VCA_PLATECAP_NUM
#define MAX_VCA_PLATECAP_NUM  3      // ���Ʒ������ץ������
#endif

#ifndef MAX_VCA_PLATERSTR_NUM
#define MAX_VCA_PLATERSTR_NUM 12     // ���Ʒ������ƺ��� �ַ����� 
#endif

#ifndef VCA_PLATE_JPGEND
#define VCA_PLATE_JPGEND 0xABABAAB
#endif

typedef struct
{
    short left;         // ������Ϣ���ϽǺ�����
    short right;        // ������Ϣ���½Ǻ�����
    short top;          // ������Ϣ���Ͻ�������    
    short bottom;       // ������Ϣ���½�������
} VSNET_VCA_PLATERECT;

typedef struct
{
    float left;         // �����������ϽǺ�����
    float top;          // �����������Ͻ�������
    float right;        // �����������½Ǻ�����
    float bottom;       // �����������½�������
} VSNET_VCA_PLATERECTF;

typedef struct
{
    unsigned int        version;                                // ����ʶ����Ϣ�汾��0x01-V1.0
    unsigned int        time_stamp;                             // ����ʱ������Ժ���Ϊ��λ
    unsigned int        pos_num;                                // ��ǰ֡��λ���ĳ�����Ŀ
    VSNET_VCA_PLATERECT pos_rect[MAX_VCA_PLATERECT_NUM];        // ��ǰ֡��λ���ĳ�����ԭʼͼ���е�λ��
    unsigned char       recog_num;                              // ʶ����ĳ��ƺ���Ŀ
    unsigned char       reserverd1[3];                          // ������������Ϊ0
    unsigned int        recog_gmttime[MAX_VCA_PLATERECT_NUM];   // ʶ�𵽵ĳ���������ֵľ���ʱ�䣬��1970��1��1�� 00:00:00 ��ʼ������,ʱ����GMTʱ������
    unsigned char		recog_number[MAX_VCA_PLATERECT_NUM][MAX_VCA_PLATERSTR_NUM];  // ʶ������ĳ����ַ�
    unsigned char		recog_trust[MAX_VCA_PLATERECT_NUM];		// �����ַ������Ŷ�
    unsigned char       recog_brightness[MAX_VCA_PLATERECT_NUM];// ��������ֵ1 ~ 255
    unsigned char		recog_color[MAX_VCA_PLATERECT_NUM];		// ������ɫ 0:����1:�Ƶ�2:�׵ף�����3:�׵ף�����4:����5:δ֪
    unsigned char       recog_direction[MAX_VCA_PLATERECT_NUM];	// �����˶����� 0:δ֪���� 1:���ƴ��ϵ����˶� 2:��ʾ���ƴ��µ����˶�
    unsigned char       recog_type[MAX_VCA_PLATERECT_NUM];		// �������� 1:������������ 2:С���������� 16:������������ 23:������������ 99:δ֪
    unsigned int        recog_speeds[MAX_VCA_PLATERECT_NUM];	// �����˶��ٶ�
	unsigned char       recog_carcolor[MAX_VCA_PLATERECT_NUM];	// ������ɫ 0:��ɫ 1:���� 2:��ɫ 3:��ɫ 4:��ɫ 5:��ɫ 6:��ɫ 7:��ɫ 8:��ɫ 9:��ɫ 99:���� 255: δ����ʶ��
} VSNET_VCA_PLATEINFO;

typedef struct
{
    unsigned int    version;                                // ����ʶ��ץ����Ϣ�汾��0x01-V1.0
    unsigned char   recog_num;                              // ʶ����ĳ��ƺ���Ŀ
    unsigned char   cap_num;                                // ʶ��ץ�ĵ�����
    unsigned char   reserverd1[2];                          // ������������Ϊ0
    unsigned int    recog_gmttime[MAX_VCA_PLATERECT_NUM];   // ʶ�𵽵ĳ���������ֵľ���ʱ�䣬��1970��1��1�� 00:00:00 ��ʼ������,ʱ����GMTʱ������
    unsigned char   recog_number[MAX_VCA_PLATERECT_NUM][MAX_VCA_PLATERSTR_NUM];  // ʶ������ĳ����ַ�
    unsigned char   recog_trust[MAX_VCA_PLATERECT_NUM];		// �����ַ������Ŷ�
    unsigned char   recog_brightness[MAX_VCA_PLATERECT_NUM];// ��������ֵ1 ~ 255
    unsigned char   recog_color[MAX_VCA_PLATERECT_NUM];		// ������ɫ 0:����1:�Ƶ�2:�׵ף�����3:�׵ף�����4:����5:δ֪
    unsigned char   recog_direction[MAX_VCA_PLATERECT_NUM];	// �����˶����� 0:δ֪���� 1:���ƴ��ϵ����˶� 2:��ʾ���ƴ��µ����˶�
    unsigned char   recog_type[MAX_VCA_PLATERECT_NUM];		// �������� 1:������������ 2:С���������� 16:������������ 23:������������ 99:δ֪
    unsigned int    recog_speeds[MAX_VCA_PLATERECT_NUM];	// �����˶��ٶ�
	unsigned char   recog_carcolor[MAX_VCA_PLATERECT_NUM];	// ������ɫ  0:��ɫ 1:���� 2:��ɫ 3:��ɫ 4:��ɫ 5:��ɫ 6:��ɫ 7:��ɫ 8:��ɫ 9:��ɫ 99:���� 255: δ����ʶ��
} VSNET_VCA_PLATECAP;

typedef struct
{
    unsigned int        cap_gmttime;                        // ץ�ľ���ʱ�䣬��1970��1��1�� 00:00:00 ��ʼ������,ʱ����GMTʱ������
    VSNET_VCA_PLATERECT cap_pos[MAX_VCA_PLATERECT_NUM];     // ʶ�𵽵ĳ�����ץ��ͼƬ�е�λ��
    unsigned int        cap_size;                           // ץ�ĵ����ݴ�С�����ֽ�Ϊ��λ�����������ƶ�λ��Ϣ��С
} VSNET_VCA_PLATEDATA;

// ����ʶ��-���ƴ�С
typedef struct
{
    int plate_w_min;     // ������С��ȣ�������Ϊ��λ
    int plate_w_max;     // ��������ȣ�������Ϊ��λ
} VSNET_VCA_PLATEWIDTH;

// ����ʶ��Ĭ��ʡ��
typedef struct
{
	int trust_thresh;    //�Ŷȵ���ֵ���ڸ�ֵ ��Ĭ��ʡ�ݴ���

    // Ĭ��ʡ��:
    // ��36����37����38����39����40����41����42����43����44����45����46����47��
    // ��48����49����50����51����52����53����54����55����56��ԥ57����58����59��
    // ��60����61����62����63����64��³65����66
    char plate_chn_default[MAX_VCA_PLATERSTR_NUM];//Ĭ��ʡ���ַ�	
} VSNET_VCA_PLATECHNDEFAULT;

// ����ʶ��������
typedef struct
{
    unsigned char plate_chn_mask[64];
    // ��λ��ʾ���ĺ���ʶ������루����ַ�ʶ��ľ��ȣ���
    // 1-���θú���ʶ��0-��ʼ�ú���ʶ��
    // ���ֶ�Ӧ����˳�����£��Ӹߵ��ף���
    // �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ԥ �� �� �� �� �� �� �� ³ ��
    // ��Ŀǰֻ��31��ʡ�ݺ��֣�����λ�����Ժ���չ���຺�֣�
} VSNET_VCA_PLATECHNMASK;

// ����ʶ�����ģʽ
typedef enum
{
    VCA_PLATEDRAW_RECT = 0x01,         // ������ӳ���ʶ��Ŀ������
    VCA_PLATEDRAW_TARGET = 0x02,       // ������ӳ��ƶ�λ��
    VCA_PLATEDRAW_CAPRECT = 0x04,      // ץ�ĵ��ӳ���ʶ��Ŀ������
    VCA_PLATEDRAW_CAPTARGET = 0x08     // ץ�ĵ��ӳ��ƶ�λ��
} ENUM_VCA_PLATEDRAW;

// ����ʶ��ץ�Ĳ���
typedef enum
{
    VCA_PLATECAPMODE_QUALITY = 0,     // ץ�ķ�ʽ����������һ��
    VCA_PLATECAPMODE_LAST = 1         // ץ�ķ�ʽ������һ��
} ENUM_VCA_PLATECAPMODE;

// ����ͼƬ��������
typedef struct
{
    unsigned short cap_quality;       // ץ��ͼ��ѹ���ʣ�ȡֵ1~100����ֵԽ�߱�ʾ����Խ��
    unsigned short cap_num;           // ץ�ĵ�ͼ��������ȡֵ��Χ1~3
    unsigned short cap_mode;          // ץ�ķ�ʽ��0-��������һ�ţ�1-����һ��
    unsigned short cap_store;         // ץ��ͼƬǰ�˴洢ѡ�0-���洢��1-�洢
} VSNET_VCA_PLATECAPPARAM;

// ����ͼƬ�����ַ��������� �������ڳ���ʶ�����ģʽ������
typedef struct
{
    unsigned char bEnable;            // �Ƿ�����jpgͼƬ���ƺ������
    unsigned char reserverd[3];       // ����
    float         jpgosd_scale;       // �ַ���ʾ����0.5-2.0
    float         jpgosd_x;           // ���ӳ��Ƶ�x����
    float         jpgosd_y;           // ���ӳ��Ƶ�y����
} VSNET_VCA_PLATEJPGOSD;

// ����ģʽ
typedef struct
{
	int plate_draw;                   // ʶ����ӿ� ��ϸ��ENUM_VCA_PLATEDRAW
    int deskew_flag;                  // ����ʶ���Ƿ�Գ�������бУ��
} VSNET_VCA_PLATEMODE;

// ���ư汾
typedef struct
{
    char   m_szDspVersion[16];          //DSP�汾
    char   m_szDspDate[16];             //DSP����
    char   m_szPlateVersion[16];        //�㷨�汾
    char   m_szPlateDate[16];           //�㷨����
} VSNET_VCA_PLATEVERSION;

/************************************ ���ܳ��� ���� ***************************************/

/************************************ SXSD START ******************************************/
#define SXSD_PARAM_MEB_NUM           11
#define SXSD_PARAM_DATA_NUM          7

typedef enum
{
    SXSD_PARAM_METHANE_L = 0,        // ��Ũ�ȼ���     0-4%         x.xx
    SXSD_PARAM_OXYGEN,               // ����           0-25%        xx.x0
    SXSD_PARAM_CARBONM,              // һ����̼       0-1000ppm    xxxx
    SXSD_PARAM_CARBOND,              // ������̼       0-5%         x.xx
    SXSD_PARAM_TEMPERAT,             // �¶ȣ�����     -10��-+70��  xx.x0
    SXSD_PARAM_WATERPRESS,           // ˮѹ           0-9999Pa     xxxx(0.1-999.9KPa  xxx.x0  0.01-99.99MPa  xx.xx)
    SXSD_PARAM_WINDSPEED,            // ����           0.4��15m/s   xx.x0
    SXSD_PARAM_HYDROGEN,             // ����         0-100ppm     xxxx
    SXSD_PARAM_WATERLINE,            // ˮλ           ��ʱ����
    SXSD_PARAM_METHANE_H,            // ��Ũ�ȼ���     0%-100%      xxx.x0
    SXSD_PARAM_HUMIDITY              // ʪ��           0-100%       xxx
} ENUM_SXSD_PARAM;

typedef struct
{
    unsigned short   m_nDataState;   // ����״̬(����ʵʱ���ݴ���)(0.������ 1.���� 2.���� 3.�쳣)
    unsigned short   m_nReserverd;   // ����SXSD_PARAM_WATERLIN ������ʾ(0����ͨ 1��KP 2��MP)������ռʱ����
    int              m_nEvrmtValue;  // ��������ֵ (��С��λ ��ֵ����x100 ע:ֻ��һλС����0���룬��ʾʱ������ֵ��ʽ)
    int              m_nAlarmData;   // ����Ũ�� �±���ENUM_SXSD_PARAMָ��
	int              m_nTypeEvrmt;   // ��������ֵ��ʾvalue(0 - 6) ��7�����ݣ�����ÿ������7�����ͣ�
} SXSD_DATA_PARAM;

// ����SXSDʵʱ��������
typedef struct
{
    char             m_cAddressDis[20];                       // �ɼ����ص�(�������ڡ�����)
	int              m_nValueType[SXSD_PARAM_MEB_NUM];        // ��Ӧm_pEvrmtValue������(ֵ�� ENUM_SXSD_PARAMָ��)
    SXSD_DATA_PARAM  m_pEvrmtValue[SXSD_PARAM_MEB_NUM][SXSD_PARAM_DATA_NUM];  // ����ֵ ����11�飩
} SXSD_REAL_DATA_TEAP;

typedef struct
{
    SXSD_REAL_DATA_TEAP m_pRealData[2];                       //�ֱ��ʾ�������ݣ����ڡ����⣩
} VSNET_SXSD_REAL_DATA;

// ����SXSD�ı�����ֵ����
typedef struct
{
    char             m_cAddressDis[20];                       // �ɼ����ص�(�������ڡ�����)
    unsigned         m_nXcoordinate;                          // OSD���Ӵ�ֱ����ֵ
    unsigned         m_nYcoordinate;                          // OSD����ˮƽ����ֵ
	int              m_nValueType[SXSD_PARAM_MEB_NUM];        // OSD��������(0-6) 
	                                                          // (�磺m_nOsdOrder[1]=SXSD_PARAM_OXYGEN,m_nValueType[1]=1,
	                                                          // ��˵��OSDλ��2��ģ����Ϊ ����2)
    int              m_nOsdOrder[SXSD_PARAM_MEB_NUM];         // OSD����˳�� ֵΪENUM_SXSD_PARAMָ�� �������޼�¼Ϊ����ʾ
    int              m_nAlarmValue[SXSD_PARAM_MEB_NUM];       // ������Χֵ  �±���ENUM_SXSD_PARAMָ��
	int              m_nAlarmEnable[SXSD_PARAM_MEB_NUM];      // ������Ч��� �±���ENUM_SXSD_PARAMָ����-1δ�յ����ݣ�0������δ���ӣ�1������������
} SXSD_TEMP_EVRMTPARAM;

// ����SXSD�Ĳ�������
typedef struct
{
    SXSD_TEMP_EVRMTPARAM m_pEventParam[2];                    // �ֱ��ʾ�������ݣ����ڡ����⣩
} VSNET_SXSD_EVRMTPARAM;
/************************************* SXSD ENDS ******************************************/

/************************************* HL-SAMMY STARTS ************************************/
// HL-SAMMY
typedef struct
{
    int m_nVideoMode;    // video mode 0,single 1,mul
    int m_nChannel;      // channels
} VSNET_ROUNDVIDEO_OUT;
/************************************* HL-SAMMY ENDS **************************************/

// �˳�����ͳ��
typedef struct
{
    int m_nVehicle;      // ������
    int m_nPedestrian;   // �˼���
} VSNET_SMART_TARGETCOUNT;

// ��������Ϣ
typedef struct
{    
    char  m_flag[8];         // �Ƿ񳬳���ֵ
    char  m_dlh_name[8][56]; // ����������
    char  m_dlh_unit[8][16]; // ��������λ
    float m_dlh_value[8];    // ��������ֵ 
    int  m_dlh_precision[8]; // ����
} VSNET_CURRENTLOOP;        

// ����������Ϣ
typedef struct
{
    int  m_channel;
    int m_alarmin_states;    // ��������״̬
    char m_alarmin_name[32]; // ̽ͷ����
} VSNET_ALARMIN;

// WHYB_D�������
typedef struct
{
	int m_ptz_horizontal_angle;	// ˮƽ�Ƕȵ�100��
	int m_ptz_vertical_angle;	// ��ֱ�Ƕȵ�100��
	int m_ptz_multiple;			// �䱶����
	int m_reverse;				// ����
} VSNETPTZ_WHYB;

//SXKD �ش�JPG 
typedef struct
{
	int           m_busnum;            //������� 0~255
	int           m_chno;              //�����ͨ����
	int           m_jpegsize;          //jpeg����
	int           m_year;
	int           m_mon;
	int           m_day;
	int           m_hour;
	int           m_min;
	int           m_sec;
	unsigned char m_jpgbuff[1024*200]; //JPG����
}VSNET_SXKD_JPEG;
				
/************************************* NVR begin ******************************************/
#define                 MAX_DEV_SEARCH_NUM          100

typedef struct
{
    char            sername[24];
    unsigned char   mac[8];
    char            ip[20];         // ip
    char            mask[16];       // submask
    char            gw[16];         // gateway
    char            dns[16];        // DNS
    char            multiip[16];
    unsigned short  wPortWeb, wPortSer, wPortMulti;
    unsigned short  channel;
    unsigned short  devtype;
    unsigned short  reserve;
} VSNETDEVINFO;

// the device list of NVR dev search
typedef struct
{
    int             m_total;                      // the number of device
    VSNETDEVINFO    m_puinfo[MAX_DEV_SEARCH_NUM]; // info of each device
} VSNETNVRDEVSEARCHINFO;

typedef struct
{
    char            m_sername[32];      // server name
    char            m_serip[20];        // server ip address
    unsigned short  m_serport;          // server port
    unsigned short  m_channel;          // the channel of server to be connected
    unsigned short  m_transtype;        // the media transport type tcp/udp/multi
    unsigned short  m_chlinkstate;      // channel link state
    unsigned short  m_imgheight;        // image height
    unsigned short  m_imgwidth;         // image width
    char            m_username[20];     // server user name
    char            m_passwd[20];       // server password
    int             m_reserved1;        //reserved1
    int             m_reserved2;        //reserved2
} VSNETNVRDECCHINFO;

typedef struct
{
    int                 m_enable;       // channel been used ?
    int                 m_maxsize;      // max video format
    VSNETNVRDECCHINFO   m_chinfo;       // channel info
} VSNETNVRDECCHSTATE;

typedef struct
{
	VSNETNVRDECCHSTATE 	m_channel[VSNET_DVR_MAXCH];   	//channel info array
}VSNETNVRDECCHANSTATE;

typedef struct
{
    int                 m_num;                          // number in data
    char                m_chname[VSNET_DVR_MAXCH][20];  // name fo each channel
    int                 m_chimgsize[VSNET_DVR_MAXCH];   // replay channel image size 0:NO 1:D1 3:720P 7:1080P
} VSNETNVRGUINOTIFYNODECABILITY;

typedef struct
{
    int                 m_enable;       // pu time synchronous enable? 0 disable, 1 everyday 00:00
} VSNETNVRPUTIMESYN;

/* usb����״̬ */
typedef struct
{
    int m_ustate;            // u������״̬��  	1:�����ӣ�0:δ����
    int m_mstate;            // �������״̬�� 	1:�����ӣ�0:δ����
    int m_estate;            // esata����״̬��	1:�����ӣ�0:δ����
	int m_reserve[2];		 // ����λ
}VSNET_NVR_USBSTATE_S;

/************************************* NVR end ********************************************/

/************************************* SCDW begin ******************************************/
typedef struct
{
	char m_code[32];		// ���볤��32λ			
}VSNETINVITECHANAL_INFO;

typedef struct
{
    int    				     m_enable[32];        // ͨ��ʹ��,32��ͨ��
    VSNETINVITECHANAL_INFO   m_ch_info[32];	 	  // 32��ͨ������
}VSNETINVITECHANAL;
/************************************* SCDW end ********************************************/

/************************************* ITS begin ******************************************/
//��󳵵���
#define MAX_LANE_NUM            10

//��󳵵�������
#define MAX_LANE_LINE_NUM       (MAX_LANE_NUM + 1)

//��󴥷��������� ��Ȧ*2  ����/�뿪2��״̬
#define MAX_LANE_COIL_NUM       3
//#define LANE_COIL_TRIGG_NUM     (MAX_LANE_COIL_NUM*2)

//һ�������У�����������Ȧ��ļ����
#define MAX_DISTANCE_NUM        (MAX_LANE_COIL_NUM-1)

//ÿ�����������������Ȧ����
#define MAX_VCOILS_NUM_IN_LANE  1

//���ڱ�ų���
#define MAX_BAYONETID_SIZE      12

//���IO�������
#define MAX_IOIN_NUM            4

//���IO�������
#define MAX_IOOUT_NUM           4

//�����̵�����
#define MAX_TRFL_NUM            MAX_LANE_NUM

// ÿ����Ȧ���ӵ�е�״̬ ����/�뿪
#define MAX_COIL_STATE          2

// ͼƬ��Ӧ������
#define CAP_TYPE_MANUAL            (1<<0)       /* �ֶ�ץ�� */
#define CAP_TYPE_OVERSPEED         (1<<1)       /* ����ץ�� */
#define CAP_TYPE_TRAFFICLIGHT      (1<<2)       /* �����ץ�� */
#define CAP_TYPE_BAYONET           (1<<3)       /* ����ץ�� */
#define CAP_TYPE_CAPTEST           (1<<4)       /* ץ�Ĳ��� */
#define CAP_TYPE_TRAFFICLIGHT_L    (1<<5)       /*��ת�����*/
#define CAP_TYPE_TRAFFICLIGHT_R    (1<<6)       /*��ת�����*/
#define CAP_TYPE_CHANGE_LANE       (1<<7)       /*���*/
#define CAP_TYPE_VIOLATION_LINE    (1<<8)       /*ѹ��*/
#define CAP_TYPE_RETROGRADE        (1<<9)       /*����*/
#define CAP_TYPE_WRONG_LANE        (1<<10)      /*�����涨������ʻ*/
#define CAP_TYPE_LLLEGAL_TURN      (1<<11)      /*��ͷΥ��*/
#define CAP_TYPE_YELLOWLIGHT_L     (1<<12)      /*��ת���Ƶ�*/
#define CAP_TYPE_YELLOWLIGHT       (1<<13)      /*ֱ�д��Ƶ�*/
#define CAP_TYPE_YELLOWLIGHT_R     (1<<14)      /*��ת���Ƶ�*/


//��ͬҵ��ģʽ�£���ͬ��Ȧ����ץ�Ĳ���
typedef enum
{
    VS_SCHEME_BAYONET_MANUAL        = 100,  //�����û��Զ���
    VS_SCHEME_BAYONET_1C_1I         = 111,  //���ڵ���Ȧ��1ץ
    VS_SCHEME_BAYONET_2C_2I         = 121,  //����˫��Ȧ��2ץ
    VS_SCHEME_BAYONET_3C_3I         = 131,  //��������Ȧ��3ץ
    VS_BAYONET_RADAR_ARRIVE_IN      = 141,  //�����״ﴥ�������������״�����ץ��
    VS_BAYONET_RADAR_ARRIVE_OUT     = 142,  //�����״ﴥ���������뿪�״�����ץ��
    VS_BAYONET_RADAR_LEAVE_IN       = 143,  //�����״ﴥ����ȥ�������״�����ץ��
    VS_BAYONET_RADAR_LEAVE_OUT      = 144,  //�����״ﴥ����ȥ���뿪�״�����ץ��

    VS_SCHEME_EP_MANUAL            = 200,  //�羯�û��Զ���
    VS_SCHEME_EP_2C_1I2I2O         = 221,  //�羯˫��Ȧ��1��2��2ץ

    VS_SCHEME_BAYEP_MANUAL          = 300,  //���ڵ羯�û��Զ���
    VS_SCHEME_BAYEP_2C_1I2I2O       = 321,  //���ڵ羯˫��Ȧ��1��2��2ץ
} VS_CAP_SCHEME;

typedef enum
{
    VS_CAP_BUSINESS_BAYONET=1,     //����ģʽ
    VS_CAP_BUSINESS_EPOLICE,       //�羯ģʽ
    VS_CAP_BUSINESS_BAYONETEP      //����ʽ�羯ģʽ
} VS_CAP_BUSINESS_E;

typedef enum
{
    VS_CAP_TRIG_TYPE_VD=1,         //����������
    VS_CAP_TRIG_TYPE_VC,           //������Ȧ����
    VS_CAP_TRIG_TYPE_SIO,          //��IO����
    VS_CAP_TRIG_TYPE_RADAR,        //�״ﴥ��
    VS_CAP_TRIG_TYPE_MANUAL,       //�ֶ�����
    VS_CAP_TRIG_TYPE_MIX,          //��ϴ���
} VS_CAP_TRIG_TYPE_E;

typedef enum
{
    VS_VDETECTOR_JIMU1,             //��Ŀ1������ ÿ����1��Ȧ
    VS_VDETECTOR_JIMU2,             //��Ŀ2������ ������2��Ȧ
    VS_VDETECTOR_JIMU3,             //��Ŀ3������ ������3��Ȧ
    VS_VDETECTOR_JIMU2A,            //��Ŀ2a����������������һ��Ȧ
    VS_VDETECTOR_JIMU3A,            //��Ŀ3a��������������������Ȧ
    VS_VDETECTOR_MAXNUM            //֧�ֳ���������
} VS_VDETECTOR_TYPE_E;


typedef enum
{
    VS_RADAR_APACHE2,              // Apache II���״�
	VS_RADAR_CSRIN,                // CSR-I N���״�
    VS_RADAR_MAXNUM,
}VS_RADAR_TYPE_E;

#ifndef MAX_RADAR_STATE
#define MAX_RADAR_STATE 4
#endif
typedef enum
{
    VS_TRADAR_ARRIVE_IN,   //���������״�����
    VS_TRADAR_ARRIVE_OUT,  //�����뿪�״�����
    VS_TRADAR_LEAVE_IN,    //ȥ�������״�����
    VS_TRADAR_LEAVE_OUT,   //ȥ���뿪�״�����
}VS_TRADAR_STATE_E;

typedef enum
{
//    TCOIL_NONE,         //��Ч
    VS_TCOIL_IN,           //����Ȧ
    VS_TCOIL_OUT           //����Ȧ
} VS_TCOIL_STAT_E;

typedef enum
{
    //TLIGHT_NONE,        //��Ч
    VS_TLIGHT_GREEN,        //�̵�
    VS_TLIGHT_RED           //���
} VS_TLIGHT_STATE_E;

// IO�����������ͣ�����������Ӧ�Ĳ�����Ȼ��������IO��������
typedef enum
{
    VS_IO_TYPE_NONE,              // ��Ч
    VS_IO_TYPE_COIL,              // ��Ȧ
    VS_IO_TYPE_TRAFFICNIGHT,      // ���̵�
    VS_IO_TYPE_SYNSIG             // ����ͬ���ź�
} VS_CAP_IOIN_TYPE_E;

//��ѹ���� 
typedef enum
{
    VS_VOLTAGE_LOW,        //�͵�ƽ
    VS_VOLTAGE_HIGH,       //�ߵ�ƽ
    VS_VOLTAGE_PULSE,      //����
} VS_VOLTAGE_E;

/**
 * @brief IO���봥����ʽ
 */
typedef enum
{
    VS_IO_EDGE_NONE       = 0,    /* ������ */
    VS_IO_EDGE_RISING     = 1,    /* ������ */
    VS_IO_EDGE_DOWN       = 2,    /* �½��� */
    VS_IO_EDGE_RIDO       = 3,    /* �����ؼ��½��� */
} VS_IO_EDGE_E;

typedef enum
{
    VS_AC_SYNC_NONE,           // ��ͬ��
    VS_AC_SYNC_POWER,          // ��Դͬ��
    VS_AC_SYNC_IO              // IO�����ź�ͬ��
} VS_AC_SYNC_TYPE_E;

typedef enum
{
    VS_FILL_LIGHT_STROBE=1,    /* Ƶ���� */
    VS_FILL_LIGHT_BURST,       /* ������ */
} VS_FILL_LIGHT_E;

#define VS_MAX_COIL_STATE          2
//ץ�Ļ�OSD���Ӵ�С
#define VS_OSD_NUM         14

typedef struct
{
    int             strobeMode;         //Ƶ���ƹ���ģʽ : 0:�ر� 1:���� 2:��ʱ 3:�Զ�
    int             brightThreshold;    //Ƶ������˸������ֵ : ��Χ 1~30
    int             StartHour;          //Ƶ������˸��ʱ����-��ʼʱ��(ʱ)
    int             StartMinute;        //Ƶ������˸��ʱ����-��ʼʱ��(��)    
    int             EndHour;            //Ƶ������˸��ʱ����-��ʼʱ��(ʱ)
    int             EndMinute;          //Ƶ������˸��ʱ����-��ʼʱ��(��)
}VSNETSTROBEPARAM;                      //����Ƶ���Ʋ���

typedef struct
{
    VSNETSTROBEPARAM m_strobe[MAX_IOOUT_NUM];   //�豸Ƶ���Ʋ���
} VSNETSTROBELIGHTCFG;                          //Ƶ���ƹ���ģʽ

typedef struct
{
    int     flashtlightype;     //��������� : 1-Ƶ����;2-������
    int     flashrate;          //����Ƶ�� : N��/��(���ڱ�����ģʽ����)
    int     flashmode;          //��˸ģʽ : Ĭ����˸����������
    int     defaultlevel;       //IOĬ�ϵ�ƽ : 0-�͵�ƽ/1-�ߵ�ƽ
    int     effectlevel;        //IO��Ч��ƽ : 0-�͵�ƽ/1-�ߵ�ƽ/2-����
    int     multiplier;         //��Ƶ : 1~15
    int     dutyratio;          //ռ�ձ� : 0~40
    int     effectdelay;        //IO��Ч�ӳ�ʱ�� : 0~40000��S
    int     effectkeep;         //IO��Ч����ʱ�� : 
} VSNETFLPARAM;                 //����Ʋ���

typedef struct
{
    VSNETFLPARAM  m_ioouts[MAX_IOOUT_NUM];  //io���(�����)    
} VSNETFLASHLIGHTCFG;                       //��������ò���

typedef struct
{
    int      syntype;       //�Ƿ��Դͬ�� : 0-��ͬ��;1-��Դͬ��;2-IOͬ��
    int      ioins;         //��ѡIO�����(��λ��ֻ��):0x01-IO1;0x02-IO2;0x04-IO3;0X08-IO4
    int      signalin;      //�ź�����ں� : 1~4������ѡ��IOͬ��ʱ�������ã�
    int      phase;         //ͬ���ź���λ�� : 0~360
} VSNETSIGNALSYNCFG;        //�źŵ�ͬ�����ò���

typedef struct
{
	unsigned char  m_enable;          //�Ƿ�����Ӧ���͵�ʹ��״̬
    unsigned char  m_type;            //��������
    unsigned char  m_res[2];          //����
    unsigned int   m_posx;            //��ʼ����X
    unsigned int   m_posy;            //��ʼ����Y
} VSNETOSDSTYLE;              //�����ַ�����ʽ

typedef struct
{
	unsigned char  m_osdEnable;       //osdʹ�ܱ�־
    unsigned char  m_osdMode;         //���ӷ�ʽ 0:�������� 1:���е��� 2:�߼�����
    unsigned char  m_osdColorR;       //��ɫR
    unsigned char  m_osdColorG;       //��ɫG
    unsigned char  m_osdColorB;       //��ɫB
	unsigned char  m_backColorR;      //��ɫR
    unsigned char  m_backColorG;      //��ɫG
    unsigned char  m_backColorB;      //��ɫB
    unsigned char  m_osdSize;         //OSD��С 2��4��6
    unsigned char  m_res[3];
    
    unsigned int   m_timeFormat;                              //ʱ���ʽ
    unsigned char  m_locaStr[VSNET_CAPTURE_OSDSTR_LENTH];     //�ص�
    unsigned char  m_directStr[VSNET_CAPTURE_OSDSTR_LENTH];   //����
    unsigned char  m_usrStr1[VSNET_CAPTURE_OSDSTR_LENTH];     //�û��Զ���1
    unsigned char  m_usrStr2[VSNET_CAPTURE_OSDSTR_LENTH];     //�û��Զ���1
    VSNETOSDSTYLE m_osdinfo[VS_OSD_NUM];
} VSNETCAPJPEGOSD, VSNETH264OSD;        //�ַ����Ӳ���

typedef struct
{
    char    capnum;         //ץ������1~5��Ĭ��1
    char    capinterval;    //ץ��֡���: 0~15��Ĭ��0(����Ӧ)
    char    reserved[2];    //����
} VSNETMANUALCAPJPEGCFG;    //�ֶ�ץ��JPEG���ò���

typedef struct
{
    int                     enftpjpeg;      //ʹ���ϴ�ץ��ͼƬ��FTP
    int                     quality;        //ץ������
	char                    tollgateid[32]; //���ڱ��(12���ַ�)
    char                    deviceid[32];    //�豸���(3���ַ�)
    VSNETMANUALCAPJPEGCFG   manualcap;
} VSNETCAPBASICPARAM;                       //ץ�Ļ�������

typedef struct
{
    int    m_capmode;       //ҵ��ģʽ: 1-����ģʽ;2-�羯ģʽ;3-���ڵ羯ģʽ
    int    m_triggermode;   //����ģʽ: 1-������(�羯/���ڵ羯ҵ��ģʽ��֧�ֳ���������);2-��Ƶ;3-��IO;4-�״ﴥ��
    int    m_device_type;  //�ͺţ��������ͺ�VDETECTOR_TYPE_E,�״��ͺ�RADAR_TYPE_E
} VSNETCAPMODECFG;          //ץ��ģʽ���ò���

typedef struct
{
    short   m_x;        //x����
    short   m_y;        //y����
    short   m_width;    //������Ȧ��
    short   m_height;   //������Ȧ��
} VSNETVCOILRECT;       //������Ȧ����

typedef struct
{
    int     m_enable;       //����/�뿪��Ȧ�Ƿ�ץ��
    int     m_capnum;       //ץ������
    int     m_interval;     //����ץ��ʱ��ץ��֡���
} VSNETCOILTRIGGER;         //��Ȧ��������

typedef struct
{
    int                 m_ioinid;               //��������IO��� [1-4]
    VSNETCOILTRIGGER    m_ct[MAX_COIL_STATE];   //��Ȧ��������:m_ct[0]-����;m_ct[1]-�뿪
} VSNETSIOCOIL;                                 //��IO������Ȧ����

typedef struct
{    
    int             m_assfl;    //��������Ʊ��: 0-������; ���ص�1/2/3/4
    VSNETSIOCOIL    m_siocoil;  //��IO������Ȧ����
} VSNETSIOLANE;                 //��IO������������

typedef struct
{
    int             m_iois;                     //��ѡ�Ĵ���IO(��λ��ֻ��):0x01-IO1;0x02-IO2;0x04-IO3;0X08-IO4
    VSNETSIOLANE    m_siolane[MAX_LANE_NUM];    //��������
} VSNETIOMODECFG;                               //��IOģʽ���ò���

typedef struct {
    
    unsigned short  m_vcoil_enable;         // 0-��ʹ�ܣ�1-ʹ��
	unsigned short	m_speed_enable;         // ����ʹ��
    unsigned short  m_direction;            // �˶�����[0,359], ��ʱ��ʹ�øò���
    VSNETVCOILRECT  m_rect;                 // ������Ȧ����

    //����ģʽ����
	unsigned short   m_day_sensitivity;	    // ��Χ[1,100]��Ĭ��70����Ӱ���ռ���������С��ֵ
    unsigned short   m_day_R;			    // ��Χ[1,255]��Ĭ��20�����������ƵĶ�����ֵ����λ�Ҷȼ�
	unsigned short   m_day_phi;			    // ��Χ[1,20]��Ĭ��5�����������ٶȣ�ÿ��phi֡����һ��    
	unsigned short  m_day_time_delay;	    // ���ڵ���1[1,400]��Ĭ��5���¼��������ӳ٣���λ֡
} VSNETCOILREGIONPRM;


typedef struct
{
    int                 m_offset;           //ҹ����ǰ����ƫ��
    VSNETCOILREGIONPRM  m_region_param;	    //�������߼�����
    VSNETCOILTRIGGER    m_ct;               //������Ȧû�н���/�뿪֮��
} VSNETVCOIL;                               //������Ȧ����

typedef struct
{
    int              m_viewable;   //�Ƿ���ʾ������Ȧ: 0-��;1-��
    int              m_assfl;      //��������Ʊ�� 
    int              m_vccount;    //��ǰ����ӵ�е�������Ȧ����(ֻ��): Ŀǰ�̶�Ϊ1
    VSNETVCOIL       m_vcs[MAX_VCOILS_NUM_IN_LANE];      //������Ȧ����
} VSNETVCOILLANE;                   //��Ƶ����ģʽ��������

typedef struct
{
	double m_x;             //x����
	double m_y;             //y����
}VSNET_TRIGGERPOINT;

typedef struct 
{
	VSNET_TRIGGERPOINT      m_region[4];       //����ƽ���ϵı궨���ε��ĸ�������ͼ���е�����λ��
    int                     m_reg_width;        //����ƽ���ϵı궨���ε�ʵ�ʿ�ȣ���λΪ��(m)����Χ[1,100]��Ĭ��
    int                     m_reg_height;       //����ƽ���ϵı궨���ε�ʵ�ʸ߶ȣ���λΪ��(m)����Χ[1,100]��Ĭ��10
} VSNET_TRIGGERALG;

typedef struct
{     
    short            m_dawn_start;		                // ������ʼʱ��
	short            m_dawn_end;	                    // ��������ʱ��
	short            m_dusk_start;                      // �ƻ迪ʼʱ��
	short            m_dusk_end;                        // �ƻ����ʱ��
	short            m_regions_max;	                    // �����õ������Ȧ��
	short            m_regions_num;	                    // ��ǰʹ�õ���Ȧ��
    VSNETVCOILLANE   m_vclane[MAX_LANE_NUM];            // ������Ȧ��������
    VSNET_TRIGGERALG m_vcalg;                           // �����������
} VSNETVIDEOMODECFG;                                    // ��Ƶ����ģʽ���ò���

typedef struct
{
    int                 m_coil_width;           //��Ȧ���
    VSNETCOILTRIGGER    m_ct[MAX_COIL_STATE];   //��Ȧ��������
} VSNETVDETECTORCOILS;                          //������������Ȧ����

typedef struct
{
    int                     m_assfl;                        //��������� [1-4]
    int                     m_asstraffic;                   //�������̵� [1-4]
    int                     m_bcaptlight;                   //�Ƿ������̵�ץ��
    int                     m_bcap_ospeed;                  //�Ƿ�������ץ��
    VS_CAP_SCHEME           m_cap_scheme;                   //ץ�ķ���
    int                     m_vehicle_mins;                 //�������
    int                     m_vehicle_maxs;                 //�������
    int                     m_coil_num;                     //������Ȧ����
    int                     m_dsize[MAX_DISTANCE_NUM];      //������Ȧ����(cm)��0��ʾ1,2���룬1��ʾ2,3����
    VSNETVDETECTORCOILS     m_lane_coils[MAX_LANE_COIL_NUM];//��Ȧ��������
} VSNETCAPLANE;                                             //����������ץ�ĳ�������

typedef struct
{      
    int             m_cap_num;                  //ץ������
    int             m_cap_interval;             //ץ��֡���
    VSNETCAPLANE    m_vdlane[MAX_LANE_NUM];     //��������������
} VSNETVEDETECTMODECFG;                         //����������ģʽ���ò���

typedef struct
{    
    int     m_ioid; //���̵�IO�����: 1~4
} VSNETTRFLPARAM;   //���̵Ʋ���

typedef struct
{
    int             m_ioins;                //���̵ƿ�ѡ��IO����(��λ��ֻ��):0x01-IO1;0x02-IO2;0x04-IO3;0X08-IO4
    VSNETTRFLPARAM  m_trfls[MAX_TRFL_NUM];  //���̵���     
} VSNETTRAFFICLIGHTCFG;                     //���̵����ò���

typedef struct
{
    int iotype;     //IO��������: 0-��Ч;1-��Ȧ;2-���̵�;3:����ͬ���ź�
    int state;      //������ʽ(�����������Ͳ�ͬ����ͬ)
} VSNETIOINPARAM;   //����IO�������

typedef struct
{
    VSNETIOINPARAM m_ioins[MAX_IOIN_NUM];   //IO����
} VSNETIOCFG;                               //IO��������

typedef struct
{
    int m_count;   //IO��������
} VSNET_IOINPUTCOUNT;

typedef struct
{
    int    type;                //0-��ʹ��,1-������,2-������
    char   blacklist[10][16];   //������IP��ַ�б����Ϊ10�������ʮ������ʽ�ַ���
    char   whitelist[10][16];   //������IP��ַ�б����Ϊ10�������ʮ������ʽ�ַ���
} VSNETIPFILTERCFG;             //IP��ַ���˲���

typedef struct{
    int                     m_timezone;         //timezone
    int                     m_year;             //year
    char                    m_month;            //month
    char                    m_day;              //day
    char                    m_hour;             //hour
    char                    m_minute;           //minute
    char                    m_second;           //second
    char                    m_received[3];		//reserved
}VSNETLOG_NETTIME;          //��־ʱ����Ϣ

typedef struct
{
    int                 m_nlogtype;                  //��������־����:0-����;1-������־;2-�쳣��־;3-������־
    int                 m_nsearchtype;               //�������ͣ�0-������;1-��ʱ��;2-���ؼ���
    char                m_szkeyword[20];             //�����ؼ���
    VSNETLOG_NETTIME    m_vsnStratTime;              //��ʼʱ��: ���������ʱ�䣬������
    VSNETLOG_NETTIME    m_vsnStopTime;               //����ʱ��
    char                m_bdownload;                 //���������ػ�������
    char                m_szReseved[63];             //����
} VSNETLOGSEARCH;                                    //��־����������Ϣ

typedef struct
{
    int                 m_log_num;          //��־���
    int                 m_log_type;         //��־����:1-������־;2-�쳣��־;3-������־
    VSNETLOG_NETTIME    m_log_time;         //��־ʱ��
    char    	        m_log_event[200];   //ת������¼�
} VSNETLOGINFO;                             //������־���

typedef struct
{
    char                pStrFPGAVer[50];       // FPGA Version
    char                pStrFPGABuildTime[50]; // FPGA Compile Time
}  VSNETFPGAVERSION;                           // FPGA�汾��Ϣ

typedef struct
{
    char                pStrDSPVer[50];       // DSP Version
    char                pStrDSPBuildTime[50]; // DSP Compile Time
}  VSNETDSPVERSION;                           // DSP�汾��Ϣ

typedef struct
{
    int                 m_enable_ftp;      // label of FTP upload(reserved)
    char                m_remote_IP[32];   // IP address
    unsigned short      m_remote_port;     // port
    char                m_linkstatus;      // FTP link state
    char                m_reserved;        //reserved for alignment
    char                m_ftp_user[40];    // Ftp username
    char                m_ftp_pwd[40];     // Ftp password
    char                m_ftp_path[40];    // Ftp path
} VSNETITSFTPINFO;                         // ץ�Ļ�FTP����

typedef struct
{
    int filesystem[8];  //�����ļ�ϵͳ����
    int reserved[8];    //����
} VSNETITSFILESYSTEM;   //ץ�Ļ��ļ�ϵͳ����

/*************************Capture parameter ********************************/
typedef struct
{
    int              m_capDayshtspd;        // shutter speed 0~255
    int              m_capNightshtspd;      // shutter speed 0~255    
    int              m_capAwb;              // balance mode 0:auto 1:sunny day 2:cloudy day 3:sodium lamp
    int              m_capWbr;              // balance by hand R 0~255
	int              m_capWbg;              // balance by hand G 0~255
    int              m_capWbb;              // balance by hand B 0~255
    int              m_capAgcOfDay;         // automatic gain of day 0~255
    int              m_capAgcOfNight;       // automatic gain of night 0~255
    int              m_capShpmode;          // shapness mode 0:auto 1:manual
    int              m_capShpdata;          // shapness data 0~255
    int              m_capBri;              // brightness 0~255
    int              m_capCon;              // contrast 0~255
    int              m_capSat;              // saturation 0~255
    int              m_capNoisemode;        // noise mode  0:auto; 1:manual
    int              m_capNoiselevel;       // noise level 0~255
    int              m_capAgcOffset;        // gain deviation value -512~512
    int              m_capReserve[4];       // reserver
} VSNETCAPSENSORPARAM;

/************************* Traffic lights parameter ********************************/
#define MAX_TRFL_AREA   6       //�����̵�������
typedef struct
{
    int              m_lightx;              // Traffic lights X coordinate
    int              m_lighty;              // Traffic lights Y coordinate   
    int              m_lightw;              // Traffic lights area weight
    int              m_lighth;              // Traffic lights area height
    int              m_redLightr;           // red light R 0~255
    int              m_redLightg;           // red light G 0~255
    int              m_redLightb;           // red light B 0~255
    int              m_yellowLightr;        // yellow light R 0~255
    int              m_yellowLightg;        // yellow light G 0~255
    int              m_yellowLightb;        // yellow light B 0~255
    int              m_greenLightr;         // green light R 0~255 
    int              m_greenLightg;         // green light G 0~255 
    int              m_greenLightb;         // green light B 0~255 
} VSNETCAPTRFLPARAM;

typedef struct
{
    VSNETCAPTRFLPARAM  m_capTrflparam[MAX_TRFL_AREA];//���̵�����
} VSNETCAPTRFLPARAMS;

typedef struct
{
    unsigned int m_paramtype;  //�ָ�Ĭ�ϵĲ�������:0x01-��ƵSENSOR����;0x02-��Ƶ��ƽ�����;
                               //0x04-ץ��SENSOR����;0x08-ץ�İ�ƽ�����0x10-���̵�У������
} VSNETITSDEFAULT;              //�ָ�Ĭ�ϲ���������

#define  VER_STR_LEN        32
typedef struct
{
    int     m_directionFilter;      //������� ������ 1 ������� 2 ���ȥ�� 3 ˫�����
    int     m_sensitive;            //������ [1-16]
    int     m_speed_min;            //�ٶ����� [0 ~ 255],�����״���
    int     m_angleCorrectArrival;  //�����Ƕ����� [0 ~ 70]
    int     m_angleCorrectAway;     //ȥ���Ƕ����� [0 ~ 70]
    char    m_ver[VER_STR_LEN];     //�汾�ţ����ڻ�ȡ
}VSNET_RADARPARAM;

typedef struct
{
    int                 m_conncettype[MAX_LANE_NUM];    //�������� 0-485��1-232
    VSNET_RADARPARAM m_radar[MAX_LANE_NUM];
}VSNET_CAPRADARCFG;

typedef struct
{
    int m_enable;       //����/�뿪/������Ȧ�Ƿ�ץ��
    int m_capnum;       //ץ������
    int m_interval;     //����ץ��ʱ��ץ��֡���
}VSNET_RADARTRIGGER;

typedef struct
{
    int                     m_associate_fl;             //��������� [1-4] 0������ 
    int                     m_associate_traffic;        //�������̵��� [1-2] 0������ ����
    int                     m_bcap_tlight;              //�Ƿ������̵�ץ�� 1 ������0�ر� ����
    int                     m_bcap_ospeed;              //�Ƿ�������ץ�� 1 ������0�ر� ����
    int                     m_vehicle_mins;             //������� km/h ����
    int                     m_vehicle_maxs;             //������� km/h ����
    VS_CAP_SCHEME           m_cap_scheme;               //ץ�ķ���
    int                     m_radarid;                  //������Ӧ�Ĵ����״��ţ�[1-MAX_LANE_NUM]�� 0������
    VSNET_RADARTRIGGER      m_rt[MAX_RADAR_STATE];      //radar triger  ����
} VSNET_VRADARLANE;

/**
 * @brief �״ﴥ�����ò���
 */
typedef struct
{
    VSNET_VRADARLANE     m_rdlane[MAX_LANE_NUM]; //�״ﳵ������
} VSNET_CAPVRADAR;

/* ����ʶ���㷨���ò����ṹ�� */
typedef struct
{
    char            m_version[16];                // �㷨�汾��
    char            m_date[16];                   // �㷨����
    int             m_type;                       // �㷨����: 0: ȱʡ 1: ��֡����ʶ���㷨 2: ��֡��Ƶ��ʽ����ʶ���㷨 3: �羯Υ���㷨
    int             m_lane_num;                   // ����������಻����4��
    int             m_lane_flag;                  // ���������з�ʽ: 0: ������������ 1: ������������
    VSNETVCOILRECT  m_plate_detect_area;          // ���Ʒ���������ο�
    int             m_plate_w_min;                // ������С���
    int             m_plate_w_max;                // ���������
	unsigned char   m_default_prov[3];            // Ĭ��ʡ�ݺ��ֵ��ַ�(2���ֽ�)���������ֽ�Ϊ'\0'
    char            m_id_lane;                    //������
    unsigned char   m_chinese_trust_thresh;       // ����ʶ�����Ŷȵ���ֵ
    unsigned char   m_chinese_mask[31];           // ����ʶ�����Ĥ(����ַ�ʶ��ľ���) 1: ���θú���ʶ�� 0: �����ú���ʶ��
    //  �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ԥ �� �� �� �� �� �� �� ³ ��
    //  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
} VSNET_PLATEREGIONPARAM;

typedef struct
{
	short m_x0;	// ��
	short m_x1;	// ��
	short m_y0;	// ��
	short m_y1;	// ��
}VSNET_RECTS;

typedef struct
{
    int         m_sign;           // ���̵Ʒ�������: 0����ʾδ���ã�1����ʾ��ת��2����ʾֱ�У�3����ʾ��ת
	int         m_num;            // ���ο��������󲻳���5
    VSNET_RECTS m_lightrect[5];   // ���̵ƾ������� (��󲻳���5)
}VSNET_LIGHTLAYERS;

typedef struct
{
    int   m_pax;   //��һ����x����
	int   m_pay;   //��һ����y����
	int   m_pbx;   //�ڶ�����x����
	int   m_pby;   //�ڶ�����y����
}VSNET_DOUBLEPOINT;

/* �羯Υ���㷨���ò����ṹ�� */
typedef struct VSNET_POLICEPARAM
{
	int               m_lanenum;        // ��������
    int               m_lanetype[8];    // ������������: 0: ȱʡ 1: ��ת     2: ֱ��     3: ��ת 
                                        //               4: ��תֱ�� 5: ֱ����ת 6: ��ת��ת 
                                        //               7: ��תֱ����ת 
	int               m_blanepacc;      //�޸�Υ�����͵�ʹ�� 0: ��Ч   1: ��Ч
	int               m_lanepeccancy[8];// ÿ��������Ч��Υ������
	                                    // 1-10λ��2����λ�ֱ��ʾ10��Υ�����͵���Ч��, 0: ��Ч   1: ��Ч
    VSNET_DOUBLEPOINT m_laneline[9];    // ������(���������)����CIFΪ��׼��������                                  
    int               m_detectline[4];  // �����λ�� 0:����ֱ��ֹͣ�� 1:Խ��ǰ�����(�����복���ཻ���ж��Ƿ񵽴�ֱ��ֹͣ��)
	                                    //            2:Խ�ߺ�����   3:Ԥ��
    VSNET_DOUBLEPOINT m_leftturnline;   // ��תֹͣ��λ��(��2����ȷ����ת��)����CIFΪ��׼��������        
    VSNET_DOUBLEPOINT m_rightturnline;  // ��תֹͣ��λ�ã���CIFΪ��׼��������                            
    VSNET_LIGHTLAYERS m_lightlayers[3]; // ���̵Ʋ����ṹ��  0:��ת�źŵ����� 1:ֱ���źŵ����� 2:��ת�źŵ�����
	VSNET_DOUBLEPOINT m_turnroundline;	// ��ͷ�����
	short             m_received[8];   // ����λ
} VSNET_POLICEPARAM;


typedef struct
{
    int    m_exflag;         // �ⲿ������̵Ʊ�־ 0: �ڲ�����  1: �ⲿ����
    int    m_traflight[3];   // �ⲿ������̵��ź�, m_traflight[0]: ��ת m_traflight[1]: ֱ�� m_traflight[2]: ��ת
                           	 // 0: �̵� 1: �Ƶ� 2: ���
}VSNET_VPOLICETRAFFICLIGHT;

typedef struct
{
	int         m_laneNum;      //ץ�Ļ���ǰ������
}VSNET_ITSLANE;

typedef struct
{
    int         m_lane;         //��ͳ�Ƴ���
    int         m_time;         //ͳ��ʱ��
    int         m_ratio_min;    //�л��ٷֱ�����
    int         m_ratio_max;    //�л��ٷֱ�����
}VSNET_ITSMIXTRIGPARAM;         //���ڻ��ץ�Ĵ������ò���

typedef struct
{
    int         m_lane_id[MAX_LANE_NUM];   //�����û�����ʵ�ʳ���
    int         m_reserved[MAX_LANE_NUM];   //����λ
}VSNET_ITSLINEIDCFG;

typedef struct
{    
	int               m_lanenum;        // ��������
    VSNET_DOUBLEPOINT m_laneline[MAX_LANE_LINE_NUM];    // ������(���������)����CIFΪ��׼��������   
    int               m_type_enable[MAX_LANE_NUM];                //Υ������ʹ�ܱ�־
    char              m_reserved[32];
}VSNET_ITSBAYONETPOLICE;

typedef struct
{
    char    m_enplat;       //��д����ʹ��
    char    m_enimagesynth; //Υ��ͼƬ�ϳ�
    char    m_enbayonetimg; //�������ͼƬʹ��
    char    reserved;       //����
}VSNET_ITSPROPERTYENABLE; 

typedef struct
{
	short		m_x;			  //x����
    short		m_y;              //y����
    short		m_width;          //������
    short		m_height;         //����߶�
	char		reserved[4];      //����
}VSNET_ITSWBCORRECTPARAM;         //��ƽ������У��

typedef struct
{
	int m_debugInfoShowEnable;       //������Ϣʹ�ܿ���
}VSNET_ITSDEBUGINFOSHOW;

/************************************* ITS end ..******************************************/



/************************************* CrossMenager START ..******************************************/
typedef struct
{
    char                m_benbale;          // Regular Restart Enable
    char                m_invalidtime;      // interval time(HOUR AS UNIT��10h-240h:10 hours to 10 days)
    char                m_rsthour;          // Restart Hour
    char                m_rstminute;        // Restart Minute
    char                m_rsfrdevice;       // Restart front device
    int                 m_reserved;         // Reserved
} VSTIMERRESETEX;


typedef struct
{
    char                m_hostserverurl[40]; // IP of Recording Server
    char                m_alarservermurl[40];// IP of Alarm Server
    unsigned short      m_hostserverport;    // Port of Recording Server
    unsigned short      m_alarserverport;    // Port of Alarm Server
    char                m_centerservermurl[40];// IP of Center Server
    char                m_hostprocotocl;     // procotocl of Recording Server
    char                m_reserved[3];       // Reserved
} VSREMOTEHOSTEX;



typedef struct
{
    VSNETDVRALARMPARAM  m_diskfull;         // disk full
    VSNETDVRALARMPARAM  m_diskerror;        // disk error
    VSNETDVRALARMPARAM  m_nodisk;           // no disk
    VSNETDVRALARMPARAM  m_cpuexception;     // cpu exception
    VSNETDVRALARMPARAM  m_netexception;     // network exception
    VSNETDVRALARMPARAM  m_reseved;          // reserved
} VSNETOTHERALARMEX;      // other parameter

typedef struct
{
    VSNETDVRALARMPARAM  m_frontnetoff;      // front network off
} VSNETDVRFRNETOFFALARM;



//����������Ϣ
#define  MAX_PLATE_LEN		            (12)
#define  MAX_PLATE_NUN		            (10)
#define  MAX_PLATE_TYPE		            (5)

typedef struct
{
    int                 m_startyear;        // Start Year
    char                m_startmonth;       // Start Month
    char                m_startday;         // Start Day
    char                m_starthour;        // Start Hour
    char                m_startmin;         // Start Minute
    int                 m_stopyear;         // Stop Year
    char                m_stopmonth;        // Stop Month
    char                m_stopday;          // Stop Day
    char                m_stophour;         // Stop Hour
    char                m_stopmin;          // Stop Minute
    int                 m_reserved;         // Reserved
} VSNETPLATETIME;

typedef struct {
    char	            m_platestr[MAX_PLATE_LEN];
    VSNETPLATETIME      m_timelist;             //plate check time list
} VSNETPLATE;

typedef struct {
    VSNETPLATE	        m_plate[MAX_PLATE_NUN];
} VSNETPLATELIST;

typedef struct
{  
    char                m_enable[NVR_MAX_LOGICHS];//enable
    char                m_plate_type;          //plate type
    char                m_trans_enable;        //transmission enable
    short               m_reserved;             // Reserved
    VSNETPLATELIST      m_plate_list[MAX_PLATE_TYPE]; //plate number list
} VSNETPLATECHECK;

typedef struct {
    int                 m_type;      //��ѯ�ĳ������� 
    int                 m_start;     //��ѯ�Ŀ�ʼʱ��
    int                 m_stop;      //��ѯ�Ľ���ʱ�� 
    char                m_platenum[MAX_PLATE_LEN];   //��ѯ�ĳ��ƺ���
} VSNETPLATELOGQUERY;

typedef struct {
	char                m_sername[64];                  //����������
	char                m_serIP[20];                    //������IP
    short               m_ch;                           //ͨ����
    short               m_plate_type;                   //��������
    char                m_platestr[MAX_PLATE_LEN];      //���ƺ���
    int                 m_captime;                      //ץ��ʱ��
    VSNETPLATETIME      m_timelist;                     ///����ʱ��
} VSNETPLATELOGINFO;

typedef struct {
    short               m_page;     //�ӵڼ�ҳ��ʼ�Ľ��    
    short                m_num;      //ÿһҳ��ʾ������    
    int               m_total;    //��ѯ�����ܱ�����Ϣ����
    int                 m_size;     //m_context�Ĵ洢�ռ� 
    VSNETPLATELOGINFO * m_context;  //��ѯ�ı�����Ϣ���ݱ���λ�� 
    int                 m_result_nr;//���浽m_context�еı�����Ϣ���� 
} VSNETPLATELOGRESULT;

typedef struct 
{
    VSNETPLATELOGQUERY  m_search;   //��������  
    VSNETPLATELOGRESULT m_result;   //�������
} VSNETPLATELOGSEARCH;



//��ʱ�ϴ���Ϣ
typedef struct
{  
    char                m_enable;     //transmission enable
    char                m_protocol;   //transmission protocol
    short               m_reserved;   //reserved
    unsigned short      m_companytype;//transmission company type
	unsigned short      m_customtype; //transmission custom  type
    TIMECHECK           m_timelist;   //transmission time list
}VSNETTIMETRANS;

//Υ�����Ͳ���
#define MAX_ILLEGAL_TYPE_NUM           (16) 
#define MAX_TYPE_NAME_LEN              (32) 
#define MAX_TYPE_CODE_NUM              (12) 

typedef struct
{
	int             m_codeNum;                      //illegal code number
    char            m_typename[MAX_TYPE_NAME_LEN];  //illegal type name
    unsigned short  m_typecode[MAX_TYPE_CODE_NUM];  //illegal type code
}VSNETTYPEINFO;

typedef struct
{  
    short           m_companynum;    //illegal type number
    short           m_customtnum;    //illegal type number
    VSNETTYPEINFO   m_companytype[MAX_ILLEGAL_TYPE_NUM];  // device illegal type
    VSNETTYPEINFO   m_customtype[MAX_ILLEGAL_TYPE_NUM];   //user defined illegal type
}VSNETILLEGALTYPE;


//��ȡ�豸�¶�
typedef struct
{  
    short   m_temperature;       //device temperature
    short   m_reserved[3];       //reserved
}VSNETGETTEMPERATURE;


#define MAX_DISK_GROUP_NUM         (4) 
#define MAX_PIC_TYPE_NUM           (4) 

//ͼƬ���ȼ���Ϣ
typedef struct
{  
    char                m_priority[MAX_PIC_TYPE_NUM]; //covering priority 0:illegal 1:cross 2: reserved 3: reserved
    short               m_keepday;                    //keep days for low priority
    short               m_reserved;                   //reserved
}VSNETPRIORITY;

//ͼƬ������Ϣ
typedef struct
{  
    int                 m_totalsize;  //total size, unit:Mb
    int                 m_usesize;    //size has been used, unit:Mb 
    int                 m_savesize;   //allocation size, unit:Gb
    int                 m_reserved;   //reserved
}VSNETJPGGROUP;

//ͼƬ�洢��Ϣ
typedef struct
{  
    VSNETPRIORITY       m_jpgprio;   //priority info
    int                 m_groupnum;  //group number
    VSNETJPGGROUP       m_group[MAX_DISK_GROUP_NUM];   //group 1 - 4    
    int                 m_reserved;   //reserved
}VSNETJPGSAVEINFO;


//��ʱ¼�����
typedef struct
{
    char                m_benrecord; // Regular Recording Enable
    char                m_reserved[3];  //reserved 
    TIMELIST            m_record;    // Regular Recording Time Table
}VSNETTIMEREC;

//��ͨ����¼�����
typedef struct
{
    char                m_enable;     //enable
    char                m_pretime;    //pre-recording time, traffic trigger: 0-30s
    char                m_delaytime;  //delay recording time,traffic trigger: 0-30s
    char                m_reserved;   //reserved 
}VSNETTRAFFICREC;

//����¼�����
typedef struct
{
    short               m_contime;    //continuous recording time,alarm:30-1800s
    short               m_reserved;   //reserved 
}VSNETALARMREC;

//¼���������ȼ�
typedef struct
{
    char                m_priority[4]; //covering priority 0:time 1:trffic 2:alarm 3:reserved
    int                 m_keepday;     //keep days for low priority
    int                 m_reserved;    //reserved 
}VSNETRECPRIORITY;

//¼��ƻ�
typedef struct
{  
    VSNETTIMEREC        m_time;      //video type, timer
    VSNETTRAFFICREC     m_trigger;   //video type, traffic trigger
    VSNETALARMREC       m_alarm;     //video type, alarm
    VSNETRECPRIORITY    m_priority;  //priority info
    int                 m_reserved;  //reserved  
}VSNETRECSAVEINFO;


//���µ���������ͨ��IP
typedef struct
{
	char  m_devname[64];      //server name
	char  m_channelIp[20];    //channel IP address
	int   m_channel;          //channel number
	int   m_devtype;          //device type 0: main device 1: channal device
	char  m_resev[20];        //reserve
}VSNETCHANNELINFOUPDATA;  

//����������־��Ϣ
#define MAX_LOG_INFO_LEN           (120) 

typedef struct 
{
    int                 m_logType;            //��־����
	int                 m_chBlend;            //1<<0: ͨ��1, 1<<1: ͨ��2, 1<<2: ͨ��3��
    int                 m_startTime;          //��ʼʱ��
    int                 m_stopTime;           //����ʱ��
    char                m_reserve[12];        //����λ
} VSNETLOGQUERY;

typedef struct 
{
    int                 m_time;         //��־ʱ��
    int                 m_chn;          //ͨ����
    int                 m_minor_type;   //��־����
    char                m_text[MAX_LOG_INFO_LEN];    //��־����
} VSNETONELOGINFO;

typedef struct 
{
    short               m_originPos;//��ʼλ��   
    short               m_num;      //ÿһҳ��ʾ������    
    int                 m_total;    //��ѯ��������־��Ϣ����
    int                 m_size;     //m_context�Ĵ洢�ռ� 
    VSNETONELOGINFO *   m_context;  //��ѯ����־��Ϣ���ݱ���λ�� 
    int                 m_result_nr;//���浽m_context�е���־��Ϣ���� 
} VSNETLOGRESULT;

typedef struct 
{
    VSNETLOGQUERY       m_search;   //��������  
    VSNETLOGRESULT      m_result;   //�������
} VSNETLOGINFOSEARCH; 

typedef struct  
{
	int                 m_formatState;  //��ʽ��״̬��1�����ڸ�ʽ���� 0��δ��ʽ�� 2����ʽ��������
	int                 m_formatErrID;  //��ʽ������ֵ(0:��ʽ���ɹ�����������)
	char                m_reserve[12];  //����λ
}VSNETFORMATDISKSTATE;
              
/************************************* CrossMenager END   ..******************************************/


/************************************** DXHJ Custom Begin *********************************/
// DXHJ7304 server record case info
typedef struct
{
    char            m_szCaseName[28];    // case name
    char            m_szCaseID[28];      // case id
    char            m_szCaseExecor[28];  // case execor
    char            m_reverse1[28];      // court name
    char            m_reverse2[28];
    char            m_reverse3[28];
} VSNETDXJBCASEINFO;

//DXHJ_D Ƭͷ������Ϣ
typedef struct
{
    char            m_szCaseName[40];      // ��������
    char            m_szCaseID[40];        // �������
    char            m_szCaseExecor[40];    // �참��Ա
	char            m_szCaseMcdw[40];      // ���ܵ�λ
    char            m_szCaseMsdw[40];      // ����λ
    char            m_szCaseLocation[40];  // �참�ص�
	char            m_szCaseReccor[40];    // ��¼��Ա
    char            m_szCaseFilename[40];  // ¼���ļ���
    char            m_reverse1[28];        // court name
    char            m_reverse2[28];
    char            m_reverse3[28];
} VSNETDXJBCASEINFOEX;

// DXHJ7304 current max window chnannel no
typedef struct
{
    int             m_iVGANO;
    char            m_reverse[16];
} VSNETDXJBVGA;

// DXHJ_D ������״̬
typedef struct
{
    int     m_nCPUUsage;    // CPUʹ���� 0~100
    int     m_nMemUsage;    // �ڴ�ռ���� 0~100
    int     m_bSerRec;      // ������¼��״̬
    char    m_reverse[60];  // ����
} VSNETDXHJWORKSTATUS;

// DXHJ_D DVD����
typedef struct
{
    char    m_value[8];
} VSNETDVDCTRL;

// DXHJ_D ���������
typedef struct
{
    char    m_value[8];
} VSNETCAMCTRL;

// DXHJ_D ��Ƶ�л���ʽ
typedef struct
{
	int  m_enable;          // ������Ƶ�л���ʽ:0:�ֶ�,1:�Զ�
	char m_reverse[64];     // ����
} VSNETAUTOORHANDCTRL; 

// ZGHY_D ������Զ��¼����ƺͷ��ز���
typedef struct
{
    VSNETDXJBCASEINFO   m_caseinfo;             // ����: ������Ϣ
    int                 m_zgch[8];              // ����: ZGHYͨ��¼�����, 1 ��ʼ, 0 ����ʼ
    char                m_reccordName_get[64];  // ��ȡ: ����¼����
    char                m_diskserialnum[32];    // ��ȡ: �������к�
    int                 m_slot;                 // ��ȡ: ����λ
    char                m_sharename[32];        // ��ȡ: ���̹�����
} VSNETSERVERRECPARAM_ZGHY;

// ZGHY_D OSD����
typedef struct
{
    char m_osd[400];        // OSD��������
    int  m_speed;           // �����ٶ�
    int  m_width;           // ����OSD��ʾ���
    char m_reverse[64];     // ����
} VSNETZGOSD;

// ZGHY_D OSD����2����
typedef struct
{
    int               bShow;           // show(1),hide(0)
    char              lpString[64];    // characters to be showed
    unsigned short    x, y;            // coordinate
} TITALOSD_ZGHY;

// ZGHY_D OSD����2
typedef struct
{
    TIMEOSD           m_time;          // time
    TITALOSD_ZGHY     m_tital[4];      // title
    BITSINFOOSD       m_bits;          // bit rate
} CHANNOSD_ZGHY;

// ZGHY_D RTMP��Ϣ
typedef struct
{
    char m_hostname[48];    // RTMP������ַ (IP��������) Ĭ�� "0.0.0.0"
    int  m_rtmpport;        // RTMP�˿� Ĭ�� 1935
    char m_appname[40];     // Ӧ��ʵ������ Ĭ�� live
    char m_streamname[48];  // RTMP������ Ĭ�� livestream
} VSNETRTMPINFO;

// ZGHY_D �����л���ֵ����
typedef struct
{
    int  m_diskchangelimen; // �����л���ֵ����λ��MB��
    char m_reverse[64];     // ����
} VSNETDISKCHANGELIMEN;

// ZGHY_D ¼����ʱ�����
typedef struct
{
    int  m_recpacktime;     // ¼����ʱ�䣨��λ�����ӣ�
    char m_reverse[64];     // ����
} VSNETRECPACKTIME;

// DXHJ ������Ϣ
typedef struct
{
    int m_state;                // ��ǰ״̬
    unsigned int m_totalsize;   // �����ܴ�С
    unsigned int m_freesize;    // ����ʣ��ռ�
    unsigned int m_usedsize;    // ���ÿռ�
} VSNETCDROMINFO;

// DXHJ ����&������Ϣ
typedef struct
{
	int          m_cdcount;       // ��������
	int          m_state[8];      // ������ǰ״̬
	unsigned int m_totalsize[8];  // �����ܴ�С
	unsigned int m_freesize[8];   // ����ʣ��ռ�
	unsigned int m_usedsize[8];   // ���ÿռ�
} VSNETCDROMINFOEX;

// DXHJ ���л�С����λ����Ϣ
typedef struct
{
	unsigned int m_index;            // С����������
	double       m_fRatioLeft;       /* ����������ˮƽ��ʼλ�ñ��� */
	double       m_fRatioTop;        /* ���������Ĵ�ֱ��ʼλ�ñ��� */
	double       m_fRatioWidth;      /* ���������Ŀ�����ű��� */
	double       m_fRatioHeight;     /* ���������ĸ߶����ű��� */
} VSNETVMIXCHANRECT;

// DXHJ ���л�����˳����Ϣ
typedef struct
{
	int   m_cncount;       // �����ܸ���
	short m_order[8];      /* ����˳�� */
} VSNETVMIXORDER;

// DXHJ MAC��ַ
typedef struct
{
    char m_pcmac[20];
} VSNETPCMACADDR;

// DXHJ �������
typedef struct
{
    char m_chator[20];  //��ϢĿ������û���
    char m_chaturl[16]; //��ϢĿ�����IP��ַ
} VSNETCHATTO;

// DXHJ ������Ϣ
typedef struct
{
    VSNETCHATTO m_chatto;
    char m_chatmsg[256];//��Ϣ����
} VSNETCHATMSG;

// DXHJ ¼��״̬֪ͨ
typedef struct
{
    int m_nState;        // ¼��״̬��0Ϊ����1Ϊ¼��ʱ�伴����
    int m_nError;        // ¼��������
    int m_nDeviceType;   // ¼�����洢�豸����
    int m_nDeviceIndex;  // ¼�����洢�豸���
    int m_nTimeRemind;   // ¼��ʣ��ʱ��
} VSNET_DX_SERRECSTATE;

// DXHJ ���һ��¼����Ϣ
typedef struct
{
	int  m_nflag;         //¼��״̬ 0:¼����� 1:¼��δ���
	char m_filepath[256]; //¼���ļ�·��
}VSNET_DX_RECORDFILEPATH;

// DXHJ �ϴ���Ѷ��¼�ĵ�
typedef struct
{
	int  m_loadSign;        //2���������ϴ��ĵ�   1������Զ���ϴ��ĵ�   0������Զ���ϴ�ģ��
	char m_uPfilepath[256]; //��Ѷ��¼�ĵ�·��
}VSNET_DX_UPLOADFILE;
/************************************** DXHJ Custom End ***********************************/

/************************************** SZWJ       Start***********************************/
//SZWJ RTMP���Ʋ���
#define RTMP_CMD_STOP           0   //ֹͣRTMP
#define RTMP_CMD_START          1   //����RTMP 
#define RTMP_CMD_RESET          2   //����RTMP
#define RTMP_CMD_SETPARAM       3   //����RTMP����
#define APP_RTMPHOST_NUM        48 

typedef struct
{
    char                m_hostip[APP_RTMPHOST_NUM];          //����ip
    int                 m_hostport;                          //�����˿�
    char                m_appname[APP_RTMPHOST_NUM];         //Ӧ�ó������Ʋ��ܴ���23���ַ�
    char                m_streamname[APP_RTMPHOST_NUM];      //�����Ʋ��ܴ���47���ַ� 
}VSNETSZWJRTMPPARAM;

typedef struct
{
    int                m_rtmpcmd;                            //rtmp�����
    VSNETSZWJRTMPPARAM m_rtmpparam;                          //RTMP_CMD_SETPARAM����Ĳ���
}VSNETSZWJRTMP;
/************************************** SZWJ Custom End ***********************************/

/************************************** CDTY       Start***********************************/
// CDTY_D WIFI���������
typedef struct
{
	int  m_wifistate;   // wifi״̬��0:δ����, 1:������
	int  m_wifisignal;  // wifi�ź�ǿ��
    int  m_nettype;     // �������ͣ�0-����ģʽ��1-NAT,2-UPNP
} VSNET_CDTY_PARAM;
/************************************** CDTY         End***********************************/

/************************************** HBR       Start***********************************/
// HBR ��̨��������
typedef struct
{
	int  m_serialport; //��̨���ƴ������� 0:485 1:232
}VSNET_SERIALPORT;

typedef struct
{
    char       m_sharpness;      //��� -2������ -1�������� 0 - 9 ���ֵ
    char       re[3];            //����
}VSNETHBEPARAM;
/************************************** HBR         End***********************************/


/************************************** FJTS       Start***********************************/
//FJTS_D ��ȡӲ�����к�
typedef struct
{
	char  m_romno[80];   // Ӳ�����к�
} VSNET_FJTS_ROMNO;
/************************************** FJTS         End***********************************/

/************************************** SHRZ      Start ***********************************/
#define VSNET_SHRZ_ALARMTYPENUM 4

//SD��״̬
typedef struct
{
    int m_loadstate; //SD������״̬:-1-�޿� 0-����ʧ�� 1-���سɹ�
    VSDISKSTATE m_sdstate;//SD����ϸ��Ϣ
} VSNET_SHRZ_SDSTATE;

//3G�ź�ǿ��
typedef struct
{
    int m_signal;
} VSNET_SHRZ_3GSIGNAL;

//����״̬
typedef struct
{
    int m_type;//��������
    int m_state;//״̬:0-δ������1-����
} VSNET_SHRZ_ALARM;

typedef struct
{
    VSNET_SHRZ_ALARM m_alarm[VSNET_SHRZ_ALARMTYPENUM];
} VSNET_SHRZ_ALARMSTATE;
/************************************** SHRZ        End ***********************************/

/************************************** XASY        Start ***********************************/
//����������
typedef struct
{   
    int    m_enable;       //ʹ�ܿ��� 1 - ��; 0 - ��
    float  m_maxquantum;   //����������ֵ����
    float  m_minquantum;   //����������ֵ����
    float  m_dlhvalvemax;  //������������ֵ����
    float  m_dlhvalvemin;  //������������ֵ����
    int    m_dlhprecision; //����
    float  m_dlhadjust;    //ƫ���׼����
    char   m_dlhunit[16];  //��������λ
    char   m_dlhname[56];  //����������
    char   m_dlhmout[4];   //����������������ֵ����������� 1 - ��; 0 - ��
} VSNET_XASY_DLH_QUANTUM_T;

#define APP_DLH_NUM 1                      //�������ϰ����,ĿǰΪ1
#define APP_DLH_CH_NUM      8*APP_DLH_NUM  //���������·��
typedef struct
{
    float  m_currentValue[APP_DLH_CH_NUM]; //����ֵ
}VSNET_XASY_CURRENT_LOOPVALUE;
/************************************** XASY        End ***********************************/

/************************************** SZYW        Start ***********************************/
//������Ƶ����
typedef struct
{
    int    m_state;          //��Ƶ����״̬ 1 - ��; 0 - ��
} VSNET_SZYW_AUDIO_LISTENING;
/************************************** SZYW        End ***********************************/

/************************************** XT        Start ***********************************/
//3D�䱶���ܲ���
typedef struct
{
    int    m_zoom;         // �Ŵ���MAX(h/H, w/W)*255 ��Ϊ0ʱ��ʾ���Ŵ�ֻ�ƶ�
    int    m_x;            // ��������(x/W)*255
    int    m_y;            // ��������(y/H)*255
	int    m_type;         // ��������(�������ݲ�ʹ��)
} VSNET_XT_PELCO_3D;       // ˵�� h:���θ� w:���ο� H:���ڸ� W:���ڿ� ������������:(x,y)

typedef struct
{
    int     m_startx;
    int     m_starty;
    int     m_endx;
    int     m_endy;
}VSNET_XT_3D_POSXY;      // ��ά����


//�������λ�ò���
typedef struct
{
	int    m_x;            // x������
	int    m_y;            // y������
	int    m_z;            // z������
	int    m_reverse[2];   // ����λ
}VSNET_XT_LOCATION;
/************************************** XT        End ***********************************/



/************************************** SXZT        Start ***********************************/
//���ƺ�Σ��Ʒ��Ϣ�ϱ��ṹ��
typedef struct 
{
    unsigned long dwLowDateTime;
    unsigned long dwHighDateTime;
} VSNET_FILETIME;

typedef struct
{
    char    m_szSerId[52];                  //ת�����������
    char    m_szSerName[40];                //��ʱ���豸����
    int     m_nChno;                        //��ʱ�������ͨ����	

    //Σ��Ʒ���
    int         m_bDanger;                  //�Ƿ����Σ��Ʒ��Ϣ
    char    m_szDangerFileName[260];        //Σ��ƷͼƬ��ת���������ϵľ���·��
    VSNET_VCA_PLATERECT m_dgRect;           //��ǰ֡��λ����Σ��Ʒ��ԭʼͼ���е�λ��
    VSNET_FILETIME  m_dgTime;               //Σ��Ʒץ��ʱ�� 

    //�������
    int         m_bPlate;                   //�Ƿ���ڳ�����Ϣ
    char    m_szPtPlateFileName[260];       //����ͼƬ��ת���������ϵľ���·�� 
    char    m_szPtNumber[12];               //���ƺ���
    int     m_nPtColor;                     //������ɫ(0:���� 1:�Ƶ� 2:�׵ף����� 3:�׵ף����� 4:���� 5:���� 6:���� 99:δ֪)
    int     m_nPtTrust;                     //���Ŷ�(0-100)
    VSNET_FILETIME  m_ptTime;               //����ץ��ʱ�� 
    int     m_nPtType;                      //��������(1:������������ 2:С���������� 16:������������ 23:������������ 99:δ֪)
    int     m_nPtCarColor;                  //������ɫ(0:��ɫ 1:���� 2:��ɫ 3:��ɫ 4:��ɫ 5:��ɫ 6:��ɫ 7:��ɫ 8:��ɫ 9:��ɫ 99:���� 255: δ����ʶ��)
    int     m_nPtSpeed;                     //�����ٶ�
    int     m_nPtbrightness;                //��������
    int     m_nPtDirection;                 //�˶�����(0:δ֪���� 1:���ƴ��ϵ����˶� 2:��ʾ���ƴ��µ����˶�)
    int     m_nPtWidth;                     //���ƿ��    
    VSNET_VCA_PLATERECT m_ptRect;           //��ǰ֡��λ���ĳ�����ԭʼͼ���е�λ��
} VSNET_SXZT_DANGER_PLATE;
/************************************** SXZT        End ***********************************/

/************************************** HT          Start *********************************/
typedef struct
{
    int         m_carinfo;                  //Ѳ�쳵��Ϣ��ʾ״̬  (0:����ʾ 1:��ʾ)
    int         m_sensorinfo;               //��������Ϣ��ʾ״̬  (0:����ʾ 1:��ʾ)
    int         m_streaminfo;               //������Ϣ��ʾ״̬    (0:����ʾ 1:��ʾ)
    int         m_ptzinfo;                  //��̨��Ϣ��ʾ״̬    (0:����ʾ 1:��ʾ)
    char        m_carname[20];              //Ѳ�쳵����
}VSNET_HTOSDCTL;

//������������ֵ
/*typedef struct 
{
    float           m_O2_max; //����
    float           m_O2_min; 
    float           m_H2S_max; //H2S
    float           m_H2S_min; 
    float           m_CO_max; //CO
    float           m_CO_min; 
    float           m_burn_max; //��ȼ����
    float           m_burn_min; 
    float           m_temperature_max; //�¶�
    float           m_temperature_min; 
    float           m_humidity_max; //ʪ��
    float           m_humidity_min; 
    float           m_in_tem_max; //�����¶�
    float           m_in_tem_min; 
    float           m_smog_max; //��������
    float           m_smog_min; 
    float           m_bright_max; //���մ�����
    float           m_bright_min; 
    float           m_capacity_max; //����
    float           m_capacity_min; 
    float           m_current_max; //����
    float           m_current_min; 
    float           m_voltage_max; //��ѹ
    float           m_voltage_min; 
    unsigned int    m_reserve[2];//����
}VSNET_HTSENSOR_THRESHOLD;*/

//������ip��Ϣ
typedef struct
{
    char m_robot_ip_addr[16];       //ip��ַ
	int  m_robot_port;              //�˿ں�
}VSNST_HT_ROBOT_ADDR;
/************************************** HT          End **********************************/

/************************************** SZYV        Start*********************************/
typedef struct 
{
    int 		 	bEnable;  	// 1ʹ�� 0���
    unsigned short 	Days;   	// ֻ����bEnableΪ1��ʱ����õ���ֵ,��ʱ����
	unsigned short  reserve;	// ����
}VSNET_SZYW_OVERTIME;
/************************************** SZYV          End **********************************/



/************************************** PowerVersion_ISM      Start*********************************/

//֪ͨ�豸����¼��
typedef struct  
{
	int	 m_nType;// 0 �ֶ�¼�� 1 �ƶ��������������2 ��Ƶ��ʧ����������3 ��Ƶ�ڵ��������� 4δ֪������������
	int  m_nDurableTime; //����ʱ�䣨�룩,����ʱ�䵽�󣬽���¼��
} VSNET_RECORD_LINKAGE; 

//Ԥ�õ���ѵ����
typedef struct
{
	int  m_nPresetNo;   //Ԥ�õ��  ��0 �� 255.         
	int	 m_nDurableTime; //��λ���롣��ǰԤ�õ�ͣ��ʱ�䣺5��-1800��
} VSNET_PTZ_LOOP_ITEM;

#define VSNET_MAX_LOOP_NUM 20

//Ԥ�õ���ѵ����
typedef struct
{
	int                    m_nIndex;		  //��Ѳ�������[0,19]
	int                    m_nNum;            // VSNET_PTZ_LOOP_ITEM �ĸ���
	VSNET_PTZ_LOOP_ITEM    m_loopInfo[VSNET_MAX_LOOP_NUM];   // ÿ��Ԥ�õ���Ϣ ���֧������20��
} VSNET_PTZ_LOOP;  

//�豸״̬
typedef struct
{
	float m_fCpuUse;        // cpuʹ����
	float m_fMemUse;        // �ڴ�ʹ����
	float m_fDiskUse;       // Ӳ��ʹ����
	float m_fNetworkUse;    // ����ʹ����	
} VSNET_SER_SYSTEM_STATUS;

//�趨һ��ʱ���osd����
typedef struct  
{
	int	m_nTitle;        //����λ�ã� 0 �����Ǳ���һ��1�����Ǳ������2���Ǳ�������3���Ǳ����ġ�
	int	m_nDurableTime;  //��λ���롣����OSDʱ�䣺5��-1800�롣������ʱ���ԭΪԭ���ĵ����ַ���
	char m_szString[32]; //�����ַ�
} VSNET_OSD_LINKAGE;

// ������������
typedef struct  
{
	int	m_bEnalbe;      // ��������ʹ��
	int m_nPresetNo;    // �������ܵ��õ�Ԥ�õ�
	int	m_nReturnTime;  // ��λ���룬���ʱ��5-1800�롣����������������������õ�Ԥ�õ����m_nReturnTimeʱ����Զ�����m_nPresetNo���õ�Ԥ�õ㡣
	// ��̨Ԥ�õ���ѵ��������Ԥ�õ�������ȡ�����Ԥ�õ�����ӳ�ʱ���������m_nReturnTimeʱ��󣬵�������Ԥ�õ㡣
} VSNET_PTZ_KEEP;

// ��������Ԥ�õ�
typedef struct  
{
	int m_nPresetNo;    // ��������Ԥ�õ㣬���
	int	m_nDurableTime;  // ͣ��ʱ�䡣��λ���룬���ʱ��5-1800�롣���ڸ�ʱ���ڣ�����������Ч��
} VSNET_PTZ_LINKAGE;

// NVRͨ������
typedef struct  
{
	int m_bEnable;    // ͨ��ʹ��
} VSNET_CHANNEL_ALARM;

/************************************** PowerVersion_ISM       End **********************************/



/************************************** ELF        Start*********************************/

typedef struct
{
    unsigned int m_elf9500_num;   //ת�޻����
    unsigned int m_elf9500_client_port;//UDPͨ����λ���˿ں�
    unsigned int m_elf9500_local_port; //ת�޻�udp�˿ں�
    char         m_elf9500_client_ip[16];//��λ��ip

}VSNET_ELF_PARAM;  //ת�޻�����

typedef struct
{
    int     m_elf_video_time;   //¼���ʱ��
    int     m_elf_passcar_cap_time;//�������ץ�ĺͲɼ���ʱ��
    int     m_elf_heat_beat_time; //�����ݲɼ�����������ʱ��
    int     m_elf_get_data_time;//����������ʱ��
}VSNET_ELF_OVER_TIME;//ת�޻���ʱʱ��

typedef struct
{
    char    m_elf_type;          //ת�޻����ͣ�1:��ͨ����2:������ͨ��
    char    m_elf_ch;           //�����ͨ��ѡ��
    char    m_rev[6];           //Ԥ��6���ֽ�
}VSNET_ELF_CCH_REV;//ת�޻�����ͷͨ����Ԥ���ֽ�

typedef struct
{
    char    m_elf_elect;          //��������
    char    m_elf_flap_start;     //����������
    char    m_elf_flap_way;       //�񶯷���
    char    m_rev[5];             //������ҪҪԤ��2���ֽڣ�����Ϊ���ֽڶ���Ԥ��5���ֽڣ�ʹ��ʱʹ��ǰ2������
}VSNET_ELF_HEAT_PARAM;//ת�޻��������еĲ�������

/************************************** ELF        end*********************************/

/************************************** VINET        Start 

***********************************/
typedef struct
{
    int m_Action;       //״̬  0Ϊ�ָ���1Ϊ��ʼ�Ŵ� 2Ϊ��С
    int m_AreaX;        //
    int m_AreaY;
    int m_AreaWidth;
    int m_AreaHeight;
}VSNET_VINET_3DZOOM;//VINET 3D�Ŵ�
/************************************** VINET        End ***********************************/

/************************************** JXYY_TITLE       Start ***********************************/
typedef enum
{
		OSD_SIZE_16_16 = 0,
		OSD_SIZE_32_16,
		OSD_SIZE_24_24,
		OSD_SIZE_32_32,
		OSD_SIZE_48_48,
		OSD_SIZE_64_64,
        OSD_SIZE_128_128,
        OSD_SIZE_128_256,
		OSD_SIZE_END
}VSNET_OSD_SIZE_E;//�����ַ���ʾ��С

typedef struct
{
    int x;
    int y;
    int osd_size;//osd��С����
    char lpstr[48];
}VSNET_JXYY_TITLE;

typedef struct
{
    int x;
    int y;
    int osd_size;//osd��С���� VSNET_OSD_SIZE_E
}VSNET_JXYY_TIME;

typedef struct
{
    VSNET_JXYY_TIME  m_time[4];
    VSNET_JXYY_TIME  m_bit[4];
    VSNET_JXYY_TITLE m_title[4][8];//4������ÿ������8������
}VSNET_JXYY_OSD;


/************************************** JXYY_TITLE End ***********************************/

/************************* HMDL Start *************************/
#define HM_ALARMHOST_CH_COUNT     12    // ��������ͨ����

typedef struct
{
	int  m_enable;		  // ʹ��
	char m_hostname[64];  // ������������
	char m_ip[32];		  // ��������IP
	char m_netmask[32];	  // ����������������
	char m_gateway[32];   // ������������
	int  m_DTP_port;      // ���������˿�(Datastream Target port)
	int  m_P2P_port;	  // ���������˿�(P2P/GCL Target/local Port)
}VSNET_HM_ALARMHOST_BASEINFO; // ����������������

typedef struct
{
	int	 m_enable;	     // ʹ��
	int	 m_flag;		 // 0\1 ��Ǵ������(0 - ������1 - ����)
	char m_chname[64];	 // ��������ͨ������
}VSNET_HM_ALARMHOST_CHANNELINFO_ITM;

typedef struct
{
    VSNET_HM_ALARMHOST_CHANNELINFO_ITM m_alarmhost_chinfo[HM_ALARMHOST_CH_COUNT];
}VSNET_HM_ALARMHOST_CHANNELINFO; // ��������ͨ������

typedef struct
{
	int m_alarm_type;		// �������ͣ�������� - 0 ���� - 1
	int m_record_enable;	// ¼��ʹ��
	int m_nvr_ch;			// NVR ¼��ץ��ͨ��
	int m_ptz_enable;		// Ԥ��λʹ��
	int m_ptz_preset;		// Ԥ�õ��
	int m_capture_enable;	// ץ��ʹ��
}VSNET_HM_ALARMHOST_LINKAGE_ITM;

typedef struct
{
	VSNET_HM_ALARMHOST_LINKAGE_ITM m_linkage[HM_ALARMHOST_CH_COUNT];
}VSNET_HM_ALARMHOST_LINKAGE; // ��������ͨ��������������
/************************** HMDL End **************************/

typedef struct
{
    short m_x;
	short m_y;
	short m_wide;
	short m_high;
}VSNET_BLACKCLIPPING_INFO; // �ڱ߲ü���Ϣ

//�����ȳ���osd�����¶���Ϣ 
typedef struct
{
    unsigned short m_tmp_x;      //x����
    unsigned short m_tmp_y;      //y����
    float m_tmp_value;          //�¶�ֵ
} VSNET_HT_TMP_VALUE;

typedef struct
{
    VSNET_HT_TMP_VALUE m_tmp_max;   //����¶�
    VSNET_HT_TMP_VALUE m_tmp_min;   //����¶�
    float m_tmp_avg;                //ƽ���¶�
    unsigned short m_lenth;         //ԭʼͼ��ĳ���
    unsigned short m_width;         //ԭʼͼ��Ŀ��
} VSNET_HT_TMP_OSD;

typedef struct
{
    char m_osdstr_l[20][50];           //��OSD��������
    char m_osdstr_r[20][50];           //��OSD��������
} VSNET_ROBOT_OSD;


/************************** GW CENSOR BEGIN **************************/

typedef struct
{
	int	m_ch; 		  // 0 - 15
	int	b_enable; 	  // 1: ���� 0: ����		    
}VSNET_GW_SENSOR_DEFENCE_INFO; // ̽ͷ����/������Ϣ

/************************** GW CENSOR ENd ****************************/

typedef struct
{
    int m_msxenable;      //msxʹ��[��:0,��:1]
    int m_reserved[2];    //Ԥ��
}VSNET_MSXENABLE;

typedef struct
{
    int m_msxstrength;    //msx�ں�ǿ��(��/��/��) 0:�� 1:�� 2:��
    int m_reserved[2];    //Ԥ��
}VSNET_MSXSTRENGTH;

typedef struct
{
    int m_msxdistance;    //msx�ںϾ���[-200, 200]
    int m_reserved[2];    //Ԥ��
}VSNET_MSXDISTANCE;

typedef struct
{
	int m_s32x;     //x����ֵ
	int m_s32y;     //y����ֵ
}VSNET_PIXELCOORD;

typedef struct
{
    int m_filetype;     //0-Radiometric jpeg�� 1-TIFF , 2-8-bit jpeg
    int m_period;       //ץ�ļ������Χ0~60s,0-ָ����ץ��
    int m_reserved[4];  //Ԥ��  m_reserved[0]:0-�ɼ��⣬1-���⣬2-�ɼ���+����
}VSNET_IRSTILLCAPCONFIG;

typedef struct
{
	int                     m_bstart;           //0-ֹͣץ�ģ�1-����ץ��
	int                     m_isadvanced;       //�߼����ñ�־��=1֧�ָ߼����ã������߼����ò�����Ч
	VSNET_IRSTILLCAPCONFIG  m_advanced;         //�߼�����
}VSNET_IRSTILLCAPTURE;                        //�����豸ץ��

typedef struct
{
    int m_tempunit;         //�¶ȵ�λ 0-�棬1-�H
    int m_emissivity;       //������ x 100,��Χ0~50
    int m_skycond;          //�������
    int m_humidity;         //ʪ�� 
    int m_airtemp;          //�����¶ȣ���λ��
    int m_bkgtemp;          //�����¶ȣ���λ��
    int m_airtrans;         //���������� x 1000
    int m_targetdistance;   //Ŀ�����
    int m_reserved[8];      //Ԥ��
}VSNET_IRRADCONFIG;

typedef struct
{
	int                     m_osdenable;        //0-���ã�1-����  
	int                     m_isadvanced;       //�߼����ñ�־��=1֧�ָ߼����ã������߼����ò�����Ч
	VSNET_IRRADCONFIG       m_advanced;         //�߼�����
}VSNET_IRRADCONFIGURE;                        //�����������

typedef struct
{
    char m_bri;             // ���ȣ�[-128,128]
    char m_con;             // �Աȶȣ�[16,48]
    char m_res[2];          // ����
} VSNET_IR_VIPARAM;       // �������ȡ��ԱȶȲ�������

typedef struct
{
    char m_en;              // DDE���أ�1 ʹ�ܣ�0 ����
    char m_level;           // DDE����0 �ͣ�1 �У�2 ��
    char m_res[2];          // ����
} VSNET_IR_DDEPARAM;      // ����DDE��������

typedef struct
{
    int m_mode;             // �Զ�������ԣ�0 ƽ����-����£�1 �����-�����
} VSNET_IR_STRETCHMODE;     // ���������������

typedef struct
{
    int m_devtype;          // 
    int m_resolution;       // 640:640x512, 320:320x256, 336:336x256
    int m_lens_hfov;        // in deg
    int m_frame_rate;       // 6:60Hz, 9:9Hz
} VSNET_IRINFO_S;           // ��������ͷ��Ϣ

//
typedef struct
{
	int m_BBCount;          //��У׼�ĺ������� ��Ĭ��Ϊ5
} VSNET_IR_BBCALICOUNT;     //����У׼������Ϣ

typedef struct
{
	int m_BBNo;             //�����ţ���0��ʼ���
	int m_BBtemp;           //�����¶ȣ���λC   
} VSNET_IR_BBCALIINFO;      //����У׼��Ϣ

typedef struct
{
	unsigned int offset;     //���ݿ���ʼ��ַƫ����
	unsigned int datasize;   //���ݿ��С
} VSNET_FLASH_DATA;

typedef struct
{
	int    m_VisEn;          //�ɼ�����ʹ��
	int    m_IREn;           //������ʹ��
	int    m_reserve[3];     //����
} VSNET_IR_MARKPARAM;        //PCBԤ����ʾ��ǲ���

typedef struct
{
	int    datavalid;       //���ݿ���Ч 12��ʾ��Ч
	double adH[9];          //��Ӧ����
	int    offsetx;         //ˮƽƫ��
	int    offsety;         //��ֱƫ��
} SDK_PTE_IMG_REGSTN;       //ͼ��У׼���� flash ƫ��0��PC��˽�����ݴ洢���豸FLASH�У�DEVICE�˲����ģ�


typedef struct
{	
	int             m_hour;      //ʱ	
    int             m_minute;    //��
    int             m_second;    //��
    int             m_msec;      //����
    int             m_state;     //��λ״̬��A = ���ݿ��ã�V = ���ݲ����á�
    double          m_lat;       //γ��
    int             m_lat_zone;  //γ�����֣�������N�����ϰ���(S)
    double          m_lon;       //����
    int             m_lon_zone;  //�������֣�����E�����������W������
    float           m_height_msl;		 //��ƽ��߶�
    float           m_speed;     //���λ���ٶȣ�0.0 �� 1851.8 knots 
    float           m_heading;   //���λ�Ʒ���000.0 �� 359.9��
    int             m_year;      //��
    int             m_month;     //��
    int             m_day;       //��
    int             checksum1;   //У��ֵ1
    int             m_moon_line; //������յ�Ѷ�ŵ���������
    int             m_moon_fixed;//��λ����������
    int             m_moon_num;  //����е�����������00 �� 12
    int             m_number;    //���Ǳ��
    int             m_noise;     //Ѷ�������ȣ�C/No���� 00 �� 99 dB���ޱ�δ���յ�Ѷ��
    int             checksum2;   //У��ֵ2
    char            reserve[20];
}VSNET_GPSINFO;

typedef struct 
{
    
    int x;//ͼ�������Ͻ���ʾ������ 
    int y;//ͼ�������Ͻ���ʾ������ 
    int w;//ͼ������� x+w ��[0,10000]
    int h;//ͼ�����߶� y+h ��[0,10000]
}_tagCALTEMPINAREA;

typedef struct  
{
    _tagCALTEMPINAREA area[TEMP_AREA_NUM];
}VSNET_CALTEMPINAREA;//�������


/*********************�������� beg*************************/
typedef enum {
    PROTOCOL_PWM = 0,
    PROTOCOL_MAVLINK,
    PROTOCOL_CVBS,
    PROTOCOL_END,
}SERIAL_PROTOCOL_TYPE;

typedef enum
{
    EN_CFL_DISABLED = 0,    /////����
    EN_CFL_IR_COLOR_LUT,                /////��ɫ��
    EN_CFL_IR_SCENE,                    /////����
    EN_CFL_RECORD_MODE,                 /////¼��ģʽ
    EN_CFL_RECORD_STATUS,               /////¼�ƿ���״̬
    EN_CFL_IR_ZOOM,                     /////����䱶
    EN_CFL_VIS_ZOOM,                    /////�ɼ���䱶
    EN_CFL_IR_DO_FFC,                   /////FFC
    EN_CFL_IR_ROI,                      /////����Ȥ����
    EN_CFL_IR_SCENE_LOCK,               /////��������
    EN_CFL_SYNC_SIGNAL,                 /////ͬ���ź�,����PWM1
    EN_CFL_DISPLAY_VIDEO_MODE,          /////��Ƶ��ʾģʽ
    EN_CFL_RECORD_SNAPHOT,              /////¼��������ֶ�ץ��
    EN_CFL_END,                         /////

}PWM_FUNC_LIST;

typedef enum {
    IR_COLOR_WHITEHOT = 0,
    IR_COLOR_BLACKHOT,
    IR_COLOR_FUSION,
    IR_COLOR_RAINBOW,
    IR_COLOR_GLOWBOW,
    IR_COLOR_IRONBOW = 5,
    IR_COLOR_GREYRED,
    IR_COLOR_SPEIA,
    IR_COLOR_LAVA,
    IR_COLOR_COLOR,
    IR_COLOR_INSTALERT,
    IR_COLOR_RAIN,
    IR_COLOR_REDHOT,
    IR_COLOR_GREENHOT,
    IR_COLOR_ARCTIC,

    IR_COLOR_HOTMETAL = 100,

    IR_COLOR_WHITEHOT_ISO = 200,
    IR_COLOR_BLACKHOT_ISO,
    IR_COLOR_FUSION_ISO,
    IR_COLOR_RAINBOW_ISO,
    IR_COLOR_GLOWBOW_ISO,
    IR_COLOR_IRONBOW_WHITEHOT_ISO,
    IR_COLOR_IRONBOW_BLACKHOT_ISO,
    IR_COLOR_SPEIA_ISO,
    IR_COLOR_MIDRANGE_WHITEHOT_ISO,
    IR_COLOR_MIDRANGE_BLACKHOT_ISO,
    IR_COLOR_ICEFIRE_ISO,
    IR_COLOR_RAINBOWHC_ISO,
    IR_COLOR_REDHOT_ISO,
    IR_COLOR_GREENHOT_ISO2RANGE,
    IR_COLOR_ARCTIC_BLACKHOT_ISO,

    IR_COLOR_END,
}IR_COLOR_LUT_TYPE;


typedef enum
{
    IR_SCENE_DEFAULT = 0,
    IR_SCENE_LINEAR,
    IR_SCENE_SEAORSKY,
    IR_SCENE_OUTDOOR,
    IR_SCENE_INDOOR,
    IR_SCENE_MANUAL,
    IR_SCENE_CUSTOM1,
    IR_SCENE_CUSTOM2,

    IR_SCENE_MARITIME,
    IR_SCENE_SAR,
    IR_SCENE_FIRE,
    IR_SCENE_AGRICULTURE,
    IR_SCENE_INSPECTION,
    IR_SCENE_WDR,
    IR_SCENE_CONTRAST,

    IR_SCENE_END,
}IR_SCENE_TYPE;

typedef enum {
    RECORD_MODE_VIDEO = 0,
    RECORD_MODE_STILL_CAPTURE,
}RECORD_MODE_TYPE;

typedef enum
{
    RECORD_STOP = 0,
    RECORD_START,
    RECORD_STATUS_END,
}RECORD_STATUS_TYPE;


typedef enum
{
    IR_ZOOM_X100 = 0,
    IR_ZOOM_X200,
    IR_ZOOM_X400,
    IR_ZOOM_END,
}IR_ZOOM_TYPE;

typedef enum
{
    VISIBLE_ZOOM_X100 = 0,
    VISIBLE_ZOOM_X200,
    VISIBLE_ZOOM_X400,
    VISIBLE_ZOOM_END,
}VISIBLE_ZOOM_TYPE;

//typedef enum
//{
//    IR_DO_FFC_0 = 0,
//    IR_DO_FFC_1,
//    IR_DO_FFC_END,
//}IR_DO_FFC_TYPE;

typedef enum
{
    IR_ROI_0 = 0,
    IR_ROI_10,
    IR_ROI_25,
    IR_ROI_33,
    IR_ROI_50,
    IR_ROI_66,
    IR_ROI_75,
    IR_ROI_100,
    IR_ROI_END,
}IR_ROI_TYPE;

//typedef enum
//{
//    IR_SCENE_LOCK_DISABLE = 0,
//    IR_SCENE_LOCK_ENABLE,
//    IR_SCENE_LOCK_END,
//}IR_SCENE_LOCK_TYPE;

//typedef enum {
//    SYNC_SIGNAL_VAL = 1,
//    SYNC_SIGNAL_END,
//}SYNC_SIGNAL_TYPE;


typedef enum {
    DISPLAY_VIDEO_MODE_IR = 0,
    DISPLAY_VIDEO_MODE_VISIBLE,
    DISPLAY_VIDEO_MODE_PIP,
    DISPLAY_VIDEO_MODE_END,
}DISPLAY_VIDEO_MODE_TYPE;


typedef enum {
    PWM_STATE_LOW = 0,
    PWM_STATE_HIGH,
    PWM_STATE_MED,
    PWM_STATE_END,
}PWM_STATE;

typedef enum _MAVLINK_SERIAL_BAUD{
    MAVLINK_SERIAL_BAUD_57600   = 57600,
    MAVLINK_SERIAL_BAUD_115200  = 115200,
    MAVLINK_SERIAL_BAUD_230400  = 230400,
}MAVLINK_SERIAL_BAUD;


typedef struct
{
    int func;                           //ͨ�����ܣ�����ΪPWM_FUNC_LIST
    int statenum;                       //ͨ����λ  2-�ߵ͵� 3-���е�3�� ������Ч
    int state[PWM_STATE_END];           //״ֵ̬
}VSNET_PWM_INFO;//ͨ����λ��Ϣ

typedef struct
{
    int	baudrate;                       //������
    int reserve[3];                     //����
}VSNET_MAVLINK_INFO;//ͨ����λ��Ϣ

typedef struct
{
    int reserve[4];                     //����
}VSNET_CVBS_INFO;//ͨ����λ��Ϣ

#ifndef PWM_NUM_MAX
#define PWM_NUM_MAX 4
#endif

typedef struct
{
    int                 protype;            //�������ͱ��,����ΪSERIAL_PROTOCOL_TYPE
    VSNET_PWM_INFO      pwm[PWM_NUM_MAX];   //PWMģʽʱʹ��
    VSNET_MAVLINK_INFO	mavlink;            //MAVLINKģʽʱʹ��
    VSNET_CVBS_INFO     cvbs;               //CVBSģʽʱʹ��
}VSNET_SERIAL_PROTOCOL;
/***********************�������� end***************************/

typedef enum {
    ALARM_LINK_NONE = 0,
    ALARM_LINK_NOTIFY = (1 << 0), //����֪ͨ
    ALARM_LINK_SNAPSHOT = (1 << 1), //����ץ��
    ALARM_LINK_RECORD = (1 << 2), //����¼��
    ALARM_LINK_END,
}TEMP_ALARM_LINK_TYPE;

typedef struct
{
    int             enH;                //���±���ʹ��
    int             tempH;              //���� (��)
    int             enL;                //���±���ʹ��
    int             tempL;              //���� (��)
    int             linkaction;        //��������, ��TEMP_ALARM_LINK_TYPE����

    int             snapshots;          //��������ץ������ץ�Ĵ���(�������3��)
    //int             recordduration;     //��������¼��ʱ��
    //int             indicator;          //ָʾ
    int             reserve[4];         //����
}VSNET_TEMP_ALARM_PARAM;

typedef struct {
    int     TempUnit;               //�¶ȵ�λ��0 - C, 1 - F
    int     OSDTempMeter;           //����� 0 - ��ʹ��, 1 - ���ĵ���£�2-��������
    int     Emissivity;             //�����ʣ���Χ50 ~ 100(uranus:0~100)
    int     AirTemp;                //�����¶ȣ���Χ-50 ~ 127��(uranus:-50~327)
    int     SkyCond;                //�����������Χ0 ~ 100(uranus:0 25 75)
    int     Humidity;               //ʪ�ȣ���Χ0 ~ 100(uranus:30 45 60)
    int     SubjectDistance;        //Ŀ����룬��Χ0 ~ 2000 ��(uranus:500)
    int     reserve[4];             //����
}VSNET_RADIOMETRY_PARAM;

// 0:FFF, 1:TIFF, 2:RAW, 3:JPG, 4:LCR
typedef enum 
{
    VSNET_CAPTURE_TYPE_FFF = 0,                   
    VSNET_CAPTURE_TYPE_TIFF = 1,                   
    VSNET_CAPTURE_TYPE_RAW = 2,
    VSNET_CAPTURE_TYPE_JPG = 3,
    VSNET_CAPTURE_TYPE_LCR = 4,
    VSNET_CAPTURE_TYPE_END                                
} VSNETCAPTURETYPE;

#if defined(GE01_FACTORY)
/*digital output******************/
typedef enum 
{
    VSNET_DIGITAL_OUTPUT_CMOS          = 0x00,                    
    VSNET_DIGITAL_OUTPUT_14BIT_RAW     = 0x01,                                 
    VSNET_DIGITAL_OUTPUT_LVDS          = 0x02,                   
    VSNET_DIGITAL_OUTPUT_TYPE_END                               
} VSNETIRDIGITALOUTPUTTYPE;

typedef enum 
{
    VSNET_DIGITAL_OUTPUT_CMOS_DISABLE      = 0x00,
    VSNET_DIGITAL_OUTPUT_BT656             = 0x01,                            
    VSNET_DIGITAL_OUTPUT_CMOS_8BIT_YUV     = 0x02,
    VSNET_DIGITAL_OUTPUT_CMOS_14BIT_RAW    = 0x03,
    VSNET_DIGITAL_OUTPUT_CMOS_MODE_END                               
} VSNETIRDIGITALOUTPUTCMOSMODE;
typedef struct
{
    unsigned char m_type;//�μ� VSNETIRDIGITALOUTPUTTYPE
    unsigned char m_mode;
}VSNETIRDIGITALOUTPUT;  //�����о������Ƶ���ģʽ

/*sensor temp******************/
typedef enum 
{
    VSNET_FPA_TEMP_X100                    = 0x00,
    VSNET_HOUSEING_TEMP_X100               = 0x01,                            
    VSNET_SHUTTER_TEMP_X100                = 0x02,
    VSNET_SENSOR_TEMP_END                  = 0x08                               
} VSNETIRSENSORTYPE;

typedef struct
{
    unsigned int    m_typemask;                     
    unsigned short  m_tempC[VSNET_SENSOR_TEMP_END];//��λC���μ� VSNETIRSENSORTYPE
}VSNETIRSENSORTEMP;  //�����о�������¶�
/*FFC PARAMS******************/
typedef enum 
{
    VSNET_FFC_MANUAL           = 0x00,//�ֶ�                     
    VSNET_FFC_AUTO             = 0x01,//�Զ�                                
    VSNET_FFC_EXTERNAL         = 0x02,//�ⲿ                 
    VSNET_FFC_MODE_END                                
} VSNETIRFFCMODE;

typedef struct
{
    unsigned char   m_mode;         //�μ� VSNETIRFFCMODE
    unsigned char   m_reserve[3];   //����
    unsigned int    m_periods;      //�Զ����ţ�ʱ�����ڣ���λ֡��
    unsigned int    m_tempdelta;    //�Զ����ţ��¶Ȳ��λ0.1C
}VSNETIRFFCPARAMS;  //������Ų���
/*GSK & GFID ��ѹ******************/
typedef struct
{
    unsigned char   m_type;         //0-GSK,1-GFID
    unsigned char   m_reserve;      //����
    unsigned short  m_voltage;      //��ѹ����λ0.1V; GSK-(1.7~3.6)V, GFID-(1~2.9)V
}VSNETIRREGISTERVOLTAGE;  //����̽�����Ĵ�����ѹ����
/*����/ʱ���˲�******************/
typedef enum
{
    VSNET_DENOISE_TIME_DOMAIN_FLITERING = 0x00,///<  Time domain filtering   
    VSNET_DENOISE_OTHER = 0x01,
    VSNET_DENOISE_TYPE_END,
} VSNETIRDENOISETYPE;
/*����/ʱ���˲�******************/
typedef struct
{
    unsigned char   m_enable;       //0-��ʹ�ܣ�1-ʹ��
    unsigned char   m_type;         //�����㷨,VSNETIRDENOISETYPE
    unsigned char   m_value;        //�˲�ϵ������Χ0~100
    unsigned char   m_reserve;   //����
}VSNETIRDENOISEPARAMS;  //���⽵��������ֳ�ʱ���˲�
/*��������ѡ��******************/
typedef struct
{
    unsigned char   m_index;        //��������������֧��6�����򣬴�0��ʼ����Χ0 ~5
    unsigned char   m_reserve[3];   //����
}VSNETIRTEMPREGIONS;//�����������ѡ��

/*дFLASH******************/
typedef enum 
{
    VSNET_FLASH_TYPE_K                     = 0x00,                   
    VSNET_FLASH_TYPE_B                     = 0x01,                   
    VSNET_FLASH_TYPE_BLIND                 = 0x02,
    VSNET_FLASH_TYPE_SENSOR                = 0x03,
    VSNET_FLASH_TYPE_FPGA_FW               = 0x04,
    VSNET_FLASH_TYPE_END                                
} VSNETFLASHTYPE;

typedef struct
{
    unsigned char   m_type;         //�μ� VSNETFLASHTYPE
    unsigned char   m_index;        //����
    unsigned char   m_reserve[2];   //����
}VSNETIRWRITEFLASH;//����дFLASH

typedef struct
{
    unsigned char   m_HighToLowTempThreshold;//[50, 160], ��λC
    unsigned char   m_HighToLowPopulationThreshold;//[0, 100]
    unsigned char   m_HLowToHighTempThreshold;// [50, 160], ��λC
    unsigned char   m_LowToHighPopulationThreshold;// [0, 100]
}VSNETIRGAINSWITCHPARAMS;//�����Զ������л�

typedef struct
{
    unsigned short   m_CINT;///< ���ֵ��ݣ���λ 0.1PF
    unsigned short   m_TINT;///< ����ʱ��,����λPSYNC����
}VSNETIRGAININTERGRATIONPARAMS;//����������ֲ���

typedef struct{
	char m_privatestr[128];//˽����ϢԤ��128bytes 
	//��Ϣ��ʽ:ID_��_��_��_ʱ_��_��_����_γ��_�߶�_����_GPS�ƶ��ٶ�_GPS�ƶ�����_����1_����2_����3
}VSNETCDUSR_INFO;//M10�����ͻ�����

typedef struct
{
    unsigned int        m_sd1_space;        //unit: Mb ʣ������
    unsigned int        m_sd1_total_space;  //unit: Mb ������
} VSNETCDUSR_MSDSTATUS;//M10�����ͻ�����
#endif

/* �¶ȶԱȱ������� */
typedef struct
{
    int                	m_enable;           // function enable
	short				m_rgn[2];	        // �Աȵ�����
    int                 m_source;           // ������Դ��0:max, 1:min, 2:avg
    int                 m_typethreshold;    // 0: >m_tempthreshold, 1: <m_tempthreshold
    float               m_tempthreshold;    // TempAlarm Threshold
    int                 m_singlehost;       // label of center for uploading alarm signal
    unsigned char       m_record[16];       // relate to recording
    unsigned char       m_out[8];           // relate to output	1:ON, 0��OFF
    unsigned char       m_enpreno[16];      // relate to preset point
    unsigned char       m_preno[16];        // number of preset point to be called
    unsigned char       m_capjpeg[16];      // relate to capturing
    TIMELIST            m_timelist;         // detection time table define ETI_TIME_DAYTYPE
} VSNETTEMPDIFFALARMPARAM;

//��������
typedef enum
{
    VSNET_TEMPTYPE_REGION = 0,
    VSNET_TEMPTYPE_POINT,
    VSNET_TEMPTYPE_LINE,
    VSNET_TEMPTYPE_END
}VS_TEMPTYPE;

/* ����������� */
typedef struct
{
    int m_temptype[REGIONTEMPNUM];                  //VS_TEMPTYPE
    VSNETREGIONTEMPAREA m_region[REGIONTEMPNUM];    //������²���
}VSNETREGIONTEMPPARAM_EX;

//��ҹ�л�ģʽ
typedef enum
{
    VSNET_DAYNIGHTMODE_AUTO = 0,            //�Զ�
    VSNET_DAYNIGHTMODE_TIME,                //��ʱ��
    VSNET_DAYNIGHTMODE_MANUAL,              //�ֶ�
    VSNET_DAYNIGHTMODE_END
}VSNET_DAYNIGHTMODE;

//�Զ�������ʽ
typedef enum
{
    VSNET_DAYNIGHTTRIG_LEVEL_LOWDAY = 0,    //��ƽ
    VSNET_DAYNIGHTTRIG_VALUE_HIGHDAY,       //��ֵ
    VSNET_DAYNIGHTTRIG_END
}VSNET_DAYNIGHTTRIG;

// ��ҹ�л�����
typedef struct
{
    int                 m_mode;             // VSNET_DAYNIGHTMODE
    int                 m_trig;             // VSNET_DAYNIGHTTRIG���Զ��л�ʱ��Ч
    int                 m_day;              // ������ֵ��ȡֵ��Χ0~255���Զ��л���ֵ����ʱ��Ч
    int                 m_night;            // ҹ����ֵ��ȡֵ��Χ0~255���Զ��л���ֵ����ʱ��Ч
    VSNET_DAYNIGHTTIME  m_daynighttime[2];  // ��ʱ���л�ʱ��Ч
    int                 m_ircut;            // 0:���죬1:��ҹ
    int                 m_color2black;      // 0:��ɫ��1:�ڰ�
    int                 m_lamp;             // ����ƣ�1:�򿪣�0:�ر�
}VSNET_DAYNIGHTPARAM;

typedef struct
{
    char                m_osdstr[32];
}VSNET_REGIONOSD;

// �������osd����
typedef struct
{
    VSNET_REGIONOSD     m_rgnosd[REGIONTEMPNUM];
}VSNET_REGIONOSDPARAM;

// ��ɫ�����
typedef enum
{
    VSNET_COLOUR_HOTMETAL                = 0,//�Ƚ���
    VSNET_COLOUR_RAINBOW                 = 1,//�ʺ�
    VSNET_COLOUR_WHITEHOT                = 2,//�ڰ�(����)
    VSNET_COLOUR_BLACKHOT                = 3,//����
    VSNET_COLOUR_GLOBOW                  = 4,
    VSNET_COLOUR_IRONBOW1                = 5,
    VSNET_COLOUR_IRONBOW2                = 6,
    VSNET_COLOUR_SEPIA                   = 7,
    VSNET_COLOUR_COLOUR1                 = 8,
    VSNET_COLOUR_COLOUR2                 = 9,
    VSNET_COLOUR_ICEFIRE                 = 10,
    VSNET_COLOUR_RAIN                    = 11,
    VSNET_COLOUR_REDHOT                  = 12,
    VSNET_COLOUR_GREENHOT                = 13,
    VSNET_COLOUR_GREYRED                 = 14,
    VSNET_COLOUR_LAVA                    = 15,
    VSNET_COLOUR_INSTALERT               = 16,
    VSNET_COLOUR_ARCTIC                  = 17,
   
    VSNET_COLOUR_END
}VSNET_COLORMAP;

typedef struct
{
    int                 m_osd_enable;        //ȫ��IROSD����ʹ�ܿ��� 0:�ر� 1:����
    int                 m_ir_temp_enable;    //����ȫ�ֲ��µ���ʹ�� 0:�ر� 1:����
    int                 m_ir_param_enable;   //����ȫ�ֲ��²�������ʹ�� 0:�ر� 1:��������Ч
    int                 m_ir_strip_enable;   //����α��ɫ������ʹ�� 0:�ر� 1:��������Ч
    int                 m_ir_cursor_enable;  //����ߵ��¹�����ʹ�� 0:�ر� 1:����
}VSNETIROSD2VISPARAM;//ע: ������µ��Ӽ���������m_osd_enable����!

/****************���ܷ�����ز��� start******************/
#define VSNET_MAX_POINT_NUM          15   
#define VSNET_MAX_DEFENSE_NUM        4   

typedef struct
{
    int     m_x;
    int     m_y;
}VSNET_SMART_ANALYSIS_POINT;

//�����������ܷ����������
typedef struct
{
    int                         m_point_num;  //����Σ����15����15����
    VSNET_SMART_ANALYSIS_POINT  m_reg[VSNET_MAX_POINT_NUM];
}VSNET_SMART_ANALYSIS_CHECKREGPARAM;

//��������
typedef struct
{
    VSNET_SMART_ANALYSIS_CHECKREGPARAM  m_shield_reg[VSNET_MAX_DEFENSE_NUM];
}VSNET_SMART_ANALYSIS_SHIELDREGPARAM;


//����Ŀ��
typedef struct
{
    int     m_maxsize_w;     //Ŀ��������ߴ��
    int     m_maxsize_h;     //Ŀ��������ߴ��     
    int     m_minsize_w;     //Ŀ�������С�ߴ��
    int     m_minsize_h;     //Ŀ�������С�ߴ��
}VSNET_SMART_ANALYSIS_TARGETFILTERPARAM;

//�߼�����
typedef struct
{
    int     m_stable_enable;             //�Ŷ�ʹ��(����)
    int     m_sensitive;                 //������(0 - 100)����ֵԽ��������Խ��
    int     m_bkgd_flush_speed;          //ÿ������֡����1�α���
    int     m_target_rectangle_enable;   //Ŀ����ο�ʹ��
    int     m_reserve[4];                //����
}VSNET_SMART_ANALYSIS_ADVANCEPARAM;

//������
typedef struct
{
    int                         m_enable;       //������ʹ��
    VSNET_SMART_ANALYSIS_POINT  m_start_point;
    VSNET_SMART_ANALYSIS_POINT  m_end_point;
    int                         m_direction;    //  0: ����(B->A) 1: ����(A->B) 2: ˫��(A<->B)
}VSNET_SMART_ANALYSIS_LINEPARAM;

typedef struct
{
    VSNET_SMART_ANALYSIS_LINEPARAM  m_line[VSNET_MAX_DEFENSE_NUM];  
}VSNET_SMART_ANALYSIS_CORDONPARAM;

//���ܷ��������ز���(���������뿪������Ʒ��������Ʒ����)
typedef struct
{
    int                                 m_enable;    //ʹ��
    VSNET_SMART_ANALYSIS_CHECKREGPARAM  m_region[VSNET_MAX_DEFENSE_NUM];
}VSNET_SMART_ANALYSIS_INFOPARAM;

typedef enum
{
    EN_SM_ANAL_CORDON = 0,
    EN_SM_ANAL_REGIONENTRY,
    EN_SM_ANAL_REGIONLEAVE,
    EN_SM_ANAL_GOODSLEFT,
    EN_SM_ANAL_GOODSMOVE,
    EN_SM_ANAL_MAX,
};

/*���ܷ����ṹ*/
typedef union
{
	VSNET_SMART_ANALYSIS_CORDONPARAM    m_cordon;
    VSNET_SMART_ANALYSIS_INFOPARAM      m_smart_analysis_info;
}VSNET_SMART_ANALYSIS;

typedef struct
{
	int                     m_analysistype;//���� 
	VSNET_SMART_ANALYSIS    m_analysis;
}VSNET_SMART_ANALYSIS_CONFIGPARAM;
/****************���ܷ�����ز��� end******************/

typedef struct
{
    float               m_wintemp_offset;       ///<�����¶Ȳ���
}VSNETWINCALIBPARAM;/*���ڲ��������������¶�У׼*/

//sensor�汾��
typedef struct
{
	unsigned char m_sensor_version[8];//�汾��  ʮ����  �ӵ͵�����ʾ  ��ʾ��Ҫ�������'.' �� 1.2.3.4.5.6.7.8
}VSNETSENSORVERSION;

#endif// __VSNET_STRUCTDEF_H__

