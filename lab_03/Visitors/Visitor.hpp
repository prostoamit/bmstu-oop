#ifndef VISITOR_HPP
#define VISITOR_HPP

#include "ObjectComposite.hpp"
#include "WireframeModel.hpp"
#include "ParallelProjectionCamera.hpp"

class Visitor {
public:
    virtual ~Visitor() = default;

    virtual void visit(ObjectComposite& composite) = 0;
    virtual void visit(WireframeModel& model) = 0;
    virtual void visit(ParallelProjectionCamera& camera) = 0;
};


#endif //VISITOR_HPP
