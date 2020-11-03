#include "schoolplanner.h"
#include "ui_schoolplanner.h"

SchoolPlanner::SchoolPlanner(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SchoolPlanner)
{
    ui->setupUi(this);
    model = new QStandardItemModel(10,5,this);
    ui->tableView->setModel(model);
    model->setHorizontalHeaderLabels(HORIZONTAL_LABELS);
    model->setVerticalHeaderLabels(VERTICAL_LABELS);
    initializeJsonDocument();
    setAvailableRooms();
    fillSchedules();
}

SchoolPlanner::~SchoolPlanner()
{
    delete ui;
}

void SchoolPlanner::initializeJsonDocument() {
    if (dataFileJson.isEmpty())
        return;

    QFile file;
    file.setFileName(dataFileJson);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QString fileData = file.readAll();
    file.close();

    jsonDocument = QJsonDocument::fromJson(fileData.toUtf8());
}

void SchoolPlanner::setAvailableRooms()
{
    // Clear Rooms first.
    ui->comboBox->clear();

    if (jsonDocument.isNull())
        return;

    QJsonObject jsonObject = jsonDocument.object();
    QJsonValue roomsValue = jsonObject.value("rooms");
    QJsonArray roomsJsonArray = roomsValue.toArray();

    for (int i = 0; i < roomsJsonArray.size(); i++) {
        roomsList.append(roomsJsonArray[i].toString());
    }

    ui->comboBox->addItems(roomsList);
}


void SchoolPlanner::fillSchedules() {
    if (roomsList.isEmpty())
        return;

    for (QString room : roomsList) {
        initializeRoom(room);
    }
}

void SchoolPlanner::initializeRoom(QString room) {
    QJsonObject jsonObject = jsonDocument.object();
    QJsonValue activitiesValues = jsonObject.value("activities");
    QJsonArray activitiesJsonArray = activitiesValues.toArray();
    QStringList roomActivities;

    for (int i = 0; i < activitiesJsonArray.size(); i++) {
        QJsonValue activity = activitiesJsonArray[i].toObject().value("room").toString();
        if (activitiesJsonArray[i].toObject().value("room").toString() == room) {
            QString group = activitiesJsonArray[i].toObject().value("group").toString();
            QString clas = activitiesJsonArray[i].toObject().value("class").toString();
            QString slot = activitiesJsonArray[i].toObject().value("slot").toString();
            //QString day = activitiesJsonArray[i].toObject().value("day").toString();
            QString teacher = activitiesJsonArray[i].toObject().value("teacher").toString();

            QModelIndex index = model->index(slot.toInt(), 1, QModelIndex());
            model->setData(index, group, Qt::EditRole);
        }
    }

    roomActivities;
}




/**********************************************************************/

void SchoolPlanner::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(fileName);
    dataFileJson = fileName;

    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Can not open file :" + file.errorString());
        return;
    }

    file.close();
    initializeJsonDocument();
    setAvailableRooms();
    fillSchedules();
}
