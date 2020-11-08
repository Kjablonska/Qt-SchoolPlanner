#ifndef ROOM_H
#define ROOM_H

#include <QString>
#include <QMap>
#include <QList>
#include "activity.h"

class Room
{
public:
    Room();
    Room(QString roomName, QList<Activity> activities);
    ~Room();
    void setRoomActivities();
    void initializeActivitiesMap(QList<Activity> activities);
    QString getRoomName() { return roomName; }
    QMap<QString, Activity> getRoomActivtiesMap() { return roomActivity; }
    QList<Activity> getRoomActivities();
    Activity getValueByKey(QString key);

    void removeEntry(QString key);
    void checkIfSuchEntryExists(Activity activity);
    bool editEntry(QString newClas, QString newGroup, QString newTeacher, int slot, QString day);
    bool addEntry(QString group, QString clas, int slot, QString day, QString teacher);

    bool checkForOverlapingActivities(int slot, QString day, QString group);
    void removeOverlapingActivities(int slot, QString day, QString group);

    void removeAllActivitiesForGroup(QString groupName);
    void removeAllActivitiesForTeacher(QString teacherName);

private:
    QString roomName;
    QMap<QString, Activity> roomActivity;
};

#endif // ROOM_H
