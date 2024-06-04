#include "Edge.hpp"

#include <utility>

Edge::Edge(size_t vertex_1_position, size_t vertex_2_position) :
        vertex_1_position(vertex_1_position),
        vertex_2_position(vertex_2_position)
{}

Edge::Edge(const Edge& other) :
        vertex_1_position(other.vertex_1_position),
        vertex_2_position(other.vertex_2_position)
{}

size_t Edge::get_vertex_1_position() const {
    return vertex_1_position;
}

size_t Edge::get_vertex_2_position() const {
    return vertex_2_position;
}