TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        firstparent.cpp \
        main.cpp \
        secondparent.cpp

HEADERS += \
    child.h \
    firstparent.h \
    secondparent.h
