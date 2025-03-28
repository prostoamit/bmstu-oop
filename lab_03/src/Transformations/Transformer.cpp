#include "Transformer.hpp"

using namespace Transformers;

Transformer::Transformer() {
    matrix = std::make_shared<TransformationMatrix>();
}

void Transformer::transform(std::shared_ptr<Point> point) const {
    matrix->apply(point);
}

std::shared_ptr<Point> Transformer::transform_get(std::shared_ptr<Point> point) const {
    return matrix->apply_get(point);
}

Transformer Transformer::operator*(const Transformer& other) const {
    Transformer tmp(*this);

    *tmp.matrix *= *other.matrix;

    return tmp;
}

Transformer& Transformer::operator*=(const Transformers::Transformer& other) {
    *matrix *= *other.matrix;

    return *this;
}
