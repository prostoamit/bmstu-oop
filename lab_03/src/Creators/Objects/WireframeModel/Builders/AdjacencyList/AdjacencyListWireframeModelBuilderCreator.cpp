#include "AdjacencyListWireframeModelBuilderCreator.hpp"

#include "Creators/Objects/WireframeModel/Builders/AdjacencyList/AdjacencyListWireframeModelBuilder.hpp"

std::shared_ptr<WireframeModel::Builder>
WireframeModel::AdjacencyListBuilderCreator::create(std::shared_ptr<Source> source) {
    return std::make_shared<AdjacencyListBuilder>(source);
}
