
#ifndef CL_SOCKET_H
#include <QTextBrowser> //文本显示框
#include <QPlainTextEdit> //文本输入框
#include <QPushButton>
#include <QDateTime>
#include <QTcpSocket>   //套接字
#include <QNetworkInterface>
#include <QHostAddress>
#include <QList>
#include <QMessageBox> //弹窗
#include <QString>
#define CL_SOCKET_H


#include <QObject>


class CL_Socket : public QObject
{
    Q_OBJECT
public:
    explicit CL_Socket(QObject *parent = nullptr);
    bool connection();   //连接
    void close(); //断连
    void sendMessage(QString str,char type='0'); //发送信息
private:
    QTcpSocket *socket;
    //    QStringList addressList_str;
    bool connectState; //客户连接状态

public slots:
    void readMessage(); //接受信息
    void disconnectSlot(); //断开连接
signals:
    void mes_signal(QString str); //收到消息的信号
    void sys_signal(QString str); //收到系统消息的信号
};

#endif // CL_SOCKET_H
