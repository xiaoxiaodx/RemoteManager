import QtQuick.Controls 2.5
import QtQuick 2.0

import "../playbackVideo"
import "../dialog"
Rectangle {
    id: root
    property int checkedHeaderLeftMargin: 20
    property int warnTimeHeaderLeftMargin: 44
    property int warnTempHeaderLeftMargin: 304
    property int warnImgHeaderLeftMargin: 478
    property int deleteHeaderLeftMargin: 771
    property int fontSize: 14

    property int listviewClickIndex: -1
    property bool isAllSelect: false

    signal s_allselect(bool isSelect);

    color: "#EEF3FA"

    onIsAllSelectChanged: {
        warnmodel.set
    }
    property string curDateStr: ""


    function screenShot(path,object,mx,my,mw,mh,temp){
        warnmodel.funScreenShoot(path,object,mx ,my,mw,mh,temp);
    }
    //加个矩形是为了解决listview显示越界的问题
    Rectangle{
        id:rectTop
        width: parent.width
        height: 20
        color: "#EEF3FA"
        anchors.top: parent.top
        z:2
    }
    Rectangle{
        id:rectWarnArea
        width: parent.width-420 >1200?(parent.width-420):1200
        height: parent.height-60
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        color: "#ffffff"
        radius: 10

        //加个矩形是为了解决listview显示越界的问题
//        Rectangle{
//            anchors.top: rectWarnArea.top
//            width: parent.width
//            height: 84
//            color: "#ffffff"
//            z:1
//        }
        //第一排控件
        Text {
            id: textitle
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.leftMargin: 60
            anchors.topMargin: 35
            font.pixelSize: 18
            z:2
            text: mylanguage.LogList
        }

        Rectangle{
            id:rectBatch
            width: txtBatchDelete.width + imgBatchDelete.width +27
            height: 36
            color: "#3B84F6"
            radius: 4
            anchors.left: textitle.right
            anchors.leftMargin: 39
            anchors.verticalCenter: textitle.verticalCenter
            z:2
            Image {
                id: imgBatchDelete
                width: 14
                height: 15
                anchors.left: parent.left
                anchors.leftMargin: 9
                anchors.verticalCenter: parent.verticalCenter
                source: "qrc:/images/warnmanager/imgDelete.png"

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

                    if(curLanguage===lRussian)
                        askDialog.width = 500
                    else
                        askDialog.width = 427
                    askDialog.height = 176
                    askDialog.askStr = mylanguage.AskMsgDelete
                    askDialog.imgSrc = "qrc:/images/ico_warn.png"
                    askDialog.curType = askDialog.warnInfoMutipleDelete
                    askDialog.open();
                }
                onReleased: rectBatch.color = "#3B84F6"
                onPressed: rectBatch.color = "#66B5FF"
            }
        }

        //日期选择
        Rectangle{

            id:dateRect
            color: "#ffffff"
            border.width: 1
            border.color: "#DCDFE6"
            radius: 4
            width: 190
            height: 34
            anchors.verticalCenter: rectBatch.verticalCenter
            anchors.right: parent.right
            anchors.rightMargin: 190
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
            width: 120
            height: 34
            z:2
            anchors.left: dateRect.right
            anchors.verticalCenter: rectBatch.verticalCenter
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
                    selecttime.open()
                }
                onEntered: imgtime.source = "qrc:/images/warnmanager/time.png"
                onReleased: imgtime.source = "qrc:/images/warnmanager/time.png"
            }

        }

        //警报列表
        Rectangle{
            id:warnHeader
            width: parent.width -120
            height: 50
            visible: warnList.count > 0
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 84
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
                            // imgSelect.source ="qrc:/images/warnmanager/btnSelect.png"
                            isAllSelect = false;
                        }else{
                            //imgSelect.source ="qrc:/images/warnmanager/btnSelect_s.png"
                            isAllSelect = true;
                        }
                        warnmodel.funSetAllSelect(isAllSelect);
                    }
                }
            }
            Text {
                id: txtWarnTime
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: warnTimeHeaderLeftMargin
                font.pixelSize: fontSize
                color: "#333333"
                text: mylanguage.WarnTime
            }
            Text {
                id: txtWarnTemp
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: warnTempHeaderLeftMargin
                font.pixelSize: fontSize
                color: "#333333"
                //font.bold: curLanguage===lKorean
                text: mylanguage.WarnTemp
            }
            Text {
                id: warnImg
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: warnImgHeaderLeftMargin
                font.pixelSize: fontSize
                //font.bold: curLanguage===lKorean
                color: "#333333"
                text: mylanguage.WarnSnapshot
            }
            Text {
                id: txtDo
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: deleteHeaderLeftMargin
                font.pixelSize: fontSize
                //font.bold: curLanguage===lKorean
                color: "#333333"
                text: mylanguage.Operating
            }
        }
        ListView{
            id:warnList
            width: warnHeader.width
            height: parent.height - 210 -warnHeader.height
            anchors.top: warnHeader.bottom
            anchors.left: warnHeader.left
            model: warnmodel
            z:0
            ScrollBar.vertical: ScrollBar {size:10}
            delegate: Rectangle{
                property bool enter: false
                width: parent.width
                height: 59
                // color:warnList.currentIndex === index?"#DFEAF8":(listviewClickIndex === index?"#DFEAF8":(enter?"#EEF3FA":"#F8FAFD"))
                color:(warnList.currentIndex === index?"#DFEAF8":(enter?"#EEF3FA":"#F8FAFD"))
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
                    id: warnTime
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: warnTimeHeaderLeftMargin
                    font.pixelSize: fontSize
                    text: model.warnTime;
                }
                Text {
                    id: warnTemp
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: warnTempHeaderLeftMargin
                    font.pixelSize: fontSize
                    text: model.warnTemp;
                }

                Image {
                    id: captureImg
                    width: 13
                    height: 14
                    anchors.left: parent.left
                    anchors.leftMargin: warnImgHeaderLeftMargin
                    anchors.verticalCenter: parent.verticalCenter
                    source: index === warnList.currentIndex?"qrc:/images/warnmanager/capture_p.png":"qrc:/images/warnmanager/capture.png"
                }
                Text {
                    id: captureTxt
                    anchors.left: captureImg.right
                    anchors.leftMargin: 7
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: fontSize
                    color: index === warnList.currentIndex?"#3B84F6":"#333333"
                    text: model.imgName;
                    MouseArea{
                        anchors.fill: parent
                        onClicked:{
                            console.debug("absolutePath:"+model.absolutePath)
                            imgshow.source ="file:///"+ model.absolutePath
                            imgpop.open();
                        }
                    }
                }


                Image {
                    id: deletetxt
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: deleteHeaderLeftMargin
                    width: 15
                    height: 15
                    source:"qrc:/images/datamanager/delete.png"
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {

                            askDialog.width = 427
                            askDialog.height = 176
                            askDialog.askStr = mylanguage.AskMsgDelete
                            askDialog.imgSrc = "qrc:/images/ico_warn.png"
                            askDialog.curType = askDialog.warnInfoSingleDelete
                            askDialog.open();
                            // warnmodel.funDeleteIndex(index);
                        }
                    }
                }

                MouseArea{
                    anchors.fill: parent
                    hoverEnabled: true
                    propagateComposedEvents:true
                    onEntered:enter = true
                    onExited: enter = false;
                    onClicked: {

                        warnList.currentIndex = index;
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

                curDateStr = Qt.formatDate(calendar.getCurrentData(),"yyyyMMdd");
                warnmodel.funFlushWarnInfo(screenv.funGetCurPath(),curDateStr);
            }
            onS_dayChange:{
                curDateStr = value;
                warnmodel.funFlushWarnInfo(screenv.funGetCurPath(),curDateStr);
            }

            onS_dayChange1: txtDate.text = value

            //onS_mouthChange:getRecordInfo(1,value)
            onS_yearChange: ;
            // Component.onCompleted:getRecordInfo(2, Qt.formatDate(calendar.getCurrentData(),"yyyyMMdd000000"))
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
                var curIndex = warnmodel.funFindIndex(timeh,timem,times)
                console.debug("curIndex "+curIndex)

                warnList.positionViewAtIndex(curIndex,ListView.Beginning)
                warnList.currentIndex = curIndex;
                //warnList.currentIndex = curIndex
            }

        }
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
                warnmodel.funDeleteIndex(warnList.currentIndex)
        }
    }



}
