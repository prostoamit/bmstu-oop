#ifndef EDGE_HPP
#define EDGE_HPP

#include <memory>

#include "Geometry/Point.hpp"

class Edge {
public:
    Edge(size_t vertex_1_position, size_t vertex_2_position);
    Edge(const Edge& other);

    size_t get_vertex_1_position() const;

    size_t get_vertex_2_position() const;

private:
    size_t vertex_1_position;
    size_t vertex_2_position;
};


#endif //EDGE_HPP
