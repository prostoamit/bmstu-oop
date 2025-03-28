#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <memory>

#include <QMainWindow>

#include <QPainter>
#include <QGraphicsScene>

#include "QtInterface/AppLogic/AppLogic.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:

    void on_MoveModelButton_clicked();

    void on_MoveAllModelsButton_clicked();

    void on_RotateModelButton_clicked();

    void on_RotateAllModelsButton_clicked();

    void on_ScaleModel_clicked();

    void on_ScaleAllModelsButton_clicked();

    void on_DeleteCameraButton_clicked();

    void on_AddCameraButton_clicked();

    void on_DeleteModelButton_clicked();

    void on_LoadModelButton_clicked();

    void on_CameraMoveUpButton_clicked();

    void on_CameraMoveLeftButton_clicked();

    void on_CameraMoveDownButton_clicked();

    void on_CameraMoveRightButton_clicked();

    void on_CameraRotateLeftButton_clicked();

    void on_CameraRotateUpButton_clicked();

    void on_CameraRotateRightButton_clicked();

    void on_CameraRotateDownButton_clicked();

    void on_ModelsComboBox_currentIndexChanged(int index);

    void on_CamerasComboBox_currentIndexChanged(int index);

    void on_CameraRotateeDownButton_clicked();

    void on_RedoButton_clicked();

    void on_UndoButton_clicked();

private:

    void show_error(const char *message);

    double t;

    bool draw_requested;
    Ui::MainWindow *ui;

    QPixmap pix_map;
    QPainter painter;

    std::shared_ptr<QGraphicsScene> scene;
    std::shared_ptr<AppLogic> logic;
};
#endif // MAINWINDOW_H
