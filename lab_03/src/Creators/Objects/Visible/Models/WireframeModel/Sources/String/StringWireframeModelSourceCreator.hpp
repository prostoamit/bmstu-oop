#ifndef STRINGWIREFRAMEMODELSOURCECREATOR_HPP
#define STRINGWIREFRAMEMODELSOURCECREATOR_HPP

#include <memory>
#include <string>

#include "WireframeModelSourceCreator.hpp"
#include "WireframeModelSourceStringAdapter.hpp"

namespace WireframeModel {
    class StringSourceCreator : public SourceCreator {
    public:
        std::shared_ptr<SourceAdapter> create(const std::string& path) override;
    };
}

class StringWireframeModelSourceCreator {

};


#endif //STRINGWIREFRAMEMODELSOURCECREATOR_HPP
