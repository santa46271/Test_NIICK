#ifndef DETALI_H
#define DETALI_H

#include <QFile>
#include <QVector>
#include "manipulator.h"

class Detali
{
private:
    QVector<Coordinate> points;

public:
    Detali(const QString& txt);
    Coordinate& operator[](qsizetype i);
    qsizetype size() const;
    QVector<Coordinate> getQVector() const;
    void show() const;
};

#endif // DETALI_H
