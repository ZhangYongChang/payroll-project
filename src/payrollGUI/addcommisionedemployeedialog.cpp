#include "addcommisionedemployeedialog.h"
#include "ui_addcommisionedemployeedialog.h"

AddCommisionedEmployeeDialog::AddCommisionedEmployeeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCommisionedEmployeeDialog)
{
    ui->setupUi(this);
}

AddCommisionedEmployeeDialog::~AddCommisionedEmployeeDialog()
{
    delete ui;
}

int AddCommisionedEmployeeDialog::GetID() const
{
	return this->ui->lineEditID->text().toInt();
}

std::string AddCommisionedEmployeeDialog::GetName() const
{
	return this->ui->lineEditName->text().toStdString();
}

std::string AddCommisionedEmployeeDialog::GetAddress() const
{
	return this->ui->lineEditAddress->text().toStdString();
}

double AddCommisionedEmployeeDialog::GetSalaried() const
{
	return this->ui->lineEditSalaried->text().toDouble();
}

double AddCommisionedEmployeeDialog::GetRate() const
{
	return this->ui->lineEditSalaried->text().toDouble();
}
