#include "RotateCreator.hpp"

#include "Transformations/Rotation/Rotate.hpp"

using namespace Transformers;

std::shared_ptr<Transformer> RotateCreator::create(double x_axis_angle, double y_axis_angle, double z_axis_angle) {
    return std::make_shared<Rotate>(x_axis_angle, y_axis_angle, z_axis_angle);
}
