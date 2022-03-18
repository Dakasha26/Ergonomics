/*
 * Автор: Скворцов Даниил
 * Дата: 14.03.22
 * Назначение: Программа отправляет Ардуино введённое пользователем число, а в ответ получает, чётное ли оно
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPortInfo>
#include <QDebug>
#include <QMessageBox>
#include <QTimer>


/* ----- Попытка подключения к Arduino ----- */
void MainWindow::on_btnConnect_clicked()
{
    arduino = new QSerialPort(this);
    serialBuffer = "";
    first_try = true;

    bool arduino_is_available = false;
    QString arduino_uno_port_name;

    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        if(serialPortInfo.hasProductIdentifier() && serialPortInfo.hasVendorIdentifier()){
            if((serialPortInfo.productIdentifier() == arduino_uno_product_id)
                    && (serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id)){
                arduino_is_available = true;
                arduino_uno_port_name = serialPortInfo.portName();
            }
        }
    }

    if(arduino_is_available){
        qDebug() << "Найден порт" + arduino_uno_port_name + "";

        // Копипастовые настройки. В случае проблем смотреть сюда
        arduino->setPortName(arduino_uno_port_name);
        arduino->open(QSerialPort::ReadWrite);
        arduino->setBaudRate(QSerialPort::Baud9600); // Стандартный 9600
        arduino->setDataBits(QSerialPort::Data8); // 8 байт
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        qDebug() << "Baud Rate: 9600";
        qDebug() << "Data Bits: 8 bitt";

        QObject::connect(arduino, SIGNAL(readyRead()), this, SLOT(readSerial()));

        ui->statusLabel->setText("Подключено");
        ui->spinBoxOfNumber->setEnabled(true);
        ui->btnGetParity->setEnabled(true);
        qDebug() << "Ардуино подключено";
    } else {
        qDebug() << "Не удалось обнаружить корректный порт";
    }
}

/* ----- Отключение Ардуино ----- */
void MainWindow::on_btnDisconnect_clicked()
{
    arduino->disconnect();
    ui->statusLabel->setText("Неактивно");
    ui->spinBoxOfNumber->setEnabled(false);
    ui->btnGetParity->setEnabled(false);
    qDebug() << "Ардуино отключено";
}

/* ----- Основная функция программы - запрос на определение чётности числа ----- */
void MainWindow::on_btnGetParity_clicked()
{
    char* c = (ui->spinBoxOfNumber->text()).toUtf8().data();
    arduino->write(c);
    readSerial();

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/* ----- Чтение и вывод Serial на Ардуино ----- */
void MainWindow::readSerial()
{
    serialData = arduino->readLine();
    if(serialData.size() == 3)
        if(serialData[0] == '1'){
            ui->parityLabel->setText("чётное");
        } else {
            ui->parityLabel->setText("нечётное");
        }
}

void MainWindow::writeSerial(char* c)
{
    arduino->write(c);
}
