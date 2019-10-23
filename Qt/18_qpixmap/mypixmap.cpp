#include "mypixmap.h"

#include <QPainter>

MyPixmap::MyPixmap()
{
    mString = "a";
    mSizePx = 50;
    mStringColor = Qt::black;
    mBackgroundColor = Qt::lightGray;
    mOutlineWidthPx = 5;
    mOutlineColor = Qt::black;
    mUpdatePixmap();
}

QPixmap MyPixmap::GetPixmap()
{
    return mPixmap;
}

void MyPixmap::SetString(const QString string)
{
    mString = string;
    mUpdatePixmap();
}

void MyPixmap::SetSizePx(const int sizePx)
{
    mSizePx = sizePx;
    mUpdatePixmap();
}

void MyPixmap::SetCharacterColor(const QColor characterColor)
{
    mStringColor = characterColor;
    mUpdatePixmap();
}

void MyPixmap::SetBackgroundColor(const QColor backgroundColor)
{
    mBackgroundColor = backgroundColor;
    mUpdatePixmap();
}

void MyPixmap::SetOutlineWidthPx(const int outlineWidthPx)
{
    mOutlineWidthPx = outlineWidthPx;
    mUpdatePixmap();
}

void MyPixmap::SetOutlineColor(const QColor outlineColor)
{
    mOutlineColor = outlineColor;
    mUpdatePixmap();
}

void MyPixmap::mUpdatePixmap()
{
    mPixmap = QPixmap(mSizePx, mSizePx);
    mPixmap.fill(mBackgroundColor);

    QPainter painter(&mPixmap);

    QFont font;
    font.setPixelSize(mSizePx);
    painter.setFont(font);
    painter.setPen(mStringColor);
    painter.drawText(mPixmap.rect(), Qt::AlignCenter, mString);

    QPen pen;
    pen.setColor(mOutlineColor);
    pen.setWidth(mOutlineWidthPx);
    painter.setPen(pen);
    painter.drawRoundedRect(
        mOutlineWidthPx / 2,
        mOutlineWidthPx / 2,
        mSizePx - mOutlineWidthPx,
        mSizePx - mOutlineWidthPx,
        50,
        50,
        Qt::RelativeSize
    );
}
