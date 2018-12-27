#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>


class connection
{
public:
    connection(const QString & path);
    ~connection();
    bool search(const QString& name);
    bool createTable();
    bool isOpen();
private :
    QSqlDatabase m_db;
};

#endif // CONNECTION_H
