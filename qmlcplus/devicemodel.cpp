#include "devicemodel.h"

DeviceModel::DeviceModel(QObject *parent) : QAbstractListModel(parent)
{

}

void DeviceModel::funtest()
{


    beginInsertRows(QModelIndex(),0,1);

    m_listDevice.append(new DeviceModelData(true,"19911103","1111111",11,"sasads",55));
    m_listDevice.append(new DeviceModelData(true,"19911103","1111111",22,"sasads",66));
    m_listDevice.append(new DeviceModelData(true,"19911103","1111111",33,"sasads",77));
    m_listDevice.append(new DeviceModelData(true,"19911103","1111111",44,"sasads",88));
    endInsertRows();
}



int DeviceModel::rowCount(const QModelIndex &) const
{
    return m_listDevice.count();
}

QVariant DeviceModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= m_listDevice.size())
        return QVariant();
    if(role == ISSELECT)
         return QVariant::fromValue(m_listDevice.at(index.row())->isSelect());
    else if (role == DEVICEID)
        return QVariant::fromValue(m_listDevice.at(index.row())->deviceId());
    else if(role == DEVICENAME)
        return QVariant::fromValue(m_listDevice.at(index.row())->deviceName());
    else if(role == DEVICECHANNEL)
        return QVariant::fromValue(m_listDevice.at(index.row())->deviceChannel());
    else if(role == RECORDSAVEPATH)
        return QVariant::fromValue(m_listDevice.at(index.row())->recordSavePath());
    else if(role == NETSTATE)
        return QVariant::fromValue(m_listDevice.at(index.row())->netState());
    return QVariant();
}

QHash<int, QByteArray> DeviceModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[ISSELECT] = "isselect";
    roles[DEVICENAME] = "deviceName";
    roles[DEVICEID] = "deviceId";
    roles[DEVICECHANNEL] = "deviceChannel";
    roles[RECORDSAVEPATH] = "recordSavePath";
    roles[NETSTATE]="netState";
    return roles;
}


bool DeviceModel::setData(const QModelIndex &index, const QVariant &value, int role)
{

    DeviceModelData *modelData= m_listDevice[index.row()];
    if (data(index, role) != value) {
        if(role == DEVICENAME)
            modelData->setdeviceName(value.toString());
        else if(role == DEVICEID)
            modelData->setdeviceId(value.toString());
        else if(role == DEVICECHANNEL)
            modelData->setdeviceChannel(value.toInt());
        else if(role == RECORDSAVEPATH)
            modelData->setrecordSavePath(value.toString());
        else if(role == NETSTATE)
            modelData->setnetState(value.toInt());
        else if(role == ISSELECT)
            modelData->setisSelect(value.toBool());
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags DeviceModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable; // FIXME: Implement me!
}
