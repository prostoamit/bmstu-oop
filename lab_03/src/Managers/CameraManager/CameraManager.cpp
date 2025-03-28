#include "CameraManager.hpp"

#include "Creators/Transformations/TransformationSolution.hpp"
#include "Visitors/Transform/TransformVisitor.hpp"

CameraManager::CameraManager() :
        cameras(std::make_shared<Cameras>()),
        active_camera(nullptr) {}

std::shared_ptr<Cameras> CameraManager::get_cameras() const {
    return cameras;
}

void CameraManager::set_cameras(std::shared_ptr<Cameras> cameras) {
    this->cameras = cameras;
}

std::shared_ptr<Camera> CameraManager::get_camera(size_t id) const {
    return cameras->get_camera(id);
}

void CameraManager::remove_camera(size_t id) {
    cameras->remove_camera(id);
}

void CameraManager::add_camera(std::shared_ptr<Camera> camera) {
    cameras->add_camera(camera);
}

std::shared_ptr<Camera> CameraManager::get_active_camera() const {
    return active_camera;
}

void CameraManager::set_active_camera(std::shared_ptr<Camera> camera) {
    active_camera = camera;

    add_camera(camera);
}

void CameraManager::camera_move(double x_delta, double y_delta, double z_delta) {
    auto transformer_creator = Transformers::TransformationSolution::get("move");
    auto transformer = transformer_creator->create(-x_delta, -y_delta, -z_delta);

    auto visitor = std::make_shared<TransformVisitor>(transformer);
    active_camera->accept(visitor);
}

void CameraManager::camera_rotate(double x_axis_angle, double y_axis_angle, double z_axis_angle) {
    auto rotation_creator = Transformers::TransformationSolution::get("rotate");
    auto move_creator = Transformers::TransformationSolution::get("move");

//    auto move_to_camera = move_creator->create(active_camera)
    auto transformer = rotation_creator->create(-x_axis_angle, -y_axis_angle, -z_axis_angle);

    auto visitor = std::make_shared<TransformVisitor>(transformer);
    active_camera->accept(visitor);
}
