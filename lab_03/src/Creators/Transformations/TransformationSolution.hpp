#ifndef TRANSFORMATIONSOLUTION_HPP
#define TRANSFORMATIONSOLUTION_HPP

#include <memory>
#include <string>
#include <map>

#include "Creators/Transformations/TransformationCreator.hpp"

namespace Transformers {
    class TransformationSolution {
    public:
        static std::shared_ptr<TransformerCreator> get(const std::string& type);

        static void register_creator(const std::string& key, std::shared_ptr<TransformerCreator> creator);
    protected:
        static std::map<std::string, std::shared_ptr<TransformerCreator>> creators_map;
    };
}

#endif //TRANSFORMATIONSOLUTION_HPP
