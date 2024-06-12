#include "ObjectComposite.hpp"

ObjectComposite::ObjectComposite(const ObjectComposite& other) {
    for (auto& [key, value] : other.container)
        container[key] = value->clone();
}

bool ObjectComposite::is_composite() const {
    return true;
}

void ObjectComposite::add(std::shared_ptr<Object> object) {
    container[object->get_id()] = object;
}

void ObjectComposite::remove(Object::iterator iterator) {
    container.erase(iterator);
}

Object::iterator ObjectComposite::begin() {
    return container.begin();
}

Object::iterator ObjectComposite::end() {
    return container.end();
}

void ObjectComposite::accept(std::shared_ptr<Visitor> visitor) {
    for (auto& object : container)
        object.second->accept(visitor);
}


//std::shared_ptr<ObjectMemento> ObjectComposite::create_memento() const {
//    return std::make_shared<ObjectMemento>(this->clone());
//}

std::shared_ptr<Object> ObjectComposite::clone() const {
    return std::make_shared<ObjectComposite>(*this);
}
