#include "LoadManager.hpp"

#include <filesystem>

#include "Managers/ManagerSolution.hpp"

#include "Creators/Objects/Models/WireframeModel/Builders/WireframeModelBuilderSolution.hpp"
#include "Creators/Objects/Models/WireframeModel/WireframeModelCreator.hpp"
#include "Creators/Objects/Models/WireframeModel/Sources/WireframeModelSourceSolution.hpp"

size_t LoadManager::load_wireframe_model(const std::string& path, const std::string& implementation_type) {
    std::filesystem::path p(path);
    std::string extension = p.extension().string();

    auto scene_manager = ManagerSolution::get_scene_manager();

    auto source_creator = WireframeModel::SourceSolution::get(extension);
    auto source = source_creator->create(path);

    auto builder_creator = WireframeModel::BuilderSolution::get(implementation_type);
    auto builder = builder_creator->create(source);

    auto model_director = WireframeModel::Creator(builder);

    auto model = model_director.create();

    scene_manager->set_active_object(model);

    return model->get_id();
}
