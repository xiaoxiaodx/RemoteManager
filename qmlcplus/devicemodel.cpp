#include "devicemodel.h"
#include <QDebug>
#include "debuglog.h"
#include <QFile>
#include <QTimer>
DeviceModel::DeviceModel(QObject *parent) : QAbstractListModel(parent)
{
    //funtest();
}

void DeviceModel::funflushDevice()
{
    //    beginInsertRows(QModelIndex(),0,1);
    //    m_listDevice.append(new DeviceModelData(true,"19911103","1111111",11,"sasads",55));
    //    m_listDevice.append(new DeviceModelData(true,"19911103","1111111",22,"sasads",66));
    //    m_listDevice.append(new DeviceModelData(true,"19911103","1111111",33,"sasads",77));
    //    m_listDevice.append(new DeviceModelData(true,"19911103","1111111",44,"sasads",88));
    //    endInsertRows();
    QFile file("device.info");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){

        QByteArray arr = file.readAll();

        QString strBuff(arr);
        QStringList listBuff = strBuff.split("\n");

        for(int i=0;i<listBuff.size();i++){

            QString lineDataStr = listBuff.at(i);

            if(lineDataStr.size() <= 0)
                continue;

            QStringList datemodelStr = lineDataStr.split(" ");

            if(datemodelStr.length() == 4){
                emit signal_channelUse(datemodelStr[2]);
                funAddDevice(datemodelStr[0],datemodelStr[1],datemodelStr[2],"admin","admin");
            }
        }

        file.close();
    }
}

DeviceModel::~DeviceModel()
{
    QFile file("device.info");
    if(file.open(QIODevice::WriteOnly)){

        for(int i=0;i<m_listDevice.size();i++){

            DeviceModelData *modeldate = m_listDevice.at(i);

            QString imgInfoStr = modeldate->deviceId()+" "+modeldate->deviceName()+" "+modeldate->deviceChannel()+" "+modeldate->recordSavePath();
            //qDebug()<<"imgInfoStr   " <<imgInfoStr;
            QTextStream out(&file);
            out <<imgInfoStr << "\n";

        }
        file.close();
    }
}


void DeviceModel::funSetAllSelect(bool isSelect)
{

    beginResetModel();
    for (int i=0;i<m_listDevice.size();i++) {
        m_listDevice.at(i)->setisSelect(isSelect);
    }
    endResetModel();
}


void DeviceModel::funAddDevice(QString deviceID,QString name,QString channel,QString account,QString pwd)
{

    qDebug()<<      "funAddDevice   "<<m_isAllSelect<<" "<<m_recordPath;

    beginInsertRows(QModelIndex(),m_listDevice.size(),m_listDevice.size());
    DeviceModelData *modeldata = new DeviceModelData(m_isAllSelect,deviceID,name,channel,m_recordPath,0);
    connect(modeldata,&DeviceModelData::signal_flushConnectState,this,&DeviceModel::slot_flustConnectState);
    connect(modeldata,&DeviceModelData::signal_recReplayVedio,this,&DeviceModel::slot_recReplayVedio);
    connect(modeldata,&DeviceModelData::signal_recPlayVedio,this,&DeviceModel::slot_recPlayVedio);
    connect(modeldata,&DeviceModelData::signal_p2pReplyData,this,&DeviceModel::slot_recRepkyData);
    connect(modeldata,&DeviceModelData::signal_sendWarnInfo,this,&DeviceModel::slot_sendWarnInfo);

    modeldata->createP2pThread(deviceID,account,pwd);
    m_listDevice.append(modeldata);
    endInsertRows();
}

void DeviceModel::slot_sendWarnInfo(QString channle ,QString name,QVariantMap map,QByteArray arrimg)
{
    emit signal_sendWarnInfo(channle,name ,map, arrimg);
}

void DeviceModel::slot_recPlayVedio(QString name ,QVariant img)
{
    emit signal_p2pCallbackVideoData(name,img);
}

void DeviceModel::slot_recReplayVedio(QString name ,QVariant img,long long pts){
    emit signal_p2pCallbackReplayVideoData(name,img);
}

void DeviceModel::slot_recRepkyData(QString name ,QVariant smap)
{
    emit signal_p2pCallbackReply(name,smap);
}

void DeviceModel::funSendData(int index,QString cmd,QVariantMap map)
{
    if(index >= m_listDevice.size())
        return;
    DeviceModelData *modeldata = m_listDevice.at(index);
    if(modeldata != nullptr)
        modeldata->funP2pSendData(cmd,map);
}

void DeviceModel::funBatchSendData(QVariantMap map){

    for (int i=0;i<m_listDevice.size();i++) {

        if(m_listDevice.at(i)->isSelect()){
            DeviceModelData *date = m_listDevice.takeAt(i);
            date->funP2pSendData("",map);
        }
    }
}



void DeviceModel::funSendData1(QString channel,QString cmd,QVariantMap map)
{

    qDebug()<<"funSendData1 "<<channel;
    for (int i=0;i<m_listDevice.size();i++) {
        DeviceModelData *modeldata = m_listDevice.at(i);
        if(modeldata != nullptr && modeldata->deviceChannel().compare(channel)==0){
            modeldata->funP2pSendData(cmd,map);
            break;
        }
    }


}
void DeviceModel::slot_flustConnectState()
{

    qDebug()<<"slot_flustConnectState";
    beginResetModel();
    endResetModel();
}

QVariant DeviceModel::funGetDevice(QString channel)
{

    for (int i= 0;i<m_listDevice.size() ;i++) {
        DeviceModelData *modeldata = m_listDevice.at(i);
        if(modeldata->deviceChannel().compare(channel)==0){

            return QVariant::fromValue(modeldata);
        }
    }

}


QVariant DeviceModel::funGetDevice(int index)
{
    if(m_listDevice.size() <= index){
        DebugLog::getInstance()->writeLog("获取设备信息异常:index 越界");
        return QVariant();
    }
    return QVariant::fromValue(m_listDevice.at(index));
}


void DeviceModel::funDeleteIndex(int index)
{
    qDebug()<<"DeviceModel funDeleteIndex:"<<index<<"   "<<m_listDevice.size();

    if(m_listDevice.size() <= index){
        DebugLog::getInstance()->writeLog("删除警报信息异常:index 越界");
        return;
    }

    beginRemoveRows(QModelIndex(),index,index);

    DeviceModelData *date = m_listDevice.takeAt(index);
    delete date;
    endRemoveRows();
}

void DeviceModel::funDeleteSelect(){
    beginResetModel();
    for (int i=0;i<m_listDevice.size();i++) {

        if(m_listDevice.at(i)->isSelect()){
            DeviceModelData *date = m_listDevice.takeAt(i);
            delete date;
            i -= 1;
        }
    }
    endResetModel();
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
    roles[ISSELECT] = "isSelect";
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
            modelData->setdeviceChannel(value.toString());
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
