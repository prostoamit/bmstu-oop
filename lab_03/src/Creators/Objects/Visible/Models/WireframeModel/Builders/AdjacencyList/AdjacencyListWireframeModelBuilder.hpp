#ifndef ADJACENCYLISTWIREFRAMEMODELBUILDER_HPP
#define ADJACENCYLISTWIREFRAMEMODELBUILDER_HPP

#include <memory>

#include "WireframeModelBuilder.hpp"
#include "WireframeModelSourceAdapter.hpp"

namespace WireframeModel {
    class AdjacencyListBuilder : public Builder {
    public:
        explicit AdjacencyListBuilder(std::shared_ptr<SourceAdapter> source);

        virtual void build_edges() override;
        virtual void build_vertices() override;
    };
}

#endif //ADJACENCYLISTWIREFRAMEMODELBUILDER_HPP
