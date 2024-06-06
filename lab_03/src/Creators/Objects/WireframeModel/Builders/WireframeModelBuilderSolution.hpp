#ifndef WIREFRAMEMODELBUILDERSOLUTION_HPP
#define WIREFRAMEMODELBUILDERSOLUTION_HPP

#include <memory>
#include <string>
#include <map>

#include "Creators/Objects/WireframeModel/Builders/WireframeModelBuilderCreator.hpp"
#include "Objects/Visible/Models/WireframeModel/Sources/WireframeModelSource.hpp"

namespace WireframeModel {
    class BuilderSolution {
    public:
        static std::shared_ptr<BuilderCreator> get(const std::string& implementation_type);

        static void register_builder(std::string key, std::shared_ptr<BuilderCreator> builder_creator);

    private:
        static std::map<std::string, std::shared_ptr<BuilderCreator>> builders_map;
    };
}

#endif //WIREFRAMEMODELBUILDERSOLUTION_HPP
