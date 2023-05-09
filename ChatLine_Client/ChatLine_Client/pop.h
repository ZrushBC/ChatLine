
#ifndef POP_H
#include <QGraphicsDropShadowEffect>
#include <QLabel>
#define POP_H


#include <QWidget>


class Pop : public QWidget
{
    Q_OBJECT
public:
    explicit Pop(QWidget *parent = nullptr);
    //弹窗
    QWidget* popback;
    //弹窗信息
    QLabel *label;
signals:
    void show_signal();
};

#endif // POP_H
