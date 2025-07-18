TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++14

SOURCES += main.cpp \
    invertimage.cpp \
    linethinning.cpp \
    imagegradient.cpp \
    imageangle.cpp \
    imagehog.cpp \
    segmentation.cpp \
    linearsegmentation.cpp \
    edgedetection.cpp \
    linearedgedetection.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    invertimage.h \
    abstractalgorithm.h \
    linethinning.h \
    imagegradient.h \
    imageangle.h \
    imagehog.h \
    segmentation.h \
    linearsegmentation.h \
    edgedetection.h \
    linearedgedetection.h

    LIBS += c:\\opencv_3_1_0\\x86\\mingw\\lib\\libopencv_world310.dll.a
    INCLUDEPATH +=c:\\opencv_3_1_0\\include
