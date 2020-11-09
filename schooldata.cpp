#include "schooldata.h"

SchoolData::SchoolData() {
    //initializeSchoolData();
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

                if (room.isEmpty() || group.isEmpty() || clas.isEmpty() || (slot < 0 || slot > 9) || day.isEmpty() || teacher.isEmpty()) {
                    QMessageBox msgBox;
                    msgBox.setText("Incorrect data");
                    msgBox.setInformativeText("One of 'activities' data is incorrect.\nDo you want to skip it?");
                    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
                    msgBox.setDefaultButton(QMessageBox::Yes);
                    int ret = msgBox.exec();

                    switch (ret) {
                        case QMessageBox::No: {
                            Activity activity = Activity(room, group, clas, slot, day, teacher);
                            roomActivities.append(activity);
                            break;
                        }
                        case QMessageBox::Yes:
                        default:
                            break;
                    }

                } else {
                    Activity activity = Activity(room, group, clas, slot, day, teacher);
                    roomActivities.append(activity);
                }
            }
        }

        std::shared_ptr<Room> newRoom(new Room(roomsList[j], roomActivities));
        roomsActivityList.push_back(newRoom);
        //roomsActivityList.append(newRoom);
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
    foreach (auto &&room, roomsActivityList) {
        if (room->getRoomName() == roomName)
            return room->getRoomActivities();
    }

    return QList<Activity>();
}

Activity SchoolData::getSelectedData(QString roomName, int slot, QString day) {
    foreach (auto &&room, roomsActivityList) {
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
    foreach (auto &&room, roomsActivityList)
        foreach (const Activity activity, room->getRoomActivities())
            activitiesList.append(activity);

    QJsonArray activitiesArray;
    foreach (Activity activity, activitiesList) {
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
    foreach (auto &&room, roomsActivityList) {
        if (room->getRoomName() == roomName) {
            QString key = QString::number(slot) + day;
            return room->removeEntry(key);
        }
    }
}

void SchoolData::editData(int slot, QString day, QString newClas, QString newGroup, QString newTeacher, QString roomName) {
    if (checkEditedData(slot, day, newGroup, roomName)) {
        QMessageBox msgBox;
        //msgBox.setText("Selected group has classes in different rooms at this time. If you proceed, those data will be deleted.\n");
        //msgBox.setInformativeText("Do you want to proceed?");
        //msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        //msgBox.setDefaultButton(QMessageBox::No);
        //int ret = msgBox.exec();

       // if (!warning.getAcceptance())
       //     return;
    }

    bool edited = false;
    foreach (auto &&room, roomsActivityList) {
        if (room->getRoomName() == roomName) {
            edited = room->editEntry(newClas, newGroup, newTeacher, slot, day);
            break;
        }
    }

    if (edited)
        removeOvelapingData(slot, day, newGroup, roomName);
}


void SchoolData::addNewRoom(QString roomName) {
    roomsList.append(roomName);
}

void SchoolData::removeRoom(QString roomName) {
    roomsList.removeOne(roomName);

    foreach(auto &&room, roomsActivityList) {
        if (room->getRoomName() == roomName) {
            //roomsActivityList.removeOne(room);
            roomsActivityList.remove(room);
            break;
        }
    }
}

void SchoolData::addNewGroup(QString groupName) {
    groupsList.append(groupName);
}

void SchoolData::removeGroup(QString groupName) {
    groupsList.removeOne(groupName);

    foreach(auto &&room, roomsActivityList)
        room->removeAllActivitiesForGroup(groupName);
}

void SchoolData::addNewTeacher(QString teacherName) {
    teachersList.append(teacherName);
}

void SchoolData::removeTeacher(QString teacherName) {
    teachersList.removeOne(teacherName);

    foreach(auto &&room, roomsActivityList)
        room->removeAllActivitiesForTeacher(teacherName);
}

void SchoolData::clearAllData() {
    roomsList.clear();
    classesList.clear();
    teachersList.clear();

    roomsActivityList.clear();
}

bool SchoolData::checkEditedData(int slot, QString day, QString newGroup, QString roomName) {
    foreach (auto &&room, roomsActivityList) {
        if (room->getRoomName() != roomName)
            return room->checkForOverlapingActivities(slot, day, newGroup);
    }

    return false;
}

void SchoolData::removeOvelapingData(int slot, QString day, QString newGroup, QString roomName) {
    foreach (auto &&room, roomsActivityList) {
        if (room->getRoomName() != roomName)
            room->removeOverlapingActivities(slot, day, newGroup);
    }
}

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
