#include "Rotate.hpp"

#include <cmath>

using namespace Transformers;

#define PI acos(-1.0)

inline double
to_rad(double angle) {
    return angle * (PI / 180.0);
}

Rotate::Rotate(double x_axis_angle, double y_axis_angle, double z_axis_angle) {
    double x_rad = to_rad(x_axis_angle);
    double y_rad = to_rad(y_axis_angle);
    double z_rad = to_rad(z_axis_angle);

    matrix->prepare_rotate(x_rad, y_rad, z_rad);
}
