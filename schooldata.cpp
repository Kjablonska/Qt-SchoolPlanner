#include "schooldata.h"

SchoolData::SchoolData() {
    // initializeSchoolData();
}

SchoolData::~SchoolData() {}

void SchoolData::initializeSchoolData(QString fileName) {
    if (fileName.isEmpty())
        return;

    QFile file;
    file.setFileName(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QString fileData = file.readAll();
    file.close();
    QJsonDocument jsonDocument = QJsonDocument::fromJson(fileData.toUtf8());
    schoolData = jsonDocument.object();
    initializeDataFromFile();
}

// Takes from JSON file activities arrays, save them as Activity object and add into corresponding Room.
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
                int slot = activitiesJsonArray[i].toObject().value("slot").toInt();
                QString day = activitiesJsonArray[i].toObject().value("day").toString();
                QString teacher = activitiesJsonArray[i].toObject().value("teacher").toString();

                if (checkJsonActivities(room, group, clas, slot, day, teacher)) {
                    Activity activity = Activity(room, group, clas, slot, day, teacher);
                    roomActivities.append(activity);
                }
            }
        }

        std::shared_ptr<Room> newRoom(new Room(roomsList[j], roomActivities));
        roomsActivityList.push_back(newRoom);
        roomActivities.clear();
    }
}

void SchoolData::initializeDataFromFile() {
    roomsList = getSchoolData("rooms");
    teachersList = getSchoolData("teachers");
    groupsList = getSchoolData("groups");
    classesList = getSchoolData("classes");

    if (checkDataCorrectness())
        initializeRoomsActivityList();
}

// Reads form JSON file "data" attributes and return them as a list.
QStringList SchoolData::getSchoolData(QString data) {
    if (schoolData.isEmpty())
        return QStringList();

    QJsonArray dataJsonArray = schoolData.value(data).toArray();
    QStringList dataList;

    foreach (const auto jsonData, dataJsonArray)
        dataList.append(jsonData.toString());

    return dataList;
}

QList<Activity> SchoolData::getRoomData(QString roomName) {
    foreach (const auto room, roomsActivityList) {
        if (room->getRoomName() == roomName)
            return room->getRoomActivities();
    }

    return QList<Activity>();
}

Activity SchoolData::getSelectedData(QString roomName, int slot, QString day) {
    foreach (const auto room, roomsActivityList) {
        if (room->getRoomName() == roomName) {
            QString key = QString::number(slot) + day;
            return room->getValueByKey(key);
        }
    }
    return Activity();
}

void SchoolData::saveDataToFile(QString fileName) {
    QFile file(fileName);

    if (!file.open(QIODevice::WriteOnly | QFile::Text))
        return;

    QJsonObject jsonData;
    jsonData.insert("rooms", QJsonValue(QJsonArray::fromStringList(roomsList)));
    jsonData.insert("classes", QJsonValue(QJsonArray::fromStringList(classesList)));
    jsonData.insert("groups", QJsonValue(QJsonArray::fromStringList(groupsList)));
    jsonData.insert("teachers", QJsonValue(QJsonArray::fromStringList(teachersList)));
    jsonData.insert("activities", QJsonValue(activitiesToJson()));

    QJsonDocument jsonDocument(jsonData);
    file.write(jsonDocument.toJson());
    file.close();
}

QJsonArray SchoolData::activitiesToJson() {
    QList<Activity> activitiesList;
    foreach (const auto room, roomsActivityList)
        foreach (const Activity activity, room->getRoomActivities())
            activitiesList.append(activity);

    QJsonArray activitiesArray;
    foreach (const auto activity, activitiesList) {
        QJsonObject jsonObject;
        jsonObject["room"] = activity.getRoom();
        jsonObject["group"] = activity.getGroup();
        jsonObject["class"] = activity.getClass();
        jsonObject["slot"] = activity.getSlot();
        jsonObject["day"] = activity.getDay();
        jsonObject["teacher"] = activity.getTeacher();
        activitiesArray.append(jsonObject);
    }

    return activitiesArray;
}

void SchoolData::deleteData(QString roomName, int slot, QString day) {
    foreach (const auto room, roomsActivityList) {
        if (room->getRoomName() == roomName) {
            QString key = QString::number(slot) + day;
            return room->removeEntry(key);
        }
    }
}

void SchoolData::editData(int slot, QString day, QString newClas, QString newGroup, QString newTeacher,
                          QString roomName) {
    if (checkEditedData(slot, day, newGroup, newTeacher, roomName)) {
        QMessageBox msgBox;
        msgBox.setText("Edit data");
        msgBox.setInformativeText(
            "Selected group or teaceher has class in different rooms at this time. If you proceed, those "
            "data will be deleted.\nDo you want to proceed?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        int response = msgBox.exec();

        switch (response) {
        case QMessageBox::No:
            return;
        case QMessageBox::Yes:
        default:
            break;
        }
    }

    foreach (const auto room, roomsActivityList) {
        if (room->getRoomName() == roomName) {
            room->editEntry(newClas, newGroup, newTeacher, slot, day);
            break;
        }
    }
    removeOvelapingData(slot, day, newGroup, newTeacher, roomName);
}

void SchoolData::addNewRoom(QString roomName) { roomsList.append(roomName); }

void SchoolData::removeRoom(QString roomName) {
    roomsList.removeOne(roomName);

    foreach (const auto room, roomsActivityList) {
        if (room->getRoomName() == roomName) {
            roomsActivityList.remove(room);
            break;
        }
    }
}

void SchoolData::addNewGroup(QString groupName) { groupsList.append(groupName); }

void SchoolData::removeGroup(QString groupName) {
    groupsList.removeOne(groupName);

    foreach (const auto room, roomsActivityList)
        room->removeAllActivitiesForGroup(groupName);
}

void SchoolData::addNewTeacher(QString teacherName) { teachersList.append(teacherName); }

void SchoolData::removeTeacher(QString teacherName) {
    teachersList.removeOne(teacherName);

    foreach (const auto room, roomsActivityList)
        room->removeAllActivitiesForTeacher(teacherName);
}

void SchoolData::clearAllData() {
    roomsList.clear();
    classesList.clear();
    teachersList.clear();

    roomsActivityList.clear();
}

bool SchoolData::checkEditedData(int slot, QString day, QString newGroup, QString newTeacher, QString roomName) {
    foreach (const auto room, roomsActivityList) {
        if (room->getRoomName() != roomName)
            return room->checkForOverlapingActivities(slot, day, newGroup, newTeacher);
    }

    return false;
}

// Same group can not have classes in different room at the same time.
// If any other entry interefere with newly added activity that entry should be
// removed.
void SchoolData::removeOvelapingData(int slot, QString day, QString newGroup, QString newTeacher, QString roomName) {
    foreach (const auto room, roomsActivityList) {
        if (room->getRoomName() != roomName)
            room->removeOverlapingActivities(slot, day, newGroup, newTeacher);
    }
}

// If in JSON data there are no rooms, groups, classes or teachers, data is
// assumed to be incorrect.
bool SchoolData::checkDataCorrectness() {
    if (roomsList.isEmpty() || groupsList.isEmpty() || classesList.isEmpty() || teachersList.isEmpty()) {
        QMessageBox msgBox;
        roomsList.clear();
        groupsList.clear();
        classesList.clear();
        teachersList.clear();
        return false;
    }
    return true;
}

// If in there is any attribute missing in activity, the user is asked if this entry should be ommited or added to
// timetable anyway.
bool SchoolData::checkJsonActivities(QString room, QString group, QString clas, int slot, QString day,
                                     QString teacher) {
    if (room.isEmpty() || group.isEmpty() || clas.isEmpty() || (slot < 0 || slot > 9) || day.isEmpty() ||
        teacher.isEmpty()) {
        QMessageBox msgBox;
        msgBox.setText("Incorrect data");
        msgBox.setInformativeText("One of 'activities' data is "
                                  "incorrect.\nDo you want to skip it?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::Yes);
        int ret = msgBox.exec();

        switch (ret) {
        case QMessageBox::No:
            return true;
        case QMessageBox::Yes:
        default:
            return false;
        }
    }

    return true;
}
