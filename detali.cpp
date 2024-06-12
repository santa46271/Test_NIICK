#include "detali.h"
#include <QIODevice>
#include <QTextStream>
#include <QString>
#include <QDebug>

Detali::Detali(const QString& path) : points() {
    QFile file(path);
    if(file.open(QIODevice::ReadOnly)) {
        QTextStream stream(&file);
        while (!stream.atEnd()) {
            QString line = stream.readLine();
            QString dataX;
            QString dataY;
            for (const auto& i: line) {
                if (!dataY.size() && i !=',' && i!=' ') {
                    dataX += i;
                }
                else if (i !=',') {
                    dataY += i;
                }
            }
            points.push_back(Coordinate{dataX.toDouble(), dataY.toDouble()});
        }
        file.close();
    }
    else {
        qDebug()<<"Не удалось открыть файл";
    }
}

Coordinate& Detali::operator [](qsizetype i) {
    return (points[i]);
}

qsizetype Detali::size() const {
    return points.size();
}

QVector<Coordinate> Detali::getQVector() const {
    return points;
}

void Detali::show() const{
    foreach (Coordinate i, points) {
        qDebug()<<"{"<<i.x<<", "<<i.y<<"}\t";
    }
    qDebug()<<"\n\r";
}
