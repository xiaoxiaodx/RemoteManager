import QtQuick 2.0
import QtQuick.Controls 2.5
import "../simpleControl"
import QtGraphicalEffects 1.12

Popup {
    id: root
    x: parent.width/2 - root.width/2
    y: parent.height/2 - root.height/2
    property alias msgStr: txt.text
//    width: 380
//    height: 253
    modal: true
    focus: true
    //设置窗口关闭方式为按“Esc”键关闭
    closePolicy: Popup.OnEscape
    //设置窗口的背景控件，不设置的话Popup的边框会显示出来
    background: rect
    dim:false
    property int curType: -1;

    //signal s_deviceIDstr(var name,var strID,var strAccoount,var strPassword)

    signal s_showToast(var str1)
    signal s_CurTypeMsg(var type);

    property int exeClose: 0
    property int warnInfoSingleDelete: 1
    property int warnInfoMutipleDelete: 2
    property int deviceInfoSingleDelete: 3
    property int deviceInfoMutipleDelete: 4

    Rectangle {
        id: rect
        anchors.fill: parent
        color: "#ffffff"

        radius: 3

        //设置标题栏区域为拖拽区域
        Image {
            id: img
            width: 22
            height: 22
            anchors.left: parent.left
            anchors.leftMargin: 20
            anchors.top: parent.top
            anchors.topMargin: 40
            source: "qrc:/images/icon_msg.png"
        }

        Text {
            id: txt
            anchors.left: img.right
            anchors.leftMargin: 16
            anchors.verticalCenter: img.verticalCenter
            lineHeight: 1.2
            anchors.top: img.top
            wrapMode: Text.WordWrap
            text: qsTr("text")
        }

        Image {
            id: imgclose
            width: 10
            height: 10
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.rightMargin: 10
            anchors.topMargin: 10
            source: "qrc:/images/modal-close.png"
            MouseArea{
                anchors.fill:parent
                onClicked: root.close()
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


}

