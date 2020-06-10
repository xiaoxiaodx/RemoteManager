import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Window 2.12
import QtQml 2.12
import QtMultimedia 5.8
import QtQuick.Controls 2.5
import "../qml/liveVedio"
import "../qml/playbackVideo"
import "../qml/masterView"
import "../qml/deviceManager"
import "../qml/dataManager"
import "../qml/warnManager"
import "../qml/dialog"
import "simpleControl"
Rectangle {

    enum ADJUSTW {
        WTOP,
        WBOTTOM,
        WLEFT,
        WRIGHT,
        WLEFTTOP,
        WRIGHTTOP,
        WLEFTBOTTOM,
        WRIGHTBOTTOM
    }
    id: maincontent;

    property bool fullscreen: false
    property bool isPress: false

    property int mWindowStates: 4   // 2：正常 4：最大化

    property int preX:0
    property int preY:0
    property int preWidth:0
    property int preHeight:0

    property string toastStr: ""

    property string versionstr: "version: v1.1.2"




    //   property int modelDataCurrentIndex: -1

    visible: false

    signal winMin();
    signal winMax();
    signal winClose();
    signal dragPosChange(var mx,var my);
    color: "#252525"




    HomeMenu{
        id:homeMenu
        property bool isDoubleClick: false
        anchors.top: parent.top
        anchors.left: parent.left
        width: parent.width
        height: 68
        z:isFullScreen?0:2
        gradient: Gradient {
            GradientStop { position: 0.0; color: "#5D9CFF"}
            GradientStop { position: 1.0; color: "#2D76E7"}
        }

        onSwinMin:  winMin()
        onSwinClose: winClose()
        onSwinMax: winMax()
        onSFullScreen:isFullScreen = true
    }

    SwipeView {
        id:vedioContent
        anchors.left: parent.left
        anchors.top: homeMenu.bottom
        width: parent.width
        height: parent.height - homeMenu.height
        currentIndex:homeMenu.mCurIndex
        interactive:false
        Component.onCompleted:{
            contentItem.highlightMoveDuration = 0      //将移动时间设为0
        }
        z:1
        MasterPreview{
            id:masterpreview
        }
        PlaybackVideo{
            id:playVideo
        }
        DeviceManager{
            id:systemsetting
        }

        WarnManager{
            id:warnmanger
        }

        DataManager{
            id:dataManager
        }
        About{
            id:about
        }
    }


    DeviceConfig{
        id:deviceconfig
        width: 800
        height: 600
        anchors.centerIn: parent
    }

    MediaPlayer {
        id: playWarn
        source: "qrc:/alarm.wav"
    }

    Timer{
        id:captureScrennTimer
        property int tCount: 0
        property bool isRecord: false
        triggeredOnStart:true

        repeat:true

        interval: 40;

        onTriggered: {

            if(!isRecord){
                screenv.funForfinishRecord();
                captureScrennTimer.stop();
                return;
            }

            screenv.funScreenRecrod(deviceconfig.getRecordPath(),main,0 ,68,main.width,main.height-68);
        }
    }



    Timer{
        id:warnTimer
        property bool isDelay1000: true
        repeat: false
        interval: 1000
        triggeredOnStart:false
        onTriggered: {

            warnTimer.isDelay1000 = true;
        }
    }

    AddDevice{
        id:adddevice
        width: 427
        height: 274
        onS_addDevice: {

            if(!deviceModel.funAddDevice(devcieID,devicename,"admin","admin")){
                ;//提示通道已满
            }

        }
    }


    NumberAnimation{
        id: animationMenuShow
        target: homeMenu
        properties:  "height"
        to: 68
        duration: 800
        easing.type: Easing.OutCubic    //设置运动轨迹
    }

    NumberAnimation{
        id: animationMenuHide
        target: homeMenu
        properties:  "height"
        to: 0
        duration: 800
        easing.type: Easing.OutCubic    //设置运动轨迹
    }

    Connections{
        target: main
        onSfullScreenChange:{
            if(isFull){
                animationMenuHide.start()
            }else{
                animationMenuShow.start()
            }
        }
    }
}
