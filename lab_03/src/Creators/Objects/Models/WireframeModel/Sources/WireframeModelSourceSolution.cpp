#include "WireframeModelSourceSolution.hpp"

#include "Creators/Objects/Models/WireframeModel/Sources/Txt/TxtWireframeModelSourceCreator.hpp"

std::map<std::string, std::shared_ptr<WireframeModel::SourceCreator>> WireframeModel::SourceSolution::creators_map {
        { ".txt", std::make_shared<TxtSourceCreator>() },
};

std::shared_ptr<WireframeModel::SourceCreator> WireframeModel::SourceSolution::get(const std::string& file_extension) {
    return creators_map[file_extension];
}

void
WireframeModel::SourceSolution::register_creator(const std::string& key,
                                               std::shared_ptr<WireframeModel::SourceCreator> creator) {
    creators_map[key] = creator;
}
