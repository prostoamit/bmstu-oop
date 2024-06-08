#include "WireframeModelDirectorSolution.hpp"

std::shared_ptr<WireframeModel::Director> WireframeModel::DirectorSolution::get(std::shared_ptr<Builder> builder) {
    return std::make_shared<Director>(builder);
}
