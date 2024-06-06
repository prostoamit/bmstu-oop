#ifndef MODELSCALECOMMAND_HPP
#define MODELSCALECOMMAND_HPP

#include "Commands/Model/ModelCommand.hpp"

class ModelScaleCommand : public ModelCommand {
public:
    ModelScaleCommand(double x_coefficient, double y_coefficient, double z_coefficient);

    void execute() override;
private:
    double x_coefficient, y_coefficient, z_coefficient;
};


#endif //MODELSCALECOMMAND_HPP
