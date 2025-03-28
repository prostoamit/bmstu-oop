#include "LoadManagerCreator.hpp"


std::shared_ptr<LoadManager> LoadManagerCreator::manager = nullptr;

std::shared_ptr<LoadManager> LoadManagerCreator::create() {
    if (!manager) {
        class Proxy : public LoadManager {
        };
        manager = std::make_shared<Proxy>();
    }

    return manager;
}
