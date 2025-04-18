#include "WireframeModelBuilderSolution.hpp"

#include "AdjacencyListWireframeModelBuilderCreator.hpp"
#include "MatrixWireframeModelBuilderCreator.hpp"
#include "VerticesPairsWireframeModelBuilderCreator.hpp"

using namespace WireframeModel;

std::map<std::string, std::shared_ptr<BuilderCreator>> BuilderSolution::builders_map {
        { "adjacencylist", std::make_shared<AdjacencyListBuilderCreator>() },
        { "matrix", std::make_shared<MatrixBuilderCreator>() },
        { "verticespairs", std::make_shared<VerticesPairsBuilderCreator>() },
};

std::shared_ptr<BuilderCreator> BuilderSolution::get(const std::string& implementation_type) {
    return builders_map[implementation_type];
}

void BuilderSolution::register_builder(std::string key, std::shared_ptr<BuilderCreator> builder) {
    builders_map[key] = builder;
}
