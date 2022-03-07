/*
 * Автор: Скворцов Даниил
 * Дата: 25.02.22
 * Назначение: Функции арифметических операций.
*/

#include "operator.h"

Oper::Oper(QObject *parent) : QObject{parent}
{

}

int Oper::sum(int a, int b) {
    return a + b;
}

int Oper::dif(int a, int b) {
    return a - b;
}

int Oper::mul(int a, int b) {
    return a * b;
}

int Oper::div(int a, int b) {
    return a / b;
}
