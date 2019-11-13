#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtNetwork>
#include <QMessageBox>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Server = new QTcpServer(this);
    Socket = nullptr;
    connect(
        ui->pushButton_start,
        &QPushButton::clicked,
        this,
        &MainWindow::OnStart
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
        Server,
        &QTcpServer::newConnection,
        this,
        &MainWindow::OnNewConnection
    );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnStart()
{
    if (Server->listen()) {
        ui->label_status->setText("Server started.");
        ui->label_ip->setText("IP: " + Ip());
        ui->label_port->setText(
            "Port: " + QString::number(Server->serverPort())
        );
    } else {
        ui->label_status->setText("Cannot start server.");
    }
}

void MainWindow::OnSend()
{
    if (Socket != nullptr)
        WriteMessage(ui->lineEdit_message->text());
}

void MainWindow::OnNewConnection()
{
    Socket = Server->nextPendingConnection();
    connect(
        Socket,
        &QAbstractSocket::disconnected,
        Socket,
        &QObject::deleteLater
    );
    ui->label_status->setText(
       "New connection from " + Socket->peerAddress().toString() + "."
    );
    connect(
        Socket,
        &QAbstractSocket::readyRead,
        this,
        &MainWindow::OnReadyRead
    );
}

void MainWindow::OnReadyRead()
{
    ui->label_status->setText("Message: " + ReadMessage());
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

QString MainWindow::Ip()
{
    for (QHostAddress ip : QNetworkInterface::allAddresses())
        if (ip != QHostAddress::LocalHost && ip.toIPv4Address())
            return ip.toString();
    return QHostAddress(QHostAddress::LocalHost).toString();
}
