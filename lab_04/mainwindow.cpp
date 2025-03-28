#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "ElevatorManager.hpp"

MainWindow::MainWindow(QWidget* parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow),
        elevator(std::make_shared<ElevatorManager>(this)) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_FloorUpButton1_clicked() {
    elevator->external_button_pressed(1, FloorStates::UP);
}


void MainWindow::on_LiftButton1_clicked() {
    elevator->internal_pressed(1);
}


void MainWindow::on_FloorDownButton2_clicked() {
    elevator->external_button_pressed(2, FloorStates::DOWN);
}


void MainWindow::on_FloorUpButton2_clicked() {
    elevator->external_button_pressed(2, FloorStates::UP);
}


void MainWindow::on_LiftButton2_clicked() {
    elevator->internal_pressed(2);
}


void MainWindow::on_FloorDownButton3_clicked() {
    elevator->external_button_pressed(3, FloorStates::DOWN);
}


void MainWindow::on_FloorUpButton3_clicked() {
    elevator->external_button_pressed(3, FloorStates::UP);
}


void MainWindow::on_LiftButton3_clicked() {
    elevator->internal_pressed(3);
}


void MainWindow::on_FloorDownButton4_clicked() {
    elevator->external_button_pressed(4, FloorStates::DOWN);
}


void MainWindow::on_FloorUpButton4_clicked() {
    elevator->external_button_pressed(4, FloorStates::UP);
}


void MainWindow::on_LiftButton4_clicked() {
    elevator->internal_pressed(4);
}


void MainWindow::on_FloorDownButton5_clicked() {
    elevator->external_button_pressed(5, FloorStates::DOWN);
}


void MainWindow::on_FloorUpButton5_clicked() {
    elevator->external_button_pressed(5, FloorStates::UP);
}


void MainWindow::on_LiftButton5_clicked() {
    elevator->internal_pressed(5);
}


void MainWindow::on_FloorDownButton6_clicked() {
    elevator->external_button_pressed(6, FloorStates::DOWN);
}


void MainWindow::on_FloorUpButton6_clicked() {
    elevator->external_button_pressed(6, FloorStates::UP);
}


void MainWindow::on_LiftButton6_clicked() {
    elevator->internal_pressed(6);
}


void MainWindow::on_FloorDownButton7_clicked() {
    elevator->external_button_pressed(7, FloorStates::DOWN);
}


void MainWindow::on_FloorUpButton7_clicked() {
    elevator->external_button_pressed(7, FloorStates::UP);
}


void MainWindow::on_LiftButton7_clicked() {
    elevator->internal_pressed(7);
}


void MainWindow::on_FloorDownButton8_clicked() {
    elevator->external_button_pressed(8, FloorStates::DOWN);
}


void MainWindow::on_LiftButton8_clicked() {
    elevator->internal_pressed(8);
}

