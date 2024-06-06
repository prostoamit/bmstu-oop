#ifndef REMOVECAMERACOMMAND_HPP
#define REMOVECAMERACOMMAND_HPP

#include "Commands/Camera/CameraCommand.hpp"

class RemoveCameraCommand : public CameraCommand {
public:
    void execute() override;
    size_t result() override;
private:
    size_t id;
};


#endif //REMOVECAMERACOMMAND_HPP
