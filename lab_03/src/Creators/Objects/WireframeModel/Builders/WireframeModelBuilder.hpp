#ifndef WIREFRAMEMODELBUILDER_HPP
#define WIREFRAMEMODELBUILDER_HPP

#include <memory>

#include "Objects/Visible/Models/WireframeModel/WireframeModel.hpp"
#include "Objects/Visible/Models/WireframeModel/Sources/WireframeModelSource.hpp"
#include "Objects/Visible/Models/WireframeModel/Implementation/WireframeModelImplementation.hpp"

namespace WireframeModel {
    class Builder {
    public:
        Builder(std::shared_ptr<Source> source);
        virtual ~Builder() = default;

        void build_vertices();
        void build_edges();

        std::shared_ptr<WireframeModel> get();
    protected:
        std::shared_ptr<Source> source;

        std::shared_ptr<Implementation> implementation;

        size_t progress;
    };
}

#endif //WIREFRAMEMODELBUILDER_HPP
