#include "HistoryManagerCreator.hpp"

std::shared_ptr<HistoryManager> HistoryManagerCreator::manager = nullptr;

std::shared_ptr<HistoryManager> HistoryManagerCreator::create() {
    if (!manager) {
        class Proxy : public HistoryManager {};
        manager = std::make_shared<Proxy>();
    }

    return manager;
}
