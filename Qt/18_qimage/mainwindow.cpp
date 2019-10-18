#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(
        ui->spinBox_size,
        QOverload<int>::of(&QSpinBox::valueChanged),
        this,
        &MainWindow::mSetSize
    );
    connect(
        ui->pushButton_characterColor,
        &QPushButton::clicked,
        this,
        &MainWindow::mSetCharacterColor
    );
    connect(
        ui->pushButton_backgroundColor,
        &QPushButton::clicked,
        this,
        &MainWindow::mSetBackgroundColor
    );
    connect(
        ui->spinBox_outlineWidth,
        QOverload<int>::of(&QSpinBox::valueChanged),
        this,
        &MainWindow::mSetOutlineWidth
    );
    connect(
        ui->pushButton_outlineColor,
        &QPushButton::clicked,
        this,
        &MainWindow::mSetOutlineColor
    );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mSetSize(int sizePx)
{

}

void MainWindow::mSetCharacterColor()
{
    QColor color = QColorDialog::getColor(Qt::black, this, "Character Color");
}

void MainWindow::mSetBackgroundColor()
{
    QColor color = QColorDialog::getColor(Qt::black, this, "Background Color");
}

void MainWindow::mSetOutlineWidth(int sizePx)
{

}

void MainWindow::mSetOutlineColor()
{
    QColor color = QColorDialog::getColor(Qt::black, this, "Outline Color");
}
