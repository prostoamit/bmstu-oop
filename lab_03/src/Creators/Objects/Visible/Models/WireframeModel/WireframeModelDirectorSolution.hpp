#ifndef WIREFRAMEMODELDIRECTORSOLUTION_HPP
#define WIREFRAMEMODELDIRECTORSOLUTION_HPP

#include <memory>
#include "WireframeModelDirector.hpp"

namespace WireframeModel {
    class DirectorSolution {
    public:
        static std::shared_ptr<Director> get(std::shared_ptr<Builder>);
    };
}

#endif //WIREFRAMEMODELDIRECTORSOLUTION_HPP
