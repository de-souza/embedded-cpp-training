#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->comboBox, &QComboBox::currentTextChanged, this, &MainWindow::mShowAge);
    mHashTable = new QHash<QString, int>;
    (*mHashTable)["Léo"] = 24;
    (*mHashTable)["Karim"] = 31;
    ui->comboBox->addItems(mHashTable->keys());
    ui->lineEdit->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mShowAge(QString name)
{
    ui->lineEdit->setText(QString::number(mHashTable->value(name)));
}
