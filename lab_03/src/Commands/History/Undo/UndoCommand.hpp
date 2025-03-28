#ifndef UNDOCOMMAND_HPP
#define UNDOCOMMAND_HPP

#include "HistoryCommand.hpp"

class UndoCommand : public HistoryCommand {
public:
    void execute() override;
};


#endif //UNDOCOMMAND_HPP
