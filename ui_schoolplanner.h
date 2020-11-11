/********************************************************************************
** Form generated from reading UI file 'schoolplanner.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCHOOLPLANNER_H
#define UI_SCHOOLPLANNER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SchoolPlanner
{
public:
    QAction *actionOpen;
    QAction *actionSave_As;
    QAction *actionSave;
    QAction *actionRooms;
    QAction *actionGroups;
    QAction *actionTeachers;
    QAction *actionNew;
    QAction *actionExit;
    QAction *actionClasses;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer;
    QTableView *tableView;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *SchoolPlanner)
    {
        if (SchoolPlanner->objectName().isEmpty())
            SchoolPlanner->setObjectName(QStringLiteral("SchoolPlanner"));
        SchoolPlanner->resize(659, 466);
        actionOpen = new QAction(SchoolPlanner);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave_As = new QAction(SchoolPlanner);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        actionSave = new QAction(SchoolPlanner);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionRooms = new QAction(SchoolPlanner);
        actionRooms->setObjectName(QStringLiteral("actionRooms"));
        actionGroups = new QAction(SchoolPlanner);
        actionGroups->setObjectName(QStringLiteral("actionGroups"));
        actionTeachers = new QAction(SchoolPlanner);
        actionTeachers->setObjectName(QStringLiteral("actionTeachers"));
        actionNew = new QAction(SchoolPlanner);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionExit = new QAction(SchoolPlanner);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionClasses = new QAction(SchoolPlanner);
        actionClasses->setObjectName(QStringLiteral("actionClasses"));
        centralWidget = new QWidget(SchoolPlanner);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout->addWidget(comboBox, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(499, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy);
        tableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);

        gridLayout->addWidget(tableView, 1, 0, 1, 3);

        SchoolPlanner->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SchoolPlanner);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 659, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        SchoolPlanner->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SchoolPlanner);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SchoolPlanner->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionRooms);
        menuEdit->addAction(actionGroups);
        menuEdit->addAction(actionTeachers);
        menuEdit->addAction(actionClasses);

        retranslateUi(SchoolPlanner);

        QMetaObject::connectSlotsByName(SchoolPlanner);
    } // setupUi

    void retranslateUi(QMainWindow *SchoolPlanner)
    {
        SchoolPlanner->setWindowTitle(QApplication::translate("SchoolPlanner", "SchoolPlanner", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("SchoolPlanner", "Open...", Q_NULLPTR));
        actionSave_As->setText(QApplication::translate("SchoolPlanner", "Save as...", Q_NULLPTR));
        actionSave->setText(QApplication::translate("SchoolPlanner", "Save", Q_NULLPTR));
        actionRooms->setText(QApplication::translate("SchoolPlanner", "Rooms", Q_NULLPTR));
        actionGroups->setText(QApplication::translate("SchoolPlanner", "Groups", Q_NULLPTR));
        actionTeachers->setText(QApplication::translate("SchoolPlanner", "Teachers", Q_NULLPTR));
        actionNew->setText(QApplication::translate("SchoolPlanner", "New", Q_NULLPTR));
        actionExit->setText(QApplication::translate("SchoolPlanner", "Exit", Q_NULLPTR));
        actionClasses->setText(QApplication::translate("SchoolPlanner", "Classes", Q_NULLPTR));
        label->setText(QApplication::translate("SchoolPlanner", "Room", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("SchoolPlanner", "File", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("SchoolPlanner", "Edit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SchoolPlanner: public Ui_SchoolPlanner {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCHOOLPLANNER_H
