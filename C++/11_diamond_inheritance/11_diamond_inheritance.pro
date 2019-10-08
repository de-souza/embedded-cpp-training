TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        child.cpp \
        firstparent.cpp \
        grandparent.cpp \
        main.cpp \
        secondparent.cpp

HEADERS += \
    child.h \
    firstparent.h \
    grandparent.h \
    secondparent.h
