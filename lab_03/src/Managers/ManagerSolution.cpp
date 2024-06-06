#include "ManagerSolution.hpp"

#include "Creators/Managers/History/HistoryManagerCreator.hpp"
#include "Creators/Managers/Scene/SceneManagerCreator.hpp"
#include "Creators/Managers/Draw/DrawManagerCreator.hpp"
#include "Creators/Managers/Transform/TransformManagerCreator.hpp"
#include "Creators/Managers/Load/LoadManagerCreator.hpp"
#include "Creators/Managers/Camera/CameraManagerCreator.hpp"

std::shared_ptr<HistoryManager> ManagerSolution::get_history_manager() {
    return HistoryManagerCreator::create();
}

std::shared_ptr<SceneManager> ManagerSolution::get_scene_manager() {
    return SceneManagerCreator::create();
}

std::shared_ptr<DrawManager> ManagerSolution::get_draw_manager() {
    return DrawManagerCreator::create();
}

std::shared_ptr<TransformManager> ManagerSolution::get_transform_manager() {
    return TransformManagerCreator::create();
}

std::shared_ptr<LoadManager> ManagerSolution::get_load_manager() {
    return LoadManagerCreator::create();
}

std::shared_ptr<CameraManager> ManagerSolution::get_camera_manager() {
    return CameraManagerCreator::create();
}