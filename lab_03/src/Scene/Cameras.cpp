#include "Cameras.hpp"

Cameras::Cameras() {}

std::shared_ptr<Camera> Cameras::get_camera(size_t id) {
    for (auto& i : cameras)
        if (i.first == id)
            return i.second;

    return nullptr;
}

void Cameras::add_camera(std::shared_ptr<Camera> camera) {
    cameras[camera->get_id()] = camera;
}

void Cameras::remove_camera(size_t id) {
    cameras.erase(id);
}

Cameras::container::iterator Cameras::begin() {
    return cameras.begin();
}

Cameras::container::iterator Cameras::end() {
    return cameras.end();
}

Cameras::container& Cameras::get_cameras() {
    return cameras;
}