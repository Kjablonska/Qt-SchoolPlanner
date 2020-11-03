#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QDialog>
#include <QTableView>
#include <QItemDelegate>
#include <QStandardItemModel>

namespace Ui {
class TableModel;
}

class TableModel : public QDialog
{
    Q_OBJECT

public:
    explicit TableModel(QWidget *parent = 0);
    ~TableModel();

private:
    Ui::TableModel *ui;

    // QStandardItemModel provides a classic
    // item-based approach to working with the model.
    QStandardItemModel *model;
};


#endif // TABLEMODEL_H
