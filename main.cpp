#include "libs.h"
const QString CHAMP_LIST_PATH = "championList.txt";
const int HASH_ALIGN = 20000;
const QString CHAMP_FOLDER_PATH = "Champions";

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mainWindow;
    QVector<Champ> vectorChamp;
    setNamesInVector(&vectorChamp, CHAMP_LIST_PATH);
    setHashWithNames(&vectorChamp, "pack.pack");
    packImages("pack.pack", CHAMP_FOLDER_PATH, HASH_ALIGN); //this FU doesn't work
    HashImg hash = getHash("pack.pack");
    QFile f("pack.pack");
    f.open(QIODevice::ReadOnly);
    f.seek(hash["zed_load.jpg"].first.first);
    QByteArray ba = f.read(hash["zed_load.jpg"].first.second - hash["zed_load.jpg"].first.first);
    QPixmap im;
    im.loadFromData(ba);
    mainWindow.label->setPixmap(im);
    mainWindow.show();
    return a.exec();
}
