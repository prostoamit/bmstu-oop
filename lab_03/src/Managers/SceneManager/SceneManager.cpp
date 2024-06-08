#include "SceneManager.hpp"

#include "Exceptions/Scene/NoModel/NoModelException.hpp"

SceneManager::SceneManager() :
        scene(std::make_shared<Scene>()) {}

std::shared_ptr<Scene> SceneManager::get_scene() const {
    return scene;
}

void SceneManager::set_scene(std::shared_ptr<Scene> scene) {
    this->scene = scene;
}

std::shared_ptr<Object> SceneManager::get_object(const std::string& name) const {
    return scene->get_object(name);
}

void SceneManager::add_object(std::shared_ptr<Object> object, const std::string& name) {
    scene->add_object(object, name);
}


std::shared_ptr<Object> SceneManager::get_active_object() {
    auto active_object = scene->get_active_object();

    if (!active_object)
        throw Exceptions::NoModelException(__FILE__, __LINE__ - 3);

    return active_object;
}

void SceneManager::set_active_object(std::shared_ptr<Object> object) {
    scene->set_active_object(object);
}

void SceneManager::remove_object(const std::string& name) {
    scene->remove_object(name);
}
