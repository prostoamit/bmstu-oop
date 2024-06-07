#include "MatrixWireframeModelBuilder.hpp"

#include <memory>

#include "Objects/Visible/Models/WireframeModel/Implementation/Matrix/Matrix.hpp"

using namespace WireframeModel;

MatrixBuilder::MatrixBuilder(std::shared_ptr<Source> source) :
        Builder(source) {
    implementation = std::make_shared<Matrix>();
}
