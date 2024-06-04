#ifndef WIREFRAMEMODEL_HPP
#define WIREFRAMEMODEL_HPP

#include <memory>

#include "Model.hpp"
#include "WireframeModelImplementation/Implementation.hpp"

class TransformVisitor;

class WireframeModel : public Model {
public:
    WireframeModel(std::shared_ptr<WireframeModelImplementation::Implementation> implementation);

    virtual void accept(std::shared_ptr<Visitor> visitor) override;

    friend TransformVisitor;


private:
    std::shared_ptr<WireframeModelImplementation::Implementation> _implementation;
};


#endif //WIREFRAMEMODEL_HPP
