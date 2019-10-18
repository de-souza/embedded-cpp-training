#include "mypushbutton.h"

MyPushButton::MyPushButton(QWidget* parent)
    : QPushButton(parent)
{}

void MyPushButton::mouseDoubleClickEvent(QMouseEvent*)
{
    emit doubleClicked();
}
