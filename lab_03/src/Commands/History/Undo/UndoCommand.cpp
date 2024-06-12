#include "UndoCommand.hpp"

#include "ManagerSolution.hpp"

void UndoCommand::execute() {
    auto history_manager = ManagerSolution::get_history_manager();
    history_manager->undo();
}
