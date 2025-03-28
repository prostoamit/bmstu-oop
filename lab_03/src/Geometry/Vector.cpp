#include "Vector.hpp"

#include <cmath>

Vector::Vector(double x, double y, double z) :
        x(x),
        y(y),
        z(z) {}

double Vector::get_x() const {
    return x;
}

void Vector::set_x(double _x) {
    this->x = _x;
}

double Vector::get_y() const {
    return y;
}

void Vector::set_y(double _y) {
    this->y = _y;
}

double Vector::get_z() const {
    return z;
}

void Vector::set_z(double _z) {
    this->z = _z;
}

double Vector::length() const{
    return sqrt(x * x + y * y + z * z);
}

void Vector::normalize() {
    double len = length();

    x /= len;
    y /= len;
    z /= len;
}

double Vector::scalar_multiply(const Vector& other) const {
    return this->x * other.x + this->y * other.y + this->z * other.z;
}

double Vector::angle(const Vector& other) const {
    double scalar_product = scalar_multiply(other);
    double length_1 = length();
    double length_2 = other.length();

    double angle_cos = scalar_product / (length_1 * length_2);

    return acos(angle_cos);
}

