#include "replaytimeline.h"
#include <QPainter>
#include <QDateTime>
#include <QDebug>
#include <QDir>
#include <QString>
ReplayTimeline::ReplayTimeline()
{

    replayCurrentTime.setHMS(0,0,0);

    setAcceptHoverEvents(true);
    setAcceptedMouseButtons(Qt::AllButtons);
    setFlag(ItemAcceptsInputMethod, true);

    rectFIndicator.setX(30);
    rectFIndicator.setY(34);
    rectFIndicator.setWidth(4);
    rectFIndicator.setHeight(20);
    init();
}
ReplayTimeline::~ReplayTimeline()
{

}

void ReplayTimeline::init()
{
    initTimeLineInterval();
}


void ReplayTimeline::slot_24hSelect()
{
    currentScaleType = TIMELINE24H;
    this->update();
}
void ReplayTimeline::slot_2hSelect()
{
    currentScaleType = TIMELINE2H;
    this->update();
}
void ReplayTimeline::slot_1hSelect()
{
    currentScaleType = TIMELINE1H;
    this->update();
}
void ReplayTimeline::slot_30mSelect()
{
    currentScaleType = TIMELINE30M;
    this->update();
}

void ReplayTimeline::initTimeLineInterval()
{
    {
        TimeInterval *timeInterval24h = new TimeInterval;
        timeInterval24h->type = TIMELINE24H;
        timeInterval24h->startTime = QTime(0,0,0);
        timeInterval24h->endTime = QTime(23,59,59,999);
        listTimeInterval24H.append(timeInterval24h);
    }
    for (int i=0;i<24;i+=2) {
        TimeInterval *timeInterval2h = new TimeInterval();
        timeInterval2h->type = TIMELINE2H;
        timeInterval2h->startTime = QTime(i,0,0);
        if(i == 22)
            timeInterval2h->endTime = QTime(i+1,59,59,999);
        else
            timeInterval2h->endTime = QTime(i+2,0,0);
        listTimeInterval2H.append(timeInterval2h);
    }

    for (int i=0;i<24;i++) {
        TimeInterval *timeInterval1h = new TimeInterval();
        timeInterval1h->type = TIMELINE1H;
        timeInterval1h->startTime = QTime(i,0,0);
        if(i==23)
            timeInterval1h->endTime = QTime(i,59,59,999);
        else
            timeInterval1h->endTime = QTime(i+1,0,0);
        listTimeInterval1H.append(timeInterval1h);
    }

    //一个小时中有2个区间
    for (int i=0;i<24;i++) {
        TimeInterval *timeInterval30m1 = new TimeInterval();
        timeInterval30m1->type = TIMELINE30M;
        timeInterval30m1->startTime = QTime(i,0,0);
        timeInterval30m1->endTime = QTime(i,30,0);
        listTimeInterval30M.append(timeInterval30m1);

        TimeInterval *timeInterval30m2 = new TimeInterval;
        timeInterval30m2->type = TIMELINE30M;
        timeInterval30m2->startTime = QTime(i,30,0);
        if(i==23)
            timeInterval30m2->endTime = QTime(i,59,59,999);
        else
            timeInterval30m2->endTime = QTime(i+1,0,0);
        listTimeInterval30M.append(timeInterval30m2);
    }
}

TimeInterval* ReplayTimeline::findInterval(QList<TimeInterval*> &list,QTime &time)
{
    // qDebug()<<"当前值："<<time.toString("hh:mm:ss");
    for (int i=0;i<list.size();i++) {
        TimeInterval *timeI = list.at(i);
        QTime tmpStart = timeI->startTime;
        QTime tmpEnd = timeI->endTime;
        //qDebug()<<"区间值:"<<tmpStart.toString("hh:mm:ss")<<" "<<tmpEnd.toString("hh:mm:ss");
        if(time>= tmpStart && time<=tmpEnd)
            return timeI;
    }

    return  NULL;
}

void ReplayTimeline::paint(QPainter *painter)
{

    painter->setRenderHint(QPainter::Antialiasing);   //线条抗锯齿
    painter->setRenderHint(QPainter::TextAntialiasing);


    drawBg(painter);

}

void ReplayTimeline::drawBg(QPainter *painter){
    //时间轴所在的矩形
    QRectF rectTimeLine(30,34,this->width()-60,this->height()-54);
    //绘制大背景
    painter->setPen(QPen(QColor("#252525"),1));
    painter->setBrush(QBrush(QColor("#252525")));
    painter->drawRect(0,41,1920,113);

    //绘制时间轴背景
    painter->save();
    painter->setBrush(QBrush(QColor("#FFFFFF")));
    painter->drawRect(rectTimeLine);
    painter->restore();

    //绘制刻度
    drawScale(painter,currentScaleType);

}

void ReplayTimeline::setSizeType(int type)
{
    if(type == 0){
        currentScaleType = TIMELINE24H;
    }else if(type == 1)
        currentScaleType = TIMELINE2H;
    else if(type == 2)
        currentScaleType= TIMELINE1H;
    else if(type == 3)
        currentScaleType = TIMELINE30M;
    update();
}

void ReplayTimeline::drawScale(QPainter *painter,IntervalType type)
{
    //时间轴所在的矩形
    QRectF rectTimeLine(30,34,this->width()-60,this->height()-54);

    int splictlineCount ;
    qreal contentWidth ;
    //字体
    QFont newFont;
    newFont.setPixelSize(14);
    newFont.setFamily("Microsoft Yahei");
    QFontMetrics fontMetrics(newFont);
    painter->setFont(newFont);
    splictlineCount = 24-1;
    contentWidth = (rectTimeLine.width()-splictlineCount) / 24;

    TimeInterval *timeInterval = NULL;
    qreal valuePerScale;
    int markInterval;

    //在这里获取：回放时间点所在的区间，区间的起始位置，每刻度的长度（单位分钟）,每隔几个刻度显示一次标注
    if(type == TIMELINE24H){
        timeInterval = findInterval(listTimeInterval24H,replayCurrentTime);
        valuePerScale = 60;
        markInterval = 1;
    }else if (type == TIMELINE2H) {
        timeInterval = findInterval(listTimeInterval2H,replayCurrentTime);
        valuePerScale = 5;
        markInterval = 1;
    }else if (type == TIMELINE1H) {
        timeInterval = findInterval(listTimeInterval1H,replayCurrentTime);
        valuePerScale = 2.5;
        markInterval = 2;
    }else if (type == TIMELINE30M) {
        timeInterval = findInterval(listTimeInterval30M,replayCurrentTime);
        valuePerScale = 1.25;
        markInterval = 4;
    }

    if(timeInterval == NULL){
        qDebug()<<"未找到指定区间";
        return;
    }


    //绘制背景刻度
    QTime startT = timeInterval->startTime;
    for (int num = 0;num<25;num++) {
        qreal linex = rectTimeLine.x() + (contentWidth+1)*num;
        painter->drawLine(QPointF(linex,rectTimeLine.y()),QPointF(linex,rectTimeLine.y()+rectTimeLine.height()));

        if(num % markInterval != 0)
            continue;
        painter->save();
        painter->setPen(QPen(QColor("#ffffff"),1));
        //每刻度1.25分钟

        int min = num*valuePerScale;
        QTime desTime = startT.addSecs(min*60);
        QTime time0(0,0,0,0);
        int startSec = time0.secsTo(startT);
        QString showtimeStr = desTime.toString("hh:mm");

        if((startSec + min*60) == 24*3600)
            showtimeStr = "24:00";

       // qDebug()<<"desTime  "<<desTime;
        QRect rect = fontMetrics.boundingRect(showtimeStr);
        painter->drawText(linex - rect.width()/2,rectTimeLine.y()-10,showtimeStr);
        painter->restore();
    }

    qreal secsPerPix = getsecsPerPix();

    //绘制平铺图
    QTime endT = timeInterval->endTime;
    painter->save();
    painter->setPen(Qt::NoPen);
    for(int i=0;i<drawListInterval.size();i++){

        TimeInterval *timeInterval = drawListInterval.at(i);
        QTime tileTimeStart = timeInterval->startTime;
        QTime tileEndStart = timeInterval->endTime;
        //qDebug()<<" time ***:"<<tileTimeStart<<"    "<<  tileEndStart;

        qreal leftX;
        qreal rightX;
        //区间 在当前显示的时间范围内
        if(tileTimeStart.secsTo(startT)<=0 && tileEndStart.secsTo(endT)>=0){

            leftX = startT.secsTo(tileTimeStart)/secsPerPix;
            rightX = startT.secsTo(tileEndStart)/secsPerPix;
             //qDebug()<<"包含  "<<leftX<<" "<<rightX;
        }
        //区间 与当前显示的时间范围 左相交
        else if(tileTimeStart.secsTo(startT)>=0 && tileEndStart.secsTo(startT)<=0  && tileEndStart.secsTo(endT)>=0 ){
            leftX = 0;
            rightX = startT.secsTo(tileEndStart)/secsPerPix;
            // qDebug()<<"左相交  "<<leftX<<" "<<rightX;
        }
        //区间 与当前显示的时间范围 右相交
        else if(tileTimeStart.secsTo(startT)<=0 && tileTimeStart.secsTo(endT)>=0 && tileEndStart.secsTo(endT)<=0){
            leftX = startT.secsTo(tileTimeStart)/secsPerPix;
            rightX = startT.secsTo(endT)/secsPerPix;
        //     qDebug()<<"右相交  "<<leftX<<" "<<rightX;
        }else {
            continue;
        }

        QRectF tmpRectF;
        tmpRectF.setX(leftX+30);
        tmpRectF.setY(34);
        tmpRectF.setWidth(rightX - leftX);
        tmpRectF.setHeight(20);
        if(timeInterval->type == VIDEONORMAL)
            painter->fillRect(tmpRectF,QBrush(QColor(255,97,73)));
        else if(timeInterval->type == VIDEOALARM)
            painter->fillRect(tmpRectF,QBrush(QColor(137,160,255)));
    }
    painter->restore();
    //绘制指示器
    int timeFromStart = startT.secsTo(replayCurrentTime);
    int dpix = (qreal)timeFromStart/secsPerPix;
    //  qDebug()<<"replayCurrentTime:"<<replayCurrentTime.fromMSecsSinceStartOfDay(<<"    startT:"<<startT;
    //qDebug()<<"replayCurrentTime:"<<replayCurrentTime<<"    startT:"<<startT;
    //qDebug()<<"timeFromStart:"<<timeFromStart<<"    secsPerPix:"<<secsPerPix;

    qreal resX = dpix + 30;
    qreal resY = rectFIndicator.y();
    qreal resW = rectFIndicator.width();
    qreal resH = rectFIndicator.height();
    rectFIndicator.setRect(resX,resY,resW,resH);
    painter->fillRect(rectFIndicator,QBrush(QColor(255,0,0)));


    painter->setPen(QColor(255,0,0));
    QString indicatortimeStr = replayCurrentTime.toString("hh:mm:ss");

    //字体
    QFont newFont1;
    newFont1.setPixelSize(8);
    newFont1.setFamily("Microsoft Yahei");
    QFontMetrics fontMetrics1(newFont1);
    QRect rect1 = fontMetrics1.boundingRect(indicatortimeStr);
    painter->drawText(rectFIndicator.x() - rect1.width()/2,rectFIndicator.y()+rectFIndicator.height()+5+rect1.height(),indicatortimeStr);
    //drawValue(painter);
}


void ReplayTimeline::drawValue(QPainter *painter)
{

    //painter->setPen(QPen(QBrush(QColor(255,0,0)),1));
    ;

}

int ReplayTimeline::getIndicatorTime()
{

    qDebug()<<"cureent time :"<<replayCurrentTime;

}

void ReplayTimeline::resetParameter()
{

    removeTime();
    replayCurrentTime.setHMS(0,0,0);
    update();
}

void ReplayTimeline::setDate(QDate date)
{

}

void ReplayTimeline::mousePressEvent(QMouseEvent* event){


    if(rectFIndicator.contains(event->pos())){
        //qDebug()<<  "mousePressEvent "<<rectFIndicator;
        isIndicatorPress = true;
        pressPt = event->pos();
        update();
    }

}
void ReplayTimeline::mouseMoveEvent(QMouseEvent *event){


}
qreal ReplayTimeline::getsecsPerPix()
{
    qreal totalInterval = this->width()-60;//时间总像素宽度
    qreal secsPerPix; //每个像素是多少秒
    if(currentScaleType == TIMELINE24H){
        secsPerPix = 24*60*60/totalInterval;
    }else if(currentScaleType == TIMELINE2H){
        secsPerPix = 2*60*60/totalInterval;
    }else if(currentScaleType == TIMELINE1H){
        secsPerPix = 60*60/totalInterval;
    }else if(currentScaleType == TIMELINE30M){
        secsPerPix = 30*60/totalInterval;
    }
    return secsPerPix;
}


void ReplayTimeline::replaytimeSlowOrFast(int sec)
{
    replayCurrentTime = replayCurrentTime.addSecs(sec);
    emit indicatorTimeChange(replayCurrentTime.toString("hh:mm:ss"));;
    //update();
}

void ReplayTimeline::mouseReleaseEvent(QMouseEvent *event){
    if(isIndicatorPress){
        // qDebug()<<  "mouseReleaseEvent "<<rectFIndicator;
        qreal dx = event->x() - pressPt.x();
        isIndicatorPress = false;
        qreal secsPerPix = getsecsPerPix();
        int dSecs = (int)(secsPerPix * dx);


        replayCurrentTime = replayCurrentTime.addSecs(dSecs);
        emit indicatorTimeChange(replayCurrentTime.toString("hh:mm:ss"));;
        update();
    }
}

void ReplayTimeline::indicatorTimeUpdate(long long pts){



    QDateTime time = QDateTime::fromTime_t(pts/1000000);//
//    qDebug()<<"pts:"<<pts<<"    ptsUpdateFirst:"<<ptsUpdateFirst;
//    if(!ptsUpdateFirst){
//        prePts = pts;
//        ptsUpdateFirst = true;
//    }

//    long long dePts = pts - prePts;



//    prePts = pts;
//    //在录像拖动的瞬间，在录像切换时间播放的瞬间，变化时间会跳变,因此忽略这次间隔
//    //时间不变 则返回
//    if(dePts == 0 ||dePts>10 || dePts <-10)
//        return;
//    //qDebug()<<"dePts:"<<dePts<<"    pts "<<pts<<"    prePts"<<prePts;
//    replayCurrentTime = replayCurrentTime.addSecs(dePts);
//    //emit indicatorTimeChange(replayCurrentTime.toString("hh:mm:ss"));

    replayCurrentTime.setHMS(time.time().hour(),time.time().minute(),time.time().second());

    update();
}


void ReplayTimeline::updateDate(QString relativePath,QString date)
{
    qDebug()<<"updateDate:"<<relativePath<<"    "<<date;

    QDir dir(relativePath+"/"+date);

    if(!dir.exists()){

        qDebug()<<"文件路径不存在";
    }
    //设置文件过滤器
    QStringList nameFilters;
    //设置文件过滤格式
    nameFilters << "*.yuv";

    QStringList files = dir.entryList(nameFilters, QDir::Files|QDir::Readable, QDir::Name);

    removeTime();
    for (int i=0;i<files.size();i++) {
        QString tmpName = files.at(i);
        QString fileName = tmpName.remove(".yuv");
        qDebug()<<"files name:"<<fileName;

        QStringList fileNames = fileName.split("_");
        if(fileNames.size() != 2)
            continue;

        QString timeStart = fileNames[0];
        QString longt = fileNames[1];
        appendTime(timeStart,longt);
    }
    update();
}
void ReplayTimeline::appendTime(QString startT,QString longt){

    int h = startT.mid(0,2).toInt();
    int m = startT.mid(2,2).toInt();
    int s = startT.mid(4,2).toInt();
    int t = longt.toInt();


    QTime time(h,m,s);
    TimeInterval *timeInterval = new TimeInterval;
    timeInterval->startTime = time;
    timeInterval->endTime = time.addSecs(t);
    timeInterval->sec = t;

    drawListInterval.append(timeInterval);
}

void ReplayTimeline::removeTime(){

    while(drawListInterval.size() >0){

        delete drawListInterval.takeFirst();
    }
}
void ReplayTimeline::mergeTimeInterval(QTime intervalStartT,int secsLen,int videoType)
{
    if(videoType > 2){
        qDebug()<<"video type is err";
        return;
    }

    bool isDataIntersect = false;

    IntervalType intervalVideotype;
    if(videoType == 0 )
        intervalVideotype = VIDEOLOSS;
    else if(videoType == 1 )
        intervalVideotype = VIDEONORMAL;
    else if(videoType == 2 )
        intervalVideotype = VIDEOALARM;

    QTime intervalEndT = intervalStartT.addSecs(secsLen);

    qDebug()<<"合并的区间:"<<intervalVideotype<<"    "<<intervalStartT.toString("hh:mm:ss")<<"    "<<intervalEndT.toString("hh:mm:ss");
    for (int j=0;j<drawListInterval.size();j++) {

        TimeInterval* timeInterval=drawListInterval.at(j);
        QTime startT = timeInterval->startTime;
        QTime endT = timeInterval->endTime;
        IntervalType type = timeInterval->type;

        //startT.msec();

        if(intervalVideotype == type){

            if(startT.secsTo(intervalStartT)<0 || endT.secsTo(intervalEndT)>0)
                continue;

            //添加区间与当前区间的左相交，则将起始时间设置为 添加区间的起始时间
            if(startT.secsTo(intervalStartT)>=0 && endT.secsTo(intervalEndT)<=0){
                timeInterval->startTime = intervalStartT;
                isDataIntersect = true;
                break;
            }
            //添加区间与当前区间的右相交，则将当前区间结束时间设置为 添加区间的结束时间
            if(startT.secsTo(intervalStartT)<=0 && endT.secsTo(intervalEndT)>=0){
                timeInterval->endTime = intervalEndT;
                isDataIntersect = true;
                break;
            }
            //添加区间 包含于当前区间，则不变
            if(startT.secsTo(intervalStartT)>=0 && endT.secsTo(intervalEndT)<=0){
                isDataIntersect = true;
                break;
            }
        }
    }
    //没有可以合并的，则额外添加一个区间
    if(!isDataIntersect){
        TimeInterval *timeinterval = new TimeInterval;
        timeinterval->startTime = intervalStartT;
        timeinterval->endTime = intervalEndT;
        timeinterval->type = intervalVideotype;
        drawListInterval.append(timeinterval);
    }
//    for (int i=0;i<drawListInterval.size();i++) {
//        TimeInterval *timeinterval = drawListInterval.at(i);
//        qDebug()<<"qujian:"<<timeinterval->startTime.toString("hh:mm:ss")<<"    "<<timeinterval->endTime.toString("hh:mm:ss");
//    }
}
//**time: "20200428230000"
//**timeinfo: QMap(("cmd", QVariant(QString, "getrecordinginfo"))
//("data", QVariant(QString,"111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111"))
//("infoType", QVariant(QString, "hourInfo"))
//("msgid", QVariant(QString, "20200428230000"))
//("statuscode", QVariant(int, 200))("time", QVariant(QString, "20200428230000")))
void ReplayTimeline::setTimeWarn(QVariant timeInfo)
{
    QString time = timeInfo.toMap().value("time").toString();
    QString timeTypeStr =  timeInfo.toMap().value("data").toString();

    qDebug()<<"setTimeWarn: time:"<<time;
    qDebug()<<"setTimeWarn: timeTypeStr:"<<timeTypeStr;
    int sendcondH = time.mid(8,2).toInt();
    //获取第一个字符
    QString preIndexStr = timeTypeStr.at(0);

    int startIndex = 0;//相同类型的一组数据的起始索引

    for(int i=1;i<timeTypeStr.size();i++){
        QString timeIndexstr = timeTypeStr.at(i);
        if(preIndexStr.compare(timeIndexstr) != 0)//当前字符与前一个不同则将之前的时间加入  区间列表
        {
            int timeType = timeIndexstr.toInt();
            int intervalLen = i - startIndex;   //相同类型的长度

            QTime timeStart(sendcondH,0,0);
            mergeTimeInterval(timeStart.addSecs(startIndex*20),intervalLen*20,preIndexStr.toInt());
            //更新索引位置  和字符
            startIndex = i;
            preIndexStr = timeIndexstr;
        }
    }

    //最后一段同类型的区间直接合并
    int intervalLen = timeTypeStr.size() - startIndex;   //相同类型的长度
    QTime timeStart(sendcondH,0,0);

    if(sendcondH == 23)//如果是23时 为了防止24:00：00计算后成为 00：00：00，故时长-1秒
        mergeTimeInterval(timeStart.addSecs(startIndex*20),intervalLen*20-1,preIndexStr.toInt());
    else
        mergeTimeInterval(timeStart.addSecs(startIndex*20),intervalLen*20,preIndexStr.toInt());
    //更新索引位置  和字符
    update();
}


