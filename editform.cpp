#include "editform.h"
#include "ui_editform.h"

EditForm::EditForm(SchoolData *schoolData, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditForm)
{
    ui->setupUi(this);
    this->schoolData = schoolData;
    initializeEditForm();
}

EditForm::~EditForm() {
    delete ui;
}

void EditForm::initializeEditForm() {
    ui->classes->addItems(schoolData->getClassesList());
    ui->groups->addItems(schoolData->getGroupsList());
    ui->teachers->addItems(schoolData->getTeachersList());

    QLabel *headersLabel = new QLabel(this);
    headersLabel->setText("Room:\n\nClass:\n\nTeacher:\n\nGroup:");

    ui->headers->addWidget(headersLabel);
}

void EditForm::setCurrentData(int column, int row, QString room, SchoolData *data) {
    QLabel *roomLabel = new QLabel(this);
    roomLabel->setText(room);
    ui->roomName->addWidget(roomLabel);

    this->schoolData = data;
    this->slot = row;
    this->day = data->DAY_TO_INT.key(column);
    this->room = room;

    Activity activity = schoolData->getSelectedData(room, slot, day);

    if (activity.getGroup().isNull() || activity.getGroup().isEmpty()) {
        ui->pushButton_3->setVisible(false);
    }
    ui->classes->setCurrentIndex(schoolData->getClassesList().indexOf(activity.getClass()));
    ui->groups->setCurrentIndex(schoolData->getGroupsList().indexOf(activity.getGroup()));
    ui->teachers->setCurrentIndex(schoolData->getTeachersList().indexOf(activity.getTeacher()));
}

// Save button
void EditForm::on_pushButton_clicked() {
    // save data.
    QString newClas = ui->classes->itemText(ui->classes->currentIndex());
    QString newGroup = ui->groups->itemText(ui->groups->currentIndex());
    QString newTeacher = ui->teachers->itemText(ui->teachers->currentIndex());

    schoolData->editData(slot, day, newClas, newGroup, newTeacher, room);
    EditForm::close();
}

// Cancel button.
void EditForm::on_pushButton_2_clicked() {
    EditForm::close();
}

// Unassign
void EditForm::on_pushButton_3_clicked() {
    schoolData->deleteData(room, slot, day);
    EditForm::close();
}
