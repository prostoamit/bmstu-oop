#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <memory>

#include "Objects/Invisible/InvisibleObject.hpp"

#include "Geometry/Point.hpp"
#include "Geometry/Vector.hpp"
#include "Transformations/Transformer.hpp"

class DrawVisitor;

class Camera : public InvisibleObject {
public:
    virtual void accept(std::shared_ptr<Visitor> visitor) override;

    friend DrawVisitor;
protected:
    virtual std::shared_ptr<Transformers::Transformer> get_view_transformer() = 0;

    std::shared_ptr<Point> point;
};

#endif //CAMERA_HPP
