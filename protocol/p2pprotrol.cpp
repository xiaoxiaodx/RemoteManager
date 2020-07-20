#include "p2pprotrol.h"
#include <QJsonArray>
#include <qdebug>
P2pProtrol::P2pProtrol(QObject *parent) : QObject(parent)
{

}


QByteArray P2pProtrol::makeJsonPacket(QString cmd,QVariant msgContent)
{
    QJsonObject jObject;
    jObject.insert("cmd",cmd);
    jObject.insert("method","request");
    jObject.insert("msgid","0123");
    jObject.insert("sessionid",sessionid);
    if(cmd.compare("login")==0){

        QJsonObject jObjectData ;
        jObjectData.insert("username",msgContent.toMap().value("username").toString());
        jObjectData.insert("password",msgContent.toMap().value("password").toString());

        jObject.insert("data",jObjectData);

    }else if (cmd.compare("setptzmove")==0) {

        QJsonObject jObjectData ;
        jObjectData.insert("movecmd",msgContent.toMap().value("movecmd").toString());
        jObjectData.insert("direction",msgContent.toMap().value("direction").toString());
        jObjectData.insert("speedx",msgContent.toMap().value("speedx").toInt());
        jObjectData.insert("speedy",msgContent.toMap().value("speedy").toInt());
        jObjectData.insert("speedz",msgContent.toMap().value("speedz").toInt());
        jObjectData.insert("posx",msgContent.toMap().value("posx").toInt());
        jObjectData.insert("posy",msgContent.toMap().value("posy").toInt());
        jObjectData.insert("posz",msgContent.toMap().value("posz").toInt());

        jObject.insert("data",jObjectData);

    }else if(cmd.compare("setptzhomepoint")==0){//不需要填充参数



    }else if(cmd.compare("setmotiondetectparam")==0){
        QJsonObject jObjectData ;
        jObjectData.insert("enable",msgContent.toMap().value("enable").toInt());
        jObjectData.insert("sensitive",msgContent.toMap().value("sensitive").toInt());

        QJsonObject jObjectDataTimesection ;
        jObjectDataTimesection.insert("enabled",msgContent.toMap().value("enabled").toInt());
        jObjectDataTimesection.insert("starttime",msgContent.toMap().value("starttime").toString());
        jObjectDataTimesection.insert("endtime",msgContent.toMap().value("endtime").toString());

        jObjectData.insert("timesection",jObjectDataTimesection);
        jObject.insert("data",jObjectData);

    }else if(cmd.compare("getmotiondetectparam")==0){//获取移动帧参数，不需要填参


    }else if (cmd.compare("getvideoencodeparam")==0) {
        QJsonObject jObjectData ;
        jObjectData.insert("chn",0);
        jObjectData.insert("streamid",0);
        jObject.insert("data",jObjectData);
    }else if (cmd.compare("setvideoencodeparam")==0) {

        QJsonObject jObjectData ;
        jObjectData.insert("chn",msgContent.toMap().value("chn").toInt());
        jObjectData.insert("streamid",msgContent.toMap().value("streamid").toInt());
        jObjectData.insert("framerate",msgContent.toMap().value("framerate").toInt());
        jObjectData.insert("bitrate",msgContent.toMap().value("bitrate").toInt());
        jObjectData.insert("quality",msgContent.toMap().value("quality").toInt());
        jObjectData.insert("cvbrmode",msgContent.toMap().value("cvbrmode").toString());
        jObjectData.insert("encoding",msgContent.toMap().value("encoding").toString());
        jObjectData.insert("h264profile",msgContent.toMap().value("h264profile").toString());

        QJsonObject jObjecResolution;
        jObjecResolution.insert("width",msgContent.toMap().value("width").toInt());
        jObjecResolution.insert("height",msgContent.toMap().value("height").toInt());

        jObjectData.insert("resolution",jObjecResolution);
        jObject.insert("data",jObjectData);
    }else if (cmd.compare("getaudioencodeparam")==0) {


    }else if (cmd.compare("setptzpreset")==0) {//deviceName:deviceName


        QJsonObject jObjectData ;
        jObjectData.insert("presetname",msgContent.toMap().value("presetname").toString());
        jObject.insert("msgid",msgContent.toMap().value("name").toString());
        jObject.insert("data",jObjectData);
    }else if (cmd.compare("getptzpreset")==0) {


    }else if (cmd.compare("gotoptzpreset")==0) {
        QJsonObject jObjectData ;
        jObjectData.insert("presetid",msgContent.toMap().value("presetid").toString());

        jObject.insert("msgid",msgContent.toMap().value("name").toString());
        jObject.insert("data",jObjectData);

    }else if (cmd.compare("removeptzpreset")==0) {
        QJsonObject jObjectData ;
        jObjectData.insert("presetid",msgContent.toMap().value("presetid").toString());
        jObject.insert("msgid",msgContent.toMap().value("name").toString());
        jObject.insert("data",jObjectData);

    }else if (cmd.compare("getrecordinginfo")==0) {//msgid当时间来使用

        QJsonObject jObjectData ;
        jObjectData.insert("method",msgContent.toMap().value("method").toInt());
        jObjectData.insert("time",msgContent.toMap().value("time").toString());
        jObject.insert("msgid",msgContent.toMap().value("time").toString());
        jObject.insert("data",jObjectData);
    }else if(cmd.compare("setosdparam") == 0){

        QJsonObject jObjectData ;

        bool isShowName = msgContent.toMap().value("swithNameShow").toBool();
        bool isShowTime = msgContent.toMap().value("swithTimeShow").toBool();


        QJsonObject jobjectName;
        jobjectName.insert("enabled",isShowName?1:0);
        if(msgContent.toMap().contains("osdname")){
            jobjectName.insert("text",msgContent.toMap().value("osdname").toString());
        }
        QJsonObject jobjectTime;
        jobjectTime.insert("enabled",isShowTime?1:0);

        jObjectData.insert("channeltitle",jobjectName);
        jObjectData.insert("time",jobjectTime);

        jObject.insert("data",jObjectData);

    }else if(cmd.compare("setrecordparam")==0){
        QJsonObject jObjectData ;
        QJsonObject jObjectTime ;
        QJsonObject jObjectTimesection;
        jObjectTimesection.insert("cycle",msgContent.toMap().value("cycle").toInt());
        QString starttime = msgContent.toMap().value("starttime").toString();
        QString endtime = msgContent.toMap().value("endtime").toString();
        starttime.replace(":","");
        endtime.replace(":","");
        jObjectTimesection.insert("starttime",starttime);
        jObjectTimesection.insert("endtime",endtime);
        jObjectTime.insert("alldayenabled",msgContent.toMap().value("alldayenabled").toInt());
        jObjectTime.insert("timesection",jObjectTimesection);

        jObjectData.insert("clarity",msgContent.toMap().value("clarity").toInt());
        jObjectData.insert("time",jObjectTime);

        jObject.insert("data",jObjectData);
    }else if(cmd.compare("setrtmpinfo")==0){

        QJsonObject jObjectData ;
        bool enable = msgContent.toMap().value("enable").toBool();
        int resolution = msgContent.toMap().value("chn").toInt();
        QString uri = msgContent.toMap().value("streamurl").toString();
        QString username = msgContent.toMap().value("username").toString();
        QString password = msgContent.toMap().value("password").toString();

        jObjectData.insert("streamurl",uri);
        jObjectData.insert("username",username);
        jObjectData.insert("password",password);
        jObjectData.insert("chn",resolution);
        jObjectData.insert("enable",enable?1:0);

        jObject.insert("data",jObjectData);

    }else if(cmd.compare("setntpparam") == 0){

        QJsonObject jObjectData ;
        bool enable = msgContent.toMap().value("ntpenabled").toBool();
        QString ntpser = msgContent.toMap().value("ntpser").toString();

        jObjectData.insert("ntpenabled",enable?1:0);
        jObjectData.insert("ntpser",ntpser);

        jObject.insert("data",jObjectData);

    }else if(cmd.compare("setcurrenttime") == 0){

        QJsonObject jObjectData ;
        int timezone = msgContent.toMap().value("timezone").toInt();


        //jObjectData.insert("QJsonObject",);


        jObject.insert("data",jObjectData);

    }else if(cmd.compare("setiradinfo") == 0){

        QJsonObject jObjectData ;
        bool isWarn = msgContent.toMap().value("switchWarn").toBool();
        double warnTemp = msgContent.toMap().value("warnTemp").toDouble();
        int tempdrift = msgContent.toMap().value("tempdrift").toInt();
        int tempcontrol = msgContent.toMap().value("tempcontrol").toInt();
        QJsonObject jobjectalarmparam;
        jobjectalarmparam.insert("enabled",isWarn?1:0);
        jobjectalarmparam.insert("alarmtemp",warnTemp);

        QJsonObject jobjectctrlparam;
        jobjectctrlparam.insert("tempdrift",tempdrift);
        jobjectctrlparam.insert("tempcontrol",tempcontrol);


        jObjectData.insert("alarmparam",jobjectalarmparam);
        jObjectData.insert("ctrlparam",jobjectctrlparam);


        jObject.insert("data",jObjectData);

    }else if(cmd.compare("setalarmparam") == 0){

        QJsonObject jObjectData ;

        if(msgContent.toMap().contains("alarmaudiooutenabled")){

            bool alarmaudiooutenabled = msgContent.toMap().value("alarmaudiooutenabled").toBool();

            jObjectData.insert("alarmaudiooutenabled",alarmaudiooutenabled?1:0);
        }
        if(msgContent.toMap().contains("alarmrecordenabled")){

            jObjectData.insert("alarmrecordenabled",msgContent.toMap().value("alarmrecordenabled").toInt());

        }
        jObject.insert("data",jObjectData);

    }
    QJsonDocument jsDoc(jObject);


    qDebug()<<"makeJsonPacket:"<<jsDoc;
    return jsDoc.toJson();
}
QMap<QString,QVariant> P2pProtrol::unJsonPacket(QByteArray &arr)
{
    QMap<QString,QVariant> map;

    QJsonDocument jsDoc = QJsonDocument::fromJson(arr.data());

    qDebug()<<"unJsonPacket:"<<jsDoc;
    QString cmd = jsDoc.object().value("cmd").toString();
    map.insert("cmd",cmd);
    map.insert("msgid",jsDoc.object().value("msgid"));
    map.insert("statuscode",jsDoc.object().value("statuscode").toInt());

    if(cmd.compare("login")==0){

        QJsonObject jObjectData = jsDoc.object().value("data").toObject();
        sessionid = jObjectData.value("sessionid").toString();

    }else if(cmd.compare("getmotiondetectparam")==0){

        QJsonObject jObjectData = jsDoc.object().value("data").toObject();

        map.insert("enable",jObjectData.value("enabled").toInt());
        map.insert("sensitive",jObjectData.value("sensitive").toInt());

        QJsonObject jobject1 = jObjectData.value("timesection").toObject();

        map.insert("enabled",jobject1.value("enabled").toInt());
        map.insert("starttime",jobject1.value("starttime").toString());
        map.insert("endtime",jobject1.value("endtime").toString());

    }else if(cmd.compare("setptzmove")==0){
        //不需要填充参数


    }else if(cmd.compare("getvideoencodeparam")==0){//获取视频参数
        QJsonObject jObjectData = jsDoc.object().value("data").toObject();

        map.insert("chn",jObjectData.value("chn").toInt());
        map.insert("streamid",jObjectData.value("streamid").toInt());
        map.insert("framerate",jObjectData.value("framerate").toInt());
        map.insert("bitrate",jObjectData.value("bitrate").toInt());
        map.insert("quality",jObjectData.value("quality").toInt());
        map.insert("cvbrmode",jObjectData.value("cvbrmode").toString());
        map.insert("gop",jObjectData.value("gop").toInt());
        map.insert("encoding",jObjectData.value("encoding").toString());
        map.insert("h264profile",jObjectData.value("h264profile").toString());

        QJsonObject jobject1 = jObjectData.value("resolution").toObject();

        map.insert("width",jobject1.value("width").toInt());
        map.insert("height",jobject1.value("height").toInt());

    }else if (cmd.compare("getaudioencodeparam")==0) {
        QJsonObject jObjectData = jsDoc.object().value("data").toObject();

        map.insert("enabled",jObjectData.value("enabled").toInt());
        map.insert("encoding",jObjectData.value("encoding").toString());
        map.insert("bitrate",jObjectData.value("bitrate").toInt());
        map.insert("samplerate",jObjectData.value("samplerate").toInt());
    }else if(cmd.compare("getptzpreset")==0){

        QJsonObject jObjectData = jsDoc.object().value("data").toObject();

        QJsonObject jObjectData1 = jObjectData.value("presets").toObject();

        QJsonArray jarr = jObjectData1.value("preset").toArray();

        QVariantList vlist ;
        for (int i=0;i<jarr.size();i++) {

            QJsonValue jvalue = jarr.at(i);

            QString presetname = jvalue.toObject().value("presetname").toString();
            QString presetid = jvalue.toObject().value("presetid").toString();

            QJsonObject jobjectPos = jvalue.toObject().value("position").toObject();
            int x = jobjectPos.value("x").toInt();
            int y = jobjectPos.value("y").toInt();
            int z = jobjectPos.value("z").toInt();

            QVariantMap preset;
            preset.insert("presetname",presetname);
            preset.insert("presetid",presetid);
            preset.insert("x",x);
            preset.insert("y",y);
            preset.insert("y",z);

            vlist.append(preset);
        }
        map.insert("presets",vlist);


    }else if(cmd.compare("gotoptzpreset")==0){

        map.insert("name",jsDoc.object().value("msgid"));

    }else if(cmd.compare("removeptzpreset")==0){

        map.insert("name",jsDoc.object().value("msgid"));
    }else if(cmd.compare("setptzpreset")==0){

        map.insert("name",jsDoc.object().value("msgid"));

    }else if (cmd.compare("getrecordinginfo")==0){//msgid当时间来使用
        QJsonObject jObjectData = jsDoc.object().value("data").toObject();

        QVariantList listRecord;

        if(jObjectData.contains("mounthInfo")){
            map.insert("infoType","mounthInfo");
            QString dataStr = jObjectData.value("mounthInfo").toString();

            for(int i=0;i<dataStr.length();i++)
                listRecord.append(dataStr.at(i));

            map.insert("data",listRecord);
        }else if (jObjectData.contains("dayInfo")) {
            map.insert("infoType","dayInfo");
            QString dataStr = jObjectData.value("dayInfo").toString();

            for(int i=0;i<dataStr.length();i++)
                listRecord.append(dataStr.at(i));

            map.insert("data",listRecord);
        }else if (jObjectData.contains("hourInfo")) {
            map.insert("infoType","hourInfo");
            QString dataStr = jObjectData.value("hourInfo").toString();

            for(int i=0;i<dataStr.length();i++)
                listRecord.append(dataStr.at(i));

            map.insert("data",dataStr);

        }else {
            map.insert("infoType","");
        }
        map.insert("time",jsDoc.object().value("msgid").toString());

    }else if(cmd.compare("getosdparam") == 0){
        QJsonObject jObjectData = jsDoc.object().value("data").toObject();
        if(jObjectData.value("channeltitle").toObject().value("enabled").toInt() > 0)
            map.insert("osdNameShowSwitch",true);
        else
            map.insert("osdNameShowSwitch",false);


        if(jObjectData.value("time").toObject().value("enabled").toInt() > 0)
            map.insert("osdTimeShowSwitch",true);
        else
            map.insert("osdTimeShowSwitch",false);

        map.insert("osdName",jObjectData.value("channeltitle").toObject().value("text").toString());

    }else if(cmd.compare("getrecordparam") == 0){

        QJsonObject jObjectData = jsDoc.object().value("data").toObject();



        map.insert("recordStartT",jObjectData.value("time").toObject().value("timesection").toObject().value("starttime").toString().insert(4,":").insert(2,":"));
        map.insert("recordEndT",jObjectData.value("time").toObject().value("timesection").toObject().value("endtime").toString().insert(4,":").insert(2,":"));

        map.insert("recordResolution",jObjectData.value("clarity").toInt());

        if(jObjectData.value("time").toObject().value("alldayenabled").toInt() > 0){
            map.insert("recordType",2);
        }else {
            map.insert("recordType",0);
        }

        if(jObjectData.value("time").toObject().value("alldayenabled").toInt() > 0){
            map.insert("recordWeeklyDate","1111111");
        }else {
            int cycle = jObjectData.value("time").toObject().value("timesection").toObject().value("cycle").toInt();

            int zhou1 = cycle & 0x00000001;
            int zhou2 = cycle & 0x00000002;
            int zhou3 = cycle & 0x00000004;
            int zhou4 = cycle & 0x00000008;
            int zhou5 = cycle & 0x00000010;
            int zhou6 = cycle & 0x00000020;
            int zhou7 = cycle & 0x00000040;
            QString string = "";
            if(zhou1>0)
                string.append("1");
            else
                string.append("0");

            if(zhou2>0)
                string.append("1");
            else
                string.append("0");
            if(zhou3>0)
                string.append("1");
            else
                string.append("0");
            if(zhou4>0)
                string.append("1");
            else
                string.append("0");
            if(zhou5>0)
                string.append("1");
            else
                string.append("0");
            if(zhou6>0)
                string.append("1");
            else
                string.append("0");
            if(zhou7>0)
                string.append("1");
            else
                string.append("0");

            map.insert("recordWeeklyDate",string);
            qDebug()<<" 星期:"<<string;
        }


    }else if(cmd.compare("getalarmparam") == 0){
        QJsonObject jObjectData = jsDoc.object().value("data").toObject();

        map.insert("alarmrecordenabled",jObjectData.value("alarmrecordenabled").toInt());


    }else if(cmd.compare("getntpparam") == 0){

        QJsonObject jObjectData = jsDoc.object().value("data").toObject();

        if(jObjectData.value("ntpenabled").toInt() > 0)
            map.insert("timeNtpSwtich",true);
        else
            map.insert("timeNtpSwtich",false);
        map.insert("timeNtpUrl",jObjectData.value("ntpser").toString());
    }else if(cmd.compare("getcurrenttime") == 0){
        QJsonObject jObjectData = jsDoc.object().value("data").toObject();

        map.insert("timeZone",jObjectData.value("timezone").toString());


    }else if(cmd.compare("getrtmpinfo") == 0){

        QJsonObject jObjectData = jsDoc.object().value("data").toObject();

        if(jObjectData.value("abrenable").toInt() > 0 )
            map.insert("rtmpSwitch",true);
        else
            map.insert("rtmpSwitch",false);

        map.insert("rtmpUrl",jObjectData.value("servaddr").toString()+jObjectData.value("streamurl").toString());
        map.insert("rtmpUser",jObjectData.value("username").toString());
        map.insert("rtmpPassword",jObjectData.value("password").toString());
        map.insert("rtmpResolution",jObjectData.value("chn").toInt());

    }else if(cmd.compare("getiradinfo") == 0){

        QJsonObject jObjectData = jsDoc.object().value("data").toObject();
        if(jObjectData.value("alarmparam").toObject().value("enable").toInt() > 0)
            map.insert("tempWarnSwitch",true);
        else
            map.insert("tempWarnSwitch",false);

        map.insert("tempWarnValue",jObjectData.value("alarmparam").toObject().value("alarmtemp").toDouble());

        map.insert("tempdriftcaplevelMin",jObjectData.value("ctrlparamlevel").toObject().value("tempdriftcaplevel").toObject().value("min").toInt());
        map.insert("tempdriftcaplevelMax",jObjectData.value("ctrlparamlevel").toObject().value("tempdriftcaplevel").toObject().value("max").toInt());
        map.insert("tempcontrolcaplevelMin",jObjectData.value("ctrlparamlevel").toObject().value("tempcontrolcaplevel").toObject().value("min").toInt());
        map.insert("tempcontrolcaplevelMax",jObjectData.value("ctrlparamlevel").toObject().value("tempcontrolcaplevel").toObject().value("max").toInt());
        map.insert("tempDrift",jObjectData.value("ctrlparam").toObject().value("tempdrift").toInt());
        map.insert("tempControlLevel",jObjectData.value("ctrlparam").toObject().value("tempcontrol").toInt());
    }else if(cmd.compare("setosdparam") == 0){

    }else if(cmd.compare("setosdparam") == 0){

    }

    return map;
}

///******参数设置的属性*******/
////OSD
//QML_PROPERTY(bool,osdIsRevise);
//QML_PROPERTY(bool,osdTimeShowSwitch)
//QML_PROPERTY(bool,osdNameShowSwitch)
//QML_PROPERTY(QString,osdName)
////录像
//QML_PROPERTY(QString,recordType)// 0 关闭,1 告警录像,2 全部录像
//QML_PROPERTY(int,recordResolution)
//QML_PROPERTY(QString,recordPath)
//QML_PROPERTY(QString,recordStartT)
//QML_PROPERTY(QString,recordEndT)
//QML_PROPERTY(QString,recordWeeklyDate)//0 代表 全选， 1-7代表周1-周日
////rtmp
//QML_PROPERTY(bool,rtmpSwitch)
//QML_PROPERTY(QString,rtmpResolution)
//QML_PROPERTY(QString,rtmpUrl)
//QML_PROPERTY(QString,rtmpUser)
//QML_PROPERTY(QString,rtmpPassword)
////时间设置
//QML_PROPERTY(bool,timeNtpSwtich)
//QML_PROPERTY(QString,timeNtpUrl)
//QML_PROPERTY(QString,timeZone)
//QML_PROPERTY(bool,timeSummerSwitch)
////温度设置
//QML_PROPERTY(bool,tempWarnSwitch)
//QML_PROPERTY(float,tempWarnValue)
//QML_PROPERTY(bool,tempScreenShot)
//QML_PROPERTY(QString,tempScreenShotPath)
//QML_PROPERTY(bool,tempBeerSwitch)
//QML_PROPERTY(float,tempDrift)
//QML_PROPERTY(float,tempControlLevel)
