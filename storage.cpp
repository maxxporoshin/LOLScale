#include "libs.h"

QString packIcons(const QString &dest = "")
{
    QHash<QString, int> hash;
    QFile pack("test.pack");
    QFile img("img1.png");
    pack.open(QIODevice::WriteOnly);
    img.open(QIODevice::ReadOnly);
    QByteArray ba = img.readAll();
    QDataStream out(&pack);
    out << hash;
    pack.seek(200);
    out.writeRawData(ba, sizeof(ba));
    pack.close();
    img.close();
}
