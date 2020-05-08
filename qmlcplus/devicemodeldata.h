#ifndef DEVICEMODELDATA_H
#define DEVICEMODELDATA_H

#include <QObject>
#include "help.h"
#include <QVariant>
class P2pWorker;
class DeviceModelData : public QObject
{

    Q_OBJECT


public:
    explicit DeviceModelData(const bool &isSelect,const QString &deviceId,const QString &deviceName,int deviceChannel,QString recordSavePath,int netState,bool isLogin = false,QObject *parent=nullptr):
        QObject(parent),m_isSelect(isSelect),
        m_deviceId(deviceId),m_deviceName(deviceName),m_deviceChannel(deviceChannel),
        m_recordSavePath(recordSavePath),m_netState(netState),m_isLogin(isLogin){}

    Q_INVOKABLE void updateOsd(int isbatch,int isShowTime,int isSHowName,QString name);
    Q_INVOKABLE void updateRecord(int isbatch,int videoType,int resolution,QString startT,QString endT,int weekly);
    Q_INVOKABLE void updateRtmp(int isbatch,int isEnable,int resolution,QString url,QString acc,QString pwd);

    Q_INVOKABLE void updateTime(int isbatch,int ntpSwitch,QString url,int timezone,int swithSummerTime);
    Q_INVOKABLE void updateTemp(int isbatch,int warnSwith,QString temp,int shootScreenSwith,QString shootScreenPath,int beerSwitch,QString drift,QString thresholdControl);

    QML_PROPERTY(bool,isSelect)
    QML_PROPERTY(QString,deviceId)
    QML_PROPERTY(QString,deviceName)
    QML_PROPERTY(int,deviceChannel)
    QML_PROPERTY(QString,recordSavePath)
    QML_PROPERTY(int,netState)
    QML_PROPERTY(bool,isLogin)




    /******参数设置的属性*******/
    //OSD
    QML_PROPERTY(bool,osdIsRevise);
    QML_PROPERTY(bool,osdTimeShowSwitch)
    QML_PROPERTY(bool,osdNameShowSwitch)
    QML_PROPERTY(QString,osdName)
    //录像
    QML_PROPERTY(QString,recordType)// 0 关闭,1 告警录像,2 全部录像
    QML_PROPERTY(QString,recordResolution)
    QML_PROPERTY(QString,recordPath)
    QML_PROPERTY(QString,recordStartT)
    QML_PROPERTY(QString,recordEndT)
    QML_PROPERTY(int,recordWeeklyDate)//0 代表 全选， 1-7代表周1-周日
    //rtmp
    QML_PROPERTY(bool,rtmpSwitch)
    QML_PROPERTY(QString,rtmpResolution)
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
    QML_PROPERTY(float,tempDrift)
    QML_PROPERTY(float,tempControlLevel)
    //
public:
    void funP2pSendData(QString cmd,QVariant map);
    void createP2pThread(QString deviceDid,QString name,QString pwd);
signals:
    void signal_flushConnectState();
    void signal_connectP2pDev(QString deviceDid,QString name,QString pwd);
    void signal_p2pReplyData(QString name,QVariant map);
    void signal_recReplayVedio(QString name ,QVariant img,long long pts);
    void signal_recPlayVedio(QString name ,QVariant img,long long pts);
public slots:
    void slot_recH264(QString name ,QVariant img,long long pts);
    void slot_recPcmALaw(QString name ,char* PcmALawArr,int arrLen,long long pts);
    void slot_reConnectP2pDev(QString deviceDid,QString name,QString pwd);
    void slot_connectState(QString name,int a,QString did,QString acc,QString pwd);
    void slot_recReplayH264(QString name ,QVariant img,long long pts);

    void slot_p2pReplyData(QString name,QVariant map);

    void slot_p2pLoginState(int isLogin);
private:


    QThread *m_p2pThread = nullptr;
    P2pWorker *p2pWorker = nullptr;
};

#endif // DEVICEMODELDATA_H
