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
    initializeActivityList();
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

void SchoolData::setRoomData(QStandardItemModel *model, QString room) {
    if (activityList.isEmpty())
        return;

    for (int i = 0; i < activityList.size(); i++) {
        if (activityList[i].getRoom() == room) {
            QModelIndex index = model->index(activityList[i].getSlot(), 1, QModelIndex());
            model->setData(index, activityList[i].getGroup(), Qt::EditRole);
        }
    }
}

void SchoolData::initializeActivityList() {
    QJsonValue activitiesValues = schoolData.value("activities");
    QJsonArray activitiesJsonArray = activitiesValues.toArray();

    for (int i = 0; i < activitiesJsonArray.size(); i++) {
        QString room = activitiesJsonArray[i].toObject().value("room").toString();
        QString group = activitiesJsonArray[i].toObject().value("group").toString();
        QString clas = activitiesJsonArray[i].toObject().value("class").toString();
        int slot = activitiesJsonArray[i].toObject().value("slot").toInt();
        QString day = activitiesJsonArray[i].toObject().value("day").toString();
        QString teacher = activitiesJsonArray[i].toObject().value("teacher").toString();

        Activity activity(room, group, clas, slot, day, teacher);
        activityList.append(activity);
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
