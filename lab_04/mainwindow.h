#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>

#include "ElevatorManager.hpp"

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
    void on_FloorUpButton1_clicked();
    void on_LiftButton1_clicked();
    void on_FloorDownButton2_clicked();
    void on_FloorUpButton2_clicked();
    void on_LiftButton2_clicked();
    void on_FloorDownButton3_clicked();
    void on_FloorUpButton3_clicked();
    void on_LiftButton3_clicked();
    void on_FloorDownButton4_clicked();
    void on_FloorUpButton4_clicked();
    void on_LiftButton4_clicked();
    void on_FloorDownButton5_clicked();
    void on_FloorUpButton5_clicked();
    void on_LiftButton5_clicked();
    void on_FloorDownButton6_clicked();
    void on_FloorUpButton6_clicked();
    void on_LiftButton6_clicked();
    void on_FloorDownButton7_clicked();
    void on_FloorUpButton7_clicked();
    void on_LiftButton7_clicked();
    void on_FloorDownButton8_clicked();
    void on_LiftButton8_clicked();
private:
    Ui::MainWindow *ui;

    std::shared_ptr<ElevatorManager> elevator;
};

#endif // MAINWINDOW_H
