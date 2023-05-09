
#include "pop.h"

Pop::Pop(QWidget *parent)
    : QWidget{parent}
{
    //弹窗
    popback=new QWidget(parent);
    popback->resize(200,20);
    popback->move(100,100);
    //透明
    popback->setAttribute(Qt::WA_TranslucentBackground);
    //阴影
    QGraphicsDropShadowEffect * effect = new QGraphicsDropShadowEffect(popback);
    effect->setColor(QColor(104,104,104));
    effect->setOffset(0,0);
    effect->setBlurRadius(15);
    popback->setGraphicsEffect(effect);
    //标签
    label=new QLabel(popback);
    label->resize(200,20);
//    label->setScaledContents(true);//自适应大小
    //透明
    label->setAttribute(Qt::WA_TranslucentBackground);
}

