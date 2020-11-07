#ifndef EDITFORM_H
#define EDITFORM_H

#include <QDialog>

#include <QLayoutItem>
#include <QPushButton>

#include <QVariant>

#include <QLabel>
#include <QHBoxLayout>

#include "schooldata.h"

namespace Ui {
class EditForm;
}

class EditForm : public QDialog
{
    Q_OBJECT

public:
    EditForm(SchoolData *schoolData, QWidget *parent = 0);
    ~EditForm();

    void initializeEditForm();
    void setCurrentData(int column, int row, QString room, SchoolData *schoolData);

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::EditForm *ui;
    SchoolData *schoolData;

    int slot;
    QString day;
    QString room;
    QString group;
};

#endif // EDITFORM_H
