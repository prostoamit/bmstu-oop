#ifndef WIREFRAMEMODELSOURCESTRING_HPP
#define WIREFRAMEMODELSOURCESTRING_HPP

#include <string>
#include <optional>
#include <fstream>

#include "Objects/Visible/Models/WireframeModel/Sources/WireframeModelSource.hpp"

namespace WireframeModel {
    class StringSource : public Source {
    public:
        StringSource(char* string);

        virtual std::optional<std::shared_ptr<Point>> read_vertex() override;
        virtual std::optional<std::shared_ptr<Edge>> read_edge() override;

    private:
        char* string;
        char* reader;

        struct {
            size_t vertices_count;
            size_t current_vertex;
            size_t edges_count;
            size_t current_edge;
        } parse_data;
    };
}


#endif //WIREFRAMEMODELSOURCESTRING_HPP
