#ifndef REPLAYTIMELINE_H
#define REPLAYTIMELINE_H

#include <QTime>
#include <QMap>
#include <QList>
#include <QQuickPaintedItem>
#include "replaydatesearch.h"

class ReplayTimeline : public QQuickPaintedItem
{
    Q_OBJECT


public:
    explicit ReplayTimeline();
    ~ReplayTimeline();

    Q_INVOKABLE void setSizeType(int type);
    Q_INVOKABLE void setTimeWarn(QVariant timeInfo);
    Q_INVOKABLE int getIndicatorTime();
    Q_INVOKABLE void updateDate(QString relativePath,QString date);
    Q_INVOKABLE void indicatorTimeUpdate(long long pts);
    Q_INVOKABLE void replaytimeSlowOrFast(int sec);

    Q_INVOKABLE void resetParameter();
    void init();
    void setDate(QDate date);

signals:
    void indicatorTimeChange(QString curTime);
public slots:
    void slot_24hSelect();
    void slot_2hSelect();
    void slot_1hSelect();
    void slot_30mSelect();
protected:
    void paint(QPainter *painter);

    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);


private:
    void initTimeLineInterval();
    //在指定区间链表中寻找包含指定时间的区间
    TimeInterval *findInterval(QList<TimeInterval*> &list,QTime &time);

    void drawBg(QPainter *painter);
    void drawScale(QPainter *painter,IntervalType type);
    void drawValue(QPainter *painter);
    qreal getsecsPerPix();
    IntervalType currentScaleType = TIMELINE24H;//刻度类型

    QTime replayCurrentTime;
    QList<TimeInterval*> listTimeInterval24H;
    QList<TimeInterval*> listTimeInterval2H;
    QList<TimeInterval*> listTimeInterval1H;
    QList<TimeInterval*> listTimeInterval30M;

    //4个不同类型的录像区间链表
    QList<TimeInterval*> listVideoInterval1;
    QList<TimeInterval*> listVideoInterval2;
    QList<TimeInterval*> listVideoInterval3;
    QList<TimeInterval*> listVideoInterval4;


    QList<TimeInterval*> drawListInterval;

    void appendTime(QString startT,QString longt);
    void removeTime();
    void mergeTimeInterval(QTime startT,int timeLen,int videoType);
    QRectF rectFIndicator;
    bool isIndicatorPress = false;
    QPoint pressPt;

    long long prePts = 0;
    bool ptsUpdateFirst = false;
};

#endif // REPLAYTIMELINE_H
