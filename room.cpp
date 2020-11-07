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

QList<Activity> Room::getRoomActivities() {
    return roomActivity.values();
}

Activity Room::getValueByKey(QString key) {
   return roomActivity.value(key);
}

void Room::removeEntry(QString key) {
    roomActivity.remove(key);
}

void Room::editEntry(QString newClas, QString newGroup, QString newTeacher, int slot, QString day) {
    QString key = QString::number(slot) + day;

    if (getValueByKey(key).getGroup().isEmpty()) {
        addEntry(newGroup, newClas, slot, day, newTeacher);
    } else {
        QMap<QString, Activity>::iterator iter = roomActivity.begin();

        for (iter = roomActivity.begin(); iter != roomActivity.end(); iter++) {
            if (iter.key() == key) {
                iter.value().setClass(newClas);
                iter.value().setGroup(newGroup);
                iter.value().setTeacher(newTeacher);
            }
        }
    }

}

void Room::addEntry(QString group, QString clas, int slot, QString day, QString teacher) {
    QString key = QString::number(slot) + day;
    Activity newActivity(roomName, group, clas, slot, day, teacher);
    roomActivity.insert(key, newActivity);
}

void Room::checkIfSuchEntryExists(Activity activity) {
    /*
    foreach (Activity activity, activities) {
        QString key = activity.getGroup() + activity.getSlot() + activity.getDay();
        Activity checkActivity = getByKey(key);

        if (!checkActivity.isEmpty())
            removeEntry(key);
    }
    */

}
