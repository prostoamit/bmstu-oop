#include "WireframeModelSourceTxtAdapter.hpp"

#include <sstream>

using namespace WireframeModel;

TxtSource::TxtSource(std::shared_ptr<Source> source) :
        source(source),
        parse_data({ 0, 0, 0, 0 }) {}

std::optional<std::shared_ptr<Point>> TxtSource::read_vertex() {
    std::stringstream line;

    if (parse_data.vertices_count == 0 && parse_data.current_vertex == 0) {
        line << source->read_line(256);
        line >> parse_data.vertices_count;
        line.clear();
    }

    if (parse_data.current_vertex >= parse_data.vertices_count)
        return std::nullopt;

    double x, y, z;
    line << source->read_line(256);
    line >> x >> y >> z;
    parse_data.current_vertex++;
    return std::make_shared<Point>(x, y, z);
}

std::optional<std::shared_ptr<Edge>> WireframeModel::TxtSource::read_edge() {
    std::stringstream line;

    if (parse_data.current_vertex < parse_data.vertices_count)
        return std::nullopt;

    if (parse_data.edges_count == 0 && parse_data.current_edge == 0) {
        line << source->read_line(256, '\n');
        line >> parse_data.edges_count;
        line.clear();
    }

    if (parse_data.current_edge >= parse_data.edges_count)
        return std::nullopt;

    size_t vertex_1_position, vertex_2_position;
    line << source->read_line(256, '\n');
    line >> vertex_1_position >> vertex_2_position;
    parse_data.current_edge++;
    return std::make_shared<Edge>(vertex_1_position, vertex_2_position);

}

