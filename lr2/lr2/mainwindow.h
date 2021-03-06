/*
 * Автор: Скворцов Даниил
 * Дата: 14.03.22
 * Назначение: Программа отправляет Ардуино введённое пользователем число, а в ответ получает, чётное ли оно
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QByteArray>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void readSerial();
    void writeSerial(char* c);

    void on_btnConnect_clicked();
    void on_btnGetParity_clicked();
    void on_btnDisconnect_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort *arduino;
    static const quint16 arduino_uno_vendor_id = 0x1A86;
    static const quint16 arduino_uno_product_id = 0x7523;
    QByteArray serialData;
    QString serialBuffer;
    bool first_try;

};
#endif // MAINWINDOW_H
