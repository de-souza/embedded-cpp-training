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
        ui->horizontalSlider_stringSizePx,
        QOverload<int>::of(&QSlider::valueChanged),
        this,
        &MainWindow::mUpdateStringSizePx
    );
    connect(
        ui->spinBox_stringSizePx,
        QOverload<int>::of(&QSpinBox::valueChanged),
        this,
        &MainWindow::mUpdateStringSizePx
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
    connect(
        ui->lineEdit_string,
        &QLineEdit::textChanged,
        this,
        &MainWindow::mUpdateString
    );
    connect(
        ui->buttonBox,
        &QDialogButtonBox::clicked,
        this,
        &MainWindow::mOnButtonClick
    );
    mSetDefaults();
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

void MainWindow::mUpdateStringSizePx(const int stringSizePx)
{
    mSetStringSizePx(stringSizePx);
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

void MainWindow::mUpdateString(const QString string)
{
    mSetString(string);
    mUpdatePreview();
}

void MainWindow::mOnButtonClick(const QAbstractButton* button)
{
    if (button == ui->buttonBox->button(QDialogButtonBox::RestoreDefaults))
        mSetDefaults();
    else if (button == ui->buttonBox->button(QDialogButtonBox::Close))
        close();
}

QPixmap MainWindow::mCreatePixmap(QString string)
{
    QPixmap pixmap(mSizePx, mSizePx);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    painter.setRenderHint(QPainter::Antialiasing);
    QPen pen(mOutlineColor, mOutlineWidthPx);
    pen.setJoinStyle(Qt::MiterJoin);
    painter.setPen(pen);
    QPainterPath path;
    path.addRoundedRect(
        mOutlineWidthPx / 2.0,
        mOutlineWidthPx / 2.0,
        mSizePx - mOutlineWidthPx,
        mSizePx - mOutlineWidthPx,
        mOutlineRadiusPercent,
        mOutlineRadiusPercent,
        Qt::RelativeSize
    );
    painter.fillPath(path, mBackgroundColor);
    painter.drawPath(path);
    QFont font;
    font.setPixelSize(mStringSizePx);
    painter.setFont(font);
    painter.setPen(mStringColor);
    painter.drawText(pixmap.rect(), Qt::AlignCenter, string);
    return pixmap;
}

void MainWindow::mSetDefaults()
{
    mSetSizePx(200);
    mSetString("W");
    mSetStringSizePx(100);
    mSetStringColor(Qt::darkBlue);
    mSetBackgroundColor(Qt::lightGray);
    mSetOutlineWidthPx(20);
    mSetOutlineColor(Qt::black);
    mSetOutlineRadiusPercent(25);
    mUpdatePreview();
}

void MainWindow::mSetSizePx(const int sizePx)
{
    ui->horizontalSlider_sizePx->setValue(sizePx);
    ui->spinBox_sizePx->setValue(sizePx);
    ui->horizontalSlider_outlineWidthPx->setMaximum(sizePx/2 - 6);
    ui->spinBox_outlineWidthPx->setMaximum(sizePx/2 - 6);
    ui->horizontalSlider_stringSizePx->setMaximum(sizePx - 2*mOutlineWidthPx);
    ui->spinBox_stringSizePx->setMaximum(sizePx - 2*mOutlineWidthPx);
    mSizePx = sizePx;
}

void MainWindow::mSetStringSizePx(const int stringSizePx)
{
    ui->horizontalSlider_stringSizePx->setValue(stringSizePx);
    ui->spinBox_stringSizePx->setValue(stringSizePx);
    mStringSizePx = stringSizePx;
}

void MainWindow::mSetStringColor(const QColor stringColor)
{
    QPalette palette;
    palette.setColor(QPalette::Button, stringColor);
    ui->pushButton_stringColor->setPalette(palette);
    mStringColor = stringColor;
}

void MainWindow::mSetBackgroundColor(const QColor backgroundColor)
{
    QPalette palette;
    palette.setColor(QPalette::Button, backgroundColor);
    ui->pushButton_backgroundColor->setPalette(palette);
    mBackgroundColor = backgroundColor;
}

void MainWindow::mSetOutlineColor(const QColor outlineColor)
{
    QPalette palette;
    palette.setColor(QPalette::Button, outlineColor);
    ui->pushButton_outlineColor->setPalette(palette);
    mOutlineColor = outlineColor;
}

void MainWindow::mSetOutlineWidthPx(const int outlineWidthPx)
{
    ui->horizontalSlider_outlineWidthPx->setValue(outlineWidthPx);
    ui->spinBox_outlineWidthPx->setValue(outlineWidthPx);
    ui->horizontalSlider_stringSizePx->setMaximum(mSizePx - 2*outlineWidthPx);
    ui->spinBox_stringSizePx->setMaximum(mSizePx - 2*outlineWidthPx);
    mOutlineWidthPx = outlineWidthPx;
}

void MainWindow::mSetOutlineRadiusPercent(const int outlineRadiusPercent)
{
    ui->horizontalSlider_outlineRadiusPercent->setValue(outlineRadiusPercent);
    ui->spinBox_outlineRadiusPercent->setValue(outlineRadiusPercent);
    mOutlineRadiusPercent = outlineRadiusPercent;
}

void MainWindow::mSetString(const QString string)
{
    mString = string;
    ui->lineEdit_string->setText(string);
}

void MainWindow::mUpdatePreview()
{
    delete ui->graphicsView_preview->scene();
    auto scene = new QGraphicsScene(this);
    scene->addPixmap(mCreatePixmap(mString));
    ui->graphicsView_preview->setScene(scene);
}
