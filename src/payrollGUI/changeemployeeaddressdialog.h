#ifndef CHANGEEMPLOYEEADDRESSDIALOG_H
#define CHANGEEMPLOYEEADDRESSDIALOG_H

#include <QDialog>

namespace Ui {
class ChangeEmployeeAddressDialog;
}

class ChangeEmployeeAddressDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeEmployeeAddressDialog(QWidget *parent = 0);
    ~ChangeEmployeeAddressDialog();

public:
	int GetID() const;
	std::string GetAddress() const;

private:
    Ui::ChangeEmployeeAddressDialog *ui;
};

#endif // CHANGEEMPLOYEEADDRESSDIALOG_H
