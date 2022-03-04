#ifndef UNITTEST_H
#define UNITTEST_H

#include <QObject>

class UnitTest : public QObject
{
   Q_OBJECT

public:
    explicit UnitTest(QObject *parent = nullptr);

private slots:
    void add();
    void sub();
    void mult();
    void div();

signals:

};

#endif // UNITTEST_H
