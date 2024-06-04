#ifndef WIREFRAMEMODELIMPLEMENTATIONMATRIX_HPP
#define WIREFRAMEMODELIMPLEMENTATIONMATRIX_HPP

#include "WireframeModelImplementation/Implementation.hpp"

#include <vector>

namespace WireframeModelImplementation {
    class Matrix : public Implementation {
    public:
        virtual void add_edge(std::shared_ptr<Edge> edge) override;

        virtual Container<std::shared_ptr<Edge>> &get_edges() override;

    private:
        std::vector<std::vector<bool>> matrix;
    };
}

#endif //WIREFRAMEMODELIMPLEMENTATIONMATRIX_HPP
