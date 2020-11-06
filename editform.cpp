#include "editform.h"
#include "ui_editform.h"

EditForm::EditForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditForm)
{
    ui->setupUi(this);

    initializeEditForm();
}

EditForm::~EditForm() {
    delete ui;
}

void EditForm::initializeEditForm() {
    ui->classes->addItems(schoolData.getClassesList());
    ui->groups->addItems(schoolData.getGroupsList());
    ui->teachers->addItems(schoolData.getTeachersList());

    QLabel *headersLabel = new QLabel(this);
    headersLabel->setText("Room:\n\nClass:\n\nTeacher:\n\nGroup:");

    ui->headers->addWidget(headersLabel);
}

void EditForm::setCurrentData(int column, int row, QString group, QString room) {
    QLabel *roomLabel = new QLabel(this);
    roomLabel->setText(room);
    ui->roomName->addWidget(roomLabel);

    activity = schoolData.getSelectedData(room, group, row, column);
    ui->classes->setCurrentIndex(schoolData.getClassesList().indexOf(activity.getClass()));
    ui->groups->setCurrentIndex(schoolData.getGroupsList().indexOf(activity.getGroup()));
    ui->teachers->setCurrentIndex(schoolData.getTeachersList().indexOf(activity.getTeacher()));
}

// Save button
void EditForm::on_pushButton_clicked() {
    // save data.
    QString clas = ui->classes->itemText(ui->classes->currentIndex());
    QString group = ui->groups->itemText(ui->groups->currentIndex());
    QString teacher = ui->teachers->itemText(ui->teachers->currentIndex());

    //activityList.findByRoomAndPossition();

    EditForm::close();
}

// Cancel button.
void EditForm::on_pushButton_2_clicked() {
    EditForm::close();
}




void EditForm::on_pushButton_3_clicked()
{
    schoolData.deleteData(activity);
    EditForm::close();
}
