#include "libs.h"

/*void initMainList(MainWindow &mainWindow, const QString &champListPath)

{
    QFile championList(champListPath);
    if (!championList.exists())
    {
        new QListWidgetItem("No Such File", mainWindow.mainList);
        return;
    }
    championList.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream inStream(&championList);
    while (!inStream.atEnd())
    {
        QString champName = inStream.readLine();
        new QListWidgetItem(pickIcon(champName), champName, mainWindow.mainList);
    }
}
*/
