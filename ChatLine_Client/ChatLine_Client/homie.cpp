
#include "homie.h"

Homie::Homie(QWidget *parent)
    : QWidget{parent}
{
    QLabel *xx=new QLabel(this);
    xx->setText("好友");
    xx->setStyleSheet("background:rgb(5,185,185)");
    xx->move(0,0);
    xx->resize(50,50);
}

