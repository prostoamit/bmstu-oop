#ifndef WIREFRAMEMODEL_HPP
#define WIREFRAMEMODEL_HPP

#include <memory>

#include "Model.hpp"
#include "WireframeModelImplementation.hpp"

class WireframeModel : Object {
public:
    WireframeModel(std::shared_ptr<WireframeModelImplementation> implementation);

    virtual void accept(std::shared_ptr<Visitor> visitor) override;


private:
    std::shared_ptr<WireframeModelImplementation> _implementation;
};


#endif //WIREFRAMEMODEL_HPP
