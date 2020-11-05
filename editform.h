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
    explicit EditForm(QWidget *parent = 0);
    ~EditForm();

    void initializeEditForm();
    void setCurrentData(int column, int row, QString room);

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::EditForm *ui;
    SchoolData schoolData;
    int column, row;
};

#endif // EDITFORM_H
