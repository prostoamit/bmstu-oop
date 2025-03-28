#ifndef ROTATECAMERACOMMAND_HPP
#define ROTATECAMERACOMMAND_HPP

#include "Commands/Camera/CameraCommand.hpp"

class RotateCameraCommand : public CameraCommand{
public:
    RotateCameraCommand(double x_axis_angle, double y_axis_angle, double z_axis_angle);

    void execute() override;
private:
    double x_axis_angle, y_axis_angle, z_axis_angle;
};


#endif //ROTATECAMERACOMMAND_HPP
