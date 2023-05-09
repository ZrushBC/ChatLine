//登录
#ifndef SIGNIN_H
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
#include "pop.h"
#include "btn.h"
#define SIGNIN_H


class SignIn : public QWidget
{
    Q_OBJECT
public:
    explicit SignIn(QWidget *parent = nullptr);
    //鼠标按下
    void mousePressEvent(QMouseEvent *event);
    //鼠标移动
    void mouseMoveEvent(QMouseEvent *event);
    //记录鼠标，窗口位置
    QPoint windowPos;
    QPoint mousePos;
    QPoint dPos;
    //表层
    QWidget *back;
    //账号
    QLineEdit *CL_Id;
    //阴影
    QGraphicsDropShadowEffect * effect;
    //密码
    QLineEdit *CL_PassWord;
    //登录
    QPushButton *SignIn_Btn;
    //注册
    QPushButton *SignUp_Btn;
    //弹窗
    Pop *pop;
signals:
};

#endif // SIGNIN_H
