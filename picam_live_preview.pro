#-------------------------------------------------
#
# Project created by QtCreator 2017-03-22T20:19:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = picam-live
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cameraworker.cpp

HEADERS  += mainwindow.h \
    cameraworker.h

FORMS    += mainwindow.ui

# Requirements for raspicam
LIBS += -L/opt/vc/lib -lmmal -lmmal_core -lmmal_util
LIBS += -L/usr/local/lib -I/usr/local/include -lraspicam

DISTFILES += \
    .astylerc
