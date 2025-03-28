#ifndef WIREFRAMEMODELBUILDERCREATOR_HPP
#define WIREFRAMEMODELBUILDERCREATOR_HPP

#include <memory>

#include "WireframeModelBuilder.hpp"
#include "WireframeModelSourceAdapter.hpp"

namespace WireframeModel {
    class BuilderCreator {
    public:
        virtual ~BuilderCreator() = default;

        virtual std::shared_ptr<Builder> create(std::shared_ptr<SourceAdapter> source) = 0;
    };
}

#endif //WIREFRAMEMODELBUILDERCREATOR_HPP
