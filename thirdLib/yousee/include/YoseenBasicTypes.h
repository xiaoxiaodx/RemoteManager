/*
@file YoseenBasicTypes.h
@author yoseen
@date 2018-04-01
*/
#ifndef YOSEENBASICTYPES_H_
#define YOSEENBASICTYPES_H_

/**
��������
*/
typedef signed char s8;
typedef unsigned char u8;

typedef signed short s16;
typedef unsigned short u16;

typedef signed int s32;
typedef unsigned int u32;

typedef signed long long s64;
typedef unsigned long long u64;

#define S8_MIN			(-128)
#define S8_MAX			127
#define S16_MIN			(-32768)
#define S16_MAX			32767
#define S16_RANGE		(65536)
#define U16_MAX			(65535)
#define U16_RANGE		(65536)

#define S32_MIN			(-2147483647 - 1)
#define U32_MAX			0xffffffff

typedef struct _bgra {
	u8 b;
	u8 g;
	u8 r;
	u8 a;
}bgra;

/**
*/
#ifdef SDK_EXPORT
#define SDK_API __declspec(dllexport)
#else
#define SDK_API __declspec(dllimport)
#endif

#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_SIZE(x)						(sizeof(x)/sizeof(x[0]))
#define MIN(a,b)				((a)<(b)?(a):(b))
#define MAX(a,b)				((a)>(b)?(a):(b))
#define ABS(a)					((a)>0?(a):-(a))

#define XMALLOC(size,alignment)	_aligned_malloc(size,alignment)
#define XFREE(x)				_aligned_free(x)
#define xmalloc(size,alignment)	_aligned_malloc(size,alignment)
#define xfree(x)				_aligned_free(x)

//
#ifdef __linux__
#define SOCKET				int
#define INVALID_SOCKET		(-1)
#define HWND				(void*)
#define __stdcall
#endif

/*
������
*/
enum YoseenErrorType {
	YET_None = 0,					///< ����
	YET_Undefined = -1,				///< δ����
	YET_NotImplemented = -2,			///< δʵ��
	YET_NotSupported = -3,			///< ��֧��
	YET_InvalidState = -4,			///< ��Ч״̬
	YET_InvalidArgs = -5,			///< ��Ч����

	//
	YET_SDKUninited = -10,			///< δ��ʼ��
	YET_InvalidHandle = -11,			///< ��Ч���
	YET_NoMemory = -12,			///< ���ڴ����
	YET_NoHandle = -13,			///< �޾������

	YET_PreviewOpenBuffer = -14,		///< Ԥ���򿪻�����ʧ��
	YET_PreviewOpenInput = -15,		///< Ԥ��������ʧ��
	YET_PreviewOpenDisplay = -16,		///< Ԥ������ʾʧ��
	YET_PreviewRecoverBegin = -17,		///< Ԥ���Զ��ָ���ʼ
	YET_PreviewRecoverEnd = -18,			///< Ԥ���Զ��ָ�����

	//
	YET_SocketOpen = -100,					///< Socket��ʧ��
	YET_SocketConn = -101,					///< Socket����ʧ��
	YET_SocketSend = -102,					///< Socket����ʧ��				
	YET_SocketRecv = -103,					///< Socket����ʧ��
	YET_SocketData = -104,					///< Socket�����д�

	//
	YET_FileOpen = -201,						///< �ļ���ʧ��
	YET_FileWrite = -202,					///< �ļ�дʧ��
	YET_FileRead = -203,						///< �ļ���ʧ��
	YET_FileType = -204,						///< �ļ���������
	YET_FileData = -205,						///< �ļ���������

	//
	YET_FfmpegDecode = -301,				///< ffmpeg����ʧ��
	YET_FfmpegMuxOpen = -302,			///< ffmpeg muxer��ʧ��
	YET_FfmpegMuxWrite = -303,			///< ffmpeg muxerд��ʧ��
	YET_FfmpegMuxClose = -304,			///< ffmpeg muxer�ر�ʧ��
};

/*
��������
*/
enum xxxdatatype {
	xxxdatatype_vol = 0,		///< 
	xxxdatatype_voldelta = 1,		///< 
	xxxdatatype_temp = 2,		///< �¶���
	xxxdatatype_video = 3,		///< ��Ƶ��
	xxxdatatype_rtsp = 4,		///< ��Ƶ��rtsp
	xxxdatatype_mix = 5,		///< �����
};

/*
�����ļ�����
*/
enum xxxmediafile {
	xxxmediafile_bmpx = 0,			///< ��֡�¶��ļ�, bmp��չ
	xxxmediafile_pngx,				///< ��֡�¶��ļ�, png��չ
	xxxmediafile_stream,			///< ��֡�¶��ļ�
	xxxmediafile_mp4,				///< mp4�ļ�
	xxxmediafile_jpgx,				///< ��֡�¶��ļ�, jpg��չ
};

/**
�豸�ļ�����
*/
enum xxxcamerafile {
	xxxcamerafile_bin = 0,			///< �豸�����
	xxxcamerafile_cali,				///< У׼��
	xxxcamerafile_com,				///< 
	xxxcamerafile_log,				///< ��־

	xxxcamerafile_cali2,			///< У׼��2
	xxxcamerafile_cali3,			///< У׼��3

	xxxcamerafile_bad,				///< �����

	xxxcamerafile_c2m,				///< ���ζ��У׼
	xxxcamerafile_c2m2,				///< ���ζ��У׼2
};

enum xxxcameramem {
	xxxcameramem_measure = 0,
};

/**
��ɫ������
*/
enum xxxpalette {
	xxxpalette_Autumn = 0,
	xxxpalette_BlackHot,
	xxxpalette_GlowBow,
	xxxpalette_HighContrast,
	xxxpalette_HotMetal,
	xxxpalette_IronBow,
	xxxpalette_Jet,
	xxxpalette_RainBow,
	xxxpalette_RedSaturation,
	xxxpalette_WhiteHot,
	xxxpalette_Winter,
	xxxpalette_IronBow2,
};

/**
�����ɫ��
*/
typedef struct _xxxpalettedata {
	char name[32];				///< ����
	bgra data[256];				///< ����
}xxxpalettedata;

/**
���������Ƿ�ʽ
*/
enum xxxdiscoverflags {
	xxxdiscoverflags_broadcast = 0x0001,		///< �㲥
	xxxdiscoverflags_multicast = 0x0002,		///< �鲥
	xxxdiscoverflags_broadcast2 = 0x0004,	///< �㲥2
};

/**
*/
typedef struct _xxxfpavol4 {
	u16 gsk;
	u16 gfid;
	u16 vsk;
	u16 vbus;
}xxxfpavol4;

typedef struct _xxxfpavol4f {
	float gsk;
	float gfid;
	float vsk;
	float vbus;
}xxxfpavol4f;

enum xxxfpacint {
	xxxfpacint_0 = 0,
	xxxfpacint_1,
	xxxfpacint_2,
	xxxfpacint_3,
	xxxfpacint_4,
	xxxfpacint_5,
	xxxfpacint_6,
	xxxfpacint_7,
};

/**
���½��
*/
typedef struct _xxxmeasure_result {
	float amin;			///< ��Сֵ
	float amax;			///< ���ֵ
	float aavg;			///< ƽ��ֵ
	s16 min;			///< ��Сֵ, ����
	s16 max;			///< ���ֵ, ����
	s16 avg;			///< ƽ��ֵ, ����

	u16 max_x;			///< ���ֵ����x
	u16 max_y;			///< ���ֵ����y

	u16 min_x;			///< ��Сֵ����x
	u16 min_y;			///< ��Сֵ����y
}xxxmeasure_result;

/**
��
*/
typedef struct _xxxpoint {
	u16 x;			///< ����x
	u16 y;			///< ����y
	u16 radius;		///< �뾶, ������(x,y), �߳�(radius*2+1)�ķ�������
}xxxpoint;

/**
��
*/
typedef struct _xxxline {
	u16 x0;			///< ���x
	u16 y0;			///< ���y
	u16 x1;			///< �յ�x
	u16 y1;			///< �յ�y
	u16 radius;		///< �߿�, δʹ��
}xxxline;

/**
����
*/
typedef struct _xxxrectangle {
	u16 xmin;			///< x��С
	u16 ymin;			///< y��С
	u16 xmax;			///< x���
	u16 ymax;			///< y���
}xxxrectangle;

/**
���¶�������
*/
enum xxxmeasuretype {
	xxxmeasuretype_point = 0,
	xxxmeasuretype_line,
	xxxmeasuretype_rectangle,
	xxxmeasuretype_ellipse,
	xxxmeasuretype_polyline,
	xxxmeasuretype_polygon,
};

/**
���±�־
*/
enum xxxmeasureflags {
	xxxmeasureflags_track_max = 0x01,	///< ����׷��
	xxxmeasureflags_track_min = 0x02,	///< ����׷��

	xxxmeasureflags_plot_max = 0x08,	///< ��������
	xxxmeasureflags_plot_min = 0x10,	///< ��������
	xxxmeasureflags_plot_avg = 0x20		///< ƽ��������
};

/**
��������
*/
enum xxxalarmtype {
	xxxalarmtype_none = 0,
	xxxalarmtype_max,
	xxxalarmtype_min,
	xxxalarmtype_mid,
	xxxalarmtype_exmid,
};

/**
���¶���
*/
typedef struct _xxxmeasure_object {
	char measure_id[16];				///< ����
	u8 measure_type;					///< ����
	u8 alarm_type;						///< ��������
	u8 pad[2];
	float alarm_min;				///< ������Сֵ
	float alarm_max;				///< �������ֵ
	float emissivity;				///< ������

	union {
		xxxpoint point;			///< ��
		xxxline line;				///< ��
		xxxrectangle rectangle;	///< ����
	}geometry;							///< ���ζ���

	u8 reserved[14];
}xxxmeasure_object;

/**
���¶���X
*/
typedef struct _xxxmeasure {
	u8	id;						///< ���
	u8	measuretype;			///< ����
	u8	points;					///< ����
	u8	emmi;					///< ������, ��λ0.01
	u16 xydata[64];				///< ������, x0,y0,x1,y1,...

	u8	alarmtype;				///< ��������
	u8	measureflags;			///< ������־
	u8	pad[2];
	float alarmdata[4];			///< �����¶�ֵt0,t1,t2

}xxxmeasure;

/**
���½��X
*/
typedef struct _xxxresult {
	s32 alarmLevel;				///< �����ȼ�
	u16 maxX;					///< �����X
	u16 maxY;					///< �����Y

	u16 minX;					///< �����X
	u16 minY;					///< �����Y

	float max;					///< �����
	float min;					///< �����
	float avg;					///< ƽ����
}xxxresult;

/**
������X
*/
typedef struct _xxxshield {
	u8		id;					///< ���			
	u8		pad[3];				///< Ԥ��
	u16		xydata[8];			///< ������p0,p1,p2,p3
}xxxshield;

/**
��������λ
*/
enum xxxspdatabits {
	xxxspdatabits_5 = 5,
	xxxspdatabits_6,
	xxxspdatabits_7,
	xxxspdatabits_8,
};

/**
����У��λ
*/
enum xxxspparity {
	xxxspparity_none = 0,
	xxxspparity_odd,
	xxxspparity_even,
};

/**
����ֹͣλ
*/
enum xxxspstopbits {
	xxxspstopbits_1 = 0,
	xxxspstopbits_2,
};

/**
���ڲ�����
*/
enum xxxspbaudrate {
	xxxspbaudrate_2400 = 0,
	xxxspbaudrate_4800,
	xxxspbaudrate_9600,

	xxxspbaudrate_19200,
	xxxspbaudrate_38400,
	xxxspbaudrate_57600,
	xxxspbaudrate_115200,
};

/**
�����÷�
*/
enum xxxspusage {
	xxxspusage_custom = 0,
	xxxspusage_pelcod,
	xxxspusage_pelcop
};

/**
GPIO��������
*/
enum xxxgpioinputtype {
	xxxgpioinputtype_none = 0,			///< �ر�
	xxxgpioinputtype_check,				///< ���
	xxxgpioinputtype_capture,			///< ��ͼ
};

/**
GPIO�������
*/
enum xxxgpiooutputtype {
	xxxgpiooutputtype_close = 0,		///< �ر�
	xxxgpiooutputtype_open,				///< ��
};

/**
�Խ�����
*/
typedef struct _xxxfocusrect {
	u16 xmin;		///< x��С
	u16 ymin;		///< y��С
	u16 xmax;		///< x���
	u16 ymax;		///< y���
}xxxfocusrect;

/**
GPIO��������
*/
enum xxxgpioalarmtype {
	xxxgpioalarmtype_manual = 0,		///< �ֶ�
	xxxgpioalarmtype_auto				///< �Զ�
};

/**
GPIO����ֵ
*/
enum xxxgpioalarmvalue {
	xxxgpioalarmvalue_low = 0,			///< ��
	xxxgpioalarmvalue_high,				///< ��
	xxxgpioalarmvalue_ignore,			///< ��
};

/**
GPIO����
*/
typedef struct _xxxgpioalarm {
	u8 value0;			///< ����ֵ0
	u8 type0;			///< ��������0
	u8 time0;			///< ����ʱ��0

	u8 value1;			///< ����ֵ1
	u8 type1;			///< ��������1
	u8 time1;			///< ����ʱ��1
}xxxgpioalarm;

/**
��������
*/
typedef struct _xxxserialportdata {
	u8 size;				///< ���ݴ�С
	u8 data[31];			///< ������
}xxxserialportdata;

/**
ʱ��
*/
typedef struct _xxxdatetime {
	s32 year;			///< ��
	s32 mon;			///< ��
	s32 day;			///< ��

	s32 hour;			///< ʱ
	s32 min;			///< ��
	s32 sec;			///< ��
}xxxdatetime;


typedef struct _xf_config {
	short ms_full;//ms
	short fc_full;//fc
	short fc1;//fc, cc0
	short fc2;//fc, cc1000

	short fc_delta;//fc
	short fc_small;//fc, 300
	u8	pad[4];
}xf_config;

/**
�¶�תλͼ�㷨�����޸ı�־
*/
enum StrechControlFlags {
	SCF_StrechType = 0x0001,	///< �㷨����
	SCF_Contrast = 0x0002,		///< �Աȶ�
	SCF_Brightness = 0x0004,	///< ����
	SCF_PHEGain = 0x0008,		///< PHE����
	SCF_Linear = 0x0010,		///< LINEAR����
	SCF_PHEStream = 0x0020,		///< PHE����
	SCF_DDELevel = 0x0040,		///< DDE�ȼ�

	SCF_ColorTemp = 0x0080,		///< �¶ȱ��
};

/**
�¶�תλͼ�㷨����
*/
enum StrechType {
	StrechType_PHE = 1,			///< PHE
	StrechType_LINEAR,			///< LINEAR
};

/*
�¶ȱ������
*/
enum ColorTempType {
	ColorTempType_None,			///< ��
	ColorTempType_High,			///< ����, 
	ColorTempType_Low,			///< ����
	ColorTempType_Mid,			///< ������
	ColorTempType_ExMid,		///< ������
};

/**
�¶�תλͼ�㷨����
*/
typedef struct _strech_control {
	s32 flags;						///< ��־

	u8 strech_type;					///< �㷨����
	u8 contrast;					///< �Աȶ�
	u8 brightness;					///< ����
	u8 phe_stream;					///< PHE����
	float phe_gain;					///< PHE����

	s16	linear_temp[2];				///< �ֶ������¶�, ��λ0.1C
	u8	linear_gray[2];				///< �ֶ����ԻҶ�

	u8	dde_level;					///< DDE�ȼ�0-8, 0�ر�DDE


	/*
	����:	�¶ȸ���ct_temp0, ��ct_color0
	���£�	�¶ȵ���ct_temp0, ��ct_color0
	�����ڣ� �¶Ƚ���[ct_temp0,ct_temp1], ��ct_color0
	������:	�¶ȵ���ct_temp0, ��ct_color0; �¶ȸ���ct_temp1,��ct_color1
	*/
	u8 ct_type;						///< �¶ȱ������
	s16 ct_temp0;					///< �¶ȱ���¶�0, ��λ0.1C
	s16 ct_temp1;					///< �¶ȱ���¶�1, ��λ0.1C
	s32 ct_color0;					///< �¶ȱ����ɫ0, bgr��ʽ
	s32 ct_color1;					///< �¶ȱ����ɫ1, bgr��ʽ
}strech_control;

#endif
