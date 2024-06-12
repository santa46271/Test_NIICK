#include "manipulator.h"
#include <QtMath>
#include <iostream>

// class Manipulator
Manipulator::Manipulator(double X, double Y, double R) : place(Coordinate{X,Y}), radius(R), allPoint() {}

Manipulator::~Manipulator() {}

Coordinate Manipulator::Place() const {
    return place;
}

double Manipulator::Radius() const {
    return radius;
}

void Manipulator::setCoordinate(double X, double Y) {
    place = Coordinate{X, Y};
}

void Manipulator::setCoordinate(const Coordinate& point) {
    place = point;
}

double Manipulator::distance(const Coordinate& point) const {
    return (qSqrt(qPow((point.x-place.x),2) + qPow((point.y-place.y),2)));
}

void Manipulator::replace(const Coordinate& point) {
    place = point;
    allPoint.addPoint(place);
}

bool Manipulator::canReplace(const Coordinate& point) {
    return radius>=distance(point);
}

void Manipulator::showMovingPoints() {
    allPoint.show();
}

// stuct Move
Move::Move() {}

void Move::addPoint(const Coordinate& P) {
    points.push_back(P);
}

void Move::addPoint(double X, double Y) {
    points.push_back(Coordinate{X, Y});
}

void Move::show() {
    for(auto i = points.begin(); i< points.end(); i++) {
        std::cout<<"{"<<(*i).x<<", "<<(*i).y<<"}";
        if (i<points.end()-1)
            std::cout<<", ";
        else
            std::cout<<std::endl;
    }
}
