#include "libs.h"

#define CH_LIST_PATH ":/misc/championList.txt"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mainWindow;
    initMainList(mainWindow, CH_LIST_PATH);
    mainWindow.show();
    return a.exec();
}
