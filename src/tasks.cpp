// Copyright 2022 UNN-CS
#include "tasks.h"
#include <cmath>
#include "circle.h"

double Rope() {
    double earth_radius = 6378100.0;
    Circle rope(earth_radius);
    double nFerence = rope.getFerence() + 1.0;
    rope.setFerence(nFerence);
    return rope.getRadius() - earth_radius;
}

double Pool() {
    double pool_radius = 3.0;
    double track_radius = 1.0;

    Circle pool(pool_radius);
    Circle road(pool_radius + track_radius);

    double priceOgrada = road.getFerence() * 2000.0;
    double priceDoroga = (road.getArea() - pool.getArea()) * 1000.0;
    return priceOgrada + priceDoroga;
}
