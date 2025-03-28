#ifndef HISTORYMANAGERCREATOR_HPP
#define HISTORYMANAGERCREATOR_HPP

#include <memory>

#include "Managers/HistoryManager/HistoryManager.hpp"

class HistoryManagerCreator {
public:
    static std::shared_ptr<HistoryManager> create();
protected:
    static std::shared_ptr<HistoryManager> manager;
};


#endif //HISTORYMANAGERCREATOR_HPP
