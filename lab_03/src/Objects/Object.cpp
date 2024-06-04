#include "Object.hpp"

size_t Object::current_objects_count = 0;

Object::Object() {
    _id = current_objects_count++;
}

size_t Object::get_id() const {
    return _id;
}

bool Object::is_visible() const {
    return false;
}

bool Object::is_composite() const {
    return false;
}

void Object::add(std::shared_ptr<Object> object) {}

void Object::remove(Object::iterator) {}

Object::iterator Object::begin() {}

Object::iterator Object::end() {
    return {};
}

void Object::accept(std::shared_ptr<Visitor> visitor) {}
