#ifndef WIREFRAMEMODELSOURCEADAPTER_HPP
#define WIREFRAMEMODELSOURCEADAPTER_HPP

#include <memory>
#include <optional>

#include "Container.hpp"
#include "Edge.hpp"
#include "Point.hpp"
#include "Source.hpp"

namespace WireframeModel {
    class SourceAdapter {
    public:
        virtual ~SourceAdapter() = default;

        virtual std::optional<std::shared_ptr<Point>> read_vertex() = 0;
        virtual std::optional<std::shared_ptr<Edge>> read_edge() = 0;
    private:
        std::shared_ptr<Source> source;
    };
}

#endif //WIREFRAMEMODELSOURCEADAPTER_HPP
