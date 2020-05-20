#ifndef P2PWORKER_H
#define P2PWORKER_H
#include <QObject>
#include <QDebug>
#include <QThread>
#include <QTimer>

extern "C"{
#include "PPCS_API.h"
#include "PPCS_Error.h"
#include "PPCS_Type.h"
}

#include "protocal_pkg.h"
#include "ffmpegcodec.h"
#include "recordVideo/record/avirecord.h"
#include "p2pprotrol.h"

#define D_SYNCDATA_HEAD0 0xBE
#define D_SYNCDATA_HEAD1 0xEE
#define serverKeyLen 16
#define appKeyLen 32

class P2pWorker : public QObject
{
    Q_OBJECT
public:
    explicit P2pWorker(QString name);
    ~P2pWorker();

    int writeBuff(unsigned int cmd,char* buff,int bufflen);
    int writeBuff1(unsigned int cmd,char* buff,int bufflen);
    void stopWoring();

    int p2pSendData(QString cmd,QVariant map);

    void setIsRecord(bool isrecord,QString path);

    void test();
    QString m_name;
signals:
    //record
    void signal_recordAudio(char *buff,int len,long long tempTime);
    void signal_recordVedio(char *buff,int len,long long tempTime);
    void signal_startRecord(QString did,long long tempTime);
    void signal_endRecord();
    void signal_setRecordingFilePath(QString str);
    //
    void signal_p2pReplyData(QString name,QVariantMap map);

    void signal_sendH264(QString name ,QVariant img,long long pts);
    void signal_sendWarnImg(QVariantMap map,QByteArray arrImg);
    void signal_sendPcmALaw(QString name ,char* PcmALawArr,int arrLen,long long pts);

    void signal_sendReplayH264(QString name ,QVariant img,long long pts);
    void signal_sendReplayPcmALaw(QString name,char* PcmALawArr,int arrLen,long long pts);

    void signal_loopEnd(QString name);


    void signal_p2pConnectState(QString name,int isSucc,QString did,QString acc,QString pwd);
    //void signal_loginState(bool isSucc,QString name,QString did,QString acc,QString pwd,QString errStr);
    void signal_loginState(int isSucc);

    void signal_p2pErr(QString name,QString str);
    void signal_deviceParameterSet(QString name,int parameterType,QVariantMap parMap);

    void signal_reconnectP2pDev(QString deviceDid,QString name,QString pwd);

public slots:

    void slot_connectDev(QString deviceDid,QString name,QString pwd);
    void slot_startLoopRead();

private:

    void p2pinit();


    void createFFmpegDecodec();
    void createFFmpegDecodec1();

    void createAviRecord();

    bool isRecord;
    AviRecord *aviRecord;
    QThread *recordThread;

    void processUnPkg(char* inBuff, int inbuffSize);
    void processUnPkg1(char* inBuff, int inbuffSize);
    void processReqPkg(unsigned int cmd,  char* inBuff, int inbuffSize, char * outBuff,int *outBuffSize,bool isNeedEncrypt);
    void usr_decode(char *pIn, int inLen, char *pKey, int keyreadDataBuffLen);
    void resetStramParseVariant();
    void resetCmdParseVariant();
    unsigned short char2Short(char ch1,char ch2 );
    int sessionHandle;

    QString err2String(int ret);

    void writeDebugFile(QString str);
    char m_appKey[appKeyLen];
    char *m_serverKey;


     FfmpegCodec *pffmpegCodec = nullptr;
     FfmpegCodec *pffmpegCodec1 = nullptr;;

    bool isFindHead;
    bool isFindCmd;
    unsigned short m_cmd;
    int m_validDatalen;
    int needLen;


    bool isCmdFindHead;
    bool isCmdFindCmd;
    unsigned short mCmd_cmd;
    int mCmd_validDatalen;
    int cmdneedLen;

    bool isWorking;
    bool isForceStopWorking;
    bool isP2pInitSucc;
    bool isConnectDevSucc;

    QString m_did;
    QString m_account;
    QString m_password;

    QByteArray readDataBuffStream;
    QByteArray readDataBuffCmd;
    P2pProtrol p2pProtrol;


};

#endif // P2PWORKER_H
