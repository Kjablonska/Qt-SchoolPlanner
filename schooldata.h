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

#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

#include "activity.h"
#include "room.h"

#include <QMap>

class SchoolData
{
public:

    QMap<QString, int> DAY_TO_INT = {
        { "Monday", 0},
        { "Tuesday", 1},
        { "Wednesday", 2},
        { "Thursday", 3},
        { "Friday", 4}
    };


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
    Activity getSelectedData(QString roomName, int slot, QString day);

    void setDataFile(QString dataFile);
    void deleteData(QString roomName, int slot, QString day);
    QString getDataFile();

    void saveDataToFile();

    void editData(int slot, QString day, QString newClas, QString newGroup, QString newTeacher, QString roomName);

    QJsonValue getActivitiesFromAllRooms();

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
    QList<Room*> roomsActivityList;
};

#endif // SCHOOLDATA_H
