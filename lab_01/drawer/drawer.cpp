#include "drawer.h"

static error_e
edge_draw(QGraphicsScene *scene, edge_t &edge, points_t &points) {
    error_e rc = SUCCESS;
    if (scene == NULL)
        return NULL_SCENE_ERROR;
    if (points.size == 0)
        return EMPTY_POINTS_ERROR;
    if (edge.point_1 >= points.size || edge.point_2 >= points.size)
        return WRONG_EDGE_POINT_ERROR;


    scene->addLine(
        points.points[edge.point_1].x, points.points[edge.point_1].y,
        points.points[edge.point_2].x, points.points[edge.point_2].y
        );

    return rc;
}

static error_e
edges_draw(QGraphicsScene *scene, edges_t &edges, points_t &points) {
    error_e rc = SUCCESS;
    if (scene == NULL)
        return NULL_SCENE_ERROR;
    if (points.size == 0)
        return EMPTY_POINTS_ERROR;
    if (edges.size == 0)
        return EMPTY_EDGES_ERROR;

    for (size_t i = 0; i < edges.size; i++) {
        if (edges.edges[i].point_1 >= points.size || edges.edges[i].point_2 >= points.size) {
            rc = WRONG_EDGE_POINT_ERROR;
            break;
        }
        else
            rc = edge_draw(scene, edges.edges[i], points);
    }

    return rc;
}

static error_e
scene_clear(QGraphicsScene *scene) {
    error_e rc = SUCCESS;
    if (scene == NULL)
        return NULL_SCENE_ERROR;

    scene->clear();

    return rc;
}

error_e
figure_draw(QGraphicsScene *scene, figure_t &figure) {
    error_e rc = SUCCESS;
    if (scene == NULL)
        return NULL_SCENE_ERROR;

    scene->clear();

    rc = edges_draw(scene, figure.edges, figure.points);
    if (rc != SUCCESS)
        rc = scene_clear(scene);


    return rc;
}
