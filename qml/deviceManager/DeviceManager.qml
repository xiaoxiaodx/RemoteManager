
import QtQuick 2.0
import QtQuick.Controls 2.5
import "../simpleControl"
Rectangle {
    id: root
    property int checkedHeaderLeftMargin: 22
    property int deviceIDHeaderLeftMargin: 46
    property int deviceNameHeaderLeftMargin: 244
    property int recordPathHeaderLeftMargin: 419
    property int stateHeaderLeftMargin: 793
    property int doHeaderLeftMargin: 969
    property int fontSize: 14

    property int listviewClickIndex: -1
    property bool isAllSelect: false

    signal s_allselect(bool isSelect);

    color: "#EEF3FA"


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
                text: qsTr("批量删除")
            }
            MouseArea{
                anchors.fill: parent

                onClicked: {

                    if(curLanguage===lRussian)
                        askDialog.width = 500
                    else
                        askDialog.width = 427
                    askDialog.height = 176
                    askDialog.askStr = curLanguage=== lChinese?"确认要删除所选设备吗？":
                                                                curLanguage===lEnglish?"Confirm to delete?":
                                                                                        curLanguage===lKorean?"삭제하시겠습니까?":
                                                                                                               curLanguage===lItaly?"Cancella Tutta la Selezione?":
                                                                                                                                     curLanguage===lRussian?"Вы уверены, что хотите удалить информацию?":""
                    askDialog.imgSrc = "qrc:/images/ico_warn.png"
                    askDialog.curType = askDialog.warnInfoMutipleDelete
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
                text: qsTr("批量设置")
            }
            MouseArea{
                anchors.fill: parent

                onClicked: {

                    deviceModel.funtest();
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
                text: qsTr("添加设备")
            }
            MouseArea{
                anchors.fill: parent

                onClicked: {


                }
                onReleased: imgDeviceAdd.color = "#FB893F"
                onPressed: imgDeviceAdd.color = "#FFCE83"
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
                placeholderText: "输入关键词"
                placeholderTxtColor: "#909399"
                isNeedDoubleClickEdit: false
                textLeftPadding:0
                txtColor: "#909399"
                color: "#ffffff"

                //onTextChanged: s_screenShotPathSet(inputScreenShotPath.text)
            }
        }

        MyComBox{
            id:cmbStateSelect
            width:60
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
            model: ListModel{
                ListElement{showStr:"在线"}
                ListElement{showStr:"离线"}
            }
            onCurrentIndexChanged: {

                //                    curLanguage = currentIndex
                //                    main.s_setLanguage(currentIndex);
                //s_temImage(currentIndex);
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
                source: isAllSelect?"qrc:/images/warnmanager/btnSelect_s.png":"qrc:/images/warnmanager/btnSelect.png"

                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        if(isAllSelect){
                            // imgSelect.source ="qrc:/images/btnSelect.png"
                            isAllSelect = false;
                        }else{
                            //imgSelect.source ="qrc:/images/btnSelect_s.png"
                            isAllSelect = true;
                        }
                        warnmodel.funSetAllSelect(isAllSelect);
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
                font.bold: curLanguage===lKorean
                text: qsTr("设备编码")
            }
            Text {
                id: txtName
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: deviceNameHeaderLeftMargin
                font.pixelSize: fontSize
                color: "#333333"
                font.bold: curLanguage===lKorean
                text: qsTr("名称")
            }
            Text {
                id: txtRecordPath

                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: recordPathHeaderLeftMargin
                font.pixelSize: fontSize
                font.bold: curLanguage===lKorean
                color: "#333333"
                text: qsTr("录像存储地址")
            }
            Text {
                id: txtState
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: stateHeaderLeftMargin
                font.pixelSize: fontSize
                font.bold: curLanguage===lKorean
                color: "#333333"
                text: qsTr("网络状态")
            }

            Text {
                id: txtDo
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: doHeaderLeftMargin
                font.pixelSize: fontSize
                font.bold: curLanguage===lKorean
                color: "#333333"
                text: qsTr("操作")
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
                                isAllSelect = false;
                                warnmodel.funSetInitSelectFalse();
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
                    source: model.netState === 2?"qrc:/images/systemset/online.png":"qrc:/images/systemset/offline.png"
                }
                Text {
                    id: devicestatetxt
                    anchors.left: devicestateimg.right
                    anchors.leftMargin: 7
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: fontSize
                    color: model.netState === 2?"#67C23A":"#FF4141"
                    text: model.netState === 2?("在线"):("离线")
                    MouseArea{
                        anchors.fill: parent
                        onClicked:{
                            console.debug("absolutePath:"+model.absolutePath)
                            imgshow.source ="file:///"+ model.absolutePath
                            imgpop.open();
                        }
                    }
                }


                Text {
                    id: deletetxt
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: doHeaderLeftMargin
                    font.pixelSize: fontSize
                    color: "#0486FE"
                    text:curLanguage === lChinese?"删除":
                                                   curLanguage === lEnglish?"Remove":
                                                                             curLanguage === lKorean?"삭제":
                                                                                                      curLanguage === lItaly?"Cancella":
                                                                                                                              curLanguage === lRussian?"Удалить":""
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            if(curLanguage === lRussian)
                                askDialog.width = 500
                            else
                                askDialog.width = 427
                            askDialog.height = 176

                            var askstr = "";
                            switch(curLanguage){
                            case lChinese:
                                askstr = "确认删除设备吗？"
                                break;
                            case lEnglish:
                                askstr = "Confirm to delete?"
                                break;
                            case lKorean:
                                askstr = "삭제 정보를 확인합니까?"
                                break;
                            case lItaly:
                                askstr = "Cancello L’Informazione?"
                                break;
                            case lRussian:
                                askstr = "Вы уверены, что хотите удалить информацию?"
                                break;
                            }
                            askDialog.askStr = askstr
                            askDialog.imgSrc = "qrc:/images/ico_warn.png"
                            askDialog.curType = askDialog.warnInfoSingleDelete
                            askDialog.open();
                            // warnmodel.funDeleteIndex(index);
                        }
                    }
                }
                Rectangle{
                    id:spilitlinerect
                    width: 1
                    height: 12
                    anchors.left: deletetxt.right
                    anchors.leftMargin: 6
                    anchors.verticalCenter: parent.verticalCenter
                    color: "#0486FE"
                }


                Text {
                    id: setText
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: spilitlinerect.right
                    anchors.leftMargin: 6
                    font.pixelSize: fontSize
                    color: "#0486FE"
                    text: qsTr("设置")
                    MouseArea{
                        anchors.fill: parent
                        onClicked: deviceconfig.open()
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


    DeviceConfig{
        id:deviceconfig
        width: 800
        height: 600
        anchors.centerIn: parent
    }


    Popup {
        id: imgpop
        x:(parent.width-720)/2
        y:(parent.height-520)/2
        width: 720
        height: 520
        modal: true
        focus: true
        //设置窗口关闭方式为按“Esc”键关闭
        closePolicy: Popup.CloseOnEscape|Popup.CloseOnPressOutside
        //设置窗口的背景控件，不设置的话Popup的边框会显示出来
        background: rect

        Rectangle{
            id:rect
            color: "#00000000"
            anchors.fill: parent
            Image {
                id: imgshow
                width: 600
                height: 400
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                source: ""
            }

            Image {
                id: imgclose
                width: 40
                height: 40
                anchors.left: imgshow.right
                anchors.bottom: imgshow.top
                anchors.leftMargin: 20
                anchors.bottomMargin: 20
                source: "qrc:/images/img_close.png"
                MouseArea{
                    anchors.fill: parent
                    onClicked: imgpop.close();
                }
            }

        }
    }


    Connections{
        target: askDialog
        onS_CurTypeMsg:{
            if(askDialog.warnInfoMutipleDelete === type){
                warnmodel.funDeleteSelect();
                isAllSelect = false;
            }else if(askDialog.warnInfoSingleDelete === type)
                warnmodel.funDeleteIndex(deviceList.currentIndex)
        }
    }


    Connections{
        target: main
        onS_setLanguage:setLanguage(typeL);
    }

    function setLanguage(type){

        //        switch(type){
        //        case lEnglish:
        //            textitle.text = "Log list";
        //            txtBatchDelete.text = "Batch Remove"
        //            txtDo.text = "Operation"
        //            txtWarnTime.text = "Alarm Time"
        //            txtWarnTemp.text = "Alarm Temperature"
        //            warnImg.text = "Snapshots"
        //            //deletetxt.text = "Remove"
        //            break;
        //        case lKorean:
        //            textitle.text = "로그정보";
        //            txtBatchDelete.text = "전체삭제"
        //            txtDo.text = "설정"
        //            txtWarnTime.text = "알람시간"
        //            txtWarnTemp.text = "알람온도"
        //            warnImg.text = "화면저장"
        //            //deletetxt.text = "삭제"
        //            break;
        //        case lItaly:
        //            textitle.text = "Elenco eventi";
        //            txtBatchDelete.text = "Cancella tutti eventi"
        //            txtDo.text = "Operazione"
        //            txtWarnTime.text = "Ora Allarme"
        //            txtWarnTemp.text = "Temperatura Allarme"
        //            warnImg.text = "Istantanea"
        //            //deletetxt.text = "Cancella"
        //            break;
        //        case lChinese:
        //            textitle.text = "日志列表";
        //            txtBatchDelete.text = "批量删除"
        //            txtDo.text = "操作"
        //            txtWarnTime.text = "告警时间"
        //            txtWarnTemp.text = "告警温度"
        //            warnImg.text = "抓拍图片"
        //            //deletetxt.text = "删除"
        //            break;
        //        case lRussian:
        //            textitle.text = "Список журналов";
        //            txtBatchDelete.text = "Очистить все события"
        //            txtDo.text = "Операция"
        //            txtWarnTime.text = "Время"
        //            txtWarnTemp.text = "Температура"
        //            warnImg.text = "Снимок"
        //            //deletetxt.text = "删除"
        //            break;
        //        }
    }
}
