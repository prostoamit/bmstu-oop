#ifndef WIREFRAMEMODELSOURCESTRINGADAPTER_HPP
#define WIREFRAMEMODELSOURCESTRINGADAPTER_HPP

#include <string>
#include <optional>
#include <fstream>

#include "WireframeModelSourceAdapter.hpp"

namespace WireframeModel {
    class StringSourceAdapter : public SourceAdapter {
    public:
        explicit StringSourceAdapter(std::shared_ptr<Source> source);

        virtual std::optional<std::shared_ptr<Point>> read_vertex() override;
        virtual std::optional<std::shared_ptr<Edge>> read_edge() override;

    private:
        std::shared_ptr<Source> source;

        struct {
            size_t vertices_count;
            size_t current_vertex;
            size_t edges_count;
            size_t current_edge;
        } parse_data;
    };
}


#endif //WIREFRAMEMODELSOURCESTRINGADAPTER_HPP
