#include "WireframeModel.hpp"

#include <Visitor.hpp>
#include <utility>

WireframeModel::WireframeModel(std::shared_ptr<WireframeModelImplementation::Implementation> implementation):
    _implementation(std::move(implementation))
    {}

void WireframeModel::accept(std::shared_ptr<Visitor> visitor) {
    visitor->visit(*this);
}