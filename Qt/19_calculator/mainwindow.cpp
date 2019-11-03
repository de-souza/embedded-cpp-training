#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(
        ui->buttonGroup,
        QOverload<QAbstractButton*>::of(&QButtonGroup::buttonClicked),
        this,
        &MainWindow::OnButtonClick
    );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnButtonClick(const QAbstractButton* button)
{
    if (button == ui->pushButton_equal)
        ui->lineEdit->setText(Evaluate(ui->lineEdit->text()));
    else
        ui->lineEdit->setText(ui->lineEdit->text() + button->text());
}

QString MainWindow::Evaluate(const QString expr)
{
    QString result, op;
    for (QString token : expr.split(' '))
        if (IsOperator(token))
            op = token;
        else
            result.setNum(Process(op, result.toFloat(), token.toFloat()));
    return result;
}

float MainWindow::Process(const QString op, const float lhs, const float rhs)
{
    if (op == "+")
        return lhs + rhs;
    if (op == "−")
        return lhs - rhs;
    if (op == "×")
        return lhs * rhs;
    if (op == "/")
        return lhs / rhs;
    return rhs;
}

bool MainWindow::IsOperator(QString token)
{
    return token == "+" || token == "−" || token == "×" || token == "/";
}
