#include "SetActiveModelCommand.hpp"

#include "Managers/ManagerSolution.hpp"

SetActiveModelCommand::SetActiveModelCommand(const std::string& name) :
        name(name) {}

void SetActiveModelCommand::execute() {
    auto scene_manager = ManagerSolution::get_scene_manager();
    auto object = scene_manager->get_object(name);

    scene_manager->set_active_object(object);
}