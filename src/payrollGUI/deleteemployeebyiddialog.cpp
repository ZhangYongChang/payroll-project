#include "deleteemployeebyiddialog.h"
#include "ui_deleteemployeebyiddialog.h"

DeleteEmployeeByIdDialog::DeleteEmployeeByIdDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteEmployeeByIdDialog)
{
    ui->setupUi(this);
}

DeleteEmployeeByIdDialog::~DeleteEmployeeByIdDialog()
{
    delete ui;
}

int DeleteEmployeeByIdDialog::GetID() const
{
	return this->ui->lineEditID->text().toInt();
}
