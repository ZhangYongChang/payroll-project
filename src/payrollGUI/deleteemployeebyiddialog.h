#ifndef DELETEEMPLOYEEBYIDDIALOG_H
#define DELETEEMPLOYEEBYIDDIALOG_H

#include <QDialog>

namespace Ui {
class DeleteEmployeeByIdDialog;
}

class DeleteEmployeeByIdDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteEmployeeByIdDialog(QWidget *parent = 0);
    ~DeleteEmployeeByIdDialog();

public:
	int GetID() const;

private:
    Ui::DeleteEmployeeByIdDialog *ui;
};

#endif // DELETEEMPLOYEEBYIDDIALOG_H
