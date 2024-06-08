#ifndef WIREFRAMEMODELSOURCESTRINGADAPTER_HPP
#define WIREFRAMEMODELSOURCESTRINGADAPTER_HPP

#include <string>
#include <optional>
#include <fstream>

#include "Objects/Visible/Models/WireframeModel/Sources/WireframeModelSourceAdapter.hpp"

namespace WireframeModel {
    class StringSourceAdapter : public SourceAdapter {
    public:
        explicit StringSourceAdapter(char* string);

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


#endif //WIREFRAMEMODELSOURCESTRINGADAPTER_HPP
