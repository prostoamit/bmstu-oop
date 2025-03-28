#include "SetCameraCommand.hpp"

#include "Managers/ManagerSolution.hpp"

SetCameraCommand::SetCameraCommand(size_t id) :
        id(id) {}

void SetCameraCommand::execute() {
    auto camera_manager = ManagerSolution::get_camera_manager();

    camera_manager->set_active_camera(camera_manager->get_camera(id));
}