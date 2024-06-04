#ifndef TRANSFORMERSCALE_HPP
#define TRANSFORMERSCALE_HPP

#include "Transformer.hpp"

namespace Transformers {
    class Scale : public Transformer {
    public:
        Scale(double x_coefficient, double y_coefficient, double z_coefficient);

        virtual void transform(Point &point) override;
    private:
        double x_coefficient;
        double y_coefficient;
        double z_coefficient;
    };
}

#endif //TRANSFORMERSCALE_HPP
