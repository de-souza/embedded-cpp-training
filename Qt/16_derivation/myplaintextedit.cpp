#include "myplaintextedit.h"

#include <QMenu>
#include <QDebug>

MyPlainTextEdit::MyPlainTextEdit(QWidget* parent)
    : QPlainTextEdit(parent)
{}

void MyPlainTextEdit::contextMenuEvent(QContextMenuEvent* event)
{
    QMenu* pMenu = createStandardContextMenu();
    auto pAction = new QAction("My Action", this);
    pMenu->addAction(pAction);
    connect(pAction, &QAction::triggered, this, &MyPlainTextEdit::OnTrigger);
    pMenu->exec(event->globalPos());
    delete pMenu;
}

void MyPlainTextEdit::OnTrigger()
{
    qDebug() << "Triggered";
}
