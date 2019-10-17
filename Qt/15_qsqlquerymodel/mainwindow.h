#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQueryModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void mOnChange(const QString& rText);

private:
    Ui::MainWindow *ui;
    QSqlQueryModel* mpCityListModel = nullptr;
    QSqlQueryModel* mpCityCountModel = nullptr;
};
#endif // MAINWINDOW_H
