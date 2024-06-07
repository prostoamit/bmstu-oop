#ifndef WIREFRAMEMODELCREATOR_HPP
#define WIREFRAMEMODELCREATOR_HPP

#include <memory>

#include "Creators/Objects/Models/WireframeModel/Builders/WireframeModelBuilder.hpp"
#include "Objects/Visible/Models/WireframeModel/WireframeModel.hpp"

namespace WireframeModel {
    class Creator {
    public:
        explicit Creator(std::shared_ptr<Builder> builder);

        std::shared_ptr<WireframeModel> create();
    protected:
        std::shared_ptr<Builder> builder;
    };
}

#endif //WIREFRAMEMODELCREATOR_HPP
