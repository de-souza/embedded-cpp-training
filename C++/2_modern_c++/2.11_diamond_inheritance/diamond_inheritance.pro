TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        grandparent.cpp \
        main.cpp

HEADERS += \
    child.h \
    firstparent.h \
    grandparent.h \
    secondparent.h
