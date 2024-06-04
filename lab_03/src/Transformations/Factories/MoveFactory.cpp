#include "MoveFactory.hpp"

MoveFactory::MoveFactory(double x_delta, double y_delta, double z_delta) :
    x_delta(x_delta),
    y_delta(y_delta),
    z_delta(z_delta)
{}

std::unique_ptr<Transformers::Transformer> MoveFactory::create() const {
    return std::make_unique<Transformers::Move>(x_delta, y_delta, z_delta);
}
