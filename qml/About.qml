import QtQuick 2.0
import QtQuick.Controls 2.5


Rectangle {
    id: root


    property int fontSize: 16
    property color fontColor: "#606266"

    color: "#EEF3FA"
    Rectangle{
        id:rectArea
        width: parent.width-420 >1200?(parent.width-420):1200
        height: parent.height-60
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        color: "#ffffff"
        radius: 10

        Text {
            id: deviceVesion
            font.pixelSize: fontSize
            color: fontColor
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.leftMargin: 100
            anchors.topMargin: 60
            text: qsTr("设备版本:1.1.0")
        }
        Text {
            id: deviceType
            anchors.left: deviceVesion.left
            anchors.top: deviceVesion.bottom
            anchors.topMargin: 20
            font.pixelSize: fontSize
            color: fontColor
            text: qsTr("设备型号:J07")
        }

        Rectangle{
            id:btnVersionup

            anchors.left: deviceType.left
            anchors.top: deviceType.bottom
            anchors.topMargin: 10
            width: btnTxt.width + 20
            height: btnTxt.height +12
            color: "#0486FE"
            Text {
                id: btnTxt
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                font.pixelSize: 14
                color: "#ffffff"
                text: qsTr("升级版本")
            }
        }
    }

}
