#include "libs.h"

const QString CHAMP_LIST_FILE = "championList.txt";
const int HASH_ALIGN = 20000;
const QString IMG_FOLDER_PATH = "Images";
const bool PACK_NEEDED = false;
const QString IMG_PACK_FILE = "images.pack";

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mainWindow;
    if (PACK_NEEDED)
    {
        setImgHash(CHAMP_LIST_FILE, IMG_PACK_FILE);
        packImages(IMG_PACK_FILE, IMG_FOLDER_PATH, HASH_ALIGN);
    }
    initMainList(mainWindow, CHAMP_LIST_FILE, IMG_PACK_FILE);
    mainWindow.show();
    return a.exec();
}
