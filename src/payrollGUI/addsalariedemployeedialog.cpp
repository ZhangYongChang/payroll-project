#include "addsalariedemployeedialog.h"
#include "ui_addsalariedemployeedialog.h"

AddSalariedEmployeeDialog::AddSalariedEmployeeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddSalariedEmployeeDialog)
{
    ui->setupUi(this);
}

AddSalariedEmployeeDialog::~AddSalariedEmployeeDialog()
{
    delete ui;
}

int AddSalariedEmployeeDialog::GetID() const
{
    QString strID = this->ui->lineEditID->text();
    return strID.toInt();
}

std::string AddSalariedEmployeeDialog::GetName() const
{
    QString strName = this->ui->lineEditName->text();
    return strName.toStdString();
}

std::string AddSalariedEmployeeDialog::GetAddress() const
{
    QString strAddress = this->ui->lineEditAddress->text();
    return strAddress.toStdString();
}

double AddSalariedEmployeeDialog::GetSalaried() const
{
    return this->ui->lineEditSalaried->text().toDouble();
}
