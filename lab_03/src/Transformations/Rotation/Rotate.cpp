#include "Rotate.hpp"

#include <cmath>

using namespace Transformers;

Rotate::Rotate(double x_axis_angle, double y_axis_angle, double z_axis_angle) :
    x_axis_angle(x_axis_angle),
    y_axis_angle(y_axis_angle),
    z_axis_angle(z_axis_angle)
{}

#define PI acos(-1.0)

inline double
to_rad(double angle) {
    return angle * (PI / 180.0);
}

static void
point_rotate_x(Point& point, double angle) {
    double r_cos = cos(to_rad(angle));
    double r_sin = sin(to_rad(angle));

    double y = point.get_y();

    point.set_y(point.get_y() * r_cos + point.get_z() * r_sin);
    point.set_z(-y * r_sin + point.get_z() * r_cos);
}

static void
point_rotate_y(Point& point, double angle) {
    double r_cos = cos(to_rad(angle));
    double r_sin = sin(to_rad(angle));

    double x = point.get_x();

    point.set_x(point.get_x() * r_cos + point.get_z() * r_sin);
    point.set_z(-x * r_sin + point.get_z() * r_cos);
}

static void
point_rotate_z(Point& point, double angle) {
    double r_cos = cos(to_rad(angle));
    double r_sin = sin(to_rad(angle));

    double x = point.get_x();

    point.set_x(point.get_x() * r_cos + point.get_y() * r_sin);
    point.set_y(-x * r_sin + point.get_y() * r_cos);
}

void Rotate::transform(Point &point) {
    point_rotate_x(point, x_axis_angle);
    point_rotate_y(point, y_axis_angle);
    point_rotate_z(point, z_axis_angle);
}