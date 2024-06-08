#include "ModelRotateCommand.hpp"

#include "Managers/ManagerSolution.hpp"

ModelRotateCommand::ModelRotateCommand(double x_axis_angle, double y_axis_angle, double z_axis_angle) :
        x_axis_angle(x_axis_angle),
        y_axis_angle(y_axis_angle),
        z_axis_angle(z_axis_angle) {}

void ModelRotateCommand::execute() {
    auto scene_manager = ManagerSolution::get_scene_manager();
    auto objects = scene_manager->get_scene()->get_objects();
    auto active_object = scene_manager->get_active_object();
    size_t active_id = scene_manager->get_active_object()->get_id();

    auto transform_manager = ManagerSolution::get_transform_manager();
    transform_manager->rotate(scene_manager->get_scene()->get_active_object_name(), x_axis_angle, y_axis_angle, z_axis_angle);
}
