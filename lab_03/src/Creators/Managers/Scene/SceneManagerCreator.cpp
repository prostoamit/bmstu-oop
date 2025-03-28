#include "SceneManagerCreator.hpp"

std::shared_ptr<SceneManager> SceneManagerCreator::manager = nullptr;

std::shared_ptr<SceneManager> SceneManagerCreator::create() {
    if (!manager) {
        class Proxy : public SceneManager {};
        manager = std::make_shared<Proxy>();
    }

    return manager;
}
