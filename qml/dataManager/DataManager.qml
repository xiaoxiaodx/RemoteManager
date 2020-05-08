import QtQuick 2.0
import QtQuick.Controls 2.5
import "../simpleControl"

import "../warnManager"
import "../playbackVideo"
import FaceDateModel 1.0
Rectangle {
    id: root
    property int checkedHeaderLeftMargin: 30
    property int photoHeaderLeftMargin: 54
    property int numberHeaderLeftMargin: 236
    property int nameHeaderLeftMargin: 406
    property int importTimeHeaderLeftMargin: 568
    property int doHeaderLeftMargin: 826
    property int fontSize: 14

    property int listviewClickIndex: -1


    signal s_allselect(bool isSelect);

    color: "#EEF3FA"

    FaceDateModel{
        id:faceDateModel
    }


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
                    askDialog.askStr = curLanguage=== lChinese?"确认要删除所选信息吗？":
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
            id:rectBatchImport
            width: imgBatchSet.width + txtBatchSet.width +27
            height: 34
            color: "#FB893F"
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
                source: "qrc:/images/systemset/deviceAdd.png"

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
                    faceDateModel.funtest();
                }
                onPressed: rectBatchImport.color = "#FFCE83"
                onReleased: rectBatchImport.color = "#FB893F"
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
            anchors.right: dateRect.left
            anchors.rightMargin: 10
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
               // text:screenv.funGetCurPath()
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

        //日期选择
        Rectangle{

            id:dateRect
            color: "#ffffff"
            border.width: 1
            border.color: "#DCDFE6"
            radius: 4
            width: 160
            height: 34
            anchors.verticalCenter: rectBatchDelete.verticalCenter
            anchors.right: parent.right
            anchors.rightMargin: 200
            z:2
            Image {
                id: imgdate
                width: 14
                height: 13
                source: "qrc:/images/warnmanager/data1.png"
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
                anchors.leftMargin: 10
            }

            Text {
                id: txtDate
                anchors.left: imgdate.right
                anchors.leftMargin: 10
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: fontSize
                color: "#909399"
                text:Qt.formatDate(calendar.getCurrentData(),"yyyy-MM-dd")
            }
            MouseArea{
                anchors.fill: parent
                hoverEnabled: true
                onPressed: {
                    calendar.open()
                }
                onEntered: imgdate.source = "qrc:/images/warnmanager/data1.png"
                onReleased: imgdate.source = "qrc:/images/warnmanager/data1.png"
            }

        }




        //时间选择
        Rectangle{

            id:timeRect
            color: "#ffffff"
            border.width: 1
            border.color: "#DCDFE6"
            radius: 4
            width: 160
            height: 34
            z:2
            anchors.left: dateRect.right
            anchors.verticalCenter: rectBatchDelete.verticalCenter
            anchors.leftMargin: 10

            Image {
                id: imgtime
                width: 14
                height: 14
                source: "qrc:/images/warnmanager/time.png"
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
                anchors.leftMargin: 10
            }

            Text {
                id: txttime
                anchors.left: imgtime.right
                anchors.leftMargin: 10
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: fontSize
                color: "#909399"
                text: qsTr("00:00:00")
            }
            MouseArea{
                anchors.fill: parent
                hoverEnabled: true
                onPressed: {
                    selecttime.open();
                }
                onEntered: imgtime.source = "qrc:/images/warnmanager/time.png"
                onReleased: imgtime.source = "qrc:/images/warnmanager/time.png"
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
            visible: dataList.count > 0
            z:1
            color: "#EEF3FA"
            Image{
                id:imgSelect
                width: 14
                height: 14
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: checkedHeaderLeftMargin
                source: faceDateModel.isAllSelect?"qrc:/images/warnmanager/btnSelect_s.png":"qrc:/images/warnmanager/btnSelect.png"

                MouseArea{
                    anchors.fill: parent
                    onClicked: {


                        faceDateModel.isAllSelect = !faceDateModel.isAllSelect

                        faceDateModel.funSetAllSelect(faceDateModel.isAllSelect);
                    }
                }
            }
            Text {
                id: txtPhoto
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: photoHeaderLeftMargin
                font.pixelSize: fontSize
                color: "#333333"
                font.bold: curLanguage===lKorean
                text: qsTr("人像图片")
            }
            Text {
                id: txtName
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: numberHeaderLeftMargin
                font.pixelSize: fontSize
                color: "#333333"
                font.bold: curLanguage===lKorean
                text: qsTr("编号")
            }
            Text {
                id: txtRecordPath

                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: nameHeaderLeftMargin
                font.pixelSize: fontSize
                font.bold: curLanguage===lKorean
                color: "#333333"
                text: qsTr("姓名")
            }
            Text {
                id: txtState
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: importTimeHeaderLeftMargin
                font.pixelSize: fontSize
                font.bold: curLanguage===lKorean
                color: "#333333"
                text: qsTr("导入时间")
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
            id:dataList
            width: deviceHeader.width
            height: parent.height - 210 -deviceHeader.height
            anchors.top: deviceHeader.bottom
            anchors.left: deviceHeader.left
            model: faceDateModel
            z:0
            ScrollBar.vertical: ScrollBar {size:10}
            delegate: Rectangle{
                property bool enter: false
                width: parent.width
                height: 112
                // color:dataList.currentIndex === index?"#DFEAF8":(listviewClickIndex === index?"#DFEAF8":(enter?"#EEF3FA":"#F8FAFD"))
                color:(dataList.currentIndex === index?"#DFEAF8":(enter?"#EEF3FA":"#F8FAFD"))
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
                                faceDateModel.isAllSelect = false;
                                //warnmodel.funSetInitSelectFalse();
                            }
                        }
                    }
                }

                Image {
                    id: faceimg
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: photoHeaderLeftMargin
                    source:(model.faceimgPath===undefine)? "":model.faceimgPath
                }
                Text {
                    id: facenumber
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: numberHeaderLeftMargin
                    font.pixelSize: fontSize
                    text: model.faceNumber;
                }
                Text {
                    id: facename
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: nameHeaderLeftMargin
                    font.pixelSize: fontSize
                    text: model.faceName;
                }

                Text {
                    id: faceimporttime
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: importTimeHeaderLeftMargin
                    font.pixelSize: fontSize
                    text: model.faceimportTime;
                }

                Image {
                    id: imgDelete
                    width: 16
                    height: 16
                    anchors.left: parent.left
                    anchors.leftMargin: doHeaderLeftMargin
                    anchors.verticalCenter: parent.verticalCenter
                    source: "qrc:/images/datamanager/delete.png"
                    MouseArea{
                        anchors.fill: parent
                        onPressed: imgDelete.source = "qrc:/images/datamanager/delete_p.png"
                        onReleased: imgDelete.source = "qrc:/images/datamanager/delete.png"
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
                    width: 16
                    height: 16
                    anchors.left: spilitlinerect.right
                    anchors.leftMargin: 6
                    anchors.verticalCenter: parent.verticalCenter
                    source: "qrc:/images/datamanager/revise.png"
                    MouseArea{
                        anchors.fill: parent
                        onPressed: imgDelete.source = "qrc:/images/datamanager/revise_p.png"
                        onReleased: imgDelete.source = "qrc:/images/datamanager/revise.png"

                    }
                }

                MouseArea{
                    anchors.fill: parent
                    hoverEnabled: true
                    propagateComposedEvents:true
                    onEntered:enter = true
                    onExited: enter = false;
                    onClicked: {

                        dataList.currentIndex = index;
                        mouse.accepted = false
                    }
                }
            }
        }

        MyCalendar{
            id:calendar
            width:280
            height: 314
            dim:false
            x:dateRect.x
            y:67
            Component.onCompleted: {

               // curDateStr = Qt.formatDate(calendar.getCurrentData(),"yyyyMMdd");
               // warnmodel.funFlushWarnInfo(deviceconfig.getScrennShotPath(),curDateStr);
            }
            onS_dayChange:{
              //  curDateStr = value;
                //warnmodel.funFlushWarnInfo(deviceconfig.getScrennShotPath(),curDateStr);
            }
            onS_dayChange1: txtDate.text = value
            onS_yearChange: ;
        }

        SelectTime{
            id:selecttime
            x:timeRect.x
            y:timeRect.y + timeRect.height + 2
            z:1
            width: 120
            height: 245
            onS_ensure: {
                var timeStr = timeh+":"+timem+":"+times
                txttime.text = timeStr
                //var curIndex = warnmodel.funFindIndex(timeh,timem,times)
                console.debug("curIndex "+curIndex)

               // warnList.positionViewAtIndex(curIndex,ListView.Beginning)
                //warnList.currentIndex = curIndex;
                //warnList.currentIndex = curIndex
            }

        }

    }






    Connections{
        target: askDialog
        onS_CurTypeMsg:{
            if(askDialog.warnInfoMutipleDelete === type){
               faceDateModel.funDeleteSelect();

            }else if(askDialog.warnInfoSingleDelete === type)
               faceDateModel.funDeleteIndex(dataList.currentIndex)
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
