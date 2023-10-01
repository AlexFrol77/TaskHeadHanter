#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "udpworker.h"

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
    void on_actionWave_Viewer_triggered();

    void on_actionAbout_triggered();

private:
    Ui::MainWindow *ui;

    UDPWorker* udpWorker;
};
#endif // MAINWINDOW_H
