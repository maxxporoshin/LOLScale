#include "libs.h"

void initMainList(MainWindow &mainWindow, const QString &listFilePath, const QString &packFilePath)

{
    QFile chList(listFilePath);
    chList.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream inStream(&chList);
    while (!inStream.atEnd())
    {
        QString champName = inStream.readLine();
        new QListWidgetItem(getIcon(packFilePath, champName, 0), champName, mainWindow.mainList);
    }
}
