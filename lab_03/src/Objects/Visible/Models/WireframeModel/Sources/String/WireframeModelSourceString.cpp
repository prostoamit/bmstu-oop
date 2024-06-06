#include "WireframeModelSourceString.hpp"

#include <cstdio>

WireframeModel::StringSource::StringSource(char* string) :
        string(string),
        reader (string),
        parse_data({0, 0, 0, 0}) {}

std::optional<std::shared_ptr<Point>> WireframeModel::StringSource::read_vertex() {
    size_t read = 0;
    if (parse_data.vertices_count == 0 && parse_data.current_vertex == 0) {
        read = sscanf(reader, "%zu", &parse_data.vertices_count);
        reader += read;
    }

    if (parse_data.current_vertex >= parse_data.vertices_count)
        return std::nullopt;

    double x, y, z;
    read = sscanf(reader, "%lf%lf%lf", &x, &y, &z);
    reader += read;

    return std::make_shared<Point>(x, y, z);
}

std::optional<std::shared_ptr<Edge>> WireframeModel::StringSource::read_edge() {
    size_t read = 0;

    if (parse_data.current_vertex < parse_data.vertices_count)
        return std::nullopt;

    if (parse_data.edges_count == 0 && parse_data.current_edge == 0) {
        read = sscanf(reader, "%zu", &parse_data.edges_count);
        reader += read;
    }

    if (parse_data.current_edge >= parse_data.edges_count)
        return std::nullopt;

    size_t vertex_1_position, vertex_2_position;
    read = sscanf(reader, "%zu%zu", &vertex_1_position, &vertex_2_position);
    reader += read;

    return std::make_shared<Edge>(vertex_1_position, vertex_2_position);
}

