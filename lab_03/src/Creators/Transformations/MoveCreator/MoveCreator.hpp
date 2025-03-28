#ifndef MOVECREATOR_HPP
#define MOVECREATOR_HPP

#include <memory>

#include "Creators/Transformations/TransformationCreator.hpp"

namespace Transformers {
    class MoveCreator : public TransformerCreator {
    public:
        std::shared_ptr<Transformer> create(double, double, double) override;
    };
}

#endif //MOVECREATOR_HPP
