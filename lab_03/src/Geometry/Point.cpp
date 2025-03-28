#include "Point.hpp"

Point::Point() :
        x(0.0),
        y(0.0),
        z(0.0) {}

Point::Point(double x, double y, double z) :
        x(x),
        y(y),
        z(z) {}

Point::Point(const Point& other) :
        x(other.x),
        y(other.y),
        z(other.z) {}

double Point::get_x() const {
    return x;
}

void Point::set_x(double x) {
    this->x = x;
}

double Point::get_y() const {
    return y;
}

void Point::set_y(double y) {
    this->y = y;
}

double Point::get_z() const {
    return z;
}

void Point::set_z(double z) {
    this->z = z;
}
