/*
 * Автор: Скворцов Даниил
 * Дата: 25.02.22
 * Назначение: Демонстрация интеграционных и unit-тестов. Отработка навыков работы в команде.
*/

#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QTest>
#include "unittest.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QTest::qExec(new UnitTest, argc, argv);
    return a.exec();
}
