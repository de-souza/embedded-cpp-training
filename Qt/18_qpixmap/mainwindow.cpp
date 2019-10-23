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
        &MainWindow::mSetSizePx
    );
    connect(
        ui->pushButton_stringColor,
        &QPushButton::clicked,
        this,
        &MainWindow::mSetStringColor
    );
    connect(
        ui->pushButton_backgroundColor,
        &QPushButton::clicked,
        this,
        &MainWindow::mSetBackgroundColor
    );
    connect(
        ui->horizontalSlider_outlineWidthPx,
        QOverload<int>::of(&QSlider::valueChanged),
        this,
        &MainWindow::mSetOutlineWidthPx
    );
    connect(
        ui->pushButton_outlineColor,
        &QPushButton::clicked,
        this,
        &MainWindow::mSetOutlineColor
    );
    mpScene = new QGraphicsScene(this);
    mInitInterface();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mSetSizePx(const int sizePx)
{
    mUpdateSizePx(sizePx);
    mUpdatePreview();
}

void MainWindow::mSetStringColor()
{
    mUpdateStringColor(
        QColorDialog::getColor(Qt::black, this, "Character Color")
    );
    mUpdatePreview();
}

void MainWindow::mSetBackgroundColor()
{
    mUpdateBackgroundColor(
        QColorDialog::getColor(Qt::lightGray, this, "Background Color")
    );
    mUpdatePreview();
}

void MainWindow::mSetOutlineWidthPx(const int outlineWidthPx)
{
    mUpdateOutlineWidthPx(outlineWidthPx);
    mUpdatePreview();
}

void MainWindow::mSetOutlineColor()
{
    mUpdateOutlineColor(
        QColorDialog::getColor(Qt::black, this, "Outline Color")
    );
    mUpdatePreview();
}

void MainWindow::mInitInterface()
{
    mUpdateString("a");
    mUpdateSizePx(50);
    mUpdateStringColor(Qt::black);
    mUpdateBackgroundColor(Qt::lightGray);
    mUpdateOutlineWidthPx(5);
    mUpdateOutlineColor(Qt::black);
    mUpdatePreview();
}

void MainWindow::mUpdateString(const QString string)
{
    mMyPixmap.SetString(string);
}

void MainWindow::mUpdateSizePx(const int sizePx)
{
    ui->lineEdit_sizePx->setText(QString("%1 px").arg(sizePx));
    mMyPixmap.SetSizePx(sizePx);
}

void MainWindow::mUpdateStringColor(const QColor stringColor)
{
    QPalette palette;
    palette.setColor(QPalette::Base, stringColor);
    ui->lineEdit_stringColor->setPalette(palette);
    mMyPixmap.SetCharacterColor(stringColor);
}

void MainWindow::mUpdateBackgroundColor(const QColor backgroundColor)
{
    QPalette palette;
    palette.setColor(QPalette::Base, backgroundColor);
    ui->lineEdit_backgroundColor->setPalette(palette);
    mMyPixmap.SetBackgroundColor(backgroundColor);
}

void MainWindow::mUpdateOutlineWidthPx(const int outlineWidthPx)
{
    ui->lineEdit_outlineWidthPx->setText(QString("%1 px").arg(outlineWidthPx));
    mMyPixmap.SetOutlineWidthPx(outlineWidthPx);
}

void MainWindow::mUpdateOutlineColor(const QColor outlineColor)
{
    QPalette palette;
    palette.setColor(QPalette::Base, outlineColor);
    ui->lineEdit_outlineColor->setPalette(palette);
    mMyPixmap.SetOutlineColor(outlineColor);
}

void MainWindow::mUpdatePreview()
{
    QPixmap pixmap = mMyPixmap.GetPixmap();
    mpScene->setSceneRect(pixmap.rect());
    mpScene->clear();
    mpScene->addPixmap(pixmap);
    ui->graphicsView_preview->setScene(mpScene);
}
