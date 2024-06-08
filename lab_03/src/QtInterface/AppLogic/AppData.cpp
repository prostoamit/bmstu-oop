#include "AppData.hpp"

void AppData::add_object(const std::string& name, size_t id) {
    objects[name] = id;
}

void AppData::remove_object(const std::string& name) {
    objects.erase(name);

    if (name == active_object.first)
        active_object = {objects.begin()->first, objects.begin()->second};
}

std::pair<std::string, size_t> AppData::set_active_object(const std::string& name) {
    active_object = {name, objects[name]};

    return active_object;
}

std::pair<std::string, size_t> AppData::get_active_object() {
    return active_object;
}

std::map<std::string, size_t>& AppData::get_objects() {
    return objects;
}

void AppData::add_camera(const std::string& name, size_t id) {
    cameras[name] = id;
}

void AppData::remove_camera(const std::string& name) {
    cameras.erase(name);

    if (name == active_camera.first)
        active_camera = {cameras.begin()->first, cameras.begin()->second};
}

std::pair<std::string, size_t> AppData::set_active_camera(const std::string& name) {
    active_camera = {name, cameras[name]};

    return active_camera;
}

std::pair<std::string, size_t> AppData::get_active_camera() {
    return active_camera;
}

std::map<std::string, size_t>& AppData::get_cameras() {
    return cameras;
}
