
#ifndef USER_H
#define USER_H

#include <QObject>
#include <QString>

class User : public QObject
{
    Q_OBJECT
public:
    explicit User(QObject *parent = nullptr);

private:
    QString name;
    QString id;
    QString passWord;
    QString face;
signals:

};

#endif // USER_H
