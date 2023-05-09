
#include "btn.h"

Btn::Btn(QPushButton *parent)
    : QPushButton{parent}
{
    this->setStyleSheet("QPushButton{background-color:rgb(185,185,185);border:0px;border-radius:5px;}"
                        "QPushButton:hover{background-color:rgb(255, 84, 57);}"
                        "QPushButton:pressed{background-color:rgb(255, 0, 0);}");
    this->resize(10,10);
}

Btn::Btn(bool btn_type){
    this->resize(10,10);
    if(btn_type){
        this->setStyleSheet("QPushButton{background-color:rgb(185,185,185);border:0px;border-radius:5px;}"
                            "QPushButton:hover{background-color:rgb(255, 84, 57);}"
                            "QPushButton:pressed{background-color:rgb(255, 0, 0);}");
    }else{
        this->setStyleSheet("QPushButton{background-color:rgb(185,185,185);border:0px;border-radius:5px;}"
                            "QPushButton:hover{background-color:rgb(255,230,235);}"
                            "QPushButton:pressed{background-color:rgb(255, 255, 255);}");
    }
}
