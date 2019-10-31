#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_0, &QPushButton::clicked, this, &MainWindow::On0);
    connect(ui->pushButton_1, &QPushButton::clicked, this, &MainWindow::On1);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::On2);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::On3);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::On4);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &MainWindow::On5);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &MainWindow::On6);
    connect(ui->pushButton_7, &QPushButton::clicked, this, &MainWindow::On7);
    connect(ui->pushButton_8, &QPushButton::clicked, this, &MainWindow::On8);
    connect(ui->pushButton_9, &QPushButton::clicked, this, &MainWindow::On9);
    connect(ui->pushButton_dot, &QPushButton::clicked, this, &MainWindow::OnDot);
    connect(ui->pushButton_add, &QPushButton::clicked, this, &MainWindow::OnAdd);
    connect(ui->pushButton_diff, &QPushButton::clicked, this, &MainWindow::OnDiff);
    connect(ui->pushButton_mult, &QPushButton::clicked, this, &MainWindow::OnMult);
    connect(ui->pushButton_div, &QPushButton::clicked, this, &MainWindow::OnDiv);
    connect(ui->pushButton_equal, &QPushButton::clicked, this, &MainWindow::OnEqual);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::On0()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "0");
}

void MainWindow::On1()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "1");
}

void MainWindow::On2()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "2");
}

void MainWindow::On3()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "3");
}

void MainWindow::On4()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "4");
}

void MainWindow::On5()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "5");
}

void MainWindow::On6()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "6");
}

void MainWindow::On7()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "7");
}

void MainWindow::On8()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "8");
}

void MainWindow::On9()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "9");
}

void MainWindow::OnDot()
{
    ui->lineEdit->setText(ui->lineEdit->text() + ".");
}

void MainWindow::OnAdd()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "+");
}

void MainWindow::OnDiff()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "-");
}

void MainWindow::OnMult()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "*");
}

void MainWindow::OnDiv()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "/");
}

void MainWindow::OnEqual()
{

}
