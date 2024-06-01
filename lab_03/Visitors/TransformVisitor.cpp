#include "TransformVisitor.hpp"

TransformVisitor::TransformVisitor(std::shared_ptr<Transformer> transformer) : transformer(transformer) {}

void TransformVisitor::visit(ObjectComposite &composite) {
    for (auto& i : composite)
        i.second->accept(std::make_shared<Visitor>(*this));
}
