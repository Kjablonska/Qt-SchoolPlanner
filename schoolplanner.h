#ifndef SCHOOLPLANNER_H
#define SCHOOLPLANNER_H

#include <QMainWindow>
#include <QTableView>
#include <QItemDelegate>
#include <QStandardItemModel>
#include <QFile>

#include <QJsonArray>
#include <QTextStream>
#include <QDataStream>
#include <QJsonDocument>
#include <QJsonObject>

#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

#include <QVariant>
#include <QModelIndex>

#include <QLabel>
#include <QHBoxLayout>

#include "editform.h"
#include "schooldata.h"

namespace Ui {
class SchoolPlanner;
}

class SchoolPlanner : public QMainWindow
{
    Q_OBJECT
    const QStringList HORIZONTAL_LABELS = (QStringList() << "Monday" << "Tuesday" << "Wednesday" << "Thursday" << "Friday");
    const QStringList VERTICAL_LABELS = (QStringList() << "8:00 - 8:45" << "8:55 - 9:40" << "9:50 - 10:35" << "10:50 - 11:35" << "11:55 - 12:40"
                                         << "12:50 - 13:35" << "13:45 - 14:30" << "14:40 - 15:25" << "15:35 - 16:20" << "16:30 - 17:15");


public:
    explicit SchoolPlanner(QWidget *parent = 0);
    ~SchoolPlanner();

    void initializeJsonDocument();
    void fillSchedules();
    void clearAllData();

private slots:
    void on_actionOpen_triggered();

    void on_comboBox_activated(const QString &arg1);

    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    Ui::SchoolPlanner *ui;
    QStandardItemModel *model;
    SchoolData schoolData;
};

#endif // SCHOOLPLANNER_H
