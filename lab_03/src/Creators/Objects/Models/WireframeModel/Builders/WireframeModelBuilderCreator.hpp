#ifndef WIREFRAMEMODELBUILDERCREATOR_HPP
#define WIREFRAMEMODELBUILDERCREATOR_HPP

#include <memory>

#include "WireframeModelBuilder.hpp"
#include "Objects/Visible/Models/WireframeModel/Sources/WireframeModelSource.hpp"

namespace WireframeModel {
    class BuilderCreator {
    public:
        virtual std::shared_ptr<Builder> create(std::shared_ptr<Source> source) = 0;
    };
}

#endif //WIREFRAMEMODELBUILDERCREATOR_HPP
