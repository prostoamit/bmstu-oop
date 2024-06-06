#include "MatrixWireframeModelBuilderCreator.hpp"

#include "Creators/Objects/WireframeModel/Builders/Matrix/MatrixWireframeModelBuilder.hpp"

using namespace WireframeModel;

std::shared_ptr<Builder>
MatrixBuilderCreator::create(std::shared_ptr<Source> source) {
    return std::make_shared<MatrixBuilder>(source);
}
