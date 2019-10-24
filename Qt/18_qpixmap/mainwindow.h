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

private slots:
    void mUpdateSizePx(const int);
    void mUpdateStringColor();
    void mUpdateBackgroundColor();
    void mUpdateOutlineColor();
    void mUpdateOutlineWidthPx(const int);
    void mUpdateOutlineRadiusPercent(const int);

private:
    Ui::MainWindow* ui;
    struct mPixmapSettings {
        QString String;
        int SizePx;
        QColor StringColor;
        QColor BackgroundColor;
        QColor OutlineColor;
        int OutlineWidthPx;
        int OutlineRadiusPercent;
    };
    mPixmapSettings mPreviewSettings;
    QPixmap mCreatePixmap(mPixmapSettings settings);
    void mSetString(const QString);
    void mSetSizePx(const int);
    void mSetStringColor(const QColor);
    void mSetBackgroundColor(const QColor);
    void mSetOutlineColor(const QColor);
    void mSetOutlineWidthPx(const int);
    void mSetOutlineRadiusPercent(const int);
    void mUpdatePreview();
};

#endif // MAINWINDOW_H
