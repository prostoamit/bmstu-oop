#include "Facade.hpp"

void Facade::apply(std::shared_ptr<Command> command) {
    command->execute();
}
