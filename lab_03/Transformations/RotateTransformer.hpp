#ifndef ROTATETRANSFORMER_HPP
#define ROTATETRANSFORMER_HPP

#include "Transformer.hpp"

#include <array>

class RotateTransformer : Transformer {
public:
    void transform(Point &point) override;

private:
    std::array<std::array<double, 4>, 4> matrix;
};


#endif //ROTATETRANSFORMER_HPP
