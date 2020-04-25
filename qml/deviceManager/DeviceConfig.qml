import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 2.5
import QtGraphicalEffects 1.12
import "../simpleControl"
Popup {
    id: root


    modal: true
    focus: true
    //设置窗口关闭方式为按“Esc”键关闭
    closePolicy: Popup.CloseOnEscape|Popup.CloseOnPressOutside
    //设置窗口的背景控件，不设置的话Popup的边框会显示出来
    background: rect

    property int fontPixSize: 14
    property color fontColor: "#606266"
    property color bgColor: "#EEF3FA"

    property string title:""

    property alias titlename: titletxt.text
    Rectangle {
        id: rect
        anchors.fill: parent
        color: bgColor
        radius: 2

        Rectangle{
            id:header
            width: parent.width
            height: 38
            gradient: Gradient {
                GradientStop { position: 0.0; color: "#5D9CFF"}
                GradientStop { position: 1.0; color: "#2D76E7"}
            }

            Text {
                id: titletxt
                anchors.left: parent.left
                anchors.leftMargin: 16
                font.pixelSize: fontPixSize
                color: "white"
            }
        }

        Rectangle{
            id:content
            width: parent.width
            height: parent.height - header.height
            anchors.top: header.bottom
            anchors.left: parent.left
            color: bgColor
            ListModel{
                id:leftlistmodel
                ListElement { name: "OSD设置"}
                ListElement { name: "录像设置"}
                ListElement { name: "RTMP设置"}
                ListElement { name: "时间设置"}
                ListElement { name: "温度设置"}
                ListElement { name: "图像设置"}
            }
            ListView{
                id:leftListv
                width: 180
                height: parent.height -20
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.topMargin: 20
                property int curSelectIndex: 0
                model: leftlistmodel
                delegate: Rectangle{
                    width: parent.width
                    height: 34
                    color: leftListv.curSelectIndex === index?"#FFFFFF":"#EEF3FA"
                    Text {
                        id: itemtext
                        anchors.left: parent.left
                        anchors.leftMargin: 10
                        anchors.verticalCenter: parent.verticalCenter
                        color: fontColor
                        font.pixelSize: fontPixSize
                        text: name
                    }

                    MouseArea{
                        anchors.fill: parent
                        onClicked:  leftListv.curSelectIndex = index
                    }
                }
            }

            SwipeView{
                id:deviceconfigswipeview
                anchors.left: leftListv.right
                anchors.top: parent.bottom
                width: parent.width - leftListv.width
                height: parent.height
                currentIndex:leftListv.curSelectIndex+1
                interactive:false
                orientation: Qt.Vertical
                SettingOSD{id:settingosd}
                SettingRecord{id:settingrecord}
                SettingRTMP{id:settingrtmp}
                SettingTime{id:settingtime;color: "#ffffff"}
                SettingTemp{id:settingtemp;color: "#ffffff"}
                SettingVideo{id:settingvideo;color: "#ffffff"}
            }
            layer.enabled: true
            layer.effect: DropShadow {
                transparentBorder: true
                horizontalOffset: 4
                verticalOffset: 4
                color:"#30000000"
            }
        }
    }
}

