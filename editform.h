#ifndef EDITFORM_H
#define EDITFORM_H

#include "schooldata.h"
#include <QDialog>
#include <QHBoxLayout>

namespace Ui {
class EditForm;
}

class EditForm : public QDialog {
    Q_OBJECT

  public:
    EditForm(SchoolData *schoolData, QWidget *parent = 0);
    ~EditForm();

    void initializeEditForm();
    void setCurrentData(int column, int row, QString room, SchoolData *schoolData);
    bool checkData(QString newClas, QString newGroup, QString newTeacher);

  private slots:
    void on_saveButton_clicked();
    void on_cancelButton_clicked();
    void on_unassignButton_clicked();

  private:
    Ui::EditForm *ui;
    SchoolData *schoolData;

    int slot;
    QString day;
    QString room;
    QString group;
};

#endif // EDITFORM_H
