#ifndef ADDHOURLYEMPLOYEEDIALOG_H
#define ADDHOURLYEMPLOYEEDIALOG_H

#include <QDialog>

namespace Ui {
class AddHourlyEmployeeDialog;
}

class AddHourlyEmployeeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddHourlyEmployeeDialog(QWidget *parent = 0);
    ~AddHourlyEmployeeDialog();

public:
	int GetID() const;
	std::string GetName() const;
	std::string GetAddress() const;
	double GetSalaried() const;

private:
    Ui::AddHourlyEmployeeDialog *ui;
};

#endif // ADDHOURLYEMPLOYEEDIALOG_H
