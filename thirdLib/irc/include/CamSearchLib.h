#ifndef __LAUCAMSEARCH_H__
#define __LAUCAMSEARCH_H__

#define CAMSEAR_APIIMPORT  extern  "C" __declspec(dllexport)

//��ʼ��,��ʼʹ��ʱ����
CAMSEAR_APIIMPORT BOOL __stdcall CAMSEAR_Startup();
//ֹͣʹ�ã�����ʹ��ʱ����
CAMSEAR_APIIMPORT BOOL __stdcall CAMSEAR_Cleanup();
/*��ʼ����
����:
m_wait:�ȴ�ʱ��(����)
notify��֪ͨ�ص�������
�������£�
devtype:�豸���ͣ�1����Ƶ��������2����������
m_sername:����������;
m_url:IP��ַ��
m_webport��WEB�������˿ڣ�
m_localport�����ض˿�
*/
CAMSEAR_APIIMPORT BOOL __stdcall CAMSEAR_Searchcam(int m_wait,
					void(WINAPI *notify)(int devtype,char *m_sername,char *m_url,BYTE m_mac[6],WORD m_webport,WORD m_localport,
					char *m_submask,char *m_getway,char *m_multiip,char *m_dns,WORD m_multiport,int channel),char *localurl = NULL);

//�����ϰ汾�ĺ���
CAMSEAR_APIIMPORT BOOL __stdcall CAMSEAR_Searchcam_old(int m_wait,
					void(WINAPI *notify)(int devtype,char *m_sername,char *m_url,BYTE m_mac[6],WORD m_webport,WORD m_localport,
					char *m_submask,char *m_getway,char *m_multiip,char *m_dns,WORD m_multiport,int channel),char *localurl = NULL);

/*
���÷�������ַ:
m_mac: MAC��ַ��ֻ����Ϊ��������ʶ��
m_sername:����������
m_url:��������ַ
m_submask:��������
m_getway:����
m_multiip���ಥ��ַ
m_webport:WEB�������˿�
m_localport:���ط���˿�
m_multiport:�ಥ�˿�
*/
CAMSEAR_APIIMPORT BOOL __stdcall CAMSEAR_SearchSeturl(BYTE m_mac[6],char *m_sername,
													  char *m_url,char *m_submask,char *m_getway,char *m_multiip,char *m_dns,
													  WORD m_webport,WORD m_localport,WORD m_multiport,char *localurl = NULL);

/*
���������������ķ�������ַ����Ҫ����������Ч
*/
CAMSEAR_APIIMPORT BOOL __stdcall CAMSEAR_SearchReset(BYTE m_mac[6],char *localurl = NULL);
CAMSEAR_APIIMPORT int  __stdcall GetEthernetInfo(void(WINAPI *notify)(char *localip));
CAMSEAR_APIIMPORT BOOL __stdcall CAMSEAR_SearchRestore(BYTE m_mac[6],char *localurl = NULL);

CAMSEAR_APIIMPORT int   __stdcall CAMSEAR_BadPixel(char *url, unsigned short *badpixelcount, unsigned short *badpixelcountmin,
                                                   unsigned short *badpixelcountmax);
#endif//__LAUCAMSEARCH_H__
