#include "addsalesreceiptsdialog.h"
#include "ui_addsalesreceiptsdialog.h"

AddSalesReceiptsDialog::AddSalesReceiptsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddSalesReceiptsDialog)
{
    ui->setupUi(this);
}

AddSalesReceiptsDialog::~AddSalesReceiptsDialog()
{
    delete ui;
}
