#ifndef TRANSFORMATIONSFACTORY_HPP
#define TRANSFORMATIONSFACTORY_HPP

#include <memory>

#include "Transformer.hpp"

class Factory {
public:
    virtual ~Factory() = default;

    virtual std::unique_ptr<Transformers::Transformer> create() const = 0;
};


#endif //TRANSFORMATIONSFACTORY_HPP
