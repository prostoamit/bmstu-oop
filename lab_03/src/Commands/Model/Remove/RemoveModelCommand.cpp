#include "RemoveModelCommand.hpp"

#include "Managers/ManagerSolution.hpp"

void RemoveModelCommand::execute() {
    auto scene_manager = ManagerSolution::get_scene_manager();
    auto active_object = scene_manager->get_active_object();

    id = 0;

    if (!active_object)
        return;

    size_t active_id = active_object->get_id();
    scene_manager->remove_object(active_id);

    if (scene_manager->get_scene()->get_objects()->end() == scene_manager->get_scene()->get_objects()->begin())
        return;

    auto new_active_model = scene_manager->get_scene()->get_objects()->begin()->second;
    scene_manager->set_active_object(new_active_model);
    id = new_active_model->get_id();
}

size_t RemoveModelCommand::result() {
    return id;
}
