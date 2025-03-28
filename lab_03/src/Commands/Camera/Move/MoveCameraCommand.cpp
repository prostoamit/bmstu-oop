#include "MoveCameraCommand.hpp"

#include "Managers/ManagerSolution.hpp"

MoveCameraCommand::MoveCameraCommand(double x_delta, double y_delta, double z_delta) :
        x_delta(x_delta),
        y_delta(y_delta),
        z_delta(z_delta) {}

void MoveCameraCommand::execute() {
    auto camera_manager = ManagerSolution::get_camera_manager();
    camera_manager->camera_move(x_delta, y_delta, z_delta);
}
