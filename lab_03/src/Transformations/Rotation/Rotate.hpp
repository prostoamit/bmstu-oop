#ifndef TRANSFORMERROTATE_HPP
#define TRANSFORMERROTATE_HPP

#include "Transformer.hpp"

namespace Transformers {
    class Rotate : public Transformer {
    public:
        Rotate(double x_axis_angle, double y_axis_angle, double z_axis_angle);

        virtual void transform(Point &point) override;

    private:
        double x_axis_angle;
        double y_axis_angle;
        double z_axis_angle;
    };
}

#endif //TRANSFORMERROTATE_HPP
