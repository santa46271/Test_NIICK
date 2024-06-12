#ifndef MANIPULATOR_H
#define MANIPULATOR_H

#include <QVector>
#include <iostream>

struct Coordinate {
    double x;
    double y;
};

struct Move {
private:
    QVector<Coordinate> points;

public:
    Move();
    void addPoint(const Coordinate& P={0,0});
    void addPoint(double X =0, double Y =0);
    void show();
};

class Manipulator
{
private:
    Coordinate place;
    double radius;
    Move allPoint;

public:
    Manipulator(double X, double Y, double R);
    Manipulator(const Coordinate& P={0,0}, double R=0);
    ~Manipulator();
    Coordinate Place() const;
    double Radius() const;
    void setCoordinate(double X, double Y);
    void setCoordinate(const Coordinate& point);
    double distance(const Coordinate& point) const;
    void replace(const Coordinate& point);
    bool canReplace(const Coordinate& point);
    void showMovingPoints();
};

#endif // MANIPULATOR_H
