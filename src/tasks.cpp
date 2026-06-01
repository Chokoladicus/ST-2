// Copyright 2022 UNN-CS
#include "tasks.h"
#include <cmath>
#include "circle.h"

double calEarthAndRope() {
    double earth_radius_meters = 6378100.0;
    Circle rope(earth_radius_meters);
    double new_ference = rope.getFerence() + 1.0;
    rope.setFerence(new_ference);
    return rope.getRadius() - earth_radius_meters;
}

double calPool() {
    double pool_radius = 3.0;
    double concrete_pavement_width = 1.0;

    Circle pool(pool_radius);
    Circle road(pool_radius + concrete_pavement_width);

    double fencing_price = road.getFerence() * 2000.0;
    double concrete_pavement_width_price =
        (road.getArea() - pool.getArea()) * 1000.0;
    return fencing_price + concrete_pavement_width_price;
}
