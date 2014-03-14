#ifndef ADDCOMMISIONEDEMPLOYEEDIALOG_H
#define ADDCOMMISIONEDEMPLOYEEDIALOG_H

#include <QDialog>

namespace Ui {
class AddCommisionedEmployeeDialog;
}

class AddCommisionedEmployeeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddCommisionedEmployeeDialog(QWidget *parent = 0);
    ~AddCommisionedEmployeeDialog();

public:
	int GetID() const;
	std::string GetName() const;
	std::string GetAddress() const;
	double GetSalaried() const;
	double GetRate() const;

private:
    Ui::AddCommisionedEmployeeDialog *ui;
};

#endif // ADDCOMMISIONEDEMPLOYEEDIALOG_H
