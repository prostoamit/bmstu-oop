#include "actions.h"

error_e action_handler(const action_t &action) {
    static figure_t figure;

    error_e rc = SUCCESS;

    switch (action.key) {
    case LOAD_FROM_FILE:
        rc = figure_handle_file_scan(figure, action.filename);
        break;

    case MOVE:
        rc = figure_move(figure, action.deltas);
        break;

    case ROTATE:
        rc = figure_rotate(figure, action.angles);
        break;

    case SCALE:
        rc = figure_scale(figure, action.coeffs);
        break;

    case QUIT:
        figure_free(figure);
        break;

    case DRAW:
        rc = figure_draw(action.scene, figure);
        break;

    default:
        rc = BAD_ACTION_KEY_ERROR;
        break;
    }

    return rc;
}
