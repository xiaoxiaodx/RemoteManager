import QtQuick.Controls 2.5
import QtQuick 2.0
import QtGraphicalEffects 1.12
import QtQuick.Dialogs 1.3
import Qt.labs.settings 1.0
import "../simpleControl"
Rectangle {
    id: root



    property int fontSize: 14
    property color fontColor: "#606266"
    //与线的左对齐线
    property int parSetFirstAlignLine: 104
    color: "#ffffff"

    Settings {
        id:setting

        fileName: "config.ini"

    }

    Text {
        id: timetxt
        anchors.left: line.left
        anchors.leftMargin: 20
        anchors.bottom: line.top
        anchors.bottomMargin: 10
        font.pixelSize: fontPixSize
        color: fontColor
        text: qsTr("时间")
    }


    Rectangle{
        id:line
        width: parent.width-20
        height: 1
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 147
        color: "#EBEEF5"
    }

    Text {
        id: labelSwitchTime
        text: qsTr("时间开关")
        font.pixelSize: fontSize
        color: fontColor
        anchors.right: swithTime.left
        anchors.rightMargin: 20
        anchors.verticalCenter: swithTime.verticalCenter
    }

    SimpleSwich{
        id:swithTime
        width: 30
        height: 15
        anchors.left: line.left
        anchors.leftMargin: parSetFirstAlignLine
        anchors.top: line.bottom
        anchors.topMargin: 20
       // onCheckedChanged: s_timeSwith(checked)
    }

    Text {
        id: nametxt
        anchors.left: line1.left
        anchors.leftMargin: 20
        anchors.bottom: line1.top
        anchors.bottomMargin: 10
        font.pixelSize: fontPixSize
        color: fontColor
        text: qsTr("名称")
    }
    Rectangle{
        id:line1
        width: parent.width-20
        height: 1
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 44
        color: "#EBEEF5"
    }

    Text {
        id: labelSwitchShow
        text: qsTr("显示开关")
        font.pixelSize: fontSize
        color: fontColor
        anchors.right: swithTime.left
        anchors.rightMargin: 20
        anchors.verticalCenter: swithShow.verticalCenter
    }

    SimpleSwich{
        id:swithShow
        width: 30
        height: 15
        anchors.left: line1.left
        anchors.leftMargin: parSetFirstAlignLine
        anchors.top: line1.bottom
        anchors.topMargin: 20
       // onCheckedChanged: s_timeSwith(checked)
    }
}
