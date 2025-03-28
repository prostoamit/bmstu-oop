#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <cstddef>

class Command {
public:
    virtual ~Command() = default;

    virtual void execute() = 0;
    virtual size_t result();
};


#endif //COMMAND_HPP
