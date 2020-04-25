/*
@file YoseenAlg.h
@author yoseen
@date 2018-04-01
*/
#ifndef YOSEENALG_H_
#define YOSEENALG_H_

#include "YoseenTypes.h"


/**
����ģ��ͷ
*/
typedef struct _MeasureTemplateHead {
	s32		Version;						///< �汾
	u16		Width;							///< ���
	u16		Height;							///< �߶�
	s32		ShieldFlags;					///< ȫ����������־
	s32		LMOFlags;						///< �ֲ����¶����־
	u8		pad[112];					///< Ԥ��
}MeasureTemplateHead;


/**
����ģ��
*/
typedef struct _MeasureTemplate {
	MeasureTemplateHead		Head;					///< ģ��ͷ

	xxxshield				ShieldArray[8];			///< ȫ��������, 0-8��
	xxxmeasure				GMO;					///< ȫ�ֲ��¶���
	xxxmeasure				LMOArray[16];			///< �ֲ����¶���, 0-16��
}MeasureTemplate;

/**
ģ����
*/
typedef struct _MeasureTemplateResult {
	xxxresult			GMR;				///< ȫ�ֽ��
	xxxresult			LMRArray[16];		///< �ֲ����
}MeasureTemplateResult;

struct _MTContext;
typedef struct _MTContext MTContext;

extern "C"{

	/**
	��ȡ���½��, ֧�ֵ㡢���ߡ�����Ρ��ߡ����Ρ���Բ
	@param measure ���¶���
	@param dfh �¶�����֡ͷ
	@param dfd �¶�������
	@param result ���½��
	@return ������
	*/
	SDK_API s32 mtGetResult(xxxmeasure* measure, DataFrameHeader* dfh, s16* dfd, xxxresult* result);

	/**
	��������ģ��������
	@param width ���ݿ��
	@param height ���ݸ߶�
	@return ����ģ��������
	*/
	SDK_API MTContext* mtCreate(s32 width, s32 height);

	/**
	�ͷŲ���ģ��������
	@param pp ��ģ��������
	*/
	SDK_API void mtFree(MTContext** pp);

	/**
	���ز���ģ��������
	@param context ������
	@param templ ����ģ��
	@return 0�ɹ�,xʧ��
	*/
	SDK_API s32 mtReload(MTContext* context, MeasureTemplate* templ);


	/**
	��ȡ����ģ��Ĳ������
	@param context ������
	@param dfh �¶�����֡ͷ
	@param dfd �¶�������
	@param result �������
	@return 0�ɹ�,xʧ��
	*/
	SDK_API s32 mtCheck(MTContext* context, DataFrameHeader* dfh, s16* dfd, MeasureTemplateResult* result);

	/**
	������
	@param point ��
	@param dfh �¶�����֡ͷ
	@param dfd �¶�������
	@param [out] result �������
	*/
	SDK_API void Alg_MeasurePoint(const xxxpoint* point, DataFrameHeader* dfh, s16* dfd, xxxmeasure_result* result);

	/**
	������
	@param line ��
	@param dfh �¶�����֡ͷ
	@param dfd �¶�������
	@param [out] result �������
	*/
	SDK_API void Alg_MeasureLine(const xxxline* line, DataFrameHeader* dfh, s16* dfd, xxxmeasure_result* result);

	/**
	��������
	@param rectangle ����
	@param dfh �¶�����֡ͷ
	@param dfd �¶�������
	@param [out] result �������
	*/
	SDK_API void Alg_MeasureRectangle(const xxxrectangle* rectangle, DataFrameHeader* dfh, s16* dfd, xxxmeasure_result* result);

	/**
	������Բ
	@param ellipse ��Բ��Ӿ���
	@param dfh �¶�����֡ͷ
	@param dfd �¶�������
	@param [out] result �������
	*/
	SDK_API void Alg_MeasureEllipse(const xxxrectangle* ellipse, DataFrameHeader* dfh, s16* dfd, xxxmeasure_result* result);


	/**
	�����ɫ������

	@param count ��ɫ������
	@return ��ɫ������, �ڴ沼��
	======================================
	��ɫ��0����, ��ɫ��0����; ��ɫ��1����, ��ɫ��1����; ...
	======================================
	*/
	SDK_API xxxpalettedata* Yoseen_AllocPaletteData(s32& count);

	/**
	�ͷŵ�ɫ������
	@param paletteData ��ɫ������
	*/
	SDK_API void Yoseen_FreePaletteData(xxxpalettedata** paletteData);


	/*
	�Ŵ��¶�����, ˫���Բ�ֵ��ʽ
	@param scale �Ŵ���, ֧��2,3,4���Ŵ�
	@param srcWidth Դ���
	@param srcHeight Դ�߶�
	@param srcData Դ����
	@param dstData Ŀ������
	@return ������
	*/
	SDK_API s32 Alg_ScaleTemp(s32 scale, u16 srcWidth, u16 srcHeight, s16* srcData, s16* dstData);
}

#endif