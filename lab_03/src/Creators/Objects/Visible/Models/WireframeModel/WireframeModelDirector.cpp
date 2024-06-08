#include "WireframeModelDirector.hpp"

WireframeModel::Director::Director(std::shared_ptr<Builder> builder) :
        builder(builder) {}

std::shared_ptr<Object> WireframeModel::Director::create() {
    builder->build_vertices();
    builder->build_edges();

    return builder->get();
}
