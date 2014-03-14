#ifndef ADDTIMECARDDIALOG_H
#define ADDTIMECARDDIALOG_H

#include <QDialog>

namespace Ui {
class AddTimeCardDialog;
}

class AddTimeCardDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddTimeCardDialog(QWidget *parent = 0);
    ~AddTimeCardDialog();

private:
    Ui::AddTimeCardDialog *ui;
};

#endif // ADDTIMECARDDIALOG_H
