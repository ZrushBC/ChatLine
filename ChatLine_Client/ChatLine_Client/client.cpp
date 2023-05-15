
#include "client.h"

Client::Client(QObject *parent)
    : QObject{parent}
{
    CL=new MainWindow;
    socket=new CL_Socket;
    signup=new SignUp;
    signin=new SignIn;
    //接受到信息，并显示
    connect(socket,&CL_Socket::mes_signal,this,[=](QString str){
        CL->chat->text_read->append(str);
    });

    //接受到系统信息，处理
    connect(socket,&CL_Socket::sys_signal,this,[=](QString str){
        qDebug()<<"处理："<<str;
        if(str[0]=='1'){
            if(str[1]=='1'){
                signin->hide();
                CL->show();
                friend_list(str.mid(2));
            }else{
                signin->pop->label->setText("账号或密码错误");
                emit signin->pop->show_signal();
            }
        }else if(str[0]=='2'){
            if(str[1]=='1'){
                QString id=str.mid(2);
                qDebug()<<id;
                signup->hide();
                signin->show();
//              signin->CL_Id->insert(id);
                QTest::qSleep(1000);
                signin->CL_Id->setText(id);
            }else{
                signup->pop->label->setText("注册失败，请稍后再试");
                emit signup->pop->show_signal();
            }
        }

    });

    //弹窗
    connect(signin->pop,&Pop::show_signal,this,[=](){
        signin->pop->popback->show();
        QTimer::singleShot(800, this,[=](){
            signin->pop->popback->close();
        });
    });
    connect(signup->pop,&Pop::show_signal,this,[=](){
        signup->pop->popback->show();
        QTimer::singleShot(800, this,[=](){
            signup->pop->popback->close();
        });
    });

    //点击发送按钮
    connect(CL->chat->send_btn,&QPushButton::clicked,this,[=](){
        QString str = CL->chat->text_send->toPlainText();
        CL->chat->text_send->clear();
        socket->sendMessage(str,'0');
    });

    //登录界面点击登录按钮
    connect(signin->SignIn_Btn,&QPushButton::clicked,this,[=](){
        if(signin->CL_Id->text().isEmpty()){
            signin->pop->label->setText("请输入账号后再登录");
            emit signin->pop->show_signal();
        }else if(signin->CL_PassWord->text().isEmpty()){
            signin->pop->label->setText("请输入密码后再登录");
            emit signin->pop->show_signal();
        }else if(!socket->connection()){
            signin->pop->label->setText("请检查网络后重试");
            emit signin->pop->show_signal();
        }else {
            QString mes=signin->CL_Id->text()+' '+signin->CL_PassWord->text();
            socket->sendMessage(mes,'1');
        }
    });

    //登陆界面点击注册
    connect(signin->SignUp_Btn,&QPushButton::clicked,this,[=](){
        signin->CL_Id->clear();
        signin->CL_PassWord->clear();
        signin->hide();
        signup->show();
    });

    //注册界面点击注册
    connect(signup->SignUp_Btn,&QPushButton::clicked,this,[=](){
        if(signup->CL_Name->text().isEmpty()){
            signup->pop->label->setText("请输入昵称");
            emit signup->pop->show_signal();
        }else if(signup->CL_Name->text().indexOf(" ")!=-1){
            signup->pop->label->setText("昵称中不能含有空格");
            emit signup->pop->show_signal();
        }else if(signup->CL_PassWord->text().isEmpty()){
            signup->pop->label->setText("请输入密码");
            emit signup->pop->show_signal();
        }else if(signup->CL_PassWord->text().indexOf(" ")!=-1){
            signup->pop->label->setText("密码中不能含有空格");
            emit signup->pop->show_signal();
        }else if(signup->re_CL_PassWord->text().isEmpty()){
            signup->pop->label->setText("请再次输入密码");
            emit signup->pop->show_signal();
        }else if(signup->CL_PassWord->text().compare(signup->re_CL_PassWord->text())){
            signup->pop->label->setText("两次密码不一致");
            emit signup->pop->show_signal();
        }else if(!socket->connection()){
            signup->pop->label->setText("请检查网络后重试");
            emit signup->pop->show_signal();
        }else {
            QString mes=signup->CL_Name->text()+' '+signup->CL_PassWord->text();
            socket->sendMessage(mes,'2');
        }
    });
    //注册界面点击登录
    connect(signup->SignIn_Btn,&QPushButton::clicked,this,[=](){
        signup->CL_Name->clear();
        signup->CL_PassWord->clear();
        signup->re_CL_PassWord->clear();
        signup->hide();
        signin->show();
    });
}

void Client::init(){
    signin->show();
}

void Client::friend_list(QString friends){
    qDebug()<<friends.indexOf(" ")<<friends.mid(friends.indexOf(" ")+1).indexOf(" ");
    CL->homie->add_homie("friends");
}
