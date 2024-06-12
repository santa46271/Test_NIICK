#include <QCoreApplication>
#include "manipulator.h"
#include "detali.h"
#include <QVector>
#include <iostream>
#include <QFile>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //QVector<Coordinate> detali{Coordinate{1,3}, Coordinate{2,1.41}, Coordinate{0.2,-7}, Coordinate{-5,-1}, Coordinate{0,9}};

    Detali detaly("detali.txt");
    Manipulator m1(0,0,8);
    Manipulator m2(2,1,10);

    auto comp = [](double a, double b){return a<b;};
    for (qsizetype i =0; i<detaly.size(); i++) {
        if (comp(m1.distance(detaly[i]),m2.distance(detaly[i]))) {
            if (m1.canReplace(detaly[i])) m1.replace(detaly[i]);
            else if (m2.canReplace(detaly[i])) m2.replace(detaly[i]);
        }
        else {
            if (m2.canReplace(detaly[i])) m2.replace(detaly[i]);
            else if (m1.canReplace(detaly[i])) m1.replace(detaly[i]);
        }
    }

    std::cout<<"m1: \n";
    m1.showMovingPoints();
    std::cout<<"m2: \n";
    m2.showMovingPoints();

    return a.exec();
}
