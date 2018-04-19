#ifndef CAMERAWORKER_H
#define CAMERAWORKER_H

#include <QImage>

#include <raspicam/raspicam.h>

// This makes it so we don't have to prefix everything with raspicam::
// So raspicam::RaspiCam becomes just RaspiCam
using namespace raspicam;

class CameraWorker : public QObject
{
    Q_OBJECT
public:
    explicit CameraWorker();
    ~CameraWorker();

private:
    RaspiCam camera;
    bool cameraRunning;
    unsigned char *data;

signals:
    void handleImage(QImage &image);
    void finished();

public slots:
    void doWork();
    void stopWork();
};

#endif // CAMERAWORKER_H
