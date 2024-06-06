#ifndef WIREFRAMEMODELSOURCETXT_HPP
#define WIREFRAMEMODELSOURCETXT_HPP

#include <string>
#include <optional>
#include <fstream>

#include "Objects/Visible/Models/WireframeModel/Sources/WireframeModelSource.hpp"

namespace WireframeModel {
    class TxtSource : public Source {
    public:
        TxtSource(const std::string& path);

        virtual std::optional<std::shared_ptr<Point>> read_vertex() override;
        virtual std::optional<std::shared_ptr<Edge>> read_edge() override;

    private:
        std::fstream file;

        struct {
            size_t vertices_count;
            size_t current_vertex;
            size_t edges_count;
            size_t current_edge;
        } parse_data;
    };
}

#endif //WIREFRAMEMODELSOURCETXT_HPP
