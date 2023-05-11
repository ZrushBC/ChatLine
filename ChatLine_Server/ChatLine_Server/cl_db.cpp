
#include "cl_db.h"

CL_DB::CL_DB(QObject *parent)
    : QObject{parent}
{
    this->init();
}

//初始化
bool CL_DB::init(){
    db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("chatline");
    db.setUserName("root");
    db.setPassword("18972533084zhao");
    db.setPort(3306);
    if(db.open())
    {
        qDebug()<<"数据库连接成功";
    }
    else
    {
        qDebug()<<"数据库连接失败,"<<db.lastError().text();
    }
}

//查询
QSqlQuery CL_DB::select_all(QString sql){
    QSqlQuery query;
    query.exec(sql);
    return query;
//    qDebug()<<query.size();
//    while(query.next()){
//        qDebug()<<query.value(0).toString().toUtf8().data()
//                 <<query.value(1).toString().toUtf8().data()
//                 <<query.value(2).toString().toUtf8().data()
//                 <<query.value(3).toString().toUtf8().data();
//    }
}
bool CL_DB::commit_data(QString sql){
    QSqlQuery query;
    return query.exec(sql);
}
