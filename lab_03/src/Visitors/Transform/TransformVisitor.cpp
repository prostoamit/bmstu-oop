#include "TransformVisitor.hpp"

#include <utility>

TransformVisitor::TransformVisitor(std::shared_ptr<Transformers::Transformer> transformer) : transformer(std::move(transformer)) {}

void TransformVisitor::visit(ObjectComposite &composite) {
    for (auto& i : composite)
        i.second->accept(shared_from_this());
}

void TransformVisitor::visit(WireframeModel &model) {
    for (auto& i : model._implementation->get_vertices())
        transformer->transform(*i);
}

void TransformVisitor::visit(ParallelProjectionCamera &camera) {
    //
}