
#include "cl_socket.h"

CL_Socket::CL_Socket(QObject *parent)
    : QObject{parent}
{
    server = new QTcpServer(this);      //创建服务端
    connect(server, &QTcpServer::newConnection, this, &CL_Socket::newConnectSlot);     //有新连接时传入信号

}

//新的客户端连接
void CL_Socket::newConnectSlot()
{
    clintSock = server->nextPendingConnection();      //获取当前连接的客户端套接字
    clientList_sock.push_back(clintSock);           //将连接的客户端放入客户端列表中
    QString str = clintSock->peerAddress().toString() + ": " + QString::number(clintSock->peerPort()) + "已经连接";
    qDebug()<<str;  //将连接信息放在列表窗口中

    connect(clintSock, &QTcpSocket::readyRead, this, &CL_Socket::readMessage);  //准备接受信息
    connect(clintSock, &QTcpSocket::disconnected, this, &CL_Socket::disConnectSlot);   //客户端的断开连接信息
}

//读取客户端信息及给其他客户端发送信息
void CL_Socket::readMessage()
{
    QTcpSocket*  currentClint;
    QByteArray arr;
    QString str;
    if(!clientList_sock.isEmpty())      //有客户端存在
    {
        for(int i = 0; i < clientList_sock.count(); i++)     //服务端接收信息
        {
            arr = clientList_sock.at(i)->readAll();      //接收客户端发送的字节信息
            if(arr.isNull())  continue;   //空代表不是该客户端发送
            currentClint = clientList_sock.at(i);
            if(arr.data()[0]!=0){
                emit sys_signal(arr.data(),currentClint);
                return;
            }
            str = QDateTime::currentDateTime().toString("dddd.yyyy.MM.dd HH:mm:ss") + '\n' + arr.data();
            break;
        }
        qDebug()<<str;     //显示信息
        for(int i = 0; i < clientList_sock.count(); i++)     //给其它客户端发送信息
        {
            QTcpSocket *temp = clientList_sock.at(i);
            if(currentClint == temp)  continue;      //遇到自己就跳过
            temp->write(str.toUtf8());   //发送信息
        }
    }

}

//发送系统信息
void CL_Socket::sendMessage(QString mes,QTcpSocket* sock){
    sock->write(mes.toUtf8());
}

//客户端断开连接时服务端显示断开信息
void CL_Socket::disConnectSlot()
{
    QString closeStr = QDateTime::currentDateTime().toString("dddd.yyyy.MM.dd HH:mm:ss") + ' ' + "clint close";
    qDebug()<<closeStr;
}

//服务端开始监听
void CL_Socket::listen()
{
    QString port="8888";
    quint16 currentPort = port.toInt();       //当前文本框的显示的端口
//    QHostAddress currentHostIP = QHostAddress(currentIp);   //地址字符串转换成主机Ip
    if(server->isListening())     //客户端正在监听
    {
        server->close();   //关闭客户端
        qDebug("关闭监听");
    }

    else    //客户端没有在监听
    {
        //*修改了第一个参数*原参：currentHostIP————>QHostAddress::Any
        if(server->listen(QHostAddress::Any, currentPort))   //监听成功返回true
        {
            qDebug()<<server->serverAddress();
            qDebug("----------开始监听-----------");
        }
        else    //监听失败
            qDebug()<<"失败"<<server->errorString();   //出现错误
    }
}
