#include "Move.hpp"

using namespace Transformers;

Move::Move(double x_delta, double y_delta, double z_delta) :
    x_delta(x_delta),
    y_delta(y_delta),
    z_delta(z_delta)
{}

void Move::transform(Point &point) {
    point.set_x(point.get_x() + x_delta);
    point.set_y(point.get_y() + y_delta);
    point.set_z(point.get_z() + z_delta);
}
