#ifndef WIREFRAMEMODELIMPLEMENTATIONMATRIX_HPP
#define WIREFRAMEMODELIMPLEMENTATIONMATRIX_HPP

#include "Objects/Visible/Models/WireframeModel/Implementation/WireframeModelImplementation.hpp"

#include <vector>

namespace WireframeModel {
    class Matrix : public Implementation {
    public:
        Matrix() = default;
        Matrix(const Matrix& other);
        Matrix(Matrix&& other) = default;

        Matrix(Container<std::shared_ptr<Point>>& vertices, Container<std::shared_ptr<Edge>>& edges);

        virtual void add_edge(std::shared_ptr<Edge> edge) override;

        virtual Container<std::shared_ptr<Edge>> &get_edges() override;

        virtual std::shared_ptr<Implementation> clone() override;

    private:
        std::vector<std::vector<bool>> matrix;
    };
}

#endif //WIREFRAMEMODELIMPLEMENTATIONMATRIX_HPP
