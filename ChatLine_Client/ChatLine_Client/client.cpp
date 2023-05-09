
#include "client.h"

Client::Client(QObject *parent)
    : QObject{parent}
{
    CL=new MainWindow;
    socket=new CL_Socket;
    signup=new SignUp;
    //接受到信息，并显示
    connect(socket,&CL_Socket::mes_signal,this,[=](QString str){
        CL->text_read->append(str);
    });
    //接受到系统信息，处理
    connect(socket,&CL_Socket::sys_signal,this,[=](QString str){
        qDebug()<<"处理："<<str;
        if(str[1]=='1'){
            signin.hide();
            CL->show();
        }else{
            signin.pop->label->setText("账号或密码错误");
            emit signin.pop->show_signal();
        }
    });
    //弹窗
    connect(signin.pop,&Pop::show_signal,this,[=](){
        signin.pop->popback->show();
        QTimer::singleShot(500, this,[=](){
            signin.pop->popback->close();
        });
    });
    //点击发送按钮
    connect(CL->send_btn,&QPushButton::clicked,this,[=](){
        QString str = CL->text_send->toPlainText();
        CL->text_send->clear();
        socket->sendMessage(str);
    });
    //点击登录按钮
    connect(signin.SignIn_Btn,&QPushButton::clicked,this,[=](){
        if(signin.CL_Id->text().isEmpty()){
            signin.pop->label->setText("请输入账号后再登录");
            emit signin.pop->show_signal();
        }else if(signin.CL_PassWord->text().isEmpty()){
            signin.pop->label->setText("请输入密码后再登录");
            emit signin.pop->show_signal();
        }else if(!socket->connection()){
            signin.pop->label->setText("请检查网络后重试");
            emit signin.pop->show_signal();
        }else {
            QString mes=signin.CL_Id->text()+' '+signin.CL_PassWord->text();
            socket->sendMessage(mes,'1');
        }
        qDebug()<<"------文本框-------";
        qDebug()<<signin.CL_Id->width()<<signin.CL_Id->height();
        qDebug()<<signin.CL_Id->text()<<signin.CL_PassWord->text();
        qDebug()<<"------文本框-------";
        //        QMessageBox::information(NULL,  "Title",  "Content", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    });
    //点击注册按钮
    connect(signin.SignUp_Btn,&QPushButton::clicked,this,[=](){
        signin.hide();
        signup->show();
    });
    //注册界面点击注册
    connect(signup->SignUp_Btn,&QPushButton::clicked,this,[=](){
        signup->hide();
        signin.show();
    });
}

void Client::init(){
    signin.show();
}
