#include "AdjacencyList.hpp"

#include <algorithm>

using namespace WireframeModelImplementation;

void AdjacencyList::add_edge(std::shared_ptr<Edge> edge) {
    while (vertices.size() > adjacency_list.size()) {
        adjacency_list.insert({adjacency_list.size(), std::vector<size_t>()});
    }

    size_t position_1 = edge->get_vertex_1_position();
    size_t position_2 = edge->get_vertex_2_position();

    adjacency_list[position_1].push_back(position_2);
}

Container<std::shared_ptr<Edge>> &AdjacencyList::get_edges() {
    static Container<std::shared_ptr<Edge>> edges_container;
    edges_container.clear();

    for (auto const& [source, destinations] : adjacency_list) {
        for (auto& destination : destinations) {
            auto edge = std::make_shared<Edge>(source, destination);

            edges_container.add(edge);
        }
    }

    return edges_container;
}