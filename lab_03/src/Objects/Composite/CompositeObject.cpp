#include "CompositeObject.hpp"


bool CompositeObject::is_composite() const {
    return true;
}

void CompositeObject::add(std::shared_ptr<Object> object) {
    container[object->get_id()] = object;
}

void CompositeObject::remove(Object::iterator iterator) {
    container.erase(iterator);
}

Object::iterator CompositeObject::begin() {
    return container.begin();
}

Object::iterator CompositeObject::end() {
    return container.end();
}

void CompositeObject::accept(std::shared_ptr<Visitor> visitor) {
    for (auto& object : container)
        object.second->accept(visitor);
}

CompositeObject::CompositeObject(const CompositeObject &other) {

}

CompositeObject::CompositeObject() {
    container.clear();
}
