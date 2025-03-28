#ifndef DRAWSCENECOMMAND_HPP
#define DRAWSCENECOMMAND_HPP

#include "Commands/Scene/SceneCommand.hpp"

class DrawSceneCommand : public SceneCommand {
public:
    void execute() override;
};


#endif //DRAWSCENECOMMAND_HPP
