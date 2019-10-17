#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSqlTableModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("communes.db");
    if (!db.open())
        exit(EXIT_FAILURE);
    auto model = new QSqlTableModel(this);
    model->setTable("communes");
    model->select();
    ui->tableView->setModel(model);
    connect(ui->tableView, &QTableView::pressed, this, &MainWindow::mOnPress);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mOnPress(const QModelIndex& rIdx)
{
    ui->lineEdit_value->setText(rIdx.data().toString());
    ui->lineEdit_row->setText(QString::number(rIdx.row()));
    ui->lineEdit_column->setText(QString::number(rIdx.column()));
}
