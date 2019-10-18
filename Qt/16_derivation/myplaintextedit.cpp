#include "myplaintextedit.h"

#include <QMenu>
#include <QDebug>

MyPlainTextEdit::MyPlainTextEdit(QWidget* parent)
    : QPlainTextEdit(parent)
{}

void MyPlainTextEdit::contextMenuEvent(QContextMenuEvent* pEvent)
{
    QMenu* pMenu = createStandardContextMenu();
    auto pAction = new QAction("My Action", this);
    pMenu->addAction(pAction);
    connect(pAction, &QAction::triggered, this, &MyPlainTextEdit::mOnTrigger);
    pMenu->exec(pEvent->globalPos());
    delete pMenu;
}

void MyPlainTextEdit::mOnTrigger()
{
    qDebug() << "Trigger";
}
