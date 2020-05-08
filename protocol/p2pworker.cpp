#include "p2pworker.h"

P2pWorker::P2pWorker(QString name)
{
    sessionHandle = -1;

    isWorking = false;
    isP2pInitSucc = false;
    isConnectDevSucc = false;

    isForceStopWorking = false;
    m_name = name;
    readDataBuffCmd.clear();
    readDataBuffCmd.clear();
    resetStramParseVariant();
    resetCmdParseVariant();

    m_serverKey = nullptr;

    pffmpegCodec = nullptr;
    pffmpegCodec1 = nullptr;

    recordThread = nullptr;
    aviRecord = nullptr;


    isRecord = false;


    createAviRecord();
}



void P2pWorker::p2pinit()
{
    int ret;
    //ret = PPCS_Initialize((CHAR*)"EBGDEJBJKDJMGAJMEJGNFPEAHNMMHCNLGMEGBFCFBLIFLFLOCIBJCNOIHEKDJBKCBNNLLHCMPINOAEDHIHMKICBFNNOHBP");//ip
    ret = PPCS_Initialize((CHAR*)"EBGDEJBJKGJKGGJJEJGOFMEDHCMCHMNFGJEBBCCBBMJELILDCAAKCBODHILEJLKLBNMHLHCIOEMIANDPJFNMIDBCMA");

    if(ret >=0)
        isP2pInitSucc = true;

    qDebug()<<"PPCS_Initialize() ret = "<<ret;
    st_PPCS_NetInfo NetInfo;
    ret = PPCS_NetworkDetect(&NetInfo, 0);
    qDebug()<<"PPCS_NetworkDetect() ret = "<<ret;
    qDebug()<<"-------------- NetInfo: -------------------";
    qDebug()<<"Internet Reachable:     "<<((NetInfo.bFlagInternet == 1) ? "YES":"NO");
    qDebug()<<"P2P Server IP resolved :"<<((NetInfo.bFlagHostResolved == 1) ? "YES":"NO");
    qDebug()<<"P2P Server Hello Ack   : "<<((NetInfo.bFlagServerHello == 1) ? "YES":"NO");

    char nat_type[64];
    memset(nat_type,0x0,sizeof(nat_type));
    switch(NetInfo.NAT_Type)
    {
    case 1: strncpy(nat_type,"IP-Restricted Cone type",sizeof(nat_type));break;
    case 2: strncpy(nat_type,"Port-Restricted Cone type",sizeof(nat_type));break;
    case 3: strncpy(nat_type,"Symmetric  Cone type",sizeof(nat_type));break;
    case 0:
    default:
        strncpy(nat_type,"unknown",sizeof(nat_type));
        break;
    }
    qDebug()<<"NAT Type	: "<<nat_type;
    qDebug()<<"My LAN IP	: "<<NetInfo.MyLanIP;
    qDebug()<<"My WAN IP	: "<<NetInfo.MyWanIP;
}

void P2pWorker::stopWoring()
{
    qDebug()<<" P2pWorker isForceStopWorking"<<m_name;
    isForceStopWorking = true;
}

void P2pWorker::slot_connectDev(QString deviceDid,QString name,QString pwd)
{

    qDebug()<<" slot_connectDev";
    if(deviceDid.contains("SST")){

        qDebug()<<"deviceDid  "<<deviceDid;

        QString tmpNumStr = deviceDid.mid(3,6);

        qDebug()<<"tmpNumStr  "<<tmpNumStr;

        QString tmpTrailStr = deviceDid.mid(10,5);

        qDebug()<<"tmpTrailStr  "<<tmpTrailStr;

        int tmpNum = tmpNumStr.toInt();

        qDebug()<<"tmpNum  "<<tmpNum;
        tmpNum += 7700;

        if(tmpNum <10000)
            m_did = "INEW-00"+QString::number(tmpNum)+"-"+tmpTrailStr;
        else if(tmpNum <100000)
            m_did = "INEW-0"+QString::number(tmpNum)+"-"+tmpTrailStr;
        else
            m_did = "INEW-"+QString::number(tmpNum)+"-"+tmpTrailStr;
    }else
        m_did = deviceDid;

    m_password = pwd;
    m_account = name;

    //qDebug()<<"m_did  "<<m_did<<"   "<<m_account<<"    "<<m_password;
    if(!isP2pInitSucc)
        p2pinit();

    sessionHandle = PPCS_Connect(deviceDid.toLatin1().data(),1,0);

    qDebug()<<"P2P connectDev   ret ="<<sessionHandle;
    if(sessionHandle >= 0){

        emit signal_p2pErr(m_name,"conenct succ");

        isWorking = true;
        isConnectDevSucc = true;

        emit signal_p2pConnectState(m_name,1,m_did,m_account,m_password);
        slot_startLoopRead();

    }else{
        QThread::msleep(500);
        emit signal_p2pErr(m_name,err2String(sessionHandle));
        if(!isForceStopWorking)
            emit signal_reconnectP2pDev(m_did,m_account,m_password);
    }
}

void P2pWorker::slot_startLoopRead()
{
    qDebug()<<"P2P slot_startLoopRead";

    createFFmpegDecodec();
    createFFmpegDecodec1();

    while(isWorking  && (!isForceStopWorking)){

        //8个通道
        for(int i=0;i<8;i++)
        {
            unsigned int readSize = 0;
            int ret = PPCS_Check_Buffer(sessionHandle,  i,  NULL, &readSize);

            if(ERROR_PPCS_SUCCESSFUL != ret){
                if(ERROR_PPCS_SESSION_CLOSED_TIMEOUT == ret){
                    qDebug()<<"长时间未收到数据，将断开";
                    emit signal_p2pConnectState(m_name,0,m_did,m_account,m_password);
                    isWorking = false;
                    break;
                }else if (ERROR_PPCS_SESSION_CLOSED_REMOTE == ret){

                    qDebug()<<"***************  "<<"远程关闭"<<ret;
                    emit signal_p2pConnectState(m_name,0,m_did,m_account,m_password);
                }else{
                    qDebug()<<"***************  "<<"P2P异常"<<ret;
                    emit signal_p2pConnectState(m_name,0,m_did,m_account,m_password);
                }
            }else {
                char buff[1024*1024];
                ret = PPCS_Read(sessionHandle,i,buff,(int *)&readSize,5000);


                if(ERROR_PPCS_SUCCESSFUL == ret){
                    // qDebug()<<"通道"<<i<<" 有"<<readSize<<"个数据：";


                    if(i == 1){
                        this->processUnPkg(buff,(int)readSize);

                    }else if(i==0){
                        this->processUnPkg1(buff,(int)readSize);
                    }
                    //qDebug()<<"通道*** "<<i<<" 有"<<readSize<<"个数据："<<endl;
                }
            }
        }
    }


    if(!isForceStopWorking){

        if(sessionHandle >=0)
            PPCS_Close(sessionHandle);

        if(m_serverKey !=nullptr){

            delete m_serverKey;
            m_serverKey = nullptr;
        }
        //如果在这里调用 slot_connectDev(),会导致在重新连上设备  进而调用slot_startLoopRead时报错，故而抛出去(可能是递归函数的调用思路出错)
        emit signal_loopEnd(m_name);
    }

}
void P2pWorker::test()
{

}

int P2pWorker::p2pSendData(QString cmd,QVariant map)
{
    qDebug()<<" p2pSendData:"<<cmd<<"   "<<map;

    int ret = 0;
    //QByteArray loginArr = p2pProtrol.makeJsonPacket(cmd,map);
    if(cmd.compare("login")==0){
        for(int i=0;i<32;i++)
            m_appKey[i] = rand() % 0xFF;
        QByteArray arr;
        arr.append(m_appKey,32);
        qDebug()<<" m_appKey "<<arr.toHex();
        ret = writeBuff1(CMD_USR_KEY, m_appKey, 32);


    }else if(cmd.compare("getVedio")==0){

        ret = writeBuff1(CMD_GET_VIDEO_INFO,"vlive -act list -para 0 ",strlen("vlive -act list -para 0 "));
        if(ret <= 0)
            return  ret;
        ret = writeBuff1(CMD_VIDEO_REQ,"vlive -act set -speed 2 -audio 1 ",strlen("vlive -act set -speed 2 -audio 1"));

    }else if(cmd.compare("stopVideo")==0){
        int ret = writeBuff1(CMD_VIDEO_STOP,"vlive -act set -speed 0 -audio 0 ",strlen("vlive -act set -speed 0 -audio 0"));

    }else if(cmd.compare("replay")==0){

        QString str = map.toMap().value("time").toString();

        QStringList  listTime = str.split(":");
        QString year = listTime.at(0);
        QString mouth = listTime.at(1);
        QString day = listTime.at(2);
        QString hour = listTime.at(3);
        QString minit = listTime.at(4);
        QString sencond = listTime.at(5);

        //replay -act play  -year 2019 -month 12 -day 3 -hour 0 -min 0 -sec 0 -buffmode 0 -duration 0
        QString replaycmd =  "replay -act play -year "+year+" -month "+mouth+" -day "+day+" -hour "+hour+" -min "+minit+" -sec "+sencond+" -buffmode 0 -duration 0";

        qDebug()<<"replay :"<<replaycmd;
        ret = writeBuff1(CMD_REC_REQ,replaycmd.toLocal8Bit().data(),replaycmd.length());
    }else if(cmd.compare("replay stop")==0){

        ret = writeBuff1(CMD_REC_STOP,"replay -act stop",strlen("replay -act stop"));

    }else if(cmd.compare("replay pause")==0){

        ret =  writeBuff1(CMD_REC_PAUSE,"replay -act pause",strlen("replay -act pause"));

    }else if(cmd.compare("replay continue")==0){

        ret =  writeBuff1(CMD_REC_CONTINUE,"replay -act cont",strlen("replay -act cont"));

    }else{
        QByteArray arr = p2pProtrol.makeJsonPacket(cmd,map);
        ret = writeBuff(CMD_NEW_PROTROL,arr.data(),arr.length());
    }


    return ret;
}

void P2pWorker::writeDebugFile(QString str)
{


    //    QTextStream txtOutput(debugFile);
    //    txtOutput << str<< endl;
}

void P2pWorker::resetStramParseVariant()
{
    isFindHead = false;
    isFindCmd = false;
    needLen = 2;
    m_validDatalen = 0;
    m_cmd = 0;
}
void P2pWorker::resetCmdParseVariant()
{
    isCmdFindHead = false;
    isCmdFindCmd = false;
    cmdneedLen = 2;
    mCmd_validDatalen = 0;
    mCmd_cmd = 0;
}



void P2pWorker::processUnPkg(char *buff,int len)
{

    readDataBuffStream.append(buff,len);
    //   qDebug()<<"processUnPkg "<<readDataBuffStream.length()<<" "<<needLen;//<<readDataBuffStream.toHex();
    while(readDataBuffStream.length() >= needLen)
    {

        //qDebug()<<"while "<<readDataBuffStream.toHex()<<" "<<needLen;
        if(!isFindHead)
        {

            unsigned short head = char2Short(readDataBuffStream.at(0),readDataBuffStream.at(1));

            if(head == MEIAN_HEAD || head == MEIAN_HEAD1)
            {

                //qDebug()<<"find head";

                writeDebugFile("find head ");
                readDataBuffStream.remove(0,2);
                isFindHead = true;
                needLen = 6;
            }else {

                readDataBuffStream.remove(0,1);
                continue;
            }
        }


        if(!isFindCmd){

            if(readDataBuffStream.length() >= needLen){


                int DatalenL = char2Short(readDataBuffStream.at(0),readDataBuffStream.at(1));
                int DatalenH = char2Short(readDataBuffStream.at(4),readDataBuffStream.at(5));

                int datL1 = 0x000000ff & readDataBuffStream.at(0);
                int datL2 = 0x000000ff & readDataBuffStream.at(1);

                int datH1 = 0x000000ff & readDataBuffStream.at(4);
                int datH2 = 0x000000ff & readDataBuffStream.at(5);

                int datL = datL1 + datL2*256;
                int datH = datH1 + datH2*256;


                m_validDatalen = datL + datH * 256*256;

                m_cmd = char2Short(readDataBuffStream.at(2),readDataBuffStream.at(3));

                readDataBuffStream.remove(0,6);

                needLen = m_validDatalen;

                isFindCmd = true;

            }else
                break;
        }

        if(readDataBuffStream.length() >= needLen){

            if(m_cmd == CMD_USR_KEY){

                QByteArray arr ;
                arr.append(readDataBuffStream.data(),needLen);

                m_serverKey = new char[serverKeyLen];

                memcpy(m_serverKey,arr.data(),serverKeyLen);

                QString loginCmd = "authcfg -act checkuser -name "+m_account+" -passwd "+ m_password;

                //想要接收流必须要使用命令登录
                writeBuff1(CMD_LOGIN,loginCmd.toLatin1().data(),loginCmd.length());

                QVariantMap map;
                map.insert("username",m_account);
                map.insert("password",m_password);
                QByteArray arrLogin = p2pProtrol.makeJsonPacket("login",map);
                writeBuff(CMD_NEW_PROTROL,arrLogin.data(),arrLogin.length());

                qDebug()<<"找到 CMD_USR_KEY  内容:"<<m_serverKey<<"    ";

            }else if(m_cmd == CMD_LOGIN) {

                QByteArray arr ;
                arr.append(readDataBuffStream.data(),needLen);

                QJsonDocument jsDoc = QJsonDocument::fromJson(arr.data());

                if(jsDoc.isObject())
                    p2pProtrol.unJsonPacket(arr);
                else{

                    usr_decode(arr.data(), arr.length(),m_serverKey, serverKeyLen);

                    QString returnStr = QString(arr);

                    qDebug()<<"找到 CMD_LOGIN  内容:"<<returnStr;

                    if(returnStr.contains("error")){

                        emit signal_loginState(0);

                    }else
                        emit signal_loginState(1);

                }

            }else if(m_cmd == CMD_VIDEO_TRNS){

                QByteArray arr;
                arr.append(readDataBuffStream.data(),needLen);

                video_frame_header *frameHeader = (video_frame_header *)arr.data();

                int vstreamLen = frameHeader->frame_len;

                //qDebug()<<"找到  视频信息 1111111:"<<vstreamLen;//<<"  "<<arr.toHex();


                QImage *img = pffmpegCodec->decodeVFrame((unsigned char*)readDataBuffStream.data(),needLen);


                if(isRecord)
                    emit signal_recordVedio(arr.data(),arr.length(),1000);

                emit signal_sendH264(m_name,QVariant::fromValue(img),1000);

            }else if(m_cmd == CMD_AUDIO_TRNS){
                //qDebug()<<"找到  音频信息:"<<needLen<<"   "<<readDataBuffStream.length();
                QByteArray arr ;
                arr.append(readDataBuffStream.data(),needLen);

                video_frame_header *video_pack= (video_frame_header*)(readDataBuffStream.data());

                if(isRecord)
                    emit signal_recordAudio(arr.data(),arr.length(),1000);

                emit signal_sendPcmALaw(m_name,arr.data(), arr.length(),1000);

            }else if(m_cmd == CMD_REC_REQ){
                qDebug()<<"请求回放应答 "<<needLen<<"   "<<readDataBuffStream.length();

                QVariantMap map;
                map.insert("cmd","replay");
                emit signal_p2pReplyData(m_name,map);

            }else if(m_cmd == CMD_REC_VIDEO_TRNS){//回放视频
                qDebug()<<"找到  回放视频信息:"<<needLen<<"   "<<readDataBuffStream.length();

                // writeDebugFile("replay video "+QString::number(needLen)+"  "+QString::number(readDataBuffStream.length()));
                QByteArray arr ;
                arr.append(readDataBuffStream.data(),needLen);

                // video_frame_header *video_pack= (video_frame_header*)(readDataBuffStream.data());

                qDebug()<<"找到  回放视频信息 ** :"<<needLen<<"   "<<readDataBuffStream.length();

                QImage *img = pffmpegCodec1->decodeVFrame((unsigned char*)arr.data(),needLen);

                if(img != nullptr)
                    emit signal_sendReplayH264(m_name,QVariant::fromValue(img),1000);
                qDebug()<<"找到  回放视频信息 ***:"<<needLen<<"   "<<readDataBuffStream.length();
                QThread::msleep(10);

            }else if(m_cmd == CMD_REC_AUDIO_TRNS){//回放音频
                //qDebug()<<"找到  回放音频信息:"<<needLen<<"   "<<readDataBuffStream.length();
                // writeDebugFile("replay audio "+QString::number(needLen)+"  "+QString::number(readDataBuffStream.length()));

                QByteArray arr ;
                arr.append(readDataBuffStream.data(),needLen);

                video_frame_header *video_pack= (video_frame_header*)(readDataBuffStream.data());

                //QThread::msleep(2);
                //emit signal_sendReplayPcmALaw(m_name,arr.data(), arr.length(),1000);

            }else if(m_cmd == CMD_REC_STOP){

                QVariantMap map;
                map.insert("cmd","replay stop");
                emit signal_p2pReplyData(m_name,map);
            }else if(m_cmd == CMD_REC_PAUSE){


                QVariantMap map;
                map.insert("cmd","replay pause");
                emit signal_p2pReplyData(m_name,map);
            }else if(m_cmd == CMD_REC_CONTINUE){

                QVariantMap map;
                map.insert("cmd","replay continue");
                emit signal_p2pReplyData(m_name,map);
            }else if(m_cmd == CMD_NEW_PROTROL){

                QByteArray arr ;
                arr.append(readDataBuffStream.data(),needLen);
                QVariantMap map = p2pProtrol.unJsonPacket(arr);

                qDebug()<<"新协议:"<<m_cmd;

                emit signal_p2pReplyData(m_name,map);

            }else
                qDebug()<<"未知命令111:"<<m_cmd;

            readDataBuffStream.remove(0,needLen);
            resetStramParseVariant();

        }else
            break;


    }
}



void P2pWorker::processUnPkg1(char *buff,int len)
{

    readDataBuffCmd.append(buff,len);
    //   qDebug()<<"processUnPkg "<<readDataBuffCmd.length()<<" "<<cmdneedLen;//<<readDataBuffCmd.toHex();
    while(readDataBuffCmd.length() >= cmdneedLen)
    {

        //qDebug()<<"while "<<readDataBuffCmd.toHex()<<" "<<cmdneedLen;
        if(!isCmdFindHead)
        {

            unsigned short head = char2Short(readDataBuffCmd.at(0),readDataBuffCmd.at(1));

            if(head == MEIAN_HEAD || head == MEIAN_HEAD1)
            {

                //qDebug()<<"find head";

                writeDebugFile("find head ");
                readDataBuffCmd.remove(0,2);
                isCmdFindHead = true;
                cmdneedLen = 6;
            }else {

                readDataBuffCmd.remove(0,1);
                continue;
            }
        }


        if(!isCmdFindCmd){

            if(readDataBuffCmd.length() >= cmdneedLen){


                int DatalenL = char2Short(readDataBuffCmd.at(0),readDataBuffCmd.at(1));
                int DatalenH = char2Short(readDataBuffCmd.at(4),readDataBuffCmd.at(5));

                int datL1 = 0x000000ff & readDataBuffCmd.at(0);
                int datL2 = 0x000000ff & readDataBuffCmd.at(1);

                int datH1 = 0x000000ff & readDataBuffCmd.at(4);
                int datH2 = 0x000000ff & readDataBuffCmd.at(5);

                int datL = datL1 + datL2*256;
                int datH = datH1 + datH2*256;


                mCmd_validDatalen = datL + datH * 256*256;

                mCmd_cmd = char2Short(readDataBuffCmd.at(2),readDataBuffCmd.at(3));


                //                if(mCmd_validDatalen >= 500*1024){
                //                    resetParseVariant();
                //                    break;
                //                }


                readDataBuffCmd.remove(0,6);

                cmdneedLen = mCmd_validDatalen;

                isCmdFindCmd = true;

            }else
                break;
        }

        if(readDataBuffCmd.length() >= cmdneedLen){

            if(mCmd_cmd == CMD_USR_KEY){

                QByteArray arr ;
                arr.append(readDataBuffCmd.data(),cmdneedLen);

                m_serverKey = new char[serverKeyLen];

                memcpy(m_serverKey,arr.data(),serverKeyLen);

                QString loginCmd = "authcfg -act checkuser -name "+m_account+" -passwd "+ m_password;

                //想要接收流必须要使用命令登录
                writeBuff1(CMD_LOGIN,loginCmd.toLatin1().data(),loginCmd.length());

                QVariantMap map;
                map.insert("username",m_account);
                map.insert("password",m_password);
                QByteArray arrLogin = p2pProtrol.makeJsonPacket("login",map);
                writeBuff(CMD_NEW_PROTROL,arrLogin.data(),arrLogin.length());

                qDebug()<<"找到 CMD_USR_KEY  内容:"<<m_serverKey<<"    ";

            }else if(mCmd_cmd == CMD_LOGIN) {

                QByteArray arr ;
                arr.append(readDataBuffCmd.data(),cmdneedLen);

                QJsonDocument jsDoc = QJsonDocument::fromJson(arr.data());

                if(jsDoc.isObject())
                    p2pProtrol.unJsonPacket(arr);
                else{

                    usr_decode(arr.data(), arr.length(),m_serverKey, serverKeyLen);

                    QString returnStr = QString(arr);

                    qDebug()<<"找到 CMD_LOGIN  内容:"<<returnStr;

                    if(returnStr.contains("error")){

                        emit signal_loginState(0);

                    }else
                        emit signal_loginState(1);

                }

            }else if(mCmd_cmd == CMD_VIDEO_TRNS){

                QByteArray arr;
                arr.append(readDataBuffCmd.data(),cmdneedLen);

                video_frame_header *frameHeader = (video_frame_header *)arr.data();

                int vstreamLen = frameHeader->frame_len;

                qDebug()<<"找到  视频信息 1:"<<vstreamLen;//<<"  "<<arr.toHex();


                QImage *img = pffmpegCodec->decodeVFrame((unsigned char*)readDataBuffCmd.data(),cmdneedLen);

                if(isRecord)
                    emit signal_recordVedio(readDataBuffCmd.data(),cmdneedLen,1000);
                emit signal_sendH264(m_name,QVariant::fromValue(img),1000);

            }else if(mCmd_cmd == CMD_AUDIO_TRNS){
                qDebug()<<"找到  音频信息:"<<cmdneedLen<<"   "<<readDataBuffCmd.length();
                QByteArray arr ;
                arr.append(readDataBuffCmd.data(),cmdneedLen);

                video_frame_header *video_pack= (video_frame_header*)(readDataBuffCmd.data());

                if(isRecord)
                    emit signal_recordAudio(readDataBuffCmd.data(),cmdneedLen,1000);

                emit signal_sendPcmALaw(m_name,arr.data(), arr.length(),1000);

            }else if(mCmd_cmd == CMD_REC_REQ){
                qDebug()<<"请求回放应答1 "<<cmdneedLen<<"   "<<QString(readDataBuffCmd);

                QVariantMap map;
                map.insert("cmd","replay");
                emit signal_p2pReplyData(m_name,map);
            }else if(mCmd_cmd == CMD_REC_VIDEO_TRNS){//回放视频
                qDebug()<<"找到  回放视频信息1:"<<cmdneedLen<<"   "<<readDataBuffCmd.length();

                // writeDebugFile("replay video "+QString::number(cmdneedLen)+"  "+QString::number(readDataBuffCmd.length()));
                QByteArray arr ;
                arr.append(readDataBuffCmd.data(),cmdneedLen);

                video_frame_header *video_pack= (video_frame_header*)(readDataBuffCmd.data());

                QImage *img = pffmpegCodec1->decodeVFrame((unsigned char*)readDataBuffCmd.data(),cmdneedLen);

                emit signal_sendReplayH264(m_name,QVariant::fromValue(img),1000);

                QThread::msleep(66);

            }else if(mCmd_cmd == CMD_REC_AUDIO_TRNS){//回放音频
                //qDebug()<<"找到  回放音频信息:"<<cmdneedLen<<"   "<<readDataBuffCmd.length();
                // writeDebugFile("replay audio "+QString::number(cmdneedLen)+"  "+QString::number(readDataBuffCmd.length()));

                QByteArray arr ;
                arr.append(readDataBuffCmd.data(),cmdneedLen);

                video_frame_header *video_pack= (video_frame_header*)(readDataBuffCmd.data());

                //QThread::msleep(2);
                //emit signal_sendReplayPcmALaw(m_name,arr.data(), arr.length(),1000);

            }else if(mCmd_cmd == CMD_REC_STOP){

                QVariantMap map;
                map.insert("cmd","replay stop");
                emit signal_p2pReplyData(m_name,map);
            }else if(mCmd_cmd == CMD_REC_PAUSE){


                QVariantMap map;
                map.insert("cmd","replay pause");
                emit signal_p2pReplyData(m_name,map);
            }else if(mCmd_cmd == CMD_REC_CONTINUE){

                QVariantMap map;
                map.insert("cmd","replay continue");
                emit signal_p2pReplyData(m_name,map);
            }else if(mCmd_cmd == CMD_NEW_PROTROL){

                QByteArray arr ;
                arr.append(readDataBuffCmd.data(),cmdneedLen);
                QVariantMap map = p2pProtrol.unJsonPacket(arr);

                qDebug()<<"新协议:"<<mCmd_cmd;

                emit signal_p2pReplyData(m_name,map);

            }else if(mCmd_cmd == CMD_GET_VIDEO_INFO){
                qDebug()<<"新协议:"<<mCmd_cmd;
            }else if(mCmd_cmd == CMD_VIDEO_REQ){
                qDebug()<<"新协议:"<<mCmd_cmd;
            }
            qDebug()<<"未知命令1:"<<mCmd_cmd;

            readDataBuffCmd.remove(0,cmdneedLen);
            resetCmdParseVariant();

        }else
            break;
    }
}

int P2pWorker::writeBuff(unsigned int cmd,char* buff,int bufflen)
{

    char sendBuff[1500];
    int sendBufflen = 0;

    processReqPkg(cmd,buff,bufflen,sendBuff,&sendBufflen,false);

    int ret = PPCS_Write(sessionHandle,0,sendBuff,sendBufflen);


    return ret;
    //    QByteArray arr;
    //    arr.append(sendBuff,sendBufflen);

    //qDebug()<<"writeBuff   "<<ret<<"    "<<arr.toHex();
}

int P2pWorker::writeBuff1(unsigned int cmd,char* buff,int bufflen)
{

    char sendBuff[1500];
    int sendBufflen = 0;

    processReqPkg(cmd,buff,bufflen,sendBuff,&sendBufflen,true);

    int ret = PPCS_Write(sessionHandle,0,sendBuff,sendBufflen);


    return ret;
    //    QByteArray arr;
    //    arr.append(sendBuff,sendBufflen);

    //    qDebug()<<"writeBuff1   "<<ret<<"    "<<arr.toHex();
}

void P2pWorker::processReqPkg(unsigned int cmd,  char* inBuff, int inbuffSize, char * outBuff,int *outBuffSize,bool isNeedEncrypt)
{
    struct meian_pkg_head_type m_pkg_head;

    memset(&m_pkg_head, 0, sizeof(m_pkg_head));
    if(isNeedEncrypt)
        m_pkg_head.head = (unsigned short)(MEIAN_HEAD1);
    else
        m_pkg_head.head = (unsigned short)(MEIAN_HEAD);
    m_pkg_head.cmd = (unsigned short)(cmd&0xFFFF);

    m_pkg_head.len =(unsigned short)(inbuffSize&0xFFFF);
    if(inbuffSize>0x10000)
    {
        m_pkg_head.reslv=(unsigned short)((inbuffSize&0xFFFF0000)>>16);
    }

    memcpy(outBuff, &m_pkg_head, sizeof(m_pkg_head));
    memcpy(outBuff + sizeof(m_pkg_head), (char *)inBuff, inbuffSize);

    *outBuffSize=inbuffSize+ sizeof(m_pkg_head);

    if(isNeedEncrypt && m_serverKey != nullptr)
        usr_decode(outBuff + sizeof(m_pkg_head), inbuffSize, m_serverKey, serverKeyLen);
}


void P2pWorker::usr_decode(char *pIn, int inLen, char *pKey, int keyLen)
{
    int i = 0;

    for (i = 0; i < inLen; i++)
    {
        *(pIn + i) = (char)(*(pIn + i) ^ *(pKey + (i % keyLen)));
    }
}
void P2pWorker::setIsRecord(bool isrecord,QString path)
{

    if(isrecord){
        emit signal_setRecordingFilePath(path);
        emit signal_startRecord(m_name,1000);
    }else
        emit signal_endRecord();

    this->isRecord = isrecord;
}

void P2pWorker::createAviRecord()
{

    if(aviRecord == nullptr){
        recordThread = new QThread;
        aviRecord = new AviRecord("");
        connect(this,&P2pWorker::signal_recordAudio,aviRecord,&AviRecord::slot_writeAudio);
        connect(this,&P2pWorker::signal_recordVedio,aviRecord,&AviRecord::slot_writeVedio);
        //connect(this,&P2pWorker::signal_startRecord,aviRecord,&AviRecord::slot_startRecord);
        connect(this,&P2pWorker::signal_endRecord,aviRecord,&AviRecord::slot_endRecord);
        connect(this,&P2pWorker::signal_setRecordingFilePath,aviRecord,&AviRecord::slot_setAviSavePath);
        connect(recordThread,&QThread::finished,aviRecord,&AviRecord::deleteLater);
        connect(recordThread,&QThread::finished,recordThread,&QThread::deleteLater);
        aviRecord->moveToThread(recordThread);
        recordThread->start();
    }
}

unsigned short P2pWorker::char2Short(char ch1,char ch2){

    unsigned short head0 = 0x00ff &  ch1;
    unsigned short head1 = 0x00ff &  ch2;

    return  head0 + head1*256;

}

QString P2pWorker::err2String(int ret)
{


    QString errStr = "";
    if(ret >= 0){
        errStr = "succ";
    }else if (ret == ERROR_PPCS_NOT_INITIALIZED) {
        errStr = "not initialized";
    }else if (ret == ERROR_PPCS_ALREADY_INITIALIZED) {
        errStr = "already initialized";
    }else if (ret == ERROR_PPCS_TIME_OUT) {
        errStr = "time out";
    }else if (ret == ERROR_PPCS_INVALID_ID) {
        errStr = "invalid id";
    }else if (ret == ERROR_PPCS_INVALID_PARAMETER) {
        errStr = "invalid parameter";
    }else if (ret == ERROR_PPCS_DEVICE_NOT_ONLINE) {
        errStr = "device not online";
    }else if (ret == ERROR_PPCS_FAIL_TO_RESOLVE_NAME) {
        errStr = "fail to resolve name";
    }else if (ret == ERROR_PPCS_INVALID_PREFIX) {
        errStr = "invalid prefix";
    }else if (ret == ERROR_PPCS_ID_OUT_OF_DATE) {
        errStr = "id out of date";
    }else if (ret == ERROR_PPCS_NO_RELAY_SERVER_AVAILABLE) {
        errStr = "no relay server available";
    }else if (ret == ERROR_PPCS_INVALID_SESSION_HANDLE) {
        errStr = "invalid session handle";
    }else if (ret == ERROR_PPCS_SESSION_CLOSED_REMOTE) {
        errStr = "session closed remote";
    }else if (ret == ERROR_PPCS_SESSION_CLOSED_TIMEOUT) {
        errStr = "session closed timeout";
    }else if (ret == ERROR_PPCS_SESSION_CLOSED_CALLED) {
        errStr = "session closed called";
    }else if (ret == ERROR_PPCS_REMOTE_SITE_BUFFER_FULL) {
        errStr = "remote site buffer full";
    }else if (ret == ERROR_PPCS_USER_LISTEN_BREAK) {
        errStr = "user listen break";
    }else if (ret == ERROR_PPCS_MAX_SESSION) {
        errStr = "max session";
    }else if (ret == ERROR_PPCS_UDP_PORT_BIND_FAILED) {
        errStr = "udp port bind failed";
    }else if (ret == ERROR_PPCS_USER_CONNECT_BREAK) {
        errStr = "user connect break";
    }else if (ret == ERROR_PPCS_SESSION_CLOSED_INSUFFICIENT_MEMORY) {
        errStr = "session closed insufficient memory";
    }else if (ret == ERROR_PPCS_INVALID_APILICENSE) {
        errStr = "invalid apilicense";
    }else if (ret == ERROR_PPCS_FAIL_TO_CREATE_THREAD) {
        errStr = "fail to create thread";
    }

    return  "p2p err:"+errStr;
}
void P2pWorker::createFFmpegDecodec()
{
    if(pffmpegCodec == nullptr)
    {
        pffmpegCodec = new FfmpegCodec;
        pffmpegCodec->vNakedStreamDecodeInit(AV_CODEC_ID_H264);
        pffmpegCodec->aNakedStreamDecodeInit(AV_CODEC_ID_PCM_ALAW,AV_SAMPLE_FMT_S16,8000,1);
        pffmpegCodec->resetSample(AV_CH_LAYOUT_MONO,AV_CH_LAYOUT_MONO,8000,44100,AV_SAMPLE_FMT_S16,AV_SAMPLE_FMT_S16,160);
        // connect(pffmpegCodec,&FfmpegCodec::signal_sendMsg,this,&XVideo::slot_recMsg);
    }
}

void P2pWorker::createFFmpegDecodec1()
{
    if(pffmpegCodec1 == nullptr)
    {
        pffmpegCodec1 = new FfmpegCodec;
        pffmpegCodec1->vNakedStreamDecodeInit(AV_CODEC_ID_H264);
        pffmpegCodec1->aNakedStreamDecodeInit(AV_CODEC_ID_PCM_ALAW,AV_SAMPLE_FMT_S16,8000,1);
        pffmpegCodec1->resetSample(AV_CH_LAYOUT_MONO,AV_CH_LAYOUT_MONO,8000,44100,AV_SAMPLE_FMT_S16,AV_SAMPLE_FMT_S16,160);
        // connect(pffmpegCodec,&FfmpegCodec::signal_sendMsg,this,&XVideo::slot_recMsg);
    }
}



P2pWorker::~P2pWorker()
{
    qDebug()<< " 析构   P2pWorker";

    if(sessionHandle >=0)
        PPCS_Close(sessionHandle);

    PPCS_DeInitialize();

    if(m_serverKey != nullptr)
        delete m_serverKey;

    if(recordThread != nullptr)
        recordThread->quit();


}





