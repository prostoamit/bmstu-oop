#include "ModelScaleCommand.hpp"

#include "Managers/ManagerSolution.hpp"

ModelScaleCommand::ModelScaleCommand(double x_coefficient, double y_coefficient, double z_coefficient) :
        x_coefficient(x_coefficient),
        y_coefficient(y_coefficient),
        z_coefficient(z_coefficient) {}

void ModelScaleCommand::execute() {
    auto history_manager = ManagerSolution::get_history_manager();
    history_manager->save_state();

    auto scene_manager = ManagerSolution::get_scene_manager();
    size_t active_id = scene_manager->get_active_object()->get_id();

    auto transform_manager = ManagerSolution::get_transform_manager();
    transform_manager->scale(scene_manager->get_scene()->get_active_object_name(), x_coefficient, y_coefficient, z_coefficient);
}
