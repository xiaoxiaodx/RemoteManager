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

        switch(weekly){
        case 0:
            weeklyAllSelect.checked = true;
            break;
        case 1:
            checkMonday.checked = true;
            break;
        case 2:
            checkTusday.checked = true;
            break;
        case 3:
            checkWensday.checked = true;
            break;
        case 4:
            checkTursday.checked = true;
            break;
        case 5:
            checkFriday.checked = true;
            break;
        case 6:
            checkSatday.checked = true;
            break;
        case 7:
            checkSunday.checked = true;
            break;
        }
    }

    function updateParameterInfo(model){

        if(isRevicse){
            return;
        }else{
            var videoType = -1;
            if(checkRecordClose.checked)
                videoType = 0
            if(checkWarnVideo.checked)
                videoType = 1
            if(checkRecordFullDay.checked)
               videoType = 2

            var weeklySelect = -1;
            if(weeklyAllSelect.checked)
                weeklySelect = 0
            if(checkMonday.checked)
                weeklySelect = 1
            if(checkTusday.checked)
                weeklySelect = 2
            if(checkWensday.checked)
                weeklySelect = 3
            if(checkTursday.checked)
                weeklySelect = 4
            if(checkFriday.checked)
                weeklySelect = 5
            if(checkSatday.checked)
                weeklySelect = 6
            if(checkSunday.checked)
                weeklySelect = 7
            model.updateRecord(isBatchSet,videoType,cmbResolution.currentIndex,txttimeStart.text,txttimeEnd.text,weeklySelect)
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
        text: qsTr("设置")
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
        text: "录像关闭"
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
        text: "告警录像"
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
        text: "全天录像"
    }

    Text {
        id: labelResolution
        text: qsTr("分辨率")
        font.pixelSize: fontSize
        color: fontColor
        anchors.left: line.left
        anchors.leftMargin: 20
        //anchors.rightMargin: 10
        anchors.verticalCenter: cmbResolution.verticalCenter
    }

    ListModel{
        id:resolutionModel
        ListElement{showStr:"1920*1080"}
        ListElement{showStr:"640*320"}
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
        onCurrentIndexChanged: {

        }
    }

    Text {
        id: labelRecordPath
        text: qsTr("存储路径")
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
            //onTextChanged: s_recordPathSet(inputrecordPath.text)
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
        text: qsTr("录像时间")
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
            onEntered: timeRectEnd.source = "qrc:/images/warnmanager/time.png"
            onReleased: timeRectEnd.source = "qrc:/images/warnmanager/time.png"
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
        text: "全选"
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
        text: "周日"
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
        text: "周一"
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
        text: "周二"
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
        text: "周三"
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
        text: "周四"
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
        text: "周五"
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
        text: "周六"
    }

    Connections{
        target: main
        onS_setLanguage:setLanguage(typeL);
    }

    function setLanguage(type){
        switch(type){
        case lEnglish:

            settxt.text = "Set"

            checkRecordFullDay.text = "All"
            checkWarnVideo.text = "Alarm"
            checkRecordClose.text ="Disable"

            checkMonday.text = "Monday"
            checkTusday.text = "Tuesday"
            checkWensday.text = "Wednesday"
            checkTursday.text = "Thursday"
            checkFriday.text = "Friday"
            checkSatday.text = "Saturday"
            checkSunday.text = "Sunday"
            weeklyAllSelect.text = "All"

            labelRecordPath.text = "Storage path"
            recordTimetext.text = "Record time"
            labelResolution.text = "Resolution"
            break;
        case lChinese:
            settxt.text = "设置"

            checkRecordFullDay.text = "全天录像"
            checkWarnVideo.text = "告警录像"
            checkRecordClose.text ="录像关闭"

            checkMonday.text = "周一"
            checkTusday.text = "周二"
            checkWensday.text = "周三"
            checkTursday.text = "周四"
            checkFriday.text = "周五"
            checkSatday.text = "周六"
            checkSunday.text = "周日"
            weeklyAllSelect.text = "全选"

            labelRecordPath.text = "存储路径"
            recordTimetext.text = "录像时间"
            labelResolution.text = "分辨率"


            break;
        }
    }
}
