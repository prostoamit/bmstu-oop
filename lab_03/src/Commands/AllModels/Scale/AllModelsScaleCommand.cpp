#include "AllModelsScaleCommand.hpp"

#include "Managers/ManagerSolution.hpp"

AllModelsScaleCommand::AllModelsScaleCommand(double x_coefficient, double y_coefficient, double z_coefficient) :
        x_coefficient(x_coefficient),
        y_coefficient(y_coefficient),
        z_coefficient(z_coefficient) {}

void AllModelsScaleCommand::execute() {
    auto scene_manager = ManagerSolution::get_scene_manager();
    auto scene = scene_manager->get_scene();
    auto composite_id = scene->get_objects()->get_id();


    auto transform_manager = ManagerSolution::get_transform_manager();
    transform_manager->scale(composite_id, x_coefficient, y_coefficient, z_coefficient);
}
