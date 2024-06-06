#include "Scale.hpp"

using namespace Transformers;

Scale::Scale(double x_coefficient, double y_coefficient, double z_coefficient) {
    matrix->prepare_scale(x_coefficient, y_coefficient, z_coefficient);
}
