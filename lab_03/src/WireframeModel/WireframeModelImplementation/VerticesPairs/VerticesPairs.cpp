#include "VerticesPairs.hpp"

using namespace WireframeModelImplementation;

void VerticesPairs::add_edge(std::shared_ptr<Edge> edge) {
    edges.add(edge);
}

Container<std::shared_ptr<Edge>> &VerticesPairs::get_edges() {
    return edges;
}
