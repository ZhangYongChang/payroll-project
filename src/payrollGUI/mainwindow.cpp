#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "addsalariedemployeedialog.h"
#include "addcommisionedemployeedialog.h"
#include "addhourlyemployeedialog.h"
#include "addsalariedemployee.h"
#include "addcommisionemployee.h"
#include "addhourlyemployee.h"

#include "changeaddresstransaction.h"
#include "changeemployeeaddressdialog.h"
#include "changenametransaction.h"
#include "changenamedialog.h"
#include "deleteemployeetransaction.h"
#include "deleteemployeebyiddialog.h"
#include "employeelistdialog.h"
#include "browerallemployee.h"
#include "loadtransaction.h"
#include "savetransaction.h"
#include "changenamedialog.h"
#include "changenametransaction.h"
#include "changeaddresstransaction.h"
#include "changeemployeeaddressdialog.h"

#include "changascommisioneddialog.h"
#include "changashourlyemployeedialog.h"
#include "changassalarieddialog.h"

#include "changecommisionedtransaction.h"
#include "changehourlytransaction.h"
#include "changesalariedtransaction.h"

#include <QTableWidget>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionLoad_triggered()
{
	QFileDialog *dlg = new QFileDialog(this);
	dlg->setWindowTitle(tr("Open Data"));
	dlg->setDirectory(".");
	dlg->setFilter(tr("Txt Files(*.txt)"));
	if(dlg->exec() == QDialog::Accepted)
	{
		QString path = dlg->selectedFiles()[0];
		std::string filepath(path.toStdString());
		LoadTransaction lt(filepath);
		lt.Execute();
	}
}

void MainWindow::on_actionSave_triggered()
{
	QString filename = QFileDialog::getSaveFileName(this, "Save file", "", ".txt");
	std::string filepath(filename.toStdString());
	SaveTransaction lt(filepath);
	lt.Execute();
}

void MainWindow::on_actionDeleteByID_triggered()
{
	DeleteEmployeeByIdDialog *dlg = new DeleteEmployeeByIdDialog();
	if (dlg->exec() == QDialog::Accepted)
	{
		int id = dlg->GetID();
		DeleteEmployeeTransaction det(id);
		det.Execute();
	}
}

void MainWindow::on_actionExit_triggered()
{
	MainWindow::close();
}

void MainWindow::on_actionReload_triggered()
{
	QFileDialog *dlg = new QFileDialog(this);
	dlg->setWindowTitle(tr("Open Data"));
	dlg->setDirectory(".");
	dlg->setFilter(tr("Txt Files(*.txt)"));
	if(dlg->exec() == QDialog::Accepted)
	{
		QString path = dlg->selectedFiles()[0];
		std::string filepath(path.toStdString());
		LoadTransaction lt(filepath);
		lt.Execute();
	}
}

void MainWindow::on_actionAddSalariedEmployee_triggered()
{
    AddSalariedEmployeeDialog *dlg = new AddSalariedEmployeeDialog();
	dlg->setWindowTitle("AddSalariedEmployee");
    if (dlg->exec() == QDialog::Accepted) 
	{
		int empid = dlg->GetID();
		std::string name = dlg->GetName();
		std::string address = dlg->GetAddress();
		double salaried = dlg->GetSalaried();

		AddSalariedEmployee ase(empid, name, address, salaried);
		ase.Execute();		
    }

    delete dlg;
}

void MainWindow::on_actionAddCommionedEmployee_triggered()
{
	AddCommisionedEmployeeDialog *dlg = new AddCommisionedEmployeeDialog();
	dlg->setWindowTitle("AddCommionedEmployee");
	if (dlg->exec() == QDialog::Accepted)
	{
		int id = dlg->GetID();
		std::string name = dlg->GetName();
		std::string address = dlg->GetAddress();

		double salaried = dlg->GetSalaried();
		double rate = dlg->GetRate();

		AddCommisionEmployee ace(id, name, address, salaried, rate);
		ace.Execute();
	}
}

void MainWindow::on_actionAddHourlyEmployee_triggered()
{
	AddHourlyEmployeeDialog *dlg = new AddHourlyEmployeeDialog();
	dlg->setWindowTitle("AddHourlyEmployee");
	if (dlg->exec() == QDialog::Accepted)
	{
		int id = dlg->GetID();
		std::string name = dlg->GetName();
		std::string address = dlg->GetAddress();
		double salaried = dlg->GetSalaried();

		AddHourlyEmployee ahe(id, name, address, salaried);
		ahe.Execute();
	}
}

void MainWindow::on_actionChangeName_triggered()
{
	ChangeNameDialog *dlg = new ChangeNameDialog();
	dlg->setWindowTitle("ChangeName");
	if (dlg->exec() == QDialog::Accepted)
	{
		int id = dlg->GetID();
		std::string name = dlg->GetName();

		ChangeNameTransaction cnt(id, name);
		cnt.Execute();
	}
}

void MainWindow::on_actionChangeAddress_triggered()
{
	ChangeEmployeeAddressDialog *dlg = new ChangeEmployeeAddressDialog();
	dlg->setWindowTitle("ChangeAddress");
	if (dlg->exec() == QDialog::Accepted)
	{
		int id = dlg->GetID();
		std::string address = dlg->GetAddress();
		ChangeAddressTransaction cat(id, address);
		cat.Execute();
	}
}

void MainWindow::on_actionChangeAsSalaried_triggered()
{	
	ChangAsSalariedDialog *dlg = new ChangAsSalariedDialog();
	dlg->setWindowTitle("ChangeAsSalaried");
	if (dlg->exec() == QDialog::Accepted)
	{
		int id = dlg->GetID();
		double salaried = dlg->GetSalaried();

		ChangeSalariedTransaction cst(id, salaried);
		cst.Execute();
	}
}

void MainWindow::on_actionChangeAsCommioned_triggered()
{
	ChangAsCommisionedDialog *dlg = new ChangAsCommisionedDialog();
	dlg->setWindowTitle("ChangeAsCommioned");
	if (dlg->exec() == QDialog::Accepted)
	{
		int id = dlg->GetID();
		double salaried = dlg->GetSalaried();
		double rate = dlg->GetRate();

		ChangeCommisionedTransaction cct(id, salaried, rate);
		cct.Execute();
	}
}

void MainWindow::on_actionChangeAsHourly_triggered()
{
	ChangAsHourlyEmployeeDialog *dlg = new ChangAsHourlyEmployeeDialog();
	dlg->setWindowTitle("ChangeAsHourly");
	if (dlg->exec() == QDialog::Accepted)
	{
		int id = dlg->GetID();
		double salaried = dlg->GetSalaried();

		ChangeHourlyTransaction cht(id, salaried);
		cht.Execute();
	}
}

void MainWindow::on_actionFindAllEmployee_triggered()
{
	EmployeeListDialog *dlg = new EmployeeListDialog();
	CBrowerAllEmployee bae;
	bae.Execute();
	std::map<int, Employee*> itsEmployees = bae.GetEmployees();

	dlg->setWindowTitle("All of Employees.");  
	dlg->ShowEmployeeList(itsEmployees);
	dlg->exec();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, "About", "CopyRight @ All of us.");
}
