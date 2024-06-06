#include "TxtWireframeModelSourceCreator.hpp"

std::shared_ptr<WireframeModel::Source> WireframeModel::TxtSourceCreator::create(const std::string& path) {
    return std::make_shared<WireframeModel::TxtSource>(path);
}
