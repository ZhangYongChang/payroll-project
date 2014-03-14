#include "changashourlyemployeedialog.h"
#include "ui_changashourlyemployeedialog.h"

ChangAsHourlyEmployeeDialog::ChangAsHourlyEmployeeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangAsHourlyEmployeeDialog)
{
    ui->setupUi(this);
}

ChangAsHourlyEmployeeDialog::~ChangAsHourlyEmployeeDialog()
{
    delete ui;
}

int ChangAsHourlyEmployeeDialog::GetID() const
{
	return this->ui->lineEditID->text().toInt();
}

double ChangAsHourlyEmployeeDialog::GetSalaried() const
{
	return this->ui->lineEditSalaried->text().toDouble();
}
