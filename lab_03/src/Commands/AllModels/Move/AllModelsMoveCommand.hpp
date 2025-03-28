#ifndef ALLMODELSMOVECOMMAND_HPP
#define ALLMODELSMOVECOMMAND_HPP

#include "Commands/AllModels/AllModelsCommand.hpp"

class AllModelsMoveCommand : public AllModelsCommand {
public:
    AllModelsMoveCommand(double x_delta, double y_delta, double z_delta);

    void execute() override;
private:
    double x_delta, y_delta, z_delta;
};


#endif //ALLMODELSMOVECOMMAND_HPP
