#include "AdjacencyListWireframeModelBuilder.hpp"

#include <memory>

#include "Objects/Visible/Models/WireframeModel/Implementation/AdjacencyList/AdjacencyList.hpp"


WireframeModel::AdjacencyListBuilder::AdjacencyListBuilder(std::shared_ptr<Source> source) :
        Builder(source) {
    implementation = std::make_shared<AdjacencyList>();
}
