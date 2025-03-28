#include "TransformManagerCreator.hpp"

std::shared_ptr<TransformManager> TransformManagerCreator::manager = nullptr;

std::shared_ptr<TransformManager> TransformManagerCreator::create() {
    if (!manager) {
        class Proxy : public TransformManager {};
        manager = std::make_shared<Proxy>();
    }

    return manager;
}