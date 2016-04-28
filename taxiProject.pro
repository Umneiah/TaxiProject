#-------------------------------------------------
#
# Project created by QtCreator 2016-04-17T15:43:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = taixProject
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    ../graph.h \
    graph.h

FORMS    += mainwindow.ui

DISTFILES +=

RESOURCES += \
    qdarkstyle/style.qrc
