#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSqlQuery>
#include <QSqlQueryModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->comboBox, &QComboBox::currentTextChanged, this, &MainWindow::mOnChange);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("communes.db");
    if (!db.open())
        exit(EXIT_FAILURE);
    auto model = new QSqlQueryModel(this);
    model->setQuery("SELECT DISTINCT dep FROM communes");
    ui->comboBox->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mOnChange(const QString& rText)
{
    if (mpCitesModel != nullptr)
        delete mpCitesModel;
    mpCitesModel = new QSqlQueryModel(this);
    mpCitesModel->setQuery(QString("SELECT libelle FROM communes WHERE dep='%1'").arg(rText));
    ui->listView->setModel(mpCitesModel);
    QSqlQuery query(QString("SELECT COUNT(libelle) FROM communes WHERE dep='%1'").arg(rText));
    query.next();
    ui->lineEdit->setText(query.value(0).toString());
}
