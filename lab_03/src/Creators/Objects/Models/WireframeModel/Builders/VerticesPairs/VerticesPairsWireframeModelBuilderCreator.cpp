#include "VerticesPairsWireframeModelBuilderCreator.hpp"

#include "VerticesPairsWireframeModelBuilder.hpp"

using namespace WireframeModel;

std::shared_ptr<Builder> VerticesPairsBuilderCreator::create(std::shared_ptr<Source> source) {
    return std::make_shared<VerticesPairsBuilder>(source);
}
