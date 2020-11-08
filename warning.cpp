#include "warning.h"
#include "ui_warning.h"

Warning::Warning(QString message, bool error, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Warning)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
    ui->textEdit->setText(message);

    if (error) {
        ui->noButton->setText("OK");
        ui->yesButton->setVisible(false);
    }
}

Warning::~Warning()
{
    delete ui;
}

void Warning::on_yesButton_clicked()
{
    proceed = true;
    Warning::close();
}

void Warning::on_noButton_clicked()
{
    proceed = false;
    Warning::close();
}
