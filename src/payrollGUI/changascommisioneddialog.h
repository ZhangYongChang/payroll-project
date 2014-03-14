#ifndef CHANGASCOMMISIONEDDIALOG_H
#define CHANGASCOMMISIONEDDIALOG_H

#include <QDialog>

namespace Ui {
class ChangAsCommisionedDialog;
}

class ChangAsCommisionedDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChangAsCommisionedDialog(QWidget *parent = 0);
    ~ChangAsCommisionedDialog();
	double GetSalaried() const;
	double GetRate() const;
	int GetID() const;
private:
    Ui::ChangAsCommisionedDialog *ui;
};

#endif // CHANGASCOMMISIONEDDIALOG_H
