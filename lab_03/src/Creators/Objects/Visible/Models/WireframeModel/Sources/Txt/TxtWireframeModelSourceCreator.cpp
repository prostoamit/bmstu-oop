#include "TxtWireframeModelSourceCreator.hpp"

#include "Source.hpp"
#include "TxtFileSource.hpp"

std::shared_ptr<WireframeModel::SourceAdapter> WireframeModel::TxtSourceCreator::create(const std::string& path) {
    return std::make_shared<TxtSource>(std::make_shared<TxtFileSource>(path));
}
