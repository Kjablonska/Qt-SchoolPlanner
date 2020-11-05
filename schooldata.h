#ifndef SCHOOLDATA_H
#define SCHOOLDATA_H

#include <QJsonObject>
#include <QStringList>
#include <QJsonDocument>
#include <QFile>
#include <QJsonArray>
#include <QStandardItemModel>
#include <QModelIndex>
#include <QList>
#include <QVariant>

#include "activity.h"

#include <QMap>

class SchoolData
{
public:
    SchoolData();
    ~SchoolData();
    QStringList getDataFromJson(QString data);
    void initializeSchoolData();

    void setAvailableRooms();
    void setAvailableTeachers();
    void setAvailableClasses();
    void setAvailableGroups();

    void initializeRoomsWithData(QStandardItemModel *model);
    void setRoomData(QStandardItemModel *model, QString room);
    void initializeActivityList();

    QStringList getSchoolData(QString data);

    void setDataFile(QString dataFile);
    QString getDataFile();
    QStringList getRoomsList();
    QStringList getClassesList();
    QStringList getGroupsList();
    QStringList getTeachersList();

private:
    QStringList roomsList;
    QStringList teachersList;
    QStringList groupsList;
    QStringList classesList;
    QMap<QString, Activity> map;

    QString dataFile = "/home/kj/projects/elka/EGUI/lab1/SchoolPlanner/resources/data.json";
    QJsonObject schoolData;
    QList<Activity> activityList;
};

#endif // SCHOOLDATA_H
