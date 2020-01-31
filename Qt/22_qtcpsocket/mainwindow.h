#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>

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
    void OnConnect();
    void OnSend();
    void OnReadyRead();

private:
    Ui::MainWindow* ui;
    QTcpSocket* Socket;
    QString ReadMessage();
    void WriteMessage(const QString);
};

#endif // MAINWINDOW_H