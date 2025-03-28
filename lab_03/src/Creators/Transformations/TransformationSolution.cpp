#include "TransformationSolution.hpp"

#include "Creators/Transformations/MoveCreator/MoveCreator.hpp"
#include "Creators/Transformations/ScaleCreator/ScaleCreator.hpp"
#include "Creators/Transformations/RotateCreator/RotateCreator.hpp"

using namespace Transformers;

std::map<std::string, std::shared_ptr<TransformerCreator>> TransformationSolution::creators_map {
        { "move", std::make_shared<MoveCreator>() },
        { "scale", std::make_shared<ScaleCreator>() },
        { "rotate", std::make_shared<RotateCreator>() },
};

std::shared_ptr<TransformerCreator> TransformationSolution::get(const std::string& type) {
    return TransformationSolution::creators_map[type];
}

void TransformationSolution::register_creator(const std::string& key, std::shared_ptr<TransformerCreator> creator) {
    TransformationSolution::creators_map[key] = creator;
}
