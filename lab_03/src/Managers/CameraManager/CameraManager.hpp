#ifndef CAMERAMANAGER_HPP
#define CAMERAMANAGER_HPP

#include <memory>
#include "Scene/Cameras.hpp"
#include "Objects/Invisible/Cameras/Camera.hpp"

class CameraManager {
public:
    std::shared_ptr<Cameras> get_cameras() const;
    void set_cameras(std::shared_ptr<Cameras> cameras);

    void camera_move(double x_delta, double y_delta, double z_delta);
    void camera_rotate(double x_axis_angle, double y_axis_angle, double z_axis_angle);

    std::shared_ptr<Camera> get_camera(size_t id) const;
    void add_camera(std::shared_ptr<Camera> camera);
    void remove_camera(size_t id);

    std::shared_ptr<Camera> get_active_camera() const;
    void set_active_camera(std::shared_ptr<Camera> camera);

protected:
    CameraManager();
    CameraManager(const CameraManager& other) = default;

private:
    std::shared_ptr<Cameras> cameras;
    std::shared_ptr<Camera> active_camera;
};


#endif //CAMERAMANAGER_HPP
