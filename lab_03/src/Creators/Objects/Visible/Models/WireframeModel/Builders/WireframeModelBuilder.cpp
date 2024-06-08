#include "WireframeModelBuilder.hpp"

std::shared_ptr<Object> WireframeModel::Builder::get() {
    return std::make_shared<WireframeModel>(implementation);
}
