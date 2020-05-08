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

        jObject.insert("msgid",msgContent.toMap().value("msgid").toString());
        jObject.insert("data",jObjectData);
    }
    QJsonDocument jsDoc(jObject);


    //qDebug()<<"makeJsonPacket:"<<jsDoc;
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

    }

    return map;
}
