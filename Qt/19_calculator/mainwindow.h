#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    enum {IdNum0, IdNum1, IdNum2, IdNum3, IdNum4, IdNum5, IdNum6, IdNum7,
          IdNum8, IdNum9, IdDot, IdAdd, IdDiff, IdMult, IdDiv, IdEqual};
    QString GetText(const int);

public slots:
    void OnButtonClick(const int);

private:
    Ui::MainWindow* ui;
};

#endif // MAINWINDOW_H
