#ifndef P2PPROTROL_H
#define P2PPROTROL_H

#include <QObject>
#include <QMap>
#include <QVariant>
#include <QJsonObject>
#include <QJsonDocument>
class P2pProtrol : public QObject
{
    Q_OBJECT
public:
    explicit P2pProtrol(QObject *parent = nullptr);

    QString sessionid;
signals:

public slots:

    QByteArray makeJsonPacket(QString cmd,QVariant msgContent);
    QMap<QString,QVariant> unJsonPacket(QByteArray &arr);


};

#endif // P2PPROTROL_H
