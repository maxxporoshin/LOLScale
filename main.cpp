#include "libs.h"

const int HASH_ALIGN = 20000;
const QString IMG_FOLDER_PATH = "Images";
const bool PACK_NEEDED = false;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    if (PACK_NEEDED)
    {
        setImgHash(w.champListFile, w.imgPackFile);
        packImages(w.imgPackFile, IMG_FOLDER_PATH, HASH_ALIGN);
    }
    w.show();
    return a.exec();
}
