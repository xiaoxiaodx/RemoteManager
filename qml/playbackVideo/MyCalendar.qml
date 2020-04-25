import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 2.5
import QtGraphicalEffects 1.12
import "../simpleControl"
Popup {
    id: root


    modal: true
    focus: true
    //设置窗口关闭方式为按“Esc”键关闭
    closePolicy: Popup.CloseOnEscape|Popup.CloseOnPressOutside
    //设置窗口的背景控件，不设置的话Popup的边框会显示出来
    background: rect


    property color fontColor: "#333333"
    property color bgColor: "#ffffff"

    signal s_yearChange(var value)
    signal s_mouthChange(var value)
    signal s_dayChange(var value)
    signal s_dayChange1(var value)

    Rectangle {
        id: rect
        anchors.fill: parent
        color: bgColor
        radius: 4

        Calendar{
            id:the_calendar
            width: parent.width - 24
            height: parent.height - 39
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.margins: 2
            style: CalendarStyle {
                gridColor: "transparent"
                //gridVisible: false
                background: Rectangle{
                    id:background
                    anchors.fill: parent
                    color:bgColor
                }

                //标题年月
                navigationBar:Item{
                    //color: "transparent"
                    height: 39
                    QmlImageButton {
                        id: yearPre
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        width: 12
                        height: 12
                        imgSourseNormal: "qrc:/images/calendar/yearpre.png"
                        imgSoursePress:"qrc:/images/calendar/yearpre_p.png"
                        imgSourseHover: imgSoursePress
                        MouseArea{
                            anchors.fill: parent
                            onClicked: {
                                control.showPreviousYear()

                                s_yearChange(""+the_calendar.visibleYear + (the_calendar.visibleMonth+1)+"00000000")
                            }
                        }
                    }

                    QmlImageButton {
                        id: yearNext

                        anchors.verticalCenter: parent.verticalCenter
                        anchors.right: parent.right
                        width: 12
                        height: 12
                        imgSourseNormal: "qrc:/images/calendar/yearnext.png"
                        imgSoursePress:"qrc:/images/calendar/yearnext_p.png"
                        imgSourseHover: imgSoursePress
                        MouseArea{
                            anchors.fill: parent
                            onClicked: {
                                control.showNextYear()
                                s_yearChange(""+the_calendar.visibleYear + (the_calendar.visibleMonth+1)+"00000000")
                            }
                        }
                    }
                    QmlImageButton {
                        id: mouthPre

                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: yearPre.right
                        anchors.leftMargin: 10
                        width: 12
                        height: 12
                        imgSourseNormal: "qrc:/images/calendar/mouthpre.png"
                        imgSoursePress:"qrc:/images/calendar/mouthpre_p.png"
                        imgSourseHover:imgSoursePress
                        MouseArea{
                            anchors.fill: parent
                            onClicked: {
                                control.showPreviousMonth()
                                s_mouthChange(""+the_calendar.visibleYear + (the_calendar.visibleMonth+1)+"00000000")
                            }
                        }
                    }
                    QmlImageButton {
                        id: mouthNext

                        anchors.verticalCenter: parent.verticalCenter
                        anchors.right: yearNext.left
                        anchors.rightMargin: 10
                        width: 12
                        height: 12
                        imgSourseNormal: "qrc:/images/calendar/mouthnext.png"
                        imgSoursePress:"qrc:/images/calendar/mouthnext_p.png"
                        imgSourseHover:imgSoursePress
                        MouseArea{
                            anchors.fill: parent
                            onClicked: {
                                control.showNextMonth()
                                s_mouthChange(""+the_calendar.visibleYear + (the_calendar.visibleMonth+1)+"00000000")
                            }
                        }
                    }

                    Rectangle{

                        id:dateShowRect
                        width: labelYearMonth.width
                        height: parent.height
                        anchors.horizontalCenter: parent.horizontalCenter
                        color: bgColor
                        Label {
                            id: labelYearMonth
                            anchors.verticalCenter: parent.verticalCenter

                            //text: the_calendar.selectedDate.getFullYear()+qsTr('年')
                            text:getMouthYearStr(control.visibleYear,(control.visibleMonth+1))//control.visibleYear+qsTr('年')
                            //elide: Text.ElideRight
                            horizontalAlignment: Text.AlignLeft
                            font.pixelSize: 14

                            color: fontColor
                        }

                        //                        Label {
                        //                            id: labelMonth
                        //                            anchors.verticalCenter: parent.verticalCenter
                        //                            anchors.left: labelYear.right
                        //                            anchors.leftMargin: 1
                        //                            //注意Date原本的月份是0开始
                        //                            text: (control.visibleMonth+1)+qsTr('月');
                        //                            //elide: Text.ElideRight
                        //                            horizontalAlignment: Text.AlignRight
                        //                            font.pixelSize: 14
                        //                            color:fontColor
                        //                        }
                    }


                    Rectangle{
                        width: parent.width
                        height: 1
                        anchors.bottom: parent.bottom
                        color: Qt.rgba(255,255,255,0.09)
                    }
                }
                //星期
                dayOfWeekDelegate: Item{
                    //color: "transparent"
                    height: the_calendar.height/8
                    Label {
                        text: getWeeklyStr(styleData.dayOfWeek+1)//control.__locale.dayName(styleData.dayOfWeek, control.dayOfWeekFormat)
                        anchors.centerIn: parent
                        color:Qt.rgba(0,0,0,0.65)
                        font.pixelSize: 12

                    }
                }
                //日期
                dayDelegate: Rectangle {
                    //选中-当月未选中-其他
                    //                color: styleData.selected
                    //                       ?Qt.rgba(52/255,142/255,145/255,1)
                    //                       : (styleData.visibleMonth && styleData.valid
                    //                          ?Qt.rgba(6/255,45/255,51/255,1)
                    //                          : Qt.rgba(3/255,28/255,35/255,1));
                    //color: styleData.selected?"#409EFF":((styleData.visibleMonth && styleData.valid)?(calendarEventModel.getDateEvent(styleData.date)):"#191919")
                    color: styleData.selected?"#8AB8FF":bgColor//(styleData.visibleMonth && styleData.valid)?(calendarEventModel.getDateEvent(styleData.date)):bgColor

                    Label {
                        text: styleData.date.getDate()
                        anchors.centerIn: parent
                        font.pixelSize: 14

                        //                    color: styleData.valid
                        //                           ?Qt.rgba(197/255,1,1,1)
                        //                           : Qt.rgba(16/255,100/255,100/255,1)
                        color: styleData.today?"#3B84F6":(((styleData.visibleMonth && styleData.valid)?fontColor:Qt.rgba(0,0,0,0.25)))
                        //color:styleData.visibleDay?"red":"white"
                    }
                }

            }
        }

        Rectangle{
            id:line1
            anchors.top:parent.top
            anchors.topMargin: 39
            width: parent.width
            height: 1
            color: Qt.rgba(0,0,0,0.09)
        }

        Rectangle{
            id:line2
            anchors.bottom:parent.bottom
            anchors.bottomMargin: 39
            width: parent.width
            height: 1
            color: Qt.rgba(0,0,0,0.09)
        }


        Text {
            id: txtToday
            anchors.left: parent.left
            anchors.leftMargin: 8
            anchors.top: line2.bottom
            anchors.topMargin: 8
            font.pixelSize: 14
            color: fontColor
            text: Qt.formatDate(the_calendar.selectedDate,"yyyy-MM-dd")
        }

        Rectangle{
            id:btnEnsure
            width: txtEnsure.width
            height: 22
            color: "transparent"
            anchors.verticalCenter: txtToday.verticalCenter
            anchors.right: parent.right
            anchors.rightMargin: 16

            Text {
                id: txtEnsure
                font.pixelSize: 14
                anchors.horizontalCenter: parent.horizontalCenter
                color: "#3B84F6"
                text: qsTr("取消")
            }


            MouseArea{
                anchors.fill: parent
                onClicked: {
                    s_dayChange(Qt.formatDate(the_calendar.selectedDate,"yyyyMMdd"))
                    s_dayChange1(Qt.formatDate(the_calendar.selectedDate,"yyyy-MM-dd"))
                    root.close()
                }
            }
        }

        Rectangle{
            id:btnCancel
            width: txtCancel.width
            height: 22

            color: "transparent"
            anchors.verticalCenter: txtToday.verticalCenter
            anchors.right: btnEnsure.left
            anchors.rightMargin: 10

            Text {
                id: txtCancel
                font.pixelSize: 14
                color: "#3B84F6"
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("取消")
            }

            MouseArea{
                anchors.fill: parent
                onClicked: {

                    root.close()
                }
            }


        }

        layer.enabled: true
        layer.effect: DropShadow {
            transparentBorder: true
            horizontalOffset: 0
            verticalOffset: 0
            color:"#30000000"
        }
    }

    function getCurrentData(){
        return the_calendar.selectedDate
    }


    function getMouthYearStr(year,month){

        switch(curLanguage){
        case lChinese:
            return year+qsTr('年 ') + month+qsTr('月');
        case lEnglish:
            return year + " "+getEnglishMouth(month);
        case lKorean:
            return year + " "+getEnglishMouth(month);
        case lItaly:
            return year + " "+getItalyMouth(month);
        case lRussian:
            return year + " "+getRussianMouth(month);
        }

    }

    function getEnglishMouth(value){

        switch(value){
        case 1:
            return "January";
        case 2:
            return "February";
        case 3:
            return "March";
        case 4:
            return "April";
        case 5:
            return "May";
        case 6:
            return "June";
        case 7:
            return "July";
        case 8:
            return "August";
        case 9:
            return "September";
        case 10:
            return "October";
        case 11:
            return "November";
        case 12:
            return "December";
        }
    }
    function getRussianMouth(value){
        switch(value){
        case 1:
            return "Январь";
        case 2:
            return "Февраль";
        case 3:
            return "Март";
        case 4:
            return "Апрель";
        case 5:
            return "Май";
        case 6:
            return "Июнь";
        case 7:
            return "Июль";
        case 8:
            return "Август";
        case 9:
            return "Сентябрь";
        case 10:
            return "Октябрь";
        case 11:
            return "Ноябрь";
        case 12:
            return "Декабрь";
        }
    }

    function getItalyMouth(value){
        switch(value){
        case 1:
            return "Gennaio";
        case 2:
            return "Febbraio";
        case 3:
            return "Marzo";
        case 4:
            return "Aprile";
        case 5:
            return "Maggio";
        case 6:
            return "Giugno";
        case 7:
            return "Luglio";
        case 8:
            return "Agosto";
        case 9:
            return "Settembre";
        case 10:
            return "Ottobre";
        case 11:
            return "Novembre";
        case 12:
            return "Dicembre";
        }
    }

    function getWeeklyStr(week){

       // console.debug("week:"+week);
        switch(curLanguage){
        case lChinese:
            return getChineseWeekly(week);
        case lEnglish:
            return getEnglishWeekly(week);
        case lKorean:
            return getEnglishWeekly(week);
        case lItaly:
            return getItalyWeekly(week);
        case lRussian:
            return getRussianWeekly(week);
        }

    }
    function getChineseWeekly(value){
        switch(value){
        case 1:
            return "周一";
        case 2:
            return "周二";
        case 3:
            return "周三";
        case 4:
            return "周四";
        case 5:
            return "周五";
        case 6:
            return "周六";
        case 7:
            return "周日";
        }
    }
    function getItalyWeekly(value){
        switch(value){
        case 1:
            return "Lu";
        case 2:
            return "Ma";
        case 3:
            return "Me";
        case 4:
            return "Gi";
        case 5:
            return "Ve";
        case 6:
            return "Sa";
        case 7:
            return "Do";
        }
    }
    function getEnglishWeekly(value){
        switch(value){
        case 1:
            return "Mon";
        case 2:
            return "Tue";
        case 3:
            return "Wed";
        case 4:
            return "Thu";
        case 5:
            return "Fri";
        case 6:
            return "Sat";
        case 7:
            return "Sun";
        }
    }

    function getRussianWeekly(value){
        switch(value){
        case 1:
            return "Пн";
        case 2:
            return "Вт";
        case 3:
            return "Ср";
        case 4:
            return "Чт";
        case 5:
            return "Пт";
        case 6:
            return "Сб";
        case 7:
            return "Вс";
        }
    }

    Connections{
        target: main
        onS_setLanguage:setLanguage(typeL);
    }

    function setLanguage(type){
        switch(type){
        case lEnglish:
            txtCancel.text = "Cancel"
            txtEnsure.text = "Confirm "
            break;
        case lKorean:
            txtCancel.text = "취소"
            txtEnsure.text = "확인"
            break;
        case lItaly:
            txtCancel.text = "Annullato"
            txtEnsure.text = "Confermare"
            break;
        case lChinese:
            txtCancel.text = "取消"
            txtEnsure.text = "确定"
            break;
        case lRussian:
            txtCancel.text = "Отмена"
            txtEnsure.text = "Подтвердить"
            break;
        }
    }


}
