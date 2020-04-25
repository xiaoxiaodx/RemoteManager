#ifndef DEVICEMODEL_H
#define DEVICEMODEL_H

#include <QObject>
#include <QAbstractListModel>

#include "help.h"

class DeviceModelData:public QObject
{
    Q_OBJECT
public:
    DeviceModelData(const bool &isSelect,const QString &deviceId,const QString &deviceName,int deviceChannel,QString recordSavePath,int netState,QObject *parent=nullptr)
        :QObject(parent),m_isSelect(isSelect),
          m_deviceId(deviceId),m_deviceName(deviceName),m_deviceChannel(deviceChannel),
          m_recordSavePath(recordSavePath),m_netState(netState){}

    QML_PROPERTY(bool,isSelect)
    QML_PROPERTY(QString,deviceId)
    QML_PROPERTY(QString,deviceName)
    QML_PROPERTY(int,deviceChannel)
    QML_PROPERTY(QString,recordSavePath)
    QML_PROPERTY(int,netState)
};




class DeviceModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit DeviceModel(QObject *parent = nullptr);

    enum datasourceRoles {
        ISSELECT = Qt::UserRole ,
        DEVICEID,
        DEVICENAME,
        DEVICECHANNEL,
        RECORDSAVEPATH,
        NETSTATE,
    };

    Q_INVOKABLE void funtest();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role ) const override;
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    virtual QHash<int, QByteArray> roleNames() const override;


private:
    void removeIndex(int index);
    void removeAll();
signals:

public slots:


private:
    QList<DeviceModelData*> m_listDevice;
};

#endif // DEVICEMODEL_H
