#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->lineEdit, &QLineEdit::editingFinished, this, &MainWindow::mPrintString);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mPrintString()
{
    const QString lineEdit_text = ui->lineEdit->text();
    qDebug() << lineEdit_text;
    ui->lineEdit->setText(lineEdit_text.toUpper());
}
