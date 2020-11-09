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

#include <memory>
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

    void initializeSchoolData(QString fileName);
    void initializeRoomsActivityList();
    void initializeDataFromFile();

    QStringList getSchoolData(QString data);
    QList<Activity> getRoomData(QString roomName);
    Activity getSelectedData(QString roomName, int slot, QString day);
    void saveDataToFile(QString fileName);
    QJsonArray activitiesToJson();
    void deleteData(QString roomName, int slot, QString day);
    void editData(int slot, QString day, QString newClas, QString newGroup, QString newTeacher, QString roomName);
    void addNewRoom(QString roomName);
    void removeRoom(QString roomName);
    void removeGroup(QString groupName);
    void addNewGroup(QString groupName);
    void removeTeacher(QString teacherName);
    void addNewTeacher(QString teacherName);
    void clearAllData();

    //void setDataFile(QString dataFile) { this->dataFile = dataFile; }
    //QString getDataFile() const { return dataFile; }
    QStringList getRoomsList() const { return roomsList; }
    QStringList getClassesList() const { return classesList; }
    QStringList getGroupsList() const { return groupsList; }
    QStringList getTeachersList() const { return teachersList; }

private:
    QStringList roomsList;
    QStringList classesList;
    QStringList groupsList;
    QStringList teachersList;

    //QString dataFile = "";
    QJsonObject schoolData;
    std::list<std::shared_ptr<Room>> roomsActivityList;

    bool checkEditedData(int slot, QString day, QString newGroup, QString roomName);
    void removeOvelapingData(int slot, QString day, QString newGroup, QString roomName);
    bool checkDataCorrectness();
};

#endif // SCHOOLDATA_H
