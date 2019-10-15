#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "about.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionExit, &QAction::triggered, this, &MainWindow::close);
    connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::mAbout);
    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::mOpen);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mAbout()
{
    About about(this);
    about.exec();
}

void MainWindow::mOpen()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                    QString("Open File"),
                                                    QDir::homePath());
    QFile file(filename);
    file.open(QIODevice::ReadWrite);
    ui->plainTextEdit->setPlainText(file.readAll());
}
