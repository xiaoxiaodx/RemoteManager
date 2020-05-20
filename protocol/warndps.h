#ifndef WARNDPS_H
#define WARNDPS_H

#include <QObject>

#include "NDT_API.h"
#include "WiPN_API.h"
#include "WiPN_WebAPI.h"
#include "DPS_API.h"
#include "SPS_API.h"
#include "cJSON.h"
#include "base64.h"


#define SIZE_iPNLicense 100
#define SIZE_iPNLicense 100
#define SIZE_SubsString 100
#define SIZE_PostString 100

class WarnDps : public QObject
{
    Q_OBJECT
public:
    explicit WarnDps(QObject *parent = nullptr);
    void initDps();
signals:

public slots:

private:

    void parameterInit();
    void GetAPIVersion();

    void recDps();
    const char* getDPSErrorCodeInfo(int err);


    void subCmd(QString did);
    char g_NDT_InitString[SIZE_InitString];  // InitString
    char g_NDT_AES128Key[SIZE_AES128Key];    // NDT AESKey
    CHAR g_DID[SIZE_DID] = {0};                 // Device DID
    CHAR g_iPNLicense[SIZE_iPNLicense] = {0};   // iPN License
    ULONG g_EventCH = 0;                        // Event Channel: 0~65535
    UINT16 Port = 0;

    // DPS Parameter
    const char *g_AG_Name = "DPS";
    char g_APP_Name[SIZE_APPName] = {0};        // app name
    char g_DPS_IP[64] = {0};                    // IP or domain Name
    UINT16 g_DPS_Port = 32750;
    char g_DPS_Key[20];
    char g_DPS_AES128Key[20];

    CHAR g_SNDIDString[SIZE_SNDIDString] = {0};
    CHAR g_SPS_IPString[SIZE_SPSInfo] = {};

    /// DPS Initialize flags: 0->not Initialize, 1->Initialize OK.
    int g_DPS_InitFlag = 0;

    //// save token from DPS Query
    char g_Token[40] = {0};

    char **gQSDID = NULL;
    char *gQSDIDBuf = NULL;

    //// Save SubscribeServerString from QueryServer, use for Subscribe or UnSubscribe
    CHAR g_SubsString[SIZE_SubsString] = {0};
    //// Save PostServerString from QueryServer, use for Post
    CHAR g_PostString[SIZE_PostString] = {0};
    //// Save SPSInfo from QueryServer, use for SPS
    CHAR g_SPSInfo[SIZE_SPSInfo] = {};

    CHAR gAPP_Name[20] = {0};// "iEagleCam";
};

#endif // WARNDPS_H
