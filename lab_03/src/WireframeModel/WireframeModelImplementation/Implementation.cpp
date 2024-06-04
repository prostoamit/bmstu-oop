#include "WireframeModelImplementation/Implementation.hpp"

using namespace WireframeModelImplementation;

void Implementation::add_vertex(std::shared_ptr<Point> vertex) {
    vertices.push_back(vertex);
}

Container<std::shared_ptr<Point>> &Implementation::get_vertices() {
    static Container<std::shared_ptr<Point>> vertices_container;
    vertices_container.clear();

    for (auto& i : vertices)
        vertices_container.add(i);

    return vertices_container;
}
