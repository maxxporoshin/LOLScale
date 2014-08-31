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

HashImg getHash(const QString &filePath)
{
    HashImg hash;
    QFile file(filePath);
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    in >> hash;
    file.close();
    return hash;
}

void setNamesInVector(QVector<Champ> *vector, const QString &listFilePath)
{
    QFile champs(listFilePath);
    champs.open(QIODevice::ReadOnly);
    QTextStream inTextStream(&champs);
    while(!inTextStream.atEnd())
    {
        QString chName = inTextStream.readLine();
        Champ ch(chName);
        vector->append(ch);
    }
    champs.close();
}

int setHashWithNames(QVector<Champ> *vector, const QString &dest)
{
    HashImg hash;
    for (QVector<Champ>::iterator it = vector->begin(); it != vector->end(); ++it)
        for (int i = 0; i <= 2; ++i)
            hash[getImageName(it->getName(), i)] = qMakePair(qMakePair(0, 0), it->getName());
    QFile file(dest);
    bool empty = !file.size();
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    out << hash;
    file.close();
    if (!empty) return file.size();
    else return 0;
}

void packImages(const QString &dest, const QString &srcFolderPath, int align) //PROB_TO_SOLVE: WRITE-READ HASH (IT DOESN'T FUCKIN WORK)
{
    HashImg hash;
    QFile pack(dest);
    pack.open(QIODevice::ReadWrite);
    QDataStream hashStream(&pack);
    hashStream >> hash;
    pack.seek(align);
    int from;
    int to;
    for (HashImg::iterator it = hash.begin(); it != hash.end(); ++it)
    {
        for (int i = 0; i <= 2; ++i)
        {
            QFile imgFile(srcFolderPath + '/' + it.value().second + '/' + it.key());
            imgFile.open(QIODevice::ReadOnly);
            QByteArray imgBA = imgFile.readAll();
            from = pack.pos();
            qDebug() << from;
            pack.write(imgBA);
            to = pack.pos();
            qDebug() << to;
            it.value().first = qMakePair(from, to);
            imgFile.close();
        }
    }
    pack.seek(0);
    hashStream << hash;
    pack.close();
}

/*    QFile pack("test.png");
    pack.remove();
    pack.open(QIODevice::ReadWrite);
    QFile img("zed_32.png");
    img.open(QIODevice::ReadOnly);
    QFile img2("aatrox_32.png");
    img2.open(QIODevice::ReadWrite);
    QByteArray ba = img.readAll();
    int s = ba.size();
    QPixmap im;
    im.loadFromData(ba);
    pack.seek(1000);
    pack.write(ba);
    ba = img2.readAll();
    pack.write(ba);
    ba.clear();
    QBuffer buf(&ba);
    //im.save(&buf, "PNG");
    pack.seek(1000);
    ba = pack.read(s);
    im.loadFromData(ba);
    qDebug() << ba.size() << buf.size();
    mainWindow.label->setPixmap(im);
    pack.close();
    img.close();
*/
