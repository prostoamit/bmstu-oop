#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->Graphics->setScene(scene);

    scene->setSceneRect(-ui->Graphics->width() / 2, -ui->Graphics->height() / 2, ui->Graphics->width(), ui->Graphics->height());

    this->scene = scene;
}

MainWindow::~MainWindow() {
    delete ui;

    error_e rc = SUCCESS;

    action_t action;
    action.key = QUIT;

    rc = action_handler(action);
    if (rc != SUCCESS) {
        error_handler(rc);
    }
}

error_e
MainWindow::draw() {
    action_t action = {
        .key = DRAW,
        .scene = this->scene
    };

    return action_handler(action);
}

void MainWindow::on_LoadButton_clicked()
{
    error_e rc = SUCCESS;

    QString q_file_name = QFileDialog::getOpenFileName(this, "Выберите файл.", "../figures");
    char *file_name = q_file_name.toLocal8Bit().data();

    action_t action;
    action.key = LOAD_FROM_FILE;
    action.filename = file_name;

    rc = action_handler(action);
    if (rc != SUCCESS)
        error_handler(rc);
    else {
        rc = draw();
        if (rc != SUCCESS)
            error_handler(rc);
    }
}


void MainWindow::on_MoveButton_clicked()
{
    error_e rc = SUCCESS;

    action_t action;
    action.key = MOVE;
    action.deltas = {
        .dx = ui->dXInput->value(),
        .dy = ui->dYInput->value(),
        .dz = ui->dZInput->value()
    };

    rc = action_handler(action);
    if (rc != SUCCESS)
        error_handler(rc);
    else {
        rc = draw();
        if (rc != SUCCESS)
            error_handler(rc);
    }
}


void MainWindow::on_ScaleButton_clicked()
{
    error_e rc = SUCCESS;

    action_t action;
    action.key = SCALE;
    action.coeffs = {
        .kx = ui->kXInput->value(),
        .ky = ui->kYInput->value(),
        .kz = ui->kZInput->value()
    };

    rc = action_handler(action);
    if (rc != SUCCESS) {
        error_handler(rc);
    }
    else {
        rc = draw();
        if (rc != SUCCESS) {
            error_handler(rc);
        }
    }
}

void MainWindow::on_RotateButton_clicked()
{
    error_e rc = SUCCESS;

    action_t action;
    action.key = ROTATE;
    action.angles = {
        .ox = ui->oXInput->value(),
        .oy = ui->oYInput->value(),
        .oz = ui->oZInput->value()
    };

    rc = action_handler(action);
    if (rc != SUCCESS)
        error_handler(rc);
    else {
        rc = draw();
        if (rc != SUCCESS)
            error_handler(rc);
    }
}
