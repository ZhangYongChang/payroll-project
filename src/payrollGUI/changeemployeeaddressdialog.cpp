#include "changeemployeeaddressdialog.h"
#include "ui_changeemployeeaddressdialog.h"

ChangeEmployeeAddressDialog::ChangeEmployeeAddressDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeEmployeeAddressDialog)
{
    ui->setupUi(this);
}

ChangeEmployeeAddressDialog::~ChangeEmployeeAddressDialog()
{
    delete ui;
}

int ChangeEmployeeAddressDialog::GetID() const
{
	return this->ui->lineEditID->text().toInt();
}

std::string ChangeEmployeeAddressDialog::GetAddress() const
{
	return this->ui->lineEditAddress->text().toStdString();
}
