#include "changassalarieddialog.h"
#include "ui_changassalarieddialog.h"

ChangAsSalariedDialog::ChangAsSalariedDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangAsSalariedDialog)
{
    ui->setupUi(this);
}

ChangAsSalariedDialog::~ChangAsSalariedDialog()
{
    delete ui;
}

double ChangAsSalariedDialog::GetSalaried() const
{
	return this->ui->lineEditSalaried->text().toDouble();
}

int ChangAsSalariedDialog::GetID() const
{
	return this->ui->lineEditID->text().toInt();
}
