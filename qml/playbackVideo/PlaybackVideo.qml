import QtQuick 2.0
import QtQuick 2.12


import TimeLine 1.0
import XVideoReplay 1.0


import "../liveVedio"
import "../simpleControl"
Rectangle {

    id:playbackvideo
    signal s_addDevice();
    signal st_showToastMsg(string str1);
    signal s_multiScreenNumChange(int num);

    property int multiScreenNum: 2
    property int premultiScreenNum: 2

    property int modelDataCurrentIndex: -1
    property int listDeviceCurrentIndex: -1

    property string shotScreenFilePath2: ""
    property string recordingFilePath2: ""

    property bool isMax: false
    property bool  isPlay: false


    MouseArea{
        anchors.fill: parent

        onClicked: ;
        onPressed: ;

    }


    Rectangle{
        id:maincontent
        width: parent.width
        height: parent.height

        color: "#252525"

        XVideoReplay{
            id:screen
            width:maincontent.width
            height:maincontent.height - rowRectHeight.height - timeline.height
        }


        Rectangle{
            id:rowRectHeight
            width: parent.width
            height: 40
            anchors.bottom: timeline.top
            color: "#323232"
            //播放控制
            Row{
                id:videoControl
                height: 40
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: 26
                Image {
                    id: imgslow
                    source: "qrc:/images/play_slow.png"

                    width: 20
                    height: 20
                    anchors.verticalCenter: parent.verticalCenter
                    MouseArea{
                        anchors.fill: parent
                        hoverEnabled: true
                        onPressed: imgslow.source = "qrc:/images/play_slow_p.png"
                        onReleased: imgslow.source = "qrc:/images/play_slow.png"
                    }
                }

                Image {
                    id: imgplay
                    source: "qrc:/images/play.png"

                    width: 20
                    height: 20
                    anchors.verticalCenter: parent.verticalCenter
                    MouseArea{
                        anchors.fill: parent
                        hoverEnabled: true
                        onPressed: {

                            imgplay.source = "qrc:/images/play_h.png"
                            //player.play();
                        }
                        onReleased: imgplay.source = "qrc:/images/play.png"
                    }
                }

                Image {
                    id: imgfast
                    source: "qrc:/images/play_fast.png"
                    width: 20
                    height: 20
                    anchors.verticalCenter: parent.verticalCenter

                    MouseArea{
                        anchors.fill: parent
                        hoverEnabled: true
                        onPressed: imgfast.source = "qrc:/images/play_fast_p.png"
                        onReleased: imgfast.source = "qrc:/images/play_fast.png"
                    }
                }
            }

            //尺寸调整
            ListModel {
                id: sizeTypeModel
                ListElement {str: "24 hr"}
                ListElement {str: "2 hr"}
                ListElement {str: "1 hr"}
                ListElement {str: "30 min"}
            }
            Row{
                id:rowAdjustSize
                property int curIndex: -1
                height: parent.height
                anchors.left: parent.left
                anchors.leftMargin: 30

                Repeater{
                    model:sizeTypeModel
                    Rectangle{
                        width: 60
                        height: 20
                        color: index === rowAdjustSize.curIndex?"#ffffff":"#323232"
                        border.color: "#ffffff"
                        border.width: 1
                        anchors.verticalCenter: parent.verticalCenter
                        Text {
                            id: sizetxt
                            text: str
                            anchors.horizontalCenter: parent.horizontalCenter
                            anchors.verticalCenter: parent.verticalCenter
                            color:index === rowAdjustSize.curIndex?"#000000":"#ffffff"
                            font.pixelSize: 12
                        }
                        MouseArea{
                            anchors.fill: parent
                            onClicked: rowAdjustSize.curIndex = index
                        }
                    }
                }

                onCurIndexChanged: {
                    timeline.setSizeType(curIndex);
                }
            }

            //日期选择
            Rectangle{

                id:timeRect
                color: "#4C4C4C"
                border.width: 0
                width: 130
                height: 22
                anchors.left: rowAdjustSize.right
                anchors.verticalCenter: parent.verticalCenter
                anchors.leftMargin: 30
                Text {
                    id: txtDate
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.leftMargin: 10
                    font.pixelSize: 12
                    color: "#ffffff"
                    text: qsTr("")
                }
                Image {
                    id: imgdate
                    width: 14
                    height: 12
                    source: "qrc:/images/date.png"
                    anchors.right: parent.right
                    anchors.rightMargin: 10
                    anchors.verticalCenter: parent.verticalCenter
                    MouseArea{
                        anchors.fill: parent
                        hoverEnabled: true
                        onPressed: {
                            calendar.open()
                        }
                        onEntered: imgdate.source = "qrc:/images/date_p.png"
                        onReleased: imgdate.source = "qrc:/images/date.png"
                    }
                }

            }
        }



        TimeLine{
            id:timeline
            width:parent.width
            height:74
            anchors.bottom:parent.bottom
            property point mousePressPt: "0,0"

            onIndicatorTimeChange:{
                screen.funPlayTimeChange(deviceconfig.getRecordPath(),Qt.formatDate(calendar.getCurrentData(),"yyyyMMdd"),curTime)
            }
        }
    }


    MyCalendar{
        id:calendar
        width: 280
        height: 314
        dim:false
        x:228
        y:parent.height -115-314-2
        onS_dayChange:{
            timeline.updateDate(deviceconfig.getRecordPath(),value)
        }
        onS_dayChange1:{

            txtDate.text = value
        }

        //onS_mouthChange:getRecordInfo(1,value)

        onS_yearChange: console.debug("onS_yearChange   "+value)

        // Component.onCompleted:getRecordInfo(2, Qt.formatDate(calendar.getCurrentData(),"yyyyMMdd000000"))
    }

    ListModel{
        id:calendarEventModel

        function getDateEvent(tmpData){

            var dayNum = Qt.formatDate(tmpData,"dd")-1
            //console.debug("getDateEvent:    "+dayNum + "  "+calendarEventModel.count+"  "+calendarEventModel.get(dayNum))


            if(calendarEventModel.count == 0)
                return "#191919"
            if(calendarEventModel.get(dayNum)=== undefined)
                return "#191919"

            if(calendarEventModel.get(dayNum).type==="1")
                return "#3A3D41";
            else if(calendarEventModel.get(dayNum).type==="2")
                return "#f64054"
            else if(calendarEventModel.get(dayNum).type==="0")
                return "#191919"

            return "#191919"
        }
    }

}



