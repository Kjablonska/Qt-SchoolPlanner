#include "schooldata.h"

SchoolData::SchoolData() {
    initializeSchoolData();
}

SchoolData::~SchoolData() {}

void SchoolData::initializeSchoolData() {
    if (dataFile.isEmpty())
        return;

    QFile file;
    file.setFileName(dataFile);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QString fileData = file.readAll();
    file.close();

    QJsonDocument jsonDocument = QJsonDocument::fromJson(fileData.toUtf8());
    schoolData = jsonDocument.object();

    setAvailableRooms();
    setAvailableClasses();
    setAvailableGroups();
    setAvailableTeachers();
    initializeRoomsActivityList();
}

QStringList SchoolData::getSchoolData(QString data) {
    if (schoolData.isEmpty())
        return QStringList();

    QJsonArray dataJsonArray = schoolData.value(data).toArray();
    QStringList dataList;

    for (int i = 0; i < dataJsonArray.size(); i++) {
        dataList.append(dataJsonArray[i].toString());
    }

    return dataList;
}

QList<Activity> SchoolData::getRoomData(QString roomName) {
    foreach (Room room, roomsActivityList) {
        if (room.getRoomName() == roomName) {
            return room.getRoomActivities();
        }
    }

    return QList<Activity>();
}

Activity SchoolData::getSelectedData(QString roomName, QString group, int slot, int day) {
    foreach (Room room, roomsActivityList) {
        if (room.getRoomName() == roomName) {
            QString key = group+slot+day;
            return room.getByKey(key);
        }
    }
    Activity act;
    return act;
}

void SchoolData::initializeRoomsActivityList() {
    if (roomsList.empty())
        return;
    QJsonValue activitiesValues = schoolData.value("activities");
    QJsonArray activitiesJsonArray = activitiesValues.toArray();

    QList<Activity> roomActivities;
    for (int j = 0; j < roomsList.size(); j++) {
        for (int i = 0; i < activitiesJsonArray.size(); i++) {
            QString room = activitiesJsonArray[i].toObject().value("room").toString();
            if (room == roomsList[j]) {
                QString room = activitiesJsonArray[i].toObject().value("room").toString();
                QString group = activitiesJsonArray[i].toObject().value("group").toString();
                QString clas = activitiesJsonArray[i].toObject().value("class").toString();
                QString slot = activitiesJsonArray[i].toObject().value("slot").toString();
                QString day = activitiesJsonArray[i].toObject().value("day").toString();
                QString teacher = activitiesJsonArray[i].toObject().value("teacher").toString();

                Activity activity(room, group, clas, slot.toInt(), 1, teacher);
                roomActivities.append(activity);
            }
        }
        roomsActivityList.append(Room(roomsList[j], roomActivities));
        roomActivities.clear();
    }
}

void SchoolData::deleteData(Activity activity) {
    foreach (Room room, roomsActivityList) {
        if (room.getRoomName() == activity.getRoom()) {
            QString key = activity.getGroup()+activity.getSlot()+activity.getDay();
            return room.removeEntry(key);
        }
    }
}

void SchoolData::setAvailableRooms() {
    roomsList = getSchoolData("rooms");

}

void SchoolData::setAvailableTeachers() {
    teachersList = getSchoolData("teachers");
}

void SchoolData::setAvailableGroups() {
    groupsList = getSchoolData("groups");
}

void SchoolData::setAvailableClasses() {
    classesList = getSchoolData("classes");
}

void SchoolData::setDataFile(QString dataFile) {
    this->dataFile = dataFile;
}

QString SchoolData::getDataFile() {
    return dataFile;
}

QStringList SchoolData::getRoomsList() {
    return roomsList;
}

QStringList SchoolData::getClassesList() {
    return classesList;
}

QStringList SchoolData::getGroupsList() {
    return groupsList;
}

QStringList SchoolData::getTeachersList() {
    return teachersList;
}
