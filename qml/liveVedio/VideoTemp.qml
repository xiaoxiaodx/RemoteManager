import QtQuick 2.0
import QtQuick 2.0
import Qt.labs.settings 1.0
import QtQuick.Controls 1.4
import "../simpleControl"
import XVideo 1.0
Rectangle {

    id:mPlayRect
    signal doubleClick(bool isFullScreen);
    signal click();
    signal s_showToastMsg(string str)
    signal s_sendList(var vmap)

    property bool mIsSelected: false
    border.color: mIsSelected?"#98C5FF":"#252525"
    border.width: 3


    MouseArea{
        anchors.fill: parent
        //hoverEnabled: true
        propagateComposedEvents:true
        onClicked: {
            click()
           // mouse.accepted = false
        }
        onDoubleClicked:doubleClick(true);

    }
    XVideo{
        id:video

        width:(mPlayRect.width*0.75>mPlayRect.height?mPlayRect.height*1.333:mPlayRect.width) -6
        height: (mPlayRect.width*0.75>mPlayRect.height?mPlayRect.height:mPlayRect.width*0.75) -6

        anchors.horizontalCenter: mPlayRect.horizontalCenter
        anchors.verticalCenter: mPlayRect.verticalCenter


        //Component.onCompleted:video.startTemperatureVideo(deviceconfig.getWarnTem(),"EO3");

        onSignal_loginStatus: main.showToast(msg);


    }
    Connections{
        target: videoNormal
        onS_tempmodelSelect:{

            if(mtype === "J07")
                video.startTemperatureVideo(deviceconfig.getWarnTem(),mtype,deviceconfig.getJ07ip())
            else
                video.startTemperatureVideo(deviceconfig.getWarnTem(),mtype);
        }
    }




    Connections{
        target: deviceconfig
        onS_timeSwith:video.fun_timeSwitch(mchecked);
        onS_temSet:video.fun_temSet( mvalue);

        onS_temMax:video.fun_temMax(mvalue);
        onS_temMin:video.fun_temMin(mvalue);
        onS_temOffset:video.fun_temOffset(mvalue);
        onS_temImage:video.fun_colorShowType(mvalue);
    }

    function httpParCallback(smap){

        console.debug("smap:"+smap)
        var strcmd = smap.cmd;
        console.debug("strcmd:"+strcmd)

        console.debug(" " + strcmd);
        if(strcmd === "getosdparam"){
            var enable = map.enable;

        }else if(strcmd === "getrecordparam"){

        }
    }
    function tempParCallback(smap){

        var cmdType = smap.parType;

        if(cmdType === "temp"){
            var num = parseFloat(deviceconfig.getWarnTem()).toFixed(2)
            var tempV = smap.tempValue;
            if( Number(tempV) >= Number(num)){
                vedioLayout.startWarn(tempV);
            }else{
                //  vedioLayout.endWarn();
            }
        }
    }


    function updateDate(){
        video.fun_updateDate();
    }

}



