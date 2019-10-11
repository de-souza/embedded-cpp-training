#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::on_pushButton_clicked()
{
    QPalette* palette = new QPalette();
    palette->setColor(QPalette::Base, Qt::lightGray);
    palette->setColor(QPalette::Text, Qt::gray);
    ui->lineEdit_FirstName->setPalette(*palette);
    delete palette;
//    ui->lineEdit_FirstName->setDisabled(true);
    ui->lineEdit_FirstName->setText("Grayed Out");
}
