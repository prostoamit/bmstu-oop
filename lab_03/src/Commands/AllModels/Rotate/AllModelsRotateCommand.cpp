#include "AllModelsRotateCommand.hpp"

#include "Managers/ManagerSolution.hpp"

AllModelsRotateCommand::AllModelsRotateCommand(double x_axis_angle, double y_axis_angle, double z_axis_angle) :
        x_axis_angle(x_axis_angle),
        y_axis_angle(y_axis_angle),
        z_axis_angle(z_axis_angle) {}

void AllModelsRotateCommand::execute() {
    auto scene_manager = ManagerSolution::get_scene_manager();
    auto scene = scene_manager->get_scene();
    auto composite_id = scene->get_objects()->get_id();


    auto transform_manager = ManagerSolution::get_transform_manager();
    transform_manager->rotate(composite_id, x_axis_angle, y_axis_angle, z_axis_angle);
}
