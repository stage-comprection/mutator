TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += src/main.cpp \
    src/mutator.cpp \
    src/readator.cpp

HEADERS += \
    src/mutator.h \
    src/readator.h
