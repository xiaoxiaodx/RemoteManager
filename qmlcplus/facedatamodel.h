#ifndef FACEDATEMODEL_H
#define FACEDATEMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include "help.h"

class FaceDataModelData:public QObject
{
    Q_OBJECT
public:
    FaceDataModelData(const bool &isSelect1,const QString &faceimgPath1,const QString &faceNumber1,const QString &faceName1,const QString &faceimportTime1,QObject *parent=nullptr)
        :QObject(parent),m_isSelect(isSelect1),
          m_faceimgPath(faceimgPath1),m_faceNumber(faceNumber1),
          m_faceName(faceName1),m_faceimportTime(faceimportTime1){}

    QML_PROPERTY(bool,isSelect)
    QML_PROPERTY(QString,faceimgPath)
    QML_PROPERTY(QString,faceNumber)
    QML_PROPERTY(QString,faceName)
    QML_PROPERTY(QString,faceimportTime)
};

class FaceDateModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit FaceDateModel(QObject *parent = nullptr);

    QML_PROPERTY(bool,isAllSelect)

public:
    enum datasourceRoles {
        ISSELECT = Qt::UserRole ,
        FACEIMGPATH,
        FACENUMBER,
        FACENAME,
        FACEIMPORTTIME,
    };

    Q_INVOKABLE void funtest();
    Q_INVOKABLE void funDeleteIndex(int index);
    Q_INVOKABLE void funDeleteSelect();
    Q_INVOKABLE void funSetAllSelect(bool isSelect);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role ) const override;
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    virtual QHash<int, QByteArray> roleNames() const override;


private:


signals:

public slots:


private:
    QList<FaceDataModelData*> m_listFaceData;
};


#endif // FACEDATEMODEL_H
