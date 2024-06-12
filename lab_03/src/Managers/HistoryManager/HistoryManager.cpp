#include "HistoryManager.hpp"

#include "ManagerSolution.hpp"

#include "NoMementoException.hpp"

void HistoryManager::save_state() {
    auto scene_manager = ManagerSolution::get_scene_manager();
    auto scene = scene_manager->get_scene();

    auto active_object = scene_manager->get_active_object();
    auto active_object_id = active_object->get_id();
    auto active_object_memento = active_object->create_memento();

    if (caretakers.find(active_object_id) == caretakers.end())
        caretakers[active_object_id] = std::make_shared<ObjectCareTaker>();

    caretakers[active_object_id]->add(active_object_memento);
}

void HistoryManager::undo() {
    auto scene_manager = ManagerSolution::get_scene_manager();
    auto scene = scene_manager->get_scene();

    auto active_object = scene_manager->get_active_object();
    auto active_object_id = active_object->get_id();

    if (caretakers.find(active_object_id) == caretakers.end())
        throw Exceptions::NoMementoException(__FILE__, __LINE__);

    auto memento = caretakers[active_object_id]->undo();
    active_object->restore_memento(memento);
}

void HistoryManager::redo() {
    auto scene_manager = ManagerSolution::get_scene_manager();
    auto scene = scene_manager->get_scene();

    auto active_object = scene_manager->get_active_object();
    auto active_object_id = active_object->get_id();

    if (caretakers.find(active_object_id) == caretakers.end())
        throw Exceptions::NoMementoException(__FILE__, __LINE__);

    auto memento = caretakers[active_object_id]->redo();
    active_object->restore_memento(memento);
}

void HistoryManager::remove(size_t id) {
    caretakers[id].reset();
    caretakers.erase(id);
}
