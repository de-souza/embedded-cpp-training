#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <memory>

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
    auto palette = std::make_unique<QPalette>();
    palette->setColor(QPalette::Base, Qt::lightGray);
    palette->setColor(QPalette::Text, Qt::gray);
    ui->lineEdit_FirstName->setPalette(*palette);
//    ui->lineEdit_FirstName->setDisabled(true);
    ui->lineEdit_FirstName->setText("Grayed Out");
}
