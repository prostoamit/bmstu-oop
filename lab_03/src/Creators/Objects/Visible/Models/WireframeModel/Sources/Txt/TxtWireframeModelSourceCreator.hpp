#ifndef TXTWIREFRAMEMODELSOURCECREATOR_HPP
#define TXTWIREFRAMEMODELSOURCECREATOR_HPP

#include <memory>
#include <string>

#include "WireframeModelSourceCreator.hpp"
#include "TxtFile/WireframeModelSourceTxtAdapter.hpp"

namespace WireframeModel {
class TxtSourceCreator : public SourceCreator {
    public:
        std::shared_ptr<SourceAdapter> create(const std::string& path) override;
    };
}

#endif //TXTWIREFRAMEMODELSOURCECREATOR_HPP
