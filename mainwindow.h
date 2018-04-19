#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QThread>

#include "cameraworker.h"

namespace Ui {
class MainWindow;
}

/*!
 * \brief The class for the application's main window.
 *
 * This class is the main window for the camera preview application. It is
 * responsible for initiating the capture as well as displaying the results.
 * \see QMainWindow
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief MainWindow constructor.
     *
     * The constructor for the application's main window; loads the window's ui
     * from mainwindow.ui.
     *
     * \param parent the window's parent.
     */
    explicit MainWindow(QWidget *parent = 0);

    //! MainWindow destructor.
    ~MainWindow();

private slots:
    /*!
     * \brief Processes an image from the camera.
     *
     * Callback for the camera thread. Handles an image grabbed from the camera
     * by setting this window's ImageLabel to the given QImage and
     * force-refreshing the ui. This slot is called when the CameraWorker
     * emits the CameraWorker::handleImage signal.
     *
     * \param image The image from the camera to process.
     * \see QImage, QApplication::processEvents(), repaint(), CameraWorker
     */
    void handleImage(QImage &image);

    /*!
     * \brief Starts video capture from the camera.
     *
     * First, initializes a new QThread and a new CameraWorker. If the camera
     * is already running, return without doing anything because we can't have
     * multiple instances of one camera. Then, move the CameraWorker to the
     * created thread and connect the slots to start the worker when the thread
     * starts, handle output from the worker, and delete the worker when the
     * thread is deleted.
     *
     * \see QThread, CameraWorker
     */
    void on_btnStart_clicked();

    /*!
     * \brief Reset everything when video capture stops.
     *
     * Resets the cameraRunning flag and the UI when the CameraWorker::finished
     * signal is emitted.
     */
    void cameraFinished();

private:
    /*!
     * \brief the main window's UI.
     *
     * The UI for MainWindow, which is loaded from the mainwindow.ui file.
     */
    Ui::MainWindow *ui;

    /*!
     * \brief whether or not the camera is running.
     *
     * Flag for the camera's state, so that the program doesn't try to start
     * the camera when it's already running.
     */
    bool cameraRunning;

    /*!
     * \brief thread to run a CameraWorker.
     *
     * The thread in which the CameraWorker runs, so that the main thread
     * with the UI is not locked by the camera running.
     */
    QThread *workerThread;

    /*!
     * \brief worker to run the camera.
     *
     * Responsible for actually running the camera and giving back the camera's
     * output.
     */
    CameraWorker *worker;
};

#endif // MAINWINDOW_H
