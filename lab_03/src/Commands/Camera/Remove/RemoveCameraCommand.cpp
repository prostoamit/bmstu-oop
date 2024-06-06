#include "RemoveCameraCommand.hpp"

#include "Managers/ManagerSolution.hpp"

#include "Commands/Camera/Add/AddCameraCommand.hpp"

void RemoveCameraCommand::execute() {
    auto camera_manager = ManagerSolution::get_camera_manager();
    size_t active_id = camera_manager->get_active_camera()->get_id();
    camera_manager->remove_camera(active_id);

    id = 0;
    if (camera_manager->get_cameras()->get_cameras().size() == 0) {
        auto create_camera_command = std::make_shared<AddCameraCommand>("parallelprojection");
        create_camera_command->execute();

        id = create_camera_command->result();
    }
    auto new_active_camera = camera_manager->get_cameras()->begin()->second;
    camera_manager->set_active_camera(new_active_camera);
}

size_t RemoveCameraCommand::result() {
    return id;
}
