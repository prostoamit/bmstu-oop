#ifndef VERTICESPAIRSWIREFRAMEMODELBUILDER_HPP
#define VERTICESPAIRSWIREFRAMEMODELBUILDER_HPP

#include <memory>

#include "WireframeModelBuilder.hpp"
#include "WireframeModelSourceAdapter.hpp"

namespace WireframeModel {
    class VerticesPairsBuilder : public Builder {
    public:
        VerticesPairsBuilder(std::shared_ptr<SourceAdapter> source);

        virtual void build_vertices() override;
        virtual void build_edges() override;
    };
}


#endif //VERTICESPAIRSWIREFRAMEMODELBUILDER_HPP
