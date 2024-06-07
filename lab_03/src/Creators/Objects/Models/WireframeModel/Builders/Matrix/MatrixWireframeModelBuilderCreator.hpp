#ifndef MATRIXWIREFRAMEMODELBUILDERCREATOR_HPP
#define MATRIXWIREFRAMEMODELBUILDERCREATOR_HPP

#include <memory>

#include "Creators/Objects/Models/WireframeModel/Builders/WireframeModelBuilderCreator.hpp"

namespace WireframeModel {
    class MatrixBuilderCreator : public BuilderCreator {
    public:
        std::shared_ptr<Builder> create(std::shared_ptr<Source> source) override;
    };
}

#endif //MATRIXWIREFRAMEMODELBUILDERCREATOR_HPP
