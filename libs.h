#ifndef LIBS_H
#define LIBS_H

    //---LIBS---
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QtWidgets>

    //---mainlist.cpp
void initMainList(MainWindow &mainWindow, const QString &champListPath);

    //---resource.cpp
//"size" must be "32", "64" or "load"
QIcon pickIcon(const QString &name, const QString &size = "32");

#endif // LIBS_H
