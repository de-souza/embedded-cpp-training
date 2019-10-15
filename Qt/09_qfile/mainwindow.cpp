#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "about.h"

#include <QFileDialog>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::mAbout);
    connect(ui->actionExit, &QAction::triggered, this, &MainWindow::close);
    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::mOpen);
    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::mSave);
    connect(ui->actionSave_As, &QAction::triggered, this, &MainWindow::mSaveAs);
}

MainWindow::~MainWindow()
{
    delete mpCurrentFile;
    delete ui;
}

void MainWindow::mAbout()
{
    About about(this);
    about.exec();
}

void MainWindow::mOpen()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open File", QDir::homePath());
    mpCurrentFile = new QFile(filename);
    mpCurrentFile->open(QIODevice::ReadOnly);
    ui->plainTextEdit->setPlainText(mpCurrentFile->readAll());
    mpCurrentFile->close();
}

void MainWindow::mSave()
{
    mpCurrentFile->open(QIODevice::WriteOnly);
    QTextStream fs(mpCurrentFile);
    fs << ui->plainTextEdit->toPlainText();
    mpCurrentFile->close();
}

void MainWindow::mSaveAs()
{
    QString filename = QFileDialog::getSaveFileName(this, "Save File", QDir::homePath());
    delete mpCurrentFile;
    mpCurrentFile = new QFile(filename);
    mSave();
}
