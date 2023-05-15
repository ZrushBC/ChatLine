
#ifndef HOMIE_H
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QString>
#define HOMIE_H


#include <QWidget>


class Homie : public QWidget
{
    Q_OBJECT
public:
    explicit Homie(QWidget *parent = nullptr);
    QWidget *leftWidget;//左侧
    QVBoxLayout *lLayout;//左部布局
    QWidget *rightWidget;//右侧
    QVBoxLayout *rLayout;//右部布局
    QLabel *lab;//右边内容
    void add_homie(QString);
signals:

};

#endif // HOMIE_H
