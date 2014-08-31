#include "champ.h"

Champ::Champ()
{

}

Champ::Champ(QString &name_, QImage *img32_, QImage *img64_, QImage *imgLoad_)
{
    name = name_;
    if (img32_) img32 = *img32_;
    if (img32_) img64 = *img64_;
    if (img32_) imgLoad = *imgLoad_;
}

void Champ::setName(QString &name_)
{
    name = name_;
}

void Champ::setImage(QImage *img_, QString type) //type - one of: "32", "64", "load"
{
    if (type == "32") img32 = *img_;
    if (type == "64") img64 = *img_;
    if (type == "load") imgLoad = *img_;
}

void Champ::setImages(QImage *img32_, QImage *img64_, QImage *imgLoad_)
{
    img32 = *img32_;
    img64 = *img64_;
    imgLoad = *imgLoad_;
}

QString Champ::getName()
{
    return name;
}

QImage Champ::getImage(QString type)
{
    if (type == "32") return img32;
    if (type == "64") return img64;
    if (type == "load") return imgLoad;
    return *(new QImage);
}
