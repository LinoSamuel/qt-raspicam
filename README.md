# Qt Raspicam Demo
This is a simple project that came from code I wrote while working at [Spin Analytical](http://spinanalytical.com/) on their Cell Alignment Tool (2016-2017). It uses the Qt framework to display live video from the Raspberry Pi camera with the [raspicam](https://github.com/cedricve/raspicam) library.

## Setup
### Prerequisites
1. Qt development libraries ([installation for raspbian](https://www.raspberrypi.org/forums/viewtopic.php?t=69163#p506401))
2. [raspicam](https://github.com/cedricve/raspicam)
### Building
1. Download the source and navigate to its root directory.
2. Run ``qmake`` to generate the project's makefile, then ``make`` to build.

## Files
* `picam_live_preview.pro`: the Qt project file; make sure to add the two LIBS lines so that the raspicam library can work properly.
* `main.cpp`: runs the application (nothing changed from the Qt starter template).
* `mainwindow.h`/`mainwindow.cpp`: the application's main window, responsible for starting the camera which runs in its own thread.
* `mainwindow.ui`:  the Qt designer file for the application's main window.
* `cameraworker.h`/`cameraworker.cpp`: the worker that grabs images from the camera and converts them to QImages which are displayed in the main window.

## Documentation
See [here](https://brianjaustin.github.io/qt-raspicam/html/annotated.html) for Doxygen documentation.
