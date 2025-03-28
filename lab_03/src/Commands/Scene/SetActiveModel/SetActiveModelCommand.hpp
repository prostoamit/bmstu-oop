#ifndef SETACTIVEMODELCOMMAND_HPP
#define SETACTIVEMODELCOMMAND_HPP

#include <string>

#include "Commands/Scene/SceneCommand.hpp"

class SetActiveModelCommand : public SceneCommand {
public:
    SetActiveModelCommand(const std::string& name);

    void execute() override;
private:
    std::string name;
};


#endif //SETACTIVEMODELCOMMAND_HPP
