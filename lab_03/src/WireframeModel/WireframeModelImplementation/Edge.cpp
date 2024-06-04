#include "Edge.hpp"

#include <utility>

Edge::Edge(std::weak_ptr<Point> vertex_1, std::weak_ptr<Point> vertex_2) :
        vertex_1(std::move(vertex_1)),
        vertex_2(std::move(vertex_2)) {}

Edge::Edge(const Edge &other) :
        vertex_1(other.vertex_1),
        vertex_2(other.vertex_2) {}

std::weak_ptr<Point> Edge::get_vertex_1() const {
    return vertex_1;
}

void Edge::set_vertex_1(std::weak_ptr<Point> vertex) {
    vertex_1 = std::move(vertex);
}

std::weak_ptr<Point> Edge::get_vertex_2() const {
    return vertex_2;
}

void Edge::set_vertex_2(std::weak_ptr<Point> vertex) {
    vertex_2 = std::move(vertex);
}
