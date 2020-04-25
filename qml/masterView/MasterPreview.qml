import QtQuick 2.0

Rectangle {




    Rectangle{
        id:rectlistDevice
        x:0
        y:0
        width: 300
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
                anchors.left: deviceImg.right
                anchors.leftMargin: 8
                anchors.verticalCenter: parent.verticalCenter
                text: qsTr("设备列表")
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

                id:adddevice
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
                    text: qsTr("添加")
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
                            listDevice.currentIndex = index
                        }
                    }
                }
            }
        }
    }

    Rectangle{
        id:rectlistpersoninfo

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
                text: qsTr("告警记录")
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
        id:videoContent
        anchors.top: parent.top
        anchors.left: rectlistDevice.right

        width: parent.width - rectlistDevice.width - rectlistpersoninfo.width
        height: parent.height - rectlistwarninfo.height
        color: "red"
        GridView {
            anchors.fill: parent

        }
    }





    Rectangle{
        id:rectlistwarninfo
        width: videoContent.width
        height: 180
        color: "#202020"

        anchors.left: rectlistDevice.right
        anchors.bottom: parent.bottom
        ListView{
            width: parent.width
            height: parent.height
            orientation:ListView.Horizontal

            delegate: Rectangle{
                Image {
                    anchors.fill: parent
                    source: "file"
                }
                Rectangle{
                    color: "#193548"
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
                        text: qsTr("监控1")
                    }

                    Text {
                        anchors.right: parent.right
                        anchors.top: parent.top
                        anchors.rightMargin: 10
                        anchors.topMargin: 2
                        font.pixelSize: 16
                        color: "#FA3F00"
                        text: qsTr("37.5°C")
                    }
                    Text {
                        anchors.left: parent.left
                        anchors.bottom: parent.bottom
                        anchors.leftMargin: 10
                        anchors.bottomMargin:4
                        font.pixelSize: 8
                        color: "#ffffff"
                        text: qsTr("2020-03-01 14:20:01")
                    }
                }
            }
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
        to: 180
        duration: 800
        easing.type: Easing.OutCubic    //设置运动轨迹
    }




}
