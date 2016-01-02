#-------------------------------------------------
#
# Project created by QtCreator 2015-11-10T13:02:10
#
#-------------------------------------------------

QT       -= core gui

TARGET = libindigoc
TEMPLATE = lib
CONFIG += staticlib
QMAKE_CXXFLAGS += -std=c++11
INCLUDEPATH += /usr/include /usr/include/c++/4.8 /home/zik/obj/libindigoc_gen

SOURCES += indigo.cpp \
    scheduler.cpp \
    pass.cpp \
    sourcefile.cpp \
    topleveldecl.cpp \
    package.cpp \
    packagedb.cpp \
    loadpackage.cpp

HEADERS += indigo.h \
    scheduler.h \
    pass.h \
    sourcefile.h \
    topleveldecl.h \
    package.h \
    loadpackage.h \
    packagedb.h \
    lmdb++.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

unix|win32: LIBS += -llmdb

DISTFILES += \
    pdbfmt.fbs \
    igolexer.l \
    igoparser.y
