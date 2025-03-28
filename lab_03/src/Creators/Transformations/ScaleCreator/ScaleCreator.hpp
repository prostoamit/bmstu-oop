#ifndef SCALECREATOR_HPP
#define SCALECREATOR_HPP

#include <memory>

#include "Creators/Transformations/TransformationCreator.hpp"

namespace Transformers {
    class ScaleCreator : public TransformerCreator {
    public:
        std::shared_ptr<Transformer> create(double, double, double) override;
    };
}

#endif //SCALECREATOR_HPP
