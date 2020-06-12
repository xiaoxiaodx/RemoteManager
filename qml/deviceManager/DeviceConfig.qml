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
    property string deviceChannel: "-1"

    property int curSelectIndex: 0
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

                        mylanguage.BatchSetting

                    }else{


                        mylanguage.Set+"(ch:"+deviceChannel+")"


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

                Component.onCompleted: {
                    leftlistmodel.append({name:mylanguage.OsdSet})
                    leftlistmodel.append({name:mylanguage.RecordSet})
                    leftlistmodel.append({name:mylanguage.RtmpSet})
                    leftlistmodel.append({name:mylanguage.Time})
                    leftlistmodel.append({name:mylanguage.TempSet})
                }

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

                    model: leftlistmodel
                    delegate: Rectangle{
                        width: parent.width
                        height: 34
                        color: curSelectIndex === index?"#FFFFFF":"#EEF3FA"
                        Text{
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
                            onClicked:  {

                                curSelectIndex = index

                                console.debug("curSelectIndex   "+curSelectIndex)

                                var deviceInfo = deviceModel.funGetDevice(deviceChannel);

                                switch(index){
                                case 0:
                                    console.debug("settingosd:"+deviceInfo.osdTimeShowSwitch+"    "+deviceInfo.osdNameShowSwitch+"    "+deviceInfo.osdName)
                                    settingosd.setOSD(deviceInfo.osdTimeShowSwitch,deviceInfo.osdNameShowSwitch,deviceInfo.osdName);
                                    break;
                                case 1:
                                    console.debug("settingrecord:"+deviceInfo.recordType+"    "+deviceInfo.recordResolution+"    "+deviceInfo.recordPath+"    "+deviceInfo.recordStartT+"    "+deviceInfo.recordEndT+"    "+deviceInfo.recordWeeklyDate)
                                    settingrecord.setRecord(deviceInfo.recordType,deviceInfo.recordResolution,deviceInfo.recordPath,deviceInfo.recordStartT,deviceInfo.recordEndT,deviceInfo.recordWeeklyDate)
                                    break;
                                case 2:
                                    console.debug("settingrtmp:"+deviceInfo.rtmpSwitch+"    "+deviceInfo.recordResolution+"    "+deviceInfo.rtmpUrl+"    "+deviceInfo.rtmpUser+"    "+deviceInfo.rtmpPassword)
                                    settingrtmp.setRtmp(deviceInfo.rtmpSwitch,deviceInfo.recordResolution,deviceInfo.rtmpUrl,deviceInfo.rtmpUser,deviceInfo.rtmpPassword)
                                    break;
                                case 3:
                                    console.debug("settingtime:"+deviceInfo.timeNtpSwtich+"    "+deviceInfo.timeNtpUrl+"    "+deviceInfo.timeZone+"    "+deviceInfo.timeSummerSwitch)
                                    settingtime.settimePar(deviceInfo.timeNtpSwtich,deviceInfo.timeNtpUrl,deviceInfo.timeZone,deviceInfo.timeSummerSwitch)
                                    break;
                                case 4:
                                    console.debug("setTempPar:"+deviceInfo.tempWarnSwitch+"    "+deviceInfo.tempWarnValue+"    "+deviceInfo.tempScreenShot+"    "+deviceInfo.tempScreenShotPath+"    "+deviceInfo.tempBeerSwitch+"    "+deviceInfo.tempDrift+"    "+deviceInfo.tempControlLevel)
                                    settingtemp.setTempPar(deviceInfo.tempWarnSwitch,deviceInfo.tempWarnValue,deviceInfo.tempScreenShot,deviceInfo.tempScreenShotPath,deviceInfo.tempBeerSwitch,deviceInfo.tempDrift,deviceInfo.tempControlLevel
                                                           ,deviceInfo.tempdriftcaplevelMin,deviceInfo.tempdriftcaplevelMax,deviceInfo.tempcontrolcaplevelMin,deviceInfo.tempcontrolcaplevelMax)
                                    break;
                                case 5:
                                    break;
                                }
                            }
                        }
                    }
                }
            }

            Rectangle{
                anchors.left: leftList.right
                anchors.top: parent.bottom
                width: parent.width - leftList.width
                height: parent.height

                SwipeView{
                    id:deviceconfigswipeview
                    anchors.fill: parent
                    currentIndex:curSelectIndex+1
                    interactive:false
                    onCurrentIndexChanged: {
                        console.debug(  "currentIndex   "+currentIndex)
                    }
                    orientation: Qt.Vertical;
                    SettingOSD{id:settingosd}
                    SettingRecord{id:settingrecord}
                    SettingRTMP{id:settingrtmp}
                    SettingTime{id:settingtime}
                    SettingTemp{id:settingtemp}
                    Rectangle{
                        id:sss
                        color:"red";
                    }
                }
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
                    text: mylanguage.AskMsgCancel
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
                    text: mylanguage.AskMsgEnsure
                }
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        updateParameterInfo(deviceChannel);
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


    function updateParameterInfo(channel){


        console.debug("*************** "+channel)
        settingosd.updateParameterInfo()
        settingrecord.updateParameterInfo()
        settingrtmp.updateParameterInfo()
        settingtemp.updateParameterInfo()
        settingtime.updateParameterInfo()


    }


    Connections{
        target: mylanguage
        onSignal_updateLan:{
            leftlistmodel.clear()
            leftlistmodel.append({name:mylanguage.OsdSet})
            leftlistmodel.append({name:mylanguage.RecordSet})
            leftlistmodel.append({name:mylanguage.RtmpSet})
            leftlistmodel.append({name:mylanguage.Time})
            leftlistmodel.append({name:mylanguage.TempSet})
        }
    }
}

