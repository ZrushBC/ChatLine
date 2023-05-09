
#include "Server.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Server w;
    w.init();
    return a.exec();
}
