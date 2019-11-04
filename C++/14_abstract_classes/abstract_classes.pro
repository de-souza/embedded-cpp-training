TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        child.cpp \
        main.cpp

HEADERS += \
    abstractparent.h \
    child.h
