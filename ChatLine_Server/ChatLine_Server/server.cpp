
#include "server.h"

Server::Server(QObject *parent)
    : QObject{parent}
{
    socket=new CL_Socket;
    db=new CL_DB;
    connect(socket,&CL_Socket::sys_signal,this,[=](QString mes,QTcpSocket* sock){
        qDebug()<<mes;
        if(mes[0]=='1'){
            int pos=mes.indexOf(" ");
            QString CL_Id=mes.mid(1,pos-1);
            QString CL_PassWord=mes.mid(pos+1);
            qDebug()<<"账号密码"<<CL_Id<<" "<<CL_PassWord;
            QString sql="select * from users where cl_id='" + CL_Id + "' and cl_password='" + CL_PassWord + "'";
            QSqlQuery res=db->select_all(sql);
            qDebug()<<"查询结果为"<<res.size();
            if(res.size()){
                socket->sendMessage("11",sock);
            }else{
                socket->sendMessage("10",sock);
            }
        }else if(mes[0]=='2'){
            int pos=mes.indexOf(" ");
            QString CL_Name=mes.mid(1,pos-1);
            QString CL_PassWord=mes.mid(pos+1);
            QString CL_Id;
            do{
                CL_Id=this->getRandomID();
                QSqlQuery res=db->select_all("select * from users where cl_id='" + CL_Id + "'");
                if(!res.size()){
                    break;
                }
            }while(1);
            QString sql="insert into users values('"+CL_Id+"','"+CL_PassWord+"','"+CL_Name+"','/ddd/head')";
            if(db->commit_data(sql)){
                socket->sendMessage("21"+CL_Id,sock);
            }else{
                socket->sendMessage("20",sock);
            }
        }
    });
}

void Server::init(){
    socket->listen();
    QString sql="select * from users";
    QSqlQuery res=db->select_all(sql);
//    qDebug()<<res.size();
//    qDebug()<<getRandomID();
}

//获取长度为6的随机字符串作为分配的id
QString Server::getRandomID(){
    qsrand(QDateTime::currentMSecsSinceEpoch());

    const char ch[] = "abcdefghijklmnopqrstuvwxyz0123456789";
    int size = sizeof(ch);
    QString res;
    int num = 0;
    for (int i = 0; i < 6; ++i)
    {
        num = rand() % (size - 1);
        res.append(ch[num]);
    }
    return res;
}
