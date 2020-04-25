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



    property int fontSize: 14
    property color fontColor: "#606266"
    //与线的左对齐线
    property int parSetFirstAlignLine: 78
    color: "#ffffff"

    Settings {
        id:setting

        fileName: "config.ini"

    }

    Text {
        id: settxt
        anchors.left: line.left
        anchors.leftMargin: 20
        anchors.bottom: line.top
        anchors.bottomMargin: 10
        font.pixelSize: fontPixSize
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
        text: "全体录像"
    }

    Text {
        id: labelResolution
        text: qsTr("分辨率")
        font.pixelSize: fontSize
        color: fontColor
        anchors.right: cmbResolution.left
        anchors.rightMargin: 10
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
        anchors.left: line.left
        anchors.leftMargin: parSetFirstAlignLine
        anchors.top: line.bottom
        anchors.topMargin: 52
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
        font.pixelSize: fontPixSize
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
            onEntered: txttimeStart.source = "qrc:/images/warnmanager/time.png"
            onReleased: txttimeStart.source = "qrc:/images/warnmanager/time.png"
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
}
