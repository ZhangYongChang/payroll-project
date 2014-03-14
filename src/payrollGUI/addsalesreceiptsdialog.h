#ifndef ADDSALESRECEIPTSDIALOG_H
#define ADDSALESRECEIPTSDIALOG_H

#include <QDialog>

namespace Ui {
class AddSalesReceiptsDialog;
}

class AddSalesReceiptsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddSalesReceiptsDialog(QWidget *parent = 0);
    ~AddSalesReceiptsDialog();

private:
    Ui::AddSalesReceiptsDialog *ui;
};

#endif // ADDSALESRECEIPTSDIALOG_H
