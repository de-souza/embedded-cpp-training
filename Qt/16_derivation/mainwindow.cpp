#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent*)
{
    qDebug() << this->width() << this->height();
}

void MainWindow::mousePressEvent(QMouseEvent* pEvent)
{
    if (pEvent->pos().y() > this->height()/2)
        qDebug() << "The mouse is in the bottom half of the window";
}
