#include "XVideoReplay.h"
#include <QPainter>
#include <QDebug>


int XVideoReplay::testIdIndex = 0;
XVideoReplay::XVideoReplay()
{
    setFlag(QQuickItem::ItemHasContents);




    testIdIndex++;
    //connect(&timerUpdate,&QTimer::timeout,this,&XVideoReplay::slot_timeout);

    testID = testIdIndex;
    m_Img = new QImage();
}


QSGNode* XVideoReplay::updatePaintNode(QSGNode *old, UpdatePaintNodeData *data)
{
    //qDebug()<<"XVideoReplay updatePaintNode thread:"<<QThread::currentThreadId()<<"   "<<listImgInfo.size();
    QSGSimpleTextureNode *oldTexture = static_cast<QSGSimpleTextureNode*>(old);

    if (oldTexture == NULL) {
        oldTexture = new QSGSimpleTextureNode();
    }

    //listImg的size必须要比3大，因为在更新时程序在执行到delete m_Img后，由于用户突然调整窗口大小，
    //从而导致再次调用更新，此时m_Img 已经为空，以下代码将会致使程序崩溃
    // QSGTexture *t = window()->createTextureFromImage(*m_Img)
    if(listImgInfo.size() >= 3){
        isImgUpdate = true;
        delete m_Img;

        m_Img = listImgInfo.at(0).pImg;
        listImgInfo.removeAt(0);

        QSGTexture *t = window()->createTextureFromImage(*m_Img);

        if (t != nullptr) {

            QSGTexture *tt = oldTexture->texture();
            if (tt) {
                tt->deleteLater();
            }
            oldTexture->setRect(boundingRect());
            oldTexture->setTexture(t);
        }

        return oldTexture;
    }else{


        if(!isImgUpdate){

            isImgUpdate = true;

            QSGTexture *t = window()->createTextureFromImage(*m_Img);

            if (t != nullptr) {

                QSGTexture *tt = oldTexture->texture();
                if (tt) {
                    tt->deleteLater();
                }
                oldTexture->setRect(boundingRect());
                oldTexture->setTexture(t);
            }
        }else
            oldTexture->setRect(boundingRect());

        return oldTexture;

    }
    //qDebug()<<"XVideoReplay updatePaintNode thread:***";
    //实时更新纹理而不使用老的纹理 是因为老的纹理的宽高未发生变化
}

void XVideoReplay::funSendVideoData(QVariant buff1)
{

    qDebug()<<" XVideoReplay funSendVideoData";
    QImage *tmpImg = buff1.value<QImage*>();


    if (tmpImg != nullptr && (!tmpImg->isNull()))
    {

        ImageInfo1 imgInfo;
        imgInfo.pImg = tmpImg;
        //imgInfo.time = time;

        // qDebug()<<QString(__FUNCTION__) + "    "+QString::number(__LINE__) ;
        if(listImgInfo.size() < minBuffLen){

            listImgInfo.append(imgInfo);
            update();
        }else
            delete tmpImg;
    }else{
        qDebug()<<" XVideoReplay funSendVideoData "<<"没有图片信息";

    }
}


void XVideoReplay::funSendAudioData(char *buff,int len)
{


}


XVideoReplay::~XVideoReplay()
{

    ////    if(playAudioThread != nullptr)
    ////        playAudioThread->quit();

    //    if(pffmpegCodec != nullptr)
    //        pffmpegCodec->deleteLater();

}

