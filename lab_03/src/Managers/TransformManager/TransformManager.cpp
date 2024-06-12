#include "TransformManager.hpp"

#include "Managers/ManagerSolution.hpp"
#include "Visitors/Transform/TransformVisitor.hpp"
#include "Creators/Transformations/TransformationSolution.hpp"

void TransformManager::move(const std::string& name, double x_delta, double y_delta, double z_delta) const {
    applyTransformation(name, "move", x_delta, y_delta, z_delta);
}

void TransformManager::rotate(const std::string& name, double x_axis_angle, double y_axis_angle, double z_axis_angle) const {
    applyTransformation(name, "rotate", x_axis_angle, y_axis_angle, z_axis_angle);
}

void TransformManager::scale(const std::string& name, double x_coefficient, double y_coefficient, double z_coefficient) const {
    applyTransformation(name, "scale", x_coefficient, y_coefficient, z_coefficient);
}

template <typename... Args>
void TransformManager::applyTransformation(const std::string& name, const std::string& transformationType, Args... args) const {
    auto scene_manager = ManagerSolution::get_scene_manager();
    auto object = scene_manager->get_object(name);

    if (!object) {
        // TODO: не помню.
    }

    auto transformer_creator = Transformers::TransformationSolution::get(transformationType);
    auto transformer = transformer_creator->create(args...);

    auto visitor = std::make_shared<TransformVisitor>(transformer);
    object->accept(visitor);

    auto history_manager = ManagerSolution::get_history_manager();
    history_manager->save_state();
}
