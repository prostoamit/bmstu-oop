#include "SaveCommand.hpp"

#include "ManagerSolution.hpp"

void SaveCommand::execute() {
    auto history_manager = ManagerSolution::get_history_manager();
    history_manager->save_state();
}