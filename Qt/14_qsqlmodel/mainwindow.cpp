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
    QSqlTableModel *model = new QSqlTableModel(this, db);
    model->setTable("communes");
    model->select();
    ui->tableView->setModel(model);
    connect(ui->tableView, &QTableView::pressed, this, &MainWindow::mOnPress);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mOnPress(const QModelIndex &idx)
{
    ui->lineEdit_value->setText(idx.data().toString());
    ui->lineEdit_row->setText(QString::number(idx.row()));
    ui->lineEdit_column->setText(QString::number(idx.column()));
}
