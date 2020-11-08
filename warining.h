#ifndef WARINING_H
#define WARINING_H

#include <QDialog>

namespace Ui {
class Warining;
}

class Warining : public QDialog
{
    Q_OBJECT

public:
    explicit Warining(QWidget *parent = 0);
    ~Warining();
    bool getAcceptance() { return proceed; }

private slots:
    void on_yesButton_clicked();

    void on_noButton_clicked();

private:
    Ui::Warining *ui;
    bool proceed;
};

#endif // WARINING_H
