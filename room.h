#ifndef ROOM_H
#define ROOM_H

#include "activity.h"
#include <QMap>

class Room {
  public:
    Room();
    Room(QString roomName, QList<Activity> activities);
    ~Room();

    void initializeActivitiesMap(QList<Activity> activities);
    void removeAllActivitiesForGroup(QString groupName);
    void removeAllActivitiesForTeacher(QString teacherName);
    bool checkForOverlapingActivities(int slot, QString day, QString group, QString teacher);
    void removeOverlapingActivities(int slot, QString day, QString group, QString teacher);
    bool editEntry(QString newClas, QString newGroup, QString newTeacher, int slot, QString day);
    bool addEntry(QString group, QString clas, int slot, QString day, QString teacher);
    QList<Activity> getRoomActivities();
    Activity getValueByKey(QString key);
    void removeEntry(QString key);

    QString getRoomName() const { return roomName; }
    QMap<QString, Activity> getRoomActivtiesMap() const { return roomActivity; }

  private:
    QString roomName;
    QMap<QString, Activity> roomActivity;
};

#endif // ROOM_H
