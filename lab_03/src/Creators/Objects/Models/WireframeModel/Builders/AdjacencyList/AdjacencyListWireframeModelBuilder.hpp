#ifndef ADJACENCYLISTWIREFRAMEMODELBUILDER_HPP
#define ADJACENCYLISTWIREFRAMEMODELBUILDER_HPP

#include <memory>

#include "Creators/Objects/Models/WireframeModel/Builders/WireframeModelBuilder.hpp"
#include "Objects/Visible/Models/WireframeModel/Sources/WireframeModelSource.hpp"

namespace WireframeModel {
    class AdjacencyListBuilder : public Builder {
    public:
        explicit AdjacencyListBuilder(std::shared_ptr<Source> source);
    };
}

#endif //ADJACENCYLISTWIREFRAMEMODELBUILDER_HPP
