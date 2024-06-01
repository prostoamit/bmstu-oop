#ifndef TRANSFORMER_HPP
#define TRANSFORMER_HPP

#include <array>

#include "Point.hpp"

class Transformer {
public:
    virtual ~Transformer() = default;

    virtual void transform(Point &point) = 0;
};


#endif //TRANSFORMER_HPP
