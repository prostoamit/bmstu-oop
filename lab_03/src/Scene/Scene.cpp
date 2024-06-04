#include "Scene.hpp"

#include <algorithm>

std::shared_ptr<Object> Scene::get_object(size_t id) {
    // TODO: use std::find_if
}

void Scene::add_object(std::shared_ptr<Object> object) {
    composite->add(std::move(object));
}

void Scene::remove_object(size_t id) {
    // TODO: use std::find_if
}

std::shared_ptr<ObjectComposite> Scene::get_composite() {
    return composite;
}
