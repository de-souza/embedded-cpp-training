#include "mypixmap.h"

#include <QPainter>

MyPixmap::MyPixmap()
{
    String = "A";
    SizePx = 264;
    StringSizePx = 72;
    OutlineWidthPx = 64;
    OutlineRadiusPercent = 50;
    BackgroundColor = Qt::darkCyan;
    StringColor = Qt::darkBlue;
    OutlineColor = Qt::black;
}

QPixmap MyPixmap::Pixmap()
{
    // Create a pixmap with a transparent background
    QPixmap pixmap(SizePx, SizePx);
    pixmap.fill(Qt::transparent);

    // Create a painter for this pixmap
    QPainter painter(&pixmap);

    // Set the painter to render with antialiasing
    painter.setRenderHint(QPainter::Antialiasing);

    // Prepare the pen for the outline
    QPen pen(OutlineColor, OutlineWidthPx);
    pen.setJoinStyle(Qt::MiterJoin);
    painter.setPen(pen);

    // Prepare a path shaped like a rounded rectangle
    QPainterPath path;
    path.addRoundedRect(
        OutlineWidthPx / 2.0,       // X cordinate of the left side (px)
        OutlineWidthPx / 2.0,       // Y coordinate of the top side (px)
        SizePx - OutlineWidthPx,    // Width (px)
        SizePx - OutlineWidthPx,    // Height (px)
        OutlineRadiusPercent,       // Horizontal curvature of the corners (%)
        OutlineRadiusPercent,       // Vertical curvature of the corners (%)
        Qt::RelativeSize            // Set the unit for curvatures to percent
    );

    // Fill the rounded rectangle with the background color
    painter.fillPath(path, BackgroundColor);

    // Draw the rounded rectangle
    painter.drawPath(path);

    // Prepare the font and the pen for the string
    QFont font;
    font.setPixelSize(StringSizePx);
    painter.setFont(font);
    painter.setPen(StringColor);

    // Draw the string in the center of the pixmap
    painter.drawText(pixmap.rect(), Qt::AlignCenter, String);

    return pixmap;
}
