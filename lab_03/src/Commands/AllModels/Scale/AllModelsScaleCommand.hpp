#ifndef ALLMODELSSCALECOMMAND_HPP
#define ALLMODELSSCALECOMMAND_HPP

#include "Commands/AllModels/AllModelsCommand.hpp"

class AllModelsScaleCommand : public AllModelsCommand {
public:
    AllModelsScaleCommand(double x_coefficient, double y_coefficient, double z_coefficient);

    void execute() override;
private:
    double x_coefficient, y_coefficient, z_coefficient;
};


#endif //ALLMODELSSCALECOMMAND_HPP
