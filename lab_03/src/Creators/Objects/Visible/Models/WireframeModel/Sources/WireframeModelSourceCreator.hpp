#ifndef WIREFRAMEMODELSOURCECREATOR_HPP
#define WIREFRAMEMODELSOURCECREATOR_HPP

#include <memory>
#include <string>

#include "Objects/Visible/Models/WireframeModel/Sources/WireframeModelSourceAdapter.hpp"

namespace WireframeModel {
    class SourceCreator {
    public:
        virtual std::shared_ptr<SourceAdapter> create(const std::string& path) = 0;
    };
}

#endif //WIREFRAMEMODELSOURCECREATOR_HPP
