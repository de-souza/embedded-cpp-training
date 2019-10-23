#ifndef MYPIXMAP_H
#define MYPIXMAP_H

#include <QPixmap>

class MyPixmap
{
public:
    MyPixmap();
    QPixmap GetPixmap();
    void SetString(const QString string);
    void SetSizePx(int sizePx);
    void SetCharacterColor(QColor color);
    void SetBackgroundColor(QColor color);
    void SetOutlineWidthPx(int outlineWidthPx);
    void SetOutlineColor(QColor color);

private:
    QPixmap mPixmap;
    QString mString;
    int mSizePx;
    QColor mStringColor;
    QColor mBackgroundColor;
    int mOutlineWidthPx;
    QColor mOutlineColor;
    void mUpdatePixmap();
};

#endif // MYPIXMAP_H
