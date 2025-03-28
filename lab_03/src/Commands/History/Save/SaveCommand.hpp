#ifndef SAVECOMMAND_HPP
#define SAVECOMMAND_HPP

#include "HistoryCommand.hpp"

class SaveCommand : public HistoryCommand {
public:
    void execute() override;
};


#endif //SAVECOMMAND_HPP
