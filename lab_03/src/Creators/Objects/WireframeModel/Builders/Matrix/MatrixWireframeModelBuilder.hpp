#ifndef MATRIXWIREFRAMEMODELBUILDER_HPP
#define MATRIXWIREFRAMEMODELBUILDER_HPP

#include <memory>

#include "Creators/Objects/WireframeModel/Builders/WireframeModelBuilder.hpp"
#include "Objects/Visible/Models/WireframeModel/Sources/WireframeModelSource.hpp"

namespace WireframeModel {
    class MatrixBuilder : public Builder {
    public:
        MatrixBuilder(std::shared_ptr<Source> source);
    };
}

#endif //MATRIXWIREFRAMEMODELBUILDER_HPP
