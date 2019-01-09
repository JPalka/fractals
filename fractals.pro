TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++11 -Wall
QMAKE_CXXFLAGS_DEBUG += -std=c++11 -Wall
SOURCES += main.cpp \
    bitmap.cpp \
    mandelbrot.cpp \
    zoomlist.cpp \
    tricorn.cpp \
    julia.cpp \
    histogram.cpp \
    fractal.cpp \
    escapefractal.cpp \
    colorrange.cpp \
    newton.cpp \
    rangebased.cpp

HEADERS += \
    bitmapfileheader.h \
    bitmapinfoheader.h \
    bitmap.h \
    fractal.h \
    escapefractal.h \
    mandelbrot.h \
    zoom.h \
    zoomlist.h \
    rgb.h \
    tricorn.h \
    julia.h \
    pixel.h \
    colorscheme.h \
    histogram.h \
    colorrange.h \
    newton.h \
    rangebased.h

