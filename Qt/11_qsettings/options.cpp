#include "options.h"
#include "ui_options.h"
#include "mainwindow.h"

#include <QSettings>

Options::Options(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Options)
{
    ui->setupUi(this);
    mLoadFont();
    connect(
        ui->fontComboBox,
        &QFontComboBox::currentFontChanged,
        this,
        &Options::mSetFontFamily
    );
    connect(
        ui->comboBox_style,
        QOverload<int>::of(&QComboBox::currentIndexChanged),
        this,
        &Options::mSetFontStyle
    );
    connect(
        ui->spinBox,
        QOverload<int>::of(&QSpinBox::valueChanged),
        this,
        &Options::mSetFontSize
    );
    connect(
        ui->comboBox_weight,
        QOverload<int>::of(&QComboBox::currentIndexChanged),
        this,
        &Options::mSetFontWeight
    );
    connect(
        ui->buttonBox,
        &QDialogButtonBox::accepted,
        this,
        &Options::mSaveFont
    );
}

Options::~Options()
{
    delete ui;
}

int Options::StyleToIndex(const QFont::Style style)
{
    switch (style) {
    case QFont::StyleNormal: return 0;
    case QFont::StyleItalic: return 1;
    case QFont::StyleOblique: return 2;
    }
}

QFont::Style Options::IndexToStyle(const int index)
{
    switch (index) {
    case 0: return QFont::StyleNormal;
    case 1: return QFont::StyleItalic;
    case 2: return QFont::StyleOblique;
    default: throw std::range_error("index out of range");
    }
}

int Options::WeightToIndex(const QFont::Weight weight)
{
    switch (weight) {
    case QFont::Thin: return 0;
    case QFont::ExtraLight: return 1;
    case QFont::Light: return 2;
    case QFont::Normal: return 3;
    case QFont::Medium: return 4;
    case QFont::DemiBold: return 5;
    case QFont::Bold: return 6;
    case QFont::ExtraBold: return 7;
    case QFont::Black: return 8;
    }
}

QFont::Weight Options::IndexToWeight(const int index)
{
    switch (index) {
    case 0: return QFont::Thin;
    case 1: return QFont::ExtraLight;
    case 2: return QFont::Light;
    case 3: return QFont::Normal;
    case 4: return QFont::Medium;
    case 5: return QFont::DemiBold;
    case 6: return QFont::Bold;
    case 7: return QFont::ExtraBold;
    case 8: return QFont::Black;
    default: throw std::range_error("index out of range");
    }
}

void Options::mLoadFont()
{
    mCurrentFont = MainWindow::LoadFont();
    ui->fontComboBox->setCurrentFont(mCurrentFont.family());
    ui->comboBox_style->setCurrentIndex(StyleToIndex(mCurrentFont.style()));
    ui->spinBox->setValue(mCurrentFont.pointSize());
    ui->comboBox_weight->setCurrentIndex(
        WeightToIndex(static_cast<QFont::Weight>(mCurrentFont.weight()))
    );
    ui->label_example->setFont(mCurrentFont);
}

void Options::mSetFontFamily(const QFont& font)
{
    mCurrentFont.setFamily(font.family());
    ui->label_example->setFont(mCurrentFont);
}

void Options::mSetFontStyle(const int& index)
{
    mCurrentFont.setStyle(IndexToStyle(index));
    ui->label_example->setFont(mCurrentFont);
}

void Options::mSetFontSize(const int& size)
{
    mCurrentFont.setPointSize(size);
    ui->label_example->setFont(mCurrentFont);
}

void Options::mSetFontWeight(const int& index)
{
    mCurrentFont.setWeight(IndexToWeight(index));
    ui->label_example->setFont(mCurrentFont);
}

void Options::mSaveFont()
{
    MainWindow::SaveFont(mCurrentFont);
}
