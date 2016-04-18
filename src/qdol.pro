#-------------------------------------------------
#
# Project created by QtCreator 2015-07-26T21:19:03
#
#-------------------------------------------------

QT       += core gui svg serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qdol
TEMPLATE = app

CONFIG += warn_off
SOURCES +=\
    hid/hidapi.c \
    machines/plotteuse/plotteuse.cpp \
    machines/machine/Machine.cpp \
    machines/machine/Tool.cpp \
    Minicut.cpp \
    gui.cpp \
    qdol.cpp \
    draw/draw_scene.cpp \
    draw/draw_view.cpp \
    draw/drawingtools.cpp \
    file/Libmanager.cpp


HEADERS  += \
    hid/hidapi.h \
    machines/plotteuse/plotteuse.h \
    machines/machine/Tool.h \
    machines/machine/Machine.h \
    Minicut.h \
    gui.h \
    draw/draw_scene.h \
    draw/draw_view.h \
    draw/drawingtools.h \
    file/Libmanager.h

FORMS    += \
    gui.ui

linux-g++ {
unix:!macx:!symbian: LIBS += -L$$PWD/../../../../../usr/lib/i386-linux-gnu/ -lusb-1.0 -ludev
}
