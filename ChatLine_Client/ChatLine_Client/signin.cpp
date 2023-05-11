#include "signin.h"
#include <qdebug.h>
SignIn::SignIn(QWidget *parent)
    : QWidget{parent}
{
    //表层
    back = new QWidget(this);
    back->setStyleSheet("background:rgb(245,245,245)");
    back->setFixedSize(490,299);
    back->move(5,5);
    //取消原始边框
    this->setWindowFlags(Qt::FramelessWindowHint);
    //设置透明
    this->setAttribute(Qt::WA_TranslucentBackground);
    //    this->setStyleSheet("background:rgb(185,185,185)");
    //设置窗口大小
    this->setFixedSize(500,309);
    //账号
    CL_Id =new QLineEdit(back);
    CL_Id->move(130,100);
    //浮显文字
    CL_Id->setPlaceholderText("ChatLine账号");
    //边框
    CL_Id->setStyleSheet("QLineEdit{border-width:1;border-style:none none solid none;}");
    //    CL_Id->resize(600,50);
    //密码
    CL_PassWord =new QLineEdit(back);
    CL_PassWord->move(130,140);
    CL_PassWord->setPlaceholderText("密码");
    //显示格式,Normal, NoEcho, Password, PasswordEchoOnEdit
    CL_PassWord->setEchoMode(QLineEdit::EchoMode::Password);
    CL_PassWord->setStyleSheet("QLineEdit{border-width:1;border-style:none none solid none;}");
    //    CL_PassWord->resize(200,20);
    //登录
    SignIn_Btn =new QPushButton(back);
    SignIn_Btn->setText("登录");
    SignIn_Btn->move(130,180);
    //    SignIn_Btn->resize(100,50);
    //注册
    SignUp_Btn =new QPushButton(back);
    SignUp_Btn->setText("注册");
    SignUp_Btn->move(230,180);
    //阴影
    effect = new QGraphicsDropShadowEffect(this);
    effect->setColor(QColor(104,104,104));
    effect->setOffset(0,0);
    effect->setBlurRadius(15);
    this->setGraphicsEffect(effect);
    //关闭按钮
    Btn *close_btn=new Btn(true);
    close_btn->setParent(back);
    close_btn->move(this->width()-close_btn->width()-12,10);
    connect(close_btn,&QPushButton::clicked,this,&SignIn::close);
    //最小化按钮
    Btn *min_btn=new Btn(false);
    min_btn->setParent(back);
    min_btn->move(this->width()-min_btn->width()-32,10);
    connect(min_btn,&QPushButton::clicked,this,&SignIn::showMinimized);
    //弹窗
    pop =new Pop(back);
    pop->popback->close();
}

//鼠标按下事件
void SignIn::mousePressEvent(QMouseEvent *event)
{
    this->windowPos = this->pos();       // 获得部件当前位置
    this->mousePos = event->globalPos(); // 获得鼠标位置
    this->dPos = mousePos - windowPos;   // 移动后部件所在的位置
}

//鼠标移动事件
void SignIn::mouseMoveEvent(QMouseEvent *event)
{

    this->move(event->globalPos() - this->dPos);
}
