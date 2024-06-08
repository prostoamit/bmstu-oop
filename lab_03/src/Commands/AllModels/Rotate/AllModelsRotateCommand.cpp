#include "AllModelsRotateCommand.hpp"

#include "Managers/ManagerSolution.hpp"

AllModelsRotateCommand::AllModelsRotateCommand(double x_axis_angle, double y_axis_angle, double z_axis_angle) :
        x_axis_angle(x_axis_angle),
        y_axis_angle(y_axis_angle),
        z_axis_angle(z_axis_angle) {}

void AllModelsRotateCommand::execute() {
    auto scene_manager = ManagerSolution::get_scene_manager();
    auto scene = scene_manager->get_scene();

    auto transform_manager = ManagerSolution::get_transform_manager();
    for (auto &[key, object] : *scene)
        transform_manager->rotate(key, x_axis_angle, y_axis_angle, z_axis_angle);
}
