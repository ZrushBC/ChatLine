
#include "chat.h"

Chat::Chat(QWidget *parent)
    : QWidget{parent}
{
//创建右侧
    QWidget *rightWidget=new QWidget(this);
    //信息接收框
    text_read= new QTextBrowser(rightWidget);
//    text_read->move(20,20);
//    text_read->resize(700,400);
    //取消边框
    text_read->setStyleSheet("QTextBrowser{border-color:rgb(133,133,133);border-width:1;border-style:solid none solid none;}");
    //输入信息框
    text_send =new QPlainTextEdit(rightWidget);
//    text_send->move(20,440);
//    text_send->resize(600,100);
    //取消边框
    text_send->setStyleSheet("QPlainTextEdit{border-width:0;border-style:none;}");
    //发送按钮
    send_btn =new QPushButton(rightWidget);
//    send_btn->move(650,440);
//    send_btn->resize(70,100);
    send_btn->setText("发送");
    //创建一个头部信息
    headWidget = new QWidget(rightWidget);
    headWidget->setFixedHeight(30);
//    headWidget->setStyleSheet("background:rgb(255,169,150)");
    //设置布局
    QVBoxLayout *rLayout = new QVBoxLayout();
    rLayout->setSpacing(0); //控件间间距
    rLayout->setMargin(0);
    rLayout->addWidget(headWidget);
    rLayout->addWidget(text_read);
    rLayout->addWidget(text_send);
    rLayout->addWidget(send_btn);
    rightWidget->setLayout(rLayout);
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
//总布局
    QHBoxLayout *Layout = new QHBoxLayout();
    Layout->setSpacing(0); //控件间间距
    Layout->setMargin(0);
    Layout->addWidget(leftWidget);
    Layout->addWidget(rightWidget);
    this->setLayout(Layout);
}

void Chat::add_chat(){
    QPushButton *btn= new QPushButton("111",leftWidget);
    lLayout->addWidget(btn);
    lLayout->insertWidget(0,btn);
    QPushButton *btn1= new QPushButton("222",leftWidget);
    lLayout->addWidget(btn1);
    lLayout->insertWidget(0,btn1);
}
