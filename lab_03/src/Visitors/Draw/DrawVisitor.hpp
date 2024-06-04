#ifndef DRAWVISITOR_HPP
#define DRAWVISITOR_HPP

#include <memory>

#include "Visitor.hpp"


class DrawVisitor : Visitor {
public:
    DrawVisitor();

    virtual void visit(ObjectComposite &composite) override;
    virtual void visit(WireframeModel &model) override;
    virtual void visit(ParallelProjectionCamera &camera) override;
};


#endif //DRAWVISITOR_HPP
