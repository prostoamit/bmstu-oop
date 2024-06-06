#ifndef WIREFRAMEMODEL_HPP
#define WIREFRAMEMODEL_HPP

#include <memory>

#include "Objects/Visible/Models/Model.hpp"
#include "Objects/Visible/Models/WireframeModel/Implementation/WireframeModelImplementation.hpp"

class TransformVisitor;
class DrawVisitor;

namespace WireframeModel {
    class WireframeModel : public Model {
    public:
        WireframeModel(std::shared_ptr<Implementation> implementation);
        virtual void accept(std::shared_ptr<Visitor> visitor) override;

        friend TransformVisitor;
        friend DrawVisitor;

    private:
        std::shared_ptr<Implementation> _implementation;
    };
}

#endif //WIREFRAMEMODEL_HPP
