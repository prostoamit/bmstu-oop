#ifndef SETACTIVEMODELCOMMAND_HPP
#define SETACTIVEMODELCOMMAND_HPP

#include "Commands/Scene/SceneCommand.hpp"

class SetActiveModelCommand : public SceneCommand {
public:
    SetActiveModelCommand(size_t id);

    void execute() override;
private:
    size_t id;
};


#endif //SETACTIVEMODELCOMMAND_HPP
