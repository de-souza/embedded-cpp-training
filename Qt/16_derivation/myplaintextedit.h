#ifndef MYPLAINTEXTEDIT_H
#define MYPLAINTEXTEDIT_H

#include <QPlainTextEdit>

class MyPlainTextEdit: public QPlainTextEdit
{
    Q_OBJECT

public:
    MyPlainTextEdit(QWidget* parent = nullptr);

private slots:
    void OnTrigger();

private:
    void contextMenuEvent(QContextMenuEvent* event);
};
#endif // MYPLAINTEXTEDIT_H
