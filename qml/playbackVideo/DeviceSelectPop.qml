import QtQuick 2.0
import QtQuick.Controls 2.5
Popup {
    id: deviceSelectPop
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
    dim:false
    property alias mmodel: listv.model
    signal s_txtChange(var txt);
    Rectangle{
        id:rect
        color: "#00000000"
        anchors.fill: parent
        ListView{
            id:listv
            width: parent.width
            height: parent.height
            model: deviceModel
            delegate: Rectangle{
                id:itemRect
                width: parent.width
                color: "#909399"
                height: 20
                Text {
                    text: model.deviceName
                    font.pixelSize: 12
                    color: "#ffffff"
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: 10
                }
                MouseArea{
                    anchors.fill: parent
                    hoverEnabled: true
                    onClicked: {
                        s_txtChange(model.deviceName)
                        //txtDeviceSelect.text = model.deviceName
                        deviceSelectPop.close();
                    }

                    onEntered: itemRect.color = "#c0c4cc"
                    onExited: itemRect.color = "#909399"
                }
            }

        }
    }


}
