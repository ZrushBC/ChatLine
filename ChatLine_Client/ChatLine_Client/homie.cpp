
#include "homie.h"

Homie::Homie(QWidget *parent)
    : QWidget{parent}
{
//创建左侧
    leftWidget = new QWidget(this);
    leftWidget->setFixedWidth(150);
    leftWidget->setStyleSheet("background:rgb(245,245,245)");
    //布局
    lLayout = new QVBoxLayout();
    lLayout->setSpacing(0); //控件间间距
    lLayout->setMargin(0);
    lLayout->addStretch();
    leftWidget->setLayout(lLayout);
//创建右侧
    rightWidget=new QWidget(this);
    lab=new QLabel(rightWidget);
    lab->setText("好友");
    //布局
    rLayout=new QVBoxLayout();
    rLayout->addWidget(lab);
    rightWidget->setLayout(rLayout);
//总布局
    QHBoxLayout *Layout=new QHBoxLayout();
    Layout->setSpacing(0); //控件间间距
    Layout->setMargin(0);
    Layout->addWidget(leftWidget);
    Layout->addWidget(rightWidget);
    this->setLayout(Layout);
}
void Homie::add_homie(QString friend_inf){
    QPushButton *btn= new QPushButton(friend_inf,leftWidget);
    lLayout->addWidget(btn);
    lLayout->insertWidget(0,btn);
}
