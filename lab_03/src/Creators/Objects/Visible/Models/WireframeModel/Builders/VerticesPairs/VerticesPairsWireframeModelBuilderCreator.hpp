#ifndef VERTICESPAIRSWIREFRAMEMODELBUILDERCREATOR_HPP
#define VERTICESPAIRSWIREFRAMEMODELBUILDERCREATOR_HPP

#include <memory>

#include "WireframeModelBuilderCreator.hpp"

namespace WireframeModel {
    class VerticesPairsBuilderCreator : public BuilderCreator {
    public:
        std::shared_ptr<Builder> create(std::shared_ptr<SourceAdapter> source) override;
    };
}

#endif //VERTICESPAIRSWIREFRAMEMODELBUILDERCREATOR_HPP
