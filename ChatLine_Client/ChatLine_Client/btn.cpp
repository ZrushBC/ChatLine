
#include "btn.h"

Btn::Btn(QPushButton *parent)
    : QPushButton{parent}
{
    this->setStyleSheet("QPushButton{background-color:rgb(185,185,185);border:0px;border-radius:8px;}"
                        "QPushButton:hover{background-color:rgb(255, 84, 57);}"
                        "QPushButton:pressed{background-color:rgb(255, 0, 0);}");
    this->resize(16,16);
}

Btn::Btn(bool btn_type){
    this->setFixedSize(16,16);
    if(btn_type){
        this->setStyleSheet("QPushButton{background-color:rgb(185,185,185);border:0px;border-radius:8px;}"
                            "QPushButton:hover{background-color:rgb(255, 84, 57);}"
                            "QPushButton:pressed{background-color:rgb(255, 0, 0);}");
    }else{
        this->setStyleSheet("QPushButton{background-color:rgb(185,185,185);border:0px;border-radius:8px;}"
                            "QPushButton:hover{background-color:rgb(255,230,235);}"
                            "QPushButton:pressed{background-color:rgb(255, 255, 255);}");
    }
}
