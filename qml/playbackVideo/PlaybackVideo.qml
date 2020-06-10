import QtQuick 2.0
//import QtQuick 2.12
import TimeLine 1.0
import XVideoReplay 1.0
import QtQuick.Controls 1.4
import QtGraphicalEffects 1.12
//import QtQuick.Controls 2.5
import QtQuick.Controls.Styles 1.4
import "../liveVedio"
import "../simpleControl"
import Qt.labs.settings 1.0
Rectangle {

    id:playbackvideo
    objectName: "playbackvideo"
    signal s_addDevice();
    signal st_showToastMsg(string str1);
    signal s_multiScreenNumChange(int num);

    property int multiScreenNum: 2
    property int premultiScreenNum: 2

    property int modelDataCurrentIndex: -1
    property int listDeviceCurrentIndex: -1

    property string shotScreenFilePath2: ""
    property string recordingFilePath2: ""

    property bool isMax: false
    property bool  isPlay: false


    property string curPlayChannel: ""
    MouseArea{
        anchors.fill: parent
        onClicked: ;
        onPressed: ;
    }
    Settings {
        id:setting

        property alias adjustsize: rowAdjustSize.curIndex

    }

    Rectangle{
        id:maincontent
        width: parent.width
        height: parent.height
        objectName: "maincontent"
        color: "#252525"

        XVideoReplay{
            id:xVideoReplay
            objectName: "replay"
            width:maincontent.width
            height:maincontent.height - rowRectHeight.height - timeline.height

            onSignal_timeDate:{
                timeline.indicatorTimeUpdate(pts)
            }
            Component.onCompleted: deviceModel.funSaveReplayVideo(xVideoReplay)
        }

        Rectangle{
            id:rowRectHeight
            width: parent.width
            height: 40
            anchors.bottom: timeline.top
            color: "#323232"
            //播放控制
            Row{
                id:videoControl
                height: 40
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: 26
                Image {
                    id: imgslow
                    source: "qrc:/images/playback/play_slow.png"

                    width: 20
                    height: 20
                    anchors.verticalCenter: parent.verticalCenter
                    MouseArea{
                        anchors.fill: parent
                        hoverEnabled: true
                        onReleased: imgslow.source = "qrc:/images/playback/play_slow_h.png"
                        onPressed:{
                            if(!isSelectChannel())
                                return;
                            imgslow.source = "qrc:/images/playback/play_slow_p.png"


                           timeline.replaytimeSlowOrFast(-10)
                        }
                        onEntered: imgslow.source = "qrc:/images/playback/play_slow_h.png"
                        onExited: imgslow.source = "qrc:/images/playback/play_slow.png"
                    }
                }

                Image {
                    id: imgplay
                    source: imgplay.isPlay?"qrc:/images/playback/play_pause.png":"qrc:/images/playback/play.png"
                    property bool isPlay: false
                    width: 20
                    height: 20
                    anchors.verticalCenter: parent.verticalCenter
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            if(!isSelectChannel())
                                return;

                            if(!imgplay.isPlay){
                                var map = {
                                    cmd:"replay continue"};
                                deviceModel.funSendData1(txtDeviceSelect.text,"replay continue",map);

                            }else{
                                var map1 = {
                                    cmd:"replay pause"};
                                deviceModel.funSendData1(txtDeviceSelect.text,"replay pause",map1);
                            }
                        }
                    }
                }

                Image {
                    id: imgfast
                    source: "qrc:/images/playback/play_fast.png"
                    width: 20
                    height: 20
                    anchors.verticalCenter: parent.verticalCenter

                    MouseArea{
                        anchors.fill: parent
                        hoverEnabled: true
                        onReleased: imgfast.source = "qrc:/images/playback/play_fast_h.png"
                        onPressed:{
                            if(!isSelectChannel())
                                return;
                            imgfast.source = "qrc:/images/playback/play_fast_p.png"
                            timeline.replaytimeSlowOrFast(10)
                        }
                        onEntered: imgfast.source = "qrc:/images/playback/play_fast_h.png"
                        onExited: imgfast.source = "qrc:/images/playback/play_fast.png"
                    }
                }
            }

            //尺寸调整
            ListModel {
                id: sizeTypeModel
                ListElement {str: "24 hr"}
                ListElement {str: "2 hr"}
                ListElement {str: "1 hr"}
                ListElement {str: "30 min"}
            }
            Row{
                id:rowAdjustSize
                property int curIndex: 0
                height: parent.height
                anchors.left: parent.left
                anchors.leftMargin: 30

                Repeater{
                    model:sizeTypeModel
                    Rectangle{
                        width: 60
                        height: 20
                        color: index === rowAdjustSize.curIndex?"#ffffff":"#323232"
                        border.color: "#ffffff"
                        border.width: 1
                        anchors.verticalCenter: parent.verticalCenter
                        Text {
                            id: sizetxt
                            text: str
                            anchors.horizontalCenter: parent.horizontalCenter
                            anchors.verticalCenter: parent.verticalCenter
                            color:index === rowAdjustSize.curIndex?"#000000":"#ffffff"
                            font.pixelSize: 12
                        }
                        MouseArea{
                            anchors.fill: parent
                            onClicked: rowAdjustSize.curIndex = index
                        }
                    }
                }

                onCurIndexChanged: {
                    timeline.setSizeType(curIndex);
                }
            }

            //日期选择
            Rectangle{

                id:timeRect
                color: "#4C4C4C"
                border.width: 0
                width: 130
                height: 22
                anchors.left: rowAdjustSize.right
                anchors.verticalCenter: parent.verticalCenter
                anchors.leftMargin: 30
                Text {
                    id: txtDate
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.leftMargin: 10
                    font.pixelSize: 12
                    color: "#ffffff"
                    text: Qt.formatDate(calendar.getCurrentData(),"yyyy-MM-dd")
                }
                Image {
                    id: imgdate
                    width: 14
                    height: 12
                    source: "qrc:/images/warnmanager/date.png"
                    anchors.right: parent.right
                    anchors.rightMargin: 10
                    anchors.verticalCenter: parent.verticalCenter
                    MouseArea{
                        anchors.fill: parent
                        hoverEnabled: true
                        onPressed: {
                            if(!isSelectChannel())
                                return;

                            imgdate.source = "qrc:/images/warnmanager/date_p.png"
                            getRecordInfo(1,Qt.formatDate(calendar.getCurrentData(),"yyyyMMdd000000"));

                            calendar.open()
                        }

                        onReleased: imgdate.source = "qrc:/images/warnmanager/date.png"
                    }
                }

            }

            //设备选择
            Rectangle{
                id:rectDeviceSelect
                width: 130
                height: 22
                anchors.left: timeRect.right
                anchors.verticalCenter: parent.verticalCenter
                anchors.leftMargin: 10
                color: "#4C4C4C"
                Text {
                    id: txtDeviceSelect
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.leftMargin: 10
                    font.pixelSize: 12
                    color: "#ffffff"
                    //text: Qt.formatDate(calendar.getCurrentData(),"yyyy-MM-dd")
                }
                Image {
                    id: imgDeviceSelect
                    width: 14
                    height: 12
                    source: "qrc:/images/playback/device.png"
                    anchors.right: parent.right
                    anchors.rightMargin: 10
                    anchors.verticalCenter: parent.verticalCenter

                }
                MouseArea{
                    anchors.fill: parent
                    hoverEnabled: true
                    onPressed: {
                        imgDeviceSelect.source = "qrc:/images/playback/device_p.png"
                        if(deviceModel.rowCount() > 0){
                            console.debug("********** "+deviceModel.rowCount())

                            deviceSelectPop.height = deviceModel.rowCount() * 20
                            deviceSelectPop.width = rectDeviceSelect.width
                            deviceSelectPop.x = 440
                            deviceSelectPop.y = main.height -175- deviceModel.rowCount() * 20
                            deviceSelectPop.open()
                        }
                    }

                    onReleased: imgDeviceSelect.source = "qrc:/images/playback/device.png"
                }
            }

            Row{
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                anchors.rightMargin: 30
                height: parent.height
                spacing: 30

                Rectangle{
                    width: rectNormal.width + txtNormal.width + 8
                    height: parent.height
                    color: "transparent"
                    Rectangle{
                        id:rectNormal
                        color: "#89A0FF"
                        width: 8
                        height: 8
                        radius: 4
                        anchors.left: parent.left
                        anchors.verticalCenter: parent.verticalCenter
                    }
                    Text {
                        id: txtNormal
                        anchors.left: rectNormal.right
                        anchors.leftMargin: 5
                        anchors.verticalCenter: parent.verticalCenter
                        font.pixelSize: 12
                        color: "white"
                        text: mylanguage.VideoNormal
                    }
                }
                Rectangle{
                    width: rectWarn.width + txtWarn.width + 8
                    height: parent.height
                    color: "transparent"
                    Rectangle{
                        id:rectWarn
                        color: "#FF6149"
                        width: 8
                        height: 8
                        radius: 4
                        anchors.left: parent.left
                        anchors.verticalCenter: parent.verticalCenter
                    }
                    Text {
                        id: txtWarn
                        anchors.left: rectWarn.right
                        anchors.leftMargin: 5
                        anchors.verticalCenter: parent.verticalCenter
                        font.pixelSize: 12
                        color: "white"
                        text: mylanguage.VideoAlarm
                    }
                }
                Rectangle{
                    width: rectNo.width + txtNo.width + 8
                    height: parent.height
                    color: "transparent"
                    Rectangle{
                        id:rectNo
                        color: "#ffffff"
                        width: 8
                        height: 8
                        radius: 4
                        anchors.left: parent.left
                        anchors.verticalCenter: parent.verticalCenter
                    }
                    Text {
                        id: txtNo
                        anchors.left: rectNo.right
                        anchors.leftMargin: 5
                        anchors.verticalCenter: parent.verticalCenter
                        font.pixelSize: 12
                        color: "white"
                        text: mylanguage.VideoLoss
                    }
                }

                Rectangle{
                    height: parent.height
                    width: imgvoice.width + voiceSlider.width+8
                    color: "transparent"
                    Image{
                        id: imgvoice
                        width: 24
                        height: 17
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        source: "qrc:/images/playback/voice.png"
                    }

                    Slider {
                        id:voiceSlider
                        width: 140
                        height:4
                        anchors.left: imgvoice.right
                        anchors.leftMargin: 5
                        anchors.verticalCenter: parent.verticalCenter
                        value: 0.5
                        style: SliderStyle {
                            groove: Rectangle {
                                implicitWidth: 140
                                implicitHeight: 4
                                color: "#88ffffff"
                                radius: 2
                                Rectangle{
                                    id:sliderrect1
                                    anchors.left: parent.left
                                    width: voiceSlider.value * parent.width
                                    height: parent.height
                                    color: "#0486FE"
                                }
                                Rectangle{
                                    id:sliderrect2
                                    anchors.left: sliderrect1.right
                                    width: parent.width - sliderrect1.width
                                    height: parent.height
                                    color: "transparent"
                                }

                            }
                            handle: Rectangle {
                                anchors.centerIn: parent
                                color: control.pressed ? "white" : "lightgray"
                                implicitWidth: 10
                                implicitHeight: 10
                                radius: 5
                            }
                        }
                    }
                }
            }
        }

        TimeLine{
            id:timeline
            width:parent.width
            height:74
            anchors.bottom:parent.bottom
            property point mousePressPt: "0,0"
            onIndicatorTimeChange:{
                //screen.funPlayTimeChange(deviceconfig.getRecordPath(),Qt.formatDate(calendar.getCurrentData(),"yyyyMMdd"),curTime)
                var str = Qt.formatDate(calendar.getCurrentData(),"yyyy:MM:dd:") +curTime;
                var map = {
                    cmd:"replay",
                    time:str};
                deviceModel.funSendData1(txtDeviceSelect.text,"replay",map);
            }
        }
    }



    DeviceSelectPop{
        id:deviceSelectPop

        mmodel:deviceModel

        onS_txtChange: {

            if(txtDeviceSelect.text === ""){
                txtDeviceSelect.text = txt
                return
            }

            if(txt !== txtDeviceSelect.text){

                askDialog.width = 427
                askDialog.height = 176
                var txtstr = "";
                switch(curLanguage){
                case lChinese:
                    txtstr = "通道改变，将重置回放界面"
                    break;
                case lEnglish:
                    break;
                }
                askDialog.askStr =txtstr
                askDialog.imgSrc = "qrc:/images/icon_question.png"
                askDialog.curType = askDialog.replayChannelChange
                askDialog.open();
            }

        }
    }

    Connections{
        target: askDialog
        onS_CurTypeMsg:{
            if(askDialog.replayChannelChange === type){

                var map1 = {
                    cmd:"replay stop"};
                deviceModel.funSendData1(txtDeviceSelect.text,"replay stop",map1);

                timeline.resetParameter();

                txtDeviceSelect.text = deviceSelectPop.curText

                calendar.calendarEventModel.clear();
            }
        }
    }

    MyCalendar{
        id:calendar
        width: 280
        height: 314
        dim:false
        x:228
        y:parent.height -115-314-2
        onS_dayChange:{
            //            timeline.updateDate(deviceconfig.getRecordPath(),value)
            //timeline.clearTimeWarn();

            timeline.resetParameter();

            getRecordInfo(2,value)
        }
        onS_dayChange1:{

            txtDate.text = value
        }

        onS_mouthChange:{
            calendar.calendarEventModel.clear();
            getRecordInfo(1,value)
        }

        onS_yearChange: {

                console.debug("onS_yearChange   "+value)
            }

        // Component.onCompleted:getRecordInfo(2, Qt.formatDate(calendar.getCurrentData(),"yyyyMMdd000000"))
    }

    function getRecordInfo(type,date){
        console.debug("onS_mouthChange   "+type+"   "+date)

        if(txtDeviceSelect.text != ""){
            var map = {cmd:"getrecordinginfo",method:type,time:date,msgid:date}
            deviceModel.funSendData1(txtDeviceSelect.text,"getrecordinginfo",map)
        }
    }
    Connections{
        target:deviceModel

        onSignal_p2pCallbackReply:{
            console.debug("smap " + smap.cmd)
            if(name === txtDeviceSelect.text){
                if(smap.cmd === "getrecordinginfo"){
                    if(smap.infoType==="hourInfo"){
                        //发送给时间轴渲染
                        timeline.setTimeWarn(smap);
                    }else if(smap.infoType==="dayInfo"){
                        var dayStr = Qt.formatDate(calendar.getCurrentData(),"yyyyMMdd");
                        var listRecord = smap.data;
                        for(var i=0;i<smap.data.length;i++){
                            if(listRecord[i] !== "0"){
                                var timeStr
                                if(i <10)
                                    timeStr= dayStr + "0"+i+"0000";
                                else
                                    timeStr= dayStr + i+"0000";
                                getRecordInfo(3,timeStr)
                            }
                        }
                    }else if(smap.infoType==="mounthInfo"){

                        var listRecord = smap.data;

                        console.debug("*****************  mounthInfo:  "+ listRecord);

                        for(var i=0;i<listRecord.length;i++){
                            calendar.calendarEventModel.append({type:listRecord[i]})
                        }

//                        for(var j=0;j<calendar.calendarEventModel.count;j++)
//                            console.debug("*****************  calendarEventModel:  "+ calendar.calendarEventModel.get(j).type);
                    }
                }else if(smap.cmd === "replay"){
                    imgplay.isPlay = true;
                }else if(smap.cmd === "replay stop"){
                    imgplay.isPlay = false;
                }else if(smap.cmd === "replay pause"){
                    imgplay.isPlay = false;
                }else if(smap.cmd === "replay continue"){
                    imgplay.isPlay = true;
                }
            }
        }


        onSignal_p2pCallbackReplayAudioData:{


        }

        onSignal_p2pCallbackReplayVideoData:{
            xVideoReplay.funSendVideoData(h264Arr)
            timeline.indicatorTimeUpdate(pts)
        }
    }

    function isSelectChannel(){
        if(txtDeviceSelect.text === ""){
            msgDialog.width = 300
            msgDialog.height = 140
            msgDialog.msgStr = "请选择通道！"
            msgDialog.open();
            return false;
        }
        return true;
    }

    function setLanguage(type){

        switch(type){
        case lEnglish:
            txtNormal.text = "Normal";
            txtWarn.text = "Alarm"
            txtNo.text = "Record lost"
            break;
        case lChinese:
            txtNormal.text = "正常录像";
            txtWarn.text = "报警录像"
            txtNo.text = "录像丢失"
            break;
        }
    }


}
