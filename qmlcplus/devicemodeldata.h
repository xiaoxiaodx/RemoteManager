#ifndef DEVICEMODELDATA_H
#define DEVICEMODELDATA_H

#include <QObject>
#include "help.h"
#include <QVariant>
#include <QTimer>

class P2pWorker;

#include "XVideo.h"
#include "xvideoreplay.h"
class DeviceModelData : public QObject
{

    Q_OBJECT


public:
    explicit DeviceModelData(QObject* objplay,QObject *objreplay,const bool &isSelect,const QString &deviceId,const QString &deviceName,QString deviceChannel,QString recordSavePath,int netState,bool isLogin = false,QObject *parent=nullptr):
        QObject(parent),m_isSelect(isSelect),
        m_deviceId(deviceId),m_deviceName(deviceName),m_deviceChannel(deviceChannel),
        m_recordSavePath(recordSavePath),m_netState(netState),m_isLogin(isLogin){


        playVideo = dynamic_cast<XVideo*>(objplay);
        replayVideo= dynamic_cast<XVideoReplay *>(objreplay);
    }
    ~DeviceModelData();
    enum PlayStates{
        STOP = 0,
        PLAY,
        PAUSE,
        FORSEPAUSE,
        SWITCH,//回放和实时 切换状态
    };

    PlayStates playState = STOP;
    PlayStates replayState = STOP;


    Q_INVOKABLE void funP2pSendData(QString cmd,QVariantMap map);
    Q_INVOKABLE void fungetInitPar();

    QML_PROPERTY(bool,isSelect)
    QML_PROPERTY(QString,deviceId)
    QML_PROPERTY(QString,deviceName)
    QML_PROPERTY(QString,deviceChannel)
    QML_PROPERTY(QString,recordSavePath)
    QML_PROPERTY(int,netState)
    QML_PROPERTY(bool,isLogin)

    /******参数设置的属性*******/
    //OSD
    QML_PROPERTY(bool,osdIsRevise)
    QML_PROPERTY(bool,osdTimeShowSwitch)
    QML_PROPERTY(bool,osdNameShowSwitch)
    QML_PROPERTY(QString,osdName)
    //录像
    QML_PROPERTY(QString,recordType)// 0 关闭,1 告警录像,2 全部录像
    QML_PROPERTY(int,recordResolution)//0 高清， 1：标清 ，2：流畅
    QML_PROPERTY(QString,recordPath)
    QML_PROPERTY(QString,recordStartT)
    QML_PROPERTY(QString,recordEndT)
    QML_PROPERTY(QString,recordWeeklyDate)//"0000000" 7个字符代表 周一到周日
    //rtmp
    QML_PROPERTY(bool,rtmpSwitch)
    QML_PROPERTY(int,rtmpResolution)
    QML_PROPERTY(QString,rtmpUrl)
    QML_PROPERTY(QString,rtmpUser)
    QML_PROPERTY(QString,rtmpPassword)
    //时间设置
    QML_PROPERTY(bool,timeNtpSwtich)
    QML_PROPERTY(QString,timeNtpUrl)
    QML_PROPERTY(QString,timeZone)
    QML_PROPERTY(bool,timeSummerSwitch)
    //温度设置
    QML_PROPERTY(bool,tempWarnSwitch)
    QML_PROPERTY(float,tempWarnValue)
    QML_PROPERTY(bool,tempScreenShot)
    QML_PROPERTY(QString,tempScreenShotPath)
    QML_PROPERTY(bool,tempBeerSwitch)
    QML_PROPERTY(int,tempDrift)
    QML_PROPERTY(int,tempControlLevel)
    QML_PROPERTY(int,tempdriftcaplevelMax)  //2
    QML_PROPERTY(int,tempdriftcaplevelMin)  //-2
    QML_PROPERTY(int,tempcontrolcaplevelMax)    //13
    QML_PROPERTY(int,tempcontrolcaplevelMin)  // 1

public:
    QThread *m_p2pThread = nullptr;
    P2pWorker *p2pWorker = nullptr;
    void createP2pThread(QString deviceDid,QString name,QString pwd);

    QString getDeviceIdefiy();
signals:
    void signal_flushConnectState();
    void signal_connectP2pDev(QString deviceDid,QString name,QString pwd);
    void signal_p2pReplyData(QString name,QVariantMap map);
    void signal_recReplayVedio(QString name ,QVariant img,long long pts);
    void signal_recPlayVedio(QString name ,QVariant img,long long pts);

    void signal_sendWarnInfo(QString channle ,QString name,QVariantMap map,QByteArray arrimg);
public slots:
    void slot_recH264(QString name ,QVariant img,long long pts);
    void slot_recImg(QImage *img,quint64 pts);
    void slot_recPcmALaw(QString name ,char* PcmALawArr,int arrLen,long long pts);
    void slot_reConnectP2pDev(QString deviceDid,QString name,QString pwd);
    void slot_connectState(QString name,int a,QString did,QString acc,QString pwd);
    void slot_recReplayH264(QString name ,QVariant img,long long pts);
    void slot_recReplayImg(QImage *img,quint64 pts);
    void slot_sendWarnImg(QVariantMap map,QByteArray arrimg);

    void slot_p2pReplyData(QString name,QVariantMap map);

    void slot_p2pLoginState(int isLogin);
    void slot_sendtimerout();
    void slot_subscriptiontimerout();


private:
    QString createMsgId(QString cmd);
    void updatePar(QVariantMap map);
    void removeAlreadySend(QString cmd,QString msgid1);

    QTimer SendTimer,subscriptionTimer;
    int sendertimerInter = 100;
    QList<QVariantMap> listMsg;
    QMap<QString,QVariant> warnPushMap;
    //WarnTcpServer *warnTcpServer = nullptr;

    XVideo *playVideo = nullptr;
    XVideoReplay *replayVideo = nullptr;
};

#endif // DEVICEMODELDATA_H
