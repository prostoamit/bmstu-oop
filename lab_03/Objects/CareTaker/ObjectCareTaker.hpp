#ifndef OBJECTCARETAKER_HPP
#define OBJECTCARETAKER_HPP

#include <memory>
#include <list>
#include <stack>

#include "ObjectMemento.hpp"

class ObjectCareTaker {
public:
    void set(std::unique_ptr<ObjectMemento> memento);
    std::unique_ptr<ObjectMemento> get();
private:
    std::stack<std::unique_ptr<ObjectMemento>> mementos;
};


#endif //OBJECTCARETAKER_HPP
