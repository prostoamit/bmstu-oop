#ifndef TRANSFORMATIONCREATOR_HPP
#define TRANSFORMATIONCREATOR_HPP


#include <memory>

#include "Transformations/Transformer.hpp"

namespace Transformers {
    class TransformerCreator {
    public:
        virtual std::shared_ptr<Transformer> create(double, double, double) = 0;
    };
}

#endif //TRANSFORMATIONCREATOR_HPP
