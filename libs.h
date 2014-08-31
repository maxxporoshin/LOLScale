#ifndef LIBS_H
#define LIBS_H

    //---LIBS---
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "champ.h"
#include <QApplication>
#include <QtWidgets>

#define HashImg QHash<QString, QPair<QPair<int, int>, QString> >

    //---gui.cpp
void initMainList(MainWindow &mainWindow, const QString &champListPath);

    //---resource.cpp
//makes name of an image from the champ's name (Kha'Zix -> khazix_32.png)
QString getImageName(const QString &name, int type);
//gets hash from resource's file
HashImg getHash(const QString &filePath);
//fills vector with Champs', setting their names from the listFile
void setNamesInVector(QVector<Champ> *vector, const QString &listFilePath);
//fills hash from the vector into the file, setting key as a name(Kha'Zix) and
//value().second (last QString in the HashImg) as an image name(khazix_32.png); returns size of hash file; returns 0 if file wasn't empty
int setHashWithNames(QVector<Champ> *vector, const QString &dest);
//adds images to the resource's file, requieres hash filled with prev foo in the file; and this FU still doesn't work at all
void packImages(const QString &dest, const QString &srcFolderPath, int align);

#endif // LIBS_H
