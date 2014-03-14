#ifndef CHANGASHOURLYEMPLOYEEDIALOG_H
#define CHANGASHOURLYEMPLOYEEDIALOG_H

#include <QDialog>

namespace Ui {
class ChangAsHourlyEmployeeDialog;
}

class ChangAsHourlyEmployeeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChangAsHourlyEmployeeDialog(QWidget *parent = 0);
    ~ChangAsHourlyEmployeeDialog();
	int GetID() const;
	double GetSalaried() const;
private:
    Ui::ChangAsHourlyEmployeeDialog *ui;
};

#endif // CHANGASHOURLYEMPLOYEEDIALOG_H
