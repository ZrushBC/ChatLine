
#ifndef SERVER_H
#include "cl_socket.h"
#include "cl_db.h"
#include <QSqlQuery>
#include <QDateTime>
#include <QString>
#define SERVER_H


#include <QObject>


class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    void init();
private:
    CL_Socket *socket;
    CL_DB *db;
    QString getRandomID();
    QString getFriendList(QString id);
signals:

};

#endif // SERVER_H
