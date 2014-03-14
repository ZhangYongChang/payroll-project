#ifndef EMPLOYEELISTDIALOG_H
#define EMPLOYEELISTDIALOG_H

#include <QDialog>
#include <map>
#include "employee.h"

namespace Ui {
class EmployeeListDialog;
}

class EmployeeListDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EmployeeListDialog(QWidget *parent = 0);
    ~EmployeeListDialog();

public:
	void ShowEmployeeList(std::map<int, Employee*> &itsEmployees);

private:
    Ui::EmployeeListDialog *ui;
};

#endif // EMPLOYEELISTDIALOG_H
