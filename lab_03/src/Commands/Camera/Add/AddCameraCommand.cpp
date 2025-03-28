#include "AddCameraCommand.hpp"

#include "ManagerSolution.hpp"
#include "CameraSolution.hpp"

AddCameraCommand::AddCameraCommand(const std::string& type) :
        type(type) {
}

void AddCameraCommand::execute() {
    auto camera_manager = ManagerSolution::get_camera_manager();
    auto camera_creator = CameraSolution::get(type);
    auto camera = camera_creator->create();

    camera_manager->add_camera(std::static_pointer_cast<Camera>(camera));
    camera_manager->set_active_camera(std::static_pointer_cast<Camera>(camera));

    id = camera->get_id();
}

size_t AddCameraCommand::result() {
    return id;
}
