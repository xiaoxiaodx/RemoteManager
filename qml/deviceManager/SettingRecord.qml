import QtQuick.Controls 2.5
import QtQuick 2.0
import QtGraphicalEffects 1.12
import QtQuick.Dialogs 1.3
import Qt.labs.settings 1.0
import QtQuick.Controls 1.4
import "../simpleControl"
import "../warnManager"
Rectangle {
    id: root



    property int fontSize: 12
    property color fontColor: "#606266"

    property bool isRevicse: false//是否有修改
    //与线的左对齐线

    property int parSetFirstAlignLine: curLanguage === lChinese?78:curLanguage === lEnglish?108:78
    color: "#ffffff"

    Settings {
        id:setting
        fileName: "config.ini"
        property alias recordclose: checkRecordClose.checked
        property alias recordwarnvideo: checkWarnVideo.checked
        property alias recordfullday: checkRecordFullDay.checked
        property alias recordresolution:cmbResolution.currentIndex
        property alias recordpath: inputrecordPath.text
        property alias recordstarttime: txttimeStart.text
        property alias recordendtime: txttimeEnd.text
        property alias recordmonday: checkMonday.checked
        property alias recordtusday:checkTusday.checked
        property alias recordwensday:checkWensday.checked
        property alias recordtursday:checkTursday.checked
        property alias recordfriday:checkFriday.checked
        property alias recordsatday:checkSatday.checked
        property alias recordsunday:checkSunday.checked
        property alias recordallweekly:weeklyAllSelect.checked
    }

    function setRecord(type,resolution,path,startT,endT,weekly){

        isRevicse = false
        if(type === 0)
            checkRecordClose.checked = true;
        else if(type === 1)
            checkWarnVideo.checked = true;
        else if(type === 2)
            checkRecordFullDay.checked = true

        inputrecordPath.text = path
        txttimeStart.text = startT
        txttimeEnd.text = endT

        cmbResolution.currentIndex = resolution



        if(weekly[0] === "1")
            checkMonday.checked = true;
        else
            checkMonday.checked = false;
        if(weekly[1] === "1")
            checkTusday.checked = true;
        else
            checkTusday.checked = false;

        if(weekly[2] === "1")
            checkWensday.checked = true;
        else
            checkWensday.checked = false;

        if(weekly[3] === "1")
            checkTursday.checked = true;
        else
            checkTursday.checked = false;

        if(weekly[4] === "1")
            checkFriday.checked = true;
        else
            checkFriday.checked = false;

        if(weekly[5] === "1")
            checkSatday.checked = true;
        else
            checkSatday.checked = false;

        if(weekly[6] === "1")
            checkSunday.checked = true;
        else
            checkSunday.checked = false;



    }

    function updateParameterInfo(){

        if(!isRevicse){
            return;
        }else{
            var videoType = -1;
            if(checkRecordClose.checked){
                videoType = 0
            }

            if(checkWarnVideo.checked){
                videoType = 1
                var mapsa = {
                    cmd:"setalarmparam",
                    alarmrecordenabled:1
                }

                if(isBatchSet)
                    deviceModel.funBatchSendData("setalarmparam",mapsa);
                else
                    deviceModel.funSendData1(deviceChannel,"setalarmparam",mapsa);
            }
            if(checkRecordFullDay.checked){
                videoType = 2
            }



            var weekly = 0;
            if(checkMonday.checked)
               weekly += 1;
            if(checkTusday.checked)
                weekly += 2;
            if(checkWensday.checked)
                weekly += 4;
            if(checkTursday.checked)
                weekly += 8;
            if(checkFriday.checked)
                weekly += 16;
            if(checkSatday.checked)
               weekly += 32;
            if(checkSunday.checked)
                weekly += 64;

            //model.updateRecord(isBatchSet,videoType,cmbResolution.currentIndex,txttimeStart.text,txttimeEnd.text,weeklySelect)

            var startt = txttimeStart.text
            var endt = txttimeEnd.text
            var maprp = {
                cmd:"setrecordparam",
                clarity:cmbResolution.currentIndex,
                starttime:startt,
                endtime:endt,
                alldayenabled:0,
                cycle:weekly
            }

            if(videoType === 2)
                maprp.alldayenabled = 1;


            if(isBatchSet)
                deviceModel.funBatchSendData("setrecordparam",maprp);
            else
                deviceModel.funSendData1(deviceChannel,"setrecordparam",maprp);

        }
    }

    Text {
        id: settxt
        anchors.left: line.left
        anchors.leftMargin: 20
        anchors.bottom: line.top
        anchors.bottomMargin: 10
        font.pixelSize: 14
        color: fontColor
        text: mylanguage.Set
    }


    Rectangle{
        id:line
        width: parent.width-20
        height: 1
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 44
        color: "#EBEEF5"
    }

    ExclusiveGroup { id: buttonGroup }

    SimpleCheckedButton{
        id:checkRecordClose
        exclusiveGroup:buttonGroup
        txtFont.pixelSize: fontSize
        txtColor: fontColor
        imgW: 12
        imgH: 12
        imgSrc: "qrc:/images/systemset/unselect.png"
        imgCheckSrc: "qrc:/images/systemset/select.png"
        anchors.left: line.left
        anchors.leftMargin: 20
        anchors.top: line.bottom
        anchors.topMargin: 20
        text: mylanguage.VideoClose
        onCheckedChanged: isRevicse = true;
    }

    SimpleCheckedButton{
        id:checkWarnVideo
        exclusiveGroup:buttonGroup
        txtFont.pixelSize: fontSize
        txtColor: fontColor
        imgW: 12
        imgH: 12
        imgSrc: "qrc:/images/systemset/unselect.png"
        imgCheckSrc: "qrc:/images/systemset/select.png"
        anchors.left: checkRecordClose.right
        anchors.leftMargin: 30
        anchors.verticalCenter: checkRecordClose.verticalCenter
        text: mylanguage.VideoAlarm
        onCheckedChanged: isRevicse = true;
    }

    SimpleCheckedButton{
        id:checkRecordFullDay
        exclusiveGroup:buttonGroup
        txtFont.pixelSize: fontSize
        txtColor: fontColor
        imgW: 12
        imgH: 12
        imgSrc: "qrc:/images/systemset/unselect.png"
        imgCheckSrc: "qrc:/images/systemset/select.png"
        anchors.left: checkWarnVideo.right
        anchors.leftMargin: 30
        anchors.verticalCenter: checkRecordClose.verticalCenter
        text: mylanguage.VideoFull
        onCheckedChanged: isRevicse = true;
    }

    Text {
        id: labelResolution
        text: mylanguage.Quality
        font.pixelSize: fontSize
        color: fontColor
        anchors.left: line.left
        anchors.leftMargin: 20
        //anchors.rightMargin: 10
        anchors.verticalCenter: cmbResolution.verticalCenter
    }

    ListModel{
        id:resolutionModel
        ListElement{showStr:"高清"}
        ListElement{showStr:"标清"}
        ListElement{showStr:"流畅"}
    }

    MyComBox{
        id:cmbResolution
        width:130
        height: 28
        anchors.left: labelResolution.right
        anchors.leftMargin:10
        anchors.top: line.bottom
        anchors.topMargin: 54
        contentBg: "#ffffff"
        itemColorBgNor:"#FFFFFF"
        itemColorBgHoverd: "#E7EAF1"
        indicatorImgSrc:"qrc:/images/imgTypeSelect.png"
        indicatorW: 9
        indicatorH: 5
        itemLeftMargin:0
        itemTopMargin:0
        itemFontColor: "#5A5E66"
        contentFontColor: "#a6000000"
        contentFontSize: fontSize
        bordColor:"#DEDFE3"
        mRadius:2
        model: resolutionModel
        onCurrentIndexChanged:isRevicse = true;

    }

    Text {
        id: labelRecordPath
        text: mylanguage.RecordPath
        font.pixelSize: fontSize
        color: fontColor
        anchors.right: rectrecordPath.left
        anchors.rightMargin: 10
        anchors.verticalCenter: rectrecordPath.verticalCenter
    }

    Rectangle{
        id:rectrecordPath
        color: "#F8FAFD"
        border.color: "#DEDFE3"
        border.width: 1
        width: 200
        height: 28
        anchors.left: line.left
        anchors.leftMargin: parSetFirstAlignLine
        anchors.top: line.bottom
        anchors.topMargin: 100
        LineEdit {
            id: inputrecordPath
            width: rectrecordPath.width - imgrecordPath.width - 22
            height: rectrecordPath.height -2
            anchors.left: parent.left
            anchors.leftMargin: 2

            anchors.verticalCenter: rectrecordPath.verticalCenter
            border.width: 0
            //text:screenv.funGetCurPath()
            font.pixelSize: fontSize
            placeholderText: ""
            isNeedDoubleClickEdit: false
            textLeftPadding:0
            txtColor: fontColor
            color: "#ffffff"
            onTextChanged: isRevicse = true;
        }
        Image {
            id: imgrecordPath
            width: 16
            height: 13
            source: "qrc:/images/warnmanager/file.png"
            anchors.right: parent.right
            anchors.rightMargin: 10
            anchors.verticalCenter: parent.verticalCenter
            MouseArea{
                anchors.fill: parent
                onPressed: {
                    imgrecordPath.source = "qrc:/images/warnmanager/fileopen.png"
                }
                onReleased: {
                    imgrecordPath.source = "qrc:/images/warnmanager/file.png"
                }
                onClicked: {
                    fileDialog.folder = "file:///"+inputrecordPath.text
                    fileDialog.pathname = "recordPath";

                    fileDialog.open()
                }
            }
        }
    }

    Text {
        id: recordTimetext
        anchors.left: line1.left
        anchors.leftMargin: 20
        anchors.bottom: line1.top
        anchors.bottomMargin: 10
        font.pixelSize: 14
        color: fontColor
        text: mylanguage.RecordTime
    }

    Rectangle{
        id:line1
        width: parent.width-20
        height: 1
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 237
        color: "#EBEEF5"
    }

    //时间选择
    Rectangle{

        id:timeRectStart
        color: "#ffffff"
        border.width: 1
        border.color: "#DCDFE6"
        radius: 4
        width: 120
        height: 30
        z:2
        anchors.left: line1.left
        anchors.leftMargin: 20
        anchors.topMargin: 20
        anchors.top: line1.bottom
        Text {
            id: txttimeStart
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: fontSize
            color: fontColor
            text: qsTr("00:00:00")
            onTextChanged: isRevicse = true;
        }

        Image {
            id: imgtimeStart
            width: 17
            height: 17
            source: "qrc:/images/warnmanager/time.png"
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
            anchors.rightMargin: 7
        }
        MouseArea{
            anchors.fill: parent
            hoverEnabled: true
            onPressed: {
                selecttimeStart.open()
            }
            onEntered: imgtimeStart.source = "qrc:/images/warnmanager/time.png"
            onReleased: imgtimeStart.source = "qrc:/images/warnmanager/time.png"
        }
    }

    Rectangle{
        id:timeSplitLine
        width: 26
        height: 1
        anchors.verticalCenter: timeRectStart.verticalCenter
        anchors.left: timeRectStart.right
        anchors.leftMargin: 10
        color: "#909399"
    }
    //时间选择
    Rectangle{

        id:timeRectEnd
        color: "#ffffff"
        border.width: 1
        border.color: "#DCDFE6"
        radius: 4
        width: 120
        height: 30
        z:2
        anchors.left: timeSplitLine.right
        anchors.leftMargin: 10
        anchors.verticalCenter: timeRectStart.verticalCenter
        Text {
            id: txttimeEnd
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: fontSize
            color: fontColor
            text: qsTr("00:00:00")
            onTextChanged: isRevicse = true;
        }

        Image {
            id: imgtimeEnd
            width: 17
            height: 17
            source: "qrc:/images/warnmanager/time.png"
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
            anchors.rightMargin: 7
        }
        MouseArea{
            anchors.fill: parent
            hoverEnabled: true
            onPressed: {
                selecttimeEnd.open()
            }
            onEntered: imgtimeEnd.source = "qrc:/images/warnmanager/time.png"
            onReleased: imgtimeEnd.source = "qrc:/images/warnmanager/time.png"
        }
    }


    SelectTime{
        id:selecttimeStart
        x:timeRectStart.x
        y:timeRectStart.y + timeRectStart.height +2
        z:1
        width: 120
        height: 245
        onS_ensure: {
            var timeStr = timeh+":"+timem+":"+times
            txttimeStart.text = timeStr
            //            var curIndex = warnmodel.funFindIndex(timeh,timem,times)
            //            console.debug("curIndex "+curIndex)


        }

    }
    SelectTime{
        id:selecttimeEnd

        x:timeRectEnd.x
        y:timeRectEnd.y + timeRectEnd.height +2
        z:1
        width: 120
        height: 245
        onS_ensure: {
            var timeStr = timeh+":"+timem+":"+times
            txttimeEnd.text = timeStr
        }
    }


    SimpleCheckedButton{
        id:weeklyAllSelect
        anchors.left: line1.left
        anchors.leftMargin: 20
        anchors.top: line1.bottom
        anchors.topMargin: 70
        imgSrc: "qrc:/images/warnmanager/btnSelect.png"
        imgCheckSrc: "qrc:/images/warnmanager/btnSelect_s.png"
        imgH: 12
        imgW: 12
        txtFont.pixelSize: fontSize
        txtColor: fontColor
        text: mylanguage.AllSelect
        onCheckedChanged: isRevicse = true;
    }

    SimpleCheckedButton{
        id:checkSunday
        anchors.left: weeklyAllSelect.left
        anchors.top: weeklyAllSelect.bottom
        anchors.topMargin: 10
        imgSrc: "qrc:/images/warnmanager/btnSelect.png"
        imgCheckSrc: "qrc:/images/warnmanager/btnSelect_s.png"
        imgH: 12
        imgW: 12
        txtFont.pixelSize: fontSize
        txtColor: fontColor
        text: mylanguage.Sun
        onCheckedChanged: isRevicse = true;
    }

    SimpleCheckedButton{
        id:checkMonday
        anchors.left: checkSunday.right
        anchors.leftMargin: 20
        anchors.verticalCenter: checkSunday.verticalCenter
        imgSrc: "qrc:/images/warnmanager/btnSelect.png"
        imgCheckSrc: "qrc:/images/warnmanager/btnSelect_s.png"
        imgH: 12
        imgW: 12
        txtFont.pixelSize: fontSize
        txtColor: fontColor
        text: mylanguage.Mon
        onCheckedChanged: isRevicse = true;
    }

    SimpleCheckedButton{
        id:checkTusday
        anchors.left: checkMonday.right
        anchors.leftMargin: 20
        anchors.verticalCenter: checkSunday.verticalCenter
        imgSrc: "qrc:/images/warnmanager/btnSelect.png"
        imgCheckSrc: "qrc:/images/warnmanager/btnSelect_s.png"
        imgH: 12
        imgW: 12
        txtFont.pixelSize: fontSize
        txtColor: fontColor
        text: mylanguage.Tue
        onCheckedChanged: isRevicse = true;
    }

    SimpleCheckedButton{
        id:checkWensday
        anchors.left: checkTusday.right
        anchors.leftMargin: 20
        anchors.verticalCenter: checkSunday.verticalCenter
        imgSrc: "qrc:/images/warnmanager/btnSelect.png"
        imgCheckSrc: "qrc:/images/warnmanager/btnSelect_s.png"
        imgH: 12
        imgW: 12
        txtFont.pixelSize: fontSize
        txtColor: fontColor
        text: mylanguage.Wed
        onCheckedChanged: isRevicse = true;
    }

    SimpleCheckedButton{
        id:checkTursday
        anchors.left: checkWensday.right
        anchors.leftMargin: 20
        anchors.verticalCenter: checkSunday.verticalCenter
        imgSrc: "qrc:/images/warnmanager/btnSelect.png"
        imgCheckSrc: "qrc:/images/warnmanager/btnSelect_s.png"
        imgH: 12
        imgW: 12
        txtFont.pixelSize: fontSize
        txtColor: fontColor
        text: mylanguage.Thu
        onCheckedChanged: isRevicse = true;
    }

    SimpleCheckedButton{
        id:checkFriday
        anchors.left: checkTursday.right
        anchors.leftMargin: 20
        anchors.verticalCenter: checkSunday.verticalCenter
        imgSrc: "qrc:/images/warnmanager/btnSelect.png"
        imgCheckSrc: "qrc:/images/warnmanager/btnSelect_s.png"
        imgH: 12
        imgW: 12
        txtFont.pixelSize: fontSize
        txtColor: fontColor
        text: mylanguage.Fri
        onCheckedChanged: isRevicse = true;
    }

    SimpleCheckedButton{
        id:checkSatday
        anchors.left: checkFriday.right
        anchors.leftMargin: 20
        anchors.verticalCenter: checkSunday.verticalCenter
        imgSrc: "qrc:/images/warnmanager/btnSelect.png"
        imgCheckSrc: "qrc:/images/warnmanager/btnSelect_s.png"
        imgH: 12
        imgW: 12
        txtFont.pixelSize: fontSize
        txtColor: fontColor
        text: mylanguage.Sat
        onCheckedChanged: isRevicse = true;
    }


}
