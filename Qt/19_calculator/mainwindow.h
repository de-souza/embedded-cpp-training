#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void On0();
    void On1();
    void On2();
    void On3();
    void On4();
    void On5();
    void On6();
    void On7();
    void On8();
    void On9();
    void OnDot();
    void OnAdd();
    void OnDiff();
    void OnMult();
    void OnDiv();
    void OnEqual();

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow* ui;
};

#endif // MAINWINDOW_H
