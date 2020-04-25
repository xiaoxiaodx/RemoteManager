/*
@file YoseenSDK.h
@author yoseen
@date 2018-04-01
*/
#ifndef YOSEENSDK_H_
#define YOSEENSDK_H_

#include "YoseenTypes.h"
#include "YoseenFile.h"

extern "C"{
	/*
	����SDK
	@return ������
	*/
	SDK_API s32 Yoseen_InitSDK();

	/*
	�ͷ�SDK
	*/
	SDK_API void Yoseen_FreeSDK();

	/*
	�趨ȫ��Socket��ʱ, ��λms, Ĭ��2000ms, ȡֵ��Χ[2000, 8000]

	@param connectTimeout ���ӳ�ʱ
	@param sendTimeout ���ͳ�ʱ
	@param recvTimeout ���ճ�ʱ
	*/
	SDK_API void Yoseen_SetTimeout(s32 connectTimeout, s32 sendTimeout, s32 recvTimeout);

	/*
	����������, �ɹ��������������ǻ�����Ϣ.
	Ŀǰֻ��֤�����ǵ�ַ, ����֤�û���������; �����ǲ����Ƶ�����û�.

	@param loginInfo ��¼��Ϣ
	@param [out] cameraBasicInfo �����ǻ�����Ϣ
	@return >=0�û����, <0 ������
	*/
	SDK_API s32 Yoseen_Login(const YoseenLoginInfo* loginInfo, CameraBasicInfo* cameraBasicInfo);

	/*
	�ǳ�������
	@param userHandle �û����
	@return ������
	*/
	SDK_API s32 Yoseen_Logout(s32 userHandle);

	/*
	���浥֡�¶ȵ��ļ�(jpg��չ��ʽ), ����ҪԤ����֧��. ������֧��ͬһʱ�̴���16����������,
	��������ͬһʱ���������ʱ, ��������ʧ�ܵļ���.
	@param userHandle �û����
	@param fileName �ļ���
	@param withTemp �Ƿ���¶���չ
	@return ������
	*/
	SDK_API s32 Yoseen_SaveFrame(s32 userHandle, const char* fileName, s32 withTemp);


	/*
	���浥֡�¶����ݵ��ڴ�, �û��ṩframeFile, SDK���frameFile�ĸ�������ָ��.
	frameFile�ĸ�������ָ��ָ��Ķ����ڲ����ݻ�����, ��ͬһuserHandle�ı����������´��ڲ����ݻ�����������.
	@param userHandle �û����
	@param frameFile �ļ�����ָ��ṹ��
	@return ������
	*/
	SDK_API s32 Yoseen_SaveFrameToMem(s32 userHandle, TempFrameFile* frameFile);

	/*
	��ʼԤ��, һ̨��������ͬʱ֧�� "1��16����Ƶ��Ԥ��" , "1��1���¶���" Ԥ��.

	��Ƶ��Ԥ��, ��˽��յ�����H264�����ͼ�����ݺ������¶�����, ����Ҫ���.
	�¶���Ԥ��, ��˽��յ�����ȫ֡�¶�����, ����Ҫ���.

	@param userHandle �û����
	@param previewInfo Ԥ����Ϣ
	@return >=0 Ԥ�����, <0 ������
	*/
	SDK_API s32 Yoseen_StartPreview(s32 userHandle, YoseenPreviewInfo* previewInfo);

	/*
	��ʼԤ��, Ԥ���ͷֱ��ʵ��¶�����(С��160x120)ʱ, �Ŵ��¶�����.
	ֻ֧��ȡ���ݣ���֧����ʾ.

	@param userHandle �û����
	@param previewInfo Ԥ����Ϣ
	@param tempScale �¶����ݷŴ�, ֧��2,3,4���Ŵ�
	@return >=0 Ԥ�����, <0 ������
	*/
	SDK_API s32 Yoseen_StartPreviewTempScale(s32 userHandle, YoseenPreviewInfo* previewInfo, s32 tempScale);

	/*
	��ʼԤ��,  ����׼rtspЭ��, Ԥ����Ƶ����. ֻ��Ҫ�ɼ����豸������豸֧��rtspЭ��.

	@param rtspInfo rtsp����Ϣ
	@param previewInfo Ԥ����Ϣ
	@return >=0 Ԥ�����, <0 ������
	*/
	SDK_API s32 Yoseen_StartPreviewRtsp(YoseenRtspInfo* rtspInfo, YoseenPreviewInfo* previewInfo);

	/*
	ֹͣԤ��
	@param previewHandle Ԥ�����
	@return ������
	*/
	SDK_API s32 Yoseen_StopPreview(s32 previewHandle);

	/*
	��ͣԤ��
	@param previewHandle Ԥ�����
	@param pause 0-����ͣ, 1-��ͣ
	@return ������
	*/
	SDK_API s32 Yoseen_PausePreview(s32 previewHandle, s32 pause);

	/*
	��ʼ����, �¶���Ԥ��֧�ֱ���.stream��.mp4�ļ�, ��Ƶ��Ԥ��֧�ֱ���.mp4�ļ�.
	@param previewHandle Ԥ�����
	@param fn �ļ���
	@param fileType �ļ�����
	@return ������
	*/
	SDK_API s32 Yoseen_BeginSave(s32 previewHandle, const char* fn, s32 fileType);

	/*
	ֹͣ����
	@param previewHandle Ԥ�����
	@param fileType �ļ�����
	@return ������
	*/
	SDK_API s32 Yoseen_EndSave(s32 previewHandle, s32 fileType);

	/*
	�����¶���Ԥ��, �¶�תλͼ�㷨����; ��Ƶ��Ԥ��ʹ��Yoseen_SetTvoutInfo.
	@param previewHandle Ԥ�����
	@param strechControl �¶�תλͼ�㷨����
	@param paletteType ��ɫ��
	@return ������
	*/
	SDK_API s32 Yoseen_PreviewSetImage(s32 previewHandle, const strech_control* strechControl, s32 paletteType);


	SDK_API s32 Yoseen_PreviewEnableMask(s32 previewHandle, s32 enable);

	/**
	����������
	@param discoverFlags 0x01�㲥, 0x02�鲥, 0x04 �㲥2
	@return ��Ӧ����
	*/
	SDK_API DiscoverCameraResp2* Yoseen_DiscoverCameras(s32 discoverFlags);

	/*
	�ͷ���Ӧ����
	@param pp ��Ӧ����
	*/
	SDK_API void Yoseen_DiscoverCamerasFree(DiscoverCameraResp2** pp);

	/**
	��ȡ�����ǻ�����Ϣ
	@param userHandle �û����
	@param [out] cameraBasicInfo ������Ϣ
	@return ������
	*/
	SDK_API s32 Yoseen_GetCameraBasicInfo(s32 userHandle, CameraBasicInfo* cameraBasicInfo);

	/**
	���������ǻ�����Ϣ
	@param userHandle �û����
	@param cameraBasicInfo ������Ϣ
	@return ������
	*/
	SDK_API s32 Yoseen_SetCameraBasicInfo(s32 userHandle, const CameraBasicInfo* cameraBasicInfo);

	/**
	��ȡ������������Ϣ

	@param userHandle �û����
	@param [out] cameraNetworkInfo ������Ϣ
	@return ������
	*/
	SDK_API s32 Yoseen_GetCameraNetworkInfo(s32 userHandle, CameraNetworkInfo* cameraNetworkInfo);

	/**
	����������������Ϣ, �ɹ����ú�, ������IP���ܷ����仯, �����·���������.
	�����ó�ʹ�þ�̬IP, ��������IP, ��ʹ�������ǵ�GPIO��λ������.

	@param userHandle �û����
	@param cameraNetworkInfo ������Ϣ
	@return ������
	*/
	SDK_API s32 Yoseen_SetCameraNetworkInfo(s32 userHandle, const CameraNetworkInfo* cameraNetworkInfo);

	/**
	��ȡ����У����Ϣ
	@param userHandle �û����
	@param [out] ffcInfo ����У����Ϣ
	@return ������
	*/
	SDK_API s32 Yoseen_GetFFCInfo(s32 userHandle, FFCInfo* ffcInfo);

	/**
	���õ���У����Ϣ, ���óɹ���, �ᴥ��һ�ε���У��.
	@param userHandle �û����
	@param ffcInfo ����У����Ϣ
	@return ������
	*/
	SDK_API s32 Yoseen_SetFFCInfo(s32 userHandle, const FFCInfo* ffcInfo);

	/**
	��ȡģ����Ƶ��Ϣ, ģ����Ƶ��ϢҲ����ͼ���㷨����\��ý�����.
	@param userHandle �û����
	@param [out] tvoutInfo ģ����Ƶ��Ϣ
	@return ������
	*/
	SDK_API s32 Yoseen_GetTvoutInfo(s32 userHandle, TvoutInfo* tvoutInfo);

	/**
	����ģ����Ƶ��Ϣ.
	@param userHandle �û����
	@param tvoutInfo ģ����Ƶ��Ϣ
	@return ������
	*/
	SDK_API s32 Yoseen_SetTvoutInfo(s32 userHandle, const TvoutInfo* tvoutInfo);

	/**
	��ȡ����������Ϣ
	@param userHandle �û����
	@param [out] fixInfo ����������Ϣ
	@return ������
	*/
	SDK_API s32 Yoseen_GetFixInfo(s32 userHandle, FixInfo* fixInfo);

	/**
	���ò���������Ϣ
	@param userHandle �û����
	@param fixInfo ����������Ϣ
	@return ������
	*/
	SDK_API s32 Yoseen_SetFixInfo(s32 userHandle, const FixInfo* fixInfo);

	/**
	��ȡ���¶�����Ϣ
	@param userHandle �û����
	@param [out] measureInfo ���¶�����Ϣ
	@return ������
	*/
	SDK_API s32 Yoseen_GetMeasureInfo(s32 userHandle, MeasureInfo* measureInfo);

	/**
	���ò��¶�����Ϣ
	@param userHandle �û����
	@param measureInfo ���¶�����Ϣ
	@return ������
	*/
	SDK_API s32 Yoseen_SetMeasureInfo(s32 userHandle, const MeasureInfo* measureInfo);

	/*
	��ȡOSD��Ϣ
	@param userHandle �û����
	@param osdInfo osd��Ϣ
	@return ������
	*/
	SDK_API s32 Yoseen_GetCameraOSDInfo(s32 userHandle, CameraOSDInfo* osdInfo);

	/*
	����OSD��Ϣ
	@param userHandle �û����
	@param osdInfo osd��Ϣ
	@return ������
	*/
	SDK_API s32 Yoseen_SetCameraOSDInfo(s32 userHandle, const CameraOSDInfo* osdInfo);

	/**
	��ȡ������ʱ����Ϣ
	@param userHandle �û����
	@param [out] cameraTimeInfo ʱ����Ϣ
	@return ������
	*/
	SDK_API s32 Yoseen_GetCameraTimeInfo(s32 userHandle, CameraTimeInfo* cameraTimeInfo);

	/**
	����������ʱ����Ϣ
	@param userHandle �û����
	@param cameraTimeInfo ʱ����Ϣ
	@return ������
	*/
	SDK_API s32 Yoseen_SetCameraTimeInfo(s32 userHandle, const CameraTimeInfo* cameraTimeInfo);

	/**
	��ȡGPIO��Ϣ
	@param userHandle �û����
	@param [out] gpioInfo GPIO��Ϣ
	@return ������
	*/
	SDK_API s32 Yoseen_GetGpioInfo(s32 userHandle, GpioInfo* gpioInfo);

	/**
	����GPIO��Ϣ
	@param userHandle �û����
	@param gpioInfo GPIO��Ϣ
	@return ������
	*/
	SDK_API s32 Yoseen_SetGpioInfo(s32 userHandle, const GpioInfo* gpioInfo);

	/**
	��ȡ������Ϣ
	@param userHandle �û����
	@param [out] serialPortInfo ������Ϣ
	@return ������
	*/
	SDK_API s32 Yoseen_GetSerialPortInfo(s32 userHandle, SerialPortInfo* serialPortInfo);

	/**
	���ô�����Ϣ
	@param userHandle �û����
	@param serialPortInfo ������Ϣ
	@return ������
	*/
	SDK_API s32 Yoseen_SetSerialPortInfo(s32 userHandle, const SerialPortInfo* serialPortInfo);

	/**
	��ȡ��������Ϣ
	@param userHandle �û����
	@param [out] cameraOutputInfo ������Ϣ
	@return ������
	*/
	SDK_API s32 Yoseen_GetCameraOutputInfo(s32 userHandle, CameraOutputInfo* cameraOutputInfo);

	/**
	���û�������Ϣ
	@param userHandle �û����
	@param cameraOutputInfo ������Ϣ
	@return ������
	*/
	SDK_API s32 Yoseen_SetCameraOutputInfo(s32 userHandle, const CameraOutputInfo* cameraOutputInfo);

	/**
	���Ϳ�����Ϣ
	@param userHandle �û����
	@param ctl ������Ϣ
	@return ������
	*/
	SDK_API s32 Yoseen_SendControl(s32 userHandle, Ctl* ctl);

	/**
	���Ϳ�����ϢX
	@param userHandle �û����
	@param ctlx ������Ϣx
	@return ������
	*/
	SDK_API s32 Yoseen_SendControlX(s32 userHandle, CtlX* ctlx);

	/*
	���ʹ������ݵ�������, �����ǽ��յ�����, ֱ��д������
	@param userHandle �û����
	@param spd ��������
	@return ������
	*/
	SDK_API s32 Yoseen_WriteSerialPortData(s32 userHandle, const xxxserialportdata* spd);

	/*
	�ϴ������ļ���������, ���������ǳ�����¡����㲹����
	@param userHandle �û����
	@param fn �ļ�����
	@param fileType �ļ�����
	@return ������
	*/
	SDK_API s32 Yoseen_UploadFile(s32 userHandle, const char* fn, s32 fileType);

	/*
	�����������ļ�������, ������������־������
	@param userHandle �û����
	@param fn �ļ�����
	@param fileType �ļ�����
	@return ������
	*/
	SDK_API s32 Yoseen_DownloadFile(s32 userHandle, const char* fn, s32 fileType);

	/*
	�ϴ������ڴ����ݵ�������, �������ò���ģ��
	@param userHandle �û����
	@param memType �ڴ���������
	@param memData �ڴ�����ָ��
	@param memSize �ڴ����ݴ�С
	@return ������
	*/
	SDK_API s32 Yoseen_UploadMem(s32 userHandle, s32 memType, void* memData, s32 memSize);

	/*
	�����������ڴ����ݵ�����, ���ڻ�ȡ����ģ��
	@param userHandle �û����
	@param memType �ڴ���������
	@param memData �ڴ�����ָ��
	@param memSize �ڴ����ݴ�С
	@return ������
	*/
	SDK_API s32 Yoseen_DownloadMem(s32 userHandle, s32 memType, void* memData, s32& memSize);
}

#endif