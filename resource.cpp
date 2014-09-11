#include "libs.h"

QString getImageName(const QString &champName, int type)
{
    QString imgType;
    switch (type)
    {
    case 0:
        imgType = "32";
        break;
    case 1:
        imgType = "64";
        break;
    case 2:
        imgType = "load";
        break;
    default:
        imgType = "";
        break;
    }
    QString imgName = champName;
    imgName = imgName.toLower();
    imgName.remove(QChar('\''));
    imgName.remove(QChar('.'));
    imgName.remove(QChar(' '));
    imgName = imgName + '_' + imgType;
    if (type == 2) imgName += ".jpg";
    else imgName += ".png";
    return imgName;
}

HashTable getHash(const QString &packFile)
{
    HashTable hash;
    QFile file(packFile);
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    in >> hash;
    file.close();
    return hash;
}

int setImgHash(const QString &statsFile, const QString &imgPackFile)
{
    HashTable hash;
    QFile chList(statsFile);
    chList.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream inStream(&chList);
    while (!inStream.atEnd())
    {
        QString champName = inStream.readLine().section('@', 1, 1);
        for (int i = 0; i <= 2; ++i)
            hash[getImageName(champName, i)];
    }
    QFile file(imgPackFile);
    file.remove();
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    out << hash;
    file.close();
    return file.size();
}

void packImages(const QString &imgPackFile, const QString &imgFolder, int align)
{
    HashTable hash;
    QFile pack(imgPackFile);
    pack.open(QIODevice::ReadWrite);
    QDataStream hashStream(&pack);
    hashStream >> hash;
    pack.seek(align);
    int from;
    int size;
    for (HashTable::iterator it = hash.begin(); it != hash.end(); ++it)
    {
        QFile imgFile(imgFolder + '/' + it.key());
        imgFile.open(QIODevice::ReadOnly);
        QByteArray imgBA = imgFile.readAll();
        size = imgBA.size();
        from = pack.pos();
        pack.write(imgBA);
        it.value() = qMakePair(from, size);
        imgFile.close();
    }
    pack.seek(0);
    hashStream << hash;
    pack.close();
}

QPixmap getImage(const QString &imgPackFile, const QString &champName, int type)
{
    HashTable hash = getHash(imgPackFile);
    QFile pack(imgPackFile);
    pack.open(QIODevice::ReadOnly);
    QString imgFileName = getImageName(champName, type);
    pack.seek(hash[imgFileName].first);
    QByteArray ba = pack.read(hash[imgFileName].second);
    QPixmap pixmap;
    pixmap.loadFromData(ba);
    return pixmap;
}

Champ getChampStats(const QString &statsFile, const QString &champName)
{
    Champ champ;
    QFile stats(statsFile);
    stats.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream inStream(&stats);
    while (!inStream.atEnd())
    {
        QString str = inStream.readLine();
        if (str.section('@', 1, 1) == champName)
        {
            champ.rpCost = str.section('@', 2, 2);
            champ.ipCost = str.section('@', 3, 3);
            champ.popularity = str.section('@', 4, 4);
            champ.winRate = str.section('@', 5, 5);
            champ.banRate = str.section('@', 6, 6);
            champ.released = str.section('@', 8, 8);
            break;
        }
    }
    stats.close();
    return champ;
}
