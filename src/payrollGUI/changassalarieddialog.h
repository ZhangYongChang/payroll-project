#ifndef CHANGASSALARIEDDIALOG_H
#define CHANGASSALARIEDDIALOG_H

#include <QDialog>

namespace Ui {
class ChangAsSalariedDialog;
}

class ChangAsSalariedDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChangAsSalariedDialog(QWidget *parent = 0);
    ~ChangAsSalariedDialog();
	double GetSalaried() const;
	int GetID() const;
private:
    Ui::ChangAsSalariedDialog *ui;
};

#endif // CHANGASSALARIEDDIALOG_H
