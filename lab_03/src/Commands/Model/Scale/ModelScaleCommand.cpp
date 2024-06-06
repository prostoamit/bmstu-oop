#include "ModelScaleCommand.hpp"

#include "Managers/ManagerSolution.hpp"

ModelScaleCommand::ModelScaleCommand(double x_coefficient, double y_coefficient, double z_coefficient) :
        x_coefficient(x_coefficient),
        y_coefficient(y_coefficient),
        z_coefficient(z_coefficient) {}

void ModelScaleCommand::execute() {
    auto scene_manager = ManagerSolution::get_scene_manager();
    size_t active_id = scene_manager->get_active_object()->get_id();

    auto transform_manager = ManagerSolution::get_transform_manager();
    transform_manager->scale(active_id, x_coefficient, y_coefficient, z_coefficient);
}
