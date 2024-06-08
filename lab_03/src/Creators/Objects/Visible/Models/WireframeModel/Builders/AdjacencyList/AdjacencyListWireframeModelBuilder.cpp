#include "AdjacencyListWireframeModelBuilder.hpp"

#include <memory>

#include "Objects/Visible/Models/WireframeModel/Implementation/AdjacencyList/AdjacencyList.hpp"

using namespace WireframeModel;

AdjacencyListBuilder::AdjacencyListBuilder(std::shared_ptr<SourceAdapter> source) {
    this->source = source;
    implementation = std::make_shared<AdjacencyList>();
}

void AdjacencyListBuilder::build_vertices() {
    std::optional<std::shared_ptr<Point>> point = source->read_vertex();
    while (point.has_value()) {
        implementation->add_vertex(point.value());
        point = source->read_vertex();
    }

    progress++;
}

void AdjacencyListBuilder::build_edges() {
    std::optional<std::shared_ptr<Edge>> edge = source->read_edge();
    while (edge.has_value()) {
        implementation->add_edge(edge.value());
        edge = source->read_edge();
    }

    progress++;
}
