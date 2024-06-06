#ifndef HISTORYMANAGER_HPP
#define HISTORYMANAGER_HPP


class HistoryManager {
public:

    void save_state();

    // TODO::get_previous_state()
protected:
    HistoryManager() = default;
    HistoryManager(const HistoryManager& other) = default;
};


#endif //HISTORYMANAGER_HPP
