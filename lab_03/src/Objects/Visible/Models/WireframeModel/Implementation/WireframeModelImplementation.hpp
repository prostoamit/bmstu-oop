#ifndef WIREFRAMEMODELIMPLEMENTATION_HPP
#define WIREFRAMEMODELIMPLEMENTATION_HPP

#include <vector>
#include <memory>

#include "Geometry/Point.hpp"
#include "Edge.hpp"

#include "Common/Container.hpp"

namespace WireframeModel {
    class Implementation {
    public:
        virtual ~Implementation() = default;

        virtual void add_vertex(std::shared_ptr<Point> vertex);

        virtual Container<std::shared_ptr<Point>> &get_vertices();

        virtual void add_edge(std::shared_ptr<Edge> edge) = 0;

        virtual Container<std::shared_ptr<Edge>> &get_edges() = 0;

    protected:
        std::vector<std::shared_ptr<Point>> vertices;
    };
}
#endif //WIREFRAMEMODELIMPLEMENTATION_HPP
