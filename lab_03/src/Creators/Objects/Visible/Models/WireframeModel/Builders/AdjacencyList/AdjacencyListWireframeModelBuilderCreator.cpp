#include "AdjacencyListWireframeModelBuilderCreator.hpp"

#include "AdjacencyListWireframeModelBuilder.hpp"

std::shared_ptr<WireframeModel::Builder>
WireframeModel::AdjacencyListBuilderCreator::create(std::shared_ptr<SourceAdapter> source) {
    return std::make_shared<AdjacencyListBuilder>(source);
}
