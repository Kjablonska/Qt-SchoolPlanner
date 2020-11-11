#ifndef SCHOOLDATA_H
#define SCHOOLDATA_H

#include "activity.h"
#include "room.h"
#include <QFile>
#include <QFileDialog>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMap>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QStringList>
#include <QTextStream>
#include <memory>

class SchoolData {

  public:
    QMap<QString, int> DAY_TO_INT = {{"Monday", 0}, {"Tuesday", 1}, {"Wednesday", 2}, {"Thursday", 3}, {"Friday", 4}};

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
    void addNewClass(QString className);
    void removeClass(QString className);
    void clearAllData();

    QStringList getRoomsList() const { return roomsList; }
    QStringList getClassesList() const { return classesList; }
    QStringList getGroupsList() const { return groupsList; }
    QStringList getTeachersList() const { return teachersList; }

  private:
    QStringList roomsList;
    QStringList classesList;
    QStringList groupsList;
    QStringList teachersList;

    QJsonObject schoolData;
    std::list<std::shared_ptr<Room>> roomsActivityList;

    bool checkEditedData(int slot, QString day, QString newGroup, QString newTeacher, QString roomName);
    void removeOvelapingData(int slot, QString day, QString newGroup, QString teacher, QString roomName);
    bool checkDataCorrectness();
    bool checkJsonActivities(QString room, QString group, QString clas, int slot, QString day, QString teacher);
};

#endif // SCHOOLDATA_H
