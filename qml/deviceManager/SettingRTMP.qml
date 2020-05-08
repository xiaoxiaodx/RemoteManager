import QtQuick.Controls 2.5
import QtQuick 2.0
import QtGraphicalEffects 1.12
import QtQuick.Dialogs 1.3
import Qt.labs.settings 1.0
import QtQuick.Controls 1.4
import "../simpleControl"
import "../warnManager"
Rectangle {
    id: root



    property int fontSize: 12
    property color fontColor: "#606266"
    //与线的左对齐线
    property int parSetFirstAlignLine: 88
    property int firstAlighnlineSpace: 10

    property bool isRevicse: false//是否有修改
    color: "#ffffff"

    Settings {
        id:setting

        fileName: "config.ini"
        property alias rtmpswith: swithRtmp.checked
        property alias rtmpresolution: cmbResolution.currentText
        property alias rtmpurl: inputurl.text
        property alias rtmpaccount: inputaccount.text
        property alias rtmppassword: inputpassword.text
    }

    function setRtmp(enable,resolution,url,acc,pwd)
    {
        isRevicse = false
        swithRtmp.checked = enable
        cmbResolution.currentText = resolution
        inputurl.text = url;
        inputaccount.text = acc
        inputpassword.text = pwd
    }

    function updateParameterInfo(model){

        if(isRevicse){
            return;
        }else{
            model.updateRtmp(isBatchSet,swithRtmp.checked,cmbResolution.currentIndex,inputurl.text,inputaccount.text,inputpassword.text);
        }
    }
    Text {
        id: settxt
        anchors.left: line.left
        anchors.leftMargin: 20
        anchors.bottom: line.top
        anchors.bottomMargin: 10
        font.pixelSize: fontPixSize
        color: fontColor
        text: qsTr("设置")
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
        text: qsTr("时间开关")
        font.pixelSize: fontSize
        color: fontColor
        anchors.right: swithRtmp.left
        anchors.rightMargin: firstAlighnlineSpace
        anchors.verticalCenter: swithRtmp.verticalCenter
    }

    SimpleSwich{
        id:swithRtmp
        width: 30
        height: 15
        anchors.left: line.left
        anchors.leftMargin: parSetFirstAlignLine
        anchors.top: line.bottom
        anchors.topMargin: 20
        // onCheckedChanged: s_timeSwith(checked)
    }


    Text {
        id: labelResolution
        text: qsTr("分辨率")
        font.pixelSize: fontSize
        color: fontColor
        anchors.right: cmbResolution.left
        anchors.rightMargin: firstAlighnlineSpace
        anchors.verticalCenter: cmbResolution.verticalCenter
    }


    ListModel{
        id:resolutionModel
        ListElement{showStr:"1920*1080"}
        ListElement{showStr:"640*320"}
    }

    MyComBox{
        id:cmbResolution
        width:130
        height: 28
        anchors.left: line.left
        anchors.leftMargin: parSetFirstAlignLine
        anchors.top: line.bottom
        anchors.topMargin: 58
        contentBg: "#ffffff"
        itemColorBgNor:"#FFFFFF"
        itemColorBgHoverd: "#E7EAF1"
        indicatorImgSrc:"qrc:/images/imgTypeSelect.png"
        indicatorW: 9
        indicatorH: 5
        itemLeftMargin:0
        itemTopMargin:0
        itemFontColor: "#5A5E66"
        contentFontColor: "#a6000000"
        contentFontSize: fontSize
        bordColor:"#DEDFE3"
        mRadius:2
        model: resolutionModel
        onCurrentIndexChanged: {

        }
    }


    Rectangle{
        id:line1
        width: parent.width-20
        height: 1
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 151
        color: "#EBEEF5"
    }

    Text {
        id: txtUrl
        font.pixelSize: fontSize
        color: fontColor
        anchors.right: inputurl.left
        anchors.rightMargin: firstAlighnlineSpace
        anchors.verticalCenter: inputurl.verticalCenter
        text: qsTr("URL")
    }

    LineEdit {
        id: inputurl
        width: 158
        height: 28
        anchors.left: line1.left
        anchors.leftMargin: parSetFirstAlignLine
        anchors.top: line1.bottom
        anchors.topMargin: 20
        border.width: 1
        border.color: "#DCDFE6"
         radius: 1
      //  text:screenv.funGetCurPath()
        font.pixelSize: fontSize
        placeholderText: ""
        isNeedDoubleClickEdit: false
        textLeftPadding:0
        txtColor: Qt.rgba(0,0,0,0.65)
       color: "#ffffff"
        //onTextChanged: s_recordPathSet(inputrecordPath.text)
    }


    Text {
        id: txtaccount
        font.pixelSize: fontSize
        color: fontColor
        anchors.right: inputaccount.left
        anchors.rightMargin: firstAlighnlineSpace
        anchors.verticalCenter: inputaccount.verticalCenter
        text: qsTr("用户名")
    }

    LineEdit {
        id: inputaccount
        width: 158
        height: 28
        anchors.left: inputurl.left
        anchors.top: inputurl.bottom
        anchors.topMargin: 20
        border.width: 1
        border.color: "#DCDFE6"
         radius: 1
      //  text:screenv.funGetCurPath()
        font.pixelSize: fontSize
        placeholderText: ""
        isNeedDoubleClickEdit: false
        textLeftPadding:0
        txtColor: Qt.rgba(0,0,0,0.65)
        color: "#ffffff"
        //onTextChanged: s_recordPathSet(inputrecordPath.text)
    }

    Text {
        id: txtpassword
        font.pixelSize: fontSize
        color: fontColor
        anchors.right: inputpassword.left
        anchors.rightMargin: firstAlighnlineSpace
        anchors.verticalCenter: inputpassword.verticalCenter
        text: qsTr("密码")
    }

    LineEdit {
        id: inputpassword
        width: 158
        height: 28
        anchors.left: inputaccount.left
        anchors.top: inputaccount.bottom
        anchors.topMargin: 20
        border.width: 1
        border.color: "#DCDFE6"
         radius: 1
      //  text:screenv.funGetCurPath()
        font.pixelSize: fontSize
        placeholderText: ""
        isNeedDoubleClickEdit: false
        textLeftPadding:0
        txtColor: Qt.rgba(0,0,0,0.65)
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

            settxt.text = "Set"
            labelSwitchTime.text = "Time Switch"
            labelResolution.text = "Resolution"
            txtaccount.text = "Account"
            txtpassword.text = "Password"
            break;
        case lChinese:
            settxt.text = "设置"
            labelSwitchTime.text = "时间开关"
            labelResolution.text = "分辨率"
            txtaccount.text = "用户名"
            txtpassword.text = "密码"
            break;
        }
    }

}
