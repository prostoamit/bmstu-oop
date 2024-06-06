#include "WireframeModelBuilder.hpp"

WireframeModel::Builder::Builder(std::shared_ptr<Source> source) :
        progress(0),
        source(source) {}

std::shared_ptr<WireframeModel::WireframeModel> WireframeModel::Builder::get() {
    return std::make_shared<WireframeModel>(implementation);
}

void WireframeModel::Builder::build_vertices() {
    std::optional<std::shared_ptr<Point>> point = source->read_vertex();
    while (point.has_value()) {
        implementation->add_vertex(point.value());
        point = source->read_vertex();
    }

    progress++;
}

void WireframeModel::Builder::build_edges() {
    std::optional<std::shared_ptr<Edge>> edge = source->read_edge();
    while (edge.has_value()) {
        implementation->add_edge(edge.value());
        edge = source->read_edge();
    }

    progress++;
}
