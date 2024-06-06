#include "AddCameraCommand.hpp"

#include "Managers/ManagerSolution.hpp"
#include "Creators/Objects/Cameras/CameraSolution.hpp"

AddCameraCommand::AddCameraCommand(const std::string& type) :
        type(type) {
}

void AddCameraCommand::execute() {
    auto camera_manager = ManagerSolution::get_camera_manager();
    auto camera_creator = CameraSolution::get(type);
    auto camera = camera_creator->create(
            std::make_shared<Point>(0, 0, -500),
            std::make_shared<Vector>()
    );

    camera_manager->add_camera(camera);
    camera_manager->set_active_camera(camera);

    id = camera->get_id();
}

size_t AddCameraCommand::result() {
    return id;
}
