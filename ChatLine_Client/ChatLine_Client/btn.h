
#ifndef BTN_H
#include <QPushButton>
#define BTN_H



class Btn : public QPushButton
{
    Q_OBJECT
public:
    explicit Btn(QPushButton *parent = nullptr);
    Btn(bool btn_type);
signals:

};

#endif // BTN_H
