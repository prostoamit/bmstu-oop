#include "ScaleCreator.hpp"

#include "Transformations/Scale/Scale.hpp"

using namespace Transformers;

std::shared_ptr<Transformer> ScaleCreator::create(double x_coefficient, double y_coefficient, double z_coefficient) {
    return std::make_shared<Scale>(x_coefficient, y_coefficient, z_coefficient);
}
