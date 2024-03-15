#include "errors.h"

#include <QMessageBox>

static void
error_box(const char *message) {
    QMessageBox::critical(NULL, "Ошибка", message);
}

void
error_handler(error_e &error) {
    switch (error) {
    case FILE_OPEN_ERROR:
        error_box("Ошибка при открытии файла.");
        break;
    case FILE_NULL_ERROR:
        error_box("Файл не передан.");
        break;
    case FILE_POINT_READ_ERROR:
        error_box("Ошибка чтения точки из файла.");
        break;
    case FILE_POINT_WRITE_ERROR:
        error_box("Ошибка записи точки в файл.");
        break;
    case FILE_EDGE_READ_ERROR:
        error_box("Ошибка чтения ребра из файла.");
        break;
    case FILE_EDGE_WRITE_ERROR:
        error_box("Ошибка записи ребра в файл.");
        break;
    case MEMORY_ALLOCATE_ERROR:
        error_box("Ошибка выделения памяти.");
        break;
    default:
        error_box("Неизвестная ошибка.");
        break;
    }
}
