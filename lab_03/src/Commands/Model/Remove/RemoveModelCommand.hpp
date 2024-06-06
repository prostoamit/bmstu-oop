#ifndef REMOVEMODELCOMMAND_HPP
#define REMOVEMODELCOMMAND_HPP

#include "Commands/Model/ModelCommand.hpp"

class RemoveModelCommand : public ModelCommand {
public:
    void execute() override;
    size_t result() override;
private:
    size_t id;
};


#endif //REMOVEMODELCOMMAND_HPP
