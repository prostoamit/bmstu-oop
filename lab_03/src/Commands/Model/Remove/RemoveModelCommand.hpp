#ifndef REMOVEMODELCOMMAND_HPP
#define REMOVEMODELCOMMAND_HPP

#include <string>
#include "Commands/Model/ModelCommand.hpp"

class RemoveModelCommand : public ModelCommand {
public:
    RemoveModelCommand(const std::string& name);

    void execute() override;
    size_t result() override;
private:
    const std::string& name;
    size_t id;
};


#endif //REMOVEMODELCOMMAND_HPP
