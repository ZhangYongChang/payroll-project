#include "changenamedialog.h"
#include "ui_changenamedialog.h"

ChangeNameDialog::ChangeNameDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeNameDialog)
{
    ui->setupUi(this);
}

ChangeNameDialog::~ChangeNameDialog()
{
    delete ui;
}

int ChangeNameDialog::GetID() const
{
	return this->ui->lineEditID->text().toInt();
}

std::string ChangeNameDialog::GetName() const
{
	return this->ui->lineEditName->text().toStdString();
}
