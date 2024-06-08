#include "LoadManager.hpp"

#include <filesystem>

#include "Managers/ManagerSolution.hpp"

#include "WireframeModelBuilderSolution.hpp"
#include "WireframeModelSourceSolution.hpp"
#include "WireframeModelDirectorSolution.hpp"

size_t LoadManager::load_wireframe_model(const std::string& path, const std::string& implementation_type) {
    std::filesystem::path p(path);
    std::string extension = p.extension().string();

    auto scene_manager = ManagerSolution::get_scene_manager();

    auto source_creator = WireframeModel::SourceSolution::get(extension);
    auto source = source_creator->create(path);

    auto builder_creator = WireframeModel::BuilderSolution::get(implementation_type);
    auto builder = builder_creator->create(source);

    auto model_director = WireframeModel::DirectorSolution::get(builder);
    auto model = model_director->create();

    scene_manager->set_active_object(model);

    return model->get_id();
}
