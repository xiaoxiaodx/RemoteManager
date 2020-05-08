#ifndef DEIVCECONNECTIONMANAGER_H
#define DEIVCECONNECTIONMANAGER_H

#include <QObject>

#include <QTimer>
#include "deivceconnection.h"
////错误码:请求错误
//#ifndef RETCODE_ERROR
//#define RETCODE_ERROR   400
//#endif

////错误码:鉴权失败
//#ifndef RETCODE_UNAUTHORIZED
//#define RETCODE_UNAUTHORIZED  401
//#endif

//错误码:接口调用失败
//#ifndef RETCODE_FUNERROR
//#define RETCODE_FUNERROR  402
//#endif

////错误码:禁止访问
//#ifndef RETCODE_FORBIDDEN
//#define RETCODE_FORBIDDEN  403
//#endif

////错误码:找不到对象
//#ifndef RETCODE_NOTFOUND
//#define RETCODE_NOTFOUND  404
//#endif

////错误码:没有权限
//#ifndef RETCODE_METHODNOTALLOWED
//#define RETCODE_METHODNOTALLOWED  405
//#endif

////错误码:循环执行
//#ifndef RETCODE_LOOP
//#define RETCODE_LOOP   406
//#endif

//错误码:没有权限
//#ifndef RETCODE_MAXUSRNUM
//#define RETCODE_MAXUSRNUM  411
//#endif

class SendMsg{
public:
    QVariant content;
    QString name;
    QString cmd;
};
class DeivceConnectionManager : public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE void funConnectP2pDevice(QString name,QString did,QString acc,QString pwd);
    Q_INVOKABLE void funP2pSendData(QString name,QString cmd,QVariant map);
    Q_INVOKABLE void funDeleteDevice(QString name);

    Q_INVOKABLE void funClearCmdList();
    Q_INVOKABLE void funRecordVideo(bool isRecord,QString name);
    Q_INVOKABLE QString funGetCurrentDir();

    QML_PROPERTY(int,typeNetwork)
    QML_PROPERTY(QString,screenShotPath)
    QML_PROPERTY(QString,recordingPath)

    Q_ENUMS(ERR_CODE)
public:
    explicit DeivceConnectionManager(QObject *parent = nullptr);

    enum ERR_CODE{
        DEVICE_ADD_DIFFPAR = 0,//参数不同
        OTHER = 100,

        RETCODE_SUCC = 200,
        RETCODE_ERROR = 400,
        RETCODE_UNAUTHORIZED,
        RETCODE_FUNERROR,
        RETCODE_FORBIDDEN,
        RETCODE_NOTFOUND,
        RETCODE_METHODNOTALLOWED,
        RETCODE_LOOP,
        RETCODE_MAXUSRNUM = 411,

    };

signals:

    void signal_err(int errCode,QVariant varint = 0);

    void signal_connectDev(QString deviceDid,QString name,QString pwd);

    void signal_startSendWait();
    void signal_endEndWait();


    //回调
    void signal_p2pConnectCallback(bool isSucc,QString name,QString did,QString acc,QString pwd,QString errStr);
    void signal_p2pCallbackVideoData(QString name ,QVariant h264Arr);
    void signal_p2pCallbackAudioData(QString name ,QVariant PcmALawArr,int arrLen,long long pts);
    void signal_p2pCallbackReplayVideoData(QString name ,QVariant h264Arr);
    void signal_p2pCallbackReplayAudioData(QString name ,QVariant PcmALawArr,int arrLen);

    //回放
    void signal_p2pCallbackReplayContinue(QString name ,QVariant smap);
    void signal_p2pCallbackReplayPause(QString name ,QVariant smap);
    void signal_p2pCallbackReplay(QString name ,QVariant smap);

    //参数配置
    void signal_videoencodeparam(QString name ,QVariant smap);
    void signal_audioencodeparam(QString name ,QVariant smap);
    void signal_motiondetectparam(QString name,QVariant smap);
    //轨迹巡航
    void signal_getptzpreset(QString name,QVariant smap);
    void signal_setrtmpinfo(QString name,QVariant smap);
    void signal_gotoptzpreset(QString name,QVariant smap);
    void signal_removeptzpreset(QString name,QVariant smap);
    //录像信息
    void signal_getrecordinginfo(QString name,QVariant smap);
public slots:

    void slot_recDataReply(QString name,QVariant map);

    void slot_recVedio(QString name ,QVariant img,quint64 time);
    void slot_recAudio(QString name ,char* PcmALawArr,int arrLen,long long pts);
    void slot_recReplayVedio(QString name ,QVariant img,quint64 time);
    void slot_recReplayAudio(QString name ,char* PcmALawArr,int arrLen,long long pts);

    void slot_reconnectP2p(QString name);
    void slot_p2pConnetState(QString did,bool isSucc);
    void slot_recP2pLoginState(bool isSucc,QString name,QString did,QString acc,QString pwd,QString errStr);
    void slot_p2pErr(QString did,QString str);
    void slot_resendMsg();
private:

    void addSendMsgToQueue(QString name,QString cmd,QVariant content);
    DeivceConnection* findDeviceName(QString did);

    void connectDevice();


    QList<DeivceConnection*> m_listDeivceConnection;



    QList<SendMsg*> listSendMsg;
    QTimer reSendTimer;
    //QList<DeviceInfo*> m_listDeviceInfo;
};


#endif // DEIVCECONNECTIONMANAGER_H
