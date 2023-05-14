
#ifndef MAINWINDOW_H
#include <QMainWindow>
#include <QWidget>
#include <QTextBrowser> //文本显示框
#include <QPlainTextEdit> //文本输入框
#include <QPushButton>
#include <QDateTime>
#include <QTcpSocket>   //套接字
#include <QNetworkInterface>
#include <QHostAddress>
#include <QList>
#include <QMessageBox> //弹窗
#include <QStackedWidget>
#include <QVBoxLayout> //垂直布局
#include <QHBoxLayout> //水平布局
#include <QFrame> //线
#include <QButtonGroup>
#include "homie.h"
#include "chat.h"
#include "btn.h"
#define MAINWINDOW_H

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Chat *chat;
    Homie *homie;
    //鼠标按下
    void mousePressEvent(QMouseEvent *event);
    //鼠标移动
    void mouseMoveEvent(QMouseEvent *event);
    //记录鼠标，窗口位置
    QPoint windowPos;
    QPoint mousePos;
    QPoint dPos;
private slots:
private:
    QPushButton *chatBtn;
    QPushButton *homieBtn;
    QButtonGroup *navGroup;
    QStackedWidget *pages;
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
