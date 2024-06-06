#ifndef DRAWVISITOR_HPP
#define DRAWVISITOR_HPP

#include <memory>

#include "Visitors/Visitor.hpp"
#include "Objects/Invisible/Cameras/Camera.hpp"
#include "Creators/DrawerFactories/ShapeDrawerFactory.hpp"
#include "Transformations/Transformer.hpp"

class DrawVisitor : public Visitor {
public:
    DrawVisitor(std::shared_ptr<Drawer::Line> line_drawer, std::shared_ptr<Camera> camera);

    virtual void visit(CompositeObject& composite) override;
    virtual void visit(WireframeModel::WireframeModel& model) override;
    virtual void visit(ParallelProjectionCamera& camera) override;

private:
    std::shared_ptr<Drawer::Line> line_drawer;
    std::shared_ptr<Camera> camera;
    std::shared_ptr<Transformers::Transformer> transformer;
};

#endif //DRAWVISITOR_HPP
