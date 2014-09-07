#include "libs.h"

QString getImageName(const QString &name, int type)
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
    QString imgName = name;
    imgName = imgName.toLower();
    imgName.remove(QChar('\''));
    imgName.remove(QChar('.'));
    imgName.remove(QChar(' '));
    imgName = imgName + '_' + imgType;
    if (type == 2) imgName += ".jpg";
    else imgName += ".png";
    return imgName;
}

HashImg getHash(const QString &packFilePath)
{
    HashImg hash;
    QFile file(packFilePath);
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    in >> hash;
    file.close();
    return hash;
}

int setImgHash(const QString &listFilePath, const QString &destFilePath)
{
    HashImg hash;
    QFile chList(listFilePath);
    chList.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream inStream(&chList);
    while (!inStream.atEnd())
    {
        QString champName = inStream.readLine();
        for (int i = 0; i <= 2; ++i)
            hash[getImageName(champName, i)];
    }
    QFile file(destFilePath);
    bool empty = !file.size();
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    out << hash;
    file.close();
    if (!empty) return file.size();
    else return 0;
}

void packImages(const QString &destFilePath, const QString &imgFolderPath, int align)
{
    HashImg hash;
    QFile pack(destFilePath);
    pack.open(QIODevice::ReadWrite);
    QDataStream hashStream(&pack);
    hashStream >> hash;
    pack.seek(align);
    int from;
    int size;
    for (HashImg::iterator it = hash.begin(); it != hash.end(); ++it)
    {
        QFile imgFile(imgFolderPath + '/' + it.key());
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

QIcon getIcon(const QString &packFilePath, const QString &champName, int type)
{
    HashImg hash = getHash(packFilePath);
    QFile pack(packFilePath);
    pack.open(QIODevice::ReadOnly);
    QString imgFileName = getImageName(champName, type);
    pack.seek(hash[imgFileName].first);
    QByteArray ba = pack.read(hash[imgFileName].second);
    QPixmap pixmap;
    pixmap.loadFromData(ba);
    return *(new QIcon(pixmap));
}


