#ifndef CAMERAS_HPP
#define CAMERAS_HPP

#include <memory>
#include <map>

#include "Objects/Composite/ObjectComposite.hpp"
#include "Objects/Invisible/Cameras/Camera.hpp"

#include "Common/Container.hpp"

class Cameras {
public:
    using container = std::map<size_t, std::shared_ptr<Camera>>;

    Cameras();

    std::shared_ptr<Camera> get_camera(size_t id);
    void add_camera(std::shared_ptr<Camera> camera);
    void remove_camera(size_t id);

    container::iterator begin();
    container::iterator end();

    Cameras::container& get_cameras();

private:
    std::map<size_t, std::shared_ptr<Camera>> cameras;
};


#endif //CAMERAS_HPP
