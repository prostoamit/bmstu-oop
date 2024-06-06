#include "LoadModelCommand.hpp"

#include "Managers/ManagerSolution.hpp"

LoadModelCommand::LoadModelCommand(const std::string& path, const std::string& implementation_type) :
        path(path),
        implementation_type(implementation_type) {}

void LoadModelCommand::execute() {
    auto load_manager = ManagerSolution::get_load_manager();
    id = load_manager->load_wireframe_model(path, implementation_type);
}

size_t LoadModelCommand::result() {
    return id;
}