#ifndef WIREFRAMEMODELDIRECTOR_HPP
#define WIREFRAMEMODELDIRECTOR_HPP

#include <memory>

#include "ModelCreator.hpp"
#include "WireframeModelBuilder.hpp"
#include "WireframeModel.hpp"

namespace WireframeModel {
    class Director : public ModelCreator {
    public:
        explicit Director(std::shared_ptr<Builder> builder);

        virtual std::shared_ptr<Object> create() override;
    protected:
        std::shared_ptr<Builder> builder;
    };
}

#endif //WIREFRAMEMODELDIRECTOR_HPP
