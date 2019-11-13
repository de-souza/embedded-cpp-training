#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtNetwork>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Socket = new QTcpSocket(this);
    connect(
        ui->pushButton_connect,
        &QPushButton::clicked,
        this,
        &MainWindow::OnConnect
    );
    connect(
        ui->pushButton_send,
        &QPushButton::clicked,
        this,
        &MainWindow::OnSend
    );
    connect(
        ui->pushButton_quit,
        &QPushButton::clicked,
        this,
        &MainWindow::close
    );
    connect(
        Socket,
        &QAbstractSocket::readyRead,
        this,
        &MainWindow::OnReadyRead
    );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnConnect()
{
    Socket->abort();
    Socket->connectToHost(
        ui->lineEdit_ip->text(),
        static_cast<quint16>(ui->lineEdit_port->text().toInt())
    );
    if (Socket->state() == QTcpSocket::ConnectedState)
        ui->label_status->setText("Client connected.");
    else
        ui->label_status->setText("Error connecting client.");

}

void MainWindow::OnReadyRead()
{
    ui->label_status->setText("Message: " + ReadMessage());
}

void MainWindow::OnSend()
{
    if (Socket->state() == QTcpSocket::ConnectedState)
        WriteMessage(ui->lineEdit_message->text());
}

QString MainWindow::ReadMessage()
{
    QString message;
    QDataStream in;
    in.setDevice(Socket);
    in.setVersion(QDataStream::Qt_5_11);
    in.startTransaction();
    in >> message;
    if (!in.commitTransaction())
        return "Error reading message.";
    return message;
}

void MainWindow::WriteMessage(const QString message)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_11);
    out << message;
    Socket->write(block);
}
