#ifndef REDOCOMMAND_HPP
#define REDOCOMMAND_HPP

#include "HistoryCommand.hpp"

class RedoCommand : public HistoryCommand {
public:
    void execute() override;
};


#endif //REDOCOMMAND_HPP
