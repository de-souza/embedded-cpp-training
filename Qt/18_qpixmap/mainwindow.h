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

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void mUpdateSizePx(const int);
    void mUpdateStringSizePx(const int);
    void mUpdateStringColor();
    void mUpdateBackgroundColor();
    void mUpdateOutlineColor();
    void mUpdateOutlineWidthPx(const int);
    void mUpdateOutlineRadiusPercent(const int);
    void mUpdateString(const QString);
    void mOnButtonClick(const QAbstractButton*);

private:
    Ui::MainWindow* ui;
    int mSizePx;
    int mStringSizePx;
    QString mString;
    QColor mStringColor;
    QColor mBackgroundColor;
    QColor mOutlineColor;
    int mOutlineWidthPx;
    int mOutlineRadiusPercent;
    QPixmap mCreatePixmap(QString string);
    void mSetDefaults();
    void mSetSizePx(const int);
    void mSetStringSizePx(const int);
    void mSetStringColor(const QColor);
    void mSetBackgroundColor(const QColor);
    void mSetOutlineColor(const QColor);
    void mSetOutlineWidthPx(const int);
    void mSetOutlineRadiusPercent(const int);
    void mSetString(const QString);
    void mUpdatePreview();
    void mSaveVisibleAscii();
    void mSaveChar(char ch, QString directory);
};

#endif // MAINWINDOW_H
