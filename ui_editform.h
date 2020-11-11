/********************************************************************************
** Form generated from reading UI file 'editform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITFORM_H
#define UI_EDITFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_EditForm
{
public:
    QGridLayout *gridLayout;
    QLabel *Room;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_2;
    QPushButton *unassignButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *saveButton;
    QPushButton *cancelButton;
    QComboBox *classes;
    QComboBox *teachers;
    QComboBox *groups;
    QLabel *roomNumber;

    void setupUi(QDialog *EditForm)
    {
        if (EditForm->objectName().isEmpty())
            EditForm->setObjectName(QStringLiteral("EditForm"));
        EditForm->resize(345, 190);
        gridLayout = new QGridLayout(EditForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        Room = new QLabel(EditForm);
        Room->setObjectName(QStringLiteral("Room"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Room->sizePolicy().hasHeightForWidth());
        Room->setSizePolicy(sizePolicy);

        gridLayout->addWidget(Room, 0, 0, 1, 1);

        label = new QLabel(EditForm);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_3 = new QLabel(EditForm);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_2 = new QLabel(EditForm);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        unassignButton = new QPushButton(EditForm);
        unassignButton->setObjectName(QStringLiteral("unassignButton"));

        gridLayout->addWidget(unassignButton, 4, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(66, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 2, 1, 1);

        saveButton = new QPushButton(EditForm);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        gridLayout->addWidget(saveButton, 4, 3, 1, 1);

        cancelButton = new QPushButton(EditForm);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        gridLayout->addWidget(cancelButton, 4, 4, 1, 1);

        classes = new QComboBox(EditForm);
        classes->setObjectName(QStringLiteral("classes"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(classes->sizePolicy().hasHeightForWidth());
        classes->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(classes, 1, 2, 1, 3);

        teachers = new QComboBox(EditForm);
        teachers->setObjectName(QStringLiteral("teachers"));

        gridLayout->addWidget(teachers, 2, 2, 1, 3);

        groups = new QComboBox(EditForm);
        groups->setObjectName(QStringLiteral("groups"));

        gridLayout->addWidget(groups, 3, 2, 1, 3);

        roomNumber = new QLabel(EditForm);
        roomNumber->setObjectName(QStringLiteral("roomNumber"));

        gridLayout->addWidget(roomNumber, 0, 2, 1, 1);


        retranslateUi(EditForm);

        QMetaObject::connectSlotsByName(EditForm);
    } // setupUi

    void retranslateUi(QDialog *EditForm)
    {
        EditForm->setWindowTitle(QApplication::translate("EditForm", "Edit form", Q_NULLPTR));
        Room->setText(QApplication::translate("EditForm", "Room", Q_NULLPTR));
        label->setText(QApplication::translate("EditForm", "Class", Q_NULLPTR));
        label_3->setText(QApplication::translate("EditForm", "Teacher", Q_NULLPTR));
        label_2->setText(QApplication::translate("EditForm", "Group", Q_NULLPTR));
        unassignButton->setText(QApplication::translate("EditForm", "Unassign", Q_NULLPTR));
        saveButton->setText(QApplication::translate("EditForm", "Save", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("EditForm", "Cancel", Q_NULLPTR));
        roomNumber->setText(QApplication::translate("EditForm", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EditForm: public Ui_EditForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITFORM_H
