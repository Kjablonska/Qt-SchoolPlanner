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
#include "room.h"

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
    void initializeActivityList();
    QList<Activity> getRoomData(QString roomName);

    void initializeRoomsActivityList();

    QStringList getSchoolData(QString data);
    Activity getSelectedData(QString roomName, QString group, int slot, int day);

    void setDataFile(QString dataFile);
    void deleteData(Activity activity);
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

    QString dataFile = "/home/kj/projects/elka/EGUI/lab1/SchoolPlanner/resources/data.json";
    QJsonObject schoolData;

    QList<Room> roomsActivityList;
};

#endif // SCHOOLDATA_H
