#ifndef SETCAMERACOMMAND_HPP
#define SETCAMERACOMMAND_HPP

#include "Commands/Camera/CameraCommand.hpp"

class SetCameraCommand : public CameraCommand {
public:
    explicit SetCameraCommand(size_t id);

    void execute() override;
private:
    size_t id;
};


#endif //SETCAMERACOMMAND_HPP
