#ifndef ACTIONS_H
#define ACTIONS_H

#include "../geometry/point.h"
#include "errors.h"
#include "../geometry/figure.h"
#include "../drawer/drawer.h"

#include <QGraphicsScene>

enum actions_keys {
    LOAD_FROM_FILE,
    LOAD_TO_FILE,
    MOVE,
    ROTATE,
    SCALE,
    QUIT,
    DRAW,
};

using actions_keys_e = actions_keys;

struct action {
    actions_keys_e key;
    union {
        QGraphicsScene *scene;
        const char *filename;
        move_deltas_t deltas;
        rotate_angles_t angles;
        scale_coeffs_t coeffs;
    };
};

using action_t = struct action;

error_e action_handler(const action_t &action);

#endif // ACTIONS_H
