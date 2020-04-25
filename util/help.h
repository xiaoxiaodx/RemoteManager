#ifndef HELP_H
#define HELP_H



//#define QML_PROPERTY(type, name, READ, getter, WRITE, setter, NOTIFY, notifyer)  type m_##name; \
//    Q_PROPERTY(type name READ getter WRITE setter NOTIFY notifyer) \
//    public: type getter() const { return m_##name;} \
//    public Q_SLOTS: void setter(type arg) { m_##name = arg; emit notifyer(arg);} \
//    Q_SIGNALS:  \
//    void notifyer(type arg);\
//    private:


#define QML_PROPERTY(type,name) \
    Q_PROPERTY(type name READ name WRITE set##name NOTIFY name##Change); \
    public: type name() const { return m_##name;} \
    public Q_SLOTS: void set##name(type arg) { m_##name = arg; emit name##Change(arg);} \
    Q_SIGNALS:  \
    void name##Change(type arg);\
    private: \
    type m_##name; \


//#define QML_PROPERTY(type,name,group) \
//    Q_PROPERTY(type name READ name WRITE set##name NOTIFY name##Change); \
//    public: type name() const { msetting->beginGroup(group);type value=msetting->value(#name);msetting->endGroup();return value;} \
//    public Q_SLOTS: void set##name(type arg) { msetting->beginGroup(group);msetting->setValue(#name,arg);msetting->endGroup();emit name##Change(arg);} \
//    Q_SIGNALS:  \
//    void name##Change(type arg);\
//    private:





//class SystemAttributes :public QObject{
//    Q_OBJECT
//public:
//    QSettings *msetting;
//    SystemAttributes(){
//        QString m_qstrFileName = QCoreApplication::applicationDirPath() + "/systemAttributes.ini";
//        msetting = new QSettings(m_qstrFileName, QSettings::IniFormat);
//    };
//private:

//    QML_PROPERTY(QVariant,netwokType,"Login")
//    QML_PROPERTY(QVariant,tcpSerIsAutoLogin,"Login")
//    QML_PROPERTY(QVariant,tcpSerAccount,"Login")
//    QML_PROPERTY(QVariant,tcpSerPassword,"Login")
//    QML_PROPERTY(QVariant,tcpSerIp,"Login")
//    QML_PROPERTY(QVariant,tcpSerPort,"Login")
//    QML_PROPERTY(QVariant,tcpSerIsRemPwd,"Login")

//    QML_PROPERTY(QVariant,screenshotFilePath,"FilePath")
//    QML_PROPERTY(QVariant,recordVedioFilePath,"FilePath")

//    QML_PROPERTY(QVariant,recordVedioFileFormat,"FileFormat")
//    QML_PROPERTY(QVariant,screenshotFileFormat,"FileFormat")
//    QML_PROPERTY(QVariant,recordVedioTime,"FileFormat")

//};

#endif // HELP_H
