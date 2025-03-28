#include "RedoCommand.hpp"

#include "ManagerSolution.hpp"

void RedoCommand::execute() {
    auto history_manager = ManagerSolution::get_history_manager();
    history_manager->redo();
}
