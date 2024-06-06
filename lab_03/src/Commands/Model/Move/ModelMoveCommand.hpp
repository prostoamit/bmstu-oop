#ifndef MODELMOVECOMMAND_HPP
#define MODELMOVECOMMAND_HPP

#include "Commands/Model/ModelCommand.hpp"

class ModelMoveCommand : public ModelCommand {
public:
    ModelMoveCommand(double x_delta, double y_delta, double z_delta);

    void execute() override;
private:
    double x_delta, y_delta, z_delta;
};


#endif //MODELMOVECOMMAND_HPP
