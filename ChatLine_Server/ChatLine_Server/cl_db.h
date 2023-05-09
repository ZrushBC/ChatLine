
#ifndef CL_DB_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#define CL_DB_H


#include <QObject>


class CL_DB : public QObject
{
    Q_OBJECT
public:
    explicit CL_DB(QObject *parent = nullptr);
    QSqlQuery select_all(QString sql);
private:
    QSqlDatabase db;
    bool init();

signals:

};

#endif // CL_DB_H
