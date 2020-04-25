/*
@file YoseenTypes.h
@author yoseen
@date 2018-04-01
*/
#ifndef YOSEENTYPES_H_
#define YOSEENTYPES_H_

#include "YoseenBasicTypes.h"

/*
�豸������Ϣ
*/
enum TransformType {
	TransformType_None = 0,
	TransformType_Rotate90,
	TransformType_Rotate180,
	TransformType_Rotate270,

	//
	TransformType_MirrorX,
	TransformType_MirrorY,
};

typedef struct _CameraBasicInfo {
	char CameraId[32];				///< ���к�
	char CameraName[32];			///< ����
	char CameraType[16];			///< ����

	char FPAId[32];					///< ̽�������к�

	char HardwareId[32];			///< Ӳ���汾
	char SoftwareId[32];			///< ����汾

	u16 DataWidth;			///< ���ݿ��
	u16 DataHeight;			///< ���ݸ߶�

	/**����֡��
	�����¶�����֡��=DataFps/(DataRatio*SendRatio)
	������Ƶ����֡��=DataFps/DataRatio
	ģ����Ƶ֡��=DataFps/DataRatio
	*/
	u16 DataFps;

	u16 DataRatio;			///< ������, �豸ÿ������֡ȡһ֡����
	u16 SendRatio;			///< ������, �豸ÿ������֡��һ֡����

	u8 DataTransform;		///< ���ݱ任����
	u8 pad[25];

	/*
	Ϊ��֤��Ƶ�ϻ��Ƶ����֡����¶��󡢵�ɫ������,
	�¶����ݷֱ��ʵ���640x480��ͼ��Ŵ�640x480, ���ڴ˻����ϻ���, H264����, JPEG����.
	*/
	u16 VideoWidth;			///< ��Ƶ������
	u16 VideoHeight;		///< ��Ƶ����߶�
}CameraBasicInfo;

/**
�豸������Ϣ
*/
typedef struct _CameraNetworkInfo {
	bool UseStaticIp;				///< �Ƿ�ʹ�þ�̬IP
	u8 pad;
	u16 MulticastPort;				///< �鲥�˿�, δʹ��

	u32 StaticIp;					///< ��̬IP
	u32 SubnetMask;					///< ��������
	u32 Gateway;					///< ����

	u32 MulticastIp;				///< �鲥IP, δʹ��

	u8 MacAddr[6];					///< MAC��ַ

	u8 pad2[2];
	u32 Dns;						///< ��DNS
	u32 Dns2;						///< ��DNS
	u8 reserved[16];
}CameraNetworkInfo;

/**
̽������Ϣ
*/
typedef struct _FPAInfo {
	xxxfpavol4 vol4;
	u16 tint;
	u8  cint;
	u8 pad;
}FPAInfo;

typedef struct _FPAInfoHK160 {
	u8		data[80];	//40used

	u8		res64;	//res64
	u8		cint;
	u16		tint;
	u16		vtemp;	//140
	u8		bias;	//0-7v, 1-5v
	u8		pad[41];
}FPAInfoHK160;

/**
����У����Ϣ
*/
typedef struct _FFCInfo {
	u8 frames_skipped_after_close;			///< ����رպ����֡��
	u8 frames_accumlated_when_closed;		///< ����رպ��ۻ�֡��
	u8 frames_skipped_after_open;			///< ����򿪺����֡��
	u8 nst_enable;							///< �޵�Ƭģʽ����
	u16 time_interval;						///< ʱ�䴥�����, ��λ֡��
	u16 temp_interval;						///< �¶ȴ������, ��λmK

	s8 af_rebound;							///< �Զ��Խ��ص�, ��λ֡��
	u8 fpa_shutter;							///< �е�Ƭ1/(1C/60s), �ڲ�����
	s16 nst_delta;							///< �޵�ƬģʽƯ��
	u8 reserved[4];
}FFCInfo;

/**
����������Ϣ
*/
typedef struct _FixInfo {
	float AtmosphericTemperature;		///< ����
	float RelativeHumidity;				///< ���ʪ��
	float Visibility;					///< �ܼ���
	float RainfallIntensity;			///< ����ǿ��
	float SnowfallIntensity;			///< ��ѩǿ��
	float TargetDistance;				///< Ŀ�����

	float GlobalEmissivity;				///< ȫ�ַ�����
	float InfraredWindowTrans;			///< ���ⴰ��͸����
	float TempOffset;					///< �¶�Ư��

	bool EnableAtmFix;					///< �Ƿ񿪴�������
	u8 reserved[35];
}FixInfo;

/**
���¶�����Ϣ
*/
typedef struct _MeasureInfo {
	s32					MOC;		///< ���¶�������
	xxxmeasure_object	MOS[8];		///< ���¶�������
}MeasureInfo;

/**
ģ����Ƶ��Ϣ
*/
enum XuiDisplayFlags {
	XDF_Palette = 0x0001,				///< ��ʾ��ɫ��
	XDF_TrackHigh = 0x0002,				///< ��ʾ����׷��
	XDF_TrackLow = 0x0004,				///< ��ʾ����׷��

	XDF_NoGlobalMax = 0x0008,			///< ����ʾȫ�������
	XDF_NoGlobalMin = 0x0010,			///< ����ʾȫ�������
	XDF_NoLocalMeasures = 0x0020,		///< ����ʾ�ֲ����¶���
};

typedef struct _TvoutInfo {
	bool				EnableTvout;		///< �Ƿ���ģ����Ƶ
	u8					PaletteType;		///< ��ɫ������
	u8					pad;
	u8					Contrast;			///< �Աȶ�
	u8					Brightness;			///< ����
	u8					Zoom;				///< ���ֱ佹
	u16					XuiDisplayFlags;	///< ��ʾ��־λ, �μ�XuiDisplayFlags

	float				Gain;				///< ����
	u32					H264_Bitrate;		///< ��ý�������
	u16					H264_GopSize;		///< ��ý��ͼ�����С

	//add20180809
	u8					StrechType;			///< �㷨����
	u8					DDELevel;			///< DDE�ȼ�
	s16					LinearTemp[2];		///< �����¶�, 0.1C
	u8					LinearGray[2];		///< ���ԻҶ�
	u8					HDMIPreset;

	/*
	add20191204
	����:	�¶ȸ���ct_temp0, ��ct_color0
	���£�	�¶ȵ���ct_temp0, ��ct_color0
	�����ڣ� �¶Ƚ���[ct_temp0,ct_temp1], ��ct_color0
	������:	�¶ȵ���ct_temp0, ��ct_color0; �¶ȸ���ct_temp1,��ct_color1
	*/
	u8 CT_Type;								///< �¶ȱ������
	s16 CT_Temp0;							///< ����¶�0, ��λ0.1C
	s16 CT_Temp1;							///< ����¶�1, ��λ0.1C
	s32 CT_Color0;							///< �����ɫ0
	s32 CT_Color1;							///< �����ɫ1
}TvoutInfo;

/**
������Ϣ
*/
typedef struct _SerialPortInfo {
	u8 Usage;					///< �÷�
	u8 PortAddr;				///< ���ڵ�ַ
	u8 BaudRate;				///< ������
	u8 DataBits;				///< ����λ
	u8 StopBits;				///< ֹͣλ
	u8 Parity;					///< У��λ
	u8 reserved[10];
}SerialPortInfo;

/**
GPIO��Ϣ
*/
typedef struct _GpioInfo {
	u8 Input0;		///< ����0
	u8 Input1;		///< ����1
	u8 Output0;		///< ���0
	u8 Output1;		///< ���0
	u8 reserved[12];
}GpioInfo;

/**
�豸ʱ����Ϣ
*/
typedef struct _CameraTimeInfo {
	char	NtpServer[32];			///< ��NTP������
	char	NtpServer2[32];			///< ��NTP������
	char	TimeZone[32];			///< ʱ��
	u8		reserved[32];
}CameraTimeInfo;

/*
�豸��֤��Ϣ
*/
typedef struct _AuthInfo {
	char	AccessKey[16];
	char	RtspUsername[16];
	char	RtspPassword[16];
	u8		reserved[16];
}AuthInfo;


/*
�豸OSD��Ϣ
*/
typedef struct _CameraOSDInfo {
	u16 X1;				///< ����X1
	u16 Y1;				///< ����Y1
	char Text1[64];		///< �ı�1, utf-8����

	u16 X2;				///< ����X2
	u16 Y2;				///< ����Y2
	char Text2[64];		///< �ı�2

	u16 X3;				///< ����X3
	u16 Y3;				///< ����Y3
	char Text3[64];		///< �ı�3

	u16 X4;				///< ����X4
	u16 Y4;				///< ����Y4
	char Text4[64];		///< �ı�4
}CameraOSDInfo;

/*
˫���ϲ���
*/
typedef struct _CameraOutputInfo {
	//mix
	u8 MixMode;					///< ���ģʽ
	u8 MixRatio;				///< ��ϱ���, ȡֵ��Χ[1,8]
	u16 CropX;					///< �ɼ���ü�X
	u16 CropY;					///< �ɼ���ü�Y
	u16 CropWidth;				///< �ɼ���ü����
	u16 CropHeight;				///< �ɼ���ü��߶�

	//
	u8					StrechType;				///< �����㷨����
	u8					DDELevel;				///< ����DDE�ȼ�, ȡֵ��Χ[0,8], 0����ر�
	float				Gain;					///< ����ͼ������
	s16					LinearTemp[2];			///< �������Էֶ��¶�, ��λ: 0.1��
	u8					LinearGray[2];			///< �������ԷֶλҶ�
	u8					PaletteType;			///< �����ɫ��
	u8					Contrast;				///< ����Աȶ�, Ĭ��50
	u8					Brightness;				///< ��������, Ĭ��50

	//
	u8					EnableHdmi;				///< �Ƿ���ģ����Ƶ
	u16					H264_GopSize;			///< ��ý��ͼ�����С
	u32					H264_Bitrate;			///< ��ý������, ��λ: bps

	//
	u8					FlipIR;					///< ���ⷭת
	u8					FlipVIS;				///< �ɼ��ⷭת
	u16					XStartVIS;				///< �ɼ����ӳ�X, �ڲ�����
	u16					YStartVIS;				///< �ɼ����ӳ�Y, �ڲ�����
	u8					reserved[10];
}CameraOutputInfo;

/*
���ģʽ
*/
enum MixMode {
	MixMode_IR = 0,		///< ������
	MixMode_VIS,		///< ���ɼ�
	MixMode_DSX,		///< ˫����
	MixMode_BLEND,		///< alpha���
	MixMode_PIP,		///< ���л�
	MixMode_FUSION,		///< 

	//
	MixMode_MAX,
};

/*
��ת����
*/
enum MixFlip {
	MixFlip_NN = 0,		///< �޷�ת
	MixFlip_XN,			///< X��ת
	MixFlip_NY,			///< Y��ת
	MixFlip_XY,			///< XY��ת
};

/*
�¶�֡ͷ
*/
typedef struct _DataFrameHeader {
	u16 Width;						///< ���
	u16 Height;						///< �߶�
	u32 ComSize;					///< ѹ����С
	u8 DataType;					///< ��������
	u8 ComType;						///< ѹ������
	u16 Index;						///< ֡����

	/**
	ȫ֡�¶���16λ�з������������ʾ, �¶ȸ���ֵ=�¶�����ֵ/Slope+Offset
	*/
	u16 Slope;
	s16 Offset;

	s32 FPATemp;					///< ̽�����¶�, �ڲ�ʹ��
	s32 ShellTemp;					///< ��Ч�����¶�, �ڲ�ʹ��

	u8 pad;
	u8 GpioInput0;					///< GPIO����0
	u8 GpioInput1;					///< GPIO����1
	u8 pad2[5];
	s64 Timestamp;					///< ʱ���, ��λ100ns
	u8 reserved[88];
}DataFrameHeader;
#define DATA_FRAME_HEADER_SIZE					128
#define DataFrameHeader_Offset_Timestamp				32


/**
YP
*/
#define YPCMD_DiscPort					55501
#define YPCMD_Port						55502
#define YPDATA_Port						55503

#define YPCMD_DiscMulticastPort			55504
#define YPCMD_DiscMulticastAddr			"239.255.255.251"

#define YPDATATM_Port					55505
#define YPDATAVM_Port					55506
#define YPDATAXM_Port					55507

#define YPCMD_DiscClientPort			55511

/**
��������
*/
enum CtlType {
	CtlType_Debug = 0,				///< 
	CtlType_ChangeDataType,			///< 
	CtlType_MoveShutter,			///< 
	CtlType_StoreFactory,			///< 
	CtlType_RestartCamera,			///< �����豸


	CtlType_ManualFFC = 32,			///< �ֶ�����У��
	CtlType_RestoreFactory,			///< �ָ���������
	CtlType_FocusManual,			///< �ֶ��Խ�, ����ģʽ���Ƶ綯��ͷ���
	CtlType_FocusAuto,				///< �Զ��Խ�
	CtlType_SetAlarm,				///< ����GPIO����
	CtlType_DisableFFC,				///< ���õ���У��
	CtlType_FocusManual2,			///< �ֶ��Խ�, ��ͣģʽ���Ƶ綯��ͷ���
};

/**
����
*/
typedef struct _Ctl {
	u16 Type;					///< ����
	union {
		u8 reserved[8];				///< �������С
		u8 DataType;				///< �¶���������
		u8 ShutterState;			///< 0���忪, 1�����
		s16 FocusDelta;				///< ����ģʽ, �綯��ͷ���ת��ʱ��, ��λ5ms, ����-Զ��, ����-����
		xxxfocusrect FocusRect;		///< �Զ��Խ�����
		u8	FocusType;				///< ��ͣģʽ, �綯��ͷ���ת����ʽ, 0 ֹͣ, 1 Զ��ת��, 2 ����ת��
		xxxgpioalarm Alarm;			///< GPIO����
		u8 DisableFFC;				///< 1����, 0����
	}Data;
}Ctl;

/**
����X����
*/
enum CtlXType {
	CtlXType_GetTime = 0,	///< ��ȡ�豸ʱ��, UTC
	CtlXType_SetTime,		///< �����豸��ʱ��, UTC
	CtlXType_GetGear,		///< ��ȡ���µ�λ
	CtlXType_SetGear,		///< ���ò��µ�λ
	CtlXType_AutoFocus,		///< �Զ��Խ�

	//add20180921
	CtlXType_XfGetConfig,	///< λ�ü���綯��ͷ, ��ȡ����
	CtlXType_XfSetConfig,	///< λ�ü���綯��ͷ, ��������,
	CtlXType_XfGetCur,		///< λ�ü���綯��ͷ, ��ȡλ��
	CtlXType_XfMove,		///< λ�ü���綯��ͷ, ����λ��
	//CtlXType_XfReset,
	//CtlXType_XfCheckDelta,

	//
	CtlXType_SetGpioOutput = 128,
};

/*
GPIO�����־
*/
enum xxxgpiooutputflags {
	xxxgpiooutputflags_light = (1 << 0),
	xxxgpiooutputflags_ledy = (1 << 1),
	xxxgpiooutputflags_ledb = (1 << 2),
	xxxgpiooutputflags_alarm = (1 << 3),
	xxxgpiooutputflags_buzz = (1 << 4),
};

/*
GPIO���
*/
typedef struct _xxxgpiooutput {
	s32 flags;
	s32 value;
}xxxgpiooutput;

/**
���Ʋ���
*/
typedef struct _CtlX {
	s32 Type;						///< ����
	union {
		u8				Reserved[64];
		s32				Error;			///< ������
		xxxdatetime		Time;			///< �豸ʱ��
		s32				GearLevel;		///< ���µ�λ
		xxxfocusrect	FocusRect;		///< �Զ��Խ�����
		xf_config	XfConfig;			///< λ�ü���綯��ͷ, ����
		s32			XfMove;				///< λ�ü���綯��ͷ, λ��-�̶�ֵ, [0-100]
		s32			XfCurType;			///< λ�ü���綯��ͷ, 0-����ֵ, 1-�̶�ֵ
		xxxgpiooutput	GpioOutput;
	}Data;
}CtlX;

/**
������������Ӧ2
*/
typedef struct _DiscoverCameraResp2 {
	CameraBasicInfo BasicInfo;				///< ������Ϣ
	u32 CameraIp;							///< �豸IP
	struct _DiscoverCameraResp2* pNext;		///< ��һ����Ӧ
}DiscoverCameraResp2;


/*
������Ϣ
*/
typedef struct _YoseenLoginInfo {
	char CameraAddr[128];			///< �豸��ַ
	char Username[32];				///< �û���
	char Password[32];				///< ����
}YoseenLoginInfo;

/*
H264��ʼ֡
*/
typedef struct _H264FrameStart {
	u32 EncDataSize;				///< ���������ݴ�С
	u16 DataWidth;						///< ���ݿ��
	u16 DataHeight;						///< ���ݸ߶�
	u8 EncData[120];				///< ����������

	u16 FpsNum;						///< ֡�ʷ���
	u16 FpsDen;						///< ֡�ʷ�ĸ
	u16 VideoWidth;
	u16 VideoHeight;
	u8 Reserved[120];
}H264FrameStart;
#define H264FrameStart_Size				256

/*
H264֡���½��
*/
typedef struct _H264_MeasureResult {
	s8	Index;				//���; 0:ȫ�ֲ��½��; 1:���Ĳ��½��; [2-9]:�ֲ����½��; x��Ч���½��
	s8	Pad[3];				//

	float Max;				//�����
	float Min;				//�����
	float Avg;				//ƽ����

	u16 MaxX;				//����µ�����X
	u16 MaxY;				//����µ�����Y
	u16 MinX;				//����µ�����X
	u16 MinY;				//����µ�����Y
}H264_MeasureResult;

/*
H264֡ͷ, ��Ƶ�����ݵ�֡֡ͷ
*/
typedef struct _H264FrameHeader {
	s32 Size;						//֡��С
	u16 Width;						//���ݿ��
	u16 Height;						//���ݸ߶�

	float FPATemp;					//̽�����¶�

	H264_MeasureResult	GlobalResult;			//ȫ�ֲ��½��
	H264_MeasureResult	CenterResult;			//���Ĳ��½��
	H264_MeasureResult LocalResults[8];			//�ֲ����½��

	u8 Reserved[772];
}H264FrameHeader;
#define H264FrameHeader_Size			1024

/*
H264֡ͷV2, ��������ݵ�֡֡ͷ
*/
typedef struct _H264FrameHeaderV2 {
	s32 Size;						//֡��С
	u16 Width;						//���ݿ��
	u16 Height;						//���ݸ߶�

	s32 ShellTemp;					//�豸�����¶�

	s32 LocalResultFlags;				//�ֲ����½����־
	xxxresult GlobalResult;				//ȫ�ֲ��½��
	xxxresult LocalResultArray[16];		//�ֲ����½��

	u8 Reserved[668];
}H264FrameHeaderV2;

/*
����֡
*/
typedef struct _DataFrame {
	void* Head;					///< �¶�����֡ͷ
	void* Temp;					///< �¶�����
	void* Com;					///< �¶�����ѹ��
	void* Bmp;					///< λͼ����
	void* H264;					///< H264֡ͷ
	struct _DataFrame* Prev;	///< ǰһ֡
}DataFrame;

/*
Ԥ���ص�
@param errorCode ������
@param dataFrame ����֡
@param customData �û�����
*/
typedef void(__stdcall* YoseenPreviewCallback)(s32 errorCode, DataFrame* dataFrame, void* customData);

/*
Ԥ����Ϣ
*/
typedef struct _YoseenPreviewInfo {
	s32 DataType;											///< xxxdatatype_video ��Ƶ��, xxxdatatype_temp �¶���
	void* Hwnd;												///< ��ʾ���ھ��, ����Ϊ��
	YoseenPreviewCallback CustomCallback;					///< Ԥ���ص�, ����Ϊ��
	void* CustomData;										///< �û�����

	/*
	�û���������, Ԥ���ɹ���, �û��ݴ˵�����ʾ���ڿ�߱�
	*/
	u16 OutputWidth;							///< ��ʾ������
	u16 OutputHeight;							///< ��ʾ����߶�
}YoseenPreviewInfo;

/*
*/
typedef struct _YoseenRtspInfo {
	char Url[256];

	u16 CropX;
	u16 CropY;
	u16 CropWidth;
	u16 CropHeight;

	//
	u16 DataWidth;
	u16 DataHeight;
}YoseenRtspInfo;

#endif