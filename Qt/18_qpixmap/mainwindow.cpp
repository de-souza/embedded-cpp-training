#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QColorDialog>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Preview String
    connect(
        ui->lineEdit_string,
        &QLineEdit::textChanged,
        this,
        &MainWindow::SetString
    );

    // Total Size (px)
    connect(
        ui->slider_sizePx,
        QOverload<int>::of(&QSlider::valueChanged),
        this,
        &MainWindow::SetSizePx
    );
    connect(
        ui->spinBox_sizePx,
        QOverload<int>::of(&QSpinBox::valueChanged),
        this,
        &MainWindow::SetSizePx
    );

    // String Size (px)
    connect(
        ui->slider_stringSizePx,
        QOverload<int>::of(&QSlider::valueChanged),
        this,
        &MainWindow::SetStringSizePx
    );
    connect(
        ui->spinBox_stringSizePx,
        QOverload<int>::of(&QSpinBox::valueChanged),
        this,
        &MainWindow::SetStringSizePx
    );

    // Outline Width (px)
    connect(
        ui->slider_outlineWidthPx,
        QOverload<int>::of(&QSlider::valueChanged),
        this,
        &MainWindow::SetOutlineWidthPx
    );
    connect(
        ui->spinBox_outlineWidthPx,
        QOverload<int>::of(&QSpinBox::valueChanged),
        this,
        &MainWindow::SetOutlineWidthPx
    );

    // Outline Radius (%)
    connect(
        ui->slider_outlineRadiusPercent,
        QOverload<int>::of(&QSlider::valueChanged),
        this,
        &MainWindow::SetOutlineRadiusPercent
    );
    connect(
        ui->spinBox_outlineRadiusPercent,
        QOverload<int>::of(&QSpinBox::valueChanged),
        this,
        &MainWindow::SetOutlineRadiusPercent
    );

    // Background Color
    connect(
        ui->pushButton_backgroundColor,
        &QPushButton::clicked,
        this,
        &MainWindow::SetBackgroundColor
    );

    // String Color
    connect(
        ui->pushButton_stringColor,
        &QPushButton::clicked,
        this,
        &MainWindow::SetStringColor
    );

    // Outline Color
    connect(
        ui->pushButton_outlineColor,
        &QPushButton::clicked,
        this,
        &MainWindow::SetOutlineColor
    );

    // Save
    connect(
        ui->buttonBox,
        &QDialogButtonBox::accepted,
        this,
        &MainWindow::Save
    );

    // Close
    connect(
        ui->buttonBox,
        &QDialogButtonBox::rejected,
        this,
        &MainWindow::close
    );

    // Reset
    connect(
        ui->buttonBox,
        &QDialogButtonBox::clicked,
        this,
        &MainWindow::Reset
    );

    Reset(ui->buttonBox->button(QDialogButtonBox::Reset));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetString(const QString string)
{
    mMyPixmap.String = string;
    mLoadPixmap();
}

void MainWindow::SetSizePx(const int sizePx)
{
    mMyPixmap.SizePx = sizePx;
    mLoadPixmap();
}

void MainWindow::SetStringSizePx(const int stringSizePx)
{
    mMyPixmap.StringSizePx = stringSizePx;
    mLoadPixmap();
}

void MainWindow::SetOutlineWidthPx(const int outlineWidthPx)
{
    mMyPixmap.OutlineWidthPx = outlineWidthPx;
    mLoadPixmap();
}

void MainWindow::SetOutlineRadiusPercent(const int outlineRadiusPercent)
{
    mMyPixmap.OutlineRadiusPercent = outlineRadiusPercent;
    mLoadPixmap();
}

void MainWindow::SetBackgroundColor()
{
    QColor color = QColorDialog::getColor(mMyPixmap.BackgroundColor, this);
    if (color.isValid()) {
        mMyPixmap.BackgroundColor = color;
        mLoadPixmap();
    }
}

void MainWindow::SetStringColor()
{
    QColor color = QColorDialog::getColor(mMyPixmap.StringColor, this);
    if (color.isValid()) {
        mMyPixmap.StringColor = color;
        mLoadPixmap();
    }
}

void MainWindow::SetOutlineColor()
{
    QColor color = QColorDialog::getColor(mMyPixmap.OutlineColor, this);
    if (color.isValid()) {
        mMyPixmap.OutlineColor = color;
        mLoadPixmap();
    }
}

void MainWindow::Save()
{
    QString directory = QFileDialog::getExistingDirectory(this);
    if (!directory.isNull()) {
        for (char ch = 32; ch < 127; ch++) {
            QFile file(QDir(directory).filePath(QString::number(ch) + ".png"));
            file.open(QIODevice::WriteOnly);
            mMyPixmap.String = QString(ch);
            mMyPixmap.Pixmap().save(&file);
        }
        QMessageBox::information(this, "Success", "Files saved successfully.");
        close();
    }
}

void MainWindow::Reset(const QAbstractButton* button)
{
    if (button == ui->buttonBox->button(QDialogButtonBox::Reset)) {
        mMyPixmap = MyPixmap();
        mLoadPixmap();
    }
}

void MainWindow::mLoadPixmap()
{
    // Preview String
    ui->lineEdit_string->setText(mMyPixmap.String);

    // Total Size (px)
    ui->slider_sizePx->setValue(mMyPixmap.SizePx);
    ui->spinBox_sizePx->setValue(mMyPixmap.SizePx);

    // Outline Width (px)
    int max_outline_width_px = mMyPixmap.SizePx / 2 - 5;
    if (mMyPixmap.OutlineWidthPx > max_outline_width_px)
        mMyPixmap.OutlineWidthPx = max_outline_width_px;
    ui->slider_outlineWidthPx->setValue(mMyPixmap.OutlineWidthPx);
    ui->slider_outlineWidthPx->setMaximum(max_outline_width_px);
    ui->spinBox_outlineWidthPx->setValue(mMyPixmap.OutlineWidthPx);
    ui->spinBox_outlineWidthPx->setMaximum(max_outline_width_px);

    // String Size (px)
    int max_string_size_px = mMyPixmap.SizePx - (2 * mMyPixmap.OutlineWidthPx);
    if (mMyPixmap.StringSizePx > max_string_size_px)
        mMyPixmap.StringSizePx = max_string_size_px;
    ui->slider_stringSizePx->setValue(mMyPixmap.StringSizePx);
    ui->slider_stringSizePx->setMaximum(max_string_size_px);
    ui->spinBox_stringSizePx->setValue(mMyPixmap.StringSizePx);
    ui->spinBox_stringSizePx->setMaximum(max_string_size_px);

    // Outline Radius (%)
    ui->slider_outlineRadiusPercent->setValue(mMyPixmap.OutlineRadiusPercent);
    ui->spinBox_outlineRadiusPercent->setValue(mMyPixmap.OutlineRadiusPercent);

    // Background Color
    QPalette palette;
    palette.setColor(QPalette::Button, mMyPixmap.BackgroundColor);
    ui->pushButton_backgroundColor->setPalette(palette);

    // String Color
    palette.setColor(QPalette::Button, mMyPixmap.StringColor);
    ui->pushButton_stringColor->setPalette(palette);

    // Outline Color
    palette.setColor(QPalette::Button, mMyPixmap.OutlineColor);
    ui->pushButton_outlineColor->setPalette(palette);

    // Preview
    delete ui->graphicsView_preview->scene();
    auto scene = new QGraphicsScene(this);
    scene->addPixmap(mMyPixmap.Pixmap());
    ui->graphicsView_preview->setScene(scene);
}
