
#include "mainwindow.h"

#include <QApplication>
#include"signin.h"
#include "client.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    SignIn w;
//    w.show();
    Client w;
    w.init();
    return a.exec();
}
