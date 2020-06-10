#include "devicemodel.h"
#include <QDebug>
#include "debuglog.h"
#include <QFile>
#include <QTimer>
DeviceModel::DeviceModel(QObject *parent) : QAbstractListModel(parent)
{
    //funtest();
}



void DeviceModel::funSavePlayVideo(QObject *playbj){
    listxvideoObj.append(playbj);

}
void DeviceModel::funSaveReplayVideo(QObject *replayobj){
    this->replayObj = replayobj;
}

QObject* DeviceModel::findPlayObjectFromlist(QString objName)
{
    for (int i=0;i<listxvideoObj.size();i++) {

        QObject *obj = listxvideoObj.at(i);
        //qDebug()<<"findPlayObjectFromlist   "<<obj->objectName();
        if(objName.compare(obj->objectName()) == 0){
            return obj;
        }
    }
}

QObject* DeviceModel::findObjectAccordingName(QObject *obj,QString objname)
{
    if(obj == nullptr)
        return nullptr;
    QList<QObject*> children = obj->children();

    for(int i=0;i<children.size();i++){

        QObject *obj1 = children.at(i);
        QString objname1 = obj1->objectName();
        qDebug()<<" objname "<<objname1;
        if(objname1.compare(objname)==0){
            return obj;
        }else{
            QObject *child = findObjectAccordingName(obj1,objname);
            if(child == nullptr)
                continue;
            else
                return child;
        }
    }
    return nullptr;
}

void DeviceModel::funDelayflushDevice(QObject *masterviewobj,QObject *replayobj1){
    QTimer::singleShot(500,[=]{
        funflushDevice(masterviewobj,replayobj1);
    });
}


void DeviceModel::funflushDevice(QObject *masterviewobj,QObject *replayobj1)
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

        qDebug()<<"funflushDevice   "<<listBuff.size();


        beginResetModel();
        for(int i=0;i<listBuff.size();i++){

            QString lineDataStr = listBuff.at(i);

            if(lineDataStr.size() <= 0)
                continue;

            QStringList datemodelStr = lineDataStr.split(" ");
            if(datemodelStr.length() == 4){

                QString deviceID = datemodelStr[0];
                QString name = datemodelStr[1];
                QString channel = datemodelStr[2];
                QString account = "admin";
                QString pwd = "admin";



                QObject *playobj = findPlayObjectFromlist("channel"+channel);

                if(playobj == nullptr){
                    qDebug()<<"not find playobj";
                    return;
                }else {

                    qDebug()<< "find playobj "<<playobj->objectName();
               }


                DeviceModelData *modeldata = new DeviceModelData(playobj,replayObj,m_isAllSelect,deviceID,name,channel,m_recordPath,0);
                connect(modeldata,&DeviceModelData::signal_flushConnectState,this,&DeviceModel::slot_flustConnectState);
                connect(modeldata,&DeviceModelData::signal_recReplayVedio,this,&DeviceModel::slot_recReplayVedio);
                connect(modeldata,&DeviceModelData::signal_recPlayVedio,this,&DeviceModel::slot_recPlayVedio);
                connect(modeldata,&DeviceModelData::signal_p2pReplyData,this,&DeviceModel::slot_recRepkyData);
                connect(modeldata,&DeviceModelData::signal_sendWarnInfo,this,&DeviceModel::slot_sendWarnInfo);

                modeldata->createP2pThread(deviceID,account,pwd);
                m_listDevice.append(modeldata);

            }
        }
        endResetModel();
        file.close();
    }
}

DeviceModel::~DeviceModel()
{

}


void DeviceModel::funSetAllSelect(bool isSelect)
{

    beginResetModel();
    for (int i=0;i<m_listDevice.size();i++) {
        m_listDevice.at(i)->setisSelect(isSelect);
    }
    endResetModel();
}




bool DeviceModel::funAddDevice(QString deviceID,QString name,QString account,QString pwd)
{

    qDebug()<<      "funAddDevice   "<<m_isAllSelect<<" "<<m_recordPath;
    int i = 0;
    for (;i<16;i++) {
        bool channelIsUsing = false;//检测当前i通道是否被使用
        for (int j=0;j<m_listDevice.size();j++) {
            QString devChannel = m_listDevice.at(j)->deviceChannel();
             qDebug()<<"funAddDevice   "<<devChannel;
            if(i == devChannel.toInt()){
                qDebug()<<"tong dao    "<<i;
                channelIsUsing = true;
                break;
            }
        }

        if(!channelIsUsing)
            break;
    }

    //超过15说明所有通道被使用了
    if(i >= 16)
        return false;

    beginInsertRows(QModelIndex(),m_listDevice.size(),m_listDevice.size());

    QObject *playobj = findPlayObjectFromlist("channel"+QString::number(i));

    if(replayObj == nullptr || playobj == nullptr)
        return false;


    qDebug()<<      "funAddDevice   "<<replayObj->objectName()<<" "<<playobj->objectName();

    DeviceModelData *modeldata = new DeviceModelData(playobj,replayObj,m_isAllSelect,deviceID,name,QString::number(i),m_recordPath,0);

    connect(modeldata,&DeviceModelData::signal_flushConnectState,this,&DeviceModel::slot_flustConnectState);
    connect(modeldata,&DeviceModelData::signal_recReplayVedio,this,&DeviceModel::slot_recReplayVedio);
    connect(modeldata,&DeviceModelData::signal_recPlayVedio,this,&DeviceModel::slot_recPlayVedio);
    connect(modeldata,&DeviceModelData::signal_p2pReplyData,this,&DeviceModel::slot_recRepkyData);
    connect(modeldata,&DeviceModelData::signal_sendWarnInfo,this,&DeviceModel::slot_sendWarnInfo);

    m_listDevice.append(modeldata);
    QFile file("device.info");
    if(file.open(QIODevice::WriteOnly | QIODevice::Append)){
        QString imgInfoStr = modeldata->deviceId()+" "+modeldata->deviceName()+" "+modeldata->deviceChannel()+" "+modeldata->recordSavePath();
        QTextStream out(&file);
        out <<imgInfoStr<<"\n";
        file.close();
    }
    endInsertRows();

    return true;
}

void DeviceModel::slot_sendWarnInfo(QString channle ,QString name,QVariantMap map,QByteArray arrimg)
{
    emit signal_sendWarnInfo(channle,name ,map, arrimg);
}

void DeviceModel::slot_recPlayVedio(QString name ,QVariant img,long long pts)
{
    qDebug()<<"slot_recPlayVedio    ";
    emit signal_p2pCallbackVideoData(name,img,pts);
}

void DeviceModel::slot_recReplayVedio(QString name ,QVariant img,long long pts){

    emit signal_p2pCallbackReplayVideoData(name,img,pts);
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
    qDebug()<<"funSendData2 "<<m_listDevice.size();
    for (int i=0;i<m_listDevice.size();i++) {
        qDebug()<<"funSendData3 "<<i;
        DeviceModelData *modeldata =    m_listDevice.at(i);
        qDebug()<<"funSendData4    ";
        qDebug()<<"deviceChannel    "<<modeldata->getDeviceIdefiy();
        if(modeldata != nullptr && modeldata->getDeviceIdefiy().compare(channel)==0){
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

void DeviceModel::funSwitchPage(int page)
{


    //为了减少性能开销，在主预览和回放切换的时候，需要对实时流和回放进行控制
    //比如在实时播放页面的话 就需要把回放的暂停
    //在回放的时候 就需要把实时播放的流暂停

    //0:主预览 1:回放

    for (int i=0;i<m_listDevice.size();i++) {

        DeviceModelData *model = m_listDevice.at(i);

        if(model != nullptr){

//            if(model->replayIsForceStop && page == 1){
//                model->replayIsForceStop = false;
//                QVariantMap map;
//                map.insert("cmd","replay continue");
//                model->funP2pSendData("",map);
//            }
//            if(model->playIsForceStop && page == 0){
//                model->playIsForceStop = false;
//                QVariantMap map;
//                map.insert("cmd","playVideo");
//                model->funP2pSendData("playVideo",map);
//            }
        }
    }
}

QVariant DeviceModel::funGetDevice(int index)
{
    if(m_listDevice.size() <= index || index < 0){
        DebugLog::getInstance()->writeLog("获取设备信息异常:index 越界或者异常");
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


    QFile file("device.info");
    if(file.open(QIODevice::WriteOnly)){

        for (int i=0;i<m_listDevice.size();i++) {

            DeviceModelData *modeldata = m_listDevice.at(i);
            QString imgInfoStr = modeldata->deviceId()+" "+modeldata->deviceName()+" "+modeldata->deviceChannel()+" "+modeldata->recordSavePath();
            QTextStream out(&file);
            out <<imgInfoStr<<"\n";
        }
        file.close();
    }
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
