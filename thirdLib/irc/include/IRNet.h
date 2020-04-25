//IRNet.h
#ifndef __IRNET_H__
#define __IRNET_H__

#include "VSNETStructDef.h"

#if defined(PLATFORM_WIN_X64)
typedef __int64 INT_PFW, *PINT_PFW;
typedef unsigned __int64 UINT_PFW, *PUINT_PFW;

#else
typedef int INT_PFW, *PINT_PFW;
typedef unsigned int UINT_PFW, *PUINT_PFW;

typedef float FLOAT;
#endif // PLATFORM_WIN_X64

#ifndef CNET_APIIMPORT
#if defined(WIN32)
#ifdef NET_API
#define CNET_APIIMPORT  extern "C" __declspec(dllexport)
#else
#define CNET_APIIMPORT  extern "C" __declspec(dllimport)
#endif // NET_API
#else
#define CNET_APIIMPORT  extern "C" 
#endif
#endif

#ifndef IRNET_HANDLE
#define IRNET_HANDLE
typedef void *IRNETHANDLE;
#endif // !IRNET_HANDLE

#ifndef IRNET_HANDLE_VALID
#define IRNET_HANDLE_VALID(handle) (handle != -1)
#endif // !IRNET_FAILED

#ifndef CALLINGCONVEN
#ifdef WIN32
#define CALLINGCONVEN __stdcall
#else
#define CALLINGCONVEN __attribute__((visibility("default")))//__attribute__((__stdcall))
#endif
#endif // !CALLINGCONVEN


#define LAUMSG_LINKMSG          1             ///< connect server link message

#define LAUMSG_ALARM            4             ///< sensor alarm
#define LAUMSG_OUTPUTSTATUS     5             ///< alarm out status

#define LAUMSG_SERVERRECORD     11            ///< server record status

#define LAUMSG_DISKFULL                23     ///<disk full
#define LAUMSG_DISKERROR               24     ///<disk error
#define LAUMSG_ACCESSVIOLATION         25     ///<access violation

#define LAUMSG_SERSTART                26     ///<server start
#define LAUMSG_SERSTOP                 27     ///<server stop


#define LAUMSG_UPDATESTREAMINFO        30     ///<update streaminfo

#define LAUMSG_ALARMMSG_GLOBAL_TEMP    117    ///< Alarm for global temperature limit
#define LAUMSG_ALARMMSG_REGION_TEMP    118    ///<Alarm for region temperature
#define LAUMSG_ALARMMSG_IN             119    ///<Alarm

#define LAUMSG_IR_HIGHT_ALARM          9001   ///<Alarm for IR Hight Temperature
#define LAUMSG_IR_LOW_ALARM            9002   ///<Alarm for IR Low Temperature

#define LAUMSG_ALARMMSG_FIRE           9003    ///<fire alarm
#define LAUMSG_ALARMMSG_TEMPDIFF       9004    ///< temperature compare alarm
#define LAUMSG_ALARMMSG_ITELLIGENT_ANALYSIS       9005    ///< itelligent analysis

/**@brief �ͻ���ͨ����Ϣ�ص�����ָ��
* @param[in] hHandle    ���Ӿ��
* @param[in] wParam     �����
* @param[in] lParam     �Ҳ���
* @param[in] context    ����
* @return ��
*/
typedef void (WINAPI *CCICALLBACK)(IRNETHANDLE hHandle, WPARAM wParam, LPARAM lParam, void *context);

/**@brief raw���ݻص�
* @param[in] data       raw���ݵ�ַ
* @param[in] width      ��
* @param[in] height     ��
* @param[in] context    ����
* @return ��
*/
typedef void(WINAPI*RAWCALLBACK)(char* data, int width, int height, void* context);

/**@brief ��ɻص��¼�
* @param[in] status     raw���ݵ�ַ
* @param[in] url        �豸IP
* @param[in] sername    �豸����
* @param[in] username   �û���
* @param[in] wserport   �˿ں�
* @param[in] context    �Զ�������
* @return ��
*/
typedef void(WINAPI*FINISHCALLBACK)(int status, char *url, char *sername, char *username, WORD wserport, void * context);


/**@brief ������ͨ������ͨ���ص�����
* @param[in] sername     ����������
* @param[in] url         ������IP
* @param[in] port        �������˿�
* @param[in] serialno    ���������к�
* @param[in] pyhmac      ������MAC��ַ
* @param[in] channels    ������ͨ����
* @param[in] AlarmInNum  ������������
* @param[in] AlarmOutNum �����������
* @param[in] ch          ��ǰ���޷�����ͨ����
* @param[in] bLogin      �Ƿ�ע������ TRUE-���� FALSE-����
* @param[in] hChHandle   ͨ�����
*/
typedef int(WINAPI *RVSCHANNELCALLBACK)(const char *sername, const char *url, WORD port, const char *serialno, unsigned char pyhmac[6], int channels, int AlarmInNum, int AlarmOutNum, int ch, BOOL bLogin, IRNETHANDLE hChHandle);

/**@brief ������������Ϣ�ص�����
* @param[in] hHandle ͨ�����
* @param[in] wParam  ��Ϣ����
* @param[in] lParam  ��Ϣ����
* @param[in] context �ص�����������
*/
typedef void(WINAPI *RVSALARMCALLBACK)(IRNETHANDLE hHandle, WPARAM wParam, LPARAM lParam, void *context);

/** @brief �������ݻص�
* @param[in] hSerial       ͸�����ھ����IRNET_ClientSerialStart����ֵ
* @param[in] pRecvDataBuff ��������ָ�룻(Ϊ��ʱ��ʾ���ӶϿ�)
* @param[in] BuffSize      ���ݳ��ȣ�(< 0ʱ��ʾ���ӶϿ�)
* @param[in] context       �û������ģ�
* @attention 1.�ûص������ǽ��յ����ݾͻص�������һ�λص���һ����һ�����������ݣ�Ҳ�п���һ�λص�����������������ݡ���������Բ�ͬЭ����н���
2.�ûص��ڲ���ִ�������������Ƽ���ʽΪ���ûص�ֻ���򵥵Ŀ��������������ݿ������û��Զ��������У����������̷��أ��û����û��Զ��������н���Э��
*/
typedef void(WINAPI *pfSerialDataCallBack)(IRNETHANDLE hSerial, char *pRecvDataBuff, int BuffSize, void *context);

/**
* FFF���¶�����
*/
struct FFFTemperatureData
{
	float * temperatueData; /**�¶������׵�ַ*/
	unsigned short width;   /**ͼ��Ŀ�*/
	unsigned short height;  /**ͼ��ĸ�*/
};

/**
* @brief jpegץ�� ���ݻص�
* @param[in]    handle      IRNET_ClientJpegCapStart����ֵ
* @param[in]    m_ch        ͨ��
* @param[in]    pBuffer     ץ�������׵�ַ
* @param[in]    size        ץ�����ݴ�С
* @param[in]    extraData   ��������(��ץ�ĵ�����ΪFFF��ʽʱ�����ֶα�ʾ@struct ::FFFTemperatureData,����ΪNULL)
* @param[in]    userdata    �û�����
*/
typedef void(WINAPI *pfJpegdataCallback)(/*LONG*/IRNETHANDLE hHandle, int m_ch, char *pBuffer, int size, void* extraData, void *userdata);

/** �ͻ���ͨ����Ϣ�ṹ*/
typedef struct {
	char *m_sername;                    ///<server name
	char *m_username;                   ///<user name
	char *m_password;                   ///<password
	WORD m_tranType;                    ///<transmit type   
	WORD m_playstart;                   ///<is start view
	BYTE m_ch;                          ///<channel
	HWND m_hVideohWnd;                  ///<video wnd handle
	HWND m_hChMsgWnd;                   ///<message wnd handle
	UINT m_nChmsgid;                    ///<message id  
	int  m_buffnum;                     ///<buff num
	int  m_useoverlay;                  ///<is use overlay
	COLORREF nColorKey;                 ///<color key(reserved)
	char url[40];                       ///<url
	CCICALLBACK m_messagecallback;       ///<message callback function
	void *context;                      ///<message callback context
}CHANNEL_CLIENTINFO;


/** ����ͼ��ץ�Ĵ�����*/
enum CaptureErrCode
{
	EN_CEC_SUCCESS = 0x10,          ///<�ɹ�
	EN_CEC_PARAM_INVALID,           ///<������Ч
	EN_CEC_PATH_INVALID,            ///<�ļ�·����Ч
	EN_CEC_MEM_NOT_ENOUGH_RAW,      ///<�ڴ治�����raw����
	EN_CEC_WRITE_RAW,               ///<д��raw����ʧ��
	EN_CEC_MEM_NOT_ENOUGH_VIS,      ///<�ڴ治����޿ɼ�������
	EN_CEC_WRITE_VIS,               ///<д��ɼ�������ʧ��
	EN_CEC_MEM_NOT_ENOUGH_PRE,      ///<�ڴ治�����Ԥ������
	EN_CEC_WRITE_PRE,               ///<д��Ԥ������ʧ��
	EN_CEC_WRITE_SENSOR_INFO,       ///<д�봫������Ϣʧ��
	EN_CEC_WRITE_CALIB_INFO,        ///<д��У׼��Ϣʧ��
	EN_CEC_WRITE_ENV_INFO,          ///<д�뻷����Ϣʧ��
	EN_CEC_WRITE_PALETTE_INFO,      ///<д���ɫ����Ϣʧ��
	EN_CEC_WRITE_STRENGTH_INFO,     ///<д��ǿ����Ϣʧ��
	EN_CEC_COLLECT_FILE_INFO,       ///<д���Ѽ��ļ���Ϣʧ��
	EN_CEC_MEM_NOT_ENOUGH,          ///<�ڴ治��
	EN_CEC_DECODE_TEMPERATURE,      /**<�����¶�ʧ��*/
	EN_CEC_UNDEFINE                 ///<δ֪����
};

/** ����ͼ��ץ�ĵ��ļ�����
*/
enum FileType
{
	EN_FT_SDK_LCR,          ///<��ͼ
	EN_FT_SDK_CHANNEL_JPG,  ///<ͨ��jpg
	EN_FT_SDK_CHANNEL_BMP,  ///<ͨ��bmp
};

/** �豸�����ⲿ����*/
typedef struct
{
	FLOAT	fEmissivity;	///< ����������(0-1)
	FLOAT	fWinTrans;		///< ���ڴ�����(0-1)
	FLOAT	fWinTemp;		///< �����¶�[K]
	FLOAT	fWinRefl;		///< ���ڷ�����(0-1)
	FLOAT	fReflTemp;		///< ���ڷ����¶�[k]
	FLOAT	fAtmTrans;		///< ����������(0-1) 
	FLOAT	fAtmTemp;		///< �����¶�[K]
	FLOAT	fBkgTemp;		///< �����¶�[K]
	FLOAT	fDistance;		///< ����[meters]
	FLOAT	fHumidity;		///< ���ʪ��[0-1]
	FLOAT   fRadRate;       ///< ������[0-1]
	FLOAT   fEnvTemp;       ///< �����¶�[��]
	int     osdena;         ///< ˮӡʹ��
}DEV_ENV_INFO;

/**�豸�¿����*/
typedef struct
{
	FLOAT	fTempMin;		///< ��С�¶�[C]
	FLOAT	fTempMax;		///< ����¶�[C]
	BOOL	bAuto;			///< �Զ�����(ΪTRUE-����fTempMin��fTempMax)
}DEV_TEMP_SPAN;

/** �豸������Ϣ*/
struct DeviceBaseInfo
{
	char *servername;   ///<�豸��
	char *username;     ///<�û���
	char *password;     ///<����
	char *url;          ///<�豸IP
	WORD wserport;      ///<�˿�
};

/**��ɫ��ģʽ*/
typedef enum
{
	DEV_PALETE_WHITEHOT = 1,///< ���� 
	DEV_PALETE_BLACKHOT,    ///< ���� 
	DEV_PALETE_FUSION,		///< �ں�
	DEV_PALETE_RAINBOW,		///< �ʺ� 
	DEV_PALETE_ARCTIC,		///< ���� 
	DEV_PALETE_LAVA,		///< ���� 
	DEV_PALETE_GREYRED,		///< �Һ� 
	DEV_PALETE_IRON,		///< ����  
	DEV_PALETE_INSTALERT,	///< InstAlert 
	DEV_PALETE_GREENHOT,	///< ���� 
	DEV_PALETE_HOTMETAL,    ///< HOTMETAL
	DEV_PALETE_GLOBOW,      ///< GLOBOW
	DEV_PALETE_IRON2,       ///< IRON2
	DEV_PALETE_SEPIA,       ///< SEPIA
	DEV_PALETE_COLOR,       ///< COLOR
	DEV_PALETE_COLOR2,      ///< COLOR2
	DEV_PALETE_ICEFIRE,     ///< ICEFIRE
	DEV_PALETE_RAIN,        ///< RAIN
	DEV_PALETE_REDHOT,      ///< REDHOT
	DEV_PALETE_MAX,
}DEV_PALETTE_MODE;

/** ¼���ļ���ʽ*/
enum RecordType
{
	RECDT_INVALID = 10,             ///<¼���ʽ��Ч
	RECDT_AUTO_BY_FILE_NAME,        ///<�����ļ����Զ��ж��ļ���ʽ()
	RECDT_PRIVATE_MP4,              ///<˽��mp4�ļ�(ֻ����˽�в���������)
	RECDT_MP4,                      ///<MP4
	RECDT_MOV,                      ///<MOV
	RECDT_ASF,                      ///<asf
	RECDT_AVI,                      ///<avi
};


/**�ں���ͼģʽ*/
enum EnumViewMode
{
	EN_MODE_VIS = 1, ///< �ɼ�����ͼ
	EN_MODE_FUSION,  ///< �ں���ͼ 
};

/** �豸У׼�ļ�����*/
enum DevCalibType
{
	EN_DCT_TEMP = 0x40, ///<�����¶�
	EN_DCT_K,           ///<Kֵ
	EN_DCT_SENSOR,      ///<sensor
	EN_DCT_BLIND,       ///<äԪ
	EN_DCT_TABLE_TEMP,  ///<�¶ȱ�  (֮ǰ���¶ȱ���ϲ����˴�)
	EN_DCT_B,           ///<Bֵ
	EN_DCT_COMPENSATE,  ///<������²���
};
/** �������� */
typedef struct _INTRUSION_AREA
{
	unsigned short usX;				///< ���Ͻ�X����
	unsigned short usY;				///< ���Ͻ�Y����
	unsigned short usWidth;			///< �����ȣ���λ������
	unsigned short usHeight;		///< ����߶ȣ���λ������
} LI_INTRUSION_AREA;
/**���ܷ�������*/
enum IntelligentAnalysisType
{
	EN_IAT_INVALID,      //��Ч
	EN_IAT_CORDON,       //������1 
	EN_IAT_REGION_ENTRY, //��������
	EN_IAT_REGION_LEAVE, //�뿪����
	EN_IAT_GOODS_LEFT,   //��Ʒ����
	EN_IAT_GOODS_MOVE,   //��Ʒ��Ǩ
	EN_IAT_TARFILTER_MIN,//����Ŀ��-��С�ߴ�
	EN_IAT_TARFILTER_MAX,//����Ŀ��-���ߴ�
	EN_IAT_REGIONSHIELD, //��������
	EN_IAT_MAX,
};

/**@brief ���ּ��ص�
* @param[in] hHandle                ͨ�����Ӿ��
* @param[in] LI_INTRUSION_AREA      ��⵽�������������ݵ�ַ
* @param[in] areaCount              ��⵽��������������
* @return ��
*/
typedef void (WINAPI*INTRDETECCALLBACK)(IRNETHANDLE hHandle, LI_INTRUSION_AREA*pArea, int areaCount);
/**@brief ���ܷ���-Ŀ����˻ص�
* @param[in] hHandle          ͨ�����Ӿ��
* @param[in] targetWidth      Ŀ��ߴ�Ŀ�
* @param[in] targetHeight     Ŀ��ߴ�ĸ�
* @param[in] context          �Զ�������
* @return ��
*/
typedef void (CALLBACK*TargeFilterCallback)(IRNETHANDLE hHandle, int targetWidth, int targetHeight, void*context);

/**��������������ע����Ϣ�ṹ*/
typedef struct
{
	char *m_rvsbindurl;        ///<RVS bind url��NULL if all url
	WORD m_rvsbindport;        ///<RVS bind port
}RVSINFOREG;

/**ת����������Ϣ�ṹ*/
typedef struct
{
	char m_multiip[16];                 ///<multicast ipaddress
	WORD m_wMultiPort;                  ///<multicast port
	WORD m_wLocaport;                   ///<local port
	int  m_videobuff;                   ///<video buff num
	int  m_audiobuff;                   ///<audio buff num
	int  m_channuser;                   ///<channel user count
	int  m_totaluser;                   ///<totola user count
	int  (WINAPI *m_UserCheckcallback)(char *m_url, char *username, char *password);	///<user check callback function
	int  (WINAPI *m_UserConnectcallback)(char *m_sername, int channel, BOOL bStart, char *m_userurl, char *username, char *password, int transtype, IRNETHANDLE handle);	///<user login logout callback function
}IRNET_REDIRECTORINFO;

/**@brief ���»ص�����ָ��
* @param[in] hHandle        ���Ӿ��
* @param[in] fTemperature   �¶����ݵ�ַ����СΪͼ��Ŀ����,��λ��
* @param[in] uWidth         ͼ��Ŀ�
* @param[in] uHeight        ͼ��ĸ�
* @param[in] tempSpan       �¿�
* @param[in] context        ��IRNET_ClientRegTempCallBack��context��ͬһ�ݣ��˴�ֻ�����ش�
* @return ��
*/
typedef void(CALLBACK*TEMPCALLBACK)(IRNETHANDLE hHandle, float fTemperature[], UINT uWidth, UINT uHeight, DEV_TEMP_SPAN* tempSpan, void*context);

/**�豸��������*/
enum
{
	MESSAGE_SERVERCHS = 1,                  ///<���ͨ����̽ͷ�������������Ŀ
	MESSAGE_CMD_RESET,                      ///<����������
	MESSAGE_CMD_GETGLOBALPARAM,             ///<��ȡȫ�ֲ���
	MESSAGE_CMD_SETGLOBALPARAM,             ///<����ȫ�ֲ���
	MESSAGE_GETCHANNELPARAM,                ///<��ȡͨ������
	MESSAGE_SETCHANNELPARAM,                ///<����ͨ������
	MESSAGE_CMD_PARAMDEFAULT,               ///<�ָ�����Ĭ�ϲ���
	MESSAGE_CMD_GETSERIAL,                  ///<��ȡ���ڲ���
	MESSAGE_CMD_SETSERIAL,                  ///<���ô��ڲ���
	MESSAGE_CMD_GETSYSTIME,                 ///<��ȡϵͳʱ��
	MESSAGE_CMD_SETSYSTIME,                 ///<����ϵͳʱ��
	MESSAGE_CMD_GETSERIALNO,                ///<��ȡ���������к�
	MESSAGE_CMD_GETSYSUSER,                 ///<��÷��������û�
	MESSAGE_CMD_SETSYSUSER,                 ///<���÷��������û�
	MESSAGE_CMD_OUTPUTCTRL,                 ///<���Ʊ������(�û�����) 
	MESSAGE_CMD_OUTPUTSTATUS,               ///<�������״̬
	MESSAGE_CMD_PTZCMDFILE,                 ///<������̨�������������ļ�
	MESSAGE_CMD_PTZCMDNAME,                 ///<�����̨���������ļ�������
	MESSAGE_CMD_SETSUBCHANNELPARAM,         ///<���÷�������ͨ������
	MESSAGE_CMD_CAPTUREJPEG,                ///<����jpegץͼ(ͼ�������Ӳ��)
	MESSAGE_CMD_GETDISKSTATE,               ///<��ȡ����״̬
	MESSAGE_CMD_FORMATDISK,                 ///<��ʽ������
	MESSAGE_CMD_ENCKEYFRAME,                ///<�÷���������һ��I֡
	MESSAGE_CMD_GETPPPOEPARAM,              ///<��ȡPPPOE����
	MESSAGE_CMD_SETPPPOEPARAM,              ///<����PPPOE����
	MESSAGE_CMD_GETSERIAL232,               ///<485��232�ϲ� ��ȡ����232����
	MESSAGE_CMD_SETSERIAL232,               ///<���ô���232����
	MESSAGE_CMD_GETDHCP,                    ///<��ȡDHCP����
	MESSAGE_CMD_SETDHCP,                    ///<����DHCP����
	MESSAGE_CMD_GETUPNPCFG,                 ///<��ȡUPNP���ò���
	MESSAGE_CMD_SETUPNPCFG,                 ///<����UPNP���ò���
	MESSAGE_CMD_GETUPNPSTATUS,              ///<��ȡUPNP״̬
	MESSAGE_CMD_GETMAILCFG,                 ///<��ȡ�ʼ�������Ϣ
	MESSAGE_CMD_SETMAILCFG,                 ///<�����ʼ�������Ϣ
	MESSAGE_CMD_GETTIMERCAP,                ///<��ȡ��ʱץ�Ĳ���
	MESSAGE_CMD_SETTIMERCAP,                ///<���ö�ʱץ�Ĳ���
	MESSAGE_CMD_GETSYSSUPPORTEX,            ///<��ȡϵͳ��չ֧����Ϣ
	MESSAGE_CMD_GETDVRSENSORALARM,          ///<��ȡDVR̽ͷ��������
	MESSAGE_CMD_SETDVRSENSORALARM,          ///<����DVR��ͷ��������
	MESSAGE_CMD_GETENCODETYPE,              ///<��ȡ��������
	MESSAGE_CMD_SETENCODETYPE,              ///<���ñ�������
	MESSAGE_CMD_MAILTEST,                   ///<�ʼ�����
	MESSAGE_CMD_GETRTSPPARAMEX,             ///<��ȡRTSP����
	MESSAGE_CMD_SETRTSPPARAMEX,             ///<����RTSP����
	MESSAGE_CMD_GETTIMEZONE,                ///<��ȡ������ʱ������
	MESSAGE_CMD_SETTIMEZONE,                ///<���÷�����ʱ������
	MESSAGE_CMD_GETCHANNELOSD_EX,           ///<����OSD����(��չ)
	MESSAGE_CMD_SETCHANNELOSD_EX,           ///<��ȡOSD����(��չ)
	MESSAGE_CMD_GETFLASHINFO,               ///<���flash�汾��Ϣ
	MESSAGE_CMD_GETUPNPPORTINFO,            ///<��ȡUPNP�˿���Ϣ

	MESSAGE_CMD_SET_FFCCTRL,                ///<���ſ���
	MESSAGE_CMD_GET_CAPTURETYPE,            ///<��ȡץ������
	MESSAGE_CMD_SET_CAPTURETYPE,            ///<����ץ������

	MESSSGE_CMD_GET_OSDPARAM,               ///<��ȡOSD����
	MESSSGE_CMD_SET_OSDPARAM,               ///<����OSD����
	MESSSGE_CMD_GET_IROSDPARAM,             ///<��ȡ����OSD����
	MESSSGE_CMD_SET_IROSDPARAM,             ///<���ú���OSD����
	MESSSGE_CMD_GET_REGIONTEMPPARAM,        ///<��ȡ������²���
	MESSSGE_CMD_SET_REGIONTEMPPARAM,        ///<����������²���
	MESSSGE_CMD_GET_REGIONTEMPALARM,        ///<��ȡ������±�������
	MESSSGE_CMD_SET_REGIONTEMPALARM,        ///<����������±�������
	MESSSGE_CMD_GET_REGIONTEMPVALUE,        ///<��ȡ��������¶�ֵ
	MESSSGE_CMD_GET_VIDEOOUTMODE,           ///<��ȡ��Ƶ���ģʽ
	MESSSGE_CMD_SET_VIDEOOUTMODE,           ///<������Ƶ���ģʽ
	MESSSGE_CMD_GET_TEMPDATA,               ///<��ȡ��������
	MESSSGE_CMD_GET_GLOBALTEMPALARM,        ///<��ȡȫ�ֲ��±�������
	MESSSGE_CMD_SET_GLOBALTEMPALARM,        ///<����ȫ�ֲ��±�������                        
	MESSAGE_CMD_GET_IR_VIPARAM,             ///<��ȡ����ͼ�����������
	MESSAGE_CMD_SET_IR_VIPARAM,             ///<���ú���ͼ�����������
	MESSAGE_CMD_GET_IR_DDEPARAM,            ///<��ȡ����ͼ����DDE����
	MESSAGE_CMD_SET_IR_DDEPARAM,            ///<���ú���ͼ����DDE����
	MESSAGE_CMD_GET_IR_STRETCHMODE,         ///<��ȡ����ͼ��������ģʽ
	MESSAGE_CMD_SET_IR_STRETCHMODE,         ///<���ú���ͼ��������ģʽ

	MESSAGE_CMD_GET_TAUGAINMODE,            ///<��ȡTAU����ģʽ
	MESSAGE_CMD_SET_TAUGAINMODE,            ///<����TAU����ģʽ

	MESSAGE_CMD_GET_GPSINFO,                ///<��ȡGPS��Ϣ
	MESSAGE_CMD_SET_GPSINFO,                ///<����GPS��Ϣ

	MESSAGE_CMD_GETDVRSYSUSEREX,            ///<��ȡ�豸�û���Ϣ
	MESSAGE_CMD_SETDVRSYSUSEREX,            ///<�����豸�û���Ϣ
	MESSAGE_CMD_REC_REMOTE_BEG,             ///<Զ��¼��
	MESSAGE_CMD_REC_REMOTE_END,             ///<Զ��¼��

	MESSAGE_CMD_GET_MSDSTATUS,              ///<SD���ռ��ȡ

	MESSAGE_CMD_GET_CAL_TEMP_IN_AREA,       ///<��ȡ�������
	MESSAGE_CMD_SET_CAL_TEMP_IN_AREA,       ///<���û������

	MESSAGE_CMD_GET_PWMUART_CFG,            ///<��ȡ��������
	MESSAGE_CMD_SET_PWMUART_CFG,            ///<���ô�������

	MESSAGE_CMD_GET_TEMP_ALARM_PARAM,       ///<�¶ȳ��ޱ���
	MESSAGE_CMD_SET_TEMP_ALARM_PARAM,       ///<�¶ȳ��ޱ���

	MESSAGE_CMD_GET_RADMET_PARAM,           ///<����������
	MESSAGE_CMD_SET_RADMET_PARAM,           ///<����������

	MESSAGE_CMD_GET_STILLCAPTURE,           ///<��ʱץ�Ŀ���
	MESSAGE_CMD_SET_STILLCAPTURE,           ///<��ʱץ�Ŀ���

	MESSAGE_CMD_GET_ALARM_INPUT_STATUS,     ///<��ȡ��������̽ͷ״̬

	MESSAGE_CMD_GET_TEMPALARMCTRL,          ///<���±�������
	MESSAGE_CMD_SET_TEMPALARMCTRL,          ///<���±�������

	MESSAGE_CMD_GET_SDCARDFULLCTRL,         ///<SD����������
	MESSAGE_CMD_SET_SDCARDFULLCTRL,         ///<SD����������

	MESSAGE_CMD_GET_FIREPOINTPARAM,         ///<��ȡ������
	MESSAGE_CMD_SET_FIREPOINTPARAM,         ///<���û�����

	MESSAGE_CMD_GET_FIREPOINT,				///<��ȡ���

	MESSAGE_CMD_GET_FIREBEHAVIOURPARAM,     ///<��ȡ���Ʋ���
	MESSAGE_CMD_SET_FIREBEHAVIOURPARAM,     ///<���û��Ʋ���

	MESSAGE_CMD_GET_FIREBEHAVIOUR,          ///<��ȡ����

	MESSAGE_CMD_GET_OSD_REGION_TRANSPARENT_PARAM,/**<OSD����͸������*/
	MESSAGE_CMD_SET_OSD_REGION_TRANSPARENT_PARAM,/**<OSD����͸������*/
	MESSAGE_CMD_GET_BUZZER_ENABLE,               /**<������ʹ��*/
	MESSAGE_CMD_SET_BUZZER_ENABLE,               /**<������ʹ��*/

	MESSAGE_CMD_GETREMOTEHOST,                  /**<Զ������*/
	MESSAGE_CMD_SETREMOTEHOST,                  /**<Զ������*/

	MESSAGE_CMD_GET_REGIONTEMPALARMCTRL,        /**<�����¶ȱ�������*/
	MESSAGE_CMD_SET_REGIONTEMPALARMCTRL,        /**<�����¶ȱ�������*/

	MESSAGE_CMD_GET_TEMPMEASURETYPE,            /**<��������*/
	MESSAGE_CMD_SET_TEMPMEASURETYPE,            /**<��������*/
	MESSAGE_CMD_GET_AREATEMPCOMPARECTRL,        /**<�����¶ȶԱȿ���*/
	MESSAGE_CMD_SET_AREATEMPCOMPARECTRL,        /**<�����¶ȶԱȿ���*/

	MESSAGE_CMD_GET_REGIONOSDNAME,              /**<��������OSD*/
	MESSAGE_CMD_SET_REGIONOSDNAME,              /**<��������OSD*/

	MESSAGE_GETALARMPARAM,                      /**<��������*/
	MESSAGE_SETALARMPARAM,                      /**<��������*/
	MESSAGE_CMD_GETMOTIONPARAM,                 /**<�ƶ�������*/
	MESSAGE_CMD_SETMOTIONPARAM,                 /**<�ƶ�������*/
	MESSAGE_CMD_GETVIDEOMASK,                   /**<��Ƶ���β���*/
	MESSAGE_CMD_SETVIDEOMASK,                   /**<��Ƶ���β���*/
	MESSAGE_CMD_GETCHANNELOSD,                  /**<��Ƶ���Ӳ���*/
	MESSAGE_CMD_SETCHANNELOSD,                  /**<��Ƶ���Ӳ���*/
	MESSAGE_CMD_AFFIRMUSER,                     /**<��֤�û�*/
	MESSAGE_CMD_GETTIMEDRESET,                  /**<��ʱ����*/
	MESSAGE_CMD_SETTIMEDRESET,                  /**<��ʱ����*/
	MESSAGE_CMD_GETHIDEALARM,                   /**<�ڵ�����*/
	MESSAGE_CMD_SETHIDEALARM,                   /**<�ڵ�����*/
	MESSAGE_CMD_GETSUBCHANNELPARAM,             /**<��ͨ������*/
	MESSAGE_CMD_GETRECORDPARAM,                 /**<Ӳ��¼�����*/
	MESSAGE_CMD_SETRECORDPARAM,                 /**<Ӳ��¼�����*/
	MESSAGE_CMD_GETJPEGCAPPARAM,                /**<JPEGץ�Ĳ���*/
	MESSAGE_CMD_SETJPEGCAPPARAM,                /**<JPEGץ�Ĳ���*/
	MESSAGE_CMD_GETSENSORALARM,                 /**<����̽ͷ����*/
	MESSAGE_CMD_SETSENSORALARM,                 /**<����̽ͷ����*/
	MESSAGE_CMD_GETAUDIOPARAM,                  /**<��Ƶ����*/
	MESSAGE_CMD_SETAUDIOPARAM,                  /**<��Ƶ����*/
	MESSAGE_CMD_GETCDMAPARAM,                   /**<CDMA����*/
	MESSAGE_CMD_SETCDMAPARAM,                   /**<CDMA����*/
	MESSAGE_CMD_GETWIFIPARAM,                   /**<Wifi����*/
	MESSAGE_CMD_SETWIFIPARAM,                   /**<Wifi����*/
	MESSAGE_CMD_GETLINKCONFIG,                  /**<�������ò���*/
	MESSAGE_CMD_SETLINKCONFIG,                  /**<�������ò���*/
	MESSAGE_CMD_GETDDNSEXPARAM,                 /**<DDNS���Ӳ���*/
	MESSAGE_CMD_SETDDNSEXPARAM,                 /**<DDNS���Ӳ���*/
	MESSAGE_CMD_GETEXALARMPARAM,                /**<�ⲿ��������*/
	MESSAGE_CMD_SETEXALARMPARAM,                /**<�ⲿ��������*/
	MESSAGE_CMD_GETHUMITUREPRAM,                /**<��ʪ�ȱ�������*/
	MESSAGE_CMD_SETHUMITUREPRAM,                /**<��ʪ�ȱ�������*/
	MESSAGE_CMD_GETVIDEOOFFSET,                 /**<��Ƶƫ����*/
	MESSAGE_CMD_SETVIDEOOFFSET,                 /**<��Ƶƫ����*/
	MESSAGE_CMD_GETVIDEOMASKAREA,               /**<��Ƶ������*/
	MESSAGE_CMD_SETVIDEOMASKAREA,               /**<��Ƶ������*/
	MESSAGE_CMD_GETSNMPCONFIG,                  /**<����������*/
	MESSAGE_CMD_SETSNMPCONFIG,                  /**<����������*/
	MESSAGE_CMD_GETALARMSMS,                    /**<�������Ų���*/
	MESSAGE_CMD_SETALARMSMS,                    /**<�������Ų���*/
	MESSAGE_CMD_GETALARMTYPE,                   /**<̽ͷ����*/
	MESSAGE_CMD_SETALARMTYPE,                   /**<̽ͷ����*/
	MESSAGE_CMD_GETFTP,                         /**<FTP��Ϣ*/
	MESSAGE_CMD_SETFTP,                         /**<FTP��Ϣ*/
	MESSAGE_CMD_GETCCDPARAM,                    /**<CCD����*/
	MESSAGE_CMD_SETCCDPARAM,                    /**<CCD����*/
	MESSAGE_CMD_GETPLATFORMINFO,                /**<ƽ̨��Ϣ*/
	MESSAGE_CMD_SETPLATFORMINFO,                /**<ƽ̨��Ϣ*/
	MESSAGE_CMD_GETVI2VO,                       /**<ͼ�񻷳�ʹ��*/
	MESSAGE_CMD_SETVI2VO,                       /**<ͼ�񻷳�ʹ��*/
	MESSAGE_CMD_GETALARMFTPUPLOAD,              /**<̽ͷ���������ϴ�FTP����*/
	MESSAGE_CMD_SETALARMFTPUPLOAD,              /**<̽ͷ���������ϴ�FTP����*/
	MESSAGE_CMD_GETMOTIONCONTACTEX,             /**<�ƶ���ⱨ��������չ����*/
	MESSAGE_CMD_SETMOTIONCONTACTEX,             /**<�ƶ���ⱨ��������չ����*/
	MESSAGE_CMD_GETDVRMOTIONALARM,              /**<DVR�ƶ���ⱨ������*/
	MESSAGE_CMD_SETDVRMOTIONALARM,              /**<DVR�ƶ���ⱨ������*/
	MESSAGE_CMD_GETDVRHIDEALARM,                /**<DVR��Ƶ�ڵ���������*/
	MESSAGE_CMD_SETDVRHIDEALARM,                /**<DVR��Ƶ�ڵ���������*/
	MESSAGE_CMD_GETDVROTHERALARM,               /**<DVR������������*/
	MESSAGE_CMD_SETDVROTHERALARM,               /**<DVR������������*/
	MESSAGE_CMD_SETBKDISK,                      /**<DVR������*/
	MESSAGE_CMD_GETSMARTINFO,                   /**<DVRӲ��SMART��Ϣ*/
	MESSAGE_CMD_GETVIEWPARAM,                   /**<V0����*/
	MESSAGE_CMD_SETVIEWPARAM,                   /**<V0����*/
	MESSAGE_CMD_GETLOOPVIEW,                    /**<��ѯ���Ʋ���*/
	MESSAGE_CMD_SETLOOPVIEW,                    /**<��ѯ���Ʋ���*/
	MESSAGE_CMD_GETDVRUSER,                     /**<DVR�û���Ϣ*/
	MESSAGE_CMD_SETDVRUSER,                     /**<DVR�û���Ϣ*/
	MESSAGE_CMD_GETDVRCHANNELOSD,               /**<DVR��Ƶ���Ӳ���*/
	MESSAGE_CMD_SETDVRCHANNELOSD,               /**<DVR��Ƶ���Ӳ���*/
	MESSAGE_CMD_GETVIDEOOFFSETEX,               /**<��Ƶƫ����*/
	MESSAGE_CMD_SETVIDEOOFFSETEX,               /**<��Ƶƫ����*/
	MESSAGE_CMD_GETDEVICEID,                    /**<�豸ID*/
	MESSAGE_CMD_SETDEVICEID,                    /**<�豸ID*/
	MESSAGE_CMD_GETKEYBOARDEX,                  /**<���̲���*/
	MESSAGE_CMD_SETKEYBOARDEX,                  /**<���̲���*/
	MESSAGE_CMD_GETCHOOSEPTZ,                   /**<ѡ����̨*/
	MESSAGE_CMD_SETCHOOSEPTZ,                   /**<ѡ����̨*/
	MESSAGE_CMD_GETDVRDOUBLEBITS,               /**<ѡ���������*/
	MESSAGE_CMD_SETDVRDOUBLEBITS,               /**<ѡ���������*/
	MESSAGE_CMD_GETPROTOCOLPARAM,               /**<ѡ���Э��*/
	MESSAGE_CMD_SETPROTOCOLPARAM,               /**<ѡ���Э��*/
	MESSAGE_CMD_GETFTPTIMEREC,                  /**<FTP��ʱ¼��*/
	MESSAGE_CMD_SETFTPTIMEREC,                  /**<FTP��ʱ¼��*/
	MESSAGE_CMD_GETSUBENCODETYPE,               /**<ѡ��ı�������*/
	MESSAGE_CMD_SETSUBENCODETYPE,               /**<ѡ��ı�������*/
	MESSAGE_CMD_GETPROLOOP,                     /**<Ԥ�õ���ѯ*/
	MESSAGE_CMD_SETPROLOOP,                     /**<Ԥ�õ���ѯ*/
	MESSAGE_CMD_GETAUDIOSILENT,                 /**<��Ƶ��������*/
	MESSAGE_CMD_SETAUDIOSILENT,                 /**<��Ƶ��������*/
	MESSAGE_CMD_GETDVRUSERSTATE,                /**<�û�״̬*/
	MESSAGE_CMD_SETDVRUSERSTATE,                /**<�û�״̬*/
	MESSAGE_CMD_GETREDUNDANCERECORD,            /**<����¼��״̬*/
	MESSAGE_CMD_SETREDUNDANCERECORD,            /**<����¼��״̬*/
	MESSAGE_CMD_GETTHIRDENCODEPARA,             /**<������������*/
	MESSAGE_CMD_SETTHIRDENCODEPARA,             /**<������������*/
	MESSAGE_CMD_GETTHIRDENCODETYPE,             /**<������������*/
	MESSAGE_CMD_SETTHIRDENCODETYPE,             /**<������������*/
	MESSAGE_CMD_GETPTZCTRLTIME,                 /**<��̨��������ʱ��*/
	MESSAGE_CMD_SETPTZCTRLTIME,                 /**<��̨��������ʱ��*/
	MESSAGE_CMD_GETAUDIOPARAMTYPE,              /**<��Ƶ����*/
	MESSAGE_CMD_SETAUDIOPARAMTYPE,              /**<��Ƶ����*/
	MESSAGE_CMD_GETDVRVOPARAM,                  /**<DVR��V0�������*/
	MESSAGE_CMD_SETDVRVOPARAM,                  /**<DVR��V0�������*/
	MESSAGE_CMD_GETVLCPARAM,                    /**<VLC����*/
	MESSAGE_CMD_SETVLCPARAM,                    /**<VLC����*/
	MESSAGE_CMD_GETNTPPARAM,                    /**<NTP����*/
	MESSAGE_CMD_SETNTPPARAM,                    /**<NTP����*/
	MESSAGE_CMD_GETBKDISK,                      /**<������Ӳ��*/
	MESSAGE_CMD_GETVIDEOINTERESTAREA,           /**<��Ƶ����Ȥ�������*/
	MESSAGE_CMD_SETVIDEOINTERESTAREA,           /**<��Ƶ����Ȥ�������*/
	MESSAGE_CMD_GETVCAABILITY,                  /**<֧�ֵ����ܷ�������*/
	MESSAGE_CMD_GETCCDPARAMEX,                  /**<Sensor����*/
	MESSAGE_CMD_SETCCDPARAMEX,                  /**<Sensor����*/
	MESSAGE_CMD_GETSTORAGE,                     /**<Ӳ������Ϣ(��)*/
	MESSAGE_CMD_SETSTORAGE,                     /**<Ӳ������Ϣ(��)*/
	MESSAGE_CMD_GETSMART,                       /**<Ӳ��smart��Ϣ(��)*/
	MESSAGE_CMD_GETEXACTTIMEZONE,               /**<׼ȷ��ʱ��*/
	MESSAGE_CMD_SETEXACTTIMEZONE,               /**<׼ȷ��ʱ��*/
	MESSAGE_CMD_GETTRAFFICLIGHTCFG,             /**<���̵�����*/
	MESSAGE_CMD_SETTRAFFICLIGHTCFG,             /**<���̵�����*/
	MESSAGE_CMD_GETRECORDSTREAMTYPE,            /**<¼�����������*/
	MESSAGE_CMD_SETRECORDSTREAMTYPE,            /**<¼�����������*/
	MESSAGE_CMD_GETWIFIMODE,                    /**<wifiģʽ*/
	MESSAGE_CMD_SETWIFIMODE,                    /**<wifiģʽ*/
	MESSAGE_CMD_GETALARMSHORTMSGPARAM,          /**<�������Ų���*/
	MESSAGE_CMD_SETALARMSHORTMSGPARAM,          /**<�������Ų���*/
	MESSAGE_CMD_GETNETERRORPARAM,               /**<�����쳣��������*/
	MESSAGE_CMD_SETNETERRORPARAM,               /**<�����쳣��������*/
	MESSAGE_CMD_GETDISKSELECTPARAM,             /**<�豸�洢����*/
	MESSAGE_CMD_SETDISKSELECTPARAM,             /**<�豸�洢����*/
	MESSAGE_CMD_GETDAYNIGHTPARAM,               /**<��ҹת������*/
	MESSAGE_CMD_SETDAYNIGHTPARAM,               /**<��ҹת������*/
	MESSAGE_CMD_GETVIDEOINTYPE,                 /**<��Ƶ�������*/
	MESSAGE_CMD_SETVIDEOINTYPE,                 /**<��Ƶ�������*/
	MESSAGE_CMD_GETWIFIENABLE,                  /**<wifi��3g֧����Ϣ*/
	MESSAGE_CMD_GETNOISEMODEPARAM,              /**<�������*/
	MESSAGE_CMD_SETNOISEMODEPARAM,              /**<�������*/
	MESSAGE_CMD_GETVPNINFO,                     /**<VPN����*/
	MESSAGE_CMD_SETVPNINFO,                     /**<VPN����*/
	MESSAGE_CMD_GETWIFIINFO,                    /**<wifi����*/
	MESSAGE_CMD_GETPHOTO_SENSITIVE_TYPE,        /**<������������*/
	MESSAGE_CMD_SETPHOTO_SENSITIVE_TYPE,        /**<������������*/
	MESSAGE_CMD_GET_ENC_VPP_MAIN,               /**<������ƵԤ��������*/
	MESSAGE_CMD_SET_ENC_VPP_MAIN,               /**<������ƵԤ��������*/
	MESSAGE_CMD_SET_ENC_VPP_SUB,                /**<������ƵԤ��������*/
	MESSAGE_CMD_GET_ENC_VPP_SUB,                /**<������ƵԤ��������*/
	MESSAGE_CMD_SET_ENC_VPP_THIRD,              /**<������ƵԤ��������*/
	MESSAGE_CMD_GET_ENC_VPP_THIRD,              /**<������ƵԤ��������*/
	MESSAGE_CMD_SET_ENC_PROFILE_MAIN,           /**<���뼶������*/
	MESSAGE_CMD_GET_ENC_PROFILE_MAIN,           /**<���뼶������*/
	MESSAGE_CMD_SET_ENC_PROFILE_SUB,            /**<���뼶������*/
	MESSAGE_CMD_GET_ENC_PROFILE_SUB,            /**<���뼶������*/
	MESSAGE_CMD_SET_ENC_PROFILE_THIRD,          /**<���뼶������*/
	MESSAGE_CMD_GET_ENC_PROFILE_THIRD,          /**<���뼶������*/
	MESSAGE_CMD_GET_CCD_RGB_DEFAULT,            /**<sensor��RGB����*/
	MESSAGE_CMD_SET_CCD_AI_CHECK,               /**<AIУ��ֵ*/
	MESSAGE_CMD_GET_REMOTESTREAMTYPE,           /**<Զ�������ϴ�����������*/
	MESSAGE_CMD_SET_REMOTESTREAMTYPE,           /**<Զ�������ϴ�����������*/
	MESSAGE_CMD_GET_ENCRYPTIONTYPE,             /**<���ܷ�ʽ(�ʼ�����)*/
	MESSAGE_CMD_SET_ENCRYPTIONTYPE,             /**<���ܷ�ʽ(�ʼ�����)*/
	MESSAGE_CMD_GETSENSORPARAM_DEVTYPE,         /**<Զ�̲����е��豸����*/
	MESSAGE_CMD_SETSENSORPARAM_DEVTYPE,         /**<Զ�̲����е��豸����*/
	MESSAGE_CMD_GETDEVICECFG,                   /**<NVR��ģת������*/
	MESSAGE_CMD_SETDEVICECFG,                   /**<NVR��ģת������*/
	MESSAGE_CMD_GETCHANNELRECORDPLANEX,         /**<������ͨ������:¼��ƻ�*/
	MESSAGE_CMD_SETCHANNELRECORDPLANEX,         /**<������ͨ������:¼��ƻ�*/
	MESSAGE_CMD_GETMOTIONALARMAREA,             /**<�ƶ��������*/
	MESSAGE_CMD_SETMOTIONALARMAREA,             /**<�ƶ��������*/
	MESSAGE_CMD_GET_OSDBORDER,                  /**<OSD�߿����*/
	MESSAGE_CMD_SET_OSDBORDER,                  /**<OSD�߿����*/
	MESSAGE_CMD_GET_RESOLUTION,                 /**<����֧�ֵķֱ���*/
	MESSAGE_CMD_GET_QOS_TOS,                    /**<����ƵQOS���ȼ�*/
	MESSAGE_CMD_SET_QOS_TOS,                    /**<����ƵQOS���ȼ�*/
	MESSAGE_CMD_GET_SNMP_CFG,                   /**<SNMP����*/
	MESSAGE_CMD_SET_SNMP_CFG,                   /**<SNMP����*/
	MESSAGE_CMD_GET_IPV6_CFG,                   /**<����IPV6*/
	MESSAGE_CMD_SET_IPV6_CFG,                   /**<����IPV6*/

	MESSAGE_CMD_GET_SENSORVERSION,              /**<��ȡSensor�汾��*/
	MESSAGE_CMD_GET_WINCALIPARAM,               /**<���ڲ�������*/
	MESSAGE_CMD_SET_WINCALIPARAM,               /**<���ڲ�������*/

	MESSAGE_CMD_GET_SMT_ANALY_ADVANCE,      ///<���ܷ���-�߼�����
	MESSAGE_CMD_SET_SMT_ANALY_ADVANCE,      ///<���ܷ���-�߼�����

	MESSAGE_CMD_GET_DAYNIGHTPARAM_EX,          /**��ҹ����*/
	MESSAGE_CMD_SET_DAYNIGHTPARAM_EX,          /**��ҹ����*/

	MESSAGE_CMD_GET_IROSD2VISPARAM,             /**�ɼ�����Ӳ���osd����*/
	MESSAGE_CMD_SET_IROSD2VISPARAM,             /**�ɼ�����Ӳ���osd����*/

	MESSAGE_CMD_GET_CHANNELTYPE,                /**ͨ������*/
	MESSAGE_CMD_GET_ANTIFLICKER,                /**��������*/
	MESSAGE_CMD_SET_ANTIFLICKER,                /**��������*/
	MESSAGE_CMD_GET_TEMPREGIONOFFSET,           /** ������λ��ƫ��(�ɼ���ͨ����Ч)*/
	MESSAGE_CMD_SET_TEMPREGIONOFFSET,           /** ������λ��ƫ��(�ɼ���ͨ����Ч)*/

	MESSAGE_CMD_GET_TEMPVALUE_EX,               /**�����¶�ֵ(��չ)*/

	MESSAGE_CMD_GET_SENSOR_SERIALNO,        ///<��ȡsensor���к�
	MESSAGE_CMD_SET_SENSOR_SERIALNO,        ///<����sensor���к�

	MESSAGE_CMD_GET_SWITCHMODE,             ///<�л�У׼ģʽ
	MESSAGE_CMD_SET_SWITCHMODE,             ///<�л�У׼ģʽ

	MESSAGE_CMD_TAU_FACDEFAULT,             ///<TAU�ָ�Ĭ��
	MESSAGE_CMD_TAU_SAVEPARAM,              ///<TAU�������

	MESSAGE_CMD_GET_TAU_SEGMENT,            ///<TAU�α��
	MESSAGE_CMD_SET_TAU_SEGMENT,            ///<TAU�α��

	MESSAGE_CMD_GET_HT_BLACK_CLIPPING,      ///<�ڱ߲ü�
	MESSAGE_CMD_SET_HT_BLACK_CLIPPING,      ///<�ڱ߲ü�

	MESSAGE_CMD_GET_DENOISEPARAM,           ///<����
	MESSAGE_CMD_SET_DENOISEPARAM,           ///<����
	MESSAGE_CMD_GET_ROLLPARAM,              ///<��ת
	MESSAGE_CMD_SET_ROLLPARAM,              ///<��ת
	MESSAGE_CMD_GET_DIGITALOUTMODE,         ///<�������ģʽ
	MESSAGE_CMD_SET_DIGITALOUTMODE,         ///<�������ģʽ
	MESSAGE_CMD_GET_FFCMODE,                ///<FFCģʽ
	MESSAGE_CMD_SET_FFCMODE,                ///<FFCģʽ
	MESSAGE_CMD_GET_FFCFRAMEPARAM,          ///<�Զ�FFC֡������
	MESSAGE_CMD_SET_FFCFRAMEPARAM,          ///<�Զ�FFC֡������
	MESSAGE_CMD_GET_FFCTEMPPARAM,           ///<�Զ�FFC�¶Ȳ���
	MESSAGE_CMD_SET_FFCTEMPPARAM,           ///<�Զ�FFC�¶Ȳ���
	MESSAGE_CMD_GET_VTEMPTEMP,              ///<VTEMP�¶Ȳ���
	MESSAGE_CMD_SET_VTEMPTEMP,              ///<VTEMP�¶Ȳ���
	MESSAGE_CMD_GET_VTEMPREGION,            ///<VTEMP�������
	MESSAGE_CMD_SET_VTEMPREGION,            ///<VTEMP�������
	MESSAGE_CMD_GET_KENABLE,                ///<Kֵ��Ч
	MESSAGE_CMD_SET_KENABLE,                ///<Kֵ��Ч
	MESSAGE_CMD_GET_BENABLE,                ///<Bֵ��Ч
	MESSAGE_CMD_SET_BENABLE,                ///<Bֵ��Ч
	MESSAGE_CMD_GET_BLINDENABLE,            ///<äԪ��Ч
	MESSAGE_CMD_SET_BLINDENABLE,            ///<äԪ��Ч
	MESSAGE_CMD_GET_FILTEENABLE,            ///<ʱ���˲���Ч
	MESSAGE_CMD_SET_FILTEENABLE,            ///<ʱ���˲���Ч
	MESSAGE_CMD_GET_FILTEPARAM,             ///<ʱ���˲�ϵ��
	MESSAGE_CMD_SET_FILTEPARAM,             ///<ʱ���˲�ϵ��
	MESSAGE_CMD_GET_TRAN,                   ///<͸��
	MESSAGE_CMD_SET_TRAN,                   ///<͸��
	MESSAGE_CMD_GET_SMART_DATA,             ///<smartData����
	MESSAGE_CMD_SET_SMART_DATA,             ///<smartData����
	MESSAGE_CMD_GET_SENSOR_TEMP,            ///<��о�������¶�
	MESSAGE_CMD_SET_WRITE_FLASH,            ///<�̻�flash
	MESSAGE_CMD_GET_SENSOR_STATE,           ///<��ǰsensor״̬
	MESSAGE_CMD_GET_OBJTEMP_FLUXRANGE,      ///<�¶����ط�Χ
	MESSAGE_CMD_GET_TAUNUCTABLEINDEXES,     ///<��ȡ��ǰ֧�ֵ�NUC Table��������
	MESSAGE_CMD_GET_TAUNUCTABLEFUNCTION,    ///<��ȡ��ǰTAU��֧�ֵ� NUC Table��⹦��
	MESSAGE_CMD_SET_TAUNUCTABLEFUNCTION,    ///<���õ�ǰTAU��֧�ֵ� NUC Table��⹦��
	MESSAGE_CMD_WNDCALIB_STARTUP,           ///<����У׼ ����
	MESSAGE_CMD_WNDCALIB_CAPBASEDATA,       ///<ץȡ��N������Ļ�׼����
	MESSAGE_CMD_WNDCALIB_CAPOBJDATA,        ///<ץȡ��N�������Ŀ������
	MESSAGE_CMD_WNDCALIB_CALC,              ///<���㴰��У׼ϵ��

	MESSAGE_CMD_MAX,                        ///<����
};

/**
* @brief ��ʼ���ͻ���SDK
* @param[in] m_nMessage        Ӧ�ó����һ���û��Զ�����Ϣ
* @param[in] m_hWnd            Ӧ�ó�����һ�����ھ��
* @param[in] m_messagecallback ��Ϣ�ص������ӿ�
* @param[in] context           �û�������
* @param[in] key               �����ַ�����Ĭ��Ϊ��
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
* @note �������ӶϿ��������ӳɹ�����Ϣ����ͨ���ص�����m_messagecallback�첽֪ͨ
* @code
//�ص���������˵��
hHandle [IN] ���Ӿ����IRNET_ClientStart����ֵ
wParam  [IN] ����1
lParam  [IN] ����2
context [IN] �û�������
* @endcode
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_ClientStartup(UINT m_nMessage, HWND m_hWnd, void (WINAPI *m_messagecallback)(IRNETHANDLE hHandle, WPARAM wParam, LPARAM lParam, void *context) = NULL, void *context = NULL, char *key = NULL);

/**
* @brief ��ȡ��Ϣ
* @param[in,out] m_sername  ����������
* @param[in,out] m_url      ��������ַ
* @param[in,out] m_port     �������˿�
* @param[in,out] m_ch       ������ͨ��
* @param[in,out] wParam     ����Ϣ
* @param[in,out] lParam     ����Ϣ
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_ClientReadMessage(char *m_sername, char *m_url, WORD *m_port, int *m_ch,/*DWORD*/WPARAM *wParam, LPARAM *lParam);

/**
* @brief ���ÿͻ��˳�ʱʱ��ͳ��Դ���
* @param[in] m_waitnum  �ȴ�ʱ��(��)
* @param[in] m_trynum   ���Դ���
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
* @attention ��Ҫ��m_waitnum��ֵ���õ�̫С�����ͨ��internet���ӷ��������п��ܻ�����ʧ��
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_ClientWaitTime(int m_waitnum = 6, int m_trynum = 3);

/**
* @brief ж�ؿͻ���SDK
* @param ��
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_ClientCleanup();

///////////////ͼ����ʾ///////////////////
/**
* @brief ��������������ӣ���ʵʱԤ��ͼ��
* @param[in] m_url       �������ĵ�ַ��ת���������ĵ�ַ
* @param[in] m_pChaninfo CHANNEL_CLIENTINFO��ָ��
* @param[in] wserport    ��������ת���������Ķ˿ں�
* @param[in] streamtype  ���ӵ���������,0:������ 1:������,������Ҫ�豸֧�֣�Ĭ��Ϊ������
* @return -1��ʾʧ�ܣ�����ֵΪ���Ӿ��
*/
CNET_APIIMPORT IRNETHANDLE  CALLINGCONVEN IRNET_ClientStart(char *m_url, CHANNEL_CLIENTINFO *m_pChaninfo, WORD wserport = 3000, int streamtype = 0);

/**
* @brief ֹͣ���ţ��Ͽ��������������
* @param hHandle [IN] ���Ӿ����IRNET_ClientStart�ķ���ֵ
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_ClientStop(IRNETHANDLE hHandle);

/**
* @brief ����ͼ����ʾ
* @param[in] hHandle    IRNET_ClientStart�ķ���ֵ
* @param[in] decodesign �ͷŽ�������Դ��־��1���ͷŽ�������Դ��0�����ͷŽ�������Դ��
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
* @note ������ͨ��ʱ���m_playstartΪFALSE������Ҫ�ֶ����øýӿ���ʵ��ͼ�����ʾ
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_ClientStartView(IRNETHANDLE hHandle, BOOL decodesign = TRUE);

/**
* @brief ֹͣͼ����ʾ
* @param[in] hHandle IRNET_ClientStart�ķ���ֵ
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_ClientStopView(IRNETHANDLE hHandle);

/**
* @brief ����ͼ����ʾ�Ĵ���
* @param[in] hHandle IRNET_ClientStart�ķ���ֵ
* @param[in] hWnd    ͼ�񴰿�
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_ClientSetWnd(IRNETHANDLE hHandle, HWND hWnd);

/**
* @brief ˢ��ͼ����ʾ�Ĵ���
* @param[in] hHandle IRNET_ClientStart�ķ���ֵ
* @param[in] rect    ����ˢ�������Ժ���ʾ��ͼ���ڸ�������ʾ��
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_ClientRefrenshWnd(IRNETHANDLE hHandle, RECT *rect = NULL);

/**
* @brief ����ͼ����ӳ�ʱ��
* @param[in] hHandle   IRNET_ClientStart�ķ���ֵ
* @param[in] delaytime �ӳ�ʱ�䣬��λΪ֡,0:����ʱ��1-100Ϊ��ʱʱ�䣬ֵԽ����ʱԽ��ͼ��������Ը���
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_ClientSetDelayTime(IRNETHANDLE hHandle, int delaytime);

/**
* @brief ����ͼ�������
* @param[in] hHandle  IRNET_ClientStart�ķ���ֵ
* @param[in] bShow    ��ֹ������־
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_ClientPreventImageSplit(IRNETHANDLE hHandle, BOOL bsplit);

/**
* @brief ������ֹͣ���ݴ���
* @param[in] hHandle IRNET_ClientStart�ķ���ֵ
* @param[in] bStart  TRUE����������������Ƶ����Ƶ���ݴ�������û���FALSE��������ֹͣ���ݴ���
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
* @attention �ýӿ�ֻ�Ƕ���TCP��UDP����ʱ����ֹͣ���ݴ��䣬���ڶಥ����ֹͣ���ݴ��䣬�����������߳̿���������
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_ClientMediaData(IRNETHANDLE hHandle, BOOL bStart);

/**
* @brief ��ȡͼ��ߴ�
* @param[in]  hHandle   IRNET_ClientStart�ķ���ֵ
* @param[out] m_pWidth  ���صĿ��
* @param[out] m_pHeight ���صĸ߶�
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_ClientGetVideoSize(IRNETHANDLE hHandle, DWORD *m_pWidth, DWORD *m_pHeight);

/**
* @brief �����Ƿ��Ƿ���ʾͼ��
* @param[in] hHandle IRNET_ClientStart�ķ���ֵ
* @param[in] bShow   TRUE����ʾ��Ƶ�� FALSE������ʾ��Ƶ
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_ClientSetImageShow(IRNETHANDLE hHandle, BOOL bShow);

/**
* @brief ��ȡ�ͻ���״̬
* @param[in] hHandle IRNET_ClientStart�ķ���ֵ
* @return ������:\n
-1 �������ӷ�����,�м�״̬\n
-1000 ��Ч��hHandle\n
0  �ɹ�\n
1  �û�ֹͣԤ��\n
2  �������������ʧ��\n
3  �������Ͽ�\n
4  �ﶨ�˿�ʧ�ܣ����öಥ��������ʱ���������������Ķಥ�˿���ͬ������ָô���\n
5  �����ڴ�ʧ�ܣ�����ϵͳ��Դʧ�ܣ��󶨶˿�ʧ�ܵ�\n
6  ��������������ʧ��\n
-102  �û����������\n
-103  ϵͳ�û���Ա��ÿ������������û���Ϊ40\n
-105  ͨ���û���Ա����TCP��UDP��ʽÿ��ͨ������������10���û�,������������������40���û������ڶಥ��ʽ���ӣ��û�������������\n
-106  ������û��ָ����ͨ��\n
-112  û���ҵ�����������������ͨ��ת������������ʱ��û���ҵ�ָ���ķ���������\n
*/
CNET_APIIMPORT LONG  CALLINGCONVEN IRNET_ClientGetState(IRNETHANDLE hHandle);

/////////////////////////////////�ص�����///////////////////////
/**
* @brief ������ʾ�Ļص�����
* @param[in] hHandle      IRNET_ClientStart�ķ���ֵ
* @param[in] ShowCallBack �ص�����
* @param[in] context      �û�������
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
* @par �ص���������˵��:
* @code
m_y      Y������ʼ��ַ
m_u      U������ʼ��ַ
m_v      V������ʼ��ַ
stridey  ����Y�Ŀ��
strideuv ����U��V���ݵĿ��
width    ͼ�����ݵĿ��
height   ͼ�����ݵĸ߶�
context  �û������������
* @endcode
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_ClientShowcallback(IRNETHANDLE hHandle, void(WINAPI *ShowCallBack)(BYTE *m_y, BYTE *m_u, BYTE *m_v, int stridey, int strideuv, int width, int height, void *context), void *context);

/**
* @brief ������Ƶ����Ļص�����
* @param[in] hHandle          IRNET_ClientStart�ķ���ֵ
* @param[in] AudioDecCallBack �ص�����
* @param[in] context          �û�������
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
* @par �ص���������˵��:
* @code
pBuffer �������������
size    ���ݳ���
context �û������������
* @endcode
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_ClientAudioDeccallback(IRNETHANDLE hHandle, void(WINAPI *AudioDecCallBack)(char *pBuffer, int size, void *context), void *context);

/**
* @brief ���û�ͼ�ص�����
* @param[in] hHandle      IRNET_ClientStart�ķ���ֵ
* @param[in] DrawCallBack �ص�����
* @param[in] context      �û�������
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
* @par �ص���������˵��:
* @code
hdc     ͼԪ�ļ�
context �û������������
* @endcode
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_ClientDrawCallBack(IRNETHANDLE hHandle, void(WINAPI *DrawCallBack)(HDC hDC, void *context), void *context);
/**
* @brief ����ͼ����ʾ���򣨻ص���ʽ��
* @param[in] hHandle      IRNET_ClientStart�ķ���ֵ
* @param[in] DrawCallBack �ص�����
* @param[in] context      �û�������
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
* @par �ص���������˵��:
* @code
hdc     ͼԪ�ļ�
context �û������������
* @endcode
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_ClientShowImageDrawCallback(IRNETHANDLE hHandle, void(WINAPI *DrawCallBack)(HDC hDC, void *context), void *context);


///////////////////��̨/////////////////////////
/**
* @brief ������̨
* @param[in] hHandle   IRNET_ClientStart�ķ���ֵ
* @param[in] type      ��̨������
* @param[in] value     ���Ʋ���
* @param[in] priority  ��̨�������ȼ�����Ҫ�豸֧��
* @param[in] extrabuff ��Ҫ�����豸�Ķ�������
* @param[in] extrasize ��Ҫ�����豸�Ķ������ݴ�С
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_ClientPTZCtrl(IRNETHANDLE hHandle, int type, int value, int priority = 0, char *extrabuff = NULL, int extrasize = 0);

/**
* @brief ������̨��ַ
* @param[in] hHandle   IRNET_ClientStart�ķ���ֵ
* @param[in] m_ptzaddr ��̨��ַ
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_ClientSetPTZAddr(IRNETHANDLE hHandle, BYTE m_ptzaddr);

////////////////¼����������///////////////////////////
/**
* @brief ����Ԥ¼��
* @param[in] hHandle      IRNET_ClientStart�ķ���ֵ
* @param[in] m_benable    ʹ�ܱ�־
* @param[in] m_buffsize   ��������С
* @param[in] m_framecount �����֡��
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
* @attention �ڰ汾6.16D�Ժ󣬲���m_buffsize����ʹ�ã�ֻ��m_framecount��Ч���ڰ汾6.19.20�Ժ����ӳɹ����Զ���Ԥ¼��m_framecountΪ250֡,Ҫ�������ã�Ԥ¼������Ҫ��ֹͣ�����ò����������ر�Ԥ¼��¼���ļ��м���������ӵļ����
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_ClientPrerecord(IRNETHANDLE hHandle, BOOL m_benable, int m_buffsize, int m_framecount);

/**
* @brief ���ͨ������Ƶ��Ƶѹ����Ϣ
* @param[in]       hHandle       IRNET_ClientStart�ķ���ֵ
* @param[in,out]   m_pStreamInfo �ṹVSTREAMINFO��ָ��
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_ClientGetStreamInfo(IRNETHANDLE hHandle, VSTREAMINFO *m_pStreamInfo);


/**
* @brief �������ԭʼ����
* @param[in] hHandle       IRNET_ClientStart�ķ���ֵ
* @param[in] m_nomalvideo  �����Ƶ���ݵĻص�����
* @param[in] pvideocontext ��Ƶ�û�������
* @param[in] m_nomalaudio  �����Ƶ���ݵĻص�����
* @param[in] paudiocontext ��Ƶ�û�������
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
* @par �ص���������˵��:
* @code
//�����Ƶԭʼ�����ص�����
void(WINAPI *m_nomalvideo)(char *pbuff,int headsize,int datasize,int timetick,int biskeyframe,void *context);
pbuff             ����ָ��
headsize          ֡ͷ���ȣ����ܳ����У�1��sizeof(ETI_DVR_FRMAME_HEAD) + �������У�sizeof(ETI_FILE_HEAD) 2��sizeof(ETI_FRMAME_HEAD)
datasize          ���ݳ���
timetick          ʱ���,�Ժ���Ϊ��λ,��ʾÿ֡��ʱ��
biskeyframe       �ؼ�֡��־,TRUE:�ؼ�֡��FALSE�����ǹؼ�֡
context           �û�������

//�����Ƶԭʼ�����ص�����
void(WINAPI *m_nomalaudio)(char *pbuff,int headsize,int datasize,int timetick,int biskeyframe,void *context);
pbuff             ����ָ��
headsize          ֡ͷ���ȣ����ܳ����У�1��sizeof(ETI_DVR_FRMAME_HEAD) + �������У�sizeof(ETI_FILE_HEAD) 2��sizeof(ETI_FRMAME_HEAD)
datasize          ���ݳ���
timetick          ʱ���,�Ժ���Ϊ��λ,��ʾ��Ƶÿ�����ݰ���ʱ��
biskeyframe       �ò�������ΪTRUE
context           �û�������
* @endcode
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_ClientStartNomalCap(IRNETHANDLE hHandle,
	void(WINAPI *m_nomalvideo)(char *pbuff, int headsize, int datasize, int timetick, int biskeyframe, void *context), void *pvideocontext,
	void(WINAPI *m_nomalaudio)(char *pbuff, int headsize, int datasize, int timetick, int biskeyframe, void *context), void *paudiocontext);

/**
* @brief ֹͣ��ȡԭʼ����
* @param[in] hHandle IRNET_ClientStart�ķ���ֵ
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_ClientStopNomalCap(IRNETHANDLE hHandle);

/**
* @brief �����ʾ����
* @param[in] hHandle IRNET_ClientStart�ķ���ֵ
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_CleanVideoDisplayBuffer(IRNETHANDLE hHandle);


////////////////////////OPT//////////////////////
/**
* @brief ��Զ�̲�����������
* @param[in] m_sername  ����������,С�ڵ���24���ַ���
* @param[in] m_url      ��������ַ
* @param[in] m_username �û�����С�ڵ���20���ַ�
* @param[in] m_password ����,С�ڵ���20���ַ�
* @param[in] wserport   �������˿ں�
* @return -1��ʾʧ�ܣ�����ֵΪ������ȡ���
* @attention �ӿڵ��óɹ��󣬱������IRNET_ClientMessageClose�ͷ���Դ����������Դй©
*/
CNET_APIIMPORT IRNETHANDLE  CALLINGCONVEN IRNET_ClientMessageOpen(char *sername, char *url, char *username, char *password, WORD serport = 3000);

/**
* @brief ���ò���
* @param[in]       hHandle ������ȡ�����IRNET_ClientMessageOpen����ֵ
* @param[in]       opt     ����ѡ��
* @param[in]       ch      ͨ��
* @param[in,out]   param1  ��ȡ�����б�
* @param[in,out]   param2  ��ȡ�����б�
* @param[in,out]   param3  ��ȡ�����б�
* @return δ������˵���£�TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
CNET_APIIMPORT int   CALLINGCONVEN IRNET_ClientMessageOpt(IRNETHANDLE hHandle, int opt, int ch = 0, void *param1 = NULL, void *param2 = NULL, void *param3 = NULL);

/**
* @brief �ر�Զ�̲�����������
* @param[in] hHandle ������ȡ�����IRNET_ClientMessageOpen����ֵ
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_ClientMessageClose(IRNETHANDLE hHandle);


///////////�ض�Զ�̲�������///////////////////////////


/**
* @brief ��ȡ�ݴ�����
* @param[in]    m_sername  ����������,С�ڵ���24���ַ���
* @param[in]    m_url      ��������ַ
* @param[in]    m_username �û�����С�ڵ���20���ַ�
* @param[in]    m_password ���룬С�ڵ���20���ַ�
* @param[in,out] pbuff      ����ָ��
* @param[in]    wserport   �������˿�
* @return ���ڵ���0��ʾ�ɹ����������ݳ��ȣ�С��0��ʾʧ��
*/
CNET_APIIMPORT int   CALLINGCONVEN IRNET_ClientGetTempData(char *m_sername, char *m_url, char *m_username, char *m_password, char *pbuff, WORD wserport = 3000);

/////////////////��������������////////////////////////////////
/**
* @brief �������
* @param[in] m_sername  ���������ƣ�С�ڵ���24�ַ�
* @param[in] m_url      ��������ַ
* @param[in] m_username �û�����С�ڵ���20�ַ�
* @param[in] m_password ���룬С�ڵ���20�ַ�
* @param[in] wserport   �������˿�
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
* @attention ����޸��˲��������Ҫ���ñ��������Ҫ���øú�����Ĭ������������˲���δ����Ļ���������ԭ�ϴα���Ĳ���
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_ClientSaveServerPara(char *m_sername, char *m_url, char *m_username, char *m_password, WORD wserport = 3000);


/////////////�������ļ�����//////////////////


/**
* @brief ����Զ�������������̼�
* @param[in] m_url       ��������ַ
* @param[in] m_username  �û�����С�ڵ���20���ַ�
* @param[in] m_password  ���룬С�ڵ���20���ַ�
* @param[in] m_filename  �ļ���
* @param[in] m_hEndEvent ���������������¼�
* @param[in] wserport    �������˿�
* @param[in] m_sername   ����������
* @return -1��ʧ�ܣ�����ֵ��ΪIRNET_ClientUpdateStop�Ĳ���
*/
CNET_APIIMPORT /*LONG*/IRNETHANDLE  CALLINGCONVEN IRNET_ClientUpdateStart(char *m_url, char *m_username, char *m_password, char *m_filename, HANDLE m_hEndEvent, WORD wserport = 3000, char *m_sername = NULL);

/**
* @brief ����Զ�������������̼�
* @param hHandle [IN] IRNET_ClientUpdateStart�ķ���ֵ
* @return
0�������ɹ�\n
2�����ӷ�����ʧ��\n
-102��������û���������
* @attention ��Ҫ�ȵ�m_hEndEvent���ٵ���IRNET_ClientUpdateStop������IRNET_ClientUpdateStop�ķ���ֵ�ж�������״̬��
*/
CNET_APIIMPORT int   CALLINGCONVEN IRNET_ClientUpdateStop(/*LONG*/IRNETHANDLE hHandle);



/**
* @brief ��������
* @param[in] hHandle  IRNET_ClientStart�ķ���ֵ
* @param[in] m_Volume ���õ�������ֵ��ȡֵ��Χ��0x0000-0xffff:0x0000������0xffff�������
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
* @attention �������ڹ���ģʽ��ʹ�õģ���ÿ��ͨ���ڿ�������������ֹͣ���������ú���IRNET_ClientAudioVolume���Զ�������
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_ClientAudioVolume(/*LONG*/IRNETHANDLE hHandle, WORD m_Volume);



/**
* @brief ����ͼ��Ԥ������
* @param[in] hHandle ͨ�����Ӿ��
* @param[in] rect    �������򣬸���ͼ��ֱ������Ϊ(0,0,width,height)
* @param[in] bEnable ʹ�ܿ���
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_ClientSetZoomRect(/*LONG*/IRNETHANDLE hHandle, RECT *pRect, BOOL bEnable);

/**
* @brief �����豸���»�����Ϣ
* @param[in] hHandle ���Ӿ����IRNET_ClientStart�ķ���ֵ
* @param[in] devInfo �豸������Ϣ
* @param[in] DeviceMode       ʹ���豸ģʽ
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
CNET_APIIMPORT BOOL CALLINGCONVEN IRNET_ClientSetDevInfo(/*LONG*/IRNETHANDLE hHandle, DEV_ENV_INFO* devInfo, BOOL DeviceMode = FALSE);

/**
* @brief ��ȡ�豸���»�����Ϣ
* @param[in] hHandle ���Ӿ����IRNET_ClientStart�ķ���ֵ
* @param[in] devInfo �豸������Ϣ
* @param[in] DeviceMode       ʹ���豸ģʽ
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
CNET_APIIMPORT BOOL CALLINGCONVEN IRNET_ClientGetDevInfo(/*LONG*/IRNETHANDLE hHandle, DEV_ENV_INFO* devInfo, BOOL DeviceMode = FALSE);

/**
* @brief ���ò����¿���Ϣ
* @param[in] hHandle          ���Ӿ����IRNET_ClientStart�ķ���ֵ
* @param[in] tempSpan         �¿���Ϣ
* @param[in] DeviceMode       ʹ���豸ģʽ
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
CNET_APIIMPORT BOOL CALLINGCONVEN IRNET_ClientSetTempSpan(/*LONG*/IRNETHANDLE hHandle, DEV_TEMP_SPAN* tempSpan, BOOL DeviceMode = FALSE);

/**
* @brief ��ȡ�����¿���Ϣ
* @param[in]        hHandle                 ���Ӿ����IRNET_ClientStart�ķ���ֵ
* @param[in,out]    tempSpan                �¿���Ϣ
* @param[in]        DeviceMode              ʹ���豸ģʽ
* @return           TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
CNET_APIIMPORT BOOL CALLINGCONVEN IRNET_ClientGetTempSpan(/*LONG*/IRNETHANDLE hHandle, DEV_TEMP_SPAN* tempSpan, BOOL DeviceMode = FALSE);

/**
* @brief ���õ�ɫ��ģʽ
* @param[in] hHandle       ���Ӿ����IRNET_ClientStart�ķ���ֵ
* @param[in] enMode        ��ɫ��ģʽ
* @param[in] DeviceMode    ʹ���豸ģʽ
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
* @attention DeviceModeΪTRUEʱ����ʾʹ���豸�ĵ�ɫ�壬����ʹ���ڴ�ĵ�ɫ�塣�豸�ĵ�ɫ����ڴ�ĵ�ɫ��֧�ֵ�������һ��,��ʵ�ʲ������Ϊ׼
*/
CNET_APIIMPORT BOOL CALLINGCONVEN IRNET_ClientSetPaletteMode(/*LONG*/IRNETHANDLE hHandle, DEV_PALETTE_MODE enMode, BOOL DeviceMode = FALSE);

/**
* @brief ��ȡ��ɫ��ģʽ
* @param[in]        hHandle       ���Ӿ����IRNET_ClientStart�ķ���ֵ
* @param[in,out]    enMode        ��ɫ��ģʽ
* @param[in]        DeviceMode    ʹ���豸ģʽ
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
* @attention DeviceModeΪTRUEʱ����ʾʹ���豸�ĵ�ɫ�壬����ʹ���ڴ�ĵ�ɫ�塣�豸�ĵ�ɫ����ڴ�ĵ�ɫ��֧�ֵ�������һ��,��ʵ�ʲ������Ϊ׼
*/
CNET_APIIMPORT BOOL CALLINGCONVEN IRNET_ClientGetPaletteMode(/*LONG*/IRNETHANDLE hHandle, DEV_PALETTE_MODE* enMode, BOOL DeviceMode = FALSE);

/**
* @brief ע����»ص�
* @param[in]       hHandle   ���Ӿ����IRNET_ClientStart�ķ���ֵ
* @param[in]       pCallBack �ص�������ַ
* @param[in,out]   tempSpan  �¿�
* @param[in]       context   �Զ�������
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
CNET_APIIMPORT BOOL CALLINGCONVEN IRNET_ClientRegTempCallBack(/*LONG*/IRNETHANDLE hHandle, TEMPCALLBACK pCallBack, DEV_TEMP_SPAN*tempSpan, void*context);

/**
* @brief ע���ȡ����ͨ����raw���ݻص�
* @param[in] hHandle     ���Ӿ����IRNET_ClientStart�ķ���ֵ
* @param[in] pFunc       �ص�������ַ
* @param[in] context     ����
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
CNET_APIIMPORT BOOL CALLINGCONVEN IRNET_ClientRegRawCallback(/*LONG*/IRNETHANDLE hHandle, RAWCALLBACK pFunc, void* context);

/**
* @brief ��ȡ�����¶�ֵ
* @param[in] hHandle         ���Ӿ����IRNET_ClientStart�ķ���ֵ
* @param[in] tempValue       �����¶�ֵ
* @param[in] DeviceMode      ʹ���豸ģʽ
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
CNET_APIIMPORT BOOL CALLINGCONVEN IRNET_ClientGetTemperatureValue(/*LONG*/IRNETHANDLE hHandle, VSNETTEMPVALUE * tempValue, BOOL DeviceMode = FALSE);

/**
* @brief ����ͼ��ץ��
* @param[in]       hHandle       ���Ӿ����IRNET_ClientStart�ķ���ֵ
* @param[in]       type          �ļ����͡�ΪEN_FT_SDK_LCRʱ��dataAddr��ʾ�¶�����
* @param[in]       fileName      �ļ���(·��+�ļ���+�ļ���չ��)
* @param[in]       quality       ͼ������(0-100)
* @param[in,out]   dataAddr      ͼ�����ݵ�ַ(�ⲿ�����ڴ�)
* @param[in,out]   dataSize      ���ݴ�С(�ⲿ������ڴ����Ϊ:����ߡ�3Bytes,��typeΪEN_FT_SDK_LCRʱ��������ڴ��СΪ ����ͼ��Ŀ������ͼ��ĸߡ�sizeof(float) )���ɹ����޸�Ϊʵ�����ݴ�С,�����޸�Ϊ0����ζ���ⲿ�����ڴ治��
* @return ������(CaptureErrCode)
* @attention ����ͼ��ץ����Ҫ��������������,�����޷�ץ��
* @attention typeΪEN_FT_SDK_LCRʱ��dataAddr��ʾ�¶�����
*/
CNET_APIIMPORT int CALLINGCONVEN IRNET_ClientCapture(/*LONG*/IRNETHANDLE hHandle, FileType type, char fileName[], int quality = 100, char* dataAddr = NULL, unsigned int* dataSize = 0);

/**
* @brief �����豸JPEGץ�Ļش�
* @param[in] m_sername        ���������ƣ�С�ڵ���24�ַ�
* @param[in] m_url            ��������ַ
* @param[in] m_ch             ����ͨ��
* @param[in] m_username       �����û�����С�ڵ���20�ַ�
* @param[in] m_password       �������룬С�ڵ���20�ַ�
* @param[in] wserport         ���Ӷ˿�
* @param[in] jpegdatacallback �ش��ص�����
* @param[in] userdata         �û��Զ������
* @return -1 ����ʧ��\n
0 �������
* @par �ص���������˵��:
* @code
hHandle  ���Ӿ����IRNET_ClientJpegCapStart����ֵ
m_ch     ����ͨ��
pBuffer  jpegͼ�񻺳�����ΪNULL��ʾ����ʧ�ܣ��߳��˳�,��������һ��������jpgͼƬ
size     jpegͼ���С��< 0 ��ʾ����ʧ�ܣ��߳��˳�
userdata �û��Զ������
* @endcode
*/
CNET_APIIMPORT /*LONG*/IRNETHANDLE  CALLINGCONVEN IRNET_ClientJpegCapStart(char *m_sername, char *m_url, char *m_username, char *m_password, WORD wserport,
	pfJpegdataCallback jpegdatacallback/*void(WINAPI *jpegdatacallback)(/*LONGIRNETHANDLE hHandle, int m_ch, char *pBuffer, int size, void *userdata)*/, void *userdata);

/**
* @brief ����һ���豸ץͼ�ش�
* @param[in] hHandle   ���Ӿ����IRNET_ClientJpegCapStart����ֵ
* @param[in] m_ch      ����ͨ��
* @param[in] m_quality JPEGѹ������(1:���-100:���)
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_ClientJpegCapSingle(/*LONG*/IRNETHANDLE hHandle, int m_ch, int m_quality);

/**
* @brief ����һ���豸ץͼ�ش�
* @param[in] hHandle   ���Ӿ����IRNET_ClientJpegCapStart����ֵ
* @param[in] m_ch      ����ͨ��
* @param[in] m_quality JPEGѹ������(1:���-100:���)
* @param[in] type      ץ������ 0x1-�ɼ��� 0x10-����   ����ֵ��Ч
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
* @attention ĳЩ�豸��֧��type����
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_ClientJpegCapSingleEx(/*LONG*/IRNETHANDLE hHandle, int m_ch, int m_quality, int type);

/**
* @brief ֹͣ�豸JPEGץͼ�ش�
* @param[in] hHandle ���Ӿ����IRNET_ClientJpegCapStart����ֵ
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_ClientJpegCapStop(/*LONG*/IRNETHANDLE hHandle);

/**
* @brief ¼��ʼ
* @param[in] hHandle     ���Ӿ����IRNET_ClientStart�ķ���ֵ
* @param[in] filename    �ļ���(·��+�ļ���+��չ��)
* @param[in] filetype    �ļ�����
* @param[in] framerate   ֡��(һ��ɼ���ͨ����30������ͨ����9)
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
CNET_APIIMPORT BOOL CALLINGCONVEN IRNET_ClientRecordBegin(/*LONG*/IRNETHANDLE hHandle, char filename[], RecordType filetype, float framerate);

/**
* @brief ¼����ͣ
* @param[in] hHandle     ���Ӿ����IRNET_ClientStart�ķ���ֵ
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
CNET_APIIMPORT BOOL CALLINGCONVEN IRNET_ClientRecordPause(/*LONG*/IRNETHANDLE hHandle);

/**
* @brief ¼��ָ�
* @param[in] hHandle     ���Ӿ����IRNET_ClientStart�ķ���ֵ
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
CNET_APIIMPORT BOOL CALLINGCONVEN IRNET_ClientRecordResume(/*LONG*/IRNETHANDLE hHandle);

/**
* @brief ¼�����
* @param[in] hHandle     ���Ӿ����IRNET_ClientStart�ķ���ֵ
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
CNET_APIIMPORT BOOL CALLINGCONVEN IRNET_ClientRecordEnd(/*LONG*/IRNETHANDLE hHandle);

/**
* @brief �ں�ͼ��
* @param[in] hMainHandle ���Ӿ����IRNET_ClientStart�ķ���ֵ(����ͨ��)
* @param[in] hSubHandle  ���Ӿ����IRNET_ClientStart�ķ���ֵ(�ɼ���ͨ��)
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_ClientFuseStart(/*LONG*/IRNETHANDLE hMainHandle, /*LONG*/IRNETHANDLE hSubHandle);

/**
* @brief ֹͣͼ���ں�
* @param[in] hHandle ���Ӿ����IRNET_ClientStart�ķ���ֵ
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
* @attention ����hHandleֻ��Ҫ��IRNET_ClientFuseStart�е�hMainHandle��ͬһ������
*/
CNET_APIIMPORT BOOL CALLINGCONVEN IRNET_ClientFuseStop(/*LONG*/IRNETHANDLE hHandle);

/**
* @brief �����ں�ǿ��
* @param[in] hHandle    ���Ӿ����IRNET_ClientStart�ķ���ֵ
* @param[in] byStrength �ں�ǿ��0-100
* @param[in] DeviceMode ʹ���豸ģʽ
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
CNET_APIIMPORT BOOL CALLINGCONVEN IRNET_ClientSetFusionStrength(/*LONG*/IRNETHANDLE hHandle, BYTE byStrength, BOOL DeviceMode = FALSE);

/**
* @brief ��ȡ�ں�ǿ��
* @param[in] hHandle    ���Ӿ����IRNET_ClientStart�ķ���ֵ
* @param[in] DeviceMode ʹ���豸ģʽ
* @return �ں�ǿ�� <0 ʧ�� ����ɹ�
*/
CNET_APIIMPORT int CALLINGCONVEN IRNET_ClientGetFusionStrength(IRNETHANDLE hHandle, BOOL DeviceMode = FALSE);

/**
* @brief �����ں�ͼ��ɼ����ˮƽƫ��
* @param[in] hHandle ���Ӿ����IRNET_ClientStart�ķ���ֵ
* @param[in] iOffset ˮƽƫ��
* @param[in] DeviceMode ʹ���豸ģʽ
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
CNET_APIIMPORT BOOL CALLINGCONVEN IRNET_ClientSetFusionOffsetHorz(/*LONG*/IRNETHANDLE hHandle, int iOffset, BOOL DeviceMode = FALSE);

/**
* @brief ��ȡ�ں�ͼ��ɼ����ˮƽƫ��
* @param[in] hHandle ���Ӿ����IRNET_ClientStart�ķ���ֵ
* @param[in] DeviceMode ʹ���豸ģʽ
* @return ˮƽƫ��
*/
CNET_APIIMPORT int CALLINGCONVEN IRNET_ClientGetFusionOffsetHorz(/*LONG*/IRNETHANDLE hHandle, BOOL DeviceMode = FALSE);
/**
* @brief �����ں�ͼ��ɼ���Ĵ�ֱƫ��
* @param[in] hHandle ���Ӿ����IRNET_ClientStart�ķ���ֵ
* @param[in] iOffset ��ֱƫ��
* @param[in] DeviceMode ʹ���豸ģʽ
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
CNET_APIIMPORT BOOL CALLINGCONVEN IRNET_ClientSetFusionOffsetVert(/*LONG*/IRNETHANDLE hHandle, int iOffset, BOOL DeviceMode = FALSE);
/**
* @brief �����ں�ͼ��ɼ���Ĵ�ֱƫ��
* @param[in] hHandle ���Ӿ����IRNET_ClientStart�ķ���ֵ
* @param[in] DeviceMode ʹ���豸ģʽ
* @return ��ֱƫ��
*/
CNET_APIIMPORT int CALLINGCONVEN IRNET_ClientGetFusionOffsetVert(/*LONG*/IRNETHANDLE hHandle, BOOL DeviceMode = FALSE);

/**
* @brief �����ں�ͼ����ͼģʽ
* @param[in] hHandle    ���Ӿ����IRNET_ClientStart�ķ���ֵ
* @param[in] mode       ��ͼģʽ
* @param[in] DeviceMode ʹ���豸ģʽ
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_ClientSetFusionViewMode(/*LONG*/IRNETHANDLE hHandle, EnumViewMode mode, BOOL DeviceMode = FALSE);
/**
* @brief ע�����ּ��ص�
* @param[in] hHandle    ���Ӿ����IRNET_ClientStart�ķ���ֵ
* @param[in] pFuncAddr  ���ֻص�
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
* @attention �˹�����ֻ֧��Linuxƽ̨
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_ClientRegIntrDetectCallback(/*LONG*/IRNETHANDLE hHandle, INTRDETECCALLBACK pFuncAddr);

/**
* @brief ��ʼ���ּ��
* @param[in] hHandle    ���Ӿ����IRNET_ClientStart�ķ���ֵ
* @param[in] areaUpper  ���������������
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
* @attention �˹�����ֻ֧��Linuxƽ̨
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_ClientIntrDetectBegin(/*LONG*/IRNETHANDLE hHandle, int areaUpper);

/**
* @brief �������ּ��
* @param[in] hHandle    ���Ӿ����IRNET_ClientStart�ķ���ֵ
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
* @attention �˹�����ֻ֧��Linuxƽ̨
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_ClientIntrDetectEnd(/*LONG*/IRNETHANDLE hHandle);

/**
* @brief �豸У׼
* @param[in] info       �豸������Ϣ
* @param[in] type       У׼����
* @param[in] filename   �ļ���
* @param[in] memaddr    �ڴ��ַ
* @param[in] memsize    �ڴ��С
* @param[in] group      ��
* @param[in] context    �Զ�������
* @param[in] pCallback  ������ɻص�

* @return -1��ʧ�ܣ�����ֵ>0:�ɹ�
* @attention ����filenameΪNULLʱ���Ż����memaddr
*/
CNET_APIIMPORT /*LONG*/IRNETHANDLE  CALLINGCONVEN IRNET_DevCalib(DeviceBaseInfo info, DevCalibType type, char *filename, unsigned char* memaddr = NULL, unsigned int memsize = 0, short group = 0, void* context = NULL, FINISHCALLBACK pCallback = NULL);

/**
* @brief ע�������ͨ�����߼��ص�����
* @param[in] pchancheck ������ͨ�����߼��ص�����
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
* @attention �ڷ�����ͨ��ע��ص�������ֻ�ܵ���IRNET_RVSRegMsgCallback��IRNET_RVSSetChanServerID��IRNET_ClientMediaData��������
���ܵ�������SDK��������������SDK�����������������������Ҫ��������SDK��������ͨ����Ϣ�ص�������֪ͨ���ӳɹ����ٵ���
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_RVSRegSerCheckCallback(RVSCHANNELCALLBACK pchancheck);

/**
* @brief ������������������ע�����
* @param[in] m_pRvsInfo �󶨼����˿���Ϣ��ָ��ṹVSNETRVSINFO��ָ��
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
* @attention �������ʹ��ת�������豸���ߺ����ʹ��IRNET_RVSSetChanServerID�����豸��ת���������е����֡�ת��������ο�IRNET_StartListenClient
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_RVSStartServer(RVSINFOREG *m_pRvsInfo);

/**
* @brief ע�������ͨ��������Ϣ�ص�����
* @param[in] hHandle        ͨ�����
* @param[in] palarmcallback ������������Ϣ�ص�����
* @param[in] context        �ص�����������
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_RVSRegMsgCallback(/*LONG*/IRNETHANDLE hHandle, RVSALARMCALLBACK palarmcallback, void *context);

/**
* @brief ���÷�������ID����ID����ת��
* @param[in] hHandle ͨ�����
* @param[in] pSerID  ������ID����Ϊת���ķ�����Ψһ��ʶ�������ͻ�������ʱm_sername��Ϊ��ID
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
* @attention Ҫʹ�ÿͷ���ͨ��ת�����Ӹ��豸ʱ�����������ƾ���pSerID���õ�ֵ��
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_RVSSetChanServerID(/*LONG*/IRNETHANDLE hHandle, char *pSerID);

/**
* @brief ֹͣ��������������ע�����
* @param ��
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_RVSStopServer();

/**
* @brief ����ת������������
* @param[in] m_pRedirect ָ��ṹIRNET_REDIRECTORINFO��ָ��
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_SetRedirectorInfo(IRNET_REDIRECTORINFO *m_pRedirect);

/**
* @brief ����ת��������
* @param[in] m_localAddrIP ������IP��ַ�����ΪNULL��SDK���Զ���ȡ����������IP��ַ����������ж��IP��ַ������ָ��һ��IP��ַ���м���
* @return 0���ɹ� 4���ﶨ�˿ڴ��� 5�������ڴ����
* @attention IRNET_RVSStartServer �����������豸����ע�����ߣ�Ҳ������ģʽ����IRNET_ClientStartNtFile ����������ͨ��ת������������ǰ���豸���ļ�����ת������������չ��Ŀǰֻ����ģʽ�Ͳ����豸֧��
*/
CNET_APIIMPORT int   CALLINGCONVEN IRNET_StartListenClient(char *m_localAddrIP = NULL);

/**
* @brief ֹͣת��������
* @param ��
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_StopListenClient();

///////////////////͸������///////////////////////////
/**
* @brief ����͸����������
* @param[in] m_sername           ���������ƣ�С�ڵ���24���ַ�
* @param[in] m_url               ��������ַ
* @param[in] m_username          �û�����С�ڵ���20���ַ�
* @param[in] m_password          ���룬С�ڵ���20���ַ�
* @param[in] iSerialPort         ���ںţ�0��RS485��1��RS232
* @param[in] pSerialInfo         ���ڲ���
* @param[in] fSerialDataCallBack ���ڽ��ջص�����
* @param[in] context             �û�������
* @param[in] wserport            �������˿�
* @return -1������ʧ�ܣ���0��͸�����ھ��
* @par VSSERIAL_INFO�ṹ
* @code
typedef struct{
int baudrate;       //������, 50,75,110,150,300,600,1200,2400,4800,9600,19200\n
char databit;       //����λ, 5,6,7,8\n
char stopbit;       //ֹͣλ, 1,2
char checkbit;      //Ч��λ, 0-��У��,1-��У��,2-żУ��,3-�̶�Ϊ1��4-�̶�Ϊ0
char flowcontrol;   //����, 0-������,1-������,2-Ӳ����
}VSSERIAL_INFO;
* @endcode
* @par �ص���������˵��
* @code

* @endcode
*/
CNET_APIIMPORT /*LONG*/IRNETHANDLE  CALLINGCONVEN IRNET_ClientSerialStart(char *m_sername, char *m_url, char *m_username, char *m_password, int iSerialPort,
	VSSERIAL_INFO *pSerialInfo,
	pfSerialDataCallBack fSerialDataCallBack,
	void *context, WORD wserport);

/**
* @brief �ر�͸����������
* @param[in] hSerial ͸�����ھ����IRNET_ClientSerialStart����ֵ
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_ClientSerialStop(/*LONG*/IRNETHANDLE hSerial);

/**
* @brief ͨ��͸�����ڷ�������
* @param[in] hSerial   ͸�����ھ����IRNET_ClientSerialStart����ֵ
* @param[in] pSendBuff ��������ָ��
* @param[in] BuffSize  ���ݳ���
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_ClientSerialSendNew(/*LONG*/IRNETHANDLE hSerial, char *pSendBuff, DWORD BuffSize);

/**
* @brief ͸�����ڽ���������ͣ
* @param[in] hSerial ͸�����ھ����IRNET_ClientSerialStart����ֵ
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_ClientSerialRecvPause(/*LONG*/IRNETHANDLE hSerial);

/**
* @brief ͸�����ڽ����������¿�ʼ
* @param[in] hSerial ͸�����ھ����IRNET_ClientSerialStart����ֵ
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
CNET_APIIMPORT BOOL  CALLINGCONVEN IRNET_ClientSerialRecvRestart(/*LONG*/IRNETHANDLE hSerial);
/**
* @brief ������Ƶ
* @param[in] hHandle ͨ�����
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
CNET_APIIMPORT BOOL CALLINGCONVEN IRNET_ClientPlayAudio(/*LONG*/IRNETHANDLE hHandle);
/**
* @brief ֹͣ��Ƶ
* @param[in] hHandle ͨ�����
* @return TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
CNET_APIIMPORT BOOL CALLINGCONVEN IRNET_ClientStopAudio(/*LONG*/IRNETHANDLE hHandle);

/**
* @brief ����rom
* @param[in] m_sername        ���������ƣ�С�ڵ���24�ַ�
* @param[in] m_url            ��������ַ
* @param[in] m_username       �����û�����С�ڵ���20�ַ�
* @param[in] m_password       �������룬С�ڵ���20�ַ�
* @param[in] m_wserport       ���Ӷ˿�
* @param[in] m_szRomPath      rom�ļ�·��
* @return void ��
* @attention ��Ҫ�ڶ��߳���ʹ�øýӿ�
*/
CNET_APIIMPORT void CALLINGCONVEN IRNET_StartUploadRom(char *m_sername, char *m_url, char *m_username, char *m_password, WORD m_wserport, char* m_szRomPath);

/**
* @brief ��ȡrom����״̬
* @param[in] ��
* @return ״̬
2: "Ŀǰû�������¼�";
1: "��������";
0: "�����ɹ�";
-1: "��rom�ļ�ʧ��";
-2: "��ȡrom�ļ�ʧ��";
-3: "url��Ч";
-4: "����ʧ��";
-5:  "��������ʧ��";
-6: "�û����������";
-7: "�����߳�����ʧ��";
*	"��������
*/
CNET_APIIMPORT int CALLINGCONVEN IRNET_GetUploadRomRst();
/**
* @brief �������õ�wifi
* @param[in] m_sername        ���������ƣ�С�ڵ���24�ַ�
* @param[in] m_url            ��������ַ
* @param[in] m_username       �����û�����С�ڵ���20�ַ�
* @param[in] m_password       �������룬С�ڵ���20�ַ�
* @param[in] m_pWifiList      wifi�б�
* @param[in] m_wserport       ���Ӷ˿�
* @return 0-ʧ��,����ɹ�
*/
CNET_APIIMPORT BOOL CALLINGCONVEN IRNET_ClientWifiSearch(char *m_sername, char *m_url, char *m_username, char *m_password, VSNETWIFISSIDLIST *m_pWifiList, WORD wserport);

/****----------���ܷ���--------------****/
/**
* @brief ���ܷ���ʹ��
* @param[in] hHandle    ͨ�����
* @param[in] bEnalbe    ʹ�� true-���� false-����
* @return �ɹ�����ʧ��
* @retval 0-ʧ��
* @retval 1-�ɹ�
*/
CNET_APIIMPORT BOOL CALLINGCONVEN IRNET_ClientIntelligentAnalysisEnable(IRNETHANDLE hHandle, bool bEnalbe);
/**
* @brief ���������
* @param[in] hHandle    ͨ�����
* @return ��ǰ����������
* @retval >= 0 ��ǰ����
* @retval <0 ʧ��
*/
CNET_APIIMPORT int CALLINGCONVEN IRNET_ClientIntelligentAnalysisAddShield(IRNETHANDLE hHandle);
/**
* @brief ��ȡ����������
* @param[in] hHandle    ͨ�����
* @return ����
* @retval >= 0 ��ǰ����
* @retval <0 ʧ��
*/
CNET_APIIMPORT int CALLINGCONVEN IRNET_ClientIntelligentAnalysisGetShield(IRNETHANDLE hHandle);
/**
* @brief ���õ�ǰ����������������
* @param[in] hHandle    ͨ�����
* @param[in] regionIndex ��������
* @return �ɹ�����ʧ��
* @retval 0-ʧ��
* @retval 1-�ɹ�
*/
CNET_APIIMPORT BOOL CALLINGCONVEN IRNET_ClientIntelligentAnalysisSetShield(IRNETHANDLE hHandle, int regionIndex);
/**
* @brief ɾ��ָ����������
* @param[in] hHandle    ͨ�����
* @param[in] regionIndex ��������
* @return �ɹ�����ʧ��
* @retval 0-ʧ��
* @retval 1-�ɹ�
*/
CNET_APIIMPORT BOOL CALLINGCONVEN IRNET_ClientIntelligentAnalysisDeleteShield(IRNETHANDLE hHandle, int regionIndex);
/**
* @brief ������������Ϣ
* @param[in] hHandle    ͨ�����
* @return �ɹ�����ʧ��
* @retval 0-ʧ��
* @retval 1-�ɹ�
*/
CNET_APIIMPORT BOOL CALLINGCONVEN IRNET_ClientIntelligentAnalysisSaveShield(IRNETHANDLE hHandle);
/**
* @brief ����Ŀ����˳ߴ�ص�(�����Ƴߴ��ʱ�����ߴ��С)
* @param[in] hHandle            ͨ�����
* @param[in] maxSizeCallback    ���ߴ�ص�
* @param[in] maxSizeContext     ���ߴ�ص����ӵ��Զ�������
* @param[in] minSizeCallback    ��С�ߴ�ص�
* @param[in] minSizeContext     ��С�ߴ�ص����ӵ��Զ�������
* @return �ɹ�����ʧ��
* @retval 0-ʧ��
* @retval 1-�ɹ�
*/
CNET_APIIMPORT BOOL CALLINGCONVEN IRNET_ClientIntelligentAnalysisTargetFilterCallback(IRNETHANDLE hHandle, TargeFilterCallback maxSizeCallback, void* maxSizeContext, TargeFilterCallback minSizeCallback, void* minSizeContext);
/**
* @brief ������СĿ����˳ߴ�
* @param[in] hHandle        ͨ�����
* @param[in,out] curWidth   ��ǰ�ߴ�Ŀ�(�ò�����ΪNULLʱ,�������ǰ�Ŀ�)
* @param[in,out] curHeight  ��ǰ�ߴ�ĸ�(�ò�����ΪNULLʱ,�������ǰ�ĸ�)
* @return �ɹ�����ʧ��
* @retval 0-ʧ��
* @retval 1-�ɹ�
*/
CNET_APIIMPORT BOOL CALLINGCONVEN IRNET_ClientIntelligentAnalysisSetMinTargetFilter(IRNETHANDLE hHandle, int * curWidth, int*curHeight);
/**
* @brief �������Ŀ����˳ߴ�
* @param[in] hHandle        ͨ�����
* @param[in,out] curWidth   ��ǰ�ߴ�Ŀ�(�ò�����ΪNULLʱ,�������ǰ�Ŀ�)
* @param[in,out] curHeight  ��ǰ�ߴ�ĸ�(�ò�����ΪNULLʱ,�������ǰ�ĸ�)
* @return �ɹ�����ʧ��
* @retval 0-ʧ��
* @retval 1-�ɹ�
*/
CNET_APIIMPORT BOOL CALLINGCONVEN IRNET_ClientIntelligentAnalysisSetMaxTargetFilter(IRNETHANDLE hHandle, int * curWidth, int*curHeight);
/**
* @brief ����Ŀ����˳ߴ�
* @param[in] hHandle    ͨ�����
* @return �ɹ�����ʧ��
* @retval 0-ʧ��
* @retval 1-�ɹ�
* @attention ���ߴ���������С�ߴ���������ܱ���
*/
CNET_APIIMPORT BOOL CALLINGCONVEN IRNET_ClientIntelligentAnalysisSaveTargetFilter(IRNETHANDLE hHandle);
/**
* @brief ��Ӿ�����
* @param[in] hHandle    ͨ�����
* @param[in] arrowDir ��ͷ���� 0-�� 1-�� 2-˫��(����)
* @return ��ǰ�����ľ���������
* @retval >= 0 ��ǰ����
* @retval <0 ʧ��
*/
CNET_APIIMPORT int CALLINGCONVEN IRNET_ClientIntelligentAnalysisAddCordon(IRNETHANDLE hHandle, int arrowDir);
/**
* @brief ��ȡ����������
* @param[in] hHandle        ͨ�����
* @return ��ǰ����������
* @retval >= 0 ����
* @retval <0 ʧ��
*/
CNET_APIIMPORT int CALLINGCONVEN IRNET_ClientIntelligentAnalysisGetCordon(IRNETHANDLE hHandle);
/**
* @brief ���õ�ǰ����������
* @param[in] hHandle        ͨ�����
* @param[in] regionIndex    ����
* @return �ɹ�����ʧ��
* @retval 0-ʧ��
* @retval 1-�ɹ�
*/
CNET_APIIMPORT BOOL CALLINGCONVEN IRNET_ClientIntelligentAnalysisSetCordon(IRNETHANDLE hHandle, int regionIndex);
/**
* @brief ���û��ȡ��ǰ�����߼�ⷽ��
* @param[in]     hHandle        ͨ�����
* @param[in]     isSet          ����   1-���� 0-��ȡ
* @param[in,out] cordonDirc     ��ǰ�����ߵķ��� 0-��� 1-�Ҳ� 2-����\n
��isSet=1ʱ *cordonDircΪ������� ��0=isSetʱ cordonDirc�ɵ����߷����ڴ�
* @return �ɹ�����ʧ��
* @retval 0-ʧ��
* @retval 1-�ɹ�
*/
CNET_APIIMPORT BOOL CALLINGCONVEN IRNET_ClientIntelligentAnalysisCordonDirc(IRNETHANDLE hHandle, BOOL isSet, int* cordonDirc);
/**
* @brief ɾ��ָ���ľ�����
* @param[in] hHandle        ͨ�����
* @param[in] regionIndex    ����
* @return �ɹ�����ʧ��
* @retval 0-ʧ��
* @retval 1-�ɹ�
*/
CNET_APIIMPORT BOOL CALLINGCONVEN IRNET_ClientIntelligentAnalysisDeleteCordon(IRNETHANDLE hHandle, int regionIndex);
/**
* @brief ���澯������Ϣ
* @param[in] hHandle    ͨ�����
* @return �ɹ�����ʧ��
* @retval 0-ʧ��
* @retval 1-�ɹ�
*/
CNET_APIIMPORT BOOL CALLINGCONVEN IRNET_ClientIntelligentAnalysisSaveCordon(IRNETHANDLE hHandle);
/**
* @brief ������ܷ���(���޽��������뿪������Ʒ��������Ʒ��Ǩ)
* @param[in] hHandle    ͨ�����
* @param[in] smartType  ����,��Χ[EN_IAT_REGION_ENTRY,EN_IAT_GOODS_MOVE]
* @return ��ǰ���������ܷ�������
* @retval >= 0 ��ǰ����
* @retval <0 ʧ��
*/
CNET_APIIMPORT int CALLINGCONVEN IRNET_ClientIntelligentAnalysisAddSmart(IRNETHANDLE hHandle, int smartType);
/**
* @brief ��ȡ������ܷ�������(���޽��������뿪������Ʒ��������Ʒ��Ǩ)
* @param[in] hHandle    ͨ�����
* @param[in] smartType  ����,��Χ[EN_IAT_REGION_ENTRY,EN_IAT_GOODS_MOVE]
* @return ���ܷ�������
* @retval >= 0 ����
* @retval <0 ʧ��
*/
CNET_APIIMPORT int CALLINGCONVEN IRNET_ClientIntelligentAnalysisGetSmart(IRNETHANDLE hHandle, int smartType);
/**
* @brief ���õ�ǰ���ܷ�������
* @param[in] hHandle        ͨ�����
* @param[in] regionIndex    ����
* @param[in] smartType      ����,��Χ[EN_IAT_REGION_ENTRY,EN_IAT_GOODS_MOVE]
* @return �ɹ�����ʧ��
* @retval 0-ʧ��
* @retval 1-�ɹ�
*/
CNET_APIIMPORT BOOL CALLINGCONVEN IRNET_ClientIntelligentAnalysisSetSmart(IRNETHANDLE hHandle, int regionIndex, int smartType);
/**
* @brief ɾ����ǰ���ܷ���
* @param[in] hHandle        ͨ�����
* @param[in] regionIndex    ����
* @param[in] smartType      ����,��Χ[EN_IAT_REGION_ENTRY,EN_IAT_GOODS_MOVE]
* @return �ɹ�����ʧ��
* @retval 0-ʧ��
* @retval 1-�ɹ�
*/
CNET_APIIMPORT BOOL CALLINGCONVEN IRNET_ClientIntelligentAnalysisDeleteSmart(IRNETHANDLE hHandle, int regionIndex, int smartType);
/**
* @brief �������ܷ���
* @param[in] hHandle    ͨ�����
* @param[in] smartType  ����,��Χ[EN_IAT_REGION_ENTRY,EN_IAT_GOODS_MOVE]
* @return �ɹ�����ʧ��
* @retval 0-ʧ��
* @retval 1-�ɹ�
*/
CNET_APIIMPORT BOOL CALLINGCONVEN IRNET_ClientIntelligentAnalysisSaveSmart(IRNETHANDLE hHandle, int smartType);
/****----------���ܷ���--------------****/

/**
* @brief ���Ʊ�������豸
* @param[in] hHandle    ͨ�����
* @param[in] devCH      ���ͨ��
* @param[in] bOn        1-��,0-�ر�
* @return �ɹ�����ʧ��
* @retval 0-ʧ��
* @retval 1-�ɹ�
*/
CNET_APIIMPORT BOOL CALLINGCONVEN IRNET_ClientOutPut(IRNETHANDLE hHandle, char devCH, BOOL bOn);

#endif//__IRNET_H__
