#include "editdictionary.h"
#include "ui_editdictionary.h"

EditDictionary::EditDictionary(SchoolData *schoolData, QString dictionary, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDictionary)
{
    ui->setupUi(this);
    initializeDictionary(schoolData, dictionary);
}

EditDictionary::~EditDictionary()
{
    delete ui;
}

void EditDictionary::initializeDictionary(SchoolData *schoolData, QString dictionary) {
    this->schoolData = schoolData;
    if (dictionary == "room")
        ui->listWidget->addItems(schoolData->getRoomsList());

}
