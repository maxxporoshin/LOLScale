#ifndef LIBS_H
#define LIBS_H

    //---LIBS---
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QtWidgets>

#define HashImg QHash<QString, QPair<int, int> >

    //---gui.cpp
void initMainList(MainWindow &mainWindow, const QString &listFilePath, const QString &packFilePath);

    //---resource.cpp
//makes name of an image from the champ's name (Kha'Zix -> khazix_32.png)
QString getImageName(const QString &name, int type);
//gets hash from resource's file
HashImg getHash(const QString &filePath);
//fills hash with names and puts it into the file, setting key as an image name(khazix_32.png);
//returns size of hash file; returns 0 if file wasn't empty
int setImgHash(const QString &listFilePath, const QString &destFilePath);
//adds images to the resource's file, requieres hash filled with prev foo in the file; and this FU still doesn't work at all
void packImages(const QString &destFilePath, const QString &imgFolderPath, int align);
QIcon getIcon(const QString &packFilePath, const QString &champName, int type);

#endif // LIBS_H
