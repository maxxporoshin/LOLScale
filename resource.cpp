#include "libs.h"

QIcon pickIcon(const QString &name, const QString &size)
{
    QIcon champIcon;
    if (name.isNull()) return champIcon;
    QString iconFullName = name;
    iconFullName = iconFullName.toLower();
    iconFullName.remove(QChar('\''));
    iconFullName.remove(QChar('.'));
    iconFullName.remove(QChar(' '));
    iconFullName = ":/champions/champions/" + name + '/' + iconFullName + '_' + size + ".png";
    champIcon.addFile(iconFullName);
    return champIcon;
}
