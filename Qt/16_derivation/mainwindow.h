#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:
    void mDoubleClicked();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
    void paintEvent(QPaintEvent*) override;
    void mousePressEvent(QMouseEvent* pEvent) override;
    void mOnClick();
    void mOnDoubleClick();
};
#endif // MAINWINDOW_H
