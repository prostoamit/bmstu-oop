#include "RotateCameraCommand.hpp"

#include "Managers/ManagerSolution.hpp"

RotateCameraCommand::RotateCameraCommand(double x_axis_angle, double y_axis_angle, double z_axis_angle) :
        x_axis_angle(x_axis_angle),
        y_axis_angle(y_axis_angle),
        z_axis_angle(z_axis_angle) {}

void RotateCameraCommand::execute() {
    auto camera_manager = ManagerSolution::get_camera_manager();
    camera_manager->camera_rotate(x_axis_angle, y_axis_angle, z_axis_angle);
}
