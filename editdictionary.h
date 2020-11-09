#ifndef EDITDICTIONARY_H
#define EDITDICTIONARY_H

#include <QDialog>
#include "schooldata.h"

namespace Ui {
class EditDictionary;
}

class EditDictionary : public QDialog
{
    Q_OBJECT

public:
    explicit EditDictionary(SchoolData *schoolData, QString dictionary, QWidget *parent = 0);
    ~EditDictionary();
    void initializeDictionary(SchoolData *schoolData, QString dictionary);

private slots:
    void on_closeButton_clicked();
    void on_addButton_clicked();
    void on_removeButton_clicked();

private:
    Ui::EditDictionary *ui;
    SchoolData *schoolData;
    QString dictionary;
};

#endif // EDITDICTIONARY_H
