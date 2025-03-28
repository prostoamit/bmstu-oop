#include "DrawSceneCommand.hpp"

#include "Managers/ManagerSolution.hpp"

void DrawSceneCommand::execute() {
    auto draw_manager = ManagerSolution::get_draw_manager();
    draw_manager->draw_scene();
}
