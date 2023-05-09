
#ifndef CL_SOCKET_H
#include <QDebug>
#include <QString>
#include <QDateTime>
#include <QTcpServer>
#include <QList>
#include <QTcpSocket>
#define CL_SOCKET_H


#include <QObject>


class CL_Socket : public QObject
{
    Q_OBJECT
public:
    explicit CL_Socket(QObject *parent = nullptr);
    void listen();      //监听槽函数
    void sendMessage(QString mes,QTcpSocket* sock); //发送系统信息
private:
    QTcpServer *server;   //服务端
    QList <QTcpSocket*> clientList_sock;   //多个客户端的套接字列表
    QTcpSocket *clintSock;
signals:
    void sys_signal(QString mes,QTcpSocket* sock);
private slots:
    void newConnectSlot();      //客户端连接后处理
    void disConnectSlot();      //客户端断开连接后处理
    void readMessage();         //接收信息的槽函数

};

#endif // CL_SOCKET_H
