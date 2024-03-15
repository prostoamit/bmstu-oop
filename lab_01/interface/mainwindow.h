#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

#include "actions.h"
#include "errors.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QGraphicsScene *scene;


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_LoadButton_clicked();

    void on_MoveButton_clicked();

    void on_ScaleButton_clicked();

    void on_RotateButton_clicked();

private:
    error_e draw();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
