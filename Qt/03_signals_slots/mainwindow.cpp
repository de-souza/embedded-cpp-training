#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(Quit()));  // Before C++11
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::mQuit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mQuit()
{
    close();
}
