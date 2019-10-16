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
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static QFont LoadFont();
    static void SaveFont(QFont font);
    static QString StyleToString(QFont::Style style);
    static QString WeightToString(QFont::Weight weight);

private slots:
    void mOptions();
    void mResetFont();

private:
    Ui::MainWindow *ui;
    void mUpdateFont();
};
#endif // MAINWINDOW_H
