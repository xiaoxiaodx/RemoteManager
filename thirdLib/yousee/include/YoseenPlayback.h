/*
@file YoseenPlayback.h
@author yoseen
@date 2018-04-01
*/
#ifndef YOSEENPLAYBACK_H_
#define YOSEENPLAYBACK_H_

#include "YoseenTypes.h"
#include "YoseenFile.h"

struct _YoseenPlaybackContext;
typedef struct _YoseenPlaybackContext YoseenPlaybackContext;

extern "C"{
	/*
	�����ط�������
	@return �ط�������
	*/
	SDK_API YoseenPlaybackContext* YoseenPlayback_Create();

	/*
	�ͷŻط�������
	@param pp �ط�������
	*/
	SDK_API void YoseenPlayback_Free(YoseenPlaybackContext** pp);

	/*
	���ûط�ͼ���㷨����
	@param ctx �ط�������
	@param sc �㷨����
	@param paletteType ��ɫ������
	*/
	SDK_API void YoseenPlayback_GetImage(YoseenPlaybackContext* ctx, strech_control* sc, s32* paletteType);
	
	/*
	��ȡ�ط�ͼ���㷨����
	@param ctx �ط�������
	@param sc �㷨����
	@param paletteType ��ɫ������
	*/
	SDK_API void YoseenPlayback_SetImage(YoseenPlaybackContext* ctx, const strech_control* sc, const s32* paletteType);

	/*
	���ļ�
	@param ctx �ط�������
	@param fileName �ļ���
	@param fileType �ļ�����
	@return ������
	*/
	SDK_API s32 YoseenPlayback_OpenFile(YoseenPlaybackContext* ctx, const char* fileName, s32 fileType);

	/*
	�ر��ļ�
	@param ctx �ط�������
	*/
	SDK_API void YoseenPlayback_CloseFile(YoseenPlaybackContext* ctx);

	/*
	�����ļ�, ֻ֧�ֵ�֡�ļ�jpg
	@param ctx �ط�������
	@param tff ��������
	@param fileName �ļ���
	@return ������
	*/
	SDK_API s32 YoseenPlayback_SaveFile(YoseenPlaybackContext* ctx, TempFrameFile* tff, const char* fileName);


	/*
	��ȡ��������,
	@param ctx �ط�������
	@param tff ��������
	@return ������
	*/
	SDK_API s32 YoseenPlayback_ReadCover(YoseenPlaybackContext* ctx, TempFrameFile* tff);

	/*
	��ȡ�¶�����, ÿ�ζ�ȡһ֡, λͼ������������.
	@param ctx �ط�������
	@param frameIndex ֡���
	@param dataFrame ����֡
	@return ������
	*/
	SDK_API s32 YoseenPlayback_ReadFrame(YoseenPlaybackContext* ctx, s32 frameIndex, DataFrame* dataFrame);
}



#endif