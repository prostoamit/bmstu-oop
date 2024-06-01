#include "Object.hpp"

size_t Object::current_objects_count = 0;

Object::Object() {
    _id = current_objects_count++;
}

size_t Object::get_id() {
    return _id;
}
