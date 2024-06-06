#ifndef TXTWIREFRAMEMODELSOURCECREATOR_HPP
#define TXTWIREFRAMEMODELSOURCECREATOR_HPP

#include <memory>
#include <string>

#include "Creators/Objects/WireframeModel/Sources/WireframeModelSourceCreator.hpp"
#include "Objects/Visible/Models/WireframeModel/Sources/TxtFile/WireframeModelSourceTxt.hpp"

namespace WireframeModel {
class TxtSourceCreator : public SourceCreator {
    public:
        std::shared_ptr<Source> create(const std::string& path) override;
    };
}

#endif //TXTWIREFRAMEMODELSOURCECREATOR_HPP
