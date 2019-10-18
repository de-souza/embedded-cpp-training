#ifndef MYPLAINTEXTEDIT_H
#define MYPLAINTEXTEDIT_H

#include <QPlainTextEdit>

class MyPlainTextEdit: public QPlainTextEdit
{
    Q_OBJECT

public:
    MyPlainTextEdit(QWidget* parent = nullptr);
    void contextMenuEvent(QContextMenuEvent* event);

private slots:
    void OnTrigger();
};
#endif // MYPLAINTEXTEDIT_H
