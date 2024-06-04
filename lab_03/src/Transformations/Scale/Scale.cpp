#include "Scale.hpp"

using namespace Transformers;

Scale::Scale(double x_coefficient, double y_coefficient, double z_coefficient) :
    x_coefficient(x_coefficient),
    y_coefficient(y_coefficient),
    z_coefficient(z_coefficient)
{}

void Scale::transform(Point &point) {
    point.set_x(point.get_x() * x_coefficient);
    point.set_y(point.get_y() * y_coefficient);
    point.set_z(point.get_z() * z_coefficient);
}
