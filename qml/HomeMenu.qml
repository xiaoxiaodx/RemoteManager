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
            //            anchors.bottom: parent.bottom
            //            anchors.bottomMargin: 10
            width: 144
            height: 40
            source: "qrc:/images/logo.png"
        }

        QmlTabBarButtonH{
            id:tabbarBtn
            height: parent.height
            width: parent.width - btnImg.width - windowMenu.width-60
            anchors.left: btnImg.right
            anchors.leftMargin: 60
            btnBgColor:"transparent"
            btnBgSelectColor:"#272727"
            mflagColor:"#80ffffff"
            textColor: "white"
            textSelectColor:"white"
            txtLeftMargin:7
            textSize:18
            Component.onCompleted: {
                tabbarBtn.barModel.append({txtStr:qsTr("主预览")})
                tabbarBtn.barModel.append({txtStr:qsTr("录像回放")})
                tabbarBtn.barModel.append({txtStr:qsTr("设备管理")})
                tabbarBtn.barModel.append({txtStr:qsTr("告警管理")})
                tabbarBtn.barModel.append({txtStr:qsTr("数据管理")})
                tabbarBtn.barModel.append({txtStr:qsTr("关于")})
                setLanguage(curLanguage)
            }
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


    Row{
        id:windowMenu
        anchors.right: parent.right
        anchors.rightMargin: 10
        width: 350
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

        QmlImageButton{
            width: 20
            height: 20
            imgSourseHover: "qrc:/images/login.png"
            imgSourseNormal: "qrc:/images/login.png"
            imgSoursePress: "qrc:/images/login.png"
            onClick:sLogin()
        }

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
                model: ListModel{
                    ListElement{showStr:"简体中文"}
                    ListElement{showStr:"English"}
//                    ListElement{showStr:"Italian"}
//                    ListElement{showStr:"Korean"}
//                    ListElement{showStr:"Russian"}
//                    ListElement{showStr:"Lithuanian"}
                }

                //{["showStr":"简体中文" "showStr":"English","Italian","Korean"]}
                onCurrentIndexChanged:{
                    console.debug("**********************" + cmb.currentIndex)
                    curLanguage = cmb.currentIndex
                    main.s_setLanguage(curLanguage);
                }

                Component.onCompleted: {
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


    Connections{
        target: main
        onS_setLanguage:setLanguage(typeL);
    }

    function setLanguage(type){

        var index = 0;
        switch(type){
        case lEnglish:
            tabbarBtn.barModel.get(index++).txtStr =  "Main Preview"
            tabbarBtn.barModel.get(index++).txtStr =  "Record"
            tabbarBtn.barModel.get(index++).txtStr =  "Device management"
            tabbarBtn.barModel.get(index++).txtStr =  "Alarm Management"
            tabbarBtn.barModel.get(index++).txtStr =  "Data Management"
            tabbarBtn.barModel.get(index++).txtStr =  "About"
            break;
        case lChinese:
            tabbarBtn.barModel.get(index++).txtStr =  "主预览"
            tabbarBtn.barModel.get(index++).txtStr =  "录像回放"
            tabbarBtn.barModel.get(index++).txtStr =  "设备管理"
            tabbarBtn.barModel.get(index++).txtStr =  "告警管理"
            tabbarBtn.barModel.get(index++).txtStr =  "数据管理"
            tabbarBtn.barModel.get(index++).txtStr =  "关于"

            break;

        }
    }


}


