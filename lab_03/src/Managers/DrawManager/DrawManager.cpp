#include "DrawManager.hpp"

#include "Managers/ManagerSolution.hpp"
#include "Visitors/Draw/DrawVisitor.hpp"

void DrawManager::set_drawer(std::shared_ptr<Drawer::ShapeDrawerFactory> factory) {
    line_drawer = factory->create_line_drawer();
    screen_cleaner = factory->create_screen_cleaner();
}

void DrawManager::draw_scene() {
    auto scene_manager = ManagerSolution::get_scene_manager();

    screen_cleaner->draw();

    auto camera_manager = ManagerSolution::get_camera_manager();
    auto camera = camera_manager->get_active_camera();

    std::shared_ptr<DrawVisitor> draw_visitor = std::make_shared<DrawVisitor>(line_drawer, camera);

    scene_manager->get_scene()->get_objects()->accept(draw_visitor);
}
