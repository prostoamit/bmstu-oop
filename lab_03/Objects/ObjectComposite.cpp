#include "ObjectComposite.hpp"


bool ObjectComposite::is_composite() {
    return true;
}

void ObjectComposite::add(std::shared_ptr<Object> object) {
    container.insert(std::make_pair<size_t, std::shared_ptr<Object>&>(object->get_id(), object));
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

ObjectComposite::ObjectComposite(const ObjectComposite &other) {

}
