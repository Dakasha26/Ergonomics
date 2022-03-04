#include <QTest>
#include "operator.h"
#include "unittest.h"


UnitTest::UnitTest(QObject *parent) : QObject{parent}
{

}

void UnitTest::sub() {
    Oper op;
    QCOMPARE(op.dif(7, 3), 4);
}

void UnitTest::add() {
    Oper op;
    QCOMPARE(op.sum(3, 5), 8);
}

void UnitTest::div() {
    Oper op;
    QCOMPARE(op.divis(12, 4), 3);
}

void UnitTest::mult() {
    Oper op;
    QCOMPARE(op.mul(3, 4), 12);
}
