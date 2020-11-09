#include "schoolplanner.h"
#include "ui_schoolplanner.h"

SchoolPlanner::SchoolPlanner(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SchoolPlanner) {
    ui->setupUi(this);
    model = new QStandardItemModel(10,5,this);

    schoolData = new SchoolData();
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

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

    schoolData->initializeSchoolData(windowFilePath());
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
    QString fileName = QFileDialog::getOpenFileName(this, "Open file");
    QFile file(fileName);
    //schoolData->setDataFile(fileName);
    setWindowFilePath(fileName);

    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Can not open file :" + file.errorString());
        return;
    }

    file.close();
    schoolData->initializeSchoolData(windowFilePath());
    fillSchedule();
}

void SchoolPlanner::on_comboBox_activated(const QString &arg1) {
    refreshData(arg1);
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
    refreshData(roomName);
}

void SchoolPlanner::on_actionSave_As_triggered() {
    QString fileName = QFileDialog::getOpenFileName(this, "Select file.");
    QFile file(fileName);

    if (!file.open(QIODevice::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Can not save to file :" + file.errorString());
        return;
    }

    setWindowFilePath(fileName);
    //schoolData->setDataFile(fileName);
    file.close();
    schoolData->saveDataToFile(windowFilePath());
}

void SchoolPlanner::on_actionSave_triggered() {
    if (windowFilePath().isEmpty()) {
        on_actionSave_As_triggered();
    }
    schoolData->saveDataToFile(windowFilePath());
}

void SchoolPlanner::on_actionRooms_triggered() {
    EditDictionary editDictionary(schoolData, "room");
    editDictionary.exec();

    ui->comboBox->clear();
    ui->comboBox->addItems(schoolData->getRoomsList());
    refreshData(ui->comboBox->itemText(ui->comboBox->currentIndex()));
}

void SchoolPlanner::on_actionGroups_triggered() {
    EditDictionary editDictionary(schoolData, "group");
    editDictionary.exec();
    refreshData(ui->comboBox->itemText(ui->comboBox->currentIndex()));
}

void SchoolPlanner::on_actionTeachers_triggered() {
    EditDictionary editDictionary(schoolData, "teacher");
    editDictionary.exec();
    refreshData(ui->comboBox->itemText(ui->comboBox->currentIndex()));
}

void SchoolPlanner::refreshData(QString roomName) {
    clearAllData();
    fillRoomData(roomName);
}

void SchoolPlanner::on_actionDelete_all_data_triggered() {
    schoolData->clearAllData();
    refreshData(ui->comboBox->itemText(ui->comboBox->currentIndex()));
    ui->comboBox->clear();
}

void SchoolPlanner::on_actionNew_triggered() {

    if (windowFilePath().isEmpty()) {
        on_actionOpen_triggered();
    } else {
        int ret = QMessageBox::warning(this, tr("New"), tr("Do you want to save current changes?\n"), QMessageBox::Save | QMessageBox::Cancel, QMessageBox::Save);
        switch (ret) {
          case QMessageBox::Save:
              on_actionSave_As_triggered();
              on_actionOpen_triggered();
              break;
          case QMessageBox::Cancel:
              on_actionOpen_triggered();
              break;
          default:
              break;
        }
    }
}

void SchoolPlanner::on_actionExit_triggered() {
    if (windowFilePath().isEmpty()) {
        close();
    } else {
        int ret = QMessageBox::warning(this, tr("Close"), tr("Do you want to save current changes?\n"), QMessageBox::Save | QMessageBox::Cancel, QMessageBox::Save);
        switch (ret) {
          case QMessageBox::Save:
              on_actionSave_As_triggered();
              on_actionOpen_triggered();
              break;
          case QMessageBox::Cancel:
              on_actionOpen_triggered();
              break;
          default:
              break;
        }
    }
}
