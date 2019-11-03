#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStack>

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
        ui->lineEdit->setText(
            Evaluate(ToPostfix(ui->lineEdit->text().split(' ')))
        );
    else if (button == ui->pushButton_clear)
        ui->lineEdit->setText("");
    else
        ui->lineEdit->setText(ui->lineEdit->text() + button->text());
}

QStringList MainWindow::ToPostfix(const QStringList infix)
{
    QStringList postfix;
    QStack<QString> stack;
    for (QString token : infix) {
        if (token == "(") {
            stack.push(token);
        } else if (token == ")") {
            while (!stack.isEmpty())
                if (stack.top() != "(")
                    postfix.append(stack.pop());
                else
                    break;
            stack.pop();
        } else if (IsOperator(token)) {
            while (!stack.isEmpty())
                if (stack.top() != "(" && Precedence(token, stack.top()) < 0)
                    postfix.append(stack.pop());
                else
                    break;
            stack.push(token);
        } else {
            postfix.append(token);
        }
    }
    while (!stack.isEmpty())
        postfix.append(stack.pop());
    return postfix;
}

QString MainWindow::Evaluate(const QStringList postfix)
{
    QString result;
    QStack<QString> stack;
    for (QString token : postfix) {
        if (IsOperator(token)) {
            float rhs = stack.pop().toFloat();
            float lhs = stack.pop().toFloat();
            result.setNum(Process(token, lhs, rhs));
            stack.push(result);
        } else {
            stack.push(token);
        }
    }
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

int MainWindow::Precedence(const QString op1, const QString op2)
{
    if ((op1 == "+" || op1 == "−") && (op2 == "×" || op2 == "/"))
        return -1;
    if ((op1 == "×" || op1 == "/") && (op2 == "+" || op2 == "−"))
        return 1;
    return 0;
}
