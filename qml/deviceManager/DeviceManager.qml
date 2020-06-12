import Qt.labs.settings 1.0
import QtQuick 2.0
import QtQuick.Controls 2.5
import "../simpleControl"
Rectangle {
    id: root
    property int checkedHeaderLeftMargin: 22
    property int deviceIDHeaderLeftMargin: 46
    property int deviceNameHeaderLeftMargin: 244
    property int deviceChnHeaderLeftMargin: 350
    property int recordPathHeaderLeftMargin: 450 //419
    property int stateHeaderLeftMargin: 793
    property int doHeaderLeftMargin: 969
    property int fontSize: 14

    property int listviewClickIndex: -1
    property bool isAllSelect: false

    signal s_allselect(bool isSelect);

    color: "#EEF3FA"


    //    Settings{
    //        id:settings
    //        fileName: "config.ini"
    //        property alias window1: value;
    //        property alias window1: value;
    //        property alias window1: value;
    //        property alias window1: value;
    //    }
    Rectangle{
        id:recDeviceArea
        width: parent.width-420 >1200?(parent.width-420):1200
        height: parent.height-60
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        color: "#ffffff"
        radius: 10
        //加个矩形是为了解决listview显示越界的问题
        //        Rectangle{
        //            anchors.top: recDeviceArea.top
        //            width: parent.width
        //            height: 84
        //            color: "#ffffff"
        //            z:1
        //        }
        //第一排控件

        Rectangle{
            id:rectBatchDelete
            width: txtBatchDelete.width + imgBatchDelete.width +27
            height: 34
            color: "#0486FE"
            radius: 4
            anchors.left: parent.left
            anchors.leftMargin: 30
            anchors.top: parent.top
            anchors.topMargin: 30
            z:2
            Image {
                id: imgBatchDelete
                width: 14
                height: 15
                anchors.left: parent.left
                anchors.leftMargin: 9
                anchors.verticalCenter: parent.verticalCenter
                source: "qrc:/images/systemset/batchDelete.png"

            }
            Text {
                id: txtBatchDelete
                font.pixelSize: fontSize
                anchors.left: imgBatchDelete.right
                anchors.leftMargin: 9
                anchors.verticalCenter: parent.verticalCenter
                color: "#ffffff"
                text: mylanguage.BatchDelete
            }
            MouseArea{
                anchors.fill: parent

                onClicked: {

                    askDialog.width = 427
                    askDialog.height = 176
                    askDialog.askStr = mylanguage.AskMsgDelete
                    askDialog.imgSrc = "qrc:/images/ico_warn.png"
                    askDialog.curType = askDialog.deviceInfoMutipleDelete
                    askDialog.open();

                }
                onPressed: rectBatchDelete.color = "#81C3FF"
                onReleased: rectBatchDelete.color = "#0486FE"
            }
        }

        Rectangle{
            id:rectBatchSet
            width: imgBatchSet.width + txtBatchSet.width +27
            height: 34
            color: "#71C648"
            radius: 4
            anchors.left: rectBatchDelete.right
            anchors.leftMargin: 20
            anchors.verticalCenter: rectBatchDelete.verticalCenter
            z:2
            Image {
                id: imgBatchSet
                width: 14
                height: 15
                anchors.left: parent.left
                anchors.leftMargin: 9
                anchors.verticalCenter: parent.verticalCenter
                source: "qrc:/images/systemset/batchSet.png"

            }
            Text {
                id: txtBatchSet
                font.pixelSize: fontSize
                anchors.left: imgBatchSet.right
                anchors.leftMargin: 9
                anchors.verticalCenter: parent.verticalCenter
                color: "#ffffff"
                text: mylanguage.BatchSetting
            }
            MouseArea{
                anchors.fill: parent

                onClicked: {
                    openDeviceConfig(true,"-1");
                }
                onPressed: rectBatchSet.color = "#B3E19D"
                onReleased: rectBatchSet.color = "#71C648"
            }
        }

        Rectangle{
            id:rectDeviceAdd
            width: imgDeviceAdd.width + txtDeviceAdd.width +27
            height: 34
            color: "#FB893F"
            radius: 4
            anchors.left: rectBatchSet.right
            anchors.leftMargin: 20
            anchors.verticalCenter: rectBatchSet.verticalCenter
            z:2
            Image {
                id: imgDeviceAdd
                width: 14
                height: 15
                anchors.left: parent.left
                anchors.leftMargin: 9
                anchors.verticalCenter: parent.verticalCenter
                source: "qrc:/images/systemset/deviceAdd.png"

            }
            Text {
                id: txtDeviceAdd
                font.pixelSize: fontSize
                anchors.left: imgDeviceAdd.right
                anchors.leftMargin: 9
                anchors.verticalCenter: parent.verticalCenter
                color: "#ffffff"
                text: mylanguage.DeviceAdd
            }
            MouseArea{
                anchors.fill: parent

                onClicked: {

                    adddevice.open();
                }
                onReleased: rectDeviceAdd.color = "#FB893F"
                onPressed: rectDeviceAdd.color = "#FFCE83"
            }
        }

        //


        Rectangle{

            id:rectSearch
            color: "#ffffff"
            border.color: "#DCDFE6"
            border.width: 1
            radius: 4
            width: 160
            height: 34
            anchors.right: parent.right
            anchors.rightMargin: 30
            anchors.verticalCenter: rectBatchDelete.verticalCenter
            z:2
            Image {
                id: imgSearch
                width: 14
                height: 14
                source: "qrc:/images/systemset/search.png"
                anchors.left: parent.left
                anchors.leftMargin: 10
                anchors.verticalCenter: parent.verticalCenter
            }

            LineEdit {
                id: inputSearch
                width: rectSearch.width - imgSearch.width - 22
                height: rectSearch.height -2
                anchors.left: imgSearch.right
                anchors.leftMargin: 2
                anchors.verticalCenter: parent.verticalCenter
                border.width: 0
                //text:screenv.funGetCurPath()
                font.pixelSize: fontSize
                placeholderText: mylanguage.InputKeyWord
                placeholderTxtColor: "#909399"
                isNeedDoubleClickEdit: false
                textLeftPadding:0
                txtColor: "#909399"
                color: "#ffffff"

                //onTextChanged: s_screenShotPathSet(inputScreenShotPath.text)
            }
        }
        ListModel{
            id:netstateModel
            ListElement{showStr:"在线"}
            ListElement{showStr:"离线"}
        }

        MyComBox{
            id:cmbStateSelect
            width:80
            height: 34
            z:2
            anchors.right: rectSearch.left
            anchors.rightMargin: 20
            anchors.verticalCenter: rectBatchDelete.verticalCenter
            contentBg: "#ffffff"
            itemColorBgNor:"#FFFFFF"
            itemColorBgHoverd: "#E7EAF1"
            indicatorImgSrc:"qrc:/images/imgTypeSelect.png"
            indicatorW: 9
            indicatorH: 5
            itemLeftMargin:0
            itemTopMargin:0
            itemFontColor: "#5A5E66"
            contentFontColor: "#909399"
            contentFontSize: fontSize
            bordColor:"#DCDFE6"
            mRadius:4
            model: netstateModel
            onCurrentIndexChanged: {


            }
        }

        //设备列表
        Rectangle{
            id:deviceHeader
            width: parent.width -60
            height: 50
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 84
            visible: deviceList.count > 0
            z:1
            color: "#EEF3FA"
            Image{
                id:imgSelect
                width: 14
                height: 14
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: checkedHeaderLeftMargin
                source: deviceModel.isAllSelect?"qrc:/images/warnmanager/btnSelect_s.png":"qrc:/images/warnmanager/btnSelect.png"

                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        //                        if(isAllSelect){
                        //                            // imgSelect.source ="qrc:/images/btnSelect.png"
                        //                            isAllSelect = false;
                        //                        }else{
                        //                            //imgSelect.source ="qrc:/images/btnSelect_s.png"
                        //                            isAllSelect = true;
                        //                        }
                        deviceModel.isAllSelect = !deviceModel.isAllSelect;
                        deviceModel.funSetAllSelect(deviceModel.isAllSelect);
                    }
                }
            }
            Text {
                id: txtDeviceID
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: deviceIDHeaderLeftMargin
                font.pixelSize: fontSize
                color: "#333333"

                text: mylanguage.DeviceDid
            }
            Text {
                id: txtName
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: deviceNameHeaderLeftMargin
                font.pixelSize: fontSize
                color: "#333333"

                text: mylanguage.DeviceName
            }

            Text {
                id: txtChn
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: deviceChnHeaderLeftMargin
                font.pixelSize: fontSize
                color: "#333333"

                text: mylanguage.DeviceChannel
            }

            Text {
                id: txtRecordPath

                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: recordPathHeaderLeftMargin
                font.pixelSize: fontSize

                color: "#333333"
                text: mylanguage.DeviceVideoSavePath
            }
            Text {
                id: txtState
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: stateHeaderLeftMargin
                font.pixelSize: fontSize

                color: "#333333"
                text: mylanguage.DeviceNetState
            }

            Text {
                id: txtDo
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: doHeaderLeftMargin
                font.pixelSize: fontSize

                color: "#333333"
                text: mylanguage.Operating
            }
        }
        ListView{
            id:deviceList
            width: deviceHeader.width
            height: parent.height - 210 -deviceHeader.height
            anchors.top: deviceHeader.bottom
            anchors.left: deviceHeader.left
            model: deviceModel
            z:0
            ScrollBar.vertical: ScrollBar {size:10}

            Component.onCompleted: {
                deviceModel.funDelayflushDevice(masterpreview,playVideo);
            }
            delegate: Rectangle{
                property bool enter: false
                width: parent.width
                height: 59
                // color:deviceList.currentIndex === index?"#DFEAF8":(listviewClickIndex === index?"#DFEAF8":(enter?"#EEF3FA":"#F8FAFD"))
                color:(deviceList.currentIndex === index?"#DFEAF8":(enter?"#EEF3FA":"#F8FAFD"))
                Image{
                    id:select
                    width: 14
                    height: 14
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: checkedHeaderLeftMargin
                    source:model.isSelect?"qrc:/images/warnmanager/btnSelect_s.png": "qrc:/images/warnmanager/btnSelect.png"
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            model.isSelect = !model.isSelect;

                            if(!model.isSelect){
                                deviceModel.isAllSelect = false;

                                //warnmodel.funSetInitSelectFalse();
                            }
                        }
                    }
                }

                Text {
                    id: devicedid
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: deviceIDHeaderLeftMargin
                    font.pixelSize: fontSize
                    text: model.deviceId;
                }
                Text {
                    id: devicename
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: deviceNameHeaderLeftMargin
                    font.pixelSize: fontSize
                    text: model.deviceName;
                }

                Text {
                    id: deviceChn
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: deviceChnHeaderLeftMargin
                    font.pixelSize: fontSize
                    text: model.deviceChannel;
                }

                Text {
                    id: devicerecordpath
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: recordPathHeaderLeftMargin
                    font.pixelSize: fontSize
                    text: model.recordSavePath;
                }

                Image {
                    id: devicestateimg
                    width: 13
                    height: 14
                    anchors.left: parent.left
                    anchors.leftMargin:stateHeaderLeftMargin
                    anchors.verticalCenter: parent.verticalCenter
                    source: model.netState?"qrc:/images/systemset/online.png":"qrc:/images/systemset/offline.png"
                }
                Text {
                    id: devicestatetxt
                    anchors.left: devicestateimg.right
                    anchors.leftMargin: 7
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: fontSize
                    color: model.netState?"#67C23A":"#FF4141"
                    text: {
                        if(model.netState){
                            mylanguage.DeviceOnLine
                        }else{
                            mylanguage.DeviceOffLine
                        }
                    }
                }


                Image {
                    id: imgDelete
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: doHeaderLeftMargin

                    width: 15
                    height: 15
                    source: "qrc:/images/datamanager/delete.png"


                    MouseArea{
                        anchors.fill: parent
                        onPressed: imgDelete.source = "qrc:/images/datamanager/delete_p.png"
                        onReleased: imgDelete.source = "qrc:/images/datamanager/delete.png"
                        onClicked: {

                            askDialog.width = 427

                            askDialog.height = 176

                            askDialog.askStr = mylanguage.AskMsgDelete
                            askDialog.imgSrc = "qrc:/images/ico_warn.png"
                            askDialog.curType = askDialog.deviceInfoSingleDelete
                            askDialog.open();
                            // warnmodel.funDeleteIndex(index);
                        }
                    }
                }

                Rectangle{
                    id:spilitlinerect
                    width: 1
                    height: 12
                    anchors.left: imgDelete.right
                    anchors.leftMargin: 6
                    anchors.verticalCenter: parent.verticalCenter
                    color: "#0486FE"
                }


                Image {
                    id: imgRevise
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: spilitlinerect.right
                    anchors.leftMargin: 6
                    width: 15
                    height: 15
                    source: "qrc:/images/datamanager/revise.png"
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {

                            openDeviceConfig(false,model.deviceChannel)

                        }
                        onPressed: imgRevise.source = "qrc:/images/datamanager/revise_p.png"
                        onReleased: imgRevise.source = "qrc:/images/datamanager/revise.png"
                    }
                }

                MouseArea{
                    anchors.fill: parent
                    hoverEnabled: true
                    propagateComposedEvents:true
                    onEntered:enter = true
                    onExited: enter = false;
                    onClicked: {
                        deviceList.currentIndex = index;
                        mouse.accepted = false
                    }

                }
            }
        }
    }



    function openDeviceConfig(isBatchSet,channel){


        var deviceInfo = deviceModel.funGetDevice(channel);



        deviceconfig.isBatchSet = isBatchSet;
        deviceconfig.deviceChannel = channel;

        deviceInfo.fungetInitPar();
        busyWait.open();
        delaytimer.start();
    }


    Timer{
        id:delaytimer;
        interval: 800;
        repeat: false;
        triggeredOnStart: false;
        onTriggered: {


            busyWait.close();
            deviceconfig.open()
        }
    }

    function setDevicePar(model){
        // deviceconfig.set
        model.recordSavePath = "11111111";
    }

    Connections{
        target: askDialog
        onS_CurTypeMsg:{
            if(askDialog.deviceInfoMutipleDelete === type){
                deviceModel.funDeleteSelect();
                isAllSelect = false;
            }else if(askDialog.deviceInfoSingleDelete === type)
                deviceModel.funDeleteIndex(deviceList.currentIndex)
        }
    }


}
