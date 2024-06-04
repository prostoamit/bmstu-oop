#ifndef EDGE_HPP
#define EDGE_HPP

#include <memory>

#include "Point.hpp"

class Edge {
public:
    Edge(std::weak_ptr<Point> vertex_1, std::weak_ptr<Point> vertex_2);
    Edge(const Edge& other);

    std::weak_ptr<Point> get_vertex_1() const;
    void set_vertex_1(std::weak_ptr<Point> vertex);

    std::weak_ptr<Point> get_vertex_2() const;
    void set_vertex_2(std::weak_ptr<Point> vertex);

private:
    std::weak_ptr<Point> vertex_1;
    std::weak_ptr<Point> vertex_2;
};


#endif //EDGE_HPP
