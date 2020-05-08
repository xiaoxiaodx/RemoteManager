#include "facedatamodel.h"
#include <debuglog.h>
#include <QDebug>

FaceDateModel::FaceDateModel(QObject *parent) : QAbstractListModel(parent)
{

}

void FaceDateModel::funtest()
{


    beginInsertRows(QModelIndex(),0,1);

    m_listFaceData.append(new FaceDataModelData(m_isAllSelect,"19911103","1111111","sasads","sasads"));
    m_listFaceData.append(new FaceDataModelData(m_isAllSelect,"19911103","1111111","sasads","sasads"));
    m_listFaceData.append(new FaceDataModelData(m_isAllSelect,"19911103","1111111","sasads","sasads"));
    m_listFaceData.append(new FaceDataModelData(m_isAllSelect,"19911103","1111111","sasads","sasads"));
    endInsertRows();
}


void FaceDateModel::funDeleteIndex(int index)
{
    qDebug()<<"DeviceModel funDeleteIndex:"<<index<<"   "<<m_listFaceData.size();

    if(m_listFaceData.size() <= index){
        DebugLog::getInstance()->writeLog("删除警报信息异常:index 越界");
        return;
    }

    beginRemoveRows(QModelIndex(),index,index);

    FaceDataModelData *date = m_listFaceData.takeAt(index);
    delete date;
    endRemoveRows();
}

void FaceDateModel::funDeleteSelect(){
    beginResetModel();
    for (int i=0;i<m_listFaceData.size();i++) {

        if(m_listFaceData.at(i)->isSelect()){
            FaceDataModelData *date = m_listFaceData.takeAt(i);
            delete date;
            i -= 1;
        }
    }
    endResetModel();
}

void FaceDateModel::funSetAllSelect(bool isSelect)
{

    beginResetModel();
    for (int i=0;i<m_listFaceData.size();i++) {
        m_listFaceData.at(i)->setisSelect(isSelect);
    }
    endResetModel();
}

int FaceDateModel::rowCount(const QModelIndex &) const
{
    return m_listFaceData.count();
}



QVariant FaceDateModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= m_listFaceData.size())
        return QVariant();
    if(role == ISSELECT)
         return QVariant::fromValue(m_listFaceData.at(index.row())->isSelect());
    else if (role == FACEIMGPATH)
        return QVariant::fromValue(m_listFaceData.at(index.row())->faceimgPath());
    else if(role == FACENUMBER)
        return QVariant::fromValue(m_listFaceData.at(index.row())->faceNumber());
    else if(role == FACENAME)
        return QVariant::fromValue(m_listFaceData.at(index.row())->faceName());
    else if(role == FACEIMPORTTIME)
        return QVariant::fromValue(m_listFaceData.at(index.row())->faceimportTime());

    return QVariant();
}

QHash<int, QByteArray> FaceDateModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[ISSELECT] = "isSelect";
    roles[FACEIMGPATH] = "facePath";
    roles[FACENUMBER] = "faceNumber";
    roles[FACENAME] = "faceName";
    roles[FACEIMPORTTIME] = "faceimportTime";

    return roles;
}


bool FaceDateModel::setData(const QModelIndex &index, const QVariant &value, int role)
{

    FaceDataModelData *modelData= m_listFaceData[index.row()];
    if (data(index, role) != value) {
        if(role == FACEIMGPATH)
            modelData->setfaceimgPath(value.toString());
        else if(role == FACENUMBER)
            modelData->setfaceNumber(value.toString());
        else if(role == FACENAME)
            modelData->setfaceName(value.toString());
        else if(role == FACEIMPORTTIME)
            modelData->setfaceimportTime(value.toString());
        else if(role == ISSELECT)
            modelData->setisSelect(value.toBool());
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags FaceDateModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable; // FIXME: Implement me!
}
