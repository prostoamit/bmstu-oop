#include "MoveCreator.hpp"

#include "Transformations/Move/Move.hpp"

using namespace Transformers;

std::shared_ptr<Transformer> MoveCreator::create(double x_delta, double y_delta, double z_delta) {
    return std::make_shared<Move>(x_delta, y_delta, z_delta);
}
