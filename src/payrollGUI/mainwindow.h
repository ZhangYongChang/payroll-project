#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionLoad_triggered();

    void on_actionSave_triggered();

    void on_actionDeleteByID_triggered();

    void on_actionExit_triggered();

    void on_actionReload_triggered();

    void on_actionAddSalariedEmployee_triggered();

    void on_actionAddCommionedEmployee_triggered();

    void on_actionAddHourlyEmployee_triggered();

    void on_actionChangeName_triggered();

    void on_actionChangeAddress_triggered();

    void on_actionChangeAsSalaried_triggered();

    void on_actionChangeAsCommioned_triggered();

    void on_actionChangeAsHourly_triggered();

    void on_actionFindAllEmployee_triggered();

    void on_actionAbout_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
