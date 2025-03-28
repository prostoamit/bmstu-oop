#include "CameraManagerCreator.hpp"

std::shared_ptr<CameraManager> CameraManagerCreator::manager = nullptr;

std::shared_ptr<CameraManager> CameraManagerCreator::create() {
    if (!manager) {
        class Proxy : public CameraManager {};
        manager = std::make_shared<Proxy>();
    }

    return manager;
}
