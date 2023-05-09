
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
        }
    });
}

void Server::init(){
    socket->listen();
    QString sql="select * from users";
    QSqlQuery res=db->select_all(sql);
//    qDebug()<<res.size();
}

