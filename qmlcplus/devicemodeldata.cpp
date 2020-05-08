#include "devicemodeldata.h"
#include "p2pworker.h"

#include <QDebug>
//#include <debuglog.h>

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
        connect(p2pWorker,&P2pWorker::signal_p2pConnectState,this,&DeviceModelData::slot_connectState);
        connect(p2pWorker,&P2pWorker::signal_sendReplayH264,this,&DeviceModelData::slot_recReplayH264);
        connect(p2pWorker,&P2pWorker::signal_loginState,this,&DeviceModelData::slot_p2pLoginState);
        // connect(p2pWorker,&P2pWorker::signal_sendH264,this,&DeviceModelData::slot_recH264);


        connect(m_p2pThread,&QThread::finished,p2pWorker,&P2pWorker::deleteLater);
        connect(m_p2pThread,&QThread::finished,m_p2pThread,&QThread::deleteLater);
        m_p2pThread->start();

        emit signal_connectP2pDev(deviceDid,name,pwd);
    }
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

void DeviceModelData::slot_p2pReplyData(QString cmd,QVariant map)
{
    emit signal_p2pReplyData(m_deviceName,map);
}
void DeviceModelData::funP2pSendData(QString cmd,QVariant map)
{
    qDebug()<<"funP2pSendData   "<<cmd<<"  "<<map;
    if(p2pWorker != nullptr)
        p2pWorker->p2pSendData(cmd,map);
}

void DeviceModelData::slot_recH264(QString name ,QVariant img,long long pts){
    //qDebug()<<" slot_recH264    "<<name;
    emit signal_recPlayVedio(m_deviceName,img,pts);
}

void DeviceModelData::slot_recReplayH264(QString name ,QVariant img,long long pts){
    //qDebug()<<" slot_recH264    "<<name;
    emit signal_recReplayVedio(m_deviceName,img,pts);
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


void DeviceModelData::updateOsd(int isbatch,int isShowTime,int isSHowName,QString name)
{

}
void DeviceModelData::updateRecord(int isbatch,int videoType,int resolution,QString startT,QString endT,int weekly)
{

}
void DeviceModelData::updateRtmp(int isbatch,int isEnable,int resolution,QString url,QString acc,QString pwd){

}
void DeviceModelData::updateTime(int isbatch,int ntpSwitch,QString url,int timezone,int swithSummerTime){

}
void DeviceModelData::updateTemp(int isbatch,int warnSwith,QString temp,int shootScreenSwith,QString shootScreenPath,int beerSwitch,QString drift,QString thresholdControl){

}


