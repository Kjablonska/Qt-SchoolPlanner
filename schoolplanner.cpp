#include "schoolplanner.h"
#include "ui_schoolplanner.h"

SchoolPlanner::SchoolPlanner(QWidget *parent) : QMainWindow(parent), ui(new Ui::SchoolPlanner) {
    ui->setupUi(this);
    model = new QStandardItemModel(10, 5, this);
    schoolData = new SchoolData();
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    fillSchedule();
}

SchoolPlanner::~SchoolPlanner() {
    delete ui;
    delete schoolData;
}

void SchoolPlanner::fillSchedule() {
    clearAllData();
    schoolData->initializeSchoolData(windowFilePath());
    ui->comboBox->clear();
    ui->comboBox->addItems(schoolData->getRoomsList());
    QString room = ui->comboBox->itemText(ui->comboBox->currentIndex());

    fillRoomData(room);
}

void SchoolPlanner::fillRoomData(QString room) {
    QList<Activity> activities = schoolData->getRoomData(room);
    foreach (const auto activity, activities) {
        QModelIndex index =
            model->index(activity.getSlot(), schoolData->DAY_TO_INT.value(activity.getDay()), QModelIndex());
        model->setData(index, activity.getGroup(), Qt::EditRole);
    }
}

void SchoolPlanner::saveData() {
    if (windowFilePath().isEmpty()) {
        saveDataAs();
        return;
    }
    schoolData->saveDataToFile(windowFilePath());
}

void SchoolPlanner::saveDataAs() {
    QString fileName = QFileDialog::getOpenFileName(this, "Select file.");
    QFile file(fileName);

    if (!file.open(QIODevice::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Can not save to file :" + file.errorString());
        return;
    }

    setWindowFilePath(fileName);
    file.close();
    schoolData->saveDataToFile(windowFilePath());
}

void SchoolPlanner::clearAllData() {
    model->clear();
    model->setHorizontalHeaderLabels(HORIZONTAL_LABELS);
    model->setVerticalHeaderLabels(VERTICAL_LABELS);
}

void SchoolPlanner::on_actionOpen_triggered() {
    QString fileName = QFileDialog::getOpenFileName(this, "Open file");
    QFile file(fileName);
    setWindowFilePath(fileName);

    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Can not open file :" + file.errorString());
        return;
    }

    file.close();
    fillSchedule();
}

void SchoolPlanner::on_comboBox_activated(const QString &arg1) { refreshData(arg1); }

void SchoolPlanner::on_tableView_doubleClicked(const QModelIndex &index) {
    if (ui->comboBox->itemText(ui->comboBox->currentIndex()).isEmpty()) {
        QMessageBox::warning(this, "Error", "No room selected");
        return;
    }

    EditForm editForm(schoolData);
    ui->comboBox->itemText(ui->comboBox->currentIndex());

    QString roomName = ui->comboBox->itemText(ui->comboBox->currentIndex());
    editForm.setCurrentData(index.column(), index.row(), roomName, schoolData);
    editForm.exec();
    refreshData(roomName);
}

void SchoolPlanner::on_actionSave_triggered() { saveData(); }

void SchoolPlanner::on_actionSave_As_triggered() { saveDataAs(); }

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

void SchoolPlanner::on_actionClasses_triggered() {
    EditDictionary editDictionary(schoolData, "class");
    editDictionary.exec();
    refreshData(ui->comboBox->itemText(ui->comboBox->currentIndex()));
}

void SchoolPlanner::refreshData(QString roomName) {
    clearAllData();
    fillRoomData(roomName);
}

void SchoolPlanner::on_actionNew_triggered() {
    if (!windowFilePath().isEmpty()) {
        int response = QMessageBox::warning(this, tr("New"), tr("Do you want to save changes?\n"),
                                            QMessageBox::Save | QMessageBox::Cancel, QMessageBox::Save);
        switch (response) {
        case QMessageBox::Save:
            saveData();
            // FALLTHROUGH
        case QMessageBox::Cancel:
            schoolData->clearAllData();
            refreshData(ui->comboBox->itemText(ui->comboBox->currentIndex()));
            ui->comboBox->clear();
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
        int response = QMessageBox::warning(this, tr("Close"), tr("Do you want to save changes?\n"),
                                            QMessageBox::Save | QMessageBox::Cancel, QMessageBox::Save);
        switch (response) {
        case QMessageBox::Save:
            saveData();
            break;
        case QMessageBox::Cancel:
            close();
            break;
        default:
            break;
        }
    }
}
