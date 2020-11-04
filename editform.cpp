#include "editform.h"
#include "ui_editform.h"

#include <QLayoutItem>
#include <QPushButton>

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
    ui->comboBox->addItems(schoolData.getClassesList());
    ui->comboBox_2->addItems(schoolData.getGroupsList());
    ui->comboBox_3->addItems(schoolData.getTeachersList());
}

