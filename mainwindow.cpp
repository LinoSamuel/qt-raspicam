#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "unistd.h"

#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow),
    cameraRunning(false)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnStart_clicked()
{
    // Initialize the thread and worker
    workerThread = new QThread;
    worker = new CameraWorker;

    // Check to make sure the camera is not already running
    // If it is, return without doing anything.
    if (cameraRunning) {
        return;
    }

    // Setup the thread
    worker->moveToThread(workerThread);

    // Connect signals to slots
    connect(workerThread, SIGNAL(started()), worker, SLOT(doWork()));
    connect(worker, SIGNAL(finished()), workerThread, SLOT(quit()));
    connect(worker, SIGNAL(finished()), worker, SLOT(deleteLater()));
    connect(workerThread, SIGNAL(finished()), workerThread, SLOT(deleteLater()));
    connect(worker, SIGNAL(finished()), this, SLOT(cameraFinished()));
    connect(worker, SIGNAL(handleImage(QImage &)), this, SLOT(handleImage(QImage &)));
    connect(ui->btnStop, SIGNAL(clicked()), worker, SLOT(stopWork()));
    workerThread->start();

    // Update the running flag
    cameraRunning = true;

    // Disable the start button, enable the stop button
    ui->btnStart->setEnabled(false);
    ui->btnStop->setEnabled(true);
}

void MainWindow::handleImage(QImage &image)
{
    // Update the image shown
    ui->imgLabel->setPixmap(QPixmap::fromImage(image));

    // Force an update of the UI so that the image is shown immediately.
    QApplication::processEvents();
    this->repaint();
}

void MainWindow::cameraFinished()
{
    // Update running flag
    cameraRunning = false;

    // Disable the stop button, enable the start button
    ui->btnStop->setEnabled(false);
    ui->btnStart->setEnabled(true);

    // Reset the image label
    ui->imgLabel->setText("Camera Disabled");
}
