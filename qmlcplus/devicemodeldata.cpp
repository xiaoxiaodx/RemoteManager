#include "devicemodeldata.h"
#include "p2pworker.h"

#include <QDebug>

void DeviceModelData::createP2pThread(QString deviceDid,QString name,QString pwd)
{

    qDebug()<<"createP2pThread";
    if(p2pWorker == nullptr){

        p2pWorker = new P2pWorker("");
        m_p2pThread = new QThread;
        p2pWorker->moveToThread(m_p2pThread);

        connect(p2pWorker,&P2pWorker::signal_sendH264,this,&DeviceModelData::slot_recH264);
        connect(p2pWorker,&P2pWorker::signal_sendPcmALaw,this,&DeviceModelData::slot_recPcmALaw);
        connect(p2pWorker,&P2pWorker::signal_p2pReplyData,this,&DeviceModelData::slot_p2pReplyData);
        connect(this,&DeviceModelData::signal_connectP2pDev,p2pWorker,&P2pWorker::slot_connectDev);
        connect(p2pWorker,&P2pWorker::signal_reconnectP2pDev,this,&DeviceModelData::slot_reConnectP2pDev);
        connect(p2pWorker,&P2pWorker::signal_p2pConnectState,this,&DeviceModelData::slot_connectState);

        connect(p2pWorker,&P2pWorker::signal_sendReplayH264,this,&DeviceModelData::slot_recReplayH264);
        connect(p2pWorker,&P2pWorker::signal_loginState,this,&DeviceModelData::slot_p2pLoginState);
        connect(p2pWorker,&P2pWorker::signal_sendWarnImg,this,&DeviceModelData::slot_sendWarnImg);


        connect(m_p2pThread,&QThread::finished,p2pWorker,&P2pWorker::deleteLater);
        connect(m_p2pThread,&QThread::finished,m_p2pThread,&QThread::deleteLater);
        m_p2pThread->start();

        emit signal_connectP2pDev(deviceDid,name,pwd);
    }


    connect(&SendTimer,&QTimer::timeout,this,&DeviceModelData::slot_sendtimerout);

}

void DeviceModelData::slot_p2pLoginState(int isSucc){



    if(isSucc>0){
        setisLogin(true);
        qDebug()<<("p2p login succ");
    }else{
        setisLogin(false);
        qDebug()<<("p2p login fail");
    }
}

void DeviceModelData::slot_sendWarnImg(QVariantMap map,QByteArray arrimg)
{
    emit signal_sendWarnInfo(m_deviceChannel,m_deviceName,map,arrimg);
}

void DeviceModelData::slot_recH264(QString name ,QVariant img,long long pts){
    //qDebug()<<" slot_recH264    "<<name;
    emit signal_recPlayVedio(m_deviceChannel,img,pts);
}



void DeviceModelData::slot_recReplayH264(QString name ,QVariant img,long long pts){
    //qDebug()<<" slot_recH264    "<<name;
    emit signal_recReplayVedio(m_deviceChannel,img,pts);
}

void DeviceModelData::slot_recPcmALaw(QString name ,char* PcmALawArr,int arrLen,long long pts)
{
    // qDebug()<<" slot_recPcmALaw    "<<name;
}

void DeviceModelData::slot_reConnectP2pDev(QString deviceDid,QString name,QString pwd)
{
    emit signal_connectP2pDev(deviceDid,name,pwd);
}
void DeviceModelData::slot_connectState(QString name,int a,QString did,QString acc,QString pwd)
{
    qDebug()<<"name "<<name<<"  "<<a;

    if(a>0){
        qDebug()<<("p2p login succ , start login");
        QVariantMap map;
        map.insert("username","admin");
        map.insert("password","admin");
        if(p2pWorker != nullptr){
            p2pWorker->p2pSendData("login",map);
        }

    }else {//断开后进行重新连接
        qDebug()<<("p2p login fail , start reconnect");
        emit signal_connectP2pDev(did,acc,pwd);
    }
    setnetState(a);
    emit signal_flushConnectState();
}



void DeviceModelData::slot_p2pReplyData(QString cmd,QVariantMap map)
{

    QString msgid1 = map.value("msgid").toString();
    QString cmd1 = map.value("cmd").toString();
    qDebug()<<"移除命令   "<<cmd1;
    removeAlreadySend(cmd1,msgid1);


    updatePar(map);
    //一些录像信息需要放松到qml中去渲染
    emit signal_p2pReplyData(m_deviceName,map);
}

void DeviceModelData::updatePar(QVariantMap map)
{

     if(map.value("cmd").toString().compare("getosdparam")==0){
        if(map.contains("osdName"))
            m_osdName = map.value("osdName").toString();
        m_osdNameShowSwitch  = map.value("osdNameShowSwitch").toBool();
        m_osdTimeShowSwitch = map.value("osdTimeShowSwitch").toBool();

    }else if(map.value("cmd").toString().compare("getrtmpinfo")==0){
        m_rtmpUrl =  map.value("rtmpUrl").toString();
        if(map.value("rtmpResolution").toInt() == 11)
            m_rtmpResolution =  0;
        else
            m_rtmpResolution =  1;
        m_rtmpUser =  map.value("rtmpUser").toString();
        m_rtmpPassword =  map.value("rtmpPassword").toString();
        m_rtmpSwitch = map.value("rtmpSwitch").toBool();

    }else if(map.value("cmd").toString().compare("getiradinfo")==0){

         //温度设置
         //        QML_PROPERTY(bool,tempWarnSwitch)
         //        QML_PROPERTY(float,tempWarnValue)
         //        QML_PROPERTY(bool,tempScreenShot)
         //        QML_PROPERTY(QString,tempScreenShotPath)
         //        QML_PROPERTY(bool,tempBeerSwitch)
         //        QML_PROPERTY(float,tempDrift)
         //        QML_PROPERTY(float,tempControlLevel)
         //        QML_PROPERTY(int,tempdriftcaplevelMax)  //2
         //        QML_PROPERTY(int,tempdriftcaplevelMin)  //-2
         //        QML_PROPERTY(int,tempcontrolcaplevelMax)    //13
         //        QML_PROPERTY(int,tempcontrolcaplevelMin)  // 1
         m_tempdriftcaplevelMax = map.value("tempdriftcaplevelMax").toInt();
         m_tempdriftcaplevelMin = map.value("tempdriftcaplevelMin").toInt();
         m_tempcontrolcaplevelMax = map.value("tempcontrolcaplevelMax").toInt();
         m_tempcontrolcaplevelMax = map.value("tempcontrolcaplevelMax").toInt();
         m_tempControlLevel = map.value("tempControlLevel").toInt();
         m_tempDrift = map.value("tempDrift").toInt();
         m_tempWarnValue = map.value("tempWarnValue").toFloat();
         m_tempWarnSwitch = map.value("tempWarnSwitch").toBool();
    }else if(map.value("cmd").toString().compare("getrecordparam")==0){

       m_recordType = map.value("recordType").toInt();
       m_recordStartT = map.value("recordStartT").toString();
       m_recordEndT = map.value("recordEndT").toString();
       m_recordWeeklyDate = map.value("recordWeeklyDate").toString();
       m_recordResolution = map.value("recordResolution").toInt();

    }else if(map.value("cmd").toString().compare("getcurrenttime")==0){
        m_timeZone = map.value("timeZone").toString();

    }else if(map.value("cmd").toString().compare("getalarmparam")==0){
        m_recordType = map.value("recordType").toInt();

    }else if(map.value("cmd").toString().compare("getntpparam")==0){

        m_timeNtpSwtich = map.value("timeNtpSwtich").toBool();
        m_timeNtpUrl = map.value("timeNtpUrl").toString();

    }

}

void DeviceModelData::fungetInitPar()
{
    QVariantMap map;
    map.insert("cmd","getosdparam");
    funP2pSendData("getosdparam",map);

    map.insert("cmd","getrtmpinfo");
    funP2pSendData("getrtmpinfo",map);

    map.insert("cmd","getiradinfo");
    funP2pSendData("getiradinfo",map);

    map.insert("cmd","getrecordparam");
    funP2pSendData("getrecordparam",map);

    map.insert("cmd","getntpparam");
    funP2pSendData("getntpparam",map);

    map.insert("cmd","getcurrenttime");
    funP2pSendData("getcurrenttime",map);

    map.insert("cmd","getalarmparam");
    funP2pSendData("getalarmparam",map);

}

void DeviceModelData::funP2pSendData(QString cmd,QVariantMap map)
{
    qDebug()<<"funP2pSendData   "<<cmd<<"  "<<map;
//    if(p2pWorker != nullptr)
//        p2pWorker->p2pSendData(cmd,map);
    QString msgid = createMsgId(map.value("cmd").toString());
    map.insert("msgid",msgid);
    listMsg.append(map);

    if(!SendTimer.isActive())
        SendTimer.start(sendertimerInter);
}


void DeviceModelData::slot_subscriptiontimerout()
{
    QVariantMap map;
    map.insert("cmd","alarmsubscription");
}

void DeviceModelData::slot_sendtimerout()
{

    qDebug()<<"slot_sendtimerout    "<<listMsg.size();
    if(listMsg.size() <= 0){
        SendTimer.stop();
    }else{
        QMap<QString,QVariant> map = listMsg.takeFirst();

        //int sendcount = map.value("sendCount",0).toInt();
        //如果一条消息发送了多次则默认网络异常，则重新开始创建连接
        listMsg.append(map);
            if(p2pWorker != nullptr)
                p2pWorker->p2pSendData(map.value("cmd").toString(),map);
    }
}

void DeviceModelData::removeAlreadySend(QString cmd,QString msgid1){

    //QMutexLocker locker(&m_msgMutex);

    for (int i=listMsg.size()-1;i>=0;i--) {
        QMap<QString,QVariant> map = listMsg.at(i);
        QString tmpCmd = map.value("cmd").toString();
        if(cmd.compare(tmpCmd)==0 ){
            listMsg.removeAt(i);
            break;
        }
    }
}

QString DeviceModelData::createMsgId(QString cmd){
    //QMutexLocker locker(&m_msgMutex);
    int msgId = 0;
    for (int i=0;i<listMsg.size();i++) {
        QMap<QString,QVariant> map = listMsg.at(i);
        QString tmpCmd = map.value("cmd").toString();
        QString msgid = map.value("msgid").toString();
        if(cmd.compare(tmpCmd)==0){
            int tmpid = msgid.toInt();
            if(msgId < tmpid){
                msgId = tmpid+1;
            }
        }
    }
    return QString::number(msgId);
}
