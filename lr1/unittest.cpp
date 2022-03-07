/*
 * Автор: Скворцов Даниил
 * Дата: 25.02.22
 * Назначение: Unit-тесты.
*/

#include <QTest>
#include "operator.h"
#include "unittest.h"


UnitTest::UnitTest(QObject *parent) : QObject{parent}
{

}

void UnitTest::dif() {
    Oper op;
    QCOMPARE(op.dif(7, 3), 4);
}

void UnitTest::sum() {
    Oper op;
    QCOMPARE(op.sum(3, 5), 8);
}

void UnitTest::div() {
    Oper op;
    QCOMPARE(op.div(12, 4), 3);
}

void UnitTest::mul() {
    Oper op;
    QCOMPARE(op.mul(3, 4), 12);
}
