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
    property int parSetFirstAlignLine: 88
    property int firstAlighnlineSpace: 10
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
        text: qsTr("NTP设置")
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



    Text {
        id: labelSwitchEnable
        text: qsTr("使能开关")
        font.pixelSize: fontSize
        color: fontColor
        anchors.right: swithNtpEnable.left
        anchors.rightMargin: firstAlighnlineSpace
        anchors.verticalCenter: swithNtpEnable.verticalCenter
    }

    SimpleSwich{
        id:swithNtpEnable
        width: 30
        height: 15
        anchors.left: line.left
        anchors.leftMargin: parSetFirstAlignLine
        anchors.top: line.bottom
        anchors.topMargin: 20
        // onCheckedChanged: s_timeSwith(checked)
    }



    Text {
        id: txtUrl
        font.pixelSize: fontPixSize
        color: fontColor
        anchors.right: inputurl.left
        anchors.rightMargin: firstAlighnlineSpace
        anchors.verticalCenter: inputurl.verticalCenter
        text: qsTr("URL")
    }

    LineEdit {
        id: inputurl
        width: 158
        height: 28
        anchors.left: line.left
        anchors.leftMargin: parSetFirstAlignLine
        anchors.top: line.bottom
        anchors.topMargin: 58
        border.width: 1
        border.color: "#DCDFE6"
         radius: 1
      //  text:screenv.funGetCurPath()
        font.pixelSize: fontSize
        placeholderText: ""
        isNeedDoubleClickEdit: false
        textLeftPadding:0
        txtColor: Qt.rgba(0,0,0,0.65)
       color: "#ffffff"
        //onTextChanged: s_recordPathSet(inputrecordPath.text)
    }

    Rectangle{
        id:btnUrlEnsure
        anchors.left: inputurl.right
        anchors.leftMargin: 20
        anchors.verticalCenter: inputurl.verticalCenter
        width: btnTxt.width + 20
        height: btnTxt.height +12
        color: "#0486FE"
        Text {
            id: btnTxt
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: fontPixSize
            color: "#ffffff"
            text: qsTr("确认")
        }
    }

    Text {
        id: labeltimezone
        text: qsTr("时区选择")
        font.pixelSize: fontSize
        color: fontColor
        anchors.left: line1.left
        anchors.leftMargin: 20
        anchors.bottom: line1.top
        anchors.bottomMargin: 10
    }

    Rectangle{
        id:line1
        width: parent.width-20
        height: 1
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 195
        color: "#EBEEF5"
    }

    ListModel{
        id:timezoneModel
        ListElement{showStr:"GMT+08:00北京"}
        ListElement{showStr:"GMT+08:00北京"}
        ListElement{showStr:"GMT+08:00北京"}
        ListElement{showStr:"GMT+08:00北京"}
        ListElement{showStr:"GMT+08:00北京"}
        ListElement{showStr:"GMT+08:00北京"}
    }

    MyComBox{
        id:cmbtimezone
        width:158
        height: 28
        anchors.left: line1.left
        anchors.leftMargin: 20
        anchors.top: line1.bottom
        anchors.topMargin: 20
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
        model: timezoneModel
        onCurrentIndexChanged: {

        }
    }


    Text {
        id: labelSunmerSet
        text: qsTr("夏令时设置")
        font.pixelSize: fontSize
        color: fontColor
        anchors.left: line2.left
        anchors.leftMargin: 20
        anchors.bottom: line2.top
        anchors.bottomMargin: 10
    }

    Rectangle{
        id:line2
        width: parent.width-20
        height: 1
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 308
        color: "#EBEEF5"
    }

    Text {
        id: labelSummerEnable
        text: qsTr("使能开关")
        font.pixelSize: fontSize
        color: fontColor
        anchors.right: swithSummerEnable.left
        anchors.rightMargin: firstAlighnlineSpace
        anchors.verticalCenter: swithSummerEnable.verticalCenter
    }

    SimpleSwich{
        id:swithSummerEnable
        width: 30
        height: 15
        anchors.left: line2.left
        anchors.leftMargin: parSetFirstAlignLine
        anchors.top: line2.bottom
        anchors.topMargin: 20
        // onCheckedChanged: s_timeSwith(checked)
    }
}
