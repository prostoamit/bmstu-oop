#ifndef WIREFRAMEMODELBUILDER_HPP
#define WIREFRAMEMODELBUILDER_HPP

#include <memory>

#include "WireframeModel.hpp"
#include "WireframeModelSourceAdapter.hpp"
#include "WireframeModelImplementation.hpp"

namespace WireframeModel {
    class Builder {
    public:
        virtual ~Builder() = default;

        virtual void build_vertices() = 0;
        virtual void build_edges() = 0;

        virtual std::shared_ptr<Object> get();
    protected:
        std::shared_ptr<SourceAdapter> source;

        std::shared_ptr<Implementation> implementation;

        size_t progress;
    };
}

#endif //WIREFRAMEMODELBUILDER_HPP
