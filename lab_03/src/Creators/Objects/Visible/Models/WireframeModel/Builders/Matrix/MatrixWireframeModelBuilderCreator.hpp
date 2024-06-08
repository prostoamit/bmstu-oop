#ifndef MATRIXWIREFRAMEMODELBUILDERCREATOR_HPP
#define MATRIXWIREFRAMEMODELBUILDERCREATOR_HPP

#include <memory>

#include "WireframeModelBuilderCreator.hpp"

namespace WireframeModel {
    class MatrixBuilderCreator : public BuilderCreator {
    public:
        std::shared_ptr<Builder> create(std::shared_ptr<SourceAdapter> source) override;
    };
}

#endif //MATRIXWIREFRAMEMODELBUILDERCREATOR_HPP
