#include "deivceconnectionmanager.h"
#include <QDir>

DeivceConnectionManager::DeivceConnectionManager(QObject *parent) : QObject(parent)
{
    m_typeNetwork = 0;
    m_listDeivceConnection.clear();

    connect(&reSendTimer,&QTimer::timeout,this,&DeivceConnectionManager::slot_resendMsg);
}

void DeivceConnectionManager::funP2pSendData(QString name,QString cmd,QVariant map)
{

    qDebug()<<" funP2pSendData  "<<name<<"  "<<cmd;
    DeivceConnection *info = findDeviceName(name);

    if(info != nullptr){

        if(info->p2pWorker->p2pSendData(cmd,map)>0){

            info->sendIsFree = false;


                if(!info->sendIsFree){
                    addSendMsgToQueue( name, cmd, map);

        }
    }else
        emit signal_err(OTHER,"not find device");
}
}

void DeivceConnectionManager::slot_resendMsg()
{
    if(listSendMsg.size() > 0){
        SendMsg *msg = listSendMsg.at(0);
        funP2pSendData(msg->name,msg->cmd,msg->content);
        delete  msg;
        listSendMsg.removeFirst();
    }else {
        reSendTimer.stop();
    }

}

void DeivceConnectionManager::addSendMsgToQueue(QString name,QString cmd,QVariant content)
{
    SendMsg *msg = new SendMsg;
    msg->name = name;
    msg->cmd = cmd;
    msg->content = content;
    listSendMsg.append(msg);

   if(!reSendTimer.isActive())
       reSendTimer.start(1000);
}

void DeivceConnectionManager::slot_recDataReply(QString name,QVariant map)
{
    QString cmd = map.toMap().value("cmd").toString();

    DeivceConnection *info = findDeviceName(name);

    if(info!=nullptr && info->curSendCmd.compare(cmd)==0)
        info->sendIsFree = true;

    if(cmd.compare("getvideoencodeparam")==0)
        emit signal_videoencodeparam(name ,map);
    else if(cmd.compare("getaudioencodeparam")==0)
        emit signal_audioencodeparam(name ,map);
    else if(cmd.compare("getmotiondetectparam")==0)
        emit signal_motiondetectparam(name ,map);
    //轨迹设置
    else if (cmd.compare("getptzpreset")==0)
        emit signal_getptzpreset(name,map);
    else if (cmd.compare("removeptzpreset")==0)
        emit signal_removeptzpreset(name,map);
    else if (cmd.compare("gotoptzpreset")==0)
        emit signal_gotoptzpreset(name,map);
    else if (cmd.compare("setrtmpinfo")==0)
        emit signal_setrtmpinfo(name,map);
    //录像信息
    else if(cmd.compare("getrecordinginfo")==0)
        emit signal_getrecordinginfo(name,map);
    else if(cmd.compare("replay pause")==0)
        emit signal_p2pCallbackReplayPause(name,map);
    else if(cmd.compare("replay continue")==0)
        emit signal_p2pCallbackReplayContinue(name,map);
    else if(cmd.compare("replay")==0)
        emit signal_p2pCallbackReplay(name,map);

}

QString DeivceConnectionManager::funGetCurrentDir(){

    QDir dir;
    return dir.absolutePath();
}

void DeivceConnectionManager::funConnectP2pDevice(QString name, QString did, QString acc, QString pwd)
{
    qDebug()<<" connectP2pDevice";
    DeivceConnection *info = findDeviceName(name);

    if(info == nullptr){

        DeivceConnection *info = new DeivceConnection;
        info->setname(name);
        info->setacc(acc);
        info->setpwd(pwd);
        info->setdid(did);
        if(m_typeNetwork == 0){

            m_listDeivceConnection.append(info);

            info->createP2pThread();
            //info->p2pWorker->test();

            connect(info->p2pWorker,&P2pWorker::signal_loopEnd,this,&DeivceConnectionManager::slot_reconnectP2p);
            connect(info->p2pWorker,&P2pWorker::signal_sendH264,this,&DeivceConnectionManager::slot_recVedio);
            connect(info->p2pWorker,&P2pWorker::signal_sendPcmALaw,this,&DeivceConnectionManager::slot_recAudio);
            connect(info->p2pWorker,&P2pWorker::signal_sendReplayH264,this,&DeivceConnectionManager::slot_recReplayVedio);
            connect(info->p2pWorker,&P2pWorker::signal_sendReplayPcmALaw,this,&DeivceConnectionManager::slot_recReplayAudio);
            connect(info->p2pWorker,&P2pWorker::signal_loginState,this,&DeivceConnectionManager::slot_recP2pLoginState);
            connect(info->p2pWorker,&P2pWorker::signal_p2pConnectState,this,&DeivceConnectionManager::slot_p2pConnetState);

            connect(info->p2pWorker,&P2pWorker::signal_p2pReplyData,this,&DeivceConnectionManager::slot_recDataReply);
            connect(info->p2pWorker,&P2pWorker::signal_p2pErr,this,&DeivceConnectionManager::slot_p2pErr);

            emit info->signal_connectP2pDev(did,acc,pwd);
        }

    }else{
        signal_err(DEVICE_ADD_DIFFPAR,"The name already exists");
    }

}

void DeivceConnectionManager::slot_reconnectP2p(QString name)
{

    DeivceConnection *info = findDeviceName(name);
    if(info != nullptr)
        emit info->signal_connectP2pDev(info->did(),info->acc(),info->pwd());

}

void DeivceConnectionManager::funDeleteDevice(QString name){

    DeivceConnection *info = findDeviceName(name);

    qDebug()<<"funDeleteDevice  "<<m_listDeivceConnection.size();
    if(info != nullptr){

        m_listDeivceConnection.removeOne(info);
        qDebug()<<"funDeleteDevice1  "<<m_listDeivceConnection.size();


        delete info;

    }

}
void DeivceConnectionManager::slot_p2pConnetState(QString name,bool isSucc){

    qDebug()<<"slot_p2pConnetState  "<<isSucc;

    if(isSucc){

        QVariantMap map;
        map.insert("username","admin");
        map.insert("password","admin");

        DeivceConnection *info = findDeviceName(name);

        if(info != nullptr){
            info->p2pWorker->p2pSendData("login",map);
        }
    }
}


void DeivceConnectionManager::slot_recP2pLoginState(bool isSucc,QString name,QString did,QString acc,QString pwd,QString errStr)
{

    qDebug()<<"slot_recP2pConenctState :"<<isSucc <<"   "<<name<<"  "<<errStr;

    emit signal_p2pConnectCallback(isSucc,name,did,acc,pwd,errStr);

}

void DeivceConnectionManager::slot_recVedio(QString name ,QVariant arr,quint64 time)
{
    emit signal_p2pCallbackVideoData(name,arr);

    QImage *img = arr.value<QImage*>();

    if(img != nullptr && !img->isNull())
        delete img;
}

void DeivceConnectionManager::funRecordVideo(bool isRecord,QString name)
{

    qDebug()<<"recordingPath    "<<m_recordingPath;
    DeivceConnection *info = findDeviceName(name);

    if(info != nullptr){
        info->p2pWorker->setIsRecord(isRecord,m_recordingPath);

    }
}

void DeivceConnectionManager::slot_recAudio(QString name ,char* PcmALawArr,int arrLen,long long pts){
    QByteArray arr;
    arr.append(PcmALawArr,arrLen);
    emit signal_p2pCallbackReplayAudioData(name,arr,arrLen);
}
void DeivceConnectionManager::slot_recReplayVedio(QString name ,QVariant arr,quint64 time){


    // qDebug()<<"slot_recReplayVedio  1";
    emit signal_p2pCallbackReplayVideoData(name,arr);
}
void DeivceConnectionManager::slot_recReplayAudio(QString name ,char* PcmALawArr,int arrLen,long long pts){
    QByteArray arr;
    arr.append(PcmALawArr,arrLen);
    emit signal_p2pCallbackReplayAudioData(name,arr,arrLen);
}






void DeivceConnectionManager::funClearCmdList()
{

}

void DeivceConnectionManager::slot_p2pErr(QString did,QString str)
{
    qDebug()<<"did  "<<did<<"   content:"<<str;
}


DeivceConnection* DeivceConnectionManager::findDeviceName(QString name)
{

    for(int i=0;i<m_listDeivceConnection.size();i++){
        DeivceConnection *info = m_listDeivceConnection.at(i);

        //qDebug()<<info->name()<<"   "   <<name;
        if(info->name().compare(name)==0){

            return info;
        }
    }

    return nullptr;
}





