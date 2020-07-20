import QtQuick 2.0
import "../qml/simpleControl"
import Qt.labs.settings 1.0
Rectangle {


    property alias mCurIndex: tabbarBtn.curIndex

    signal swinMin();
    signal swinMax();
    signal swinClose();
    signal sFullScreen();
    signal sLogin();

    Settings {
        id:setting1
        property alias curLindex: cmb.currentIndex
    }

    Rectangle{
        width: parent.width - rectLanguage.width -20
        height: parent.height
        color: "#00ffffff"
        Image {
            id: btnImg
            anchors.left: parent.left
            anchors.leftMargin: 30
            anchors.verticalCenter: parent.verticalCenter
            width: 144
            height: 40
            source: "file:///"+mylanguage.getCurPath()+"/logo.png"
        }

        QmlTabBarButtonH{
            id:tabbarBtn
            height: parent.height
            width: parent.width - btnImg.width - windowMenu.width-60
            anchors.left: btnImg.right
            anchors.leftMargin: 20
            btnBgColor:"transparent"
            btnBgSelectColor:"#272727"
            mflagColor:"#80ffffff"
            textColor: "white"
            textSelectColor:"white"
            txtLeftMargin:7
            textSize:18
            //            Component.onCompleted: {
            //                tabbarBtn.barModel.append({txtStr:mylanguage.Masterview})
            //                tabbarBtn.barModel.append({txtStr:mylanguage.VideoPlayback})
            //                tabbarBtn.barModel.append({txtStr:mylanguage.DeviceManagement})
            //                tabbarBtn.barModel.append({txtStr:mylanguage.AlarmManagement})
            //                //                tabbarBtn.barModel.append({txtStr:qsTr("数据管理")})
            //                //                tabbarBtn.barModel.append({txtStr:qsTr("关于")})
            //            }
        }

        MouseArea{
            property point clickPoint: "0,0"

            anchors.fill: parent
            acceptedButtons: Qt.LeftButton
            propagateComposedEvents: true
            onPressed: {
                homeMenu.isDoubleClick = false;
                clickPoint  = Qt.point(mouse.x, mouse.y)
                //mouse.accepted = false;
            }

            onDoubleClicked: {
                homeMenu.isDoubleClick = true
                winMax();
            }
            onPositionChanged: {

                if(!homeMenu.isDoubleClick){
                    var offset = Qt.point(mouse.x - clickPoint.x, mouse.y - clickPoint.y)
                    dragPosChange(offset.x, offset.y)

                }
            }
        }
    }

    Connections{
        target: mylanguage
        onSignal_updateLan:{
            tabbarBtn.barModel.clear();
            tabbarBtn.barModel.append({txtStr:mylanguage.Masterview})
            tabbarBtn.barModel.append({txtStr:mylanguage.VideoPlayback})
            tabbarBtn.barModel.append({txtStr:mylanguage.DeviceManagement})
            tabbarBtn.barModel.append({txtStr:mylanguage.AlarmManagement})
        }
    }

    Row{
        id:windowMenu
        anchors.right: parent.right
        anchors.rightMargin: 10
        width: 320
        height: 20
        anchors.topMargin: 6
        anchors.top: parent.top
        spacing:20

        QmlImageButton{
            width: 20
            height: 20
            imgSourseHover: "qrc:/images/fullScreen.png"
            imgSourseNormal: "qrc:/images/fullScreen.png"
            imgSoursePress: "qrc:/images/fullScreen_p.png"
            onClick:sFullScreen()
        }

//        QmlImageButton{
//            width: 20
//            height: 20
//            imgSourseHover: "qrc:/images/login.png"
//            imgSourseNormal: "qrc:/images/login.png"
//            imgSoursePress: "qrc:/images/login.png"
//            onClick:sLogin()
//        }

        Rectangle{
            id:rectLanguage
            width: imgl.width + cmb.width
            height: parent.height
            color: "#00ffffff"
            anchors.verticalCenter: parent.verticalCenter
            Image {
                id: imgl
                width: 20
                height: 20
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
                source: "qrc:/images/language.png"
            }
            MyComBox{
                id:cmb
                width:110
                height: 20
                anchors.left: imgl.right
                anchors.rightMargin: 10
                anchors.verticalCenter: parent.verticalCenter
                contentBg: "#00FFFFFF"
                itemColorBgNor:"#ffffff"
                itemColorBgHoverd: "#E7EAF1"
                indicatorImgSrc:"qrc:/images/language_down.png"
                indicatorW: 11
                indicatorH: 7
                itemLeftMargin:-12
                itemTopMargin:0
                currentIndex:1
                model: languageModel

                onCurrentIndexChanged:{
                    mylanguage.updateLanguage(cmb.currentIndex);
                }


            }
        }

        Rectangle{
            id:line
            width: 2
            height: 18
            anchors.verticalCenter: parent.verticalCenter
        }

        QmlImageButton{
            width: 20
            height: 20
            imgSourseHover: "qrc:/images/win_min_P.png"
            imgSourseNormal: "qrc:/images/win_min.png"
            imgSoursePress: "qrc:/images/win_min_P.png"
            onClick:swinMin()
        }
        QmlImageButton{
            width: 20
            height: 20
            imgSourseHover: "qrc:/images/win_max_p.png"
            imgSourseNormal: "qrc:/images/win_max.png"
            imgSoursePress: "qrc:/images/win_max_p.png"
            onClick:swinMax()

        }
        QmlImageButton{
            width: 20
            height: 20
            imgSourseHover: "qrc:/images/win_close_p.png"
            imgSourseNormal: "qrc:/images/win_close.png"
            imgSoursePress: "qrc:/images/win_close_p.png"
            onClick:swinClose()
        }
    }


    Timer {
        interval: 600;
        running: true;
        repeat: false
        triggeredOnStart:false
        onTriggered:{
            console.debug("***************  timer")
            mylanguage.updateLanguage(cmb.currentIndex);
        }
    }



}


