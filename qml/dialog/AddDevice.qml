import QtQuick 2.0
import QtQuick.Controls 2.5
import "../simpleControl"
import QtGraphicalEffects 1.12

Popup {
    id: root
    x: parent.width/2 - root.width/2
    y: parent.height/2 - root.height/2
    //property alias askStr: txt.text

    modal: true
    focus: true
    //设置窗口关闭方式为按“Esc”键关闭
    closePolicy: Popup.OnEscape
    //设置窗口的背景控件，不设置的话Popup的边框会显示出来
    background: rect

    property int fontSize: 14

    signal s_addDevice(var devicename,var devcieID);

    Rectangle {
        id: rect
        anchors.fill: parent
        color: "#ffffff"
        radius: 10

        //设置标题栏区域为拖拽区域
        Text {
            id: txttitle
            anchors.left: parent.left
            anchors.leftMargin: 20
            anchors.top: parent.top
            anchors.topMargin: 20
            font.pixelSize: 16
            color: "#303133"
            text: "添加设备"
        }

        Image{
            id:imgClose
            width: 14
            height: 14
            anchors.right: parent.right
            anchors.rightMargin: 20
            anchors.verticalCenter: txttitle.verticalCenter
            source: "qrc:/images/modal-close.png"
        }

        Text {
            id: txtDeviceName
            font.pixelSize: 14
            color: "#909399"
            anchors.right: inputDeviceName.left
            anchors.rightMargin: 6
            anchors.verticalCenter: inputDeviceName.verticalCenter
            text: qsTr("设备名称")
        }

        LineEdit {
            id: inputDeviceName
            width: 180
            height: 28
            anchors.left: parent.left
            anchors.leftMargin: 148
            anchors.top: parent.top
            anchors.topMargin: 84
            border.width: 1
            border.color: "#DCDFE6"
             radius: 1
            text:"testname"
            font.pixelSize: fontSize
            placeholderText: ""
            isNeedDoubleClickEdit: false
            textLeftPadding:0
            txtColor: Qt.rgba(0,0,0,0.65)
           color: "#ffffff"
            //onTextChanged: s_recordPathSet(inputrecordPath.text)
        }

        Text {
            id: txtDeviceID
            font.pixelSize: 14
            color: "#909399"
            anchors.right: inputDeviceID.left
            anchors.rightMargin: 6
            anchors.verticalCenter: inputDeviceID.verticalCenter
            text: qsTr("设备ID")
        }

        LineEdit {
            id: inputDeviceID
            width: 180
            height: 28
            anchors.left: inputDeviceName.left
            anchors.top: inputDeviceName.bottom
            anchors.topMargin: 20
            border.width: 1
            border.color: "#DCDFE6"
            radius: 1
            text:"INEW-003910-JVTBZ"
            font.pixelSize: fontSize
            placeholderText: ""
            isNeedDoubleClickEdit: false
            textLeftPadding:0
            txtColor: Qt.rgba(0,0,0,0.65)
            color: "#ffffff"
            //onTextChanged: s_recordPathSet(inputrecordPath.text)
        }

        Rectangle{
            id:btnEnsure
            width: txtEnsure.width +24
            height: txtEnsure.height + 14
            border.width: 1
            border.color: "#0486FE"
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            anchors.rightMargin: 40
            anchors.bottomMargin: 40
            Text {
                id: txtEnsure
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                elide: Text.ElideMiddle
                font.pixelSize: 12
                color: "#0486FE"
                text: qsTr("确定")
            }
            MouseArea{
                anchors.fill: parent
                onClicked: {

                    s_addDevice(inputDeviceName.text,inputDeviceID.text);
                    root.close()
                }
            }
        }

        Rectangle{
            id:btnCancel
            width: txtCancel.width + 24
            height: txtCancel.height + 14
            anchors.bottom: btnEnsure.bottom
            anchors.right: btnEnsure.left
            anchors.rightMargin: 16
            border.width: 1
            border.color: "#909399"
            Text {
                id: txtCancel
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                elide: Text.ElideMiddle
                font.pixelSize: 12
                color: "#909399"
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
            horizontalOffset: 4
            verticalOffset: 4
            color:"#80000000"
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

