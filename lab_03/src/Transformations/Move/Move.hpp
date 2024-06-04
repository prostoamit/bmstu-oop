#ifndef TRANSFORMERMOVE_HPP
#define TRANSFORMERMOVE_HPP

#include "Transformer.hpp"

namespace Transformers {
    class Move : public Transformer {
    public:
        Move(double x_delta, double y_delta, double z_delta);

        virtual void transform(Point &point) override;

    private:
        double x_delta;
        double y_delta;
        double z_delta;
    };
}

#endif //TRANSFORMERMOVE_HPP
