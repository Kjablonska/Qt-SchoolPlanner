#include "editform.h"
#include "ui_editform.h"

EditForm::EditForm(SchoolData *schoolData, QWidget *parent) : QDialog(parent), ui(new Ui::EditForm) {
    ui->setupUi(this);
    this->schoolData = schoolData;
    initializeEditForm();
}

EditForm::~EditForm() { delete ui; }

void EditForm::initializeEditForm() {
    ui->classes->addItems(schoolData->getClassesList());
    ui->groups->addItems(schoolData->getGroupsList());
    ui->teachers->addItems(schoolData->getTeachersList());
}

void EditForm::setCurrentData(int column, int row, QString room, SchoolData *data) {
    ui->roomNumber->setText(room);

    this->schoolData = data;
    this->slot = row;
    this->day = data->DAY_TO_INT.key(column);
    this->room = room;

    Activity activity = schoolData->getSelectedData(room, slot, day);

    if (activity.getGroup().isNull() || activity.getGroup().isEmpty()) {
        ui->unassignButton->setVisible(false);
    }
    ui->classes->setCurrentIndex(schoolData->getClassesList().indexOf(activity.getClass()));
    ui->groups->setCurrentIndex(schoolData->getGroupsList().indexOf(activity.getGroup()));
    ui->teachers->setCurrentIndex(schoolData->getTeachersList().indexOf(activity.getTeacher()));
}

bool EditForm::checkData(QString newClas, QString newGroup, QString newTeacher) {
    if (newGroup.isEmpty() || newClas.isEmpty() || newTeacher.isEmpty()) {
        QMessageBox msgBox;
        msgBox.setText("Warning");
        msgBox.setInformativeText("You must set all data.");
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
        return false;
    }
    return true;
}

void EditForm::on_saveButton_clicked() {
    QString newClas = ui->classes->itemText(ui->classes->currentIndex());
    QString newGroup = ui->groups->itemText(ui->groups->currentIndex());
    QString newTeacher = ui->teachers->itemText(ui->teachers->currentIndex());

    if (checkData(newClas, newGroup, newTeacher))
        schoolData->editData(slot, day, newClas, newGroup, newTeacher, room);

    EditForm::close();
}

void EditForm::on_cancelButton_clicked() { EditForm::close(); }

void EditForm::on_unassignButton_clicked() {
    schoolData->deleteData(room, slot, day);
    EditForm::close();
}
