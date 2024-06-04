#ifndef PARALLELPROJECTIONCAMERA_HPP
#define PARALLELPROJECTIONCAMERA_HPP

#include "Camera.hpp"

class ParallelProjectionCamera : Camera {
public:
    void accept(std::shared_ptr<Visitor> visitor) override;
};


#endif //PARALLELPROJECTIONCAMERA_HPP
