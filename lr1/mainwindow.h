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
    void on_btnPlus_clicked();
    void on_btnMinus_clicked();
    void on_btnMultiplier_clicked();
    void on_btnDevider_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
