#ifndef CONNECT_MYSQL_H
#define CONNECT_MYSQL_H

#include <QSqlDatabase>

class connect_mysql
{
public:
    connect_mysql();
    ~connect_mysql();
    bool isOpen();
    QList<QString> search(const QString& str);

private :
    QSqlDatabase db;
};

#endif // CONNECT_MYSQL_H
