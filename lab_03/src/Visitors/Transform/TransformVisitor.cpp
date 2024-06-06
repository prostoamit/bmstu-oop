#include "TransformVisitor.hpp"

#include <utility>

#include "Creators/Transformations/TransformationSolution.hpp"

TransformVisitor::TransformVisitor(std::shared_ptr<Transformers::Transformer> transformer) : transformer(std::move(transformer)) {}

void TransformVisitor::visit(CompositeObject &composite) {
    for (auto& i : composite)
        i.second->accept(shared_from_this());
}

void TransformVisitor::visit(WireframeModel::WireframeModel &model) {
    for (auto& i : model._implementation->get_vertices())
        transformer->transform(i);
}

void TransformVisitor::visit(ParallelProjectionCamera &camera) {
    auto move_transformer_creator = Transformers::TransformationSolution::get("move");

    auto move_to_center = move_transformer_creator->create(-camera.point->get_x(), -camera.point->get_y(), -camera.point->get_z());
    auto move_from_center = move_transformer_creator->create(camera.point->get_x(), camera.point->get_y(), camera.point->get_z());

    *camera.transformer * *move_to_center;
    *camera.transformer * *transformer;
    *camera.transformer * *move_from_center;
}