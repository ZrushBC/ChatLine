
#include "chat.h"

Chat::Chat(QWidget *parent)
    : QWidget{parent}
{
    //信息接收框
    text_read= new QTextBrowser(this);
//    text_read->move(20,20);
//    text_read->resize(700,400);
    //输入信息框
    text_send =new QPlainTextEdit(this);
//    text_send->move(20,440);
//    text_send->resize(600,100);
    //发送按钮
    send_btn =new QPushButton(this);
//    send_btn->move(650,440);
//    send_btn->resize(70,100);
    send_btn->setText("发送");
    QVBoxLayout *Layout = new QVBoxLayout();
    //创建一个头部信息
    QWidget *headWidget = new QWidget(this);
    headWidget->setFixedHeight(30);
    headWidget->setStyleSheet("background:rgb(255,169,150)");
    //设置布局
    Layout->setSpacing(0); //控件间间距
    Layout->setMargin(0);
    Layout->addWidget(headWidget);
    Layout->addWidget(text_read);
    Layout->addWidget(text_send);
    Layout->addWidget(send_btn);
    this->setLayout(Layout);

}

