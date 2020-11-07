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
    foreach (Room *room, roomsActivityList) {
        if (room->getRoomName() == roomName) {
            return room->getRoomActivities();
        }
    }

    return QList<Activity>();
}

Activity SchoolData::getSelectedData(QString roomName, int slot, QString day) {
    foreach (Room *room, roomsActivityList) {
        if (room->getRoomName() == roomName) {
            QString key = QString::number(slot) + day;
            return room->getValueByKey(key);
        }
    }
    return Activity();
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
                int slot = activitiesJsonArray[i].toObject().value("slot").toInt() - 1;
                QString day = activitiesJsonArray[i].toObject().value("day").toString();
                QString teacher = activitiesJsonArray[i].toObject().value("teacher").toString();

                Activity activity = Activity(room, group, clas, slot, day, teacher);
                roomActivities.append(activity);
            }
        }
        Room *newRoom = new Room(roomsList[j], roomActivities);
        roomsActivityList.append(newRoom);
        roomActivities.clear();
    }
}

void SchoolData::deleteData(QString roomName, int slot, QString day) {
    foreach (Room* room, roomsActivityList) {
        if (room->getRoomName() == roomName) {
            QString key = QString::number(slot) + day;
            return room->removeEntry(key);
        }
    }
}

void SchoolData::editData(int slot, QString day, QString newClas, QString newGroup, QString newTeacher, QString roomName) {
    foreach (Room* room, roomsActivityList) {
        if (room->getRoomName() == roomName) {
            return room->editEntry(newClas, newGroup, newTeacher, slot, day);
        }
    }
}

void SchoolData::saveDataToFile() {
    QFile file(dataFile);

    if (!file.open(QIODevice::WriteOnly | QFile::Text))
        return;

    QJsonObject jsonData;
    jsonData.insert("rooms", QJsonValue(QJsonArray::fromStringList(roomsList)));
    jsonData.insert("classes", QJsonValue(QJsonArray::fromStringList(classesList)));
    jsonData.insert("groups", QJsonValue(QJsonArray::fromStringList(groupsList)));
    jsonData.insert("teachers", QJsonValue(QJsonArray::fromStringList(teachersList)));


    QList<Activity> act;
    foreach (Room * room, roomsActivityList) {
        foreach (Activity a, room->getRoomActivities())
            act.append(a);
    }


    QJsonArray array;

    foreach (Activity a, act) {
        QJsonObject obj;

        obj["room"] = a.getRoom();
        obj["group"] = a.getGroup();
        array.append(obj);
    }
    jsonData.insert("activities", QJsonValue(array));

    QJsonDocument jsonDocument(jsonData);
    file.write(jsonDocument.toJson());
    file.close();
}


/***********************************************************/

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
