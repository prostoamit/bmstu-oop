#ifndef MATRIXWIREFRAMEMODELBUILDER_HPP
#define MATRIXWIREFRAMEMODELBUILDER_HPP

#include <memory>

#include "WireframeModelBuilder.hpp"
#include "WireframeModelSourceAdapter.hpp"

namespace WireframeModel {
    class MatrixBuilder : public Builder {
    public:
        MatrixBuilder(std::shared_ptr<SourceAdapter> source);

        virtual void build_edges() override;
        virtual void build_vertices() override;
    };
}

#endif //MATRIXWIREFRAMEMODELBUILDER_HPP
