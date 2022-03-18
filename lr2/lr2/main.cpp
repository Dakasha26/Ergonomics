/*
 * Автор: Скворцов Даниил
 * Дата: 14.03.22
 * Назначение: Программа отправляет Ардуино введённое пользователем число, а в ответ получает, чётное ли оно
*/

#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
