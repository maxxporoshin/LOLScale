#ifndef CHAMP_H
#define CHAMP_H

#include <QtWidgets>

class Champ
{
    QString name;
    QImage img32;
    QImage img64;
    QImage imgLoad;
public:
    Champ();
    Champ(QString &name_, QImage *img32_ = 0, QImage *img64_ = 0, QImage *imgLoad_ = 0);
    void setName(QString &name_);
    void setImage(QImage *img_, QString type); //type - one of: "32", "64", "load"
    void setImages(QImage *img32_, QImage *img64_, QImage *imgLoad_);
    QString getName();
    QImage getImage(QString type);
};

#endif // CHAMP_H
