#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    udpWorker = new UDPWorker(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionWave_Viewer_triggered()
{
    udpWorker->initSocket();
}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(0, "About", "Alex Frol \n" "city Moscow \n" "+7 (915) 282 93 31");
}

