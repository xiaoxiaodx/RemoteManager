#include "XVideo.h"
#include <QPainter>
#include <QDebug>
#include <render/texturenode.h>
#include <QPainter>

XVideo::XVideo()
{
    qDebug()<<"XVideo "<<"  "<<QThread::currentThreadId() ;



}


void XVideo::fun_setInitPar(QString ip,int parentW,int parentH,int x,int y,int w,int h)
{
    m_ip = ip;
    showRectX = x;
    showRectY = y;
    showRectW = w;
    showRectH = h;
    showParentW = parentW;
    showParentH = parentH;

    qDebug()<<" fun_setInitPar  "<<showRectX<<" "<<showRectY;
}

void XVideo::startNormalVideo(float tp)
{
    DebugLog::getInstance()->writeLog("startNormalVideo ");
    warnTemp = tp;
    createTcpThread();
    //createSearchIp();
}




void XVideo::createFFmpegDecodec()
{
    if(pffmpegCodec == nullptr)
    {
        pffmpegCodec = new FfmpegCodec;
        pffmpegCodec->vNakedStreamDecodeInit(AV_CODEC_ID_H264);
        pffmpegCodec->aNakedStreamDecodeInit(AV_CODEC_ID_PCM_ALAW,AV_SAMPLE_FMT_S16,8000,1);
        pffmpegCodec->resetSample(AV_CH_LAYOUT_MONO,AV_CH_LAYOUT_MONO,8000,44100,AV_SAMPLE_FMT_S16,AV_SAMPLE_FMT_S16,160);


        if(m_readThread != nullptr)
            connect(m_readThread,&QThread::finished,pffmpegCodec,&FfmpegCodec::deleteLater);
    }
}

void XVideo::fun_setIraInfo(QVariantMap map)
{
    emit signal_httpParSet(map);
}

void XVideo::fun_getInitPar()
{
    qDebug()<<"fun_getInitPar";

    QTimer::singleShot(500,[&]{
        QMap<QString,QVariant> map;
        map.insert("cmd","getinftempmodel");
        emit signal_httpParSet(map);
    });

    QTimer::singleShot(1000,[&]{
        QMap<QString,QVariant> map;
        map.insert("cmd","getosdparam");
        emit signal_httpParSet(map);
    });

    QTimer::singleShot(2000,[&]{
        QMap<QString,QVariant> map;
        map.insert("cmd","setcurrenttime");
        emit signal_httpParSet(map);
    });

    QTimer::singleShot(1500,[&]{

        QMap<QString,QVariant> map;
        map.insert("cmd","getiradinfo");
        emit signal_httpParSet(map);

    });
}


void XVideo::createTcpThread()
{
    if(worker == nullptr){
        worker = new TcpWorker(0);
        m_readThread = new QThread;

        connect(worker,&TcpWorker::signal_sendH264,this,&XVideo::slot_recH264,Qt::DirectConnection);
        connect(this,&XVideo::signal_connentSer,worker,&TcpWorker::creatNewTcpConnect);
        connect(m_readThread,&QThread::finished,worker,&TcpWorker::deleteLater);
        connect(m_readThread,&QThread::finished,m_readThread,&QThread::deleteLater);
        worker->moveToThread(m_readThread);
        m_readThread->start();

        emit signal_connentSer(m_ip,555);

    }
    createHttpApi();

}

void XVideo::createHttpApi(){

    if(httpDevice == nullptr){
        httpThread = new QThread;
        httpDevice = new CHttpApiDevice("INEW-004122-JWGWM", m_ip,8564, "admin", "admin");
        connect(httpDevice, &CHttpApiDevice::signal_ReadMsg, this, &XVideo::slog_HttpmsgCb);
        connect(this, &XVideo::signal_getInitPar,httpDevice,&CHttpApiDevice::slot_httpGetInitPar);
        connect(this, &XVideo::signal_httpParSet,httpDevice,&CHttpApiDevice::slot_httpParSet);
        httpDevice->moveToThread(httpThread);
        httpThread->start();

        // emit signal_getInitPar();
        fun_getInitPar();
    }
}

void XVideo::slog_HttpmsgCb(QMap<QString,QVariant> map) {

    qDebug()<<" slog_HttpmsgCb "<<map;
    emit signal_httpUiParSet(QVariant::fromValue(map));
}

void XVideo::createSearchIp()
{
    //    if(psearch == nullptr){
    //        psearch = new MySearch1;
    //        searchThread = new QThread;
    //        connect(psearch,&MySearch1::signal_sendIp,this,&XVideo::recSearchIp);
    //        connect(this,&XVideo::signal_resetSearch,psearch,&MySearch1::resetSearch);
    //        connect(this,&XVideo::signal_finishSearch,psearch,&MySearch1::forceFinishSearch);
    //        connect(searchThread,&QThread::finished,searchThread,&MySearch1::deleteLater);
    //        connect(searchThread,&QThread::finished,psearch,&MySearch1::deleteLater);
    //        psearch->moveToThread(searchThread);
    //        searchThread->start();
    //    }

    //    emit signal_resetSearch();

}

void XVideo::recSearchIp(QString ip)
{

    DebugLog::getInstance()->writeLog("my recSearchIp:"+ip);
    //qDebug()<<"my recSearchIp:"<<ip;

    //m_ip = "10.67.1.146";//ip;//"192.168.1.101";
    //createTcpThread();

}


void XVideo::updateUi()
{



}

void XVideo::fun_updateDate()
{
    QMap<QString,QVariant> map;
    map.insert("cmd","setcurrenttime");
    emit signal_httpParSet(map);

}

void XVideo::paint(QPainter *painter)
{


}

void XVideo::fun_setRectPar(int sx,int sy,int sw,int sh,int pw,int ph){

    showRectX = sx;
    showRectY = sy;
    showRectW = sw;
    showRectH = sh;

    showParentW = pw;
    showParentH = ph;
}

//tcpworker 线程
void XVideo::slot_recH264(char* h264Arr,int arrlen,quint64 time)
{

    // qDebug()<<QString(__FUNCTION__) + " "+QString::number(__LINE__)<<"  "<<QThread::currentThreadId() ;
    createFFmpegDecodec();

    if(pffmpegCodec != nullptr){

        QImage *Img = nullptr;
        if(pffmpegCodec != nullptr){
            Img = pffmpegCodec->decodeVFrame((unsigned char*)h264Arr,arrlen);
            if (Img != nullptr )
            {
                mMutex.lock();
                if(listBuffImg.size() < maxBuffLen)
                    listBuffImg.append(Img);
                else
                    delete Img;
                mMutex.unlock();
            }
        }

    }
}
//由红外控制ui更新
void XVideo::fun_setListRect(QVariant var){
    //qDebug()<<"tcp 流线程 fun_setListRect:"<<QThread::currentThreadId()<<"    "<<var.toList();

    update();



}

void XVideo::fun_initRedFrame(int w,int h){



    //    }
}


void XVideo::fun_timeSwitch(bool isChecked){
    qDebug()<< "    fun_timeSwitch  "<<isChecked;
    QMap<QString , QVariant> map;
    map.insert("cmd","setosdparam");
    map.insert("enable",isChecked);
    emit signal_httpParSet(map);
}

void XVideo::fun_temSet(QVariant mvalue){
    warnTemp = mvalue.toFloat();
}


XVideo::~XVideo()
{

}

