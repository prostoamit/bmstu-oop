#ifndef ADDCAMERACOMMAND_HPP
#define ADDCAMERACOMMAND_HPP

#include <string>

#include "Commands/Camera/CameraCommand.hpp"

class AddCameraCommand : public CameraCommand {
public:
    AddCameraCommand(const std::string& type);

    void execute() override;
    size_t result() override;
private:
    size_t id;
    std::string type;
};


#endif //ADDCAMERACOMMAND_HPP
