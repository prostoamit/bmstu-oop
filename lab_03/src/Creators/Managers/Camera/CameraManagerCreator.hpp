#ifndef CAMERAMANAGERCREATOR_HPP
#define CAMERAMANAGERCREATOR_HPP

#include <memory>

#include "Managers/CameraManager/CameraManager.hpp"

class CameraManagerCreator {
public:
    static std::shared_ptr<CameraManager> create();
protected:
    static std::shared_ptr<CameraManager> manager;
};


#endif //CAMERAMANAGERCREATOR_HPP
