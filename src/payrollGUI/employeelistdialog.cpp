#include "employeelistdialog.h"
#include "ui_employeelistdialog.h"

EmployeeListDialog::EmployeeListDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmployeeListDialog)
{
    ui->setupUi(this);
	ui->tableWidgetEmployeeList->setGeometry(QRect(20, 10, 351, 221));
	ui->tableWidgetEmployeeList->setColumnCount(4);
	ui->tableWidgetEmployeeList->setRowCount(10);

	QStringList header;  
	header << "ID" << "Name" << "Address" << "Type";
	QTableWidget *tableWidget = this->ui->tableWidgetEmployeeList;
	tableWidget->setHorizontalHeaderLabels(header);
}

EmployeeListDialog::~EmployeeListDialog()
{
    delete ui;
}

void EmployeeListDialog::ShowEmployeeList( std::map<int, Employee*> &itsEmployees )
{
	QTableWidget *tableWidget = this->ui->tableWidgetEmployeeList;
	int count = 0;
	for ( std::map<int, Employee *>::reverse_iterator it = itsEmployees.rbegin();
		it != itsEmployees.rend();
		++it ) {
			Employee *e = it->second;
			QString strID;

			tableWidget->setItem(count,0,new QTableWidgetItem(QString::number(e->GetEmpId(), 10)));
			tableWidget->setItem(count,1,new QTableWidgetItem(e->GetName().c_str()));
			tableWidget->setItem(count,2,new QTableWidgetItem(e->GetAddress().c_str()));
			tableWidget->setItem(count,3,new QTableWidgetItem("null"));

			++count;
	}

	tableWidget->show();
}
