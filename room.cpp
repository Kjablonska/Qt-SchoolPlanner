#include "room.h"

Room::Room() {}

Room::Room(QString roomName, QList<Activity> activities) {
    this->roomName = roomName;
    initializeActivitiesMap(activities);
}

Room::~Room() {}

void Room::initializeActivitiesMap(QList<Activity> activities) {
    foreach (Activity activity, activities) {
        QString key = activity.getGroup() + activity.getSlot() + activity.getDay();
        roomActivity.insert(key, activity);
    }
}

QList<Activity> Room::getRoomActivities() {
    return roomActivity.values();
}

Activity Room::getByKey(QString key) {
    Activity act = roomActivity.value(key);
   return act;
}

void Room::removeEntry(QString key) {
    roomActivity.remove(key);
    roomActivity;
}
