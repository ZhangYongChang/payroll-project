#include "changascommisioneddialog.h"
#include "ui_changascommisioneddialog.h"

ChangAsCommisionedDialog::ChangAsCommisionedDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangAsCommisionedDialog)
{
    ui->setupUi(this);
}

ChangAsCommisionedDialog::~ChangAsCommisionedDialog()
{
    delete ui;
}

double ChangAsCommisionedDialog::GetSalaried() const
{
	return this->ui->lineEditSalaried->text().toDouble();
}

double ChangAsCommisionedDialog::GetRate() const
{
	return this->ui->lineEditSalaried->text().toDouble();
}

int ChangAsCommisionedDialog::GetID() const
{
	return this->ui->lineEditID->text().toInt();
}
