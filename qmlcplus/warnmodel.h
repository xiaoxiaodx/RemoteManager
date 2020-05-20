#ifndef WARNMODEL_H
#define WARNMODEL_H
#include <QAbstractListModel>
#include <QQuickWindow>
#include <QDateTime>
#include <QDir>
#include "help.h"
class WarnModelData : public QObject
{
    Q_OBJECT

    QML_PROPERTY(bool,isSelect)
    QML_PROPERTY(QString,warnTime)
    QML_PROPERTY(QString,warnTemp)
    QML_PROPERTY(QString,imgName)
    QML_PROPERTY(QString,absolutePath)
    QML_PROPERTY(QString,personName)
    QML_PROPERTY(QString,personSerial)
    QML_PROPERTY(QString,deviceChannel)
    QML_PROPERTY(QString,deviceName)

public:
    WarnModelData(const bool &isSelect,const QString &warnTime,const QString &warnTemp,QString imgName,QString path,
                  QString personname="",QString personserial="",QString deviceChannel= "",QString deviceName = "",QObject *parent=nullptr)
        :QObject(parent),m_isSelect(isSelect),
        m_warnTime(warnTime),m_warnTemp(warnTemp),m_imgName(imgName),m_absolutePath(path)
      ,m_personName(personname),m_personSerial(personserial)
        ,m_deviceChannel(deviceChannel),m_deviceName(deviceName){  }
};
class WarnModel : public QAbstractListModel
{
    Q_OBJECT
public:

    WarnModel(QObject *parent = nullptr);

    enum datasourceRoles {
        IsSelect = Qt::UserRole ,
        WarnTime,
        WarnTemp,
        ImgName,
        AbsolutePath,
        PersonName,
        PersonSerial,
        DeviceChannel,
        DeviceName,
    };
    Q_INVOKABLE void funFlushWarnInfo(QString capturePaht,QString logFileName);
    Q_INVOKABLE void funDeleteIndex(int index);
    Q_INVOKABLE void funDeleteSelect();
    Q_INVOKABLE int funFindIndex(QString h,QString m,QString s);
    Q_INVOKABLE void funSetAllSelect(bool isSelect);//选中所有数据
    Q_INVOKABLE void funSetInitSelectFalse();//将数据初始化选中属性修改为false


    //截屏
    Q_INVOKABLE bool funScreenShoot(QString path,QQuickWindow *quic,int capx,int capy,int capw,int caph,float warnTemp);

    Q_INVOKABLE void funAppendWarnInfo(QString path,QString channel,QString devicename,QVariantMap map,QByteArray arrimg);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role ) const override;
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    virtual QHash<int, QByteArray> roleNames() const override;

private:
    void removeIndex(int index);
    void removeAll();

    QList<WarnModelData*> m_listWarn;
    QString curDate = "";
    QString curPath = "";
    bool curSelect = false;
};

#endif // WARNMODEL_H
