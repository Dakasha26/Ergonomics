/*
 * Автор: Скворцов Даниил
 * Дата: 14.02.22
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
        arduino->setDataBits(QSerialPort::Data8); // байт
        //arduino->setFlowControl(QSerialPort::NoFlowControl);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        qDebug() << "Baud Rate: 9600/nData Bits: 8 bit";

        QObject::connect(arduino, SIGNAL(readyRead()), this, SLOT(readSerial()));

        ui->statusLabel->text() = "Подключено";
        qDebug() << "Ардуино подключено";
    } else {
        qDebug() << "Не удалось обнаружить корректный порт";
    }
}

/* ----- Отключение Ардуино ----- */
void MainWindow::on_btnDisconnect_clicked()
{
    arduino->disconnect();
    ui->statusLabel->text() = "Неактивно";
    qDebug() << "Ардуино отключено";
}

/* ----- Основная функция программы - запрос на определение чётности числа ----- */
void MainWindow::on_btnGetParity_clicked()
{
    char* c = (ui->spinBoxOfNumber->text()).toUtf8().data();
    arduino->write(c);

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

void MainWindow::readSerial()
{
    serialData = arduino->readAll();
    if(serialData == "0")
        ui->parityLabel->text() = "чётное";
    else
        ui->parityLabel->text() = "нечётное";
}

void MainWindow::writeSerial(char* c)
{
    arduino->write(c);
}



