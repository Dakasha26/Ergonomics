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
