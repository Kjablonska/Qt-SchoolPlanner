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
    void setAvailableRooms();
    void initializeJsonDocument();
    void fillSchedules();
    void initializeRoom(QString room);

private slots:
    void on_actionOpen_triggered();

private:
    Ui::SchoolPlanner *ui;
    QStandardItemModel *model;
    QString dataFileJson = "/home/kj/projects/elka/EGUI/lab1/SchoolPlanner/resources/data.json";
    QJsonDocument jsonDocument;
    QStringList roomsList;
};

#endif // SCHOOLPLANNER_H
