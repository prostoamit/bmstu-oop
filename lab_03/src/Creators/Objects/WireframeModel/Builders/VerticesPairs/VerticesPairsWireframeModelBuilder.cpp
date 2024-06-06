#include "VerticesPairsWireframeModelBuilder.hpp"

#include <memory>

#include "Objects/Visible/Models/WireframeModel/Implementation/VerticesPairs/VerticesPairs.hpp"

using namespace WireframeModel;

VerticesPairsBuilder::VerticesPairsBuilder(std::shared_ptr<Source> source) :
        Builder(source) {
    implementation = std::make_shared<VerticesPairs>();
}
