#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mypixmap.h"

#include <QMainWindow>
#include <QAbstractButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

public slots:
    void SetString(const QString);
    void SetSizePx(const int);
    void SetStringSizePx(const int);
    void SetOutlineWidthPx(const int);
    void SetOutlineRadiusPercent(const int);
    void SetBackgroundColor();
    void SetStringColor();
    void SetOutlineColor();
    void Reset(const QAbstractButton*);
    void Save();

private:
    Ui::MainWindow* ui;
    MyPixmap mMyPixmap;
    void mLoadPixmap();
};

#endif // MAINWINDOW_H
