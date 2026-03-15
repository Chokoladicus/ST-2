// Copyright 2022 UNN-CS
#include <cstdint>
#include <cmath>
#include "circle.h"

Circle::Circle(double rad) {
    setRadius(rad);
}

void Circle::setRadius(double rad) {
    radius = rad;
    ference = 2 * M_PI * rad;
    area = M_PI * radius * radius;
}

void Circle::setFerence(double fer) {
    ference = fer;
    radius = ference/(M_PI*2);
    area = (ference*ference)/(4*M_PI);
}

void Circle::setArea(double ar) {
    area = ar;
    radius = std::sqrt(area/M_PI);
    ference = 2 * M_PI * radius;
}

double Circle::getArea() const {
    return area;
}

double Circle::getRadius() const {
    return radius;
}

double Circle::getFerence() const {
    return ference;
}
