#include "ModelRotateCommand.hpp"

#include "Managers/ManagerSolution.hpp"

ModelRotateCommand::ModelRotateCommand(double x_axis_angle, double y_axis_angle, double z_axis_angle) :
        x_axis_angle(x_axis_angle),
        y_axis_angle(y_axis_angle),
        z_axis_angle(z_axis_angle) {}

void ModelRotateCommand::execute() {
    auto scene_manager = ManagerSolution::get_scene_manager();
    size_t active_id = scene_manager->get_active_object()->get_id();

    auto transform_manager = ManagerSolution::get_transform_manager();
    transform_manager->rotate(active_id, x_axis_angle, y_axis_angle, z_axis_angle);
}
