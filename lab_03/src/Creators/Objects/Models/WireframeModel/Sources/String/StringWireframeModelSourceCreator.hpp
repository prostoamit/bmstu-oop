#ifndef STRINGWIREFRAMEMODELSOURCECREATOR_HPP
#define STRINGWIREFRAMEMODELSOURCECREATOR_HPP

#include <memory>
#include <string>

#include "Creators/Objects/Models/WireframeModel/Sources/WireframeModelSourceCreator.hpp"
#include "Objects/Visible/Models/WireframeModel/Sources/String/WireframeModelSourceString.hpp"

namespace WireframeModel {
    class StringSourceCreator : public SourceCreator {
    public:
        std::shared_ptr<Source> create(const std::string& path) override;
    };
}

class StringWireframeModelSourceCreator {

};


#endif //STRINGWIREFRAMEMODELSOURCECREATOR_HPP
