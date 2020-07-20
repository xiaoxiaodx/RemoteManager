import QtQuick 2.0
import "../simpleControl"
import QtQuick.Controls 1.4
import Qt.labs.settings 1.0
import QtGraphicalEffects 1.12
Rectangle {


    objectName: "masterpreview"

    Settings{
        id:settings
        fileName: "config.ini"
        property alias window1: mW1.checked;
        property alias window4: mW4.checked;
        property alias window9: mW9.checked;
        property alias window16: mW16.checked;
    }


    property int numberWindow: 4

    Rectangle{
        id:rectlistDevice
        objectName: "rectlistDevice"
        x:0
        y:0
        width: 300
        property int preWidth : 300
        height: parent.height
        color: "#F0F5FB"

        Rectangle{
            id:listHeader
            width: parent.width
            height: 65
            color: "#F0F5FB"

            Image {
                id: deviceImg
                width: 18
                height: 18
                anchors.left: parent.left
                anchors.leftMargin: 16
                anchors.verticalCenter: parent.verticalCenter
                source: "qrc:/images/masterpreview/deviceheader.png"
            }

            Text {
                id: devicelisttxt
                font.pixelSize: 16
                color: "#303133"
                font.bold: true
                anchors.left: deviceImg.right
                anchors.leftMargin: 8
                anchors.verticalCenter: parent.verticalCenter
                text: mylanguage.DeviceList
            }

            Image {
                id: deviceDown
                width: 10
                height: 6
                anchors.left: devicelisttxt.right
                anchors.leftMargin: 10
                anchors.verticalCenter: parent.verticalCenter
                source: "qrc:/images/masterpreview/devicedown.png"
            }

            Rectangle{

                id:adddevicerect
                height: (imgAdd.height>txtAdd.height ? imgAdd.height : txtAdd.height)+6
                width: imgAdd.width + txtAdd.width + 12
                color: "#0486FE"
                anchors.right: parent.right
                anchors.rightMargin: 30
                anchors.verticalCenter: parent.verticalCenter
                radius: 2
                Image {
                    id: imgAdd
                    width: 14
                    height: 14
                    anchors.left: parent.left
                    anchors.leftMargin: 4
                    anchors.verticalCenter: parent.verticalCenter
                    source: "qrc:/images/masterpreview/deviceAdd.png"
                }
                Text {
                    id: txtAdd
                    anchors.left: imgAdd.right
                    anchors.leftMargin: 4
                    anchors.verticalCenter: parent.verticalCenter
                    color: "#ffffff"
                    font.pixelSize: 12
                    text: mylanguage.Add
                }
                MouseArea{
                    anchors.fill: parent
                    onClicked: adddevice.open()
                }
            }
        }

        ListView{
            id:listDevice
            width: parent.width
            height: parent.height - listHeader.height
            anchors.left: parent.left
            anchors.top: listHeader.bottom
            model: deviceModel
            delegate: Rectangle{

                width: parent.width
                height: 45
                color: listDevice.currentIndex === index ?"#D7DFE9":"transparent"
                Rectangle{
                    width: 6
                    height: parent.height
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    color: "#0486FE"
                    visible: listDevice.currentIndex === index
                }

                Text {
                    color: "#303133"
                    font.pixelSize: 16
                    anchors.left: parent.left
                    anchors.leftMargin: 42
                    anchors.verticalCenter: parent.verticalCenter
                    text: model.deviceName
                }



                Image {
                    width: 16
                    height: 16
                    anchors.right: parent.right
                    anchors.rightMargin: 30
                    anchors.verticalCenter: parent.verticalCenter
                    source: "qrc:/images/masterpreview/deviceset.png"
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            systemsetting.openDeviceConfig(false,model.deviceChannel);
                        }
                    }
                }

                MouseArea{
                    anchors.fill: parent
                    propagateComposedEvents: true
                    onDoubleClicked: {


                            var map = {cmd:"getVedio"};
                            deviceModel.funSendData1(model.deviceChannel,"getVedio",map)

                    }
                    onClicked: {

                        listDevice.currentIndex = index
                        mouse.accepted = false
                    }
                }
            }
        }
    }

    Rectangle{
        id:rectlistpersoninfo
        property int preWidth: 217
        anchors.right: parent.right
        anchors.top: parent.top
        width: 217
        height: parent.height
        Rectangle{
            id:personinfoHeader
            width: parent.width
            height: 39
            anchors.top: parent.top
            anchors.right: parent.right
            Text {
                id: txttitle
                anchors.left: parent.left
                anchors.leftMargin: 10
                anchors.verticalCenter: parent.verticalCenter
                text: mylanguage.AlarmRecord
            }
            Image {
                id: imgtitle
                width: 18
                height: 18
                anchors.right: personinfoHeader.right
                anchors.rightMargin: 10
                anchors.verticalCenter: parent.verticalCenter
                source: "qrc:/images/masterpreview/warnrecor.png"
            }
        }

        ListView{
            id:listpersoninfo
            width: parent.width
            height: parent.height - personinfoHeader.height
            anchors.top: personinfoHeader.bottom
            anchors.left: parent.left
            delegate: Rectangle{

                Image {
                    id:imgphoto
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    //source: "file"
                }
                Text {
                    id:devicename
                    anchors.left: imgphoto.right
                    anchors.leftMargin: 10
                    anchors.top: parent.top
                    anchors.topMargin: 4
                    font.pixelSize: 10
                    color: "#0486FE"
                    text: qsTr("监控1")
                }

                Image {
                    id: imgtemp
                    anchors.left: devicename.left
                    anchors.top: devicename.top
                    anchors.topMargin: 15
                    width: 12
                    height: 12
                    source: "file"
                }
                Text {
                    id: texttemp
                    anchors.left: imgtemp.right
                    anchors.leftMargin: 10
                    anchors.verticalCenter: imgtemp.verticalCenter
                    font.pixelSize: 10
                    color: "#333333"
                    text: qsTr("36.3")
                }

                Image {
                    id: imgname
                    anchors.left: devicename.left
                    anchors.top: devicename.top
                    anchors.topMargin: 36
                    width: 12
                    height: 12
                    source: "file"
                }
                Text {
                    id: textname
                    anchors.left: imgname.right
                    anchors.leftMargin: 10
                    anchors.verticalCenter: imgname.verticalCenter
                    font.pixelSize: 10
                    color: "#333333"
                    text: qsTr("36.3")
                }

                Image {
                    id: imgnumber
                    anchors.left: devicename.left
                    anchors.top: devicename.top
                    anchors.topMargin: 57
                    width: 12
                    height: 12
                    source: "file"
                }
                Text {
                    id: textnumber
                    anchors.left: imgnumber.right
                    anchors.leftMargin: 10
                    anchors.verticalCenter: imgnumber.verticalCenter
                    font.pixelSize: 10
                    color: "#333333"
                    text: qsTr("36.3")
                }

                Text {
                    id: txtTime
                    font.pixelSize: 8
                    color: "#666666"
                    anchors.left: devicename.left
                    anchors.top: devicename.top
                    anchors.topMargin: 84
                    text: qsTr("2020-03-01 13:40:00")
                }
            }
        }
    }


    Rectangle{
        id:rectlistwarninfo
        property int preHeight: 160
        width: videoContent.width
        height: 160
        color: "#202020"
        z:1
        anchors.left: rectlistDevice.right
        anchors.bottom: parent.bottom
        ListView{
            width: parent.width
            height: parent.height
            orientation:ListView.Horizontal
            model: warnmodel
            delegate: Rectangle{
                width: 120
                height: parent.height
                color: "#202020"
                Rectangle{

                    anchors.fill: parent
                    anchors.margins: 5

                    Image {
                        anchors.fill: parent
                        source: "file:///"+ model.absolutePath
                    }
                    Rectangle{
                        color: "#cc193548"
                        width: parent.width
                        height: 38
                        anchors.bottom: parent.bottom

                        Text {

                            anchors.left: parent.left
                            anchors.top: parent.top
                            anchors.leftMargin: 10
                            anchors.topMargin: 7
                            font.pixelSize: 8
                            color: "#ffffff"
                            text: model.deviceChannel
                        }

                        Text {
                            anchors.right: parent.right
                            anchors.top: parent.top
                            anchors.rightMargin: 10
                            anchors.topMargin: 2
                            font.pixelSize: 16
                            color: "#FA3F00"
                            text: model.warnTemp
                        }
                        Text {
                            anchors.left: parent.left
                            anchors.bottom: parent.bottom
                            anchors.leftMargin: 10
                            anchors.bottomMargin:4
                            font.pixelSize: 8
                            color: "#ffffff"
                            text: model.warnTime
                        }
                    }
                }
            }
        }

        layer.enabled: true
    }

    Rectangle{
        id:videoContent
        anchors.top: parent.top
        anchors.left: rectlistDevice.right
        width: parent.width - rectlistDevice.width - rectlistpersoninfo.width
        height: parent.height - rectlistwarninfo.height


        objectName: "videoContent"
        Rectangle{
            id:rectVideo
            width: parent.width
            height: videoContent.height - videoMutilWindow.height
            GridView {
                id:gridViewVideo
                objectName: "gridViewVideo"
                anchors.fill: parent
                model: videoShowModel
                interactive: false
                cacheBuffer:1920*50
                cellWidth: (rectVideo.width)/numberWindow
                cellHeight: (rectVideo.height)/numberWindow
                property int curSelectIndex: -1
                property int beforeMaxPos: 0
                property int beforeMaxNumW: 0
                property bool isMax: false
                focus: true

                delegate: Rectangle{
                    id:delegateRect
                    width: gridViewVideo.cellWidth
                    height: gridViewVideo.cellHeight
                    color: "#202020"
                    border.width: 1
                    border.color: gridViewVideo.curSelectIndex===index?"#5697FB":"#131415"
                    VideoShow{
                        id:videoshow
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.horizontalCenter: parent.horizontalCenter
                        width: parent.width-2
                        height: parent.height-2
                        mIsSelected:gridViewVideo.curSelectIndex === index
                        belongDevice: channel
                        onClick: gridViewVideo.curSelectIndex = index

                        onDoubleClick: {
                            console.debug("onDoubleClick    " +belongDevice)
                            if(mW1.checked)
                                return;
                            if(!gridViewVideo.isMax)
                                gridViewVideo.maxW(index)
                            else
                                gridViewVideo.restoreW()

                        }

                    }
                }
                function maxW(posIndex){
                    gridViewVideo.isMax = true

                    console.debug(" maxW "+posIndex + "   "+numberWindow)

                    gridViewVideo.beforeMaxPos = posIndex
                    gridViewVideo.beforeMaxNumW = numberWindow

                    videoShowModel.move(posIndex,0,1);

                    numberWindow = 1;
                }
                function restoreW(){
                    gridViewVideo.isMax = false

                    console.debug(" restoreW "+gridViewVideo.beforeMaxNumW + "   "+gridViewVideo.beforeMaxPos)

                    videoShowModel.move(0,gridViewVideo.beforeMaxPos,1);

                    numberWindow = gridViewVideo.beforeMaxNumW;

                    gridViewVideo.curSelectIndex = gridViewVideo.beforeMaxPos
                }

                function addjustWindowNum(num){
                    if(num === 1){
                        gridViewVideo.isMax = true
                        var posIndex = gridViewVideo.curSelectIndex
                        if(posIndex < 0)
                            posIndex = 0;
                        console.debug(" maxW "+posIndex + "   "+numberWindow)

                        gridViewVideo.beforeMaxPos = posIndex
                        gridViewVideo.beforeMaxNumW = numberWindow

                        videoShowModel.move(posIndex,0,1);


                    }else{

                        if(gridViewVideo.isMax){
                            gridViewVideo.isMax = false
                            console.debug(" restoreW "+gridViewVideo.beforeMaxNumW + "   "+gridViewVideo.beforeMaxPos)
                            videoShowModel.move(0,gridViewVideo.beforeMaxPos,1);
                            numberWindow = gridViewVideo.beforeMaxNumW;
                            gridViewVideo.curSelectIndex = gridViewVideo.beforeMaxPos
                        }
                    }
                    numberWindow = num;
                }
            }
        }
        Rectangle{
            id:videoMutilWindow
            width: parent.width
            height: isFullScreen ?0:34
            anchors.bottom: parent.bottom

            gradient: Gradient {
                GradientStop { position: 0.0; color: "#5D9CFF"}
                GradientStop { position: 1.0; color: "#2D76E7"}
            }
            ExclusiveGroup { id: buttonGroup }

            SimpleCheckedButton{
                id:mW1
                anchors.right: parent.right
                anchors.rightMargin: 139
                anchors.verticalCenter: parent.verticalCenter
                exclusiveGroup: buttonGroup
                isOnlySelect:true
                color: "transparent"
                imgW: 24
                imgH: 24
                imgSrc: "qrc:/images/masterpreview/video1.png"
                imgCheckSrc: "qrc:/images/masterpreview/video1_s.png"
                onCheckedChanged: {
                    if(mW1.checked)gridViewVideo.addjustWindowNum(1);
                }
            }
            SimpleCheckedButton{
                id:mW4
                anchors.right: parent.right
                anchors.rightMargin: 102
                anchors.verticalCenter: parent.verticalCenter
                exclusiveGroup: buttonGroup
                isOnlySelect:true
                color: "transparent"
                imgW: 24
                imgH: 24
                imgSrc: "qrc:/images/masterpreview/video4.png"
                imgCheckSrc: "qrc:/images/masterpreview/video4_s.png"
                onCheckedChanged: {

                    if(mW4.checked)gridViewVideo.addjustWindowNum(2)
                }

            }

            SimpleCheckedButton{
                id:mW9
                anchors.right: parent.right
                anchors.rightMargin: 66
                anchors.verticalCenter: parent.verticalCenter
                color: "transparent"
                exclusiveGroup: buttonGroup
                isOnlySelect:true
                imgW: 24
                imgH: 24
                imgSrc: "qrc:/images/masterpreview/video9.png"
                imgCheckSrc: "qrc:/images/masterpreview/video9_s.png"
                onCheckedChanged: {

                    if(mW9.checked)gridViewVideo.addjustWindowNum(3)
                }
            }
            SimpleCheckedButton{
                id:mW16
                anchors.right: parent.right
                anchors.rightMargin: 30
                anchors.verticalCenter: parent.verticalCenter
                color: "transparent"
                exclusiveGroup: buttonGroup
                isOnlySelect:true
                imgW: 24
                imgH: 24
                imgSrc: "qrc:/images/masterpreview/video16.png"
                imgCheckSrc: "qrc:/images/masterpreview/video16_s.png"
                onCheckedChanged: {

                    if(mW16.checked)gridViewVideo.addjustWindowNum(4)
                }
            }
            layer.enabled: true
        }
    }

    Image {
        id: imgDecicelistDrag

        property bool isShow: true
        source: isShow?"qrc:/images/masterpreview/devicelist_left.png":"qrc:/images/masterpreview/devicelist_right.png"
        anchors.left: rectlistDevice.right
        anchors.verticalCenter: rectlistDevice.verticalCenter
        width: 9
        height: 100

        MouseArea{
            anchors.fill: parent

            onClicked:{

                if(imgDecicelistDrag.isShow)
                    animationLeftHide.start()
                else
                    animationLeftShow.start()

            }
        }
    }

    NumberAnimation{
        id: animationLeftHide
        target: rectlistDevice
        properties:"width"
        to: 0
        duration: 800
        easing.type: Easing.OutCubic    //设置运动轨迹
        onStopped: imgDecicelistDrag.isShow = false;
    }

    NumberAnimation{
        id: animationLeftShow
        target: rectlistDevice
        properties:"width"
        to: 300
        duration: 800
        easing.type: Easing.OutCubic
        onStopped: imgDecicelistDrag.isShow = true;
    }

    Image {
        id: imgPersoninfolistDrag
        property bool isShow: true
        source: isShow?"qrc:/images/masterpreview/devicelist_right.png":"qrc:/images/masterpreview/devicelist_left.png"
        anchors.right: rectlistpersoninfo.left
        anchors.verticalCenter: rectlistpersoninfo.verticalCenter
        width: 9
        height: 100
        MouseArea{
            anchors.fill: parent

            onClicked:{

                if(imgPersoninfolistDrag.isShow )
                    animationRightHide.start();
                else
                    animationRightShow.start();
            }
        }
    }

    NumberAnimation{
        id: animationRightHide
        target: rectlistpersoninfo
        properties:  "width"
        to: 0
        duration: 800
        easing.type: Easing.OutCubic
        onStopped: imgPersoninfolistDrag.isShow = false
    }
    NumberAnimation{
        id: animationRightShow
        target: rectlistpersoninfo
        properties:  "width"
        to: 217
        duration: 800
        easing.type: Easing.OutCubic
        onStopped: imgPersoninfolistDrag.isShow = true
    }


    NumberAnimation{
        id: animationBottomHide
        target: rectlistwarninfo
        properties:  "height"
        to: 0
        duration: 800
        easing.type: Easing.OutCubic

    }
    NumberAnimation{
        id: animationBottomShow
        target: rectlistwarninfo
        properties:  "height"
        to: 160
        duration: 800
        easing.type: Easing.OutCubic    //设置运动轨迹
    }


    Connections{
        target: main

        onSfullScreenChange:{

            if(isFull){

                rectlistwarninfo.preHeight = rectlistwarninfo.height
                rectlistpersoninfo.preWidth = rectlistpersoninfo.width
                rectlistDevice.preWidth = rectlistDevice.width
                animationBottomHide.start();
                animationRightHide.start();
                animationLeftHide.start();
                gridViewVideo.curSelectIndex = -1
            }else{

                if(rectlistwarninfo.preHeight > 0){
                    animationBottomShow.start();
                }

                if(rectlistpersoninfo.preWidth > 0){
                    animationRightShow.start();
                }
                if(rectlistDevice.preWidth > 0){
                    animationLeftShow.start();
                }

                //                animationBottomShow.start();
                //                animationRightShow.start();
                //                animationLeftShow.start();
            }
        }
    }


}
