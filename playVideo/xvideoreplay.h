#ifndef XVideoREPLAY_H
#define XVideoREPLAY_H
#include <QQuickPaintedItem>
#include <QImage>
#include <QList>
#include <QTimer>
#include <QAudioFormat>
#include <QAudioDeviceInfo>
#include <QAudioOutput>
#include <QSGSimpleTextureNode>
#include <QDateTime>
#include <QDir>

#include <QQuickWindow>
//#include "tcpworker.h"
#include "playaudio.h"
//#include "dispatchmsgmanager.h"
//#include "p2pworker.h"
//#include "mp4format.h"
#include "ffmpegcodec.h"
//#include "avirecord.h"


class ImageInfo1{

public:
    QImage *pImg;
    quint64 time;
};
class XVideoReplay : public QQuickItem
{
    Q_OBJECT
public:



    Q_INVOKABLE void funSendVideoData(QVariant buff);
    Q_INVOKABLE void funSendAudioData(char *buff,int len);




    explicit XVideoReplay();
    ~XVideoReplay();

signals:


public slots:


protected:
    QSGNode* updatePaintNode(QSGNode *old, UpdatePaintNodeData *);
private:



    void writeDebugfile(QString filename,QString funname,int lineCount,QString strContent);


    FfmpegCodec *pffmpegCodec;


    PlayAudio *playAudio;
    QThread *playAudioThread;


    QTimer timerUpdate;

    QList<ImageInfo1> listImgInfo;
    QImage *m_Img;


    bool isImgUpdate = false;

    int minBuffLen = 15;

    bool isPlayAudio;
    bool isRecord;
    bool isStartRecord;//是否启动录像
    bool isScreenShot;
    bool isAudioFirstPlay;
    bool isFirstData;

    quint64 preAudioTime;
    static int testIdIndex;
    int testID;
};
#endif // XVideoReplayREPLAY_H
