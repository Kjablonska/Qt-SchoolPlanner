#ifndef WARNING_H
#define WARNING_H

#include <QDialog>

namespace Ui {
class Warning;
}

class Warning : public QDialog
{
    Q_OBJECT

public:
    explicit Warning(QString message, bool error = false, QWidget *parent = 0);
    ~Warning();
    bool getAcceptance() { return proceed; }

private slots:
    void on_yesButton_clicked();
    void on_noButton_clicked();

private:
    Ui::Warning *ui;
    bool proceed;
};

#endif // WARNING_H
