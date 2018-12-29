#include "connect_mysql.h"
#include<iostream>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
connect_mysql::connect_mysql()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("muongthanh");
    db.setUserName("root");
    db.setPassword("root");

    if (!db.open())
       {
          qDebug() << "Error: connection with database fail";
       }
       else
       {
          qDebug() << "Database: connection ok";



       }

}
connect_mysql::~connect_mysql()
{
    if (db.isOpen())
    {
        db.close();
    }
}



bool connect_mysql::isOpen()
{
    return db.isOpen();
}

QList<QString> connect_mysql::search(const QString& str){
    QList<QString> list_word ;
    if (!str.isEmpty()){
        QSqlQuery qry;
        QString query = "SELECT word from tbl_word where word like '%" + str + "%' order by word ASC";
        qry.prepare(query);
        if( !qry.exec() )
            qDebug() << qry.lastError();
        else
        {

              QSqlRecord rec = qry.record();
              int cols = rec.count();
              QString temp="";
              while( qry.next() )
              {
                temp = "";
                for( int c=0; c<cols; c++ )
                  temp += qry.value(c).toString() + ((c<cols-1)?"\t":"");

                list_word.append(temp);
              }
        }
    }
    return list_word;

}

