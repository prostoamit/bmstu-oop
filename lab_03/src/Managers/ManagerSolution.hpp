#ifndef MANAGERSOLUTION_HPP
#define MANAGERSOLUTION_HPP

#include "Managers/HistoryManager/HistoryManager.hpp"
#include "Managers/SceneManager/SceneManager.hpp"
#include "Managers/DrawManager/DrawManager.hpp"
#include "Managers/TransformManager/TransformManager.hpp"
#include "Managers/LoadManager/LoadManager.hpp"
#include "Managers/CameraManager/CameraManager.hpp"

class ManagerSolution {
public:
    static std::shared_ptr<HistoryManager> get_history_manager();
    static std::shared_ptr<SceneManager> get_scene_manager();
    static std::shared_ptr<DrawManager> get_draw_manager();
    static std::shared_ptr<TransformManager> get_transform_manager();
    static std::shared_ptr<LoadManager> get_load_manager();
    static std::shared_ptr<CameraManager> get_camera_manager();
};

#endif //MANAGERSOLUTION_HPP
