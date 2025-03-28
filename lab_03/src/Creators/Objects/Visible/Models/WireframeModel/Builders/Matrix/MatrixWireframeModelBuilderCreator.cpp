#include "MatrixWireframeModelBuilderCreator.hpp"

#include "MatrixWireframeModelBuilder.hpp"

using namespace WireframeModel;

std::shared_ptr<Builder>
MatrixBuilderCreator::create(std::shared_ptr<SourceAdapter> source) {
    return std::make_shared<MatrixBuilder>(source);
}
