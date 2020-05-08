import QtQuick.Controls 2.5
import QtQuick 2.0
import QtGraphicalEffects 1.12
import QtQuick.Dialogs 1.3
import Qt.labs.settings 1.0
import "../simpleControl"
Rectangle {
    id: root

    signal s_timeSwith(bool mchecked);
    signal s_warnSwith(bool mchecked);
    signal s_screenShotSwith(bool mchecked);
    signal s_beerSwith(bool mchecked);
    signal s_recordSwith(bool mchecked);
    signal s_temSet(var mvalue);
    signal s_screenShotPathSet(var mvalue);
    signal s_recordPathSet(var mvalue);
    //    signal s_temDrift(var mvalue);

    signal s_getInitPar();

    signal s_temOffset(var mvalue);
    signal s_temMax(var mvalue);
    signal s_temMin(var mvalue);
    signal s_temImage(var mvalue);

    signal s_iradInfoSet(var mvalue);

    property int fontSize: 12
    property color fontColor: "#606266"

    property string curDevTypeStr:"E03"
    //第一根左对齐线
    property int parSetFirstAlignLine: curLanguage === lChinese?102:curLanguage === lEnglish?230:curLanguage === lKorean?204:curLanguage ===lRussian?210:300
    property int parSetSecondAlignLine: curLanguage === lChinese?262:curLanguage === lEnglish?488:curLanguage === lKorean?388:curLanguage ===lRussian?538:700

    property int tempdriftcapMax: 2
    property int tempdriftcapMin: -2
    property int tempcontrolcapMax: 6
    property int tempcontrolcapMin: 0

    property bool isRevicse: false//是否有修改
    Settings {
        id:setting

        fileName: "config.ini"


        property alias tempwarn:swichWarn.checked
        property alias temptemp:inputTem.text
        property alias tempscreenshot:swichScreenShot.checked
        property alias tempbeer:swichBeer.checked
        property alias tempscreenshotpath:inputScreenShotPath.text
        property alias tempdrift:inputTempDrift.text
        property alias tempthreshold:inputTempMin.text

    }

    function setTempPar(tempenable,tempvalue,screenshotswitch,screenshotpath,beerenable,drift,threshold){
        isRevicse = false
        swichWarn.checked = tempenable
        inputTem.text = tempvalue
        swichScreenShot.checked = screenshotswitch
        inputScreenShotPath.text = screenshotpath
        swichBeer.checked = beerenable
        inputTempDrift.text = drift
        inputTempMin.text = threshold
    }
    function updateParameterInfo(modle){

        if(isRevicse){
            return;
        }else{
            model.updateTemp(isBatchSet,swichWarn.checked,inputTem.text,swichScreenShot.checked,inputScreenShotPath.text,inputTempDrift.text,inputTempMin.text);
        }
    }
    Rectangle{
        width: parent.width
        height: parent.height
        MouseArea{
            anchors.fill: parent
        }

        Text {
            id: txtparset
            font.pixelSize: 14
            color: fontColor
            text: qsTr("参数设置")
            anchors.leftMargin: 20
            anchors.bottom: line2.top
            anchors.left: line2.left
            anchors.bottomMargin: 10
        }
        Rectangle{
            id:line2
            width:parent.width - 10*2
            height: 1
            color: "#e2e2e2"
            anchors.top: parent.top
            anchors.topMargin: 44
            anchors.horizontalCenter: parent.horizontalCenter
        }



        Text {
            id: txtSwichWarn
            text: qsTr("报警")
            font.pixelSize: fontSize
            color: fontColor
            anchors.right: swichWarn.left
            anchors.rightMargin: 20
            anchors.verticalCenter: swichWarn.verticalCenter

        }

        SimpleSwich{
            id:swichWarn
            width: 30
            height: 15
            anchors.left: line2.left
            anchors.leftMargin: parSetFirstAlignLine
            anchors.top: line2.bottom
            anchors.topMargin: 20
            onCheckedChanged: s_warnSwith(checked)
        }
        Text {
            id: txtWarnTemSet
            text: qsTr("温度设置")
            color: fontColor
            font.pixelSize: fontSize
            anchors.right: inputTem.left
            anchors.rightMargin: 20
            anchors.verticalCenter: swichWarn.verticalCenter

        }
        LineEdit {
            id: inputTem
            width: 88
            height: 28
            anchors.left: line2.left
            anchors.leftMargin: parSetSecondAlignLine

            anchors.verticalCenter:swichWarn.verticalCenter
            border.width: 1
            border.color: "#DEDFE3"
            font.pixelSize: fontSize
            placeholderText: ""
            isNeedDoubleClickEdit: false
            textLeftPadding:0
            txtColor: Qt.rgba(0,0,0,0.65)
            text: "38"
            color: "#ffffff"
            onTextChanged: s_temSet(inputTem.text)
        }
        Text {
            id: txtTem1
            text: qsTr("℃")
            font.pixelSize: fontSize
            color: fontColor
            anchors.left: inputTem.right
            anchors.leftMargin: 6
            anchors.verticalCenter: inputTem.verticalCenter
        }

        Text {
            id: txtSwichScreenShot
            text: qsTr("抓拍开关")
            font.pixelSize: fontSize
            color: fontColor
            anchors.right: swichScreenShot.left
            anchors.rightMargin: 20
            anchors.verticalCenter: swichScreenShot.verticalCenter
        }
        SimpleSwich{
            id:swichScreenShot
            width: 30
            height: 15
            anchors.left: line2.left
            anchors.leftMargin: parSetFirstAlignLine
            anchors.top: line2.bottom
            anchors.topMargin: 68
            onCheckedChanged: s_screenShotSwith(checked)
        }

        Text {
            id: txtScreenShotPath
            text: qsTr("存储路径")
            font.pixelSize: fontSize
            color: fontColor
            anchors.right: rectScreenShotPath.left
            anchors.rightMargin: 20
            anchors.verticalCenter: swichScreenShot.verticalCenter
        }
        Rectangle{

            id:rectScreenShotPath
            color: "#ffffff"
            border.color: "#DEDFE3"
            border.width: 1
            width: 200
            height: 28
            anchors.left: line2.left
            anchors.leftMargin: parSetSecondAlignLine
            anchors.verticalCenter: swichScreenShot.verticalCenter
            LineEdit {
                id: inputScreenShotPath
                width: rectScreenShotPath.width - imgScreenShotPath.width - 22
                height: rectScreenShotPath.height -2
                anchors.left: parent.left
                anchors.leftMargin: 2

                anchors.verticalCenter: rectScreenShotPath.verticalCenter
                border.width: 0
                text:screenv.funGetCurPath()
                font.pixelSize: fontSize
                placeholderText: ""
                isNeedDoubleClickEdit: false
                textLeftPadding:0
                txtColor: Qt.rgba(0,0,0,0.65)
                color: "#ffffff"
                //onTextChanged: s_screenShotPathSet(inputScreenShotPath.text)
            }
            Image {
                id: imgScreenShotPath
                width: 16
                height: 13
                source: "qrc:/images/warnmanager/file.png"
                anchors.right: parent.right
                anchors.rightMargin: 10
                anchors.verticalCenter: parent.verticalCenter
                MouseArea{
                    anchors.fill: parent
                    onPressed: {
                        imgScreenShotPath.source = "qrc:/images/warnmanager/fileopen.png"
                    }
                    onReleased: {
                        imgScreenShotPath.source = "qrc:/images/warnmanager/file.png"
                    }
                    onClicked: {
                        fileDialog.folder = "file:///"+inputScreenShotPath.text
                        fileDialog.pathname = "screenShotPath";

                        fileDialog.open()
                    }
                }
            }

        }

        Text {
            id: txtSwichBeer
            text: qsTr("蜂鸣开关")
            font.pixelSize: fontSize
            color: fontColor
            anchors.right: swichBeer.left
            anchors.rightMargin: 20
            anchors.verticalCenter: swichBeer.verticalCenter

        }
        SimpleSwich{
            id:swichBeer
            width: 30
            height: 15
            anchors.left: line2.left
            anchors.leftMargin: parSetFirstAlignLine
            anchors.top: line2.bottom
            anchors.topMargin:111
            onCheckedChanged: s_beerSwith(checked)
        }


        Text {
            id: txtTempDrift
            text: qsTr("温漂设置")
            color: fontColor
            font.pixelSize: fontSize
            anchors.right: rectTempDrift.left
            anchors.rightMargin: 20
            anchors.verticalCenter: rectTempDrift.verticalCenter
        }

        Rectangle{
            id:rectTempDrift
            color: "#ffffff"
            border.width: 1
            border.color: "#DCDFE6"
            width: 88
            height: 32
            radius: 4
            anchors.left: line2.left
            anchors.leftMargin: parSetFirstAlignLine
            anchors.top: line2.bottom
            anchors.topMargin: 149
            LineEdit {
                id: inputTempDrift
                width: rectTempDrift.width  - 22
                height: rectTempDrift.height -2
                anchors.left: parent.left
                anchors.leftMargin: 1
                anchors.verticalCenter: rectTempDrift.verticalCenter
                border.width: 0
                inputLimite:Qt.ImhDigitsOnly
                font.pixelSize: fontSize
                placeholderText: ""
                isNeedDoubleClickEdit: false
                textLeftPadding:0
                txtColor: Qt.rgba(0,0,0,0.65)
                text: "0"
                color: "#ffffff"
                isReadOnly:true
                onTextChanged: {
                    s_temOffset(inputTempDrift.text);

                }
            }
            Image {
                id: imgValueUp
                width: 20
                height: 15
                source: "qrc:/images/arrow_up.png"
                anchors.right: parent.right
                anchors.rightMargin: 1
                anchors.top: parent.top
                anchors.topMargin: 1
                MouseArea{
                    anchors.fill: parent
                    onPressed: {
                        imgValueUp.source="qrc:/images/arrow_up_p.png"
                        var num = parseInt(inputTempDrift.text)
                        if(num >= tempdriftcapMax)
                            return

                        inputTempDrift.text = ""+(Number(num)+Number(1))

                    }
                    onReleased: imgValueUp.source="qrc:/images/arrow_up.png"
                }
            }
            Image {
                id: imgValuedown
                width: 20
                height: 15
                source: "qrc:/images/arrow_low.png"
                anchors.right: imgValueUp.right
                anchors.top: imgValueUp.bottom
                anchors.topMargin: 1
                MouseArea{
                    anchors.fill: parent

                    onPressed: {

                        imgValuedown.source="qrc:/images/arrow_low_p.png"
                        var num = parseInt(inputTempDrift.text)

                        if(num <= tempdriftcapMin)
                            return

                        inputTempDrift.text = ""+(Number(num)-Number(1))
                    }
                    onReleased: imgValuedown.source="qrc:/images/arrow_low.png"
                }
            }
        }

        Text {
            id: txtTemp
            text: qsTr(" ℃")
            color: fontColor
            font.pixelSize: fontSize
            anchors.verticalCenter: rectTempDrift.verticalCenter
            anchors.left: rectTempDrift.right
            anchors.topMargin: 6
        }

        ////////////
        Text {
            id: txtTempMin
            text: qsTr("温度控制阀")
            color: fontColor
            font.pixelSize: fontSize
            anchors.right: rectTempMin.left
            anchors.rightMargin: 20
            anchors.verticalCenter: rectTempMin.verticalCenter

        }

        Rectangle{
            id:rectTempMin
            color: "#ffffff"
            border.width: 1
            border.color: "#DCDFE6"
            width: 88
            height: 32
            radius: 4
            anchors.left: line2.left
            anchors.top:line2.bottom
            anchors.topMargin: 197
            anchors.leftMargin: parSetFirstAlignLine
            LineEdit {
                id: inputTempMin
                width: rectTempMin.width  - 22
                height: rectTempMin.height -2
                anchors.left: parent.left
                anchors.leftMargin: 1
                anchors.verticalCenter: rectTempMin.verticalCenter
                border.width: 0
                inputLimite:Qt.ImhDigitsOnly
                font.pixelSize: fontSize
                placeholderText: ""
                isNeedDoubleClickEdit: false
                textLeftPadding:0
                txtColor: Qt.rgba(0,0,0,0.65)
                text: "4"
                isReadOnly:true
                color: "#ffffff"
                onTextChanged: {
                    if(inputTempMin.text === "1")
                        s_temMin("21");
                    else if(inputTempMin.text === "2")
                        s_temMin("24");
                    else if(inputTempMin.text === "3")
                        s_temMin("26");
                    else if(inputTempMin.text === "4")
                        s_temMin("28");
                    else if(inputTempMin.text === "5")
                        s_temMin("30");
                    else if(inputTempMin.text === "6")
                        s_temMin("32");

                }
            }

            Image {
                id: imgValueMinUp
                width: 20
                height: 15
                source: "qrc:/images/arrow_up.png"
                anchors.right: parent.right
                anchors.rightMargin: 1
                anchors.top: parent.top
                anchors.topMargin: 1
                MouseArea{
                    anchors.fill: parent
                    onPressed: {
                        imgValueMinUp.source="qrc:/images/arrow_up_p.png"
                        var num = parseInt(inputTempMin.text)
                        if(num >= tempcontrolcapMax)
                            return

                        inputTempMin.text = ""+(Number(num)+Number(1))
                    }
                    onReleased: imgValueMinUp.source="qrc:/images/arrow_up.png"
                }
            }
            Image {
                id: imgValueMindown
                width: 20
                height: 15
                source: "qrc:/images/arrow_low.png"
                anchors.right: imgValueMinUp.right
                anchors.top: imgValueMinUp.bottom
                anchors.topMargin: 1
                MouseArea{
                    anchors.fill: parent

                    onPressed: {

                        imgValueMindown.source="qrc:/images/arrow_low_p.png"
                        var num = parseInt(inputTempMin.text)

                        if(num <= tempcontrolcapMin)
                            return

                        inputTempMin.text = ""+(Number(num)-Number(1))
                    }
                    onReleased: imgValueMindown.source="qrc:/images/arrow_low.png"
                }
            }

        }

        Text {
            id: txtTemp1

            text: qsTr(" ℃")
            color: fontColor
            font.pixelSize: fontSize
            anchors.verticalCenter: rectTempMin.verticalCenter
            anchors.left: rectTempMin.right
            anchors.topMargin: 6
        }
    }



    FileDialog {
        id: fileDialog
        property string pathname:""
        title: "Please choose a file path"
        selectFolder:true
        selectMultiple: false
        //folder: shortcuts.home
        onAccepted: {
            if(pathname === "recordPath"){
                var str = fileDialog.fileUrl.toString();
                inputRecordPath.text = str.replace('file:///','');
                // devicemanagerment.recordingPath = txtVedioSavePath.text
            }else if(pathname === "screenShotPath"){
                inputScreenShotPath.text = fileDialog.fileUrl.toString().replace('file:///','');
                //devicemanagerment.screenShotPath = txtscreenshotSavePath.text
            }

        }
        onRejected: {


        }
    }


    function iradInfoSet(){

        var osdenableV;
        if(swithTime.checked)
            osdenableV = 1
        else
            osdenableV = 0
        var alarmtempEnableV;
        if(swichWarn.checked)
            alarmtempEnableV = 1;
        else
            alarmtempEnableV = 0;

        var map ={
            osdenable:osdenableV,
            alarmtempEnable:alarmtempEnableV,
            alarmtemp:inputTem.text,
            tempdrift:inputTempDrift.text,
            tempcontrol:inputTempMin.text,
            cmd:"setiradinfo"
        }
        s_iradInfoSet(map);
    }


    function getRecordPath(){
        return setting.recordPath;
    }
    function getScrennShotPath(){
        return setting.screenShotPath;
    }
    function getTemDrift(){
        return setting.temDrift
    }
    function setTemDrift(mvalue){
        inputTempDrift.text = mvalue;
    }


    function getWarnTem(){
        return setting.warnTem
    }
    function setWarnTem(mvalue){
        inputTem.text = mvalue
    }

    function getSwitchWarn()
    {
        return setting.switchWarn;
    }

    function setSwitchWarn(mvalue)
    {
        swichWarn.checked = mvalue
    }

    function getSwitchTime(){
        return setting.switchTime
    }

    function setSwitchTime(mvalue){
        swithTime.checked = mvalue
    }

    function getSwitchRecord(){
        return setting.switchRecord
    }

    function getSwitchScreenShot(){
        return setting.switchScreenShot
    }

    function getSwitchBeer(){
        return setting.switchBeer
    }

    function setTempContrl(mavlue){
        inputTempMin.text = mavlue
    }

    function setTcpip(value){
        setting.tcpip = value
    }
    function setIsOpenAdjustRect(value){
        setting.isOpenAdjustRect = value
    }

    function setRedRect(pw,ph,rx,ry,rw,rh){


        if(curDevTypeStr === "e03"){
            setting.e03showParentW = pw
            setting.e03showParentH = ph
            setting.e03showRectX = rx
            setting.e03showRectY = ry
            setting.e03showRectW = rw
            setting.e03showRectH = rh
        }else if(curDevTypeStr === "f03"){
            setting.f03showParentW = pw
            setting.f03showParentH = ph
            setting.f03showRectX = rx
            setting.f03showRectY = ry
            setting.f03showRectW = rw
            setting.f03showRectH = rh
        }else if(curDevTypeStr === "d04"){
            setting.d04showParentW = pw
            setting.d04showParentH = ph
            setting.d04showRectX = rx
            setting.d04showRectY = ry
            setting.d04showRectW = rw
            setting.d04showRectH = rh
        }else if(curDevTypeStr === "d06"){
            setting.d06showParentW = pw
            setting.d06showParentH = ph
            setting.d06showRectX = rx
            setting.d06showRectY = ry
            setting.d06showRectW = rw
            setting.d06showRectH = rh
        }
    }


    function getTcpip(){
        return setting.tcpip
    }
    function getIsOpenAdjustRect(){
        return setting.isOpenAdjustRect
    }
    function getShowRectX(){

        if(curDevTypeStr === "e03"){
            return setting.e03showRectX
        }else if(curDevTypeStr === "f03"){
            return setting.f03showRectX
        }else if(curDevTypeStr === "d04"){
            return setting.d04showRectX
        }else if(curDevTypeStr === "d06"){
            return setting.d06showRectX
        }
    }
    function getShowRectY(){
        if(curDevTypeStr === "e03"){
            return setting.e03showRectY
        }else if(curDevTypeStr === "f03"){
            return setting.f03showRectY
        }else if(curDevTypeStr === "d04"){
            return setting.d04showRectY
        }else if(curDevTypeStr === "d06"){
            return setting.d06showRectY
        }

    }
    function getShowRectW(){
        if(curDevTypeStr === "e03"){
            return setting.e03showRectW
        }else if(curDevTypeStr === "f03"){
            return setting.f03showRectW
        }else if(curDevTypeStr === "d04"){
            return setting.d04showRectW
        }else if(curDevTypeStr === "d06"){
            return setting.d06showRectW
        }
    }
    function getShowRectH(){
        if(curDevTypeStr === "e03"){
            return setting.e03showRectH
        }else if(curDevTypeStr === "f03"){
            return setting.f03showRectH
        }else if(curDevTypeStr === "d04"){
            return setting.d04showRectH
        }else if(curDevTypeStr === "d06"){
            return setting.d06showRectH
        }
    }
    function getShowParentW(){
        if(curDevTypeStr === "e03"){
            return setting.e03showParentW
        }else if(curDevTypeStr === "f03"){
            return setting.f03showParentW
        }else if(curDevTypeStr === "d04"){
            return setting.d04showParentW
        }else if(curDevTypeStr === "d06"){
            return setting.d06showParentW
        }
    }
    function getShowParentH(){
        if(curDevTypeStr === "e03"){
            return setting.e03showParentH
        }else if(curDevTypeStr === "f03"){
            return setting.f03showParentH
        }else if(curDevTypeStr === "d04"){
            return setting.d04showParentH
        }else if(curDevTypeStr === "d06"){
            return setting.d06showParentH
        }
    }



    Connections{
        target: main
        onS_setLanguage:setLanguage(typeL);
    }

    function setLanguage(type){

        switch(type){
        case lEnglish:

            txtScreenShotPath.text = "Storage Path"
            txtWarnTemSet.text = "Alarm Temperature"
            txtparset.text = "Parameter Settings"
            txtSwichBeer.text = "Buzzer"
            txtSwichScreenShot.text = "Snapshot"
            txtSwichWarn.text = "Alarm"
            txtTempMin.text = "Temperature control valve"
            txtTempDrift.text = "Temperature drift setting"
            break;
        case lChinese:

            txtScreenShotPath.text = "抓拍存储路径"
            txtWarnTemSet.text = "告警温度设置"
            txtparset.text = "参数设置"
            txtSwichBeer.text = "蜂鸣开关"
            txtSwichScreenShot.text = "抓拍开关"
            txtSwichWarn.text = "报警开关"
            txtTempMin.text = "温度控制阀"
            txtTempDrift.text = "温漂设置"
            break;

        }
    }
}
