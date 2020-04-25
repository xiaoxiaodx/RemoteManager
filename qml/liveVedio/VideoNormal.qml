import QtQuick 2.0
import XVideo 1.0
import Qt.labs.settings 1.0
import QtQuick.Controls 1.4
import "../simpleControl"
Rectangle {

    id:mPlayRect
    signal doubleClick(bool isFullScreen);
    signal click();
    signal s_showToastMsg(string str)
    signal s_sendList(var vmap)

    property bool mIsSelected: false

    border.color: mIsSelected?"#98C5FF":"#252525"
    border.width: 3

    signal s_startTemWarn();
    signal s_endTemWarn();
    signal s_tempmodelSelect(var mtype);

    property int mouseAdjustWidth1: 4
    property int    wTOP:1
    property int    wBOTTOM:2
    property int    wLEFT:3
    property int    wRIGHT:4
    property int    wLEFTTOP:5
    property int    wRIGHTTOP:6
    property int    wLEFTBOTTOM:7
    property int    wRIGHTBOTTOM:8
    property int    wCenter:9
    property point mousePressPt1: "0,0"


    MouseArea{
        anchors.fill: parent
        //hoverEnabled: true
        propagateComposedEvents:true

        onClicked: {

            click()
            // mouse.accepted = false
        }
        onDoubleClicked:doubleClick(true);

    }
    XVideo{
        id:video

        //anchors.fill: parent

        width:(mPlayRect.width*0.75>mPlayRect.height?mPlayRect.height*1.333:mPlayRect.width) -6
        height: (mPlayRect.width*0.75>mPlayRect.height?mPlayRect.height:mPlayRect.width*0.75) -6

        anchors.horizontalCenter: mPlayRect.horizontalCenter
        anchors.verticalCenter: mPlayRect.verticalCenter


        Component.onCompleted:{
            //video.fun_setInitPar(deviceconfig.getTcpip(),deviceconfig.getShowParentW(),deviceconfig.getShowParentH(),deviceconfig.getShowRectX(),deviceconfig.getShowRectY(),deviceconfig.getShowRectW(),deviceconfig.getShowRectH())
            video.startNormalVideo(deviceconfig.getWarnTem())
        }



        onSignal_loginStatus: main.showToast(msg);

        onSignal_httpUiParSet:httpParCallback(map);


        Rectangle{
            id:rectadmjt
            x:deviceconfig.getShowRectX()
            y:deviceconfig.getShowRectY()
            width: deviceconfig.getShowRectW()
            height: deviceconfig.getShowRectH()
            color: "#505D9CFF"
            visible:deviceconfig.getIsOpenAdjustRect();
            MouseArea{
                id:areaTop
                x:mouseAdjustWidth1
                y:0
                width: parent.width - mouseAdjustWidth1*2
                height: mouseAdjustWidth1
                hoverEnabled: true

                onEntered: cursorShape = Qt.SizeVerCursor
                onExited: cursorShape = Qt.ArrowCursor
                onPressed:  mousePressPt1  = Qt.point(mouse.x, mouse.y)
                onPositionChanged: {

                    if(pressed){
                        var offsetX = mouse.x - mousePressPt1.x
                        var offsetY = mouse.y - mousePressPt1.y
                        adjustWindow(wTOP,0,offsetY);
                    }
                }

            }

            MouseArea{
                id:areaLeftTop
                x:0
                y:0
                width: mouseAdjustWidth1
                height: mouseAdjustWidth1
                hoverEnabled: true

                onEntered: cursorShape = Qt.SizeFDiagCursor
                onExited: cursorShape = Qt.ArrowCursor
                onPressed:  mousePressPt1  = Qt.point(mouse.x, mouse.y)
                onPositionChanged: {

                    if(pressed){
                        var offsetX = mouse.x - mousePressPt1.x
                        var offsetY = mouse.y - mousePressPt1.y
                        adjustWindow(wLEFTTOP,offsetX,offsetY);
                    }
                }

            }

            MouseArea{
                id:areaRightTop
                x:parent.width - mouseAdjustWidth1
                y:0
                width: mouseAdjustWidth1
                height: mouseAdjustWidth1
                hoverEnabled: true

                onEntered: cursorShape = Qt.SizeBDiagCursor
                onExited: cursorShape = Qt.ArrowCursor
                onPressed:  mousePressPt1  = Qt.point(mouse.x, mouse.y)
                onPositionChanged: {

                    if(pressed){
                        var offsetX = mouse.x - mousePressPt1.x
                        var offsetY = mouse.y - mousePressPt1.y
                        adjustWindow(wRIGHTTOP,offsetX,offsetY);
                    }
                }

            }

            MouseArea{
                id:areaLeft
                x:0
                y:mouseAdjustWidth1
                width: mouseAdjustWidth1
                height: parent.height - mouseAdjustWidth1
                hoverEnabled: true

                onEntered: cursorShape = Qt.SizeHorCursor
                onExited: cursorShape = Qt.ArrowCursor
                onPressed:  mousePressPt1  = Qt.point(mouse.x, mouse.y)
                onPositionChanged: {

                    if(pressed){
                        var offsetX = mouse.x - mousePressPt1.x
                        var offsetY = mouse.y - mousePressPt1.y
                        adjustWindow(wLEFT,offsetX,0);
                    }
                }

            }

            MouseArea{
                id:areaRight
                x:parent.width - mouseAdjustWidth1
                y:0
                width: mouseAdjustWidth1
                height: parent.height - mouseAdjustWidth1
                hoverEnabled: true
                onEntered: cursorShape = Qt.SizeHorCursor
                onExited: cursorShape = Qt.ArrowCursor
                onPressed:  mousePressPt1  = Qt.point(mouse.x, mouse.y)
                onPositionChanged: {


                    if(pressed){
                        var offsetX = mouse.x + mousePressPt1.x
                        var offsetY = mouse.y + mousePressPt1.y
                        adjustWindow(wRIGHT,offsetX,0);
                    }

                }
            }

            MouseArea{
                id:areaLeftBottom
                x:0
                y:parent.height - mouseAdjustWidth1
                width: mouseAdjustWidth1
                height: mouseAdjustWidth1
                hoverEnabled: true

                onEntered: cursorShape = Qt.SizeBDiagCursor
                onExited: cursorShape = Qt.ArrowCursor
                onPressed:  mousePressPt1  = Qt.point(mouse.x, mouse.y)
                onPositionChanged: {

                    if(pressed){
                        var offsetX = mouse.x - mousePressPt1.x
                        var offsetY = mouse.y - mousePressPt1.y
                        adjustWindow(wLEFTBOTTOM,offsetX,offsetY);
                    }
                    //setDlgPoint(offset.x, 0)

                }
            }

            MouseArea{
                id:areaRightBottom
                x:rectadmjt.width - mouseAdjustWidth1
                y:rectadmjt.height - mouseAdjustWidth1
                width: mouseAdjustWidth1
                height: mouseAdjustWidth1
                hoverEnabled: true

                onEntered: cursorShape = Qt.SizeFDiagCursor
                onExited: cursorShape = Qt.ArrowCursor
                onPressed:  mousePressPt1  = Qt.point(mouse.x, mouse.y)
                onPositionChanged: {

                    if(pressed){
                        var offsetX = mouse.x - mousePressPt1.x
                        var offsetY = mouse.y - mousePressPt1.y
                        adjustWindow(wRIGHTBOTTOM,offsetX,offsetY);
                    }
                    //setDlgPoint(offset.x, 0)
                }
            }

            MouseArea{
                id:areaBottom
                x:mouseAdjustWidth1
                y:parent.height - mouseAdjustWidth1
                width: parent.width - mouseAdjustWidth1*2
                height: mouseAdjustWidth1
                hoverEnabled: true

                onEntered: cursorShape = Qt.SizeVerCursor
                onExited: cursorShape = Qt.ArrowCursor
                onPressed:  mousePressPt1  = Qt.point(mouse.x, mouse.y)
                onPositionChanged: {

                    if(pressed){
                        var offsetX = mouse.x - mousePressPt1.x
                        var offsetY = mouse.y - mousePressPt1.y
                        adjustWindow(wBOTTOM,0,offsetY);
                    }
                    //setDlgPoint(offset.x, 0)

                }
            }

            MouseArea{
                id:areaCenter
                x:mouseAdjustWidth1
                y:mouseAdjustWidth1
                width: parent.width - mouseAdjustWidth1*2
                height: parent.height - mouseAdjustWidth1*2
                hoverEnabled: true
                onPressed:  mousePressPt1  = Qt.point(mouse.x, mouse.y)
                onPositionChanged: {

                    if(pressed){
                        var offsetX = mouse.x - mousePressPt1.x
                        var offsetY = mouse.y - mousePressPt1.y
                        adjustWindow(wCenter,offsetX,offsetY);
                    }
                    //setDlgPoint(offset.x, 0)

                }
            }

            Rectangle{
                id:rectEnsure
                anchors.right: rectadmjt.right
                anchors.top:rectadmjt.top
                width: 20
                height: 10
                color: "transparent"
                Image{
                    id:imgEnsure
                    width: 12
                    height: 24
                    source: "qrc:/images/adjust_ensure.png"
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {

                            video.fun_setRectPar(rectadmjt.x,rectadmjt.y,rectadmjt.width,rectadmjt.height,video.width,video.height)
                            rectadmjt.visible = false

                            deviceconfig.setRedRect(video.width,video.height,rectadmjt.x,rectadmjt.y,rectadmjt.width,rectadmjt.height)
                            deviceconfig.setIsOpenAdjustRect(false)
                        }
                    }
                }
                Image{
                    id:imgCancel
                    width: 12
                    height: 12
                    anchors.top: imgEnsure.bottom
                    anchors.left: imgEnsure.left
                    source: "qrc:/images/adjust_cancel.png"
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            rectadmjt.x = deviceconfig.getShowRectX()
                            rectadmjt.y = deviceconfig.getShowRectY()
                            rectadmjt.width = deviceconfig.getShowRectW()
                            rectadmjt.height = deviceconfig.getShowRectH()
                        }
                    }
                }
            }
        }



    }



    Connections{
        target: deviceconfig
        onS_timeSwith:video.fun_timeSwitch(mchecked);//时间使能
        onS_temSet:video.fun_temSet(mvalue);//警报温度设置


        onS_iradInfoSet:{
//            dataObj.insert("osdenable",value.value("osdenable").toInt());
//            alarmparamObj.insert("alarmtempEnable", value.value("alarmtempEnable").toInt());
//            alarmparamObj.insert("alarmtemp", value.value("alarmtemp").toDouble());
//            ctrlparamObj.insert("tempdrift", value.value("tempdrift").toInt());
//            ctrlparamObj.insert("tempcontrol", value.value("tempcontrol").toInt());
//            dataObj.insert("alarmparam", QJsonValue(alarmparamObj));
//            dataObj.insert("ctrlparam", QJsonValue(ctrlparamObj));

            video.fun_setIraInfo();
        }
    }
    //    Connections{
    //        target: videoTemp
    //        onS_sendList:video.fun_setListRect(vmap)
    //    }

    function funsetlistRect(map){
        video.fun_setListRect(map)
    }

    function funinitRedFrame(w,h){
        video.fun_initRedFrame(w,h)
    }

    function httpParCallback(smap){

        var strcmd = smap.cmd;
        console.debug("strcmd:"+strcmd)

        if(strcmd === "getosdparam"){
            var enable = smap.enable;

        }else if(strcmd === "getrecordparam"){

        }else if(strcmd === "getinftempmodel"){

            console.debug(" **************** "+smap.tempmodel)
            var enable = smap.timeenable;
            if(smap.tempmodel === "D04")
                deviceconfig.curDevTypeStr = "d04"
            else if(smap.tempmodel === "D06")
                deviceconfig.curDevTypeStr = "d06"
            else if(smap.tempmodel === "E03")
                deviceconfig.curDevTypeStr = "e03"
            else if(smap.tempmodel === "F03")
                deviceconfig.curDevTypeStr = "f03"

            deviceconfig.setSwitchTime(enable)

            video.fun_setInitPar(deviceconfig.getTcpip(),deviceconfig.getShowParentW(),deviceconfig.getShowParentH(),deviceconfig.getShowRectX(),deviceconfig.getShowRectY(),deviceconfig.getShowRectW(),deviceconfig.getShowRectH())
            s_tempmodelSelect(smap.tempmodel);
        }else if(strcmd === "getiradinfo"){


            var alarmtempEnable = smap.alarmtempEnable;
            var alarmTemp = smap.alarmTemp;
            var tempdriftcaplevelMin = smap.tempdriftcaplevelMin;
            var tempdriftcaplevelMax = smap.tempdriftcaplevelMax;
            var tempcontrolcaplevelMin = smap.tempcontrolcaplevelMin;
            var tempcontrolcaplevelMax = smap.tempcontrolcaplevelMax;
            var tempdrift = smap.tempdrift;
            var tempcontrol = smap.tempcontrol;
            var osdenable = smap.osdenable;

            deviceconfig.tempcontrolcapMax = tempcontrolcaplevelMax
            deviceconfig.tempcontrolcapMin = tempdriftcaplevelMin;
            deviceconfig.tempdriftcapMax = tempdriftcaplevelMax;
            deviceconfig.tempdriftcapMin = tempdriftcaplevelMin;
            deviceconfig.setTemDrift(tempdrift)
            deviceconfig.setWarnTem(alarmTemp)
            deviceconfig.setSwitchTime(osdenable)
            deviceconfig.setTempContrl(tempcontrol)
            deviceconfig.setSwitchWarn(alarmtempEnable)
        }
    }

    function updateDate(){
        video.fun_updateDate();
    }



    function adjustWindow(adjustw,dX,dY)
    {
        var dx = 0;
        var dy = 0;
        var dw = 0;
        var dh = 0;
        if(adjustw === wLEFT){
            rectadmjt.x = rectadmjt.x + dX;
            rectadmjt.width = rectadmjt.width - dX;
        }else if(adjustw === wRIGHT){

            rectadmjt.width = rectadmjt.width + dX;

        }else if(adjustw === wTOP){
            rectadmjt.y = rectadmjt.y + dY;
            rectadmjt.height = rectadmjt.height - dY;

        }else if(adjustw === wBOTTOM){
            console.debug( "*****   " + dY)
            rectadmjt.height = rectadmjt.height + dY;
        }else if(adjustw === wRIGHTTOP){

            rectadmjt.x = rectadmjt.x - dX;
            rectadmjt.width = rectadmjt.width + dX;

            rectadmjt.y = rectadmjt.y + dY;
            rectadmjt.height = rectadmjt.height - dY;

        }else if(adjustw === wLEFTTOP){

            rectadmjt.x = rectadmjt.x + dX;
            rectadmjt.width = rectadmjt.width - dX;

            rectadmjt.y = rectadmjt.y + dY;
            rectadmjt.height = rectadmjt.height - dY;

        }else if(adjustw === wLEFTBOTTOM){
            rectadmjt.x = rectadmjt.x + dX;
            rectadmjt.width = rectadmjt.width - dX;

            rectadmjt.height = rectadmjt.height + dY;

        }else if(adjustw === wRIGHTBOTTOM){

            rectadmjt.width = rectadmjt.width + dX;

            rectadmjt.height = rectadmjt.height + dY;
        }else if(wCenter === adjustw){

            rectadmjt.x = rectadmjt.x + dX;
            rectadmjt.y = rectadmjt.y + dY;
        }


        video.fun_setRectPar(rectadmjt.x,rectadmjt.y,rectadmjt.width,rectadmjt.height,video.width,video.height)
        console.debug("矩形位置："+rectadmjt.x+" "+rectadmjt.y+" "+rectadmjt.width+" "+rectadmjt.height+" "+video.width+" "+video.height);

    }

}



