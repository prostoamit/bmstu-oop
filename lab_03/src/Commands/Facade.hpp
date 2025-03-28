#ifndef FACADE_HPP
#define FACADE_HPP

#include <memory>

#include "Command.hpp"

class Facade {
public:
    void apply(std::shared_ptr<Command> command);
};


#endif //FACADE_HPP
