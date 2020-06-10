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

    function updateParameterInfo(){

        console.debug("updateParameterInfo  "+isRevicse)
        if(!isRevicse){
            return;
        }else{

            if(isBatchSet){
                var map = {
                    cmd:"setosdparam",
                    swithNameShow:swithShow.checked,
                    swithTimeShow:swithTime.checked,
                }
                deviceModel.funBatchSendData("setosdparam",map);
            }else{
                var map1 = {
                    cmd:"setosdparam",
                    swithNameShow:swithShow.checked,
                    swithTimeShow:swithTime.checked,
                    osdname:inputDeviceName.text
                }
                deviceModel.funSendData1(deviceChannel,"setosdparam",map1);
            }
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
        text: mylanguage.Time
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
        text: mylanguage.Switch
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
        onCheckedChanged: isRevicse = true;
    }

    Text {
        id: nametxt
        anchors.left: line1.left
        anchors.leftMargin: 20
        anchors.bottom: line1.top
        anchors.bottomMargin: 10
        font.pixelSize: fontPixSize
        color: fontColor
        text: mylanguage.Name
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
        text: mylanguage.Show
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
        onCheckedChanged:isRevicse = true;
    }

    Text {
        id: labelDeviceChannel
        text: "ch "+deviceChannel
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
        border.width: 1
        border.color: "#DCDFE6"
        radius: 1
        font.pixelSize: fontSize
        placeholderText: ""
        isNeedDoubleClickEdit: false
        textLeftPadding:0
        txtColor: Qt.rgba(0,0,0,0.65)
        color: "#ffffff"
        onTextChanged: isRevicse = true;
    }



}
