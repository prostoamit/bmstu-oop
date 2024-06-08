#ifndef TRANSFORMMANAGER_HPP
#define TRANSFORMMANAGER_HPP

#include <string>

#include "Visitors/Transform/TransformVisitor.hpp"

class TransformManager {
public:
    void move(const std::string& name, double x_delta, double y_delta, double z_delta) const;
    void rotate(const std::string& name, double x_axis_angle, double y_axis_angle, double z_axis_angle) const;
    void scale(const std::string& name, double x_coefficient, double y_coefficient, double z_coefficient) const;
protected:
    TransformManager() = default;
    TransformManager(const TransformManager& other) = default;

    template<typename... Args>
    void applyTransformation(const std::string& name, const std::string& transformationType, Args... args) const;
};


#endif //TRANSFORMMANAGER_HPP
