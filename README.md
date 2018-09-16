# Qt Raspicam

This is a simple project that came from code I wrote while working at [Spin Analytical](http://spinanalytical.com/). It demonstrates how to use Qt to render live video from the Raspberry Pi camera with the [raspicam](https://github.com/cedricve/raspicam) library. Integrating Qt with the raspberry pi camera proved a bit challenging, so I thought it might be useful to share this code.

## Prerequisites
* Qt development libraries ([installation for raspbian](https://www.raspberrypi.org/forums/viewtopic.php?t=69163#p506401))
* [raspicam](https://github.com/cedricve/raspicam)

## Files
* `picam_live_preview.pro`: the Qt project file; make sure to add the two LIBS lines so that the raspicam library can work properly.
* `main.cpp`: runs the application (nothing changed from the Qt starter template).
* `mainwindow.h`/`mainwindow.cpp`: the application's main window, responsible for starting the camera which runs in its own thread.
* `mainwindow.ui`:  the Qt designer file for the application's main window.
* `cameraworker.h`/`cameraworker.cpp`: the worker that grabs images from the camera and converts them to QImages which are displayed in the main window.

## Documentation
TODO: link to Doxygen for this project.

