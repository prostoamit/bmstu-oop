#include "Matrix.hpp"

#include <algorithm>

using namespace WireframeModelImplementation;

void Matrix::add_edge(std::shared_ptr<Edge> edge) {
    while (vertices.size() > matrix.size()) {
        matrix.resize(vertices.size());
        for (auto &i: matrix)
            i.resize(vertices.size());
    }

    auto iterator_1 = std::find(vertices.begin(), vertices.end(), edge->get_vertex_1().lock());
    size_t position_1 = iterator_1 - vertices.begin();
    auto iterator_2 = std::find(vertices.begin(), vertices.end(), edge->get_vertex_2().lock());
    size_t position_2 = iterator_2 - vertices.begin();

    matrix[position_1][position_2] = true;
    matrix[position_2][position_1] = true;
}

Container<std::shared_ptr<Edge>> &Matrix::get_edges() {
    static Container<std::shared_ptr<Edge>> edges_container;
    edges_container.clear();

    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = i + 1; j < matrix.size(); j++)
            if (matrix[i][j]) {
                auto edge = std::make_shared<Edge>(
                        std::weak_ptr<Point>(vertices[i]),
                        std::weak_ptr<Point>(vertices[j])
                                        );

                edges_container.add(edge);
            }
    }

    return edges_container;
}
