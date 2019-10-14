#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->dateEdit->setCalendarPopup(true);
    ui->dateEdit->setMinimumWidth(110);
    ui->spinBox->setRange(-100, 100);
    connect(ui->dateEdit, &QDateEdit::dateChanged, this, &MainWindow::mShowNewDate);
    connect(ui->spinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::mShowNewDate);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mShowNewDate()
{
    QDate new_date = ui->dateEdit->date();
    new_date = new_date.addDays(ui->spinBox->value());
    ui->label_result->setText(new_date.toString("dd/MM/yyyy"));
}
