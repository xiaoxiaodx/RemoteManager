#ifndef WARNDPS_H
#define WARNDPS_H

#include <QObject>

class WarnDps : public QObject
{
    Q_OBJECT
public:
    explicit WarnDps(QObject *parent = nullptr);

signals:

public slots:
};

#endif // WARNDPS_H