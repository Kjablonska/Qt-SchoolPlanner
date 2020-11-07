#include "schoolplanner.h"
#include "ui_schoolplanner.h"

SchoolPlanner::SchoolPlanner(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SchoolPlanner) {
    ui->setupUi(this);
    model = new QStandardItemModel(10,5,this);

    QLabel *roomLabel = new QLabel(this);
    roomLabel->setText("Room");
    ui->verticalLayout->addWidget(roomLabel);

    schoolData = new SchoolData();
    ui->tableView->setModel(model);
    fillSchedule();
}

SchoolPlanner::~SchoolPlanner() {
    delete ui;
}

void SchoolPlanner::fillSchedule() {
    clearAllData();
    ui->comboBox->clear();
    ui->comboBox->addItems(schoolData->getRoomsList());
    QString room = ui->comboBox->itemText(ui->comboBox->currentIndex());

    fillRoomData(room);
}

void SchoolPlanner::fillRoomData(QString room) {
    QList<Activity> activities = schoolData->getRoomData(room);
    foreach (Activity activity, activities) {
        QModelIndex index = model->index(activity.getSlot(), schoolData->DAY_TO_INT.value(activity.getDay()), QModelIndex());
        model->setData(index, activity.getGroup(), Qt::EditRole);
    }
}

void SchoolPlanner::on_actionOpen_triggered() {
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(fileName);
    schoolData->setDataFile(fileName);

    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Can not open file :" + file.errorString());
        return;
    }

    file.close();
    schoolData->initializeSchoolData();
    fillSchedule();
}

void SchoolPlanner::on_comboBox_activated(const QString &arg1) {
    clearAllData();
    fillRoomData(arg1);
}

void SchoolPlanner::clearAllData() {
    model->clear();
    model->setHorizontalHeaderLabels(HORIZONTAL_LABELS);
    model->setVerticalHeaderLabels(VERTICAL_LABELS);
}

void SchoolPlanner::on_tableView_doubleClicked(const QModelIndex &index) {
    EditForm editForm(schoolData);
    ui->comboBox->itemText(ui->comboBox->currentIndex());

    QString roomName = ui->comboBox->itemText(ui->comboBox->currentIndex());
    editForm.setCurrentData(index.column(), index.row(), roomName, schoolData);
    editForm.exec();
    clearAllData();
    fillRoomData(roomName);
}

void SchoolPlanner::on_actionSave_As_triggered() {
    // Ask user where to save.
}

void SchoolPlanner::on_actionSave_triggered() {
    schoolData->saveDataToFile();
}

void SchoolPlanner::on_actionEdit_rooms_list_triggered() {

}
