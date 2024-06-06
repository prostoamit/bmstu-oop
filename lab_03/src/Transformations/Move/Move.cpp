#include "Move.hpp"

using namespace Transformers;

Move::Move(double x_delta, double y_delta, double z_delta) {
    matrix->prepare_move(x_delta, y_delta, z_delta);
}
