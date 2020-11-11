#ifndef SCHOOLPLANNER_H
#define SCHOOLPLANNER_H

#include "editdictionary.h"
#include "editform.h"
#include "schooldata.h"
#include <QFile>
#include <QHBoxLayout>
#include <QMainWindow>
#include <QMap>
#include <QMessageBox>
#include <QTableView>

namespace Ui {
class SchoolPlanner;
}

class SchoolPlanner : public QMainWindow {

    Q_OBJECT
    const QStringList HORIZONTAL_LABELS = (QStringList() << "Monday"
                                                         << "Tuesday"
                                                         << "Wednesday"
                                                         << "Thursday"
                                                         << "Friday");

    const QStringList VERTICAL_LABELS = (QStringList() << "8:00 - 8:45"
                                                       << "8:55 - 9:40"
                                                       << "9:50 - 10:35"
                                                       << "10:50 - 11:35"
                                                       << "11:55 - 12:40"
                                                       << "12:50 - 13:35"
                                                       << "13:45 - 14:30"
                                                       << "14:40 - 15:25"
                                                       << "15:35 - 16:20"
                                                       << "16:30 - 17:15");

  public:
    explicit SchoolPlanner(QWidget *parent = 0);
    ~SchoolPlanner();

    void initializeJsonDocument();
    void fillSchedule();
    void fillRoomData(QString room);
    void clearAllData();
    void refreshData(QString roomName);

  private slots:
    void on_actionOpen_triggered();
    void on_comboBox_activated(const QString &arg1);
    void on_tableView_doubleClicked(const QModelIndex &index);
    void on_actionSave_As_triggered();
    void on_actionSave_triggered();
    void on_actionRooms_triggered();
    void on_actionGroups_triggered();
    void on_actionTeachers_triggered();
    void on_actionNew_triggered();
    void on_actionExit_triggered();

    void on_actionClasses_triggered();

  private:
    Ui::SchoolPlanner *ui;
    QStandardItemModel *model;
    SchoolData *schoolData;
};

#endif // SCHOOLPLANNER_H
