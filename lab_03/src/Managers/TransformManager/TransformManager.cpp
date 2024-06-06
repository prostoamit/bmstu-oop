#include "TransformManager.hpp"

#include "Managers/ManagerSolution.hpp"
#include "Visitors/Transform/TransformVisitor.hpp"
#include "Creators/Transformations/TransformationSolution.hpp"

void TransformManager::move(size_t id, double x_delta, double y_delta, double z_delta) const {
    applyTransformation(id, "move", x_delta, y_delta, z_delta);
}

void TransformManager::rotate(size_t id, double x_axis_angle, double y_axis_angle, double z_axis_angle) const {
    applyTransformation(id, "rotate", x_axis_angle, y_axis_angle, z_axis_angle);
}

void TransformManager::scale(size_t id, double x_coefficient, double y_coefficient, double z_coefficient) const {
    applyTransformation(id, "scale", x_coefficient, y_coefficient, z_coefficient);
}

template <typename... Args>
void TransformManager::applyTransformation(size_t id, const std::string& transformationType, Args... args) const {
    auto scene_manager = ManagerSolution::get_scene_manager();
    auto object = scene_manager->get_object(id);

    if (!object) {
        // TODO: не помню.
    }

    auto transformer_creator = Transformers::TransformationSolution::get(transformationType);
    auto transformer = transformer_creator->create(args...);

    auto visitor = std::make_shared<TransformVisitor>(transformer);
    object->accept(visitor);
}
