#ifndef TRANSFORMVISITOR_HPP
#define TRANSFORMVISITOR_HPP

#include <memory>

#include "Visitor.hpp"
#include "Transformer.hpp"

class TransformVisitor : Visitor {
public:
    TransformVisitor(std::shared_ptr<Transformer> transformer);

    virtual void visit(ObjectComposite &composite) override;
    virtual void visit(WireframeModel &model) override;
    virtual void visit(ParallelProjectionCamera &camera) override;
private:
    std::shared_ptr<Transformer> transformer;
};


#endif //TRANSFORMVISITOR_HPP
