#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStringList>
#include <QCompleter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList first_names;
    first_names << "Florian" << "Gilles" << "Harout"    << "Henri" << "Hugo"
                << "Inna"    << "Jonas"  << "Karim"     << "Kodjo" << "Léa"
                << "Léo"     << "Maroua" << "Oluwasayo" << "Youcef";
    auto completer = new QCompleter(first_names, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit->setCompleter(completer);
}

MainWindow::~MainWindow()
{
    // No need for "delete completer" here as "completer" is a descendant of
    // MainWindow, which is a descendant of QObject.
    delete ui;
}

