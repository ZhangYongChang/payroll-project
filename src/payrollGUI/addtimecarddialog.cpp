#include "addtimecarddialog.h"
#include "ui_addtimecarddialog.h"

AddTimeCardDialog::AddTimeCardDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTimeCardDialog)
{
    ui->setupUi(this);
}

AddTimeCardDialog::~AddTimeCardDialog()
{
    delete ui;
}
