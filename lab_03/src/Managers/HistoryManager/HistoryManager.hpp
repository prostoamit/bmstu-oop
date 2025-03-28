#ifndef HISTORYMANAGER_HPP
#define HISTORYMANAGER_HPP

#include <map>
#include "ObjectCareTaker.hpp"

class HistoryManager {
public:
    void save_state();
    void undo();
    void redo();

    void remove(size_t id);

protected:
    HistoryManager() = default;
    HistoryManager(const HistoryManager& other) = default;

    std::map<size_t, std::shared_ptr<ObjectCareTaker>> caretakers;
};


#endif //HISTORYMANAGER_HPP
