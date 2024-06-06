#ifndef VERTICESPAIRSWIREFRAMEMODELBUILDERCREATOR_HPP
#define VERTICESPAIRSWIREFRAMEMODELBUILDERCREATOR_HPP

#include <memory>

#include "Creators/Objects/WireframeModel/Builders/WireframeModelBuilderCreator.hpp"

namespace WireframeModel {
    class VerticesPairsBuilderCreator : public BuilderCreator {
    public:
        std::shared_ptr<Builder> create(std::shared_ptr<Source> source) override;
    };
}

#endif //VERTICESPAIRSWIREFRAMEMODELBUILDERCREATOR_HPP
