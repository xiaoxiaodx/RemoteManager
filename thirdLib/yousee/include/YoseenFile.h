/*
@file YoseenFile.h
@author yoseen
@date 2018-04-01
*/
#ifndef YOSEENFILE_H_
#define YOSEENFILE_H_

#include "YoseenTypes.h"

#pragma pack(push, 1)
typedef struct _xxxbmp_file_header{
	u16 bfType;
	u32 bfSize;
	u16 bfReserved1;
	u16 bfReserved2;
	u32 bfOffBits;
} xxxbmp_file_header;

typedef struct _xxxbmp_info_header{
	u32 biSize;
	s32 biWidth;
	s32 biHeight;
	u16 biPlanes;
	u16 biBitCount;
	u32 biCompression;
	u32 biSizeImage;
	s32 biXPelsPerMeter;
	s32 biYPelsPerMeter;
	u32 biClrUsed;
	u32 biClrImportant;
} xxxbmp_info_header;

/**
bmp�ļ�ͷ
*/
typedef struct _bmp_file_header{
	xxxbmp_file_header bfHeader;
	xxxbmp_info_header biHeader;
	u8 pad[2];
	u32 version;
	u8 reserved[4];
}bmp_file_header;


/**
֡�ļ�ͷ
*/
typedef struct _frame_file_header{
	char camera_id[32];			///< ���������к�
	s64 captured_time;			///< ����ʱ��

	u16 width;					///< ���ݿ��
	u16 height;					///< ���ݸ߶�

	FixInfo fix_info;			///< ������Ϣ

	u8 palette;					///< ��ɫ��
	u8 reserved[11];
}frame_file_header;


/**
���ļ�ͷ
*/
typedef struct _stream_file_header{
	char camera_id[32];			///< ���������к�
	s64 captured_time;			///< ����ʱ��
	u16 width;					///< ���ݿ��
	u16 height;					///< ���ݸ߶�

	FixInfo fix_info;			///< ������Ϣ

	u16 fps_num;				///< ֡�ʷ���
	u16 fps_den;				///< ֡�ʷ�ĸ
	u32 frame_count;			///< ֡��

	u8 palette;					///< ��ɫ��
	u8 pad;
	s16 record_ratio;			///< ¼����, >0 ÿ������֡����һ֡; <0 ÿ�������뱣��һ֡
}stream_file_header;


/*
bmp
*/
#define Bmp_FileHeaderSize						64
#define Bmp_FileSize(width,height)				(Bmp_FileHeaderSize+width*height*4+1024+128+128+width*height*2)


/*
* png
*/
#define Png_FileVersion					20160901
#define Png_TempChunkType				(0x704d6574)//teMp
#define Png_TempChunkSize(pixels)			(4+4+128+16 * 1024+128+pixels*2+32+4)
#define Png_TempChunkDataSize(pixels)		(128+16 * 1024+128+pixels*2+32)

#define Png_VisiChunkType				(0x69536976)//viSi

/**
png�¶����ݿ�teMp
�ڴ沼��
===========================================
length		4
type		4
data		ffh+16k+dfh+dfd+pth
crc			4
===========================================
*/
struct png_temp_chunk{
	s32		length;					///< ����
	s32		type;					///< ����
	frame_file_header ffh;			///< ֡�ļ�ͷ
	u8		custom[16 * 1024];				///< �û�����	
	DataFrameHeader dfh;			///< �¶�����֡ͷ
};

/**
png�¶�����ͷ
*/
struct png_temp_header{
	u16 width;				///< ���
	u16 height;				///< �߶�
	s32 version;			///< �汾
	u8 reserved[24];
};

/*
png�ɼ������ݿ�viSi
�ڴ沼��
===========================================
length		4
type		4
data		visiPngFile+pvh
crc			4
===========================================
*/

/**
png�ɼ�������ͷ
*/
struct png_visi_header{
	u16 width;				///< ���
	u16 height;				///< �߶�
	s32 size;				///< �ɼ������ݴ�С
	u8 reserved[24];
};


/**
�¶��ļ�����
*/
typedef struct _TempFrameFile{
	frame_file_header* ffh;				///< ֡�ļ�ͷ�����ļ�ͷ, 128
	u8* custom;							///< ֡�ļ��û���, 16k
	DataFrameHeader* dfh;				///< �¶�֡ͷ, 128
	s16* dfd;							///< �¶�֡������, pixels*2

	//
	u8* visiImage;						///< ����
	u8* coverImage;						///< ��������, ��׼bmp��jpg�ļ���ȫ���ֽ�
	s32 visiImageSize;					///< ����
	s32 coverImageSize;					///< �������ݴ�С
}TempFrameFile;

#pragma pack(pop)

#endif