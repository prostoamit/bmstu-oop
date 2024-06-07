#include "WireframeModelCreator.hpp"

WireframeModel::Creator::Creator(std::shared_ptr<Builder> builder) :
        builder(builder) {}

std::shared_ptr<WireframeModel::WireframeModel> WireframeModel::Creator::create() {
    builder->build_vertices();
    builder->build_edges();

    return builder->get();
}
