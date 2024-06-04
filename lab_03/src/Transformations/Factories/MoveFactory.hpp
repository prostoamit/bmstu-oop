#ifndef TRANSFORMATIONSMOVEFACTORY_HPP
#define TRANSFORMATIONSMOVEFACTORY_HPP

#include "Factories/Factory.hpp"
#include "Move/Move.hpp"

class MoveFactory : public Factory {
public:
    MoveFactory(double x_delta, double y_delta, double z_delta);

    virtual std::unique_ptr<Transformers::Transformer> create() const override;
private:
    double x_delta;
    double y_delta;
    double z_delta;
};


#endif //TRANSFORMATIONSMOVEFACTORY_HPP
