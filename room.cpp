#include "room.h"

Room::Room() {}

Room::Room(QString roomName, QList<Activity> activities) {
    this->roomName = roomName;
    initializeActivitiesMap(activities);
}

Room::~Room() {}

void Room::initializeActivitiesMap(QList<Activity> activities) {
    foreach (Activity activity, activities) {
        QString key = QString::number(activity.getSlot()) + activity.getDay();
        roomActivity.insert(key, activity);
    }
}

void Room::removeAllActivitiesForGroup(QString groupName) {
    QMap<QString, Activity>::iterator iter = roomActivity.begin();
    for (iter = roomActivity.begin(); iter != roomActivity.end(); iter++) {
        if (iter.value().getGroup() == groupName)
            removeEntry(iter.key());

        if (roomActivity.isEmpty())
            return;
    }
}

void Room::removeAllActivitiesForTeacher(QString teacherName) {
    QMap<QString, Activity>::iterator iter = roomActivity.begin();
    for (iter = roomActivity.begin(); iter != roomActivity.end(); iter++) {
        if (iter.value().getTeacher() == teacherName)
            removeEntry(iter.key());

        if (roomActivity.isEmpty())
            return;
    }
}

bool Room::checkForOverlapingActivities(int slot, QString day, QString group) {
    QString key = QString::number(slot) + day;

    if (getValueByKey(key).getGroup() == group)
        return true;

    return false;
}

void Room::removeOverlapingActivities(int slot, QString day, QString group) {
    QString key = QString::number(slot) + day;

    if (getValueByKey(key).getGroup() == group)
        removeEntry(key);
}

bool Room::editEntry(QString newClas, QString newGroup, QString newTeacher, int slot, QString day) {
    QString key = QString::number(slot) + day;

    if (getValueByKey(key).getGroup().isEmpty())
        return addEntry(newGroup, newClas, slot, day, newTeacher);

    QMap<QString, Activity>::iterator iter = roomActivity.begin();
    for (iter = roomActivity.begin(); iter != roomActivity.end(); iter++) {
        if (iter.key() == key) {
            iter.value().setClass(newClas);
            iter.value().setGroup(newGroup);
            iter.value().setTeacher(newTeacher);

            return true;
        }
    }

    return false;
}

bool Room::addEntry(QString group, QString clas, int slot, QString day, QString teacher) {
    QString key = QString::number(slot) + day;
    Activity newActivity(roomName, group, clas, slot, day, teacher);
    roomActivity.insert(key, newActivity);

    return true;
}

QList<Activity> Room::getRoomActivities() {
    return roomActivity.values();
}

Activity Room::getValueByKey(QString key) {
   return roomActivity.value(key);
}

void Room::removeEntry(QString key) {
    roomActivity.remove(key);
}
