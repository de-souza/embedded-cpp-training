#ifndef MYPLAINTEXTEDIT_H
#define MYPLAINTEXTEDIT_H

#include <QPlainTextEdit>

class MyPlainTextEdit: public QPlainTextEdit
{
    Q_OBJECT

public:
    MyPlainTextEdit(QWidget* parent = nullptr);

private slots:
    void mOnTrigger();

private:
    void contextMenuEvent(QContextMenuEvent* pEvent);
};
#endif // MYPLAINTEXTEDIT_H
