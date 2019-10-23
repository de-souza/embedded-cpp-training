#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mypixmap.h"

#include <QMainWindow>
#include <QGraphicsScene>

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
    void mSetSizePx(const int sizePx);
    void mSetStringColor();
    void mSetBackgroundColor();
    void mSetOutlineWidthPx(const int outlineWidthPx);
    void mSetOutlineColor();

private:
    Ui::MainWindow* ui;
    MyPixmap mMyPixmap;
    QGraphicsScene* mpScene;
    void mInitInterface();
    void mUpdateString(const QString string);
    void mUpdateSizePx(const int sizePx);
    void mUpdateStringColor(const QColor stringColor);
    void mUpdateBackgroundColor(const QColor backgroundColor);
    void mUpdateOutlineWidthPx(const int outlineWidthPx);
    void mUpdateOutlineColor(const QColor outlineColor);
    void mUpdatePreview();
};

#endif // MAINWINDOW_H
