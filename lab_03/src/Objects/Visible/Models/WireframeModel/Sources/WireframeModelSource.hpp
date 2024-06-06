#ifndef WIREFRAMEMODELSOURCE_HPP
#define WIREFRAMEMODELSOURCE_HPP

#include <memory>
#include <optional>

#include "Common/Container.hpp"
#include "Objects/Visible/Models/WireframeModel/Implementation/Edge.hpp"
#include "Geometry/Point.hpp"

namespace WireframeModel {
    class Source {
    public:
        virtual ~Source() = default;

        virtual std::optional<std::shared_ptr<Point>> read_vertex() = 0;
        virtual std::optional<std::shared_ptr<Edge>> read_edge() = 0;
    };
}

#endif //WIREFRAMEMODELSOURCE_HPP
