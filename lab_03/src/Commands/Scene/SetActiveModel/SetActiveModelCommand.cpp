#include "SetActiveModelCommand.hpp"

#include "Managers/ManagerSolution.hpp"

SetActiveModelCommand::SetActiveModelCommand(size_t id) :
        id(id) {}

void SetActiveModelCommand::execute() {
    auto scene_manager = ManagerSolution::get_scene_manager();
    auto object = scene_manager->get_object(id);

    scene_manager->set_active_object(object);
}