#ifndef MYPIXMAP_H
#define MYPIXMAP_H

#include <QPixmap>

class MyPixmap
{
public:
    MyPixmap();
    QString String;
    int SizePx;
    int StringSizePx;
    int OutlineWidthPx;
    int OutlineRadiusPercent;
    QColor BackgroundColor;
    QColor StringColor;
    QColor OutlineColor;
    QPixmap Pixmap();
};

#endif // MYPIXMAP_H
