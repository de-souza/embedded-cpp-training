#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class MyPushButton: public QPushButton
{
    Q_OBJECT

public:
    MyPushButton(QWidget* parent = nullptr);

signals:
    void doubleClicked();

private:
    void mouseDoubleClickEvent(QMouseEvent*);
};
#endif // MYPUSHBUTTON_H
