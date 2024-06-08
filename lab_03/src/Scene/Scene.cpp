#include "Scene.hpp"

#include <algorithm>

Scene::Scene() :
        objects(std::make_shared<ObjectComposite>()) {}

std::shared_ptr<Object> Scene::get_object(size_t id) {
    if (id == objects->get_id())
        return objects;

    for (auto& i : *objects)
        if (i.first == id)
            return i.second;

    return nullptr;
}

void Scene::add_object(std::shared_ptr<Object> object) {
    objects->add(object);
}

void Scene::remove_object(size_t id) {
    if (id == active_object->get_id())
        active_object = nullptr;
    for (auto i = objects->begin(); i != objects->end(); i++)
        if (i->first == id) {
            objects->remove(i);
            return;
        }
}

ObjectComposite::iterator Scene::begin() {
    return objects->begin();
}

ObjectComposite::iterator Scene::end() {
    return objects->end();
}

std::shared_ptr<ObjectComposite> Scene::get_objects() {
    return objects;
}

std::shared_ptr<Object> Scene::get_active_object() {
    return active_object;
}

void Scene::set_active_object(std::shared_ptr<Object> object) {
    active_object = object;

    add_object(active_object);
}
