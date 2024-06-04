#ifndef WIREFRAMEMODELIMPLEMENTATIONADJACENCYLIST_HPP
#define WIREFRAMEMODELIMPLEMENTATIONADJACENCYLIST_HPP

#include <memory>
#include <vector>
#include <map>

#include "WireframeModelImplementation/Implementation.hpp"

namespace WireframeModelImplementation {
    class AdjacencyList : public Implementation {
    public:
        virtual void add_edge(std::shared_ptr<Edge> edge) override;

        virtual Container<std::shared_ptr<Edge>> & get_edges() override;
    private:
        std::map<size_t, std::vector<size_t>> adjacency_list;
    };
}

#endif //WIREFRAMEMODELIMPLEMENTATIONADJACENCYLIST_HPP
