#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calculate.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(
        ui->buttonGroup,
        QOverload<QAbstractButton*>::of(&QButtonGroup::buttonClicked),
        this,
        &MainWindow::OnButtonClick
    );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnButtonClick(const QAbstractButton* button)
{
    if (button == ui->pushButton_equal)
        ui->lineEdit->setText(Evaluate(ui->lineEdit->text()));
    else
        ui->lineEdit->setText(ui->lineEdit->text() + button->text());
}

QString MainWindow::Evaluate(const QString)
{

}
