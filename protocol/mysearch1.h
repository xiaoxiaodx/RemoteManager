#ifndef MySearch1_H
#define MySearch1_H

#include <QObject>
#include <QUdpSocket>


class MySearch1 : public QObject
{
    Q_OBJECT
public:
    explicit MySearch1(QObject *parent = nullptr);
    ~MySearch1();

signals:
    void signal_sendIp(QString ip);
public slots:
    void startSearch();
    void forceFinishSearch();
    void sendSearch();
    void resetSearch();
    void readResultMsg();//udp数据回调
private:

    QUdpSocket *s_searchsocket = NULL;//udp搜索socket
};

#endif // MySearch1_H
