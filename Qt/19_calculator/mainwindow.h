#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void OnButtonClick(const QAbstractButton*);

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    QString Evaluate(const QString);
    float Process(const QString op, const float lhs, const float rhs);
    bool IsOperator(const QString);

private:
    Ui::MainWindow* ui;
};

#endif // MAINWINDOW_H
