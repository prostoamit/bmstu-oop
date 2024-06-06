#ifndef TRANSFORMERMOVE_HPP
#define TRANSFORMERMOVE_HPP

#include "Transformations/Transformer.hpp"

namespace Transformers {
    class Move : public Transformer {
    public:
        Move(double x_delta, double y_delta, double z_delta);
    };
}

#endif //TRANSFORMERMOVE_HPP
