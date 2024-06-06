#ifndef TRANSFORMVISITOR_HPP
#define TRANSFORMVISITOR_HPP

#include <memory>

#include "Visitors/Visitor.hpp"
#include "Transformations/Transformer.hpp"

class TransformVisitor : public Visitor {
public:
    TransformVisitor(std::shared_ptr<Transformers::Transformer> transformer);

    virtual void visit(CompositeObject& composite) override;
    virtual void visit(WireframeModel::WireframeModel& model) override;
    virtual void visit(ParallelProjectionCamera& camera) override;
private:
    std::shared_ptr<Transformers::Transformer> transformer;
};

#endif //TRANSFORMVISITOR_HPP
