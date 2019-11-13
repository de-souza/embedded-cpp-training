#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void OnStart();
    void OnSend();
    void OnNewConnection();
    void OnReadyRead();

private:
    Ui::MainWindow* ui;
    QTcpServer* Server;
    QTcpSocket* Socket;
    void WriteMessage(const QString);
    QString ReadMessage();
    QString Ip();
};

#endif // MAINWINDOW_H
