#include "editdictionary.h"
#include "ui_editdictionary.h"

EditDictionary::EditDictionary(SchoolData *schoolData, QString dictionary, QWidget *parent)
    : QDialog(parent), ui(new Ui::EditDictionary) {
    ui->setupUi(this);
    initializeDictionary(schoolData, dictionary);
}

EditDictionary::~EditDictionary() { delete ui; }

void EditDictionary::initializeDictionary(SchoolData *schoolData, QString dictionary) {
    ui->listWidget->clear();
    this->schoolData = schoolData;
    this->dictionary = dictionary;

    ui->removeButton->setVisible(true);
    if (dictionary == "room") {
        if (schoolData->getRoomsList().isEmpty())
            ui->removeButton->setVisible(false);
        else
            ui->listWidget->addItems(schoolData->getRoomsList());
    } else if (dictionary == "group") {
        if (schoolData->getGroupsList().isEmpty())
            ui->removeButton->setVisible(false);
        else
            ui->listWidget->addItems(schoolData->getGroupsList());
    } else if (dictionary == "teacher") {
        if (schoolData->getTeachersList().isEmpty())
            ui->removeButton->setVisible(false);
        else
            ui->listWidget->addItems(schoolData->getTeachersList());
    }

    QListWidgetItem *item = new QListWidgetItem("");
    item->setFlags(item->flags() | Qt::ItemIsEditable);
    ui->listWidget->addItem(item);
}

void EditDictionary::on_closeButton_clicked() { EditDictionary::close(); }

void EditDictionary::on_addButton_clicked() {
    QListWidgetItem *toAddItem = ui->listWidget->takeItem(ui->listWidget->currentRow());
    QString toAdd = toAddItem->text();

    if (dictionary == "room")
        schoolData->addNewRoom(toAdd);
    else if (dictionary == "group")
        schoolData->addNewGroup(toAdd);
    else if (dictionary == "teacher")
        schoolData->addNewTeacher(toAdd);

    initializeDictionary(schoolData, dictionary);
}

void EditDictionary::on_removeButton_clicked() {
    QMessageBox msgBox;
    msgBox.setText("All data connected to the selected entry will be removed.");
    msgBox.setInformativeText("Do you want to proceed?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);
    int ret = msgBox.exec();

    switch (ret) {
    case QMessageBox::Yes: {
        QListWidgetItem *toRemoveItem = ui->listWidget->takeItem(ui->listWidget->currentRow());
        QString toRemove = toRemoveItem->text();

        if (dictionary == "room")
            schoolData->removeRoom(toRemove);
        else if (dictionary == "group")
            schoolData->removeGroup(toRemove);
        else if (dictionary == "teacher")
            schoolData->removeTeacher(toRemove);
        break;
    }
    case QMessageBox::No:
    default:
        break;
    }
}
