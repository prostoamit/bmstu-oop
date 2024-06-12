#include "WireframeModelImplementation.hpp"

using namespace WireframeModel;

Implementation::Implementation(const Implementation& other) {
    for (auto& i : other.vertices)
        vertices.push_back(std::make_shared<Point>(*i));
}

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
