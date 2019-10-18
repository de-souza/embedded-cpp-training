#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPainter>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auto updateTimer = new QTimer(this);
    connect(updateTimer, &QTimer::timeout, this, &MainWindow::mUpdate);
    updateTimer->setInterval(20);
    updateTimer->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mUpdate()
{
    mXPos += 10;
    repaint();
}

void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QFont font = painter.font();
    font.setPixelSize(50);
    painter.setFont(font);
    painter.drawText(mXPos, mYPos, "😐");
}
