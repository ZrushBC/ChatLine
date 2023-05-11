
#include "cl_socket.h"

CL_Socket::CL_Socket(QObject *parent)
    : QObject{parent}
{
    //    QList <QHostAddress> addressList = QNetworkInterface::allAddresses();     //接收本机所有Ip地址
    //    for(int i = 0; i < addressList.size(); i++)
    //    {
    //        if(addressList.at(i).isNull()) continue;   //地址为空则跳过
    //        if(addressList.at(i).protocol() != QAbstractSocket::IPv4Protocol) continue;   //协议族不是ipv4的则跳过
    //        if(addressList.at(i).isLoopback()) continue;   //协议族不是ipv4的则跳过
    //        qDebug()<<addressList.at(i).toString()<<"---"<<i;
    //        addressList_str.append(addressList.at(i).toString());//符合条件的地址添加到列表中
    //    }
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &CL_Socket::readMessage);    //接收信息
    connect(socket, &QTcpSocket::disconnected, this, &CL_Socket::disconnectSlot);   //打印断开连接信息
}

//连接
bool CL_Socket::connection()
{
    //虚拟机
//    QString ipStr = "192.168.169.143";
    //本地
    QString ipStr = "127.0.0.1";
    //局域网
    //    QString ipStr = "10.1.140.229";
    QString port="8888";
    quint16 currentPort = port.toInt();   //当前端口
    if(!connectState)    //客户端还未连接服务端
    {
        socket->connectToHost(ipStr, currentPort);   //连接服务端
        quint16 localPort=10001;
        //        socket->bind(QHostAddress(addressList_str.at(1)),localPort);
        if(socket->waitForConnected())   //等待连接成功
        {
            qDebug()<<"--------------";
            qDebug()<<socket->peerAddress().toString();
            qDebug()<<QString::number(socket->peerPort());
            qDebug("连接成功");
            connectState = true;
            return true;
        }
        else     //连接失败
        {
            qDebug()<<"连接失败"<<socket->errorString();   //连接错误信息提醒
            return false;
        }
    }else return true;
}

//断开连接
void CL_Socket::close(){
    socket->close();   //关闭套接字，此时会发送disconnected信号
}

//接收信息
void CL_Socket::readMessage()
{
    QByteArray arr = socket->readAll();
    qDebug()<<arr.data();
    QString mes=arr.data();
    if(mes[0]!='0'){
        emit sys_signal(mes);
    }
    else{
        QString str;
        str = QDateTime::currentDateTime().toString("dddd yyyy.MM.dd hh:mm:ss") + '\n' + mes.mid(1);
        emit mes_signal(str);     //传递信息
    }
}

//发送信息
//0.消息
//1.登录验证
//2.注册验证
void CL_Socket::sendMessage(QString str,char type)
{
    str=type+str;
    if(socket->isOpen() && socket->isValid())
    {
        socket->write(str.toUtf8());    //给服务端发送信息
    }
    if(type=='0') {
        QString showStr = QDateTime::currentDateTime().toString("dddd yyyy.MM.dd hh:mm:ss") + '\n' + str.mid(1);
        emit mes_signal(showStr);
    }
}

//打印连接断开信息
void CL_Socket::disconnectSlot()
{
    qDebug("clint disconnected");
}
