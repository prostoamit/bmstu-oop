#include "Point2D.hpp"

Point2D::Point2D() :
    _x(0.0),
    _y(0.0)
{}

Point2D::Point2D(double x, double y) :
    _x(x),
    _y(y)
{}

double Point2D::get_x() const {
    return _x;
}

void Point2D::set_x(double x) {
    _x = x;
}

double Point2D::get_y() const {
    return _y;
}

void Point2D::set_y(double y) {
    _y = y;
}
