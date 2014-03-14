#ifndef ADDSALARIEDEMPLOYEEDIALOG_H
#define ADDSALARIEDEMPLOYEEDIALOG_H

#include <QDialog>
#include <string>

namespace Ui {
class AddSalariedEmployeeDialog;
}

class AddSalariedEmployeeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddSalariedEmployeeDialog(QWidget *parent = 0);
    ~AddSalariedEmployeeDialog();

    int GetID() const;
    std::string GetName() const;
    std::string GetAddress() const;
    double GetSalaried() const;

private:
    Ui::AddSalariedEmployeeDialog *ui;
};

#endif // ADDSALARIEDEMPLOYEEDIALOG_H
