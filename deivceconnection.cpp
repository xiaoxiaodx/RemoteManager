#include "deivceconnection.h"

DeivceConnection::DeivceConnection(QObject *parent) : QObject(parent)
{
}



//void DeivceConnection::createP2pThread()
//{

////    qDebug()<<"createP2pThread";
////    if(p2pWorker == nullptr){

////        p2pWorker = new P2pWorker(m_name);
////        m_p2pThread = new QThread;
////        p2pWorker->moveToThread(m_p2pThread);

//////        connect(p2pWorker,&P2pWorker::signal_sendH264,this,&DeivceConnection::slot_recH264,Qt::DirectConnection);
//// //       connect(p2pWorker,&P2pWorker::signal_sendPcmALaw,this,&DeivceConnection::slot_recPcmALaw,Qt::DirectConnection);

////        connect(this,&DeivceConnection::signal_connectP2pDev,p2pWorker,&P2pWorker::slot_connectDev);


////        connect(m_p2pThread,&QThread::finished,p2pWorker,&P2pWorker::deleteLater);
////        connect(m_p2pThread,&QThread::finished,m_p2pThread,&QThread::deleteLater);


////        m_p2pThread->start();

////    }
//}

//void DeivceConnection::createTcpThread()
//{

//}

////tcpworker 线程
//void DeivceConnection::slot_recH264(char* h264Arr,int arrlen,quint64 time)
//{

//}


////tcpworker 线程
//void DeivceConnection::slot_recPcmALaw( char * buff,int len,quint64 time)
//{

//}


//DeivceConnection:: ~DeivceConnection()
//{



////    if(p2pWorker!= nullptr){

////        p2pWorker->stopWoring();
////        m_p2pThread->quit();

////    }

//}
