#ifndef OPERATOR_H
#define OPERATOR_H

#include <QObject>

class Oper : public QObject
{
    Q_OBJECT

public:
    explicit Oper(QObject *parent = nullptr);


public slots:
    int sum(int a, int b);
    int mul(int a, int b);
    int div(int a, int b);
    int dif(int a, int b);

signals:

};

#endif // OPERATOR_H
