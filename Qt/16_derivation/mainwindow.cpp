#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->myPushButton, &MyPushButton::clicked, this, &MainWindow::mOnClick);
    connect(ui->myPushButton, &MyPushButton::doubleClicked, this, &MainWindow::mOnDoubleClick);
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
        qDebug() << "Mouse press in the bottom half of the window";
}

void MainWindow::mOnClick()
{
    qDebug() << "Click";
}

void MainWindow::mOnDoubleClick()
{
    qDebug() << "Double-click";
}
