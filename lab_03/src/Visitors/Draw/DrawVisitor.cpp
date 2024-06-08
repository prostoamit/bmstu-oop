#include "DrawVisitor.hpp"

#include "Geometry/Point2D.hpp"

#include "Creators/Transformations/TransformationSolution.hpp"

DrawVisitor::DrawVisitor(std::shared_ptr<Drawer::Line> line_drawer, std::shared_ptr<Camera> camera) :
        line_drawer(line_drawer),
        camera(camera) {}

void DrawVisitor::visit(ObjectComposite& composite) {
    for (auto& i : composite)
        i.second->accept(shared_from_this());
}

void DrawVisitor::visit(WireframeModel::WireframeModel& model) {
    transformer = camera->get_view_transformer();
    Container<std::shared_ptr<Point>>& vertices = model._implementation->get_vertices();

    for (auto& i : model._implementation->get_edges()) {
        std::shared_ptr<Point> modified_point_1 = transformer->transform_get(vertices[i->get_vertex_1_position()]);
        std::shared_ptr<Point> modified_point_2 = transformer->transform_get(vertices[i->get_vertex_2_position()]);

//        if (modified_point_1->get_z() < 0 || modified_point_2->get_z() < 0)
//            return;

        Point2D projection_1(modified_point_1->get_x(), modified_point_1->get_y());
        Point2D projection_2(modified_point_2->get_x(), modified_point_2->get_y());

        line_drawer->draw(projection_1, projection_2);
    }
}

void DrawVisitor::visit(ParallelProjectionCamera& camera) {
}
