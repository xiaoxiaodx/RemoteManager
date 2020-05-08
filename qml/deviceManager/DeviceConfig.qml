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
    closePolicy: Popup.NoAutoClose
    //设置窗口的背景控件，不设置的话Popup的边框会显示出来
    background: rect

    property bool isBatchSet: false
    property int fontPixSize: 14
    property color fontColor: "#606266"
    property color bgColor: "#ffffff"

    //property alias titlename: titletxt.text

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
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: fontPixSize
                text: {

                    if(isBatchSet){
                        switch(1){
                        case 1:
                            "设备批量配置";
                            break;
                        }

                    }else{
                        "设配配置"

                    }

                    }
                color: "white"
            }

            Image {
                id: imgclose
                width: 14
                height: 14
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                anchors.rightMargin: 16
                source:"qrc:/images/modal-close.png"
                MouseArea{
                    anchors.fill: parent
                    onClicked: root.close()
                }
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
            Rectangle{
                id:leftList
                width: 180
                height: parent.height -20
                color: "#EEF3FA"
                ListView{
                    id:leftListv
                    width: parent.width
                    height: parent.height
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
            }

            SwipeView{
                id:deviceconfigswipeview
                anchors.left: leftList.right
                anchors.top: parent.bottom
                width: parent.width - leftList.width
                height: parent.height
                currentIndex:leftListv.curSelectIndex+1
                interactive:false
                orientation: Qt.Vertical;
                SettingOSD{id:settingosd}
                SettingRecord{id:settingrecord}
                SettingRTMP{id:settingrtmp}
                SettingTime{id:settingtime;color: "#ffffff"}
                SettingTemp{id:settingtemp;color: "#ffffff"}
                SettingVideo{id:settingvideo;color: "#ffffff"}
            }


            Rectangle{
                id:btnCancel
                anchors.right: btnEnsure.left
                anchors.rightMargin: 14
                anchors.verticalCenter: btnEnsure.verticalCenter
                width: txtCancel.width + 30
                height: txtCancel.height +16
                color: "transparent"
                border.width: 1
                border.color: "#D9D9D9"
                radius: 4
                Text {
                    id: txtCancel
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.pixelSize: 12
                    color: "#D9D9D9"
                    text: qsTr("取消")
                }
                MouseArea{
                    anchors.fill: parent
                    onClicked: root.close()
                }
            }

            Rectangle{
                id:btnEnsure

                anchors.right: parent.right
                anchors.rightMargin: 30
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 20

                width: txtEnsure.width + 30
                height: txtEnsure.height +16
                border.width: 1
                border.color: "#0486FE"
                color: "transparent"
                radius: 4
                Text {
                    id: txtEnsure
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.pixelSize: 12
                    color: "#0486FE"
                    text: qsTr("确认")
                }
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        updateParameterInfo(leftListv.curSelectIndex);
                        root.close()
                    }
                }
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

    function flushParameterInfo(index){

        var deviceInfo = deviceModel.funGetDevice(index);

        settingosd.setOSD(deviceInfo.osdTimeShowSwitch,deviceInfo.osdNameShowSwitch,deviceInfo.osdName)

        settingrecord.setRecord(deviceInfo.recordType,deviceInfo.recordResolution,deviceInfo.recordPath,deviceInfo.recordStartT,deviceInfo.recordEndT,deviceInfo.recordWeeklyDate)

        settingrtmp.setRtmp(deviceInfo.rtmpSwitch,deviceInfo.recordResolution,deviceInfo.rtmpUrl,deviceInfo.rtmpUser,deviceInfo.rtmpPassword)

        settingtemp.setTempPar(deviceInfo.tempWarnSwitch,deviceInfo.tempWarnValue,deviceInfo.tempScreenShot,deviceInfo.tempScreenShotPath,deviceInfo.tempBeerSwitch,deviceInfo.tempDrift,deviceInfo.tempControlLevel)

        settingtime.settimePar(deviceInfo.timeNtpSwtich,deviceInfo.timeNtpUrl,deviceInfo.timeZone,deviceInfo.timeSummerSwitch)
    }

    function updateParameterInfo(index){

        console.debug("************ "+index)

        var deviceInfo = deviceModel.funGetDevice(index);



        settingosd.updateParameterInfo(deviceInfo)
        settingrecord.updateParameterInfo(deviceInfo)
        settingrtmp.updateParameterInfo(deviceInfo)
        settingtemp.updateParameterInfo(deviceInfo)
        settingtime.updateParameterInfo(deviceInfo)
    }
}

