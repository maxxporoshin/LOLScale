#ifndef LIBS_H
#define LIBS_H

    //---LIBS---
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QtWidgets>

#define HashTable QHash<QString, QPair<int, int> >

    //---resource.cpp
//makes name of an image from the champ's name (Kha'Zix -> khazix_32.png)
QString getImageName(const QString &champName, int type);
//gets hash from resource's file
HashTable getHash(const QString &packFile);
//fills hash with names and puts it into the file, setting key as an image name(khazix_32.png);
//returns size of hash file; deletes previous file
int setImgHash(const QString &statsFile, const QString &imgPackFile);
//adds images to the resource's file, requieres hash filled with prev foo in the file; and this FU still doesn't work at all
void packImages(const QString &imgPackFile, const QString &imgFolder, int align);
QPixmap getImage(const QString &imgPackFile, const QString &champName, int type);
Champ getChampStats(const QString &statsFile, const QString &champName);

#endif // LIBS_H
