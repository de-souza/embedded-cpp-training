#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QColorDialog>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(
        ui->horizontalSlider_sizePx,
        QOverload<int>::of(&QSlider::valueChanged),
        this,
        &MainWindow::mUpdateSizePx
    );
    connect(
        ui->spinBox_sizePx,
        QOverload<int>::of(&QSpinBox::valueChanged),
        this,
        &MainWindow::mUpdateSizePx
    );
    connect(
        ui->pushButton_stringColor,
        &QPushButton::clicked,
        this,
        &MainWindow::mUpdateStringColor
    );
    connect(
        ui->pushButton_backgroundColor,
        &QPushButton::clicked,
        this,
        &MainWindow::mUpdateBackgroundColor
    );
    connect(
        ui->pushButton_outlineColor,
        &QPushButton::clicked,
        this,
        &MainWindow::mUpdateOutlineColor
    );
    connect(
        ui->horizontalSlider_outlineWidthPx,
        QOverload<int>::of(&QSlider::valueChanged),
        this,
        &MainWindow::mUpdateOutlineWidthPx
    );
    connect(
        ui->spinBox_outlineWidthPx,
        QOverload<int>::of(&QSpinBox::valueChanged),
        this,
        &MainWindow::mUpdateOutlineWidthPx
    );
    connect(
        ui->horizontalSlider_outlineRadiusPercent,
        QOverload<int>::of(&QSlider::valueChanged),
        this,
        &MainWindow::mUpdateOutlineRadiusPercent
    );
    connect(
        ui->spinBox_outlineRadiusPercent,
        QOverload<int>::of(&QSpinBox::valueChanged),
        this,
        &MainWindow::mUpdateOutlineRadiusPercent
    );
    mSetString("W");
    mSetSizePx(200);
    mSetStringColor(Qt::darkBlue);
    mSetBackgroundColor(Qt::lightGray);
    mSetOutlineWidthPx(10);
    mSetOutlineColor(Qt::black);
    mSetOutlineRadiusPercent(25);
    mUpdatePreview();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mUpdateSizePx(const int sizePx)
{
    mSetSizePx(sizePx);
    mUpdatePreview();
}

void MainWindow::mUpdateStringColor()
{
    mSetStringColor(
        QColorDialog::getColor(Qt::black, this, "Character Color")
    );
    mUpdatePreview();
}

void MainWindow::mUpdateBackgroundColor()
{
    mSetBackgroundColor(
        QColorDialog::getColor(Qt::lightGray, this, "Background Color")
    );
    mUpdatePreview();
}

void MainWindow::mUpdateOutlineColor()
{
    mSetOutlineColor(
        QColorDialog::getColor(Qt::black, this, "Outline Color")
    );
    mUpdatePreview();
}

void MainWindow::mUpdateOutlineWidthPx(const int outlineWidthPx)
{
    mSetOutlineWidthPx(outlineWidthPx);
    mUpdatePreview();
}

void MainWindow::mUpdateOutlineRadiusPercent(const int outlineRadiusPercent)
{
    mSetOutlineRadiusPercent(outlineRadiusPercent);
    mUpdatePreview();
}

QPixmap MainWindow::mCreatePixmap(mPixmapSettings settings)
{
    QPixmap pixmap(settings.SizePx, settings.SizePx);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    painter.setRenderHint(QPainter::Antialiasing);
    QPainterPath path;
    path.addRoundedRect(
        settings.OutlineWidthPx / 2.0,
        settings.OutlineWidthPx / 2.0,
        settings.SizePx - settings.OutlineWidthPx,
        settings.SizePx - settings.OutlineWidthPx,
        settings.OutlineRadiusPercent,
        settings.OutlineRadiusPercent,
        Qt::RelativeSize
    );
    painter.fillPath(path, settings.BackgroundColor);
    QPen pen(settings.OutlineColor, settings.OutlineWidthPx);
    painter.setPen(pen);
    painter.drawPath(path);
    QFont font;
    font.setPixelSize(settings.SizePx - 2*settings.OutlineWidthPx);
    painter.setFont(font);
    painter.setPen(settings.StringColor);
    painter.drawText(pixmap.rect(), Qt::AlignCenter, settings.String);
    return pixmap;
}

void MainWindow::mSetString(const QString string)
{
    mPreviewSettings.String = string;
}

void MainWindow::mSetSizePx(const int sizePx)
{
    ui->horizontalSlider_sizePx->setValue(sizePx);
    ui->spinBox_sizePx->setValue(sizePx);
    ui->horizontalSlider_outlineWidthPx->setMaximum(sizePx/2 - 6);
    ui->spinBox_outlineWidthPx->setMaximum(sizePx/2 - 6);
    mPreviewSettings.SizePx = sizePx;
}

void MainWindow::mSetStringColor(const QColor stringColor)
{
    QPalette palette;
    palette.setColor(QPalette::Button, stringColor);
    ui->pushButton_stringColor->setPalette(palette);
    mPreviewSettings.StringColor = stringColor;
}

void MainWindow::mSetBackgroundColor(const QColor backgroundColor)
{
    QPalette palette;
    palette.setColor(QPalette::Button, backgroundColor);
    ui->pushButton_backgroundColor->setPalette(palette);
    mPreviewSettings.BackgroundColor = backgroundColor;
}

void MainWindow::mSetOutlineColor(const QColor outlineColor)
{
    QPalette palette;
    palette.setColor(QPalette::Button, outlineColor);
    ui->pushButton_outlineColor->setPalette(palette);
    mPreviewSettings.OutlineColor = outlineColor;
}

void MainWindow::mSetOutlineWidthPx(const int outlineWidthPx)
{
    ui->horizontalSlider_outlineWidthPx->setValue(outlineWidthPx);
    ui->spinBox_outlineWidthPx->setValue(outlineWidthPx);
    mPreviewSettings.OutlineWidthPx = outlineWidthPx;
}

void MainWindow::mSetOutlineRadiusPercent(const int outlineRadiusPercent)
{
    ui->horizontalSlider_outlineRadiusPercent->setValue(outlineRadiusPercent);
    ui->spinBox_outlineRadiusPercent->setValue(outlineRadiusPercent);
    mPreviewSettings.OutlineRadiusPercent = outlineRadiusPercent;
}

void MainWindow::mUpdatePreview()
{
    delete ui->graphicsView_preview->scene();
    auto scene = new QGraphicsScene(this);
    scene->addPixmap(mCreatePixmap(mPreviewSettings));
    ui->graphicsView_preview->setScene(scene);
}
