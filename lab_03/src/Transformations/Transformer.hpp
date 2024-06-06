#ifndef TRANSFORMER_HPP
#define TRANSFORMER_HPP

#include <memory>

#include "Geometry/TransformationMatrix.hpp"

#include "Geometry/Point.hpp"

namespace Transformers {
    class Transformer {
    public:
        Transformer();
        virtual ~Transformer() = default;

        void transform(std::shared_ptr<Point> point) const ;
        std::shared_ptr<Point> transform_get(std::shared_ptr<Point> point) const;

        Transformer operator*(const Transformer& other) const;
        Transformer& operator*=(const Transformer& other);

    protected:
        std::shared_ptr<TransformationMatrix> matrix;
    };
}

#endif //TRANSFORMER_HPP
