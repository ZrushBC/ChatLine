#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1000,618);
    //信息接收框
    text_read= new QTextBrowser(this);
    text_read->move(20,20);
    text_read->resize(700,400);
    //输入信息框
    text_send =new QPlainTextEdit(this);
    text_send->move(20,440);
    text_send->resize(600,100);
    //发送按钮
    send_btn =new QPushButton(this);
    send_btn->move(650,440);
    send_btn->resize(70,100);
    send_btn->setText("发送");
}

MainWindow::~MainWindow()
{
    delete ui;
}
