#ifndef TRANSFORMERSCALE_HPP
#define TRANSFORMERSCALE_HPP

#include "Transformations/Transformer.hpp"

namespace Transformers {
    class Scale : public Transformer {
    public:
        Scale(double x_coefficient, double y_coefficient, double z_coefficient);
    };
}

#endif //TRANSFORMERSCALE_HPP
