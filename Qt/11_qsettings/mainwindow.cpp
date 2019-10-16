#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "options.h"

#include <QSettings>
#include <QCoreApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mUpdateFont();
    connect(ui->actionExit, &QAction::triggered, this, &MainWindow::close);
    connect(ui->actionOptions, &QAction::triggered, this, &MainWindow::mOptions);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::mResetFont);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QFont MainWindow::LoadFont()
{
    QFont font;
    QSettings settings(
        QCoreApplication::applicationDirPath() + "/settings.ini",
        QSettings::IniFormat
    );
    if (settings.childGroups().contains("font")) {
        font.setFamily(settings.value("font/family").toString());
        font.setStyle(
            static_cast<QFont::Style>(settings.value("font/style").toInt())
        );
        font.setPointSize(settings.value("font/size").toInt());
        font.setWeight(
            static_cast<QFont::Weight>(settings.value("font/weight").toInt())
        );
    }
    return font;
}

void MainWindow::SaveFont(QFont font)
{
    QSettings settings(
        QCoreApplication::applicationDirPath() + "/settings.ini",
        QSettings::IniFormat
    );
    settings.setValue("font/family", font.family());
    settings.setValue("font/style", font.style());
    settings.setValue("font/size", font.pointSize());
    settings.setValue("font/weight", font.weight());
}

QString MainWindow::StyleToString(QFont::Style style)
{
    switch (style) {
    case QFont::StyleNormal: return "Normal";
    case QFont::StyleItalic: return "Italic";
    case QFont::StyleOblique: return "Oblique";
    }
}

QString MainWindow::WeightToString(QFont::Weight weight)
{
    switch (weight) {
    case QFont::Thin:return "Thin";
    case QFont::ExtraLight: return "ExtraLight";
    case QFont::Light: return "Light";
    case QFont::Normal: return "Normal";
    case QFont::Medium: return "Medium";
    case QFont::DemiBold: return "DemiBold";
    case QFont::Bold: return "Bold";
    case QFont::ExtraBold: return "ExtraBold";
    case QFont::Black: return "Black";
    }
}

void MainWindow::mOptions()
{
    Options options_dialog;
    options_dialog.exec();
    mUpdateFont();
}

void MainWindow::mResetFont()
{
    QFont default_font;
    SaveFont(default_font);
    mUpdateFont();
}

void MainWindow::mUpdateFont()
{
    QFont font = LoadFont();
    ui->label_familyValue->setText(font.family());
    ui->label_styleValue->setText(StyleToString(font.style()));
    ui->label_sizeValue->setText(QString::number(font.pointSize()));
    ui->label_weightValue->setText(
        WeightToString(static_cast<QFont::Weight>(font.weight()))
    );
    ui->plainTextEdit->setFont(font);
}
