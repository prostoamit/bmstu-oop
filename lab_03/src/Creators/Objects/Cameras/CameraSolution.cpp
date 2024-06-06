#include "CameraSolution.hpp"

#include "Creators/Objects/Cameras/ParallelProjection/ParallelProjectionCameraCreator.hpp"

std::map<std::string, std::shared_ptr<CameraCreator>> CameraSolution::creators_map {
        { "parallelprojection", std::make_shared<ParallelProjectionCameraCreator>() },
};

std::shared_ptr<CameraCreator> CameraSolution::get(const std::string& type) {
    return creators_map[type];
}

void CameraSolution::register_creator(const std::string& type, std::shared_ptr<CameraCreator> creator) {
    CameraSolution::creators_map[type] = creator;
}
