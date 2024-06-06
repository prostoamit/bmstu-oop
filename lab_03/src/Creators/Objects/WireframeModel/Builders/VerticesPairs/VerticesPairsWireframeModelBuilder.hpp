#ifndef VERTICESPAIRSWIREFRAMEMODELBUILDER_HPP
#define VERTICESPAIRSWIREFRAMEMODELBUILDER_HPP

#include <memory>

#include "Creators/Objects/WireframeModel/Builders/WireframeModelBuilder.hpp"
#include "Objects/Visible/Models/WireframeModel/Sources/WireframeModelSource.hpp"

namespace WireframeModel {
    class VerticesPairsBuilder : public Builder {
    public:
        VerticesPairsBuilder(std::shared_ptr<Source> source);
    };
}


#endif //VERTICESPAIRSWIREFRAMEMODELBUILDER_HPP
