#-------------------------------------------------
#
# Project created by QtCreator 2014-08-13T20:51:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LOLScale
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    resource.cpp

HEADERS  += mainwindow.h \
    libs.h

FORMS    += mainwindow.ui

DEFINES += PROJECT_PATH=\"\\\"$$PWD\\\"\"
