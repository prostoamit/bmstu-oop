#ifndef MOVECAMERACOMMAND_HPP
#define MOVECAMERACOMMAND_HPP

#include "Commands/Camera/CameraCommand.hpp"

class MoveCameraCommand : public CameraCommand {
public:
    explicit MoveCameraCommand(double x_delta, double y_delta, double z_delta);

    void execute() override;
private:
    double x_delta, y_delta, z_delta;
};


#endif //MOVECAMERACOMMAND_HPP
