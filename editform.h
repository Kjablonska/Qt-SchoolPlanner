#ifndef EDITFORM_H
#define EDITFORM_H

#include <QDialog>
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

private:
    Ui::EditForm *ui;
    SchoolData schoolData;
};

#endif // EDITFORM_H
