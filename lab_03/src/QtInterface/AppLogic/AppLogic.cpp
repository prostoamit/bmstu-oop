#include "AppLogic.hpp"

#include <filesystem>

AppLogic::AppLogic() :
        facade(std::make_shared<Facade>()),
        data(std::make_shared<AppData>()){}

void AppLogic::draw() {
    auto command = std::make_shared<DrawSceneCommand>();

    facade->apply(command);
}

void AppLogic::load_object(const std::string& path, const std::string& implementation_type) {
    auto command = std::make_shared<LoadModelCommand>(path, implementation_type);

    facade->apply(command);

    std::filesystem::path file_path(path);
    std::string file_name = file_path.filename();
    size_t current_object_id = command->result();

    data->add_object(file_name, current_object_id);
    data->set_active_object(file_name);

    draw();
}

void AppLogic::delete_object(const std::string& name) {
    auto command = std::make_shared<RemoveModelCommand>(name);

    facade->apply(command);

    size_t new_active_id = command->result();
    std::string new_active_name;

    for (auto& i : data->get_objects())
        if (i.second == new_active_id)
            new_active_name = i.first;

    data->set_active_object(new_active_name);
    draw();
}

void AppLogic::set_active_object(const std::string& name) {
    if (name == "")
        return;
    size_t id = data->get_objects()[name];

    auto command = std::make_shared<SetActiveModelCommand>(name);

    facade->apply(command);
    draw();
}

void AppLogic::move_object(double x_delta, double y_delta, double z_delta) {
    auto command = std::make_shared<ModelMoveCommand>(x_delta, y_delta, z_delta);

    facade->apply(command);
    draw();
}

void AppLogic::rotate_object(double x_axis_angle, double y_axis_angle, double z_axis_angle) {
    auto command = std::make_shared<ModelRotateCommand>(x_axis_angle, y_axis_angle, z_axis_angle);

    facade->apply(command);
    draw();
}

void AppLogic::scale_object(double x_coefficient, double y_coefficient, double z_coefficient) {
    auto command = std::make_shared<ModelScaleCommand>(x_coefficient, y_coefficient, z_coefficient);

    facade->apply(command);
    draw();
}

void AppLogic::move_all_objects(double x_delta, double y_delta, double z_delta) {
    auto command = std::make_shared<AllModelsMoveCommand>(x_delta, y_delta, z_delta);

    facade->apply(command);
    draw();
}

void AppLogic::rotate_all_objects(double x_axis_angle, double y_axis_angle, double z_axis_angle) {
    auto command = std::make_shared<AllModelsRotateCommand>(x_axis_angle, y_axis_angle, z_axis_angle);

    facade->apply(command);
    draw();
}

void AppLogic::scale_all_objects(double x_coefficient, double y_coefficient, double z_coefficient) {
    auto command = std::make_shared<AllModelsScaleCommand>(x_coefficient, y_coefficient, z_coefficient);

    facade->apply(command);
    draw();

}

void AppLogic::undo() {
    auto command = std::make_shared<UndoCommand>();

    facade->apply(command);
    draw();
}

void AppLogic::redo() {
    auto command = std::make_shared<RedoCommand>();

    facade->apply(command);
    draw();
}

void AppLogic::add_camera() {
    auto command = std::make_shared<AddCameraCommand>("parallelprojection");

    facade->apply(command);

    size_t current_camera_number = command->result();
    std::string current_camera_name = "Camera " + std::to_string(current_camera_number);

    data->add_camera(current_camera_name, current_camera_number);
    data->set_active_camera(current_camera_name);

    draw();
}

void AppLogic::delete_camera() {
    auto command = std::make_shared<RemoveCameraCommand>();

    facade->apply(command);

    size_t id = command->result();

    if (data->get_cameras().size() == 1)
        return;

    data->remove_camera(data->get_active_camera().first);
    if (id != 0) {
        data->add_camera("Camera 0", id);
    } else {
    }

    draw();
}

void AppLogic::set_active_camera(const std::string& name) {
    size_t camera_id = data->set_active_camera(name).second;

    auto command = std::make_shared<SetCameraCommand>(camera_id);

    facade->apply(command);
    draw();
}

void AppLogic::move_camera(double x_delta, double y_delta, double z_delta) {
    auto command = std::make_shared<MoveCameraCommand>(x_delta, y_delta, z_delta);

    facade->apply(command);
    draw();
}

void AppLogic::rotate_camera(double x_axis_angle, double y_axis_angle, double z_axis_angle) {
    auto command = std::make_shared<RotateCameraCommand>(x_axis_angle, y_axis_angle, z_axis_angle);

    facade->apply(command);
    draw();
}

std::shared_ptr<AppData> AppLogic::get_data() {
    return data;
}


