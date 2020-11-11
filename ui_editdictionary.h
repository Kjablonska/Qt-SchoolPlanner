/********************************************************************************
** Form generated from reading UI file 'editdictionary.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITDICTIONARY_H
#define UI_EDITDICTIONARY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EditDictionary
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QHBoxLayout *buttonsLayout;
    QPushButton *addButton;
    QPushButton *removeButton;
    QPushButton *closeButton;

    void setupUi(QDialog *EditDictionary)
    {
        if (EditDictionary->objectName().isEmpty())
            EditDictionary->setObjectName(QStringLiteral("EditDictionary"));
        EditDictionary->resize(311, 258);
        verticalLayout = new QVBoxLayout(EditDictionary);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        listWidget = new QListWidget(EditDictionary);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget);

        buttonsLayout = new QHBoxLayout();
        buttonsLayout->setObjectName(QStringLiteral("buttonsLayout"));
        addButton = new QPushButton(EditDictionary);
        addButton->setObjectName(QStringLiteral("addButton"));

        buttonsLayout->addWidget(addButton);

        removeButton = new QPushButton(EditDictionary);
        removeButton->setObjectName(QStringLiteral("removeButton"));

        buttonsLayout->addWidget(removeButton);

        closeButton = new QPushButton(EditDictionary);
        closeButton->setObjectName(QStringLiteral("closeButton"));

        buttonsLayout->addWidget(closeButton);


        verticalLayout->addLayout(buttonsLayout);


        retranslateUi(EditDictionary);

        QMetaObject::connectSlotsByName(EditDictionary);
    } // setupUi

    void retranslateUi(QDialog *EditDictionary)
    {
        EditDictionary->setWindowTitle(QApplication::translate("EditDictionary", "Dialog", Q_NULLPTR));
        addButton->setText(QApplication::translate("EditDictionary", "Add", Q_NULLPTR));
        removeButton->setText(QApplication::translate("EditDictionary", "Remove", Q_NULLPTR));
        closeButton->setText(QApplication::translate("EditDictionary", "Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EditDictionary: public Ui_EditDictionary {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITDICTIONARY_H
