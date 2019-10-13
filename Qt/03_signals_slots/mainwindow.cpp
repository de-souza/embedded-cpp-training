#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(Quit()));
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::Quit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Quit()
{
    close();
}
