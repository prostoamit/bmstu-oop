#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>

#include "Commands/Commands.hpp"

#include "Managers/ManagerSolution.hpp"
#include "Creators/DrawerFactories/QtDrawerFactory/QtShapeDrawerFactory.hpp"

#include "Creators/Objects/Cameras/CameraSolution.hpp"

#include "Geometry/Vector.hpp"

MainWindow::MainWindow(QWidget* parent)
        :
        QMainWindow(parent),
        ui(new Ui::MainWindow),
        logic(std::make_shared<Logic>()) {
    ui->setupUi(this);
    painter.setPen(QPen(Qt::black, 3));

    scene = std::make_shared<QGraphicsScene>(this);
    scene->setSceneRect(
            0.0,
            0.0,
            ui->GraphicsView->rect().width(),
            ui->GraphicsView->rect().height()
    );

    ui->GraphicsView->setScene(scene.get());

    pix_map.fill(Qt::transparent);

    painter.begin(&pix_map);

    draw_requested = true;

    auto draw_manager = ManagerSolution::get_draw_manager();
    draw_manager->set_drawer(std::make_shared<Drawer::QtShapeDrawerFactory>(scene));

    on_AddCameraButton_clicked();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_MoveModelButton_clicked() {
    double x_delta = ui->MoveModeldx->value();
    double y_delta = ui->MoveModeldy->value();
    double z_delta = ui->MoveModeldz->value();

    try {
        logic->move_object(x_delta, y_delta, z_delta);
    } catch (std::exception& e) {
        show_error("Модель не загружена.");
    }
}


void MainWindow::on_MoveAllModelsButton_clicked() {
    double x_delta = ui->MoveModeldx->value();
    double y_delta = ui->MoveModeldy->value();
    double z_delta = ui->MoveModeldz->value();

    try {
        logic->move_all_objects(x_delta, y_delta, z_delta);
    } catch (std::exception& e) {
        show_error("Модель не загружена.");
    }
}


void MainWindow::on_RotateModelButton_clicked() {
    double x_axis_angle = ui->RotateModelax->value();
    double y_axis_angle = ui->RotateModelay->value();
    double z_axis_angle = ui->RotateModelaz->value();

    try {
        logic->rotate_object(x_axis_angle, y_axis_angle, z_axis_angle);
    } catch (std::exception& e) {
        show_error("Модель не загружена.");
    }
}


void MainWindow::on_RotateAllModelsButton_clicked() {
    double x_axis_angle = ui->RotateModelax->value();
    double y_axis_angle = ui->RotateModelay->value();
    double z_axis_angle = ui->RotateModelaz->value();

    try {
        logic->rotate_all_objects(x_axis_angle, y_axis_angle, z_axis_angle);
    } catch (std::exception& e) {
        show_error("Модель не загружена.");
    }
}


void MainWindow::on_ScaleModel_clicked() {
    double x_coefficient = ui->ScaleModelkx->value();
    double y_coefficient = ui->ScaleModelky->value();
    double z_coefficient = ui->ScaleModelkz->value();

    try {
        logic->scale_object(x_coefficient, y_coefficient, z_coefficient);
    } catch (std::exception& e) {
        show_error("Модель не загружена.");
    }
}


void MainWindow::on_ScaleAllModelsButton_clicked() {
    double x_coefficient = ui->ScaleModelkx->value();
    double y_coefficient = ui->ScaleModelky->value();
    double z_coefficient = ui->ScaleModelkz->value();

    try {
        logic->scale_all_objects(x_coefficient, y_coefficient, z_coefficient);
    } catch (std::exception& e) {
        show_error("Модель не загружена.");
    }
}


void MainWindow::on_DeleteCameraButton_clicked() {
    if (logic->get_data()->get_cameras().size() == 1)
        return;

    logic->delete_camera();

    ui->CamerasComboBox->removeItem(ui->CamerasComboBox->currentIndex());
}


void MainWindow::on_AddCameraButton_clicked() {
    logic->add_camera();

    std::string new_camera_name = logic->get_data()->get_active_camera().first;

    ui->CamerasComboBox->addItem(QString::fromStdString(new_camera_name));
    ui->CamerasComboBox->setCurrentIndex(ui->CamerasComboBox->count() - 1);
}


void MainWindow::on_DeleteModelButton_clicked() {
    try {
        logic->delete_object();
    } catch (std::exception& e) {
        show_error("Моделей нет.");
    }

    ui->ModelsComboBox->removeItem(ui->ModelsComboBox->currentIndex());
}


void MainWindow::on_LoadModelButton_clicked() {
    std::string path = QFileDialog::getOpenFileName(this, "Выберите файл.", "../../data/").toUtf8().constData();

    if (path == "")
        return;


    logic->load_object(path, "verticespairs");

    std::string new_model_name = logic->get_data()->get_active_object().first;

    ui->ModelsComboBox->addItem(QString::fromStdString(new_model_name));
    ui->ModelsComboBox->setCurrentIndex(ui->ModelsComboBox->count() - 1);
}

void MainWindow::show_error(const char* message) {
    QMessageBox::critical(nullptr, "Ошибка", message);
}


void MainWindow::on_CameraMoveUpButton_clicked() {
    logic->move_camera(0, -10.0, 0);
}


void MainWindow::on_CameraMoveLeftButton_clicked() {
    logic->move_camera(-10.0, 0, 0);
}


void MainWindow::on_CameraMoveDownButton_clicked() {
    logic->move_camera(0, 10.0, 0);
}


void MainWindow::on_CameraMoveRightButton_clicked() {
    logic->move_camera(10.0, 0, 0);
}


void MainWindow::on_CameraRotateLeftButton_clicked() {
    logic->rotate_camera(0.0, -10, 0.0);
}


void MainWindow::on_CameraRotateUpButton_clicked() {
    logic->rotate_camera(10.0, 0.0, 0.0);
}


void MainWindow::on_CameraRotateRightButton_clicked() {
    logic->rotate_camera(0.0, 10.0, 0.0);
}


void MainWindow::on_CameraRotateDownButton_clicked() {

}


void MainWindow::on_CameraRotateeDownButton_clicked()
{
    logic->rotate_camera(-10.0, 0.0, 0.0);
}


void MainWindow::on_ModelsComboBox_currentIndexChanged(int index) {
    logic->set_active_object(ui->ModelsComboBox->currentText().toStdString());
}


void MainWindow::on_CamerasComboBox_currentIndexChanged(int index) {
    logic->set_active_camera(ui->CamerasComboBox->currentText().toStdString());
}

