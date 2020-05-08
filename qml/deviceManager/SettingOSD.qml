import QtQuick.Controls 2.5
import QtQuick 2.0
import QtGraphicalEffects 1.12
import QtQuick.Dialogs 1.3
import Qt.labs.settings 1.0
import "../simpleControl"
Rectangle {
    id: root



    property int fontSize: 12
    property color fontColor: "#606266"
    //与线的左对齐线
    property int parSetFirstAlignLine: 104

    color: "#ffffff"

   property bool isRevicse: false//是否有修改

    Settings {
        id:setting

        fileName: "config.ini"

        property alias osdshowswitch: swithShow.checked
        property alias osdtimeswith: swithTime.checked
        property alias osdName: inputDeviceName.text
    }

    function setOSD(timeshow,nameshow,deivcenname){
        isRevicse = false
        swithTime.checked = timeshow
        swithShow.checked = nameshow
        inputDeviceName.text = deivcenname
    }

    function updateParameterInfo(model){

        if(isRevicse){
            return;
        }else{
            model.updateOsd(isBatchSet,swithShow.checked,swithTime.checked,inputDeviceName.text)
        }
    }


    Text {
        id: timetxt
        anchors.left: line.left
        anchors.leftMargin: 20
        anchors.bottom: line.top
        anchors.bottomMargin: 10
        font.pixelSize: fontPixSize
        color: fontColor
        text: qsTr("时间")
    }


    Rectangle{
        id:line
        width: parent.width-20
        height: 1
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 44
        color: "#EBEEF5"
    }

    Text {
        id: labelSwitchTime
        text: qsTr("开关")
        font.pixelSize: fontSize
        color: fontColor
        anchors.right: swithTime.left
        anchors.rightMargin: 20
        anchors.verticalCenter: swithTime.verticalCenter
    }

    SimpleSwich{
        id:swithTime
        width: 30
        height: 15
        anchors.left: line.left
        anchors.leftMargin: parSetFirstAlignLine
        anchors.top: line.bottom
        anchors.topMargin: 20
       // onCheckedChanged: s_timeSwith(checked)
    }

    Text {
        id: nametxt
        anchors.left: line1.left
        anchors.leftMargin: 20
        anchors.bottom: line1.top
        anchors.bottomMargin: 10
        font.pixelSize: fontPixSize
        color: fontColor
        text: qsTr("名称")
    }
    Rectangle{
        id:line1
        width: parent.width-20
        height: 1
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 147
        color: "#EBEEF5"
    }

    Text {
        id: labelSwitchShow
        text: qsTr("显示")
        font.pixelSize: fontSize
        color: fontColor
        anchors.right: swithTime.left
        anchors.rightMargin: 20
        anchors.verticalCenter: swithShow.verticalCenter
    }

    SimpleSwich{
        id:swithShow
        width: 30
        height: 15
        anchors.left: line1.left
        anchors.leftMargin: parSetFirstAlignLine
        anchors.top: line1.bottom
        anchors.topMargin: 20
       // onCheckedChanged: s_timeSwith(checked)
    }

    Text {
        id: labelDeviceChannel
        text: qsTr("")
        visible:!isBatchSet
        font.pixelSize: fontSize
        color: fontColor
        anchors.right: inputDeviceName.left
        anchors.rightMargin: 20
        anchors.verticalCenter: inputDeviceName.verticalCenter
    }

    LineEdit {
        id: inputDeviceName
        width: 130
        height: 26
        visible:!isBatchSet
        anchors.left: line1.left
        anchors.leftMargin: 104
        anchors.top: line1.bottom
        anchors.topMargin: 58

        //text:screenv.funGetCurPath()
        font.pixelSize: fontSize
        placeholderText: ""
        isNeedDoubleClickEdit: false
        textLeftPadding:0
        txtColor: fontColor
        color: "#ffffff"
        //onTextChanged: s_recordPathSet(inputrecordPath.text)
    }


    Connections{
        target: main
        onS_setLanguage:setLanguage(typeL);
    }

    function setLanguage(type){
        switch(type){
        case lEnglish:
            timetxt.text = "Time"
            labelSwitchTime.text = "Switch"
            nametxt.text = "Name"
            labelSwitchShow.text = "Visible"
            break;
        case lChinese:
            timetxt.text = "时间"
            labelSwitchTime.text = "开关"
            nametxt.text = "名字"
            labelSwitchShow.text = "显示"
            break;
        }
    }
}
