#ifndef ROTATECREATOR_HPP
#define ROTATECREATOR_HPP

#include <memory>

#include "Creators/Transformations/TransformationCreator.hpp"

namespace Transformers {
    class RotateCreator : public TransformerCreator {
    public:
        std::shared_ptr<Transformer> create(double, double, double) override;
    };
}

#endif //ROTATECREATOR_HPP
