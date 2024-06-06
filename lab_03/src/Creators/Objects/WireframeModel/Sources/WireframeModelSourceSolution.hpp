#ifndef WIREFRAMEMODELSOURCESOLUTION_HPP
#define WIREFRAMEMODELSOURCESOLUTION_HPP

#include <memory>
#include <string>
#include <map>

#include "Creators/Objects/WireframeModel/Sources/WireframeModelSourceCreator.hpp"

namespace WireframeModel {
    class SourceSolution {
    public:
        static std::shared_ptr<SourceCreator> get(const std::string& file_extension);

        static void register_creator(const std::string& key, std::shared_ptr<SourceCreator> creator);
    protected:
        static std::map<std::string, std::shared_ptr<SourceCreator>> creators_map;
    };
}

#endif //WIREFRAMEMODELSOURCESOLUTION_HPP
