#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtDebug"


int sum(int a, int b)
{
    return a + b;
}

int dif(int a, int b)
{
    return a - b;
}

int mul(int a, int b)
{
    return a * b;
}

int divis(int a, int b)
{
    return a / b;
}

void testSum()
{
    int a = 3;
    int b = 4;
    int ans = 7;
    if(sum(a, b) == ans){
         qDebug() << "Тест на сложение пройден";
    } else {
        qDebug() << "Тест на сложение НЕ пройден";
    }
}

void testDif()
{
    int a = 12;
    int b = 4;
    int ans = 8;
    if(dif(a, b) == ans){
         qDebug() << "Тест на разность пройден";
    } else {
        qDebug() << "Тест на разность НЕ пройден";
    }
}

void testMul()
{
    int a = 3;
    int b = 4;
    int ans = 12;
    if(mul(a, b) == ans){
         qDebug() << "Тест на умножение пройден";
    } else {
        qDebug() << "Тест на умножение НЕ пройден";
    }
}

void testDiv()
{
    int a = 12;
    int b = 4;
    int ans = 3;
    if(divis(a, b) == ans){
         qDebug() << "Тест на деление пройден";
    } else {
        qDebug() << "Тест на деление НЕ пройден";
    }
}




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    testSum();
    testDif();
    testMul();
    testDiv();
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_btnMinus_clicked()
{
    int firstNum = ui->firstNum->text().toInt();
    int secondNum = ui->secondNum->text().toInt();

    ui->resultNum->setText(QString::number(dif(firstNum, secondNum)));

}

void MainWindow::on_btnPlus_clicked()
{
    int firstNum = ui->firstNum->text().toInt();
    int secondNum = ui->secondNum->text().toInt();

    ui->resultNum->setText(QString::number(sum(firstNum, secondNum)));
}

void MainWindow::on_btnMultiplier_clicked()
{
    int firstNum = ui->firstNum->text().toInt();
    int secondNum = ui->secondNum->text().toInt();

    ui->resultNum->setText(QString::number(mul(firstNum, secondNum)));
}

void MainWindow::on_btnDevider_clicked()
{
    int firstNum = ui->firstNum->text().toInt();
    int secondNum = ui->secondNum->text().toInt();

    ui->resultNum->setText(QString::number(divis(firstNum, secondNum)));
}

