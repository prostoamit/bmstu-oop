#ifndef APPLOGIC_HPP
#define APPLOGIC_HPP

#include <memory>
#include <string>

#include "QtInterface/AppLogic/AppData.hpp"

#include "Commands/Commands.hpp"

#include "Commands/Facade.hpp"

class AppLogic {
public:
    AppLogic();

    void draw();

    void load_object(const std::string& path, const std::string& implementation_type);
    void delete_object();
    void set_active_object(const std::string& name);

    void move_object(double x_delta, double y_delta, double z_delta);
    void rotate_object(double x_axis_angle, double y_axis_angle, double z_axis_angle);
    void scale_object(double x_coefficient, double y_coefficient, double z_coefficient);

    void move_all_objects(double x_delta, double y_delta, double z_delta);
    void rotate_all_objects(double x_axis_angle, double y_axis_angle, double z_axis_angle);
    void scale_all_objects(double x_coefficient, double y_coefficient, double z_coefficient);

    void add_camera();
    void delete_camera();
    void set_active_camera(const std::string& name);

    void move_camera(double x_delta, double y_delta, double z_delta);
    void rotate_camera(double x_axis_angle, double y_axis_angle, double z_axis_angle);

    std::shared_ptr<AppData> get_data();


private:
    std::shared_ptr<AppData> data;
    std::shared_ptr<Facade> facade;
};


#endif //APPLOGIC_HPP
