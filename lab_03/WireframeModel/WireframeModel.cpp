#include "WireframeModel.hpp"

WireframeModel::WireframeModel(std::shared_ptr<WireframeModelImplementation> implementation) : _implementation(implementation) {};

void WireframeModel::accept(std::shared_ptr<Visitor> visitor) {
    ;
}