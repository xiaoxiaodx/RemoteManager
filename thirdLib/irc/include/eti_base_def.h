/*
* ��Ȩ���У��������ʳ����ּ������޹�˾
* ��    �ߣ�HongJun Chen
* �������: 2003-11-15
* $Id: eti_base_def.h,v 1.1.1.1 2006/06/29 12:41:28 administrator Exp $
*/
#ifndef __ETI_BASE_DEF_H__
#define __ETI_BASE_DEF_H__

#define ETI_MAX_CH_PERDSP       2
#define ETI_QCIF_CHANNELS       2

#define ETI_MAX_SUPPORTCH         16  //���в�Ʒ��֧�ֵ����ͨ��
#define APP_PASSWORD_LENGTH       20  //���������ַ�����
#define APP_PTZ_STRING_LEN        60  //��̨���Ʒ����ַ�������
#define APP_TIMECHECK_LISTNUM     7   //�������Զ�¼����ʱ���б����
#define APP_ZTE_TIMECHECK_LISTNUM 32  //ZTE �ƶ����/���뱨��ʱ�����
#define APP_ADDRLIST_NUM          20  //
#define APP_DECLOOP_ITEMNUM       100
#define APP_PPPOE_STRING_SIZE     20
#define APP_PHONE_NUMBER_SIZE     20
#define APP_PPPOE_STRING_SIZE     20
#define APP_PHONE_NUMBER_SIZE     20

#define APP_TITALSTRING_COUNT     4
#define APP_ALARMNAMELENGTH       32

#define ETI_CHAR_816LIB_SIZE      4096    //8*16 ANSC�ֿ��С
#define ETI_HANZI_1616LIB_SIZE    261696  //16*16 ���ֿ��С

#define ETI_MP4_STREAM_AV         0       //�����Ӹ���������
#define ETI_MP4_STREAM_V          1       //��Ƶ������

#define ETI_MP4_BITCTRL_VBR       1       //��Ƶ���ʶ���������
#define ETI_MP4_BITCTRL_CBR       0       //��Ƶ���ʶ����ʿ���

#define ETI_MP4_QUANTIZER_MIN     2       //��Ƶ��С����ϵ��
#define ETI_MP4_QUANTIZER_MAX     31      //��Ƶ�������ϵ��

#define ETI_MP4_BITRATE_MIN       32      //��Ƶ��С���� 32K
#define ETI_MP4_BITRATE_MAX       4000    //��Ƶ������� 4M

#define ETI_MP4_KEYINTERVAL_MIN   12      //��С�ؼ�֡���
#define ETI_MP4_KEYINTERVAL_MAX   200     //���ؼ�֡���

#define ETI_AUDIO_ENCTYPE_MP3   0x55    //MP3
#define ETI_AUDIO_ENCTYPE_G722  0XFE    //G.722
#define ETI_AUDIO_ENCTYPE_G711A 0x13    //G.711A
#define ETI_AUDIO_ENCTYPE_G711U 0x14    //G.711U
#define ETI_AUDIO_ENCTYPE_G726  0x15    //G.726
#define ETI_AUDIO_ENCTYPE_AAC   0x16    //AAC
#define ETI_AUDIO_ENCTYPE_AMR   0x17    //AMR
#define ETI_AUDIO_ENCTYPE_PCM   0x18    //PCM

enum{
    ETI_VIDEOTAG_MPEG4 = 0X58564944,    //DIVX
    ETI_VIDEOTAG_H264  = 0X34363248,    //(('4'<<24) | ('6'<<16) | ('2'<<8) |'H')                //H264
    ETI_VIDEOTAG_MJPEG = 0X47504A4D,    //(('G'<<24) | ('P'<<16) | ('J'<<8) |'M')                //MJPG
    ETI_VIDEOTAG_H265  = 0X35363248,     //(('5'<<24) | ('6'<<16) | ('2'<<8) |'H')                //H265
    ETI_VIDEOTAG_RAW  =  0X00574152,     //(('0'<<24) | ('W'<<16) | ('A'<<8) |'R')                //RAW
    ETI_VIDEOTAG_IR14    =  0x34315249        //('4'<< 24)| ('1' << 16) ('R'<<8) | 'I'            //IR14
};

#define ETI_AUDIO_SAMPLE_RATE_48K        48000
#define ETI_AUDIO_SAMPLE_RATE_44K        44100
#define ETI_AUDIO_SAMPLE_RATE_32K        32000
#define ETI_AUDIO_SAMPLE_RATE_24K        24000
#define ETI_AUDIO_SAMPLE_RATE_22K        22050
#define ETI_AUDIO_SAMPLE_RATE_16K        16000
#define ETI_AUDIO_SAMPLE_RATE_8K         8000

#define ETI_STREAM_STATUS_START          0X00000001    //��������
#define ETI_STREAM_STATUS_STOP           0X00000002    //ֹͣ����
#define ETI_STREAM_STATUS_RECV           0X00000004    //��������
#define ETI_STREAM_STATUS_FTPBACK        0X00000008    //FTP����

#define ETI_ALARM_STATUS_MOTION          0X00000001    //��Ƶ�ƶ�����
#define ETI_ALARM_STATUS_LOSTVI          0X00000002    //��Ƶ��ʧ����
#define ETI_ALARM_STATUS_LOSTAI          0X00000004    //��Ƶ��ʧ����
/********************** ������ʾ***************************/
typedef enum{
    ETI_STREAM_MAIN = 0,                 // ��������ʾ
    ETI_STREAM_SUB1 = 1,                 // ��������ʾ
    ETI_STREAM_SUB2 = 2,                 // ��������ʾ
    ETI_STREAM_SUB3 = 3,                 // ��������ʾ
}ENUM_EIT_STREAMID;

/********************** ����������ʾ***********************/
#define ETI_JPEG_CONTINUEUPLOADFTP    0           //ftp��������
#define ETI_JPEG_CONTINUEUPLOADSDK    1           //sdk��������
#define ETI_RVS_STREAM 100  //RVS�ϴ�����

/********************** �����С***************************/
#define ETI_PREREC_BUFF_SIZE_CIF        0XA2800         //650*1024
#define ETI_PREREC_BUFF_SIZE_2CIF       0XE6000         //920*1024
#define ETI_PREREC_BUFF_SIZE_4CIF       0X14CCC0        //1024*1024*1.3(32�ı���)
/********************** ����ʱ�䶨�� ********************************/
#define ETI_ALARM_MIN_RECTIME            30            //��С��������(¼��/����)ʱ��(s)
#define ETI_ALARM_MAX_RECTIME            3600          //��С��������(¼��/����)ʱ��(s)
/********************** ��Ƶ��ʽ���� ********************************/

#define ETI_MP4_FORMAT_QCIF         0
#define ETI_MP4_FORMAT_CIF          1
#define ETI_MP4_FORMAT_2CIF         2
#define ETI_MP4_FORMAT_4CIF         3
#define ETI_MP4_FORMAT_DCIF         4
#define ETI_MP4_FORMAT_QVGA         5      //320*240
#define ETI_MP4_FORMAT_VGA_60HZ     6      //640*480
#define ETI_MP4_FORMAT_SVGA_60HZ    7      //800*600
#define ETI_MP4_FORMAT_XGA_60HZ     8      //1024*768
#define ETI_MP4_FORMAT_SXGA_60HZ    9      //1280*1024
#define ETI_MP4_FORMAT_UXGA_60HZ    10     //1600*1200
#define ETI_MP4_FORMAT_720P         11     //1280*720, no use
#define ETI_MP4_FORMAT_HDTV         12     //1920*1080, no use
#define ETI_MP4_FORMAT_SVGA_75HZ    13     //800*600
#define ETI_MP4_FORMAT_XGA_75HZ     14     //1024*768
#define ETI_MP4_FORMAT_720P_50HZ    15     //1280*720, 50HZ
#define ETI_MP4_FORMAT_720P_60HZ    16     //1280*720, 60HZ
#define ETI_MP4_FORMAT_1080P_50HZ   17     //1920*1080, 50HZ
#define ETI_MP4_FORMAT_1080P_60HZ   18     //1920*1080, 60HZ
#define ETI_MP4_FORMAT_LTF          19     //240*192
#define ETI_MP4_FORMAT_WQVGA1       20     //480*352
#define ETI_MP4_FORMAT_WQVGA2       21     //480*272
#define ETI_MP4_FORMAT_UVGA_50HZ    22     //1280*960,50HZ
#define ETI_MP4_FORMAT_UVGA_60HZ    23     //1280*960,60Hz
#define ETI_MP4_FORMAT_1080P_30HZ   24     //1920*1080, 30HZ
#define ETI_MP4_FORMAT_1080I_50HZ   25     //1920*1080, 50HZ
#define ETI_MP4_FORMAT_1080I_60HZ   26     //1920*1080, 60HZ
#define ETI_MP4_FORMAT_SXGA_75HZ    27     //1280*1024, 75HZ
#define ETI_MP4_FORMAT_WXGA_60HZ    28     //1280*800, 60HZ
#define ETI_MP4_FORMAT_WXGA_75HZ    29     //1280*800, 75HZ
#define ETI_MP4_FORMAT_SXGAP_60HZ   30     //1400*1050, 60HZ  SXGA+
#define ETI_MP4_FORMAT_SXGAP_75HZ   31     //1400*1050, 75HZ  SXGA+
#define ETI_MP4_FORMAT_WXGAP_60HZ   32     //1440*900, 60HZ  WXGA+
#define ETI_MP4_FORMAT_WSXGAP_60HZ  33     //1680*1050, 60HZ WSXGA+
#define ETI_MP4_FORMAT_WSUVGAP_60HZ 34     //1920*1080, 60HZ WSUVGA+
#define ETI_MP4_FORMAT_1366X768_60HZ 35    //1366*768, 60HZ 
#define ETI_MP4_FORMAT_WXGA_59HZ     36    //1280*800, 60HZ,�Ǳ�
#define ETI_MP4_FORMAT_1280X720_59HZ 37    //1280*720, 60HZ �Ǳ�
#define ETI_MP4_FORMAT_1360X768_60HZ 38    //1360*768, 60HZ
#define ETI_MP4_FORMAT_720P_25HZ     39    //1280*720, 25HZ
#define ETI_MP4_FORMAT_720P_30HZ     40    //1280*720, 30HZ
#define ETI_MP4_FORMAT_1080P_25HZ    41    //1920*1080, 25HZ
#define ETI_MP4_FORMAT_UXGA_25HZ     42    //1600*1200, 25HZ
#define ETI_MP4_FORMAT_XGA_25HZ      43    //1024*768, 25HZ
#define ETI_MP4_FORMAT_SVGA_25HZ     44    //800*600, 25HZ
#define ETI_MP4_FORMAT_QQVGA         45    //160*120
#define ETI_MP4_FORMAT_QNHD          46    //320*180
#define ETI_MP4_FORMAT_NHD           47    //640*360
#define ETI_MP4_FORMAT_A720P_60HZ    48    //960*720, 60HZ
#define ETI_MP4_FORMAT_QXGA_15HZ     49    //2048*1536 15HZ
#define ETI_MP4_FORMAT_QXGA_20HZ     50    //2048*1536 20HZ
#define ETI_MP4_FORMAT_QSXGA_10HZ    51    //2592*1920 10HZ
#define ETI_MP4_FORMAT_UVGA_25HZ     52    //1280*960,25HZ
#define ETI_MP4_FORMAT_UVGA_30HZ     53    //1280*960,30Hz

#define ETI_MP4_FORMAT_VGAX          55     //640*352
#define ETI_MP4_FORMAT_DVGA          56     //960*576

#define ETI_MP4_FORMAT_720x576       58    //576I 25HZ
#define ETI_MP4_FORMAT_720x480       59    //480I 30HZ

#define ETI_MP4_FORMAT_2448x2048_15HZ 60    //ץ�Ļ�500��

#define ETI_MP4_FORMAT_384x288       61    //384*288 

#define ETI_MP4_FORMAT_8M            70   ///* 3840 * 2160 */
#define ETI_MP4_FORMAT_12M           71   ///* 4000 * 3000 */
#define ETI_MP4_FORMAT_IR_VGA        72   ///* 640 * 512 */
#define ETI_MP4_FORMAT_IR_QVGA       73   ///* 320 * 256 */
#define ETI_MP4_FORMAT_IR_MVGA       74   ///* 336 * 256 */

#define ETI_MP4_FORMAT_CUSTOM_QVGA   75   ///* 880 * 496 */
#define ETI_MP4_FORMAT_CUSTOM_1080   76   ///* 1440 * 1080*/


/********************** ��Ƶ֧�ָ�ʽ���� ****************************/
#define ETI_FORMAT_SUPPORT_QCIF     0X00000001
#define ETI_FORMAT_SUPPORT_CIF      0X00000002
#define ETI_FORMAT_SUPPORT_2CIF     0X00000004
#define ETI_FORMAT_SUPPORT_4CIF     0X00000008
#define ETI_FORMAT_SUPPORT_8CIF     0X00000010

#define ETI_FORMAT_VI_NTSC 0
#define ETI_FORMAT_VI_PAL  1

/************************OSD͸��ģʽ******************************/
enum{
    ETI_OSD_MODE_TRANSPARENT = 0,  //͸��
    ETI_OSD_MODE_TRANSLUCENT,      //��͸��
    ETI_OSD_MODE_OPAQUE            //��͸��
};

/********************** ����������� ********************************/
#define ETI_ROUTEDEV_ADSL    0    //ADSL
#define ETI_ROUTEDEV_WBN    1    //���ǿ��
/********************** ��Ƶ�ߴ綨�� ********************************/
#define ETI_MAX_422_STIDE            1440

#define ETI_MAX_IMAGE_WIDTH          704
#define ETI_MAX_IMAGE_HEIGHT_PAL     576
#define ETI_MAX_IMAGE_HEIGHT_NTSC    480

#define ETI_IMAGE_WIDTH_QCIF        176
#define ETI_IMAGE_WIDTH_CIF         352
#define ETI_IMAGE_WIDTH_2CIF        ETI_MAX_IMAGE_WIDTH
#define ETI_IMAGE_WIDTH_DCIF        528
#define ETI_IMAGE_WIDTH_4CIF        ETI_MAX_IMAGE_WIDTH

#define ETI_IMAGE_HEIGHT_QCIF_PAL   144
#define ETI_IMAGE_HEIGHT_QCIF_NTSC  120
#define ETI_IMAGE_HEIGHT_CIF_PAL    288
#define ETI_IMAGE_HEIGHT_CIF_NTSC   240
#define ETI_IMAGE_HEIGHT_2CIF_PAL   ETI_IMAGE_HEIGHT_CIF_PAL
#define ETI_IMAGE_HEIGHT_2CIF_NTSC  ETI_IMAGE_HEIGHT_CIF_NTSC
#define ETI_IMAGE_HEIGHT_DCIF_PAL   384
#define ETI_IMAGE_HEIGHT_DCIF_NTSC  320
#define ETI_IMAGE_HEIGHT_4CIF_PAL   ETI_MAX_IMAGE_HEIGHT_PAL
#define ETI_IMAGE_HEIGHT_4CIF_NTSC  ETI_MAX_IMAGE_HEIGHT_NTSC

#define ETI_MAX_IMAGE_WIDTH_QVGA    320
#define ETI_MAX_IMAGE_HEIGHT_QVGA   240
#define ETI_MAX_IMAGE_WIDTH_VGA     640
#define ETI_MAX_IMAGE_HEIGHT_VGA    480
#define ETI_MAX_IMAGE_WIDTH_SVGA    800
#define ETI_MAX_IMAGE_HEIGHT_SVGA   600
#define ETI_MAX_IMAGE_WIDTH_XGA     1024
#define ETI_MAX_IMAGE_HEIGHT_XGA    768
#define ETI_MAX_IMAGE_WIDTH_SXGA    1280
#define ETI_MAX_IMAGE_HEIGHT_SXGA   1024
#define ETI_MAX_IMAGE_WIDTH_UXGA    1600
#define ETI_MAX_IMAGE_HEIGHT_UXGA   1200

#define ETI_MAX_IMAGE_WIDTH_720P    1280
#define ETI_MAX_IMAGE_HEIGHT_720P   720
#define ETI_MAX_IMAGE_WIDTH_HDTV    1920
#define ETI_MAX_IMAGE_HEIGHT_HDTV   1080
#define ETI_MAX_IMAGE_WIDTH_QXGA    2048
#define ETI_MAX_IMAGE_HEIGHT_QXGA   1536
#define ETI_MAX_IMAGE_WIDTH_QSXGA   2592
#define ETI_MAX_IMAGE_HEIGHT_QSXGA  1920
#define ETI_MAX_IMAGE_WIDTH_UVGA    1280
#define ETI_MAX_IMAGE_HEIGHT_UVGA   960

/*************************�����Ƶ֡��С**************************/
#define ETI_MAX_IMAGE_FRAMESIZE        (1536*1024)    //�����Ƶ֡��С1.5MB
/*************************�����Ƶ����****************************/
#define ETI_MAX_AUDIO_BITRATE        64            //�����Ƶ����64Kb
/****************ͨ�����ͼ�����ο���*****************/
#define ETI_MAX_COVER_REGION 4
/******************���ͼ�����γߴ�*******************/
#define ETI_VIDEOMASK_MAXWIDTH        352
#define ETI_VIDEOMASK_MAXHEGITH       288
/*****************************************************/
#define ETI_USER_OPERIAL        10    //����Ա����
#define ETI_DVR_USER_OPERIAL    32    //����Ա����
#define ETI_GROUP_MAXNUM        8     //8����
/********************** �û�Ȩ�޶��� ********************************/
#define ETI_USER_RIGHT_ADLOG    0     //��½�û�
#define ETI_USER_RIGHT_ADMIN    1     //����ԱȨ��
#define ETI_USER_RIGHT_HIOPER   2     //�߼�����Ա
#define ETI_USER_RIGHT_OPERIAL  3     //����Ա
#define ETI_USER_RIGHT_SUPER    4     //�������Ա

#define ETI_RIGHT_LOCALPLAY     ((unsigned int)(1<<0))        //���ػط�
#define ETI_RIGHT_NETPLAY       ((unsigned int)(1<<1))        //Զ�̻ط�
#define ETI_RIGHT_NETVIEW       ((unsigned int)(1<<2))        //Զ��Ԥ��
#define ETI_RIGHT_NETTALK       ((unsigned int)(1<<3))        //�Խ�
#define ETI_RIGHT_LOCALPTZ      ((unsigned int)(1<<4))        //������̨����
#define ETI_RIGHT_NETPTZ        ((unsigned int)(1<<5))        //Զ����̨����
#define ETI_RIGHT_HANDRECORD    ((unsigned int)(1<<6))        //�ֶ�¼��
#define ETI_RIGHT_BKFILE        ((unsigned int)(1<<7))        //¼���ļ�����
#define ETI_RIGHT_LOGMANAGE     ((unsigned int)(1<<8))        //��־����
#define ETI_RIGHT_PARAMSET      ((unsigned int)(1<<9))        //ϵͳ��������
#define ETI_RIGHT_UPDATE        ((unsigned int)(1<<10))       //����ϵͳ
#define ETI_RIGHT_SHUTDOWN      ((unsigned int)(1<<11))       //�ر��豸
#define ETI_RIGHT_USERMANAGE    ((unsigned int)(1<<12))       //�û��ʺŹ���
#define ETI_RIGHT_ALL           0xFFFFFFFF  //����Ȩ��

typedef enum
{
    ETI_NETVIEW_GROUP = 0,                    //Ԥ����
    ETI_OPERATOR_GROUP,                       //��ͨ����Ա��
    ETI_ADVANCE_OPERATOR_GROUP,               //�߼�����Ա��
    ETI_ADMIN_GROUP                           //����Ա��
}ETI_RIGHT_GROUP;

/**************************Ȩ����Ϣ�ṹ****************************/
typedef struct
{
    unsigned int      m_right;                //��λ��ʾȨ�ޣ��ɵ͵�������Ϊ�����ػطš�Զ�̻طš�Զ��Ԥ�����Խ���
                                              //������̨���ơ�Զ����̨���ơ��ֶ�¼��¼���ļ����ݡ���־����
                                              //ϵͳ�������á�����ϵͳ���ر��豸���û��ʺŹ���
    unsigned int      m_right1;               //����
    unsigned int      m_netview;              //Զ��Ԥ����0~31ͨ��
    unsigned int      m_netview1;             //Զ��Ԥ����32~63ͨ��
    unsigned int      m_netplay;              //Զ�̻طŵ�0~31ͨ��
    unsigned int      m_netplay1;             //Զ�̻طŵ�32~63ͨ��
    unsigned int      m_localplay;            //���ػطŵ�0~31ͨ��
    unsigned int      m_localplay1;           //���ػطŵ�32~63ͨ��
}ETI_RIGHT_T;

/**************************����Ϣ�ṹ****************************/
typedef struct
{
    ETI_RIGHT_T    m_right;
    char       m_groupname[APP_PASSWORD_LENGTH];
}ETI_GROUP_T;

/**************************�û���Ϣ�ṹ****************************/
typedef struct
{
    char            m_username[APP_PASSWORD_LENGTH];
    char            m_password[APP_PASSWORD_LENGTH];
    int             m_groupnum;                         //�û�������Ȩ����
    ETI_RIGHT_T     m_right;
}ETI_USER_T;

/**************************�û���Ϣ����****************************/
typedef struct
{
    int             m_usernum;                          //�û�����
    int             m_groupnum;                         //��Ч�����
    ETI_GROUP_T     m_group[ETI_GROUP_MAXNUM];          //8���飬��ʼ��4����Ԥ��4��
    ETI_USER_T      m_user[ETI_DVR_USER_OPERIAL];       //32���û�����ʼ��4��
}ETI_SYSUSER_T;

/********************** user info extent(add user stauts) *********/
typedef struct
{
    char m_status[ETI_DVR_USER_OPERIAL];              // the status of user(0:disbale, 1:enable)
    ETI_SYSUSER_T m_user;
}ETI_SYSUSER_EX_T;                                    // extent user info(add the stauts of user)


/********************** ������ر��������û������������� ********************************/
#define ETI_USERS_OPERIAL       20  //���֧��20���û�(����������Ա��һ�����Ա�Ͳ���Ա3���û�)

/* ������������Ȩ�޶��� */
#define ETI_RIGHT_QUERYSTATE    ((unsigned int)(1<<0))        //״̬��ѯ
#define ETI_RIGHT_QUERYENV      ((unsigned int)(1<<1))        //������Ϣ��ѯ
#define ETI_RIGHT_QUERYLOG      ((unsigned int)(1<<2))        //��־��ѯ
#define ETI_RIGHT_SETPARAM      ((unsigned int)(1<<3))        //��������
#define ETI_RIGHT_ADMUSER       ((unsigned int)(1<<4))        //�û�����
#define ETI_RIGHT_DEFAULTSYS    ((unsigned int)(1<<5))        //�ָ���������
#define ETI_RIGHT_UPDATESYS     ((unsigned int)(1<<6))        //ϵͳ����
#define ETI_RIGHT_SHUTSYS       ((unsigned int)(1<<7))        //�ر�ϵͳ

#define ETI_RIGHT_NUMS          8                             //��Ȩ����

typedef enum
{
    ETI_OPERATORS_GROUP = 0,                  //����Ա��
    ETI_COMADMIN_GROUP,                       //��ͨ����Ա��
    ETI_SUPADMIN_GROUP                        //��������Ա��
}ETI_RIGHTS_GROUP;

typedef struct
{
/*��λ��ʾȨ�ޣ��ɵ͵�������Ϊ��״̬��ѯ/������Ϣ��ѯ/��־
 *��ѯ/��������/�û�����/�ָ���������/ϵͳ����*/
    unsigned int    m_right;                //Ȩ��
    unsigned int    m_right1;               //����
    unsigned int    m_right2;               //����
    unsigned int    m_right3;               //����
}ETI_RIGHTS_T;

typedef struct
{
    char            m_groupname[APP_PASSWORD_LENGTH];
    ETI_RIGHTS_T    m_right;
}ETI_GROUPS_T;

typedef struct
{
    char            m_username[APP_PASSWORD_LENGTH];//�û���
    char            m_password[APP_PASSWORD_LENGTH];//����
    int             m_groupnum;                     //�û�������Ȩ����
    ETI_RIGHTS_T    m_right;                        //Ȩ��
}ETI_USERS_T;

typedef struct
{
    char            m_status[ETI_USERS_OPERIAL];    //the status of user(0:disbale,1:enable)
    int             m_groupnum;                     //��Ч�����
    int             m_usernum;                      //�û�����
    ETI_GROUPS_T    m_group[ETI_GROUP_MAXNUM];      //3���飬��ʼ��3����Ԥ��5��
    ETI_USERS_T     m_user[ETI_USERS_OPERIAL];      //20���û�����ʼ��1����ʣ���û���������û�Ȩ�޵��û����
}ETI_SYSUSERS_T;
/********************** ������ر��������û���������������� ********************************/


/********************** �������Զ���***************************/
//����λ
enum{UART_DATABIT_5 = 5U,UART_DATABIT_6 = 6U,UART_DATABIT_7 = 7U,UART_DATABIT_8 = 8U};
//ֹͣλ
enum{UART_STOPBIT_0 = 0U,UART_STOPBIT_1 = 1U,UART_STOPBIT_2 = 2U};
//У��λ
enum{UART_VERIFY_NONE = 0U,UART_VERIFY_ODD = 1U,UART_VERIFY_EVEN = 2U,UART_VERIFY_MASK1 = 3U,UART_VERIFY_MASK0 = 4U};
//����
enum{UART_STREAMCTRL_NONE = 0U,UART_STREAMCTRL_SOFT = 1U,UART_STREAMCTRL_HARD = 2U};
/**************������붨��***************************/
#define ETI_OK        0
#define ETI_ERROR    -1

/**************���������������***************/
#define ETI_UDPATE_ERR_MASKID     -1
#define ETI_UPDATE_ERR_SIZE       -2
#define ETI_UPDATE_ERR_OFFSET     -3
#define ETI_UPDATE_ERR_WRITEFLASH -4
/*****************************************************/

/**************ϵͳ�������Ͷ���***************************/
#define ETI_SYSLANGUAGE_CHINA    1   //����
#define ETI_SYSLANGUAGE_ENGLISH  2   //Ӣ��
/*****************************************************/

/***************��̨����Э�鶨��********************/
#define ETI_PTZTYPE_NONE        0    //��
#define ETI_PTZTYPE_PELCOP      1
#define ETI_PTZTYPE_PELCOD      2
#define ETI_PTZTYPE_HUNTERD     3
#define ETI_PTZTYPE_YINGKE      4
#define ETI_PTZTYPE_SONY100     5

#define ETI_PTZCMDMAXSIZE       4096
#define ETI_PTZCMDMAXSIZE_EX    16384
#define ETI_LICENSEMAXSIZE      1024

/*****************************************************/

/**************���紫�����ͺʹ���Э��֧��*************/
#define ETI_TRAN_TYPE_UDP        1
#define ETI_TRAN_TYPE_MULTI      2
#define ETI_TRAN_TYPE_TCP        3
#define ETI_TRAN_TYPE_RTP        4

#define LAN_NET_TRANTYPE_UDP    ETI_TRAN_TYPE_UDP
#define LAN_NET_TRANTYPE_MULTI  ETI_TRAN_TYPE_MULTI
#define LAN_NET_TRANTYPE_TCP    ETI_TRAN_TYPE_TCP
#define LAN_NET_TRANTYPE_RTP    ETI_TRAN_TYPE_RTP    

#define ETI_TRAN_SUPPROT_UDP    0X01
#define ETI_TRAN_SUPPORT_MULTI  0X02
#define ETI_TRAN_SUPPORT_TCP    0X04
#define ETI_TRAN_SUPPORT_RTP    0X08
/*****************************************************/
enum{
    ETI_VOVIEWMODE_1 = 1,
    ETI_VOVIEWMODE_2 = 2,
    ETI_VOVIEWMODE_4 = 4,
    ETI_VOVIEWMODE_6 = 6,
    ETI_VOVIEWMODE_8 = 8,
    ETI_VOVIEWMODE_9 = 9,
};
/***************�ƶ�������ͼ������********************/
/*
 * ����PAL��ʽ,���ܱ�32����
 * ����NTSC��ʽ,�߲��ܱ�32����,���һ�в���32*16�Ŀ��С
*/
#define ETI_MOTIONAREA_SIZE     396    //(704/32)*(576/32) = 18 * 22
/*****************************************************/

#define ETI_MAX_OSD_SIZE        32

/************��������ʱͨ�����籸���ļ�ѡ��**************/
#define ETI_ALARM_BACK_FTP      0X01    //ͨ��FTP����
#define ETI_ALARM_BACK_MODEM    0X02    //ͨ�����ű���

/********************** ֡ͷID���� ********************************/
#define ETI_FRAME_HEAD_ID       0XB2010000  // ��֡ͷ����ʾ��9000\8000\5000\5100ϵ��ʹ��
#define ETI_DVR_FRAME_HEAD_ID   0XB3010000  // ��֡ͷ����ʾ
#define ETI_VCA_FRAME_HEAD_ID   0XB4010000  // ���ܷ���֡ͷ��ʾ

#define ETI_BRV_FRAME_HEAD_ID        ETI_FRAME_HEAD_ID + 1  // ��ά֡ͷID����������ƽ̨���ư汾

/********************** ֡���Ͷ��� ********************************/
#define ETI_FRAME_CH_MASK        0X000F       //0X0001111B
#define ETI_FRAME_TIMERESET      0X0010       //0X0010000B
#define ETI_FRAME_KEY_MASK       0X0020       //0X0100000B
#define ETI_FRAME_VIDEOSIZE_MAXK 0X0040       //0X1000000Bͼ��ߴ��־
#define ETI_FRAME_DATA_MASK      0XFF80
#define ETI_FRAME_VIDEOSIZE_LEN  4            //(width + height)

/********************** DVR֡���Ͷ��� *****************************/
#define    ETI_DVR_FRAME_KEY_MASK    1<<0        //��ƵI֡
#define ETI_DVR_FRAME_PFRAME_MASK    1<<1        //��ƵP֡
#define ETI_DVR_FRAME_BFRAME_MASK    1<<3        //��ƵB֡
#define ETI_DVR_FRAME_AUDIO          1<<4        //������Ƶ����
#define ETI_DVR_FRAME_FILEHEAD       1<<5        //�����ļ�ͷ
#define ETI_VCA_FRAME_INFOHEAD       1<<6        //�������ܷ�����Ϣͷ
#define ETI_DVR_FRAME_SYSHEAD        1<<7        //���� ϵͳͷ

/********************** ���ܷ�����Ϣ���Ͷ��� **********************/
#define ETI_VCA_FRAME_INFO_TYPE_PLATE 0x01       //���ܷ�����Ϣ���ͣ�����ʶ����Ϣ

/* �޸���ʽת����bug */
#if defined(DVR_BIG_ENDIAN)
#define ETI_DVR_FRAME_ISKEY(buff) \
    (lc_swab32((unsigned int)(((ETI_DVR_FRMAME_HEAD*)(buff))->nVideoSize)) > 0U && (lc_swab16(((ETI_DVR_FRMAME_HEAD*)(buff))->nMuxData) & (unsigned short)(ETI_FRAME_KEY_MASK)))
#define ETI_DVR_FRAME_ISFRAME(buff) \
    ((lc_swab32(((ETI_DVR_FRMAME_HEAD*)(buff))->nID) == ETI_DVR_FRAME_HEAD_ID) && ((lc_swab32((unsigned int)(((ETI_DVR_FRMAME_HEAD*)(buff))->nVideoSize)) + lc_swab32(((ETI_DVR_FRMAME_HEAD*)(buff))->nAudioSize) > 0U)))
#define ETI_DVR_FRAME_ISVIDEO(buff) (int)lc_swab32((unsigned int)(((ETI_DVR_FRMAME_HEAD*)(buff))->nVideoSize)) > 0 ? 1 : 0
#define ETI_DVR_FRAME_TICK(buff)    lc_swab32(((ETI_DVR_FRMAME_HEAD*)(buff))->nTimeTick)
#define ETI_DVR_FRAME_ISRESET(buff) (lc_swab16(((ETI_DVR_FRMAME_HEAD*)(buff))->nMuxData) & (unsigned short)(ETI_FRAME_TIMERESET))
#define ETI_DVR_FRAME_GMTTIME(buff) lc_swab32(((ETI_DVR_FRMAME_HEAD*)(buff))->nGMTTime)
#else
#define ETI_DVR_FRAME_ISKEY(buff) \
    ( ((ETI_DVR_FRMAME_HEAD*)(buff))->nVideoSize > 0 && (((ETI_DVR_FRMAME_HEAD*)(buff))->nFrameType & ETI_DVR_FRAME_KEY_MASK))
#define ETI_DVR_FRAME_ISFRAME(buff) \
    ((((ETI_DVR_FRMAME_HEAD*)(buff))->nID == ETI_DVR_FRAME_HEAD_ID) && ((((ETI_DVR_FRMAME_HEAD*)(buff))->nVideoSize + ((ETI_DVR_FRMAME_HEAD*)(buff))->nAudioSize > 0)))
#define ETI_DVR_FRAME_ISVIDEO(buff) ((ETI_DVR_FRMAME_HEAD*)(buff))->nVideoSize > 0 ? 1 : 0
#define ETI_DVR_FRAME_TICK(buff)    ((ETI_DVR_FRMAME_HEAD*)(buff))->nTimeTick
#define ETI_DVR_FRAME_ISRESET(buff) (((ETI_DVR_FRMAME_HEAD*)(buff))->nMuxData & ETI_FRAME_TIMERESET)
#define ETI_DVR_FRAME_GMTTIME(buff) ((ETI_DVR_FRMAME_HEAD*)(buff))->nGMTTime
#endif

#define ETI_FRAME_ISKEY(buff) \
    ( ((ETI_FRMAME_HEAD*)(buff))->nVideoSize > 0 && ((ETI_FRMAME_HEAD*)(buff))->nMuxData & ETI_FRAME_KEY_MASK)
#define ETI_FRAME_ISFRAME(buff)    \
    ((((ETI_FRMAME_HEAD*)(buff))->nID == ETI_FRAME_HEAD_ID) && ((((ETI_FRMAME_HEAD*)(buff))->nVideoSize + ((ETI_FRMAME_HEAD*)(buff))->nAudioSize > 0)))
#define ETI_FRAME_ISVIDEO(buff)     ((ETI_FRMAME_HEAD*)(buff))->nVideoSize > 0 ? 1 : 0
#define ETI_FRAME_TICK(buff)        ((ETI_FRMAME_HEAD*)(buff))->nTimeTick
#define ETI_FRAME_ISRESET(buff)     ( ((ETI_FRMAME_HEAD*)(buff))->nMuxData & ETI_FRAME_TIMERESET )

#define ETT_BRV_PACKETSEQSIZE(pframehead)    (pframehead->m_filehead.m_totalframes == 0?0:(pframehead->m_filehead.m_totalframes - 1)*sizeof(DATA_BRV_CHECK_HEND_T))

#define DVR_FILE_HEAD_SIZE(buff) (((ETI_DVR_FRMAME_HEAD*)(buff))->nFrameType & ETI_DVR_FRAME_FILEHEAD?(int)sizeof(ETI_FILE_HEAD):0)
#define DVR_SYS_HEAD_SIZE(buff) (((ETI_DVR_FRMAME_HEAD*)(buff))->nFrameType & ETI_DVR_FRAME_SYSHEAD?((ETI_DVR_FRMAME_HEAD*)(buff))->nVideoSize:0)

#define ETI_VCA_FRAME_ISKEY(buff)    ETI_DVR_FRAME_ISKEY(buff)
#define ETI_VCA_FRAME_ISFRAME(buff) \
((((ETI_VCA_FRMAME_HEAD*)(buff))->nID == ETI_VCA_FRAME_HEAD_ID) && ((((ETI_VCA_FRMAME_HEAD*)(buff))->nVideoSize + ((ETI_VCA_FRMAME_HEAD*)(buff))->nAudioSize > 0)))
#define ETI_VCA_FRAME_ISVIDEO(buff) ETI_DVR_FRAME_ISVIDEO(buff)
#define ETI_VCA_FRAME_TICK(buff)    ETI_DVR_FRAME_TICK(buff)
#define ETI_VCA_FRAME_ISRESET(buff) ETI_DVR_FRAME_ISRESET(buff)
#define ETI_VCA_FRAME_GMTTIME(buff) ETI_DVR_FRAME_GMTTIME(buff)

#define VCA_FILE_HEAD_SIZE(buff)    DVR_FILE_HEAD_SIZE(buff)
#define VCA_INFO_HEAD_SIZE(buff)    (((ETI_VCA_FRMAME_HEAD*)(buff))->nFrameType & ETI_VCA_FRAME_INFOHEAD?sizeof(ETI_VCA_INFO_HEAD):0)
#define VCA_INFO_DATA_TYPE(buff)    ((ETI_VCA_INFO_HEAD*)((char*)(buff) + sizeof(ETI_VCA_FRMAME_HEAD) + VCA_FILE_HEAD_SIZE(buff)))->vca_type
#define VCA_INFO_DATA_ISPLATE(buff)    (VCA_INFO_DATA_TYPE(buff) == ETI_VCA_FRAME_INFO_TYPE_PLATE)
#define VCA_INFO_DATA_SIZE(buff)    ((ETI_VCA_INFO_HEAD*)((char*)(buff) + sizeof(ETI_VCA_FRMAME_HEAD) + VCA_FILE_HEAD_SIZE(buff)))->vca_length

#define ETI_STREAMINFO_VIDEOID_DVS    0
#define ETI_STREAMINFO_VIDEOID_DVR    1

#define ETI_DVS_FILE_VERSION        1
#define ETI_DVR_FILE_VERSION        2
#define ETI_AUDIO_FILE_VERSION      3

typedef struct
{
/*
nMuxData Format :16 bits
����û����ݳ���Ϊ1024
-----------------------------------------------------
|0--4 ͨ����| 5 ֡����| 6 ͼ��ߴ��־|7---15 �û����ݳ���|
�����ͼ��ߴ��־����nVideoSize�����4���ֽڵ�ͼ���Ⱥ͸߶�
-----------------------------------------------------
*/
    //unsigned char  nID[4];     //0X00,0X00,0X01,0XB2
    unsigned int   nID;          //0XB2010000
    unsigned int   nTimeTick;    //ʱ���
    int               nVideoSize;//��Ƶ���ݳ���
    unsigned short nAudioSize;   //��Ƶ���ݳ���
    unsigned short nMuxData;     //�������ݣ���Ƶͨ����֡���͡��û�����
}ETI_FRMAME_HEAD,*PETI_FRMAME_HEAD;

/*
1.����ƵI֡������Ƶ��ʽ�仯ʱ�����ļ�ͷ��Ϣ,nFrameType = 0x20,�ļ�ͷ����sizeof(ETI_FILE_HEAD).
2.ID����Ϊ ETI_DVR_FRAME_HEAD_ID,0XB3010000,��ID��MPEG4����H264�����в������.
3.���������ͬʱ��������Ƶ���ݺ��ļ�ͷ��Ϣ,����˳��Ϊ: �ļ�ͷ��Ϣ,��Ƶ����,��Ƶ����,nFrameCount����Ƶ���ݽ�����д.
4.nGMTTime����GMTʱ����������,���ڶ�λ��ǰ֡�ľ��Բ���ʱ��.
5.nFrameCount���ձ���֡�������ۼ�,�����жϷ���ʱ�Ƿ���ڶ�֡,��֡�󲻽��к���P֡����,�������ͼ����.
6.nMuxDataȥ��ԭ������,��ʱ����,����.
*/
typedef struct
{
    unsigned int    nID;            //ETI_DVR_FRAME_HEAD_ID,0XB3010000
                                    //ETI_VCA_FRAME_HEAD_ID,0XB4010000 ���ܷ���֡ͷ��ʾ
    unsigned int    nTimeTick;      //ʱ���,���ʱ��,����Ϊ��λ
    unsigned int    nGMTTime;       //����ʱ��,��1970��1��1�� 00:00:00 ��ʼ������,ʱ����GMTʱ������.
    int             nFrameType;     //��4λ��ʾ��Ƶ֡����: 0->I-FRAME/1->P-FRAME/3->B-FRAME
                                    //��5λ��ʾ�Ƿ������Ƶ: 0x10��ʾ����Ƶ֡
                                    //��6λ��ʾ�Ƿ�����ļ�ͷ��Ϣ: 0x20:��ʾ���ļ�ͷ��Ϣ
                                    //��7λ��ʾ�Ƿ�������ܷ�����Ϣ��0x40��ʾ�����ܷ�����Ϣ
                                    //��8λ��ʾ�Ƿ�������ڽ����ʼ����ϵͳͷ��ETI_DVR_FRAME_SYSHEAD 1<<7 ʹ��nVideoSize ��ʾϵͳͷ��С
    int             nFrameCount;    //����֡���
    int             nVideoSize;     //��Ƶ���ݳ���
    unsigned short  nAudioSize;     //��Ƶ���ݳ���
    unsigned short  nMuxData;       //��������
}
ETI_DVR_FRMAME_HEAD,*PETI_DVR_FRMAME_HEAD,
ETI_VCA_FRMAME_HEAD,*PETI_VCA_FRMAME_HEAD; // ���ܷ���֡ͷ

typedef struct
{
    unsigned int    nID;            //ETI_DVR_FRAME_HEAD_ID,0XB3010000
    unsigned int    nTimeTick;      //ʱ���,���ʱ��,����Ϊ��λ
    unsigned int    nGMTTime;       //����ʱ��,��1970��1��1�� 00:00:00 ��ʼ������,ʱ����GMTʱ������.
    int             nFrameType;     //��6λ��ʾ�Ƿ�����ļ�ͷ��Ϣ: 0x20:��ʾ���ļ�ͷ��Ϣ
    int             nFrameCount;    //����֡���
    int             nAudioSizeOne;  //��Ƶ1����
    unsigned short  nAudioSizeTwo;  //��Ƶ2����
    unsigned short  nMuxData;        //��������
} ETI_AUDIO_FRMAME_HEAD,*PETI_AUDIO_FRMAME_HEAD; // ˫��Ƶ֡ͷ


#define ETI_FILE_MASKEND        0XABCEDF01
#define ETI_FILEMASK            "LAUNCHDIGITAL"
#define ETI_FILEMASK_NEW        "MP4RECORDFILE"
#define ETI_FILEMASK_DX_NOAUDIO "DXNOAUDIOFILE"
#define TARGET_DX4

typedef struct
{
    char            m_filemask[16]; //�ļ�ͷMASK "LAUNCHDIGITAL"
    int             m_fileversion;  //�ļ��汾�� ETI_DVR_FILE_VERSIONΪ�ṹ ETI_DVR_FILE_HEAD
                                    //           ETI_DVS_FILE_VERSIONΪ�ṹ ETI_FILE_HEAD
    int             videofoucc;     //��ƵFOURCC
    short           framerate;      //��Ƶ֡��
    short           videoid;        //��ƵID ��ʱ���� 0
    short           m_width;        //ͼ����
    short           m_height;       //ͼ��߶�
    short           m_audiotag;     //��Ƶ��ʶ
    short           m_haveaudio;    //�Ƿ������Ƶ��־
    short           m_auchs;        //��Ƶͨ����
    short           m_aurates;      //��Ƶ����
    int             m_ausample;     //��Ƶ������
    unsigned int    m_totalframes;  //�ļ��а�����֡��
    unsigned int    m_firsttick;    //��һ֡ʱ���
    unsigned int    m_losttick;     //���һ֡ʱ���
    int             maskend;        //������־
}ETI_FILE_HEAD;

typedef struct
{
    char            m_filemask[16]; //�ļ�ͷMASK "LAUNCHDIGITAL"
    int             m_fileversion;  //�ļ��汾�� ETI_DVR_FILE_VERSIONΪ�ṹ ETI_DVR_FILE_HEAD
                                    //           ETI_DVS_FILE_VERSIONΪ�ṹ ETI_FILE_HEAD
    int             videofoucc;     //��ƵFOURCC
    short           framerate;      //��Ƶ֡��
    short           videoid;        //��ƵID ��ʱ���� 0
    short           m_width;        //ͼ����
    short           m_height;       //ͼ��߶�
    short           m_audiotag;     //��Ƶ��ʶ
    short           m_haveaudio;    //�Ƿ������Ƶ��־
    short           m_auchs;        //��Ƶͨ����
    short           m_aurates;      //��Ƶ����
    int             m_ausample;     //��Ƶ������
    unsigned int    m_totalframes;  //�ļ��а�����֡��
    unsigned int    m_firsttick;    //��һ֡ʱ���
    unsigned int    m_losttick;     //���һ֡ʱ���
    unsigned int    m_reserved;     //����λ
    unsigned int    m_firstGMTTime; //�ļ���ʼ����ʱ��,ʱ����GMTʱ������.
    unsigned int    m_lastGMTTime;  //�ļ���������ʱ��,ʱ����GMTʱ������.
    int             maskend;        //������־
}ETI_DVR_FILE_HEAD;

typedef struct
{
    char            m_filemask[16];  //�ļ�ͷMASK "LAUNCHDIGITAL"
    int             m_fileversion;   //�ļ��汾�� ETI_DVR_FILE_VERSION Ϊ�ṹ ETI_DVR_FILE_HEAD
                                     //           ETI_DVS_FILE_VERSION Ϊ�ṹ ETI_FILE_HEAD
                                     //           ETI_AUDIO_FILE_VERSION Ϊ�ṹ ETI_AUDIO_FILE_HEAD
    short           m_audiotag1;     //��Ƶ��ʶ
    short           m_haveaudio1;    //�Ƿ������Ƶ��־
    short           m_auchs1;        //��Ƶͨ����
    short           m_aurates1;      //��Ƶ����
    int             m_ausample1;     //��Ƶ������

    short           m_audiotag2;     //��Ƶ��ʶ
    short           m_haveaudio2;    //�Ƿ������Ƶ��־
    short           m_auchs2;        //��Ƶͨ����
    short           m_aurates2;      //��Ƶ����
    int             m_ausample2;     //��Ƶ������

    unsigned int    m_totalframes1;  //��Ƶ1�ļ��а�����֡��
    unsigned int    m_totalframes2;  //��Ƶ2�ļ��а�����֡��

    unsigned int    m_firsttick;     //��һ֡ʱ���
    unsigned int    m_losttick;      //���һ֡ʱ���

    unsigned int    m_firstGMTTime;  //�ļ���ʼ����ʱ��,ʱ����GMTʱ������.
    unsigned int    m_lastGMTTime;   //�ļ���������ʱ��,ʱ����GMTʱ������.

    unsigned int    m_reserved;      //����λ
    int             maskend;         //������־
} ETI_AUDIO_FILE_HEAD;


//////////////////////////DXHJ BEGIN///////////////////////////////
typedef struct
{
    char            m_court[48];        //�������ڷ�Ժ
    char            m_courtroom[48];    //�������ڷ�ͥ
    char            m_id[16];           //����Ψһʶ���
    char            m_szCaseID[28];     //case id
    char            m_szCaseExecor[28]; //case ִ����
    char            m_recv1[32];        //����1
    char            m_recv2[32];        //����2
    char            m_recv3[32];        //����3
}DX_FILE_HEAD;

typedef struct
{
    char            m_filemask[16]; //�ļ�ͷMASK "LAUNCHDIGITAL"
    int             m_fileversion;  //�ļ��汾�� ETI_DVR_FILE_VERSIONΪ�ṹ ETI_DVR_FILE_HEAD
                                    //           ETI_DVS_FILE_VERSIONΪ�ṹ ETI_FILE_HEAD
    int             videofoucc;     //��ƵFOURCC
    short           framerate;      //��Ƶ֡��
    short           videoid;        //��ƵID ��ʱ���� 0
    short           m_width;        //ͼ����
    short           m_height;       //ͼ��߶�
    short           m_audiotag;     //��Ƶ��ʶ
    short           m_haveaudio;    //�Ƿ������Ƶ��־
    short           m_auchs;        //��Ƶͨ����
    short           m_aurates;      //��Ƶ����
    int             m_ausample;     //��Ƶ������
    unsigned int    m_totalframes;  //�ļ��а�����֡��
    unsigned int    m_firsttick;    //��һ֡ʱ���
    unsigned int    m_losttick;     //���һ֡ʱ���
    unsigned int    m_reserved;     //����λ
    unsigned int    m_firstGMTTime; //�ļ���ʼ����ʱ��,ʱ����GMTʱ������.
    unsigned int    m_lastGMTTime;  //�ļ���������ʱ��,ʱ����GMTʱ������.
    DX_FILE_HEAD    m_dxfile;       //¼��ͷ����ӷ�Ժ��Ϣ
    int             maskend;        //������־
}ETI_DX4_DVR_FILE_HEAD;

//////////////////////////DXHJ END/////////////////////////////////

typedef struct
{
    unsigned int    nID;            //ETI_BRV_FRAME_HEAD_ID,0XB2010001
    unsigned int    nTimeTick;      //ʱ���
    int             nVideoSize;     //��Ƶ���ݳ���
    unsigned short  nAudioSize;     //��Ƶ���ݳ���
    unsigned short  nMuxData;       //�������ݣ���Ƶͨ����֡���͡��û�����
    ETI_FILE_HEAD   m_filehead;     //�ļ�ͷ
}ETI_BRV_FRMAME_HEAD,*PETI_BRV_FRMAME_HEAD;

#define MIN_FRMAME_HEAD ETI_FRMAME_HEAD
typedef struct
{
    unsigned short    framenum;
    unsigned short    packnum;
}DATA_BRV_CHECK_HEND_T;

#define BRV_PACETSIZE        1116


// ���ܷ�����Ϣ�ṹ
typedef struct
{
    unsigned int vca_type;          // ���ܷ�����Ϣ���ͣ�0x01-����ʶ����Ϣ
    unsigned int vca_length;        // ���ܷ�����Ϣ���ȣ����ֽ�Ϊ��λ
}ETI_VCA_INFO_HEAD;

typedef struct
{
    short left;                     // ������������Ͻ�X����   
    short right;                    // ������������½�X����
    short top;                      // ������������Ͻ�Y����
    short bottom;                   // ������������½�Y����
}ETI_VCA_PLATERECT;

#ifndef MAX_VCA_PLATERECT_NUM
#define MAX_VCA_PLATERECT_NUM  4    // ���Ʒ�����೵����
#endif

#ifndef MAX_VCA_PLATERSTR_NUM
#define MAX_VCA_PLATERSTR_NUM 12    // ���Ʒ������ƺ���  
#endif

// ���ܷ���������Ϣ
typedef struct 
{
    unsigned int        version;                                   // ����ʶ����Ϣ�汾��0x01-V1.0
    unsigned int        time_stamp;                                // ����ʱ������Ժ���Ϊ��λ
    unsigned int        pos_num;                                   // ��ǰ֡��λ���ĳ�����Ŀ
    ETI_VCA_PLATERECT   pos_rect[MAX_VCA_PLATERECT_NUM];           // ��ǰ֡��λ���ĳ�����ԭʼͼ���е�λ��
    unsigned char       recog_num;                                 // ʶ����ĳ��ƺ���Ŀ
    unsigned char       reserverd1[3];                             // ������������Ϊ0
    unsigned int        recog_gmttime[MAX_VCA_PLATERECT_NUM];      // ʶ�𵽵ĳ���������ֵľ���ʱ�䣬��1970��1��1�� 00:00:00 ��ʼ������,ʱ����GMTʱ������
    unsigned char       recog_number[MAX_VCA_PLATERECT_NUM][MAX_VCA_PLATERSTR_NUM];  // ʶ������ĳ����ַ�
    unsigned char       recog_trust[MAX_VCA_PLATERECT_NUM];        // �����ַ������Ŷ�
    unsigned char       recog_brightness[MAX_VCA_PLATERECT_NUM];   // ��������ֵ1 ~ 255
    unsigned char       recog_color[MAX_VCA_PLATERECT_NUM];        // ������ɫ 0:����1:�Ƶ�2:�׵ף�����3:�׵ף�����4:����5:δ֪
    unsigned char       recog_direction[MAX_VCA_PLATERECT_NUM];    // �����˶����� 0:δ֪���� 1:���ƴ��ϵ����˶� 2:��ʾ���ƴ��µ����˶�
    unsigned char       recog_type[MAX_VCA_PLATERECT_NUM];         // �������� 1:������������ 2:С���������� 16:������������ 23:������������ 99:δ֪
    unsigned int        recog_speeds[MAX_VCA_PLATERECT_NUM];       // �����˶��ٶ�
    unsigned char       recog_carcolor[MAX_VCA_PLATERECT_NUM];     // ������ɫ 0:δ֪ 1:��ɫ 2:��ɫ 3:��ɫ 4:��ɫ 5:��ɫ 6:��ɫ -1:ʧ��
}ETI_VCA_PLATEINFO;

/********************** ����ʱ����Ϣ��ʽ���� ********************************/
typedef enum{
    ETI_TIME_FORMAT_OFF = 0X00,     //�ر�
    ETI_TIME_FORMAT_1    = 0X01,    //2003-09-12 15:23:33
    ETI_TIME_FORMAT_2    = 0X02,    //2003-09-12 ������ 15:23:33
    ETI_TIME_FORMAT_3    = 0X03,    //09-12-2003 15:23:33
    ETI_TIME_FORMAT_4    = 0X04,    //09-12-2003 ������ 15:23:33
    ETI_TIME_FORMAT_5    = 0X05,    //12-09-2003 15:23:33
    ETI_TIME_FORMAT_6    = 0X06,    //12-09-2003 ������ 15:23:33
    ETI_TIME_FORMAT_7    = 0X07,    //2003/09/12 15:23:33
    ETI_TIME_FORMAT_8    = 0X08,    //09/12/2003 15:23:33
    ETI_TIME_FORMAT_9    = 0X09,    //12/09/2003 15:23:33
    ETI_TIME_FORMAT_A    = 0X0A,    //2003.09.12 15:23:33
    ETI_TIME_FORMAT_B    = 0X0B,    //09.12.2003 15:23:33
    ETI_TIME_FORMAT_C    = 0X0C     //12..09.2003 15:23:33
}ETI_TIME_FORMAT;
/*****************************************************/

/**************ʱ�������***************************/
typedef enum
{
    ETI_DAY_MONDAY        = 0,    //����һ
    ETI_DAY_TUESDAY       = 1,    //���ڶ�
    ETI_DAY_WEDNESDAY     = 2,    //������
    ETI_DAY_THURSDAY      = 3,    //������
    ETI_DAT_FRIDAY        = 4,    //������
    ETI_DAY_SATURDAY      = 5,    //������
    ETI_DAY_SUNDAY        = 6,    //������
    ETI_DAY_MON_FRI       = 7,    //����һ-������
    ETI_DAY_SAT_SUN       = 8,    //������-������
    ETI_DAY_DAILY         = 9,    //ÿ��
    ETI_DAY_OFF           = 10,   //�ر�
}ETI_TIME_DAYTYPE;
/*****************************************************/

//���ʿ���ģʽ���ҹ�˾�뺣˼�����RC_MODE_E��ͬ��CBR��VBR�෴(������ǰ���)
typedef enum
{
    ETI_MODE_CBR = 0,
    ETI_MODE_VBR,
    ETI_MODE_ABR,
    ETI_MODE_FIXQP,
}ETI_MODE_E;


#define ETI_MAX_JPEG_SIZE 2000*1024
#define ETI_PLATE_STR_SIZE 12

typedef struct
{
    int     m_filesize;         //�ļ���С
    int     m_year;             //��
    char    m_month;            //��
    char    m_day;              //��
    char    m_hour;             //ʱ
    char    m_captype;          //ץ������:0x01-�ֶ�ץ��;0x02-����ץ��;0x04-�����ץ��;0x08-����ץ��;
    char    m_filename[60];     //�ļ���
    char    m_tollgateid[32];   //���ڱ��
    char    m_deviceid[32];      //�豸���
} ETI_JPEG_HEAD;

typedef struct
{
    char    m_roadwaynum;       //������
    char    m_color;            //������ɫ
    char    m_ptype;            //��������
    char    m_car_color;        //������ɫ
    char    m_direction;        //����
    char    m_reserved;         //����    
    short   m_speed;            //����
    int     m_captype;          //ץ������:0x01-�ֶ�ץ��;0x02-����ץ��;0x04-�����ץ��;0x08-����ץ��;
    char    m_filename[60];     //�ļ���
    char    m_tollgateid[32];   //���ڱ��
    char    m_deviceid[32];     //�豸���
    char    m_platestr[ETI_PLATE_STR_SIZE];     //���ƺ�
    char    m_reserve[32];      //������������չ
} ETI_JPEG_HEAD_EX;

#define ETI_MAX_JPEG_NUM        10
typedef struct
{
    short   m_year;             //��
    short   m_msecond;          //����
    char    m_month;            //��
    char    m_day;              //��
    char    m_hour;             //ʱ
    char    m_minute;           //��
    char    m_second;           //��
    char    m_is_plate;         //�Ƿ�Ϊ����ͼƬ
    char    m_seqnum;           //ץ��ͼƬ���
    char    m_reserve;          //����
    int     m_size;             //ͼƬ��С
    int     m_offset;           //ͼƬƫ��
} JPEG_INFO;

typedef struct
{
    int                     m_jpgnum;                       //ͼƬ����
    int                     m_totalsize;                    //ͼƬ�ܴ�С
    JPEG_INFO               m_jpeg_info[ETI_MAX_JPEG_NUM];  //ƫ�ƺʹ�С
    ETI_JPEG_HEAD_EX        m_jpeg_head;                    //ͼƬͷ��Ϣ
    char                    m_reserve[32];                  //����λ
} ETI_JPEG_PACK;

/* tyto ץ��ͼƬ��Ϣ*/
typedef struct
{
    unsigned int            m_doffset;          //ͼƬ����ƫ��
    unsigned int            m_dlen;             //ͼƬ���ݳ���
    short                   m_width;            //ͼ����
    short                   m_height;           //ͼ��߶�
    unsigned int            m_timestamp;        //ʱ���
    short                   m_year;             //��
    short                   m_msecond;          //����
    char                    m_month;            //��
    char                    m_day;              //��
    char                    m_hour;             //ʱ
    char                    m_minute;           //��
    char                    m_second;           //��
    char                    m_reserve[3];       //����
} ETI_JPEG_INFO;

typedef enum
{
    WEB_MSG_OPT_RESTART         = 0,   //�������������� δ���ָֻ�Ĭ������ ��Ҫ�����
    WEB_MSG_OPT_RELOGIN         = 1,   //�����µ�¼�豸
    WEB_MSG_OPT_UPDATA          = 2,   //ϵͳ��������,���Ժ�
    WEB_MSG_OPT_UPDATASUCCESS   = 3,   //���������ɹ�,�����µ�¼
    WEB_MSG_OPT_UPDATAILLEGAL   = 4,   //���ϴ����ļ���ʽ����ȷ,�޷�����,����ϵͳ������Ҫ����...
    WEB_MSG_OPT_USERERROR       = 5,   //�û������������
    WEB_MSG_OPT_NORIGHT         = 6,   //��û��Ȩ�� 
    WEB_MSG_OPT_FORMAT          = 7,   //��ʽ��Ӳ�̳ɹ����豸��Ҫ����
    WEB_MSG_OPT_FORMATERROR     = 8,   //��ʽ��Ӳ��ʧ�ܣ��豸��Ҫ����
    WEB_MSG_OPT_DEFAULT         = 9,   //�ָ���������
    WEB_MSG_OPT_USERCHANGE      = 10,  //�����޸ĳɹ��������µ�¼
    WEB_MSG_OPT_DISABLED        = 11,  //�û��ѽ���
    WEB_MSG_OPT_OLDPASSWD_ERR   = 12,  //ԭ�������
    WEB_MSG_OPT_SETUSER_ERR     = 13,  //�����û�(����/ɾ��/�޸��û�)ʧ��
    WEB_MSG_OPT_RESTARTFAILED   = 14,  //����������ʧ��
    WEB_MSG_OPT_LOOPING         = 15,  //������Ѳ
}ETI_WEB_RETURN_ORDER;

/*-------------------IR Raw extra data----------------------*/
typedef enum
{
	ETI_EXDATA_SENSOR_INVALID		= 0,
	ETI_EXDATA_SENSOR_START_FPA		= 1,
	ETI_EXDATA_SENSOR_CURRENT_FPA	= 2,
	ETI_EXDATA_SENSOR_HOUSE_TEMP	= 3,
	ETI_EXDATA_SENSOR_SHUTTER_TEMP	= 4,
	ETI_EXDATA_SENSOR_OTHER			= 5
}ETI_EXDATA_TEMPSENSORID;

typedef struct  
{
	unsigned char	temp_sensor_id;//TempSensor���� 
	unsigned char	resverve[3];
	/*1-start FPA:����FPA
	  2-Current FPA:��ǰFPA
	  3-House Temp:����¶�
	  4-Shutter Temp:�����¶�
	  5-����*/
	float			temprature;//�¶�(K)
}ETI_EXDATA_TEMPSENSOR;

typedef enum
{
	ETI_EXDATA_CHIP_INVALID = 0,
	ETI_EXDATA_CHIP_LP2_0	= 1,
	ETI_EXDATA_CHIP_LP2_5	= 2,
	ETI_EXDATA_CHIP_LP3_0	= 3,
	ETI_EXDATA_CHIP_LP3_5	= 4,
	ETI_EXDATA_CHIP_TAU2	= 5,
	ETI_EXDATA_CHIP_OTHER	= 6,
}ETI_EXDATA_SENSOR_CHIP;

typedef struct  
{
	unsigned char			sensor_type;//0-��Ч 1-lepton2.0 2-lepton2.5 3-lepton3.0 4-lepton3.5 5-tau2 6-����
	unsigned char			reserve_1[3];//
	float					planck_r;//���ʿ˳���
	float					planck_b;
	float					planck_f;
	float					planck_o;
	unsigned char			temp_sensor_cnt;//�¶ȴ��������� ���֧��20��
	unsigned char			reserve_2;
	unsigned short			temp_sensor_offset;
	ETI_EXDATA_TEMPSENSOR	temp_sensor[0];//
}ETI_EXTRA_DATA;
/*-------------------IR Raw extra data end------------------*/
#endif  //__ETI_BASE_DEF_H__

