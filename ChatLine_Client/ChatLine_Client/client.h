
#ifndef CLIENT_H
#include "signin.h"
#include <QWidget>
#include <QLineEdit> //单行文本输入框
#include <QPushButton>
#include <QMouseEvent>
#include <QPoint>
#include <QPainter>
#include <QGraphicsDropShadowEffect>
#include <QMessageBox>
#include <QTimer>
#include <QLabel>
#include <QDebug>
#include "btn.h"
#include "mainwindow.h"
#include "cl_socket.h"
#include "signup.h"
#include "user.h"
#include "pop.h"
#define CLIENT_H


#include <QObject>


class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);

    void init();
private:
    MainWindow *CL;
    CL_Socket *socket;
    SignUp *signup;
    SignIn signin;
    User user;
signals:

};

#endif // CLIENT_H
