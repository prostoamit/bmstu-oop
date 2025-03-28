#include "ModelMoveCommand.hpp"

#include "Managers/ManagerSolution.hpp"

ModelMoveCommand::ModelMoveCommand(double x_delta, double y_delta, double z_delta) :
        x_delta(x_delta),
        y_delta(y_delta),
        z_delta(z_delta) {}

void ModelMoveCommand::execute() {
    auto scene_manager = ManagerSolution::get_scene_manager();
    size_t active_id = scene_manager->get_active_object()->get_id();

    auto transform_manager = ManagerSolution::get_transform_manager();
    transform_manager->move(scene_manager->get_scene()->get_active_object_name(), x_delta, y_delta, z_delta);
}
