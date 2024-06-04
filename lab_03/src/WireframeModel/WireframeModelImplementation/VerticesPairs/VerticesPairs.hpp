#ifndef WIREFRAMEMODELIMPLEMENTATIONVERTICESPAIRS_HPP
#define WIREFRAMEMODELIMPLEMENTATIONVERTICESPAIRS_HPP

#include "WireframeModelImplementation/Implementation.hpp"

namespace WireframeModelImplementation {
    class VerticesPairs : public Implementation {
    public:
        virtual void add_edge(std::shared_ptr<Edge> edge) override;

        virtual Container<std::shared_ptr<Edge>> &get_edges() override;

    protected:
        Container<std::shared_ptr<Edge>> edges;
    };
}

#endif //WIREFRAMEMODELIMPLEMENTATIONVERTICESPAIRS_HPP
