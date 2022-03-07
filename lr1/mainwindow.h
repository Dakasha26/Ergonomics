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
    void on_btnSum_clicked();
    void on_btnDif_clicked();
    void on_btnMul_clicked();
    void on_btnDiv_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
