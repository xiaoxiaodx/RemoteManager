import QtQuick 2.0
import XVideo 1.0
import QtQuick.Controls 1.4
import "../simpleControl"
Rectangle {

    id:mPlayRect
    signal doubleClick(bool isFullScreen);
    signal click();
    signal s_showToastMsg(string str)

    signal s_authenticationFailue(string str)


    property bool mIsCreateConenect: false
    property bool mIsPlayAudio: false
    property bool mIsSelected: false
    property bool mIsRecordVedio: false

    property string shotScrennFilePath: ""
    property string recordingFilePath: ""
    property string belongDevice: ""

//    border.color: mIsSelected?"#409EFF":"#00000000"
//    border.width: 2
    color: "black"
    onMIsCreateConenectChanged: {
        console.debug("onMXVideoIsCreateTcpConnectChanged   "+ mIsCreateConenect)
        if(mIsCreateConenect){
            video.sendAuthentication(mID,mAcc,mPwd);
            video.connectServer(mip,mport)
        }else{
            video.disConnectServer();
        }
    }

    onMIsPlayAudioChanged: video.funPlayAudio(mIsPlayAudio)
    onShotScrennFilePathChanged: video.funSetShotScrennFilePath(shotScrennFilePath);
    onRecordingFilePathChanged: video.funSetRecordingFilePath(recordingFilePath)

    MouseArea{
        anchors.fill: parent
        hoverEnabled: true
        propagateComposedEvents:true
        onClicked: click();
        onDoubleClicked:doubleClick(true);
    }

    XVideo{
        id:video
        //anchors.fill: parent
       // anchors.margins: 2

        width:(mPlayRect.width*0.75>mPlayRect.height?mPlayRect.height*1.333:mPlayRect.width)
        height: (mPlayRect.width*0.75>mPlayRect.height?mPlayRect.height:mPlayRect.width*0.75)

        anchors.horizontalCenter: mPlayRect.horizontalCenter
        anchors.verticalCenter: mPlayRect.verticalCenter

        property bool mXVideoPlayAudio: mIsPlayAudio
        property bool mXVideoRecordVedio: mIsRecordVedio
        property bool mXVideoIsCreateTcpConnect: mIsCreateConenect

    }

    Text {
        id: txtbelongDeviceName
        font.pixelSize: 12
        font.family: "Microsoft Yahei"
        color: "red"
        anchors.left: parent.left
        anchors.leftMargin: 5
        anchors.top: parent.top
        text: belongDevice
    }

    Image {
        id: img_delete
        x:parent.x + parent.width - img_delete.width

        visible:   mIsSelected
        source: "qrc:/images/masterpreview/img_delete.png"

        MouseArea{
            anchors.fill: parent
            enabled: true

            onClicked: {

                screenBlack.visible = true;
                if(belongDeviceName==="")
                    showToast("no device specified ")
                else{
                    var nameNum = 0;
                    for(var i=0;i<listDeviceDataModel.count;i++){
                        if(belongDeviceName === listDeviceDataModel.get(i).deviceName)
                            nameNum ++;
                    }

                    if(nameNum > 1)
                        listDeviceDataModel.get(modelDataCurrentIndex).deviceName = ""
                    else{
                        var map;
                        devicemanagerment.funP2pSendData(belongDeviceName,"stopVideo",map);
                        listDeviceDataModel.get(modelDataCurrentIndex).deviceName = ""
                    }
                }
            }
        }
    }

    Rectangle{
        id:rectRecord
        anchors.bottom:parent.bottom
        anchors.bottomMargin: 1
        anchors.horizontalCenter: parent.horizontalCenter
        height: 50
        width: parent.width-2
        color:"#88000000"
        visible:mIsSelected
//            opacity: 0

//            states: [
//                State {
//                    name: "show"; PropertyChanges { target: rectRecord; opacity: 1 }
//                },
//                State {
//                    name: "hide"; PropertyChanges { target: rectRecord;  opacity: 0 }
//                }]

//            transitions: Transition {
//                PropertyAnimation  {properties: "opacity"; duration: 600; easing.type: Easing.Linear  }
//            }

//            MouseArea{
//                anchors.fill: parent
//                hoverEnabled: true
//                enabled: true
//                preventStealing:true
//                propagateComposedEvents:true
//                onEntered:if(mIsSelected)rectRecord.state = "show"
//                onExited:if(mIsSelected)rectRecord.state = "hide"
//                onDoubleClicked: ;
//            }

        Image{
            id:btnRecordVideo
            width: 30
            height: 30
            anchors.right: parent.right
            anchors.rightMargin: 40
            anchors.verticalCenter: parent.verticalCenter
            source:"qrc:/images/masterpreview/recordVideo_start.png"
            MouseArea{
                anchors.fill: parent
                onClicked: {

                    mIsRecordVedio = !mIsRecordVedio;
                    if(mIsRecordVedio){
                        btnRecordVideo.source = "qrc:/images/masterpreview/recordVideo_ing.png"
                        recordBtnClickFun(mIsRecordVedio);
                    }else{
                        btnRecordVideo.source = "qrc:/images/masterpreview/recordVideo_start.png"
                        //delayFun(500,recordBtnClickFun(mIsRecordVedio));
                    }

                }
                // onPressed:
                // onReleased: btnRecordVideo.source="qrc:/images/recordVideo_start.png"
            }
        }

        Image{
            id:btnScreenShot
            width: 30
            height: 30
            anchors.right: btnRecordVideo.left
            anchors.rightMargin: 25
            anchors.top: parent.top
            anchors.topMargin: 8
            source:"qrc:/images/masterpreview/screenshot.png"


            MouseArea{
                anchors.fill: parent

                //onClicked: delayFun(500,screenShotBtnClick());
                onPressed: btnScreenShot.source = "qrc:/images/masterpreview/screenshot_p.png"
                onReleased: btnScreenShot.source="qrc:/images/masterpreview/screenshot.png"
            }
        }
    }

//        Rectangle{
//            id:screenBlack
//            anchors.fill: parent
//            visible:true
//            color: "#3A3D41"
//        }

    Rectangle{
        id:screenShotMask
        anchors.fill: parent
        color: "white"
        opacity: 0

        SequentialAnimation {

            id:animationOpacity
            NumberAnimation { target: screenShotMask; property: "opacity"; to: 0.5; duration: 100 }
            NumberAnimation { target: screenShotMask; property: "opacity"; to: 0; duration: 100 }
        }
        function startAnimation(){
            animationOpacity.start();
        }
    }

    Connections{
        target: deviceModel
        onSignal_p2pCallbackVideoData:{
            //console.debug("***************  "+name + "  "+belongDeviceName)
            if(belongDevice === name)
                video.funSendVideoData(h264Arr)
        }
    }


    function recordBtnClickFun(isrecord){

        //devicemanagerment.funRecordVideo(isrecord,belongDeviceName)

    }

    function screenShotBtnClick(){

        screenShotMask.startAnimation();
        //video.funScreenShot();
    }
}



