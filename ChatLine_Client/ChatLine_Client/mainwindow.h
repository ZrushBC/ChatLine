
#ifndef MAINWINDOW_H
#include <QMainWindow>
#include <QTextBrowser> //文本显示框
#include <QPlainTextEdit> //文本输入框
#include <QPushButton>
#include <QDateTime>
#include <QTcpSocket>   //套接字
#include <QNetworkInterface>
#include <QHostAddress>
#include <QList>
#include <QMessageBox> //弹窗
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
    QTextBrowser *text_read;
    QPlainTextEdit *text_send;
    QPushButton *send_btn;
private slots:
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
