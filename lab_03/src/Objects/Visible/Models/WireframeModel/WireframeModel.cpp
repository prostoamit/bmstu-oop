#include "WireframeModel.hpp"

#include "Visitors/Visitor.hpp"

#include "ObjectMemento.hpp"


WireframeModel::WireframeModel::WireframeModel(std::shared_ptr<Implementation> implementation) :
        _implementation(implementation) {

}

WireframeModel::WireframeModel::WireframeModel(const WireframeModel& other) :
        _implementation(other._implementation->clone()) {

}

void WireframeModel::WireframeModel::accept(std::shared_ptr<Visitor> visitor) {
    visitor->visit(*this);
}

std::shared_ptr<Object> WireframeModel::WireframeModel::clone() const {
    return std::make_shared<WireframeModel>(*this);
}

void WireframeModel::WireframeModel::restore_memento(std::shared_ptr<ObjectMemento> memento) {
    auto model = std::dynamic_pointer_cast<WireframeModel>(memento->get_object());
    this->_implementation = model->_implementation->clone();
}
