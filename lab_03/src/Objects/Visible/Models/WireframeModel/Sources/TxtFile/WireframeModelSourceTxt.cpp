#include "WireframeModelSourceTxt.hpp"

#include <fstream>

WireframeModel::TxtSource::TxtSource(const std::string& path) :
        file(std::fstream(path, std::fstream::in)),
        parse_data({0, 0, 0, 0})
        {}

std::optional<std::shared_ptr<Point>> WireframeModel::TxtSource::read_vertex() {
    if (parse_data.vertices_count == 0 && parse_data.current_vertex == 0)
        file >> parse_data.vertices_count;

    if (parse_data.current_vertex >= parse_data.vertices_count)
        return std::nullopt;

    double x, y, z;
    file >> x >> y >> z;
    parse_data.current_vertex++;
    return std::make_shared<Point>(x, y, z);
}

std::optional<std::shared_ptr<Edge>> WireframeModel::TxtSource::read_edge() {
    if (parse_data.current_vertex < parse_data.vertices_count)
        return std::nullopt;

    if (parse_data.edges_count == 0 && parse_data.current_edge == 0)
        file >> parse_data.edges_count;

    if (parse_data.current_edge >= parse_data.edges_count)
        return std::nullopt;

    size_t vertex_1_position, vertex_2_position;
    file >> vertex_1_position >> vertex_2_position;
    parse_data.current_edge++;
    return std::make_shared<Edge>(vertex_1_position, vertex_2_position);

}

