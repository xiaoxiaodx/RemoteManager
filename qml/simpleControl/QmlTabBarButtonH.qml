import QtQuick 2.0

import QtQuick 2.0
Row {

    id:menurow
    property alias barModel: mymodel

    property int curIndex: 0

    property string btnBgColor: ""
    property string btnBgSelectColor: ""
    property string mflagColor: ""
    property string textColor: ""
    property string textSelectColor: ""
    property int txtLeftMargin: 0
    property int imageLeftMargin: 0
    property string imageSrcEnter: ""
    property int textSize: 5
    ListModel{
        id:mymodel
    }

   // spacing: 57
    Repeater{
        width: parent.width
        height: parent.height
        model: mymodel
        Rectangle{
            width: name.width+60
            height: parent.height
            gradient: Gradient {
                GradientStop { position: 0.0; color: "#5D9CFF"}
                GradientStop { position: 1.0; color: "#2D76E7"}
            }

            Rectangle{
                width: name.width+10
                height: 3

                anchors.bottom: parent.bottom

                //anchors.left: parent.left
                anchors.horizontalCenter: parent.horizontalCenter

                color: curIndex === index?mflagColor:"#00000000"
            }

            Text {
                id: name
                //width: parent.width
                text: model.txtStr
                color: curIndex == index?textSelectColor:textColor
                //elide: Text.ElideRight
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 16
               // anchors.verticalCenter: parent.verticalCenter
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 16
                anchors.horizontalCenter: parent.horizontalCenter
            }

            MouseArea{
                anchors.fill: parent
                onClicked: curIndex = index
            }
        }

//        QmlTabButton{
//            height: parent.height
//            txtColor:curIndex == index?textSelectColor:textColor
//            flagColor:curIndex == index?mflagColor:"#00000000"
//            bgColor:curIndex == index?btnBgSelectColor:btnBgColor
//            txtStr: model.txtStr
//            textLeftMargin:txtLeftMargin
//            imgLeftMargin: imageLeftMargin

//            txtSize:textSize
//            onClick:{
//                curIndex = index

//            }
//        }
    }
}
