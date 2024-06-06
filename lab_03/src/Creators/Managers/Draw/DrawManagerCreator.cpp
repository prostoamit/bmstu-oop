#include "DrawManagerCreator.hpp"

std::shared_ptr<DrawManager> DrawManagerCreator::manager = nullptr;

std::shared_ptr<DrawManager> DrawManagerCreator::create() {
    if (!manager) {
        class Proxy : public DrawManager {};
        manager = std::make_shared<Proxy>();
    }

    return manager;
}
