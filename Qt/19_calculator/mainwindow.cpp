#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calculate.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->buttonGroup->setId(ui->pushButton_0, IdNum0);
    ui->buttonGroup->setId(ui->pushButton_1, IdNum1);
    ui->buttonGroup->setId(ui->pushButton_2, IdNum2);
    ui->buttonGroup->setId(ui->pushButton_3, IdNum3);
    ui->buttonGroup->setId(ui->pushButton_4, IdNum4);
    ui->buttonGroup->setId(ui->pushButton_5, IdNum5);
    ui->buttonGroup->setId(ui->pushButton_6, IdNum6);
    ui->buttonGroup->setId(ui->pushButton_7, IdNum7);
    ui->buttonGroup->setId(ui->pushButton_8, IdNum8);
    ui->buttonGroup->setId(ui->pushButton_9, IdNum9);
    ui->buttonGroup->setId(ui->pushButton_dot, IdDot);
    ui->buttonGroup->setId(ui->pushButton_equal, IdEqual);
    ui->buttonGroup->setId(ui->pushButton_add, IdAdd);
    ui->buttonGroup->setId(ui->pushButton_diff, IdDiff);
    ui->buttonGroup->setId(ui->pushButton_mult, IdMult);
    ui->buttonGroup->setId(ui->pushButton_div, IdDiv);
    connect(
        ui->buttonGroup,
        QOverload<int>::of(&QButtonGroup::buttonClicked),
        this,
        &MainWindow::OnButtonClick
    );
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::GetText(const int id)
{
    switch (id) {
    case IdNum0: return "0";
    case IdNum1: return "1";
    case IdNum2: return "2";
    case IdNum3: return "3";
    case IdNum4: return "4";
    case IdNum5: return "5";
    case IdNum6: return "6";
    case IdNum7: return "7";
    case IdNum8: return "8";
    case IdNum9: return "9";
    case IdDot: return ".";
    case IdAdd: return "+";
    case IdDiff: return "-";
    case IdMult: return "*";
    case IdDiv: return "/";
    default: return "?";
    }
}

void MainWindow::OnButtonClick(const int id)
{
    if (id == IdEqual)
        ui->lineEdit->setText(Calculate::GetResult(ui->lineEdit->text()));
    else
        ui->lineEdit->setText(ui->lineEdit->text() + GetText(id));
}
