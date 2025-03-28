#include "AllModelsMoveCommand.hpp"

#include "Managers/ManagerSolution.hpp"

AllModelsMoveCommand::AllModelsMoveCommand(double x_delta, double y_delta, double z_delta) :
        x_delta(x_delta),
        y_delta(y_delta),
        z_delta(z_delta) {}

void AllModelsMoveCommand::execute() {
    auto scene_manager = ManagerSolution::get_scene_manager();
    auto scene = scene_manager->get_scene();

    auto transform_manager = ManagerSolution::get_transform_manager();
    for (auto &[key, object] : *scene)
        transform_manager->move(key, x_delta, y_delta, z_delta);
}