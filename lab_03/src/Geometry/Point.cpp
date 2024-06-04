#include "Point.hpp"

Point::Point(double x, double y, double z) :
    _x(x),
    _y(y),
    _z(z)
{}

Point::Point(const Point &other) :
    _x(other._x),
    _y(other._y),
    _z(other._z)
{}

double Point::get_x() const {
    return _x;
}

void Point::set_x(double x) {
    _x = x;
}

double Point::get_y() const {
    return _y;
}

void Point::set_y(double y) {
    _y = y;
}

double Point::get_z() const {
    return _z;
}

void Point::set_z(double z) {
    _z = z;
}
