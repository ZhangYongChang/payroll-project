#include "addhourlyemployeedialog.h"
#include "ui_addhourlyemployeedialog.h"

AddHourlyEmployeeDialog::AddHourlyEmployeeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddHourlyEmployeeDialog)
{
    ui->setupUi(this);
}

AddHourlyEmployeeDialog::~AddHourlyEmployeeDialog()
{
    delete ui;
}

int AddHourlyEmployeeDialog::GetID() const
{
	return this->ui->lineEditID->text().toInt();
}

std::string AddHourlyEmployeeDialog::GetName() const
{
	return this->ui->lineEditName->text().toStdString();
}

std::string AddHourlyEmployeeDialog::GetAddress() const
{
	return this->ui->lineEditAddress->text().toStdString();
}

double AddHourlyEmployeeDialog::GetSalaried() const
{
	return this->ui->lineEditSalaried->text().toDouble();
}
