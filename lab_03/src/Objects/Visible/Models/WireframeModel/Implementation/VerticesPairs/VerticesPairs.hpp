#ifndef WIREFRAMEMODELIMPLEMENTATIONVERTICESPAIRS_HPP
#define WIREFRAMEMODELIMPLEMENTATIONVERTICESPAIRS_HPP

#include "Objects/Visible/Models/WireframeModel/Implementation/WireframeModelImplementation.hpp"

namespace WireframeModel {
    class VerticesPairs : public Implementation {
    public:
        VerticesPairs() = default;
        VerticesPairs(const VerticesPairs& other);
        ~VerticesPairs() = default;

        virtual void add_edge(std::shared_ptr<Edge> edge) override;

        virtual Container<std::shared_ptr<Edge>> &get_edges() override;

        virtual std::shared_ptr<Implementation> clone() override;

    protected:
        Container<std::shared_ptr<Edge>> edges;
    };
}

#endif //WIREFRAMEMODELIMPLEMENTATIONVERTICESPAIRS_HPP
