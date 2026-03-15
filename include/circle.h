// Copyright 2022 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_
#include <cstdint>

class Circle {
 private:
  double radius;
  double ference;
  double area;

 public:
  explicit Circle(double rad);
  void setRadius(double rad);
  void setFerence(double fer);
  void setArea(double ar);
  double getRadius() const;
  double getFerence() const;
  double getArea() const;
};

#endif  // INCLUDE_CIRCLE_H_
