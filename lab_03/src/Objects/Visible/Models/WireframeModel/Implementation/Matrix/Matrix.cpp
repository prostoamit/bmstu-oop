#include "Matrix.hpp"

#include <algorithm>

using namespace WireframeModel;

void Matrix::add_edge(std::shared_ptr<Edge> edge) {
    while (vertices.size() > matrix.size()) {
        matrix.resize(vertices.size());
        for (auto& i : matrix)
            i.resize(vertices.size());
    }

    size_t position_1 = edge->get_vertex_1_position();
    size_t position_2 = edge->get_vertex_2_position();

    matrix[position_1][position_2] = true;
    matrix[position_2][position_1] = true;
}

Container<std::shared_ptr<Edge>>& Matrix::get_edges() {
    static Container<std::shared_ptr<Edge>> edges_container;
    edges_container.clear();

    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = i + 1; j < matrix.size(); j++)
            if (matrix[i][j]) {
                auto edge = std::make_shared<Edge>(i, j);

                edges_container.add(edge);
            }
    }

    return edges_container;
}

Matrix::Matrix(Container<std::shared_ptr<Point>>& _vertices, Container<std::shared_ptr<Edge>>& _edges) {
    for (auto& i : _vertices)
        this->vertices.push_back(i);

    for (auto& i : _edges)
        this->add_edge(i);
}
