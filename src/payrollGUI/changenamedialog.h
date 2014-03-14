#ifndef CHANGENAMEDIALOG_H
#define CHANGENAMEDIALOG_H

#include <QDialog>

namespace Ui {
class ChangeNameDialog;
}

class ChangeNameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeNameDialog(QWidget *parent = 0);
    ~ChangeNameDialog();

	int GetID() const;
	std::string GetName() const;

private:
    Ui::ChangeNameDialog *ui;
};

#endif // CHANGENAMEDIALOG_H
