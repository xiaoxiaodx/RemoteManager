#ifndef DEVICEMODEL_H
#define DEVICEMODEL_H

#include <QObject>
#include <QAbstractListModel>

#include "devicemodeldata.h"
class DeviceModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit DeviceModel(QObject *parent = nullptr);
    ~DeviceModel();


    QML_PROPERTY(bool,isAllSelect)
    QML_PROPERTY(QString,recordPath)
public:
    enum datasourceRoles {
        ISSELECT = Qt::UserRole ,
        DEVICEID,
        DEVICENAME,
        DEVICECHANNEL,
        RECORDSAVEPATH,
        NETSTATE,
    };

    Q_INVOKABLE void funflushDevice();
    Q_INVOKABLE void funDeleteIndex(int index);
    Q_INVOKABLE void funDeleteSelect();
    Q_INVOKABLE void funAddDevice(QString deviceID,QString name,QString channel="",QString account="admin",QString pwd="admin");
    Q_INVOKABLE void funSendData(int index,QString cmd,QVariantMap map);
    Q_INVOKABLE void funBatchSendData(QVariantMap map);
    Q_INVOKABLE void funSendData1(QString channel,QString cmd,QVariantMap map);
    Q_INVOKABLE void funSetAllSelect(bool isSelect);//选中所有数据
    Q_INVOKABLE QVariant funGetDevice(int index);
    Q_INVOKABLE QVariant funGetDevice(QString  channel);


    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role ) const override;
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    virtual QHash<int, QByteArray> roleNames() const override;


signals:
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
    void signal_p2pCallbackReply(QString name ,QVariant smap);

    //程序启动时，从文件更新设备信息时，应通知qml 哪些通道已经被使用
    void signal_channelUse(QString channel);
    //告警信息
    void signal_sendWarnInfo(QString channle ,QString name,QVariantMap map,QByteArray arrimg);
public slots:
    void slot_flustConnectState();
    void slot_recReplayVedio(QString name ,QVariant img,long long pts);
    void slot_recRepkyData(QString name ,QVariant smap);
    void slot_recPlayVedio(QString name ,QVariant smap);
    void slot_sendWarnInfo(QString channle ,QString name,QVariantMap map,QByteArray arrimg);

private:


signals:


private:
    QList<DeviceModelData*> m_listDevice;
};

#endif // DEVICEMODEL_H
