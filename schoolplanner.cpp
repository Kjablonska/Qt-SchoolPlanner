#include "schoolplanner.h"
#include "ui_schoolplanner.h"

SchoolPlanner::SchoolPlanner(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SchoolPlanner) {
    ui->setupUi(this);
    model = new QStandardItemModel(10,5,this);
    ui->textEdit->setReadOnly(true);

    ui->tableView->setModel(model);
    fillSchedules();
}

SchoolPlanner::~SchoolPlanner() {
    delete ui;
}

// Change.
void SchoolPlanner::fillSchedules() {
    clearAllData();
    ui->comboBox->clear();
    schoolData.initializeRoomsWithData(model);
    ui->comboBox->addItems(schoolData.getRoomsList());
}

void SchoolPlanner::on_actionOpen_triggered() {
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(fileName);
    schoolData.setDataFile(fileName);

    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Can not open file :" + file.errorString());
        return;
    }

    file.close();
    schoolData.initializeSchoolData();
    fillSchedules();
}

void SchoolPlanner::on_comboBox_activated(const QString &arg1) {
    clearAllData();
    schoolData.setRoomData(model, arg1);
}

void SchoolPlanner::clearAllData() {
    model->clear();
    model->setHorizontalHeaderLabels(HORIZONTAL_LABELS);
    model->setVerticalHeaderLabels(VERTICAL_LABELS);
}

void SchoolPlanner::on_tableView_doubleClicked(const QModelIndex &index) {
    EditForm editForm;
    editForm.exec();
}
