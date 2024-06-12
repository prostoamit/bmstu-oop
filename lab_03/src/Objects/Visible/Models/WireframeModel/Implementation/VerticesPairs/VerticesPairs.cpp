#include "VerticesPairs.hpp"

using namespace WireframeModel;


VerticesPairs::VerticesPairs(const VerticesPairs& other) :
        Implementation(other) {
    for (auto& i : other.edges)
        edges.add(std::make_shared<Edge>(*i));
}

void VerticesPairs::add_edge(std::shared_ptr<Edge> edge) {
    edges.add(edge);
}

Container<std::shared_ptr<Edge>>& VerticesPairs::get_edges() {
    return edges;
}

std::shared_ptr<Implementation> VerticesPairs::clone() {
    auto tmp = std::make_shared<VerticesPairs>(*this);
    return tmp;
}
