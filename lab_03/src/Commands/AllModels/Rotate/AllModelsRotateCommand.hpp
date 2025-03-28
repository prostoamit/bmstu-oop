#ifndef ALLMODELSROTATECOMMAND_HPP
#define ALLMODELSROTATECOMMAND_HPP


#include "Commands/AllModels/AllModelsCommand.hpp"

class AllModelsRotateCommand : public AllModelsCommand {
public:
    AllModelsRotateCommand(double x_axis_angle, double y_axis_angle, double z_axis_angle);

    void execute() override;
private:
    double x_axis_angle, y_axis_angle, z_axis_angle;
};


#endif //ALLMODELSROTATECOMMAND_HPP
