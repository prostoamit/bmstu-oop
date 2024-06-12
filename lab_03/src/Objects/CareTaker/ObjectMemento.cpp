#include "ObjectMemento.hpp"


ObjectMemento::ObjectMemento(std::shared_ptr<Object> object) :
        object(object) {}

void ObjectMemento::set_object(std::shared_ptr<Object> _object) {
    object = _object;
}

std::shared_ptr<Object> ObjectMemento::get_object() {
    return object;
}