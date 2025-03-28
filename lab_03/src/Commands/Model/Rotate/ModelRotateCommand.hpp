#ifndef MODELROTATECOMMAND_HPP
#define MODELROTATECOMMAND_HPP

#include "Commands/Model/ModelCommand.hpp"

class ModelRotateCommand : public ModelCommand {
public:
    ModelRotateCommand(double x_axis_angle, double y_axis_angle, double z_axis_angle);

    void execute() override;
private:
    double x_axis_angle, y_axis_angle, z_axis_angle;
};


#endif //MODELROTATECOMMAND_HPP
