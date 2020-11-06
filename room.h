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
    Activity getByKey(QString key);
    void removeEntry(QString key);

private:
    QString roomName;
    QMap<QString, Activity> roomActivity;
};

#endif // ROOM_H
