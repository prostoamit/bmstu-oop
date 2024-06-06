#ifndef VISITOR_HPP
#define VISITOR_HPP

#include "Objects/Composite/CompositeObject.hpp"
#include "Objects/Visible/Models/WireframeModel/WireframeModel.hpp"
#include "Objects/Invisible/Cameras/ParallelProjectionCamera/ParallelProjectionCamera.hpp"

class Visitor : public std::enable_shared_from_this<Visitor> {
public:
    virtual ~Visitor() = default;

    virtual void visit(CompositeObject& composite) = 0;
    virtual void visit(WireframeModel::WireframeModel& model) = 0;
    virtual void visit(ParallelProjectionCamera& camera) = 0;
};

#endif //VISITOR_HPP
