
#ifndef CHAT_H
#include <QTextBrowser> //文本显示框
#include <QPlainTextEdit> //文本输入框
#include <QPushButton>
#include <QVBoxLayout>
#define CHAT_H


#include <QWidget>


class Chat : public QWidget
{
    Q_OBJECT
public:
    explicit Chat(QWidget *parent = nullptr);
    QTextBrowser *text_read;
    QPlainTextEdit *text_send;
    QPushButton *send_btn;
    QWidget *headWidget;//头部
    QWidget *leftWidget;//左侧
    QVBoxLayout *lLayout;//左部布局
    void add_chat();
signals:

};

#endif // CHAT_H
