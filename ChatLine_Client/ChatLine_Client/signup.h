//注册
#ifndef SIGNUP_H
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
#include "btn.h"
#define SIGNUP_H


#include <QWidget>


class SignUp : public QWidget
{
    Q_OBJECT
public:
    explicit SignUp(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event);
    //鼠标移动
    void mouseMoveEvent(QMouseEvent *event);
    //记录鼠标，窗口位置
    QPoint windowPos;
    QPoint mousePos;
    QPoint dPos;
    //表层
    QWidget *back;
    //昵称
    QLineEdit *CL_Name;
    //阴影
    QGraphicsDropShadowEffect * effect;
    //密码
    QLineEdit *CL_PassWord;
    QLineEdit *re_CL_PassWord;
    //注册
    QPushButton *SignUp_Btn;
signals:

};

#endif // SIGNUP_H
