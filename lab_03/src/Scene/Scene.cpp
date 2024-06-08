#include "Scene.hpp"

#include <algorithm>

Scene::Scene() {}

std::shared_ptr<Object> Scene::get_object(const std::string& name) {
    return objects[name];
}

std::map<std::string, std::shared_ptr<Object>>::iterator Scene::begin() {
    return objects.begin();
}

std::map<std::string, std::shared_ptr<Object>>::iterator Scene::end() {
    return objects.end();
}

void Scene::add_object(std::shared_ptr<Object> object, const std::string& name) {
    objects[name] = object;

    active_object = object;
    active_object_name = name;
}

void Scene::remove_object(const std::string& name) {
    objects.erase(name);

    if (objects.size() == 0) {
        active_object_name = "";
        active_object = nullptr;
    }
}


std::map<std::string, std::shared_ptr<Object>>& Scene::get_objects() {
    return objects;
}

std::shared_ptr<Object> Scene::get_active_object() {
    return active_object;
}

void Scene::set_active_object(std::shared_ptr<Object> object) {
    for (auto &[key, value] : objects)
        if (object == value) {
            active_object = value;
            active_object_name = key;
        }
}

std::string& Scene::get_active_object_name() {
    return active_object_name;
}
