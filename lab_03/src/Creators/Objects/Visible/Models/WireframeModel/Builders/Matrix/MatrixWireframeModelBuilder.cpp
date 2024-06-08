#include "MatrixWireframeModelBuilder.hpp"

#include <memory>

#include "Objects/Visible/Models/WireframeModel/Implementation/Matrix/Matrix.hpp"

using namespace WireframeModel;

MatrixBuilder::MatrixBuilder(std::shared_ptr<SourceAdapter> source) {
    this->source = source;
    implementation = std::make_shared<Matrix>();
}

void MatrixBuilder::build_vertices() {
    std::optional<std::shared_ptr<Point>> point = source->read_vertex();
    while (point.has_value()) {
        implementation->add_vertex(point.value());
        point = source->read_vertex();
    }

    progress++;
}

void MatrixBuilder::build_edges() {
    std::optional<std::shared_ptr<Edge>> edge = source->read_edge();
    while (edge.has_value()) {
        implementation->add_edge(edge.value());
        edge = source->read_edge();
    }

    progress++;
}