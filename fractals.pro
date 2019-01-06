TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++11 -Wall
QMAKE_CXXFLAGS_DEBUG += -std=c++11 -Wall
SOURCES += main.cpp \
    bitmap.cpp \
    mandelbrot.cpp \
    zoomlist.cpp

HEADERS += \
    bitmapfileheader.h \
    bitmapinfoheader.h \
    bitmap.h \
    mandelbrot.h \
    zoom.h \
    zoomlist.h
