#ifndef ADJACENCYLISTWIREFRAMEMODELBUILDERCREATOR_HPP
#define ADJACENCYLISTWIREFRAMEMODELBUILDERCREATOR_HPP

#include <memory>

#include "Creators/Objects/Models/WireframeModel/Builders/WireframeModelBuilderCreator.hpp"

namespace WireframeModel {
    class AdjacencyListBuilderCreator : public BuilderCreator {
    public:
        std::shared_ptr<Builder> create(std::shared_ptr<Source> source) override;
    };
}

#endif //ADJACENCYLISTWIREFRAMEMODELBUILDERCREATOR_HPP
